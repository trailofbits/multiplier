# Future Direction: Hook Dispatch as a First-Class Work-Stack Item

**Status: NOT IMPLEMENTED — design notes only**

## Background

The interpreter work stack is already a two-level structure:

- **IR level** ("machine code"): `CALL`, `LOAD`, `COND_BRANCH` — the IR opcodes the analyst sees.
- **Work-stack level** ("microcode"): `EXEC_CALL`, `ANALYZE`, `DECIDE_COND_BRANCH` — how each IR op is realized across one or more work items popped by the dispatch loop.

Hook dispatch (intercept/observe chains) currently lives *inside* `dispatch()` as an inline C++ call into Python.  This conflation means there is no clean point at which to suspend the interpreter between "hooks decided what to do about this instruction" and "instruction executes."

## The Problem

When a Python hook raises `StopNow` (or any exception), the C++ abort path fires.  The item that triggered the hook was already popped from the work stack before `dispatch` was called, so the work stack at abort time represents *everything after the current instruction*, not *the current instruction itself*.  Preserving that work stack and re-running gives re-fire semantics: on next entry, the hook fires again for the same instruction.

Re-fire is the correct and accepted semantic for user-driven resumption — the user makes an explicit choice to resume and can set `path.vars` state to change hook behavior before doing so.  The current implementation is fine for this use case.

The limitation appears when you want suspension *without* re-fire — i.e., to resume past the hook without re-invoking it.  That requires hook dispatch to be a distinct, independently resumable work item.

## Proposed Architecture

Add a new work-item kind, tentatively `FIRE_HOOKS`, that encapsulates a single hook-dispatch event:

```
EXEC_CALL
  └─► FIRE_CALL_HOOKS(inst, serialized_args, resolved_name)
  └─► EXEC_CALL_INLINE(callee)     ← only if hooks deferred
```

`FIRE_CALL_HOOKS` is popped, the Python hook chain runs, and:

- If a hook intercepts (returns a value), `EXEC_CALL_INLINE` is removed and the call result is written.
- If the chain defers, `EXEC_CALL_INLINE` stays and executes next.
- If a hook suspends (raises `StopNow` or similar), the work stack is left with `FIRE_CALL_HOOKS` at the top.  On resume, the hook chain runs again from scratch — but the item is the *same* item, so no special re-entry logic is needed.

The same pattern applies to `FIRE_MEM_READ_HOOKS`, `FIRE_BRANCH_HOOKS`, etc.

## Benefits

- Suspension at a hook boundary leaves the work stack pointing exactly at the hook-dispatch item.  Resume re-executes the hook chain cleanly with no "was this already fired?" bookkeeping.
- The current work-stack/clear distinction (`abort_requested` clears, user-pause doesn't) becomes unnecessary: suspension is just "don't pop the item."
- Every suspension point in the system has the same shape: a work item that is safe to re-pop.

## Cost and Re-architecting Scope

- Hook arguments (args list, resolved name, target eid, etc.) must be serializable into the `WorkItem` struct so they survive across a suspend/resume cycle.  Today they are computed inline and discarded.
- `dispatch()` gains new `FIRE_*_HOOKS` cases; the inline hook calls in `exec_call`, `exec_load`, `exec_store`, etc. are replaced by work-item pushes.
- The Python `InterceptorPolicy` stays largely unchanged; `dispatch()` just calls it from a different control-flow site.
- Estimated scope: medium — touches `InterpreterLoop.h`, `SymbolicInterpreter.cpp/h`, and the work-item struct, but not the Python symex layer above.

## Current Interim Behavior

`ctx.stop_now()` / `StopNow` uses the existing exception-abort path, which clears the work stack.  The path is marked terminal and is not stepped again.  Re-fire on a hypothetical user resume is accepted as correct: the user controls when and whether to resume, and sets path state accordingly before doing so.
