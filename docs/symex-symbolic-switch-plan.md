# Symbolic SWITCH plan

## Goal

When a SWITCH instruction's selector is a symbolic value (z3 BitVec), the
substrate currently calls `policy.extract_int(sel)` which returns `0` for
non-concrete values, picks whichever case covers `0` (or the default), and
proceeds down a single path. This loses the other branches.

Target behavior: fork into one path per case (and one for the default), each
carrying a path-condition constraint that pins the selector into that case's
range. Each case is treated like an entry point on a state-machine — the
substrate hands the driver a list of (range, target_block) pairs and the
driver realizes them as forked paths.

## Conceptual model

A SWITCH with cases `[1 → A]`, `[2..5 → B]`, `[7 → C]`, `[default → D]` and
symbolic selector `S` becomes 4 forked paths:

| path | target | path-condition addition         |
|------|--------|---------------------------------|
| 1    | A      | `S == 1`                        |
| 2    | B      | `2 <= S && S <= 5`              |
| 3    | C      | `S == 7`                        |
| 4    | D      | `!(S == 1 \|\| (2 <= S && S <= 5) \|\| S == 7)` |

A case is treated as part of the instruction stack/state machine: the driver
clones the snapshot, enters the case's target block, then the path's solver
gets the constraint added. Infeasible paths (where the constraint conflicts
with the path's existing condition) are dropped.

## Files to touch

### 1. `include/multiplier/IR/Interpret/Continuation.h`

Add a new continuation type alongside `BranchContinuation`:

```cpp
struct SwitchCase {
    int64_t low;
    int64_t high;
    IRBlock target_block;
};

template <typename ValueT, typename RC>
class SwitchContinuation : public Continuation<ValueT, RC> {
    ValueT selector_;
    RawEntityId sel_eid_;
    std::vector<SwitchCase> cases_;   // non-default cases, in source order
    IRBlock default_block_;            // default — `id().Pack() == 0` if none
public:
    SwitchContinuation(ref_t<InterpreterState<ValueT, RC>> snap,
                       ValueT selector, RawEntityId sel_eid,
                       std::vector<SwitchCase> cases,
                       IRBlock default_block);
    const ValueT &selector() const { return selector_; }
    RawEntityId selector_eid() const { return sel_eid_; }
    const std::vector<SwitchCase> &cases() const { return cases_; }
    const IRBlock &default_block() const { return default_block_; }
    // Accept(visitor) routing — match the existing pattern for branches.
};
```

### 2. `include/multiplier/IR/Interpret/Policy.h`

Add a precise concreteness predicate for ints (the existing `extract_int`
silently returns 0 for symbolic values, which is what bit us). Default is
"always concrete" so ConcretePolicy needs no override:

```cpp
std::optional<int64_t> try_extract_int(const ValueT &val) {
    return self().try_extract_int_impl(val);
}
std::optional<int64_t> try_extract_int_impl(const ValueT &val) {
    return self().extract_int(val);   // Concrete: always succeeds
}
```

PythonPolicy overrides to return `std::nullopt` for non-PyLong values
(the way `is_true` already does).

### 3. `include/multiplier/IR/Interpret/InterpreterLoop.h::decide_switch`

Replace the unconditional `extract_int` with a `try_extract_int`. On
`std::nullopt` (symbolic), gather all cases + default and emit a switch
continuation:

```cpp
auto maybe_sel = policy.try_extract_int(sel);
if (maybe_sel) {
    int64_t sel_val = *maybe_sel;
    // ... existing concrete path: pick matching case or default ...
    return;
}

// Symbolic selector: collect case ranges and emit a switch continuation.
std::vector<SwitchCase> case_list;
IRBlock default_block{};
for (auto sc : sw->cases()) {
    if (sc.is_default()) {
        default_block = sc.target_block();
    } else {
        case_list.push_back({sc.low(), sc.high(), sc.target_block()});
    }
}
sched.on_switch(sel, sel_eid, std::move(case_list),
                default_block, state.clone());
state.work_stack.clear();
```

### 4. `include/multiplier/IR/Interpret/Policy.h::Scheduler` + scheduler impls

Add to the CRTP base:

```cpp
void on_switch(ValueT selector, RawEntityId sel_eid,
               std::vector<SwitchCase> cases,
               IRBlock default_block,
               auto &&state) {
    self().on_switch(std::move(selector), sel_eid,
                     std::move(cases), default_block,
                     std::forward<decltype(state)>(state));
}
```

`NoOpScheduler::on_switch` (in Policy.h) pushes a `SwitchContinuation` onto
`outcome.continuations`.

### 5. `bindings/Python/SymbolicInterpreter.h::PythonScheduler`

Add `on_switch` mirroring the other scheduler hooks — pushes a
`SwitchContinuation<SharedPyPtr, PyObjectRC>` onto `outcome.continuations`.

### 6. `bindings/Python/SymbolicInterpreter.cpp::SymbolicStep`

In the existing block that translates `outcome.continuations` into the
result dict's `forks` list, add a case for `SwitchContinuation`. Each fork
entry is a Python dict shaped like:

```python
{
    "kind": "switch",
    "selector": <z3 BitVec or python int>,
    "selector_eid": <int>,
    "cases": [(low, high, target_block_eid), ...],
    "default_block_eid": <int or None>,
    "snapshot": <opaque InterpreterState wrapper>,
}
```

`target_block_eid` and `default_block_eid` are the packed entity ids of the
IRBlocks (matching how `branch` forks already report block ids). The snapshot
is opaque to Python — it's handed back to `_interp.resume_from_switch_case`
or similar (see step 7).

### 7. New substrate entry point: resume at a switch case

Add a Python-callable to the existing interpreter dispatch (`Interpreter.cpp`)
that takes a switch-fork dict, picks one case (by index, or `-1` for default),
and:

  * clones the snapshot,
  * pushes an ENTER_BLOCK work item for the chosen target,
  * returns the new state (or wraps it in the engine's existing state
    container).

Two sketches; pick whichever fits the existing API better:

```python
# Option A — one call per case, like resume_addr does for memory:
_interp.resume_switch_case(snapshot, target_block_eid)

# Option B — caller passes the case index from the fork dict:
_interp.resume_switch_case(fork_dict, case_index_or_neg1_for_default)
```

The constraint addition (`solver.add(low <= sel && sel <= high)`) happens
on the Python driver side, not in the substrate.

### 8. Driver: `bindings/Python/symex/engine.py`

In the BFS / DFS fork-handling section (where `fork["kind"] == "branch"` is
handled today), add a `"switch"` arm:

```python
elif fork["kind"] == "switch":
    sel = fork["selector"]
    cases = fork["cases"]                       # list of (lo, hi, target)
    default_eid = fork["default_block_eid"]    # may be None

    # One child per case.
    for low, high, target_eid in cases:
        child = self._fork_child_for_switch_case(
            path, fork["snapshot"], sel, low, high, target_eid)
        if child is not None:                   # feasibility check passed
            queue.append(child)

    # Default branch: constrain selector to be outside every case.
    if default_eid is not None:
        child = self._fork_child_for_switch_default(
            path, fork["snapshot"], sel, cases, default_eid)
        if child is not None:
            queue.append(child)
```

Helpers (new in engine.py):

```python
def _fork_child_for_switch_case(self, parent, snapshot, sel, low, high, target_eid):
    child = self._fork_child(parent, _interp.clone_state(snapshot))
    self._enter_block_in_state(child._state, target_eid)
    if _is_z3(sel):
        if low == high:
            child.solver.add(sel == low)
        else:
            child.solver.add(z3.And(sel >= low, sel <= high))
    if not child.solver.feasible():
        return None
    child.path_condition.append({
        "kind": "switch_case",
        "selector_eid": fork["selector_eid"],
        "low": low, "high": high,
    })
    return child

def _fork_child_for_switch_default(self, parent, snapshot, sel, cases, default_eid):
    child = self._fork_child(parent, _interp.clone_state(snapshot))
    self._enter_block_in_state(child._state, default_eid)
    if _is_z3(sel):
        for low, high, _ in cases:
            if low == high:
                child.solver.add(sel != low)
            else:
                child.solver.add(z3.Or(sel < low, sel > high))
    if not child.solver.feasible():
        return None
    child.path_condition.append({
        "kind": "switch_default",
        "selector_eid": fork["selector_eid"],
    })
    return child
```

`_enter_block_in_state` is the small new helper that pushes an ENTER_BLOCK
work item targeting the resolved IRBlock — this lives next to the existing
`_init_path` block-resolving code.

### 9. Path condition record shape

`Path.path_condition` is a list of dicts (matching the existing branch
record). Switch-case records use:

```python
{"kind": "switch_case", "selector_eid": <int>, "low": <int>, "high": <int>}
{"kind": "switch_default", "selector_eid": <int>}
```

`Path.condition_str()` should learn to render these as `S == 7` /
`2 <= S <= 5` / `S ∉ {1, 2..5, 7}` for human-readable summaries.

### 10. Events

`path.events` should record each switch fork the same way branch forks are
recorded today — one entry per case actually taken. Re-use the existing
`branch` event kind with a `direction` field, or introduce a `switch_case`
event kind. Recommend the latter for clarity:

```python
{"kind": "switch_case", "selector_eid": <int>,
 "low": lo, "high": hi, "target_block": <eid>}
{"kind": "switch_default", "selector_eid": <int>, "target_block": <eid>}
```

### 11. Tests

`tests/symex/test_phaseN_symbolic_switch.py` (pick the next free phase
number):

  * `test_symbolic_switch_three_cases_plus_default` — symbolic 8-bit
    selector, switch with 3 single-value cases + default, expect 4 paths.
  * `test_symbolic_switch_range_case` — case `[2..5]` adds the
    range constraint correctly; only one path per range.
  * `test_symbolic_switch_infeasible_case` — pre-constrain the path's
    solver so one case is unreachable; expect that path to be dropped.
  * `test_symbolic_switch_no_default` — a switch with no default block
    correctly emits only the case forks.
  * `test_concrete_switch_unchanged` — concrete selector still picks
    exactly one path (regression guard).

Each test inspects the path count, terminal kinds, and per-path
`path_condition` to confirm the right constraints landed.

## Order of work

1. `Continuation.h` — add `SwitchCase` and `SwitchContinuation`.
2. `Policy.h` — add `try_extract_int` (CRTP default + Python override).
3. Scheduler `on_switch` in both base and concrete schedulers.
4. `decide_switch` change.
5. `PythonScheduler::on_switch` and `SymbolicStep` translation.
6. `_interp.resume_switch_case` (or equivalent) Python-callable substrate
   entry.
7. Driver fork dispatch + helpers in `engine.py`.
8. `Path.path_condition` recording + `condition_str()` rendering.
9. Tests.

Each step should leave `python3 -m pytest tests/symex/ -x -q` green; the
last step adds new tests.

## Notes / pitfalls

* The selector might be a SymExpr (our Python placeholder) rather than a
  real z3 BitVec if some upstream cast hasn't been lowered to z3 yet.
  In that case `_is_z3(sel)` is False and the solver constraints are
  no-ops — the paths still fork structurally but feasibility checks
  always pass. Acceptable as a stop-gap; can be tightened later.

* `decide_switch` runs *after* the selector is computed (the work-stack
  push of `ANALYZE` for the selector at `decide_switch:1518` ensures
  this). The continuation captures the selector value, not the operand
  — so the symbolic value flows through cleanly without re-evaluation.

* Snapshot cloning is cheap (shared_ptr / PyObjectRC segments); the cost
  per switch is N small clones, not N full state copies.

* Path-condition feasibility: for paths with no prior symbolic
  constraints, every case is feasible and we always fork into N
  branches. That's expected — switches with O(256) ranges produce
  O(256) paths. If this becomes a problem, add a per-explore cap akin
  to `engine.lazy_region_budget`.
