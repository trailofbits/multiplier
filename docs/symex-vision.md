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
- `path.dot_cfg()` — emit a Graphviz string of every block visited
  on this path, with branch-direction styling overlaid where the
  path forked. Phase 8d wired a substrate `on_enter_block`
  callback through to `engine.observe.block_enter` and to
  `path.events`, so even a branchless function renders an edge per
  visited block (pre-8d this rendered an empty placeholder).
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

- `AddressStrategy` interface: `next_decisions(suspension) ->
  Iterable[Decision]`. `Decision` today has one variant,
  `ConcretizeTo(addr, *, extra_constraint=None)`; Phase 6 widens it
  with `SplitByRegion` and `ConstrainTo` so region splits and
  constraint-only decisions don't have to flatten to ints.
- Built-ins:
  - `ConcretizeFinite([…])` — explicit address set.
  - `ConcretizePointerSet(layout=…, names=…)` — resolve named
    globals/functions through a layout; `.functions(layout)` and
    `.globals(layout)` are the common-case classmethods. (Range
    probing subsumed by `ConcretizeFinite` + `ConcretizeByRegion`.)
  - `ConcretizeByRegion(layout, *, max_models=None)` — fork one
    path per layout region.
  - `ConcretizeViaSolver(*, max_models=k)` — z3 enumerate distinct
    sat-models, attaching `addr_var == k` as `extra_constraint`
    so the child path's solver agrees with the executed address.
- `engine.address_strategy = …` (default), per-call override via
  `engine.explore(..., concretize=AddressStrategy)`, per-site
  override via `engine.concretize_at(strategy, **selector_kwargs)`
  reusing the intercept dispatch's `_Selector` (`addr_range=`,
  `name=`, `eid=`, `func=`, `block=`).
- Soundness: `ConcretizeViaSolver` attaches `addr_var == k` as
  `extra_constraint`; the engine asserts a feasibility pre-check
  (`path_condition ∧ addr == k`) on every concrete candidate and
  drops infeasible picks before resuming.
- Events: `concretization_truncated` (max_models reached),
  `concretization_infeasible` (candidate dropped by feasibility
  check). Terminal: `concretization-refused` (strategy returned
  zero decisions — distinct from `stuck-suspension`).
- Bound: max-models per suspension, total-fork budget.

**Tests:** P5.1–P5.10.

### Phase 6 — region-aware memory + first sink oracles

- `Region`, `LazyRegion`, and a sorted-by-base `RegionTable` in
  `bindings/Python/symex/region.py`. `Layout` upgraded to back its
  globals with `Region` objects; legacy `globals()` /
  `functions()` / `address_range()` API preserved.
- New `Decision` variants `SplitByRegion(regions=(…))` and
  `ConstrainTo(constraint)` in `concretize.py`.
  `ConcretizeByRegion` widened to return a single `SplitByRegion`
  so the engine can fork one child per region with `addr_var ∈
  region` asserted on each.
- `lazy_region_budget` per path; `ConcretizeByRegion(...,
  lazy_default=True)` materializes a fresh `LazyRegion` when the
  layout has no regions to enumerate. Over-budget regions are
  refused with a `lazy_budget_exhausted` event.
- Per-region `z3.Array(BitVec(64), BitVec(8))` overlay backing
  symbolic-offset reads/writes; concrete writes mirror byte-by-byte
  into existing overlays so symbolic reads see the prior concrete
  bytes (`Memory.py` blueprint, `_ReconstructValue`-shaped).
- `SinkRegistry` + `Sink` ABC + three built-ins: `OOBSink`,
  `NullDerefSink`, `DivByZeroSink`. Each has a *concrete-addr*
  mode (containment check; no solver call) and a *symbolic-addr*
  mode (path-condition + bad predicate). Findings land on
  `path.findings` with a model-witness.
- New events: `region_materialized`, `lazy_budget_exhausted`,
  `constrain_to_concrete_addr`, `split_by_region`, `sink_fired`,
  `binary_op` (sink event). New terminal: `Terminal.SINK_HIT` for
  fatal sinks. Memory events tagged with `region` (name or None).
- Required substrate hook: `interp_resume_addr_symbolic(state,
  eid, py_value)` — sibling of `resume_addr` that writes a Python
  value (typically z3 expression) into the suspended op's address
  slot.

**Tests:** P6.0–P6.13. 8 strategy/overlay unit tests + 6 end-to-end.

**Delivered by Phase 7:** Python dispatch for
`PythonPolicy::ptr_add` / `ptr_diff` / `ptr_offset` mirrors the
`binary_op` / `cast` shape; `InterceptorPolicy` propagates
symbolic operands as z3 BitVec(64). Organic explores now
produce suspensions whose `address_expr` is a live z3
expression, and `_addr_feasible` filters strategy decisions
against the actual path condition.

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

**P5.1** `test_p5_1_concretize_finite` — `ConcretizeFinite([a, b, c])`
produces 3 paths, each with the right `memaddr_concretize` event.

**P5.2** `test_p5_2_concretize_via_solver_attaches_constraint` —
strategy unit test: `ConcretizeViaSolver(max_models=4)` over a
constrained z3 BitVec yields ≤ 4 distinct sat-models in sorted
order, each carrying `addr_var == k` as `extra_constraint`.

**P5.3** `test_p5_3_concretize_pointer_set_from_layout` —
`ConcretizePointerSet.functions(layout)` yields one decision per
placed function in registration order.

**P5.4** `test_p5_4_concretize_by_region` — `ConcretizeByRegion(layout)`
yields one decision per global region's base, in deterministic order.

**P5.5** `test_p5_5_concretize_truncation_event` — capped strategy
hitting `max_models` emits `concretization_truncated` on every child.

**P5.6** `test_p5_6_per_site_override_by_name` — `engine.concretize_at(
strategy, name="g")` overrides the default for suspensions on the
named region.

**P5.7** `test_p5_7_per_site_override_by_addr_range` — `addr_range=`
override fires when the suspension's address can land in range.

**P5.8** `test_p5_8_concretize_infeasible_check` — engine's
`_addr_feasible` drops candidates that violate `path_condition`.

**P5.9** `test_p5_9_concretize_refused_terminal` — strategy returning
zero decisions terminates the path with `concretization-refused`.

**P5.10** `test_p5_10_legacy_callable_still_works` — pre-Phase-5
`concretize=lambda fork: [k]` keeps working through the back-compat
adapter.

### Phase 6 — region-aware memory + first sink oracles

**P6.0** `test_p6_0_resume_addr_symbolic_substrate_hook` /
`_round_trip` — the `resume_addr_symbolic` C++ hook writes a
z3 expression into an address slot; `get_value_at` reads it back.

**P6.1** `test_p6_1_split_by_region_two_regions` /
`_engine_forks` — `ConcretizeByRegion(layout)` returns a
`SplitByRegion`; engine forks one child per region with
`addr_var ∈ region` asserted.

**P6.2** `test_p6_2_split_by_region_offset_stays_symbolic` —
in-region offset stays free: at least two distinct addresses
satisfy each child's constraint.

**P6.3** `test_p6_3_constrain_to_arbitrary_predicate` —
`ConstrainTo(addr_var % 8 == 0)` lands on the child's
path_condition.

**P6.4** `test_p6_4_lazy_region_materialization` — empty layout +
`lazy_default=True` materializes a `LazyRegion` and emits
`region_materialized`.

**P6.5** `test_p6_5_lazy_region_budget_caps` — budget=2; third
LazyRegion materialization rejected with
`lazy_budget_exhausted`.

**P6.6** `test_p6_6_overlay_symbolic_write_concrete_read` —
symbolic Store, concrete Select returns a non-trivial z3
expression.

**P6.7** `test_p6_7_overlay_concrete_write_symbolic_read` —
concrete byte mirrors into the overlay; symbolic-offset read
reproduces the value with the right model.

**P6.8** `test_p6_8_oob_sink_fires_on_unsafe_read` — concrete-mode
OOB findings on enumerated addresses past a region's end.

**P6.9** `test_p6_9_null_deref_sink_fires` — concrete-mode null
finding when the strategy enumerates 0.

**P6.10** `test_p6_10_div_by_zero_sink_fires` — symbolic-mode
finding via intercept-driven `binary_op` divisor (no ptr_add
involvement); witness model contains `b_sym == 0`.

**P6.11** `test_p6_11_fatal_sink_terminates_path` —
`fatal=True` ends the OOB path with `Terminal.SINK_HIT`.

**P6.12** `test_p6_12_regions_touched_summary` —
`path.regions_touched()` aggregates per-region read/write counts.

**P6.13** `test_p6_13_oob_worked_example` — CWE-787-style: an
8-byte `g_buf` and a `ConcretizeFinite` enumeration over 8
candidate addresses; OOBSink records reproducible Findings on
the OOB children.

### Phase 7 — substrate dispatch + worked notebook polish (delivered)

**Substrate dispatch.** `PythonPolicy::ptr_add`, `ptr_diff`, and
`ptr_offset` now dispatch through Python first
(`SymbolicInterpreter.cpp:442/461/485`), with cache fields
`cached_ptr_*_` mirroring the `binary_op` / `cast` shape. The
existing concrete fallback runs only when the policy returns
`NotImplemented`, so callers without a `ptr_*` method see no
behavior change. `InterceptorPolicy.{ptr_add, ptr_diff,
ptr_offset}` lower symbolic operands to z3 BitVec(64) — base is
zero-extended, index is sign-extended; element scaling is
multiplied in z3; `ptr_diff`'s element_size division is `UDiv`.

**Test catalog (`tests/symex/test_phase7.py`):**

- **P7.1** `test_p7_1_ptr_add_dispatches_through_python` —
  proves the substrate emits a z3 `address_expr` at suspension
  via the presence of a `MEMADDR_CONCRETIZE` event.
- **P7.2** `test_p7_2_addr_feasibility_filters_unreachable_decisions`
  — with `idx ∈ [0, 3]` constrained, ConcretizeFinite's
  out-of-range candidate is rejected E2E by the strategy's
  `_addr_feasible` check (vacuous pre-Phase 7).
- **P7.3** `test_p7_3_constrain_to_alignment_no_concrete_fallback`
  — `ConstrainTo(addr & 7 == 0)` over a synthesized z3
  `address_expr` lands on the child path's path_condition; the
  `constrain_to_concrete_addr` regression-guard event does *not*
  fire.
- **P7.4** `test_p7_4_oob_sink_symbolic_witness_through_split_by_region`
  — drives `_dispatch_split_by_region` over a region whose size
  is not a multiple of the access size; `OOBSink._check_symbolic`
  emits a Finding for the partial-overflow at the upper boundary.
- **P7.5** `test_p7_5_cwe787_oob_write_witness` — the
  CWE-787 worked example. `store_at(base, idx, value)` over
  `dst[16]` with `ConcretizeFinite` enumerating in/OOB
  addresses; OOB children produce reproducible `oob_write`
  Findings with witness `index = resolved_addr - dst.base`.
- **P7.6** `test_p7_6_copy_into_loop_walkthrough` — end-to-end
  exercise of `copy_into` from `tests/symex/c/cwe787_oob_write.c`,
  verifying both branches of the bounds check (8 src reads + 8
  dst writes on the safe path; 0 dst writes on the early-return
  path).
- **P7.7** `test_p7_7_docstring_examples` — `doctest.testmod`
  sweep over the symex package; modules without examples are
  skipped.

### Phase 8a — symbolic-LOAD resolution (delivered)

The substrate gap Phase 7 deferred is now closed. `exec_load` and
`exec_store` consult `policy.exec_symbolic_load` /
`exec_symbolic_store` *before* the suspension path; PythonPolicy's
overrides cache `cached_symbolic_load_` / `cached_symbolic_store_`
and dispatch to `InterceptorPolicy.symbolic_load` /
`symbolic_store`. With `_region_at_suspension` set (by
`SplitByRegion`), the dispatch reads/writes through
`region.select_byte` / `store_byte` little-endian — returning a z3
Concat of per-byte `Select`s — so the resumed substrate continues
without re-suspending. End-to-end `engine.explore` through
`SplitByRegion`, `ConstrainTo`, and `LazyRegion` flows now works
organically.

**Test catalog (`tests/symex/test_phase8a.py`):**

- **P8a.1** `test_p8a_1_split_by_region_load_via_overlay_e2e` —
  the resumed path completes; the load's recorded MEMORY_READ
  event carries a z3 expression as its `value`.
- **P8a.2** `test_p8a_2_split_by_region_offset_stays_symbolic_e2e`
  — the in-region offset stays free under the path condition;
  multiple distinct in-region addresses are admissible end to end.
- **P8a.3** `test_p8a_3_oob_sink_symbolic_witness_e2e` — the
  Phase 7 P7.4 setup driven through `engine.explore`; OOBSink's
  symbolic-mode Finding witnesses the partial-overflow window.
- **P8a.4** `test_p8a_4_overlay_concrete_then_symbolic_read` — a
  symbolic read materializes the overlay; a subsequent concrete
  write is mirrored in (Phase 6 invariant); a symbolic read
  constrained to the write's offset returns the written byte.
- **P8a.5** `test_p8a_5_constrain_to_alignment_and_overlay_load`
  — ConstrainTo's predicate lands on path_condition, and a
  region-tagged child sees `symbolic_load` return a z3 expression
  rather than collapsing to default-0.
- **P8a.6** `test_p8a_6_lazy_region_load_e2e` — a pre-declared
  LazyRegion participates in `ConcretizeByRegion`; the resumed
  load reads against the freshly-minted overlay.
- **P8a.7** `test_p8a_7_no_region_falls_back_to_suspension` —
  without `_region_at_suspension`, `symbolic_load` returns
  NotImplemented and the existing suspension path fires; with
  an empty strategy the path terminates `CONCRETIZATION_REFUSED`.

**Future work still out of scope:**

- **Typed pointer values.** A region × interval representation
  (a distinct `SymExpr` shape) instead of flat BitVec(64).
  Z3's theory of arrays handles the targets we care about.
- **Cross-path state merging.** Per the non-goals.
- **Auto-derived layouts.** Layouts are still analyst-supplied;
  points-to-driven `ConcretizeByRegion` is a future phase.
- **Float-typed overlay slots.** `_coerce_store_value` lifts ints
  / pointers / BitVecs; IEEE-typed stores aren't wired through
  the overlay yet (the substrate's float path still rounds to a
  bit pattern, but Phase 8a doesn't model float byte
  decomposition end to end).
- **Custom symbolic memory models.** The `symbolic_load` /
  `symbolic_store` hooks aren't yet exposed on
  `engine.intercept`; analyst-defined heap shapes (e.g. "every
  malloc(N) returns a fresh region") would be a future
  addition with no further substrate work needed.

### Phase 8b — symbolic returns + global access events (delivered)

Two surgical fixes that close honesty gaps Phase 8a left visible:

- **Symbolic returns no longer collapse to 0.**
  `read_return_value` (in `InterpreterLoop.h`) used to overwrite
  the live `ret_from_inst` with a slot read of `frame.return_ptr`.
  For symbolic returns the slot was never written (the default
  `mem_write` chain drops z3 values), so `path.return_value` on a
  function whose hooks made the return symbolic silently came back
  as `0` — no error, no warning. A new `bool has_ret_value` thread
  through `exec_ret` short-circuits to `ret_from_inst` whenever the
  RET carried an operand. Aggregate-style returns (RET without
  operand, function memcpy'd into the slot) are unaffected.

- **`engine.observe.global_read` / `global_write` actually fire.**
  The events were declared, exported, and selector-matched but no
  dispatch path ever called `_fire_observers(GLOBAL_READ, …)`.
  `InterceptorPolicy` now fans `mem_read` / `mem_write` (and the
  Phase 8a `symbolic_load` / `symbolic_store`) out to the global-
  event registry when the access lands in a `kind == "global"`
  region. Lazy and function-placement regions are filtered out —
  they aren't analyst-named globals. Goal #9 ("per-path trace of
  which globals were accessed and when") is now real.

**Test catalog (`tests/symex/test_phase8b.py`):**

- **P8b.1** symbolic return propagates through `path.return_value`
  (post-fix is z3; pre-fix collapsed to 0).
- **P8b.2** concrete primitive return regression — same value as
  pre-fix.
- **P8b.3** multi-frame concrete call regression — exercises the
  callee_result branch of `exec_ret` across recursion.
- **P8b.4** aggregate return — placeholder skip (no corpus
  function exposes a no-operand RET; transitively covered by the
  unchanged InterpretIR suite).
- **P8b.5** observe.global_read fires on a concrete read.
- **P8b.6** observe.global_write fires on a concrete write.
- **P8b.7** observe.global_read fires on a `symbolic_load` access.
- **P8b.8** lazy regions don't fire global_read (kind filter).
- **P8b.9** function-placement regions don't fire global_read
  (kind filter).
- **P8b.10** selector by name routes correctly.

### Phase 8c — symbolic-capable substrate slots + drop RET's operand (delivered)

Phase 8b's `read_return_value` short-circuit was a surgical patch
on a structural bug: the substrate's symbolic memory model only
covered analyst-named layout regions. Substrate-internal
allocations (return slot, `ALLOCA/ARG`, `ALLOCA/LOCAL`, VLA
storage) had no overlay, so a z3 store to one of those addresses
was silently dropped by the dispatcher's default `mem_write`.
Phase 8b sidestepped this for primitive returns by preferring
`RET`'s SSA operand. The same gap remained everywhere else (the
next analyst who passes a z3 through `ALLOCA/ARG` to a callee
that runs for real would see the input erased) and the workaround
cemented a confusing dual-source-of-truth in the IR (RET carries
the value AND the preceding store puts it in the slot).

Phase 8c collapses the duplication:

- **Substrate-internal slots can hold z3.** `Path` carries a
  `_symbolic_shadow: dict[(addr, size) -> z3 expr]` whose
  reference is shared with the `InterceptorPolicy` constructed
  for that path. The dispatcher's default `mem_write` routes z3
  values to the shadow keyed on `(addr, size)`; the default
  `mem_read` consults it before falling back to concrete bytes.
  Concrete writes evict the shadow entry at that key, preserving
  store / load consistency. `snapshot()` round-trips the shadow;
  `restore()` mutates in place so any policy still holding the
  reference sees the post-restore state. Partial-overlap reads
  and width-mismatch reads are out of scope (the substrate's IR
  lowering keeps slot widths consistent).

- **RET is a pure terminator.** `IRGen::EmitReturnStmt` no longer
  sets `inst.operand_indices` on the RET; the value flows
  exclusively through the preceding `RETURN_PTR` + `MEMORY/STORE`
  into the slot. `RetInst::return_value()` is removed from the
  C++ API, the Python binding, and the type stub.

- **Phase 8b's substrate workaround is reverted.**
  `read_return_value` returns to its pre-Phase-8b shape: no
  `has_ret_value` parameter, no SSA-operand short-circuit. The
  slot read is the universal mechanism. The Phase 8b user-facing
  win (P8b.1: symbolic primitive returns survive in
  `path.return_value`) still holds — now via the shadow-backed
  slot read, not via an operand bypass.

- **Phase 8b's global-event fan-out stays.**
  `_fire_global_event_if_applicable` and the four call sites in
  `mem_read` / `mem_write` / `symbolic_load` / `symbolic_store`
  are orthogonal to the slot fix and remain in place.

**Test catalog (`tests/symex/test_phase8c.py`):**

- **P8c.1** an `InterceptorPolicy.mem_write` of a z3 expression
  to a concrete substrate-allocated address followed by a
  same-`(addr, size)` `mem_read` returns the stored expression.
  Two distinct policies share the path's shadow, mirroring the
  cross-step flow that the return slot, `ALLOCA/ARG`, and
  `ALLOCA/LOCAL` all rely on.

### Phase 8d — close analyst-facing gaps (delivered)

Phase 8d is a "honesty pass": it closes four loose ends Phase 8c
left visible, without architectural rework.

- **`engine.intercept.symbolic_load` / `symbolic_store`.** The
  substrate has consulted these hooks since Phase 8a, but the
  `InterceptDispatcher` only routed `memory_read` / `memory_write`
  events. Phase 8d adds `SYMBOLIC_LOAD` / `SYMBOLIC_STORE` to
  `EventKind`, exposes them through `engine.intercept.*`, and
  wraps the existing region-overlay logic in a chain bottom that
  analyst handlers compose over via `next_hook`. A new `region=`
  selector matches against `path._region_at_suspension` so an
  analyst can scope a handler to a single SplitByRegion-tagged
  region without it firing on unrelated paths.

- **Init-time z3 args persist.** `engine._init_path` migrates the
  init-policy's symbolic shadow to the path's durable shadow after
  `init_state` runs. Pre-Phase-8d, a z3 written to an
  `ALLOCA/ARG` slot during initialization landed in the
  init-policy's ephemeral shadow and was lost when the path was
  created; the body's first read returned the slot's
  pre-symbolic concrete bytes. Post-fix, `engine.explore("foo",
  args=[z3_var])` works as advertised.

- **Aggregate-return E2E coverage.** P8b.4 was a documented skip
  ("no corpus function exposes RET-without-operand"); after
  Phase 8c every RET is no-operand, so the actual gate is
  `read_return_value`'s `sz > 8` branch. The un-skipped test
  drives `make_large` from `tests/InterpretIR/test_byvalue.c`
  (returns `struct Large`, sz=20) and verifies the path
  completes with the slot pointer. (A separate substrate quirk
  with `LOCAL_VALUE` ALLOCAs through `InterceptorPolicy` keeps
  the test from asserting field values; documented inline.)

- **Per-block-enter event.** A new `on_enter_block(state, block)`
  policy callback fires at the top of every `enter_block` in
  `InterpreterLoop.h`. `ConcretePolicy` keeps a no-op default;
  `PythonPolicy` calls back into Python with the block id. The
  dispatcher fans out to `engine.observe.block_enter` and
  appends a `BLOCK_ENTER` event to `path.events`. `path.dot_cfg`
  walks `BRANCH` and `BLOCK_ENTER` events together, drawing
  edges for every block visited — branchless functions now
  render real graphs instead of the empty placeholder.

**Test catalog (`tests/symex/test_phase8d.py`):**

- **P8d.1** `intercept.symbolic_load(region="g_buf")`
  short-circuits and the analyst's z3 expression appears as the
  load result; the region overlay is not consulted.
- **P8d.2** Two handlers compose: outer forwards via
  `next_hook`; inner short-circuits with its own value; the
  inner result reaches the load.
- **P8d.2b** Handler scoped to a non-matching region is filtered
  out — no spurious dispatch on unrelated paths.
- **P8d.3** `engine.explore("symbolic_test_add_i32",
  args=[z3.BitVec("a", 32), z3.BitVec("b", 32)])` returns a path
  whose `return_value` is structurally `a + b`. Pre-8d the z3
  args were dropped in init.
- **P8d.4** `engine.observe.block_enter` fires per visited block
  on a branchless function; `path.dot_cfg` renders edges for
  every visit (no more empty placeholder).

### Phase 8e — fix LOCAL_VALUE alloca regression + float overlay (delivered)

Phase 8d's "honesty pass" left two threads dangling. Phase 8e
closes both.

- **LOCAL_VALUE alloca regression.** Phase 8d's tightened
  P8b.4 surfaced that `engine.explore("make_large", args=[7])`
  silently returned a return slot full of zeros — the body's
  field stores landed at address 0 instead of the local's slot.
  Three substrate seams were complicit: (a) `value_to_python`
  lowers a `Value` to a bare `PyLong`, dropping the `("ptr", N)`
  tag carried by `make_literal_ptr`; (b) the ptr_add /
  ptr_offset C++ fallbacks ran results through that lowering,
  producing plain ints from pointer arithmetic; (c)
  `PythonPolicy::extract_address` only accepted tuple-tagged
  pointers, so any plain-int address triggered the
  symbolic-suspension path, which the default address strategy
  collapsed to 0. Phase 8e wraps the ptr_add / ptr_offset
  fallbacks in `make_literal_ptr` and teaches `extract_address`
  to also accept bare PyLongs (a plain int IS a concrete
  address). With both fixes, `engine.explore` is correctness-
  equivalent to `ConcretePolicy` on every function in the
  corpus that exercises LOCAL_VALUE allocas through GEP_FIELD.

- **Float-typed overlay slots.** `_coerce_store_value` now packs
  Python floats via `_struct.pack("<f"|"<d", val)` and lifts the
  IEEE byte pattern into a `z3.BitVecVal`. A symbolic-overlay
  float store + load round-trips through the bit pattern. The
  read path returns the z3 expression unchanged; substrate-
  facing concretization (when a unique value is forced) is left
  for a future pass.

**Test catalog (`tests/symex/test_phase8e.py`):**

- **P8e.1** `engine.explore("make_large", args=[7])` decodes the
  return slot to `[7, 8, 9, 10, 11]` (pre-fix it was all zeros).
- **P8e.2** Functions exercising LOCAL_VALUE allocas through
  GEP_FIELD (`test_byvalue`, `test_struct_assign`,
  `test_pointers`, `test_init_lists`) match `ConcretePolicy`'s
  return value when run through `engine.explore`.
- **P8e.3** `_coerce_store_value` packs Python floats into IEEE
  bit patterns; a symbolic-overlay float store + same-address
  load round-trips through the bit pattern.

P8b.4's "substrate quirk" caveat is removed — the tightened
test now asserts `[7, 8, 9, 10, 11]` field values directly.
Three pre-existing `tests/InterpretIR/test_symbolic_addresses.py`
tests that relied on plain-int suspension were reworked to use
an opaque-sentinel policy (`_OpaqueAddr`) so they still drive
the suspension/resumption loop without exploiting the old bug.

### Phase 8f — multi-function entry exploration (delivered)

`engine.explore("foo")` runs from one entry. Real harness-style
analysis usually wants "explore every function whose name matches
X" — every public API entry, every `on_*_event`, every syscall
handler. Phase 8f adds `engine.explore_many(start_funcs)`:

- `start_funcs` accepts a list of names / IRFunctions (mixed
  allowed), a compiled `re.Pattern` matched against function
  names, or a callable `name -> bool` predicate. Pattern and
  predicate forms iterate `mx.ast.FunctionDecl.IN(index)` and
  de-duplicate by IRFunction id so multi-TU declarations don't
  double up. Empty resolution raises `ValueError` (a typo'd
  regex would otherwise vanish into a silent no-op).
- Entries drive sequentially under one shared `Layout` (matching
  `explore`'s pin-on-first-call behavior) and one shared `until`.
  The user's `until` sees the cumulative `ExploreState` —
  `paths` is every path produced across every entry — so a
  threshold flips True from any entry's progress. A cross-entry
  guard re-checks `until` before initializing each next entry,
  so a triggered predicate cleanly skips remaining entries
  (they leave no zero-step paths behind).
- Each `Path` carries `entry_func` (the IRFunction it started
  in), propagated through forks. `PathSet.by_entry()` groups
  results, preserving resolution order.

Per-entry `args` mapping (`{"foo": [1, 2], "bar": [3]}`) and
concurrent entry exploration are deferred — sequential covers
every harness shape we have today, and per-path z3 solver state
isn't trivially shareable across processes anyway. Sub-block
resume granularity and path serialization, the other two Phase 8f
candidates the original sketch surfaced, remain deferred (both
are substrate-shaped).

**Test catalog (`tests/symex/test_phase8f.py`):**

- **P8f.1** Two-name list resolves to two IRFunctions; each
  entry's return value matches `ConcretePolicy`.
- **P8f.2** A compiled regex resolves to the known
  `test_(byvalue|struct_assign|init_lists|pointers)` set and
  every match completes.
- **P8f.3** A callable predicate resolves a single entry;
  `factorial(5)` returns 120.
- **P8f.4** Empty resolution (regex matching nothing, predicate
  always-False) raises `ValueError`.
- **P8f.5** A mixed list of `str` and pre-resolved IRFunction
  resolves both.
- **P8f.6** `path.entry_func` is the IRFunction the path
  started in, set on every returned path (forks too).
- **P8f.7** `until.steps(1)` firing on the first entry's first
  slice short-circuits the cross-entry guard so the second
  entry contributes no paths.

After Phase 8f the symex API supports single-function entry
(`explore`), multi-function entry (`explore_many`), per-path
queries (`PathSet`, `path.events`, `path.dot_cfg`), and
aggregate queries (`PathSet.by_entry()`) — enough for "find
OOB writes across every public entry in this module."

### Phase 9 — total address-space mediation (delivered)

Phase 9 puts the analyst in the loop for every address the engine
assigns. Two directions:

**Forward (place):** `intercept.address_for(kind=, name=, eid=)` fires
when the engine needs an address for a function, global, or TLS entity.
Precedence: pre-placed in `Layout` wins → intercept chain → substrate
auto-allocator. Memoized per `canonical_eid` on the engine so
`explore_many` reuses placements across entries. The hook receives
`(ctx, eid, name, kind, size, align, next_hook)` and may return an
`int` address or forward via `next_hook(...)`.

**Reverse (resolve):** `intercept.indirect_call` now accepts
`target_kind="concrete"` / `"symbolic"` selectors. When a call target
is symbolic, the substrate suspends with a `"call-addr"` sub_kind and
the engine fires the `target_kind="symbolic"` handler. Returning a list
of addresses forks one child path per candidate, each with
`target_expr == addr` asserted. `Terminal.UNRESOLVED_CALL` terminates
paths whose handler returns `None`.

**Layout additions:**
- `place_functions(mapping)` — atomic bulk placement from `{name: addr}`.
- `place_globals(entries)` — atomic bulk placement from list of tuples.
- `next_function_address(*, align=4)` — cursor-based allocation in the
  `0x4000_0000_0000_0000` reserved range.
- `tls_offset(eid)` — stable per-entity TLS offset within the TLS segment
  (base at `0x6000_0000_0000_0000`). Per-path TLS isolation is
  implemented via `path._tls_shadow` (same shape as `_symbolic_shadow`);
  handlers install `intercept.memory_read/write` to route TLS reads to the
  per-path dict.

**Path additions:** `path.tls_base` (inherited through forks);
`path._tls_shadow` (per-path TLS value dict, cloned at fork time).

**Telemetry:** `observe.address_resolved` fires on every address
invention with `source` (`"pre_placed"` / `"intercept"` / `"auto_alloc"`)
and `handler` (qualname or `None`). `INDIRECT_CALL_RESOLVED` events
record `fork_index` and `candidates` for provenance.

`engine.value_origins` side-table is available for Phase 10 lineage
walks; mint sites that ship in Phase 9 are `address_for`-intercept
placements.

Deferred: symbolic addresses returned from the forward hook (substrate
expects concrete ints); per-path TLS base without shared ConcreteMemory
(requires state-level address-cache invalidation, a Phase 9b substrate
item).

Test suite: `tests/symex/test_phase9.py` (15 tests, P9.1–P9.13
including P9.7b/c TLS isolation); `tests/symex` count is 131 passed.

### Phase 10 — `path.origin(expr)` provenance walk (delivered)

Phase 10 adds symbolic-value provenance to every `Path`. The entry point
is `solver.fresh_int(name, *, size, ...)`, which now records a mint-site
dict into `path._origin_by_name`:

```python
{
    "kind":    "fresh_int",
    "name":    name,
    "size":    size,       # bytes
    "path_id": path.id,
    "step":    path.steps, # interpreter step counter at mint time
}
```

Two new `Path` methods consume the table:

- `path.origin(expr) -> list[dict]` — DFS-walks a z3 expression,
  collects the origin record for every distinct leaf `BitVecRef` variable.
  Unknown variables (minted outside `fresh_int`, e.g. raw `z3.BitVec`)
  produce `{"kind": "unknown", "name": <str>}`. Duplicate leaf
  appearances are deduplicated; concrete literals return only unknown
  records.
- `path.origin_tree(expr) -> dict` — recursive view:
  - Leaves: `{"kind": "leaf", "name": ..., "origin": <record>}`
  - Compound nodes: `{"kind": "op", "op": <str>, "args": [...]}`

`_origin_by_name` is propagated in `Path.clone()` and
`SymExEngine._fork_child()` so forked paths retain full provenance of
all inputs minted before the fork. Newly minted variables on a child
path stay local to that child.

Test suite: `tests/symex/test_phase10.py` (10 tests, P10.1–P10.10);
`tests/symex` count is 141 passed.

### Phase 11 — PathSet analysis + Path taint helpers (delivered)

Phase 11 completes the analyst-facing result API. After `engine.explore`
returns a `PathSet`, analysts can now answer high-level questions without
manually iterating over paths.

**PathSet additions:**

```python
paths.all_terminal()          # bool — no live paths remain
paths.terminals()             # {terminal_value: PathSet} partition
paths.findings()              # FindingsList across all paths (path_id injected)
paths.summary_table()         # human-readable text report
paths.counter_example(pred)   # (path, {name: int} model) or None
```

`counter_example(pred)` walks paths, applies `pred(path)`, and asks the
per-path SMT solver for a satisfying model. Returns the first `(path,
model)` pair where both hold; skips UNSAT paths; returns `None` when
nothing matches.

**Path taint helpers** — thin wrappers over `path.origin()`:

```python
path.taint_sources(expr)  # frozenset[str] of fresh_int names in expr
path.is_tainted(expr)     # bool shorthand
```

`taint_sources` excludes unknown/external variables (created outside
`solver.fresh_int`) so it only reports analyst-controlled inputs.

Test suite: `tests/symex/test_phase11.py` (14 tests, P11.1–P11.14);
`tests/symex` count is 155 passed.

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
tests/symex/test_phase7.py
tests/symex/test_phase8a.py
tests/symex/test_phase8b.py
tests/symex/c/cwe787_oob_write.c
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

- Phases 0–7 + 8a complete, each with its test suite green.
- Phase 6: `tests/symex/test_phase6.py` 14 tests pass; sinks
  surface findings end-to-end on the worked example.
- Phase 7: `ptr_add` / `ptr_diff` / `ptr_offset` dispatch through
  Python; `tests/symex/test_phase7.py` (7 tests, P7.1–P7.7)
  green; the CWE-787 worked example produces a reproducible
  `oob_write` Finding (P7.5).
- Phase 8a: substrate consults `symbolic_load` / `symbolic_store`
  before suspending; `tests/symex/test_phase8a.py` (7 tests,
  P8a.1–P8a.7) green; total `tests/symex` count is 86.
- Phase 8b: `read_return_value` short-circuits to `ret_from_inst`
  for primitive RETs with an operand; `InterceptorPolicy` fans
  global-region accesses out to `GLOBAL_READ` / `GLOBAL_WRITE`
  observers; `tests/symex/test_phase8b.py` (10 tests,
  P8b.1–P8b.10; one skipped) green; total `tests/symex` count
  is 96.
- Phase 8c: substrate-internal slots hold symbolic values via a
  per-`Path` shadow consulted by the dispatcher's default
  mem_read / mem_write; RET becomes a pure terminator
  (`RetInst::return_value()` removed; `IRGen` stops setting the
  operand); Phase 8b's `has_ret_value` short-circuit is reverted
  and P8b.1's symbolic-return invariant now holds via the slot;
  `tests/symex/test_phase8c.py` (1 test, P8c.1) green; total
  `tests/symex` count is 97 collected (96 passed + 1 skipped).
- Phase 8d: `engine.intercept.symbolic_load` / `symbolic_store`
  exposed via `EventKind.SYMBOLIC_LOAD` / `SYMBOLIC_STORE` with
  a `region=` selector; init-time z3 args migrate from
  init-policy shadow to path shadow so `engine.explore("foo",
  args=[z3_var])` works; P8b.4 un-skipped against `make_large`
  for the sz>8 RET branch; new `on_enter_block` policy callback
  fans out as `engine.observe.block_enter` and `path.dot_cfg`
  renders block-visit edges. `tests/symex/test_phase8d.py` (5
  tests, P8d.1–P8d.4) green; `tests/symex` count is 103 passed,
  0 skipped.
- Phase 8e: ptr_add / ptr_offset C++ fallbacks preserve the
  `("ptr", N)` tag (no more silent collapse to 0 through the
  default address strategy); `extract_address` accepts bare
  PyLong addresses; `_coerce_store_value` packs Python floats
  into IEEE bit patterns. P8b.4 tightened to assert field
  values; three InterpretIR tests reworked to use an opaque
  sentinel after the substrate's int-as-address normalization.
  `tests/symex/test_phase8e.py` (3 tests, P8e.1–P8e.3 with 4
  parametrizations on P8e.2) green; `tests/symex` count is 109
  passed, 0 skipped.
- Phase 8f: `engine.explore_many(start_funcs)` accepts a list
  of names / IRFunctions, a compiled regex pattern, or a name
  predicate, and drives one combined exploration over every
  matched entry under a shared `Layout` and a shared `until`.
  Each `Path` carries `entry_func`; `PathSet.by_entry()` groups
  the result by entry in resolution order. Empty resolution
  raises `ValueError`. Sub-block resume granularity, path
  serialization, and per-entry args mapping remain deferred.
  `tests/symex/test_phase8f.py` (7 tests, P8f.1–P8f.7) green;
  `tests/symex` count is 116 passed, 0 skipped.
- Phase 9: total address-space mediation — `intercept.address_for`
  + `observe.address_resolved` (forward); `intercept.indirect_call`
  with `target_kind="symbolic"` + `Terminal.UNRESOLVED_CALL`
  (reverse); `Layout.place_functions`, `place_globals`,
  `next_function_address`, `tls_offset`; `Path.tls_base` +
  `_tls_shadow`. `tests/symex/test_phase9.py` (15 tests,
  P9.1–P9.13 with P9.7b/c TLS isolation) green; `tests/symex`
  count is 131 passed, 0 skipped.
- Phase 10: `path.origin(expr)` provenance walk — `solver.fresh_int`
  records mint-site metadata into `path._origin_by_name`; `Path.origin`
  DFS-walks a z3 AST to collect origin records; `Path.origin_tree`
  produces a recursive `{"kind":"leaf"/"op"}` view; propagated through
  `clone()` and `_fork_child`. `tests/symex/test_phase10.py` (10 tests,
  P10.1–P10.10) green; `tests/symex` count is 141 passed, 0 skipped.
- Phase 11: PathSet analysis + Path taint helpers — `PathSet.all_terminal`,
  `terminals`, `findings`, `summary_table`, `counter_example(pred)`;
  `Path.taint_sources(expr)` and `Path.is_tainted(expr)` thin aliases
  over `origin()`. `tests/symex/test_phase11.py` (14 tests, P11.1–P11.14)
  green; `tests/symex` count is 155 passed, 0 skipped.
- The 235-test pre-existing harness still passes (regression gate).
- Public API has docstrings; the README links to the Phase 7
  walkthrough.
- A new project-memory entry summarizes the API for future sessions.
