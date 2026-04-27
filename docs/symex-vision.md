# Multiplier Symbolic Execution — Vision & Plan

> Status: planning. Branch target: `feature/symbolic-execution`.
> Audience: program analyst writing under-constrained symbolic
> exploration on top of Multiplier's IR interpreter.

## Stated goals (user's words, lightly grouped)

### Address space

1. Globals + functions placed at chosen, fixed concrete addresses, mimicking
   a real process layout.
2. Some globals get concrete initial values; others get symbolic z3
   variables with **useful, analyst-chosen names**.

### Execution model

3. Under-constrained start: enter a function part-way through, **mid-loop**.
4. Iterate the loop; intercept its calls; stop when we'd leave the loop.
5. Local variables and parameters not seeded by the analyst still need
   sensible default values (concrete zero, or named symbolic).

### Hooks

6. Struct-field accesses can be intercepted: synthesize a value on read,
   or write a value before the read happens.
7. Indirect calls dispatched through analyst code (resolve callee, or
   model the call).
8. External / system calls modeled by stubs with a **lens** to read
   pointer arguments (incl. memory through them) and write to return
   values / output pointers.

### Observability

9. **Per-path** trace of which globals were accessed and **when** —
   essentially "along path P, at step S, global G was read/written
   with value V".

---

## Two extension models: policies vs observers

Before the API sketch, name the distinction that drives everything else.

There are exactly two ways the analyst extends the engine, and the
difference matters because the analyst has to pick the right tool:

| | **Policy / intercept** | **Observer / hook** |
|---|---|---|
| Agency | Agentic — return value flows into execution | None — return value ignored |
| Timing | Synchronous, blocking — engine waits for the answer | Notional async — engine moves on |
| Tense | "Decide what *is*" | "Tell me what is *about to be* or *was*" |
| Failure mode | Wrong answer corrupts execution | Wrong answer logs noise |
| Composition | Chained — each handler receives `next_hook` and forwards or short-circuits | All run; order = registration |
| Implementation | Substrate (overrides on `PythonPolicy`) | Built on top of policy events |

**Policies subsume observers.** Anything an observer can do, a policy
can do — observers are policies that ignore their return value.
The reverse is not true: an observer cannot redirect a load, choose
a callee, or stub a syscall, because it has no way to inject a
result back into the engine.

So **prefer observers** for diagnostic/telemetry/measurement work
(fewer footguns, no risk of corrupting execution by accident), and
**reach for policies** when you actually need to change what the
program sees.

In the API this becomes two namespaces:

- `@engine.intercept.<event>(…)` — agentic. Each handler takes
  `next_hook` as its last positional argument. Forward by calling
  `next_hook(...)` (the rest of the chain ending in the substrate's
  natural default); short-circuit by returning a value without
  calling it.
- `@engine.observe.<event>(…)` — observational. Return value
  ignored. Fires by default *after* the policy event commits
  (`observe.after.<event>` for explicitness; `observe.before.<event>`
  is available when the analyst wants pre-event notifications).

A handler that handles a memory-mapped global by giving back a z3
expression is `@intercept`. A handler that **records** every read
of `g_users` for a per-path access trace is `@observe`. The same
event can have both — they don't conflict because they live in
different layers.

---

## Vision: what a "killer" symbolic-execution API looks like

The current C++ interpreter exposes a lot of mechanism (policies,
schedulers, continuations) but a Python analyst should rarely touch
it directly. The Python layer is a **thin orchestration façade**
where the analyst:

1. Declares the *world* (address space, initial values).
2. Declares the *interceptors* (agentic — change what the program sees).
3. Declares the *observers* (passive — record what happened).
4. Asks the engine to *explore* and gets back *paths* with rich
   metadata.

Everything that follows is what we can build on the existing C++
substrate **without further C++ refactors of similar size to Steps 0–6**.

### Design principles

- **Inversion of control.** The engine drives the loop. Analyst code
  reacts to events via decorated handlers. No manual `while
  interp.step(): …` loops in user code (we provide one as an escape
  hatch, but the default path is declarative).
- **Selectors over imperative checks.** `@hook(addr_range=…)` /
  `@hook(name="read")` / `@hook(eid=…)` — the engine routes events;
  analyst writes only the body.
- **Context object is a toolbox.** Every hook receives a `ctx` with
  typed memory views, path metadata, the live z3 `Solver`, and
  control verbs (`ctx.fork`, `ctx.stop`, `ctx.skip`).
- **Lenses everywhere.** `ctx.mem.read_str(addr)`,
  `ctx.mem[addr:addr+8]`, `ctx.args.read_int(0)` — never raw
  `mem_read`/`mem_write` in user code.
- **Paths are first-class.** A `Path` object is the snapshot of one
  execution trace. It carries a `solver`, an `events` log,
  `tags`, and supports `clone`, `snapshot`, `replay(modify=…)`.
- **Events are queryable.** Every meaningful interpreter step emits
  a structured event; the path's event log is queryable
  (`path.events.where(kind="global_read", name="g_users")`).
- **Composable policies.** The same external-call model (e.g. `FILE*`
  semantics) is a Python class you import and register; it works
  across analyses.
- **Pluggable concretization.** `MemAddrContinuation` resolution is a
  strategy object: pick-one, enumerate-finite, smt-driven, hybrid.
- **Determinism by default.** Same input ⇒ same path order, same z3
  variable names. No accidental nondeterminism from set/dict iteration.

### Sketch: what the analyst sees

```python
import multiplier as mx
from multiplier.symex import (
    SymExEngine, Layout, ConcretizeFinite, ExploreUntil,
)
import z3

idx = mx.Index.in_memory("mx-index.db")
engine = SymExEngine(idx)

# 1. Address space — declarative, no agency.
layout = Layout(base=0x10000)
layout.place_global("g_users",   addr=0x20000, size=8 * 64)
layout.place_global("g_lock",    addr=0x21000, size=8, init=0)
layout.place_global("g_counter", addr=0x22000, size=4,
                    init=z3.BitVec("counter_in", 32))
engine.layout = layout

# 2. INTERCEPTORS — agentic. Return value flows into execution.
@engine.intercept.memory_read(addr_range=("g_users", 8 * 64))
def read_user_table(ctx, addr, size, next_hook):
    idx_ = (addr - layout["g_users"]) // 8
    return z3.BitVec(f"user[{idx_}]", size * 8)        # becomes the read result

@engine.intercept.call(name="read")
def stub_read(ctx, next_hook):
    fd     = ctx.args.read_int(0)
    buf    = ctx.args[1]
    n_val  = ctx.args.read_int(2)
    sym    = z3.BitVec(f"read_{ctx.path.id}_{ctx.step}", 8 * n_val)
    ctx.mem.write(buf, sym, n_val)
    return ctx.solver.fresh_int("read_ret", lo=0, hi=n_val)

@engine.intercept.indirect_call
def resolve_indirect(ctx, target_addr, next_hook):
    return ctx.layout.function_at(target_addr) or ctx.default()

@engine.intercept.loop(func="process_users")
def lp(ctx, next_hook):
    if ctx.loop.iteration >= 3: return False  # take the exit edge
    return next_hook(ctx)                     # natural concrete behavior

# 3. OBSERVERS — passive. Return value ignored. Engine fires after the event.
@engine.observe.global_read                            # any global, any path
def trace_global_reads(ctx, name, addr, value):
    ctx.path.events.append("global_read", name=name, addr=addr, value=value)

@engine.observe.branch
def trace_branches(ctx, taken_block, other_block, condition):
    ctx.path.events.append("branch", taken=taken_block.id)

@engine.observe.before.memory_write(addr_range=("g_lock", 8))
def saw_lock_write_coming(ctx, addr, value):           # rare: pre-event observer
    ctx.path.tag("touched_lock")

# 4. Explore.
paths = engine.explore(
    start_func="process_users",
    start_block=5,                                     # mid-loop
    seed={"argc": z3.BitVec("argc_in", 32)},
    until=ExploreUntil.path_count(50) | ExploreUntil.steps(100_000),
)

# 5. Analyze.
for p in paths:
    accesses = p.events.where(kind__in=("global_read", "global_write"))
    print(p.id, p.tags, [(a.name, a.kind) for a in accesses])
```

The "killer" qualities of this surface:

- **Two namespaces, one mental model.** Reach for `intercept` only
  when you need to change what the program sees; reach for `observe`
  for everything else. Same selector vocabulary in both
  (`addr_range=`, `name=`, `eid=`, `func=`).
- **Address tokens** (`"g_users"`) flow through every API — no raw
  hex on the analyst's side once the layout is declared.
- **Selector-routed events.** The engine matches; the body is just
  the model. Hooks are decorators, not loops.
- **`ctx` is a service locator** for memory, args, solver, control
  flow, *and* path metadata. One handle, learn it once.
- **Termination predicates compose** with `|` / `&`.
- **Path event log is structured** and queryable; you don't grep
  log files.

### Picking the right tool: a decision table

| You want to … | Use |
|---|---|
| Return a symbolic value for a global read | `intercept.memory_read` / `intercept.global_read` |
| Stub a syscall (read args, write a return value) | `intercept.call(name=…)` |
| Choose which callee fires for an indirect call | `intercept.indirect_call` |
| Choose which addresses to enumerate when one is symbolic | `intercept.concretize` (concretization strategy) |
| Stop / continue / skip a loop iteration | `intercept.loop(func=…)` |
| Pre-write a value before a struct field is read | `intercept.memory_read` (write inside, then `return next_hook(ctx, addr, size)`) **or** `observe.before.memory_read` |
| Count how many times `foo` is called | `observe.call(name="foo")` |
| Tag a path when it touches a sentinel address | `observe.memory_read(addr_range=…)` |
| Build a per-path trace of global accesses | `observe.global_read` + `observe.global_write` |
| Log every branch and which side was taken | `observe.branch` |
| Trip-wire on every step (debug) | `observe.step` |

When you're unsure, start with `observe`. If you discover the
analysis needs to *change* what the program saw, promote it to an
`intercept` — the hook body usually carries over verbatim plus a
`return value` line.

---

## Non-goals (keep this scope tight)

- Full function-summary cache across runs. (Per-run only.)
- Path merging / state-merging optimization. (Each path stays
  independent.)
- A graphical path browser. (Structured events make TUI/GUI
  trivial later, but not now.)
- Full POSIX / libc model. We ship a *kit* for writing stubs, plus
  one or two reference stubs (`memcpy`/`strlen`/`read`).
- Whole-program proof obligations. We surface accesses; the analyst
  does the reasoning.
- New IR opcodes or interpreter-loop changes beyond what Phase 0
  requires.

---

## Architecture overview

The two-tier extension model maps cleanly onto a layered architecture:
**interceptors compile down to policy overrides** (substrate); **observers
are notifications** the engine emits *around* policy events.

```
┌──────────────────────────────────────────────────────────────────────┐
│                        Analyst-facing layer                          │
│  SymExEngine · Layout · @intercept.* · @observe.* · Path · Ctx       │
│  Lenses · Termination predicates · Concretization strategies         │
├──────────────────────────────────────────────────────────────────────┤
│                          Glue layer (Python)                         │
│                                                                      │
│   ┌─ InterceptorPolicy(PythonPolicy) ─────────────────────────────┐  │
│   │  Sole consumer of the C++ policy hooks. For each event:       │  │
│   │    1. fire `observe.before.<event>` notifications             │  │
│   │    2. compose matching `intercept.<event>` handlers into a    │  │
│   │       chain ending in the substrate's natural default; each   │  │
│   │       handler decides whether to forward via `next_hook`     │  │
│   │    3. fire `observe.after.<event>` notifications              │  │
│   │  Default behavior (when no intercept handles) = stock         │  │
│   │  PythonPolicy / ConcretePolicy semantics.                     │  │
│   └────────────────────────────────────────────────────────────────┘ │
│                                                                      │
│  - Driver loop:                                                      │
│      consumes step() result dict, classifies continuations,          │
│      enumerates BranchContinuation via .next(), drives MemAddr-      │
│      Continuation through a concretization strategy, builds Path     │
│      objects.                                                        │
│  - InitFromBlock helper: seeds InterpreterState at chosen block.     │
│  - Selector compiler: turns @intercept/@observe selectors into a     │
│      keyed dispatch table (addr-range tree, name table, eid map).    │
│  - Event recorder: every observer call is timestamped into the       │
│      path's structured event log.                                    │
├──────────────────────────────────────────────────────────────────────┤
│         Existing C++ substrate (mostly untouched after Phase 0)      │
│  ConcreteMemory · ConcretePolicy · PythonPolicy · interp_step        │
│  Continuation · MemAddrContinuation · BranchContinuation             │
│  Sharable / PyObjectRC InterpreterState                              │
└──────────────────────────────────────────────────────────────────────┘
```

**Why interceptors and observers don't share a code path beyond
dispatch.** Interceptors must run inside the policy callback because
they can suspend / fork / write memory before the C++ side commits.
Observers run via callbacks the engine schedules around the policy
event — failing or being slow in an observer can never corrupt the
interpreter; it can at worst spam the event log.

The only **new** C++ work needed (Phase 0):

- A small `interp_init_state_at(state, func, block, value_bindings)`
  helper that lets the driver seed the entry block of execution.
  The IR has block-id-keyed phi/op data already; we just don't have a
  Python-callable that says "start here, with these eid → value
  bindings."
- A `with_value` suspension sibling to `with_address`, **only if** we
  decide global lazy-init needs it. Probably *not* needed for
  Phase 1; deferrable.

Everything else is Python.

---

## Phased delivery

Each phase ends with a green test gate. **No phase ships without
its tests passing.** Tests double as API exemplars and are listed
under "Test catalog" below — phase numbers there match these.

### Phase 0 — interpreter primitives

**Goal:** unblock mid-block entry and standardize the result-dict
shape that the new driver consumes.

- C++: `interp_init_state_at(state, func, block, frame_value_seed)`.
  Sets `call_stack.top().current_block = block`, fills
  `frame.values[eid] = …` from the seed map.
- C++ (small): expose `Layout` primitives in the binding —
  pre-allocate at chosen address, `place_at(addr, size, align)` on
  `ConcreteMemory`. (May already exist; verify and wrap.)
- Python: regression tests against existing 235 — must stay green.

**Tests:** P0.1–P0.4.

### Phase 1 — analyst-facing skeleton

**Goal:** ship `SymExEngine`, `Layout`, `Path`, `Ctx`, basic
explore-all loop. No fancy hooks yet — just enough that the
sketch above runs end-to-end on a toy program.

- `Layout` class: name → address book, `place_global`, `place_function`,
  `[]` indexing, address-range queries.
- `SymExEngine`: holds layout + hooks; orchestrates `explore`.
- `Path`: wraps `InterpreterState`, exposes `.id`, `.events`,
  `.tags`, `.solver`, `.clone`, `.snapshot`, `.restore`.
- `Ctx`: passed to hooks, holds `path`, `mem` (lens),
  `args` (lens), `solver`, control verbs.
- Memory lens: `ctx.mem[addr:addr+n]`, `read_int`, `read_str`,
  `write`.
- Args lens: `ctx.args[i]`, `read_int(i)`, `read_str(i)`.
- Termination: `ExploreUntil.path_count(N) | ExploreUntil.steps(N)`.
- Driver: enumerate `BranchContinuation.next()`, push paths;
  handle `MemAddrContinuation` with a default
  `ConcretizeFinite([0])` strategy.

**Tests:** P1.1–P1.7.

### Phase 2 — interceptors, observers, lenses

**Goal:** the two-namespace extension model, the heart of the
analyst API.

- **Interceptors (agentic).** Decorators register handlers on the
  `engine.intercept.*` namespace:
  - `intercept.memory_read(addr_range=…, eid=…, name=…)`
  - `intercept.memory_write(...)`
  - `intercept.call(name=…, eid=…)`
  - `intercept.indirect_call`
  - `intercept.global_read` / `intercept.global_write`
  - `intercept.branch` (rarely needed; for forced-edge experiments)
  - `intercept.loop(func=…)`
  - `intercept.concretize` (concretization strategy, see Phase 5)

  Each handler takes `next_hook` as its last positional argument.
  To forward to the rest of the chain (and ultimately the substrate's
  natural default), call `next_hook(...)` and return its result.
  To short-circuit, return a typed value without calling `next_hook`.
  Use `ctx.default()` for the substrate's default value, or
  `ctx.stop_path()` to mark the path as stopped before returning.

- **Observers (passive).** Decorators register handlers on the
  `engine.observe.*` namespace, mirroring the intercept selector
  vocabulary. `observe.<event>` defaults to *after*; explicit
  `observe.before.<event>` / `observe.after.<event>` available:
  - `observe.memory_read`, `observe.memory_write`
  - `observe.call`, `observe.return`
  - `observe.global_read`, `observe.global_write`
  - `observe.branch`
  - `observe.step` (every committed instruction; debug)
  - `observe.path_start`, `observe.path_end`

  Return values are ignored. Multiple observers run in
  registration order; an exception in one logs and is swallowed
  so it can't corrupt execution. Observers see the value the
  intercept chain (or default policy) decided on.

- **Selector compilation:** declarative selectors compile to a
  keyed dispatch table — addr-range tree for `addr_range`, hash
  for `name` / `eid`, function-id set for `func`. Constant-time
  per event in the common case.

- **Composable models.** Ship `multiplier.symex.models.libc` with
  reference interceptors for `read`, `write`, `memcpy`, `memset`,
  `strlen`, `strcpy`, `malloc`, `free`. `engine.use(libc)`
  registers them all. Models can be subclassed, overridden, or
  paired with observers (e.g. `models.libc.read` plus an
  `@observe.call(name="read")` for tracing).

- **Lens features.** `ctx.mem.read_struct(addr, layout)`,
  `ctx.mem.write_struct(...)`, `ctx.args.as_string(i)`,
  `ctx.args.as_pointer_to(i, T)`. Same lenses available in
  observer bodies (read-only) and interceptor bodies (read+write).

- **Event recorder.** Observer callbacks always run inside the
  recorder so the path's `events` log gets a structured entry
  per call.

**Tests:** P2.1–P2.13.

### Phase 3 — loop & path control

**Goal:** under-constrained mid-loop execution becomes a real,
useful primitive.

- Backedge analysis: a Python pass over IR's block CFG that
  classifies each branch edge as `tree`, `forward`, `back`, or
  `cross`. Result cached on the function.
- `LoopContext` available on `ctx.loop` inside loop-aware hooks —
  `iteration`, `header_block`, `latch_block`, `would_exit`.
- `intercept.branch(func=…, block=…)` chain dispatch and the
  `intercept.loop(func=…, header_block=…)` sugar built on top.
  Loop hooks compose: return `False` to take the exit edge,
  `True` to continue, or call `next_hook(ctx)` to take the natural
  concrete decision. `intercept.branch` handlers receive
  `(ctx, condition, next_hook)`.
- Path concurrency control: `engine.explore(strategy="dfs"|"bfs")`,
  `ExploreUntil.max_paths(N)` / `max_depth(D)`.
- `Path.snapshot()` / `Path.restore(snap)` /
  `Path.replay(modify=callable, engine=…)` — let the analyst
  surgically retry a path with one mutation applied first.

**Tests:** P3.1–P3.6.

### Phase 4 — observability

**Goal:** the analyst can answer "what happened, where, why."

- `path.events.where(...)` — predicate queries on the structured
  event log via the `EventLog` (a `list` subclass with predicate
  methods). Operators: bare `field=v`, `__in=(…)`, `__between=(lo, hi)`,
  `__gt`, `__lt`, `__ge`, `__le`, `__ne`, `__contains`. Companion
  helpers: `events.first(...)`, `events.count(...)`.
- `paths` is a `PathSet` (a `list` subclass) with the same
  `where` / `first` / `count` shape over path-level filters:
  `terminal=`, `return_value=`, `tags__contains=`,
  `events__contains_kind=`, `events__contains_addr=`.
- `path.summary()` — multi-line human-readable summary: function
  name, terminal kind, return value, step count, globals_touched,
  branch_forks, event count, tags.
- `path.dot_cfg()` — emit a Graphviz string of branch transitions
  this path took. Phase 4 caveat: the substrate doesn't yet emit
  a per-block-enter event to Python, so the rendered graph is the
  branch-transition graph, not every block visited.
- z3 integration: `ctx.solver.fresh_int(name, *, size, lo=None,
  hi=None)` mints (or returns the cached) z3 BitVec and adds the
  bound constraints. `path.assert_(cond)` adds an assertion and
  marks the path `terminal="infeasible"` if the resulting
  constraint set is unsat. `path.solver.model()` runs `check()`
  and returns `{name: int}` on `sat`, None on `unsat`.
  `compare` / `binary_op` / `unary_op` produce derived z3 exprs
  when an operand is a z3 expression; branch forks accumulate the
  branch condition (`cond` on the true child, `Not(cond)` on the
  false child) onto `path.path_condition`.

**Tests:** P4.1–P4.6 plus the un-skipped `P1.5_z3_named_global`.

### Phase 5 — concretization strategies

**Goal:** when symbolic addresses block progress, the analyst
chooses how to widen.

- `Strategy` interface: `next_addresses(addr_expr, hint, ctx) ->
  Iterable[int]`.
- Built-ins:
  - `ConcretizeFinite([…])` — explicit address set.
  - `ConcretizePointerSet(targets=[…])` — likely targets from
    layout or function-pointer table.
  - `ConcretizeViaSolver(max_models=k)` — z3 enumerate-models.
  - `ConcretizeRange(low, high, step)` — array probing.
- `engine.concretize_default = …`, plus per-hook override:
  `@on_memory_read(strategy=ConcretizeViaSolver(8))`.
- Bound: max-models per suspension, total-fork budget.

**Tests:** P5.1–P5.4.

### Phase 6 — polishing & docs

- Docstrings on every public API.
- One full worked example: a small CVE-style under-constrained
  analysis on a real C function, end-to-end, in a Jupyter notebook.
- `multiplier.symex` exposed cleanly; namespaces tightened.
- Performance pass: profile path-explosion benchmarks, bound
  per-event Python overhead.

---

## Test catalog (Python, double as API exemplars)

Each test is a single function in `tests/symex/test_*.py`. Where
useful, the test fixture program is a small C file in
`tests/symex/c/` indexed once per session.

### Phase 0 — interpreter primitives

**P0.1** `test_init_state_at_block_runs_to_completion` — start at the
entry block (regression: existing init still works).

**P0.2** `test_init_state_at_non_entry_block` — function with 4 blocks,
seed value bindings for live-ins, start at block 2, verify exit.

**P0.3** `test_existing_235_still_pass` — run the existing
`test_symbolic_harness.py` + `test_symbolic_addresses.py`
against new build; must be 235/235.

**P0.4** `test_layout_pre_allocate` — `ConcreteMemory.place_at(addr,
size, align)` succeeds at unused addresses, fails on overlap.

### Phase 1 — analyst skeleton

**P1.1** `test_layout_basic` — declare layout with three globals;
`layout["g_users"]` returns the right address; `function_at(addr)`
returns the symbol.

**P1.2** `test_engine_explore_concrete_only` — toy `int sum(int n)`;
no symbolic anything; one path; return value is correct.

**P1.3** `test_explore_returns_path_objects` — each path has `.id`,
`.events`, `.solver`, `.tags`, `.snapshot()`.

**P1.4** `test_path_event_log_records_branches` — function with one
`if`; both paths produced; each path's `events` ends with a
`branch` event naming the taken edge.

**P1.5** `test_z3_named_global` — global initialized with
`z3.BitVec("counter_in", 32)`; reading it through the engine
returns *that* z3 variable (identity, not just structural
equality).

**P1.6** `test_explore_until_path_count` — 8-way branching function;
`ExploreUntil.path_count(3)` stops after 3 paths.

**P1.7** `test_explore_until_steps` — long-running function;
`ExploreUntil.steps(100)` halts at the budget.

### Phase 2 — interceptors, observers, lenses

Each test is named after the namespace it exercises. Tests in
this phase deliberately demonstrate **the same event** under
both `intercept` and `observe` so the difference is concrete in
code form.

**P2.1** `test_intercept_memory_read_addr_range` — read inside a
global's range fires the interceptor; read outside falls through
to default policy.

**P2.2** `test_intercept_memory_read_returns_z3` — interceptor
returns `z3.BitVec(...)`; the value flows into the program's
computation; the next arithmetic op sees the symbolic value.

**P2.3** `test_intercept_memory_write_drops_write` — interceptor
returns `None` without calling `next_hook`; subsequent read of the
address returns the prior value, not the dropped one.

**P2.4** `test_intercept_call_by_name` —
`@intercept.call(name="strlen")` fires; interceptor reads pointer
arg via `ctx.args.read_str(0)`; returns correct length; default
policy never sees the call.

**P2.5** `test_intercept_call_lens_writes_through_pointer` —
`@intercept.call(name="read")` writes a symbolic buffer through
`args[1]`; caller's subsequent indexing returns the symbolic bytes.

**P2.6** `test_intercept_indirect_call_resolution` — function
pointer table at known addresses; interceptor returns the right
callee based on `ctx.layout.function_at(target_addr)`.

**P2.7** `test_intercept_call_default_returns_default` — interceptor
returns `ctx.default()`; caller sees the substrate's default
return value.

**P2.8** `test_chain_forwards_through_next_hook` — two
`@intercept.memory_read` handlers on overlapping ranges; first
calls `next_hook(...)`, second short-circuits with a value;
verify the second's value propagates back through the first.

**P2.9** `test_intercept_struct_field_pre_write` — interceptor
on field's address `ctx.mem.write`s a value, then forwards via
`next_hook(ctx, addr, size)`; the chain bottom's natural read
returns the pre-written value.

**P2.10** `test_observe_memory_read_records_to_path` — same
event as P2.1, but with `@observe.memory_read`; the path's
events log has the read; *no change to program execution*
(verifiable by comparing return value to a baseline run).

**P2.11** `test_observe_call_counts_invocations` —
`@observe.call(name="malloc")`; counter increments per call;
program's behavior is identical to baseline (intercept-free) run.

**P2.12** `test_intercept_and_observe_coexist_on_same_event` —
both `@intercept.global_read(name="g_counter")` *and*
`@observe.global_read(name="g_counter")` registered; observer
sees the value the interceptor decided (not the underlying
memory's stale value).

**P2.13** `test_observer_exception_does_not_corrupt_path` —
observer raises `RuntimeError`; the path completes normally,
the exception is logged on the path's diagnostics, no
interceptor / default-policy work is skipped.

**P2.14** `test_libc_model_pack_registers_all` —
`engine.use(models.libc)`; calls to `strlen`, `memcpy`, `read`,
`malloc` all dispatch to the pack's interceptors; verify each
fires exactly once.

### Phase 3 — loop & path control

**P3.1** `test_backedge_analysis` — IR with a 4-block loop;
backedge classifier identifies the latch→header edge.

**P3.2** `test_loop_iterate_n_times_then_exit` — `loop_policy`
allows 3 iterations, then forces exit; path summary shows
iteration=3 then exit.

**P3.3** `test_mid_loop_entry_with_seed` — start at the loop body
block with `i = z3.BitVec("i_in", 32)`; check that `i` flows
through and increments through one iteration.

**P3.4** `test_path_snapshot_restore` — run a path 50 steps, snap,
run 100 more, restore, verify state matches snap.

**P3.5** `test_path_replay_with_modify` — run to completion;
replay with `mem.write(g_lock, 1)` modify; new path takes
different branch.

**P3.6** `test_explore_dfs_vs_bfs` — branching function; BFS visits
shallow paths first, DFS visits deepest first.

### Phase 4 — observability

**P4.1** `test_events_where_filter` — five hooks fired across
different kinds; `events.where(kind="global_read")` returns
exactly those.

**P4.2** `test_events_where_addr_between` — two reads at different
addresses; `events.where(addr__between=(start, end))` filters
correctly.

**P4.3** `test_path_summary_string` — completed path's
`summary()` mentions function name, exit block, count of
globals touched.

**P4.4** `test_paths_query_first_to_target` —
`paths.first(events__contains_kind="global_write")` returns
the first path that wrote any global.

**P4.5** `test_z3_solver_model_extracts_input` — symbolic
`argc_in`; path takes `argc > 5` branch; `path.solver.model()`
gives a witness with `argc_in > 5`.

**P4.6** `test_path_dot_cfg_renders` — `path.dot_cfg()` returns a
non-empty Graphviz string; smoke check it parses.

### Phase 5 — concretization strategies

**P5.1** `test_concretize_finite` — symbolic-address read; strategy
`ConcretizeFinite([a, b, c])` produces 3 paths with those
addresses.

**P5.2** `test_concretize_via_solver` — pointer constrained to
`[lo, hi]` by path conditions; solver enumerator yields ≤ k
distinct addresses, all in range.

**P5.3** `test_concretize_pointer_set` — function-pointer table
known via layout; strategy yields exactly the table entries.

**P5.4** `test_concretize_budget_exhaustion` — finite address set
of size 5 with `max_models=3`; engine explores 3 paths and
emits a `concretization_truncated` event on the suspension.

### Phase 6 — example & polish

**P6.1** `test_under_constrained_loop_walkthrough` — end-to-end on
a 50-line C program: layout, hooks for `read`/`write`, loop
policy iterating 4×, indirect call dispatch, observe global
access trace. **The exemplar test.**

**P6.2** `test_docstring_examples` — every public symbol's
docstring example block passes when run.

---

## Open design questions

- **Z3 ownership.** One `Solver` per path, or a global solver with
  per-path scoped assertions? Per-path is simpler; risks no
  cross-path constraint sharing. Recommend per-path; add
  `engine.shared_solver` later if needed.
- **Address-range selectors with z3 expressions.** What if the
  read address is partially symbolic? Our `with_address_impl`
  already concretizes before the hook fires, so the selector
  always sees an `int`. Good.
- **Interceptor ordering across files.** Explicit `priority=`
  kwarg, or registration order? Recommend registration order
  (first-registered = outermost in the chain) with optional
  priority. The composition shape makes "two intercepts conflict"
  impossible by construction: each handler decides whether to
  forward or short-circuit, so ordering is the only knob.
- **Mid-block (not just mid-loop) entry.** Sub-block granularity
  (e.g. resume after step 3 of block 5) requires saving the
  per-instruction work-stack. Defer; mid-block-as-block-entry is
  enough for Phase 1–2.
- **Multi-function entry.** Today `start_func` is one function.
  Composable? Imagine "explore from any function whose name
  matches `r"on_.*_event"`." Defer to Phase 6.
- **Path serialization.** Snapshot is in-process today; cross-
  process replay needs serializing the symbolic state + z3
  solver. Defer.

---

## Files we will create

```
bindings/Python/symex/__init__.py
bindings/Python/symex/engine.py        # SymExEngine, explore, until-predicates
bindings/Python/symex/layout.py        # Layout
bindings/Python/symex/path.py          # Path, snapshot, replay
bindings/Python/symex/ctx.py           # Ctx, default()/stop_path() helpers
bindings/Python/symex/lens.py          # MemView, ArgsView, struct lenses

bindings/Python/symex/intercept.py     # @intercept.* decorators (agentic)
bindings/Python/symex/observe.py       # @observe.* decorators (passive)
bindings/Python/symex/dispatch.py      # InterceptorPolicy (PythonPolicy
                                       # subclass): selector compilation,
                                       # before/after observer dispatch,
                                       # intercept chain, fall-through to
                                       # default policy.

bindings/Python/symex/concretize.py    # strategies
bindings/Python/symex/loop.py          # backedge analysis, LoopContext
bindings/Python/symex/events.py        # event log + queries
bindings/Python/symex/models/libc.py   # reference interceptors

tests/symex/conftest.py                # fixtures, indexing helpers
tests/symex/c/                         # small C programs per phase
tests/symex/test_phase0.py
tests/symex/test_phase1.py
tests/symex/test_phase2.py             # both @intercept and @observe tests
tests/symex/test_phase3.py
tests/symex/test_phase4.py
tests/symex/test_phase5.py
tests/symex/test_phase6.py
```

The split between `intercept.py` and `observe.py` is deliberate:
the two namespaces are kept in separate modules so the analyst
can see at a glance which extension model a handler uses, and
so a code reviewer can audit "is anything in this file changing
program semantics?" with `git grep '^from multiplier.symex.intercept'`.

C++ delta (Phase 0 only, kept minimal):

```
include/multiplier/IR/Interpret/InterpreterLoop.h   # interp_init_state_at
bindings/Python/Interpreter.cpp                     # Python wrapper for it
include/multiplier/IR/Interpret/ConcreteMemory.h    # place_at if missing
```

---

## Definition of done

- Phases 0–6 complete, each with its test suite green.
- `tests/symex/test_phase6.py::test_under_constrained_loop_walkthrough`
  runs in under 10 seconds on the test program.
- The 235-test pre-existing harness still passes (regression gate).
- Public API has docstrings; the README links to the Phase 6
  walkthrough.
- A new project-memory entry summarizes the API for future sessions.
