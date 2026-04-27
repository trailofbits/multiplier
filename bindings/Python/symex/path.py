# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""A Path is one execution trace.

A Path wraps an interpreter state, a queryable `EventLog`, the
analyst's tag set, a per-path z3 solver (`_PathSolver`), the
accumulated branch path-condition, and the per-path back-edge counter.
`snapshot()` captures everything an analyst might want to roll back to
(including a fresh state clone) and `restore()` re-clones from the
snapshot so the snap stays reusable. `replay(modify=…)` runs the
engine forward from a snapshot with one mutation applied. `summary()`
and `dot_cfg()` produce human-readable views over the recorded event
stream.
"""

import multiplier as mx

from .dispatch import _z3_module
from .events import (
    EventLog, BRANCH, MEMORY_READ, MEMORY_WRITE, BranchDirection, Terminal,
    _FilterableList, _match,
)

_interp = mx.ir.interpret


_id_counter = [0]


def _next_id():
    _id_counter[0] += 1
    return _id_counter[0]


class FindingsList(_FilterableList):
    """Queryable list of `Finding` records on a Path. Filter syntax
    matches the EventLog: `path.findings.where(kind="oob_write")`,
    `path.findings.first(region="g_buf")`, etc."""

    def _match(self, finding, filters):
        # Adapt dataclass fields to the dict-keyed _match helper.
        return _match(_finding_as_dict(finding), filters)


def _finding_as_dict(f):
    if isinstance(f, dict):
        return f
    return {
        "kind": f.kind,
        "addr_eid": f.addr_eid,
        "step": f.step,
        "witness": f.witness,
        "region": f.region,
        "mode": f.mode,
    }


class _PathSolver:
    """Per-path z3 solver wrapper.

    Tracks the named symbolic inputs the analyst has minted via
    `fresh_int(...)` and rebuilds the underlying `z3.Solver()` lazily
    from the path's `path_condition` whenever the constraint set
    changes. Importing z3 only happens on first use, so analysts who
    don't use the solver don't pay for the import.
    """

    __slots__ = ("_path", "_solver", "_fresh_vars")

    def __init__(self, path):
        self._path = path
        self._solver = None
        self._fresh_vars = {}

    @property
    def solver(self):
        if self._solver is None:
            z3 = _z3_module()
            self._solver = z3.Solver()
            for cond in self._path.path_condition:
                self._solver.add(cond)
        return self._solver

    def fresh_int(self, name, *, size, lo=None, hi=None):
        """Return a z3 BitVec of width `size * 8` named `name`.

        Repeated calls with the same name return the same variable
        without re-adding bounds — symbolic inputs are identified by
        name. `lo` / `hi` are unsigned bounds added to the path
        condition.
        """
        if name in self._fresh_vars:
            return self._fresh_vars[name]
        z3 = _z3_module()
        var = z3.BitVec(name, size * 8)
        self._fresh_vars[name] = var
        if lo is not None:
            self._path.path_condition.append(z3.UGE(var, lo))
        if hi is not None:
            self._path.path_condition.append(z3.ULE(var, hi))
        self.invalidate()
        return var

    def model(self):
        """Run `check()`; on `sat`, return `{name: int}` for every
        fresh_int the path minted. On `unsat`, return None."""
        z3 = _z3_module()
        s = self.solver
        if s.check() != z3.sat:
            return None
        m = s.model()
        out = {}
        for name, var in self._fresh_vars.items():
            out[name] = m.eval(var, model_completion=True).as_long()
        return out

    def invalidate(self):
        self._solver = None

    def adopt_fresh_vars(self, fresh_vars):
        """Replace the cached `name -> z3.BitVec` dict (for clones,
        snapshot restore, and fork propagation). Also invalidates the
        cached solver since variables changed."""
        self._fresh_vars = dict(fresh_vars)
        self.invalidate()


class Path:
    def __init__(self, state, mem, *, parent_id=None):
        self.id = _next_id()
        self._state = state
        self._mem = mem
        self._parent_id = parent_id
        self.events = EventLog()
        self.tags = set()
        self.path_condition = []
        self.solver = _PathSolver(self)
        self._func_name = None
        self._layout = None
        self.terminal = None
        self.return_value = None
        self.error_kind = None
        self.suspended = None
        # Per-path back-edge counter; keyed by (latch_id, header_id).
        # Mutated by the dispatcher each time intercept.loop fires.
        self._loop_iters = {}
        # Phase 6: queryable list of sink Findings recorded on this path.
        self.findings = FindingsList()
        # Phase 6: name of the region asserted on `addr_var` when this
        # path was forked off a SplitByRegion / ConstrainTo decision.
        # `None` for paths whose suspensions were resolved via
        # ConcretizeTo (Phase 5 fast path) or never suspended.
        self._region_at_suspension = None
        # Phase 6: count of LazyRegion materializations charged to
        # this path so far (engine.lazy_region_budget caps).
        self._lazy_regions_used = 0

    @property
    def state(self):
        return self._state

    @property
    def mem(self):
        return self._mem

    @property
    def steps(self):
        return self._state.steps

    def clone(self):
        cloned_state = _interp.clone_state(self._state)
        new_path = Path(cloned_state, self._mem, parent_id=self.id)
        new_path.events = EventLog(self.events)
        new_path.tags = set(self.tags)
        new_path.path_condition = list(self.path_condition)
        new_path._loop_iters = dict(self._loop_iters)
        new_path._func_name = self._func_name
        new_path._layout = self._layout
        new_path.solver.adopt_fresh_vars(self.solver._fresh_vars)
        new_path._region_at_suspension = self._region_at_suspension
        new_path._lazy_regions_used = self._lazy_regions_used
        new_path.findings = FindingsList(self.findings)
        return new_path

    def snapshot(self):
        """Capture full path state — interpreter state, events, tags,
        terminal, return_value, loop counter, path condition, fresh
        symbolic inputs — into a reusable snapshot.

        The snapshot owns a fresh clone of the interpreter state, so
        further stepping on the path doesn't affect it.
        """
        return _Snapshot(
            state=_interp.clone_state(self._state),
            events=EventLog(self.events),
            tags=set(self.tags),
            path_condition=list(self.path_condition),
            terminal=self.terminal,
            return_value=self.return_value,
            error_kind=self.error_kind,
            loop_iters=dict(self._loop_iters),
            func_name=self._func_name,
            fresh_vars=dict(self.solver._fresh_vars),
        )

    def restore(self, snap):
        """Roll the path back to `snap`. Re-clones the snapshot's state
        so the snapshot remains reusable."""
        self._state = _interp.clone_state(snap.state)
        self.events = EventLog(snap.events)
        self.tags = set(snap.tags)
        self.path_condition = list(snap.path_condition)
        self.terminal = snap.terminal
        self.return_value = snap.return_value
        self.error_kind = snap.error_kind
        self._loop_iters = dict(snap.loop_iters)
        self._func_name = snap.func_name
        self.solver.adopt_fresh_vars(snap.fresh_vars)

    def replay(self, *, modify, engine, slice_steps=1024,
               concretize=None, until=None):
        """Run a fresh exploration starting from a clone of this path,
        with `modify(path)` applied once before resuming.

        Returns the list of paths produced by the resumed exploration.
        Doesn't mutate `self`. The `modify` callback receives the
        cloned Path; it can use `path.mem`, `path.solver`, or directly
        write through the interpreter state.
        """
        snap = self.snapshot()
        return engine.resume_from(snap, modify=modify,
                                  slice_steps=slice_steps,
                                  concretize=concretize,
                                  parent_id=self.id,
                                  until=until)

    def assert_(self, cond):
        """Add a z3 assertion to the path condition. If the path becomes
        unsatisfiable, mark it `terminal="infeasible"` so the driver
        stops stepping it."""
        z3 = _z3_module()
        self.path_condition.append(cond)
        self.solver.invalidate()
        if self.solver.solver.check() == z3.unsat:
            self.terminal = Terminal.INFEASIBLE

    def summary(self):
        """Single human-readable summary of what happened on this path.

        Built entirely from already-recorded events plus the path's
        terminal state. Counts globals_touched by checking memory_read /
        memory_write events whose address falls in any range the layout
        knows about; counts branch_forks from `kind="branch"` entries.
        """
        func = self._func_name or "<unknown>"
        terminal = self.terminal or Terminal.LIVE
        rv = self.return_value
        rv_part = f"return={rv}" if rv is not None else ""
        steps = self.steps

        branch_forks = self.events.count(kind=BRANCH)
        globals_touched = self._count_globals_touched()
        events_count = len(self.events)
        tags_part = f"tags={sorted(self.tags)}" if self.tags else ""

        lines = []
        head = f"Path #{self.id}  {terminal}  {rv_part}  steps={steps}".strip()
        lines.append(head)
        lines.append(f"  func: {func}")
        lines.append(f"  globals_touched: {globals_touched}")
        lines.append(f"  branch_forks: {branch_forks}  (this path)")
        lines.append(f"  events: {events_count}")
        if tags_part:
            lines.append(f"  {tags_part}")
        return "\n".join(lines)

    def dot_cfg(self):
        """Render a Graphviz string of the branch transitions this path
        took. The substrate doesn't surface per-block-enter events to
        Python yet, so the rendered graph is the branch-transition
        graph rather than every block visited. Each edge connects the
        source block to the taken target with the step counter and
        direction as label."""
        branch_events = self.events.where(kind=BRANCH)
        if not branch_events:
            return (f"digraph path_{self.id} {{\n"
                    f"  empty [label=\"no branch events recorded\"];\n"
                    f"}}\n")

        lines = [f"digraph path_{self.id} {{"]
        for entry in branch_events:
            direction = entry.get("direction", BranchDirection.UNKNOWN)
            true_block = entry.get("true_block")
            false_block = entry.get("false_block")
            step = entry.get("step", "?")
            took_true = (direction == BranchDirection.TRUE)
            taken = true_block if took_true else false_block
            other = false_block if took_true else true_block
            lines.append(
                f"  block_{true_block} -> block_{taken} "
                f"[label=\"step {step}, {direction}\"];")
            if other is not None and other != taken:
                lines.append(
                    f"  block_{true_block} -> block_{other} "
                    f"[style=dashed, label=\"not taken\"];")
        lines.append("}")
        return "\n".join(lines) + "\n"

    def regions_touched(self):
        """Aggregate `region` tags on memory_read / memory_write events
        into `{region_name: {"reads": n, "writes": m}}`. Events whose
        region is `None` (an OOB or layout-unaware access) are dropped.
        """
        out = {}
        for entry in self.events.where(kind__in=(MEMORY_READ, MEMORY_WRITE)):
            r = entry.get("region")
            if r is None:
                continue
            slot = out.setdefault(r, {"reads": 0, "writes": 0})
            if entry.get("kind") == MEMORY_READ:
                slot["reads"] += 1
            else:
                slot["writes"] += 1
        return out

    def _count_globals_touched(self):
        if self._layout is None:
            return 0
        ranges = [self._layout.address_range(name)
                  for name in self._layout.globals()]
        if not ranges:
            return 0
        seen = set()
        for entry in self.events.where(kind__in=(MEMORY_READ, MEMORY_WRITE)):
            addr = entry.get("addr")
            if addr is None:
                continue
            for lo, hi in ranges:
                if lo <= addr < hi:
                    seen.add((lo, hi))
                    break
        return len(seen)


class _Snapshot:
    """Reusable point-in-time capture of a Path's full state."""

    __slots__ = ("state", "events", "tags", "path_condition", "terminal",
                 "return_value", "error_kind", "loop_iters", "func_name",
                 "fresh_vars")

    def __init__(self, *, state, events, tags, path_condition, terminal,
                 return_value, error_kind, loop_iters, func_name,
                 fresh_vars):
        self.state = state
        self.events = events
        self.tags = tags
        self.path_condition = path_condition
        self.terminal = terminal
        self.return_value = return_value
        self.error_kind = error_kind
        self.loop_iters = loop_iters
        self.func_name = func_name
        self.fresh_vars = fresh_vars
