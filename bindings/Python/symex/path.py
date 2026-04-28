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
    EventLog, BRANCH, BLOCK_ENTER, MEMORY_READ, MEMORY_WRITE,
    BranchDirection, Terminal,
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
        self._path._origin_by_name[name] = {
            "kind": "fresh_int",
            "name": name,
            "size": size,
            "path_id": self._path.id,
            "step": self._path.steps,
        }
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
        # Phase 8f: the IRFunction this path started from. Set by
        # `_init_path` (so both `explore` and `explore_many` populate
        # it) and propagated by `clone` and `_fork_child`. `None` only
        # for paths constructed bare (e.g., snapshot restoration that
        # predates Phase 8f).
        self.entry_func = None
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
        # Phase 8c: shadow map for symbolic values written to concrete
        # substrate-allocated addresses (return slot, ALLOCA/ARG,
        # ALLOCA/LOCAL). Keyed on (addr, size) -> z3 expression.
        self._symbolic_shadow: dict = {}
        # Phase 9: TLS base address for this logical thread. Set by
        # the engine to layout.tls_base at init time. Inherited by
        # forks (cloned, then diverge via _tls_shadow).
        self.tls_base: int = 0
        # Phase 9: per-path TLS values. Keyed (addr, size) -> value,
        # same shape as _symbolic_shadow. Memory-read/write intercept
        # handlers installed by the analyst use this for isolation.
        self._tls_shadow: dict = {}
        # Phase 10: provenance table. Maps BitVec variable name -> origin
        # record dict. Populated by solver.fresh_int and any engine hook
        # that mints a named symbolic value (e.g. address_for).
        self._origin_by_name: dict = {}

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
        new_path.entry_func = self.entry_func
        new_path.solver.adopt_fresh_vars(self.solver._fresh_vars)
        new_path._region_at_suspension = self._region_at_suspension
        new_path._lazy_regions_used = self._lazy_regions_used
        new_path._symbolic_shadow = dict(self._symbolic_shadow)
        new_path.tls_base = self.tls_base
        new_path._tls_shadow = dict(self._tls_shadow)
        new_path._origin_by_name = dict(self._origin_by_name)
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
            symbolic_shadow=dict(self._symbolic_shadow),
            # Phase 6
            findings=FindingsList(self.findings),
            region_at_suspension=self._region_at_suspension,
            lazy_regions_used=self._lazy_regions_used,
            # Phase 8f
            entry_func=self.entry_func,
            # Phase 9
            tls_base=self.tls_base,
            tls_shadow=dict(self._tls_shadow),
            # Phase 10
            origin_by_name=dict(self._origin_by_name),
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
        # Mutate in place so any InterceptorPolicy that captured a
        # reference to this dict still sees the post-restore state.
        self._symbolic_shadow.clear()
        self._symbolic_shadow.update(snap.symbolic_shadow)
        # Phase 6
        self.findings = FindingsList(snap.findings)
        self._region_at_suspension = snap.region_at_suspension
        self._lazy_regions_used = snap.lazy_regions_used
        # Phase 8f
        self.entry_func = snap.entry_func
        # Phase 9
        self.tls_base = snap.tls_base
        self._tls_shadow.clear()
        self._tls_shadow.update(snap.tls_shadow)
        # Phase 10
        self._origin_by_name.clear()
        self._origin_by_name.update(snap.origin_by_name)

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

    def origin(self, expr) -> list:
        """Return a list of origin records for all named symbolic inputs
        that appear as leaves in the z3 expression `expr`.

        Each record is the dict that was stored when the variable was
        minted (e.g. via `solver.fresh_int`). Unknown variables produce
        `{"kind": "unknown", "name": <str>}`. Concrete (non-BitVec) exprs
        return an empty list.
        """
        seen = {}
        stack = [expr]
        while stack:
            e = stack.pop()
            if e.num_args() == 0:
                name = str(e)
                if name not in seen:
                    seen[name] = self._origin_by_name.get(
                        name, {"kind": "unknown", "name": name}
                    )
            else:
                for i in range(e.num_args()):
                    stack.append(e.arg(i))
        return list(seen.values())

    def origin_tree(self, expr) -> dict:
        """Recursive provenance tree for `expr`.

        Leaves: `{"kind": "leaf", "name": <str>, "origin": <record>}`
        Compound nodes: `{"kind": "op", "op": <str>, "args": [...]}`

        `origin` at a leaf is the same dict that `origin()` would return
        for that variable. Unknown variables have `{"kind": "unknown", ...}`
        as their origin.
        """
        if expr.num_args() == 0:
            name = str(expr)
            rec = self._origin_by_name.get(
                name, {"kind": "unknown", "name": name}
            )
            return {"kind": "leaf", "name": name, "origin": rec}
        children = [self.origin_tree(expr.arg(i))
                    for i in range(expr.num_args())]
        return {"kind": "op", "op": str(expr.decl()), "args": children}

    def can_be(self, expr, value) -> bool:
        """Return True if there exists a satisfying assignment for the
        path condition where `expr == value`.

        Builds a fresh solver from the path condition each call so the
        query is side-effect-free. `value` is coerced to a z3 BitVec of
        the same width as `expr`.
        """
        z3 = _z3_module()
        s = z3.Solver()
        for c in self.path_condition:
            s.add(c)
        target = z3.BitVecVal(int(value), expr.size())
        s.add(expr == target)
        return s.check() == z3.sat

    def must_be(self, expr, value) -> bool:
        """Return True if `expr == value` holds in every satisfying
        assignment for the path condition (i.e. no counter-example
        exists).

        Equivalent to checking that `expr != value` is UNSAT.
        """
        z3 = _z3_module()
        s = z3.Solver()
        for c in self.path_condition:
            s.add(c)
        target = z3.BitVecVal(int(value), expr.size())
        s.add(expr != target)
        return s.check() == z3.unsat

    def possible_values(self, expr, *, limit: int = 10) -> list:
        """Enumerate up to `limit` distinct concrete values that `expr`
        can take under the current path condition.

        Returns a sorted list of Python ints. If the expression is
        fully constrained the list has exactly one element; if the path
        is UNSAT the list is empty.
        """
        z3 = _z3_module()
        s = z3.Solver()
        for c in self.path_condition:
            s.add(c)
        results = []
        while len(results) < limit:
            if s.check() != z3.sat:
                break
            m = s.model()
            val_z = m.eval(expr, model_completion=True)
            val_i = val_z.as_long()
            results.append(val_i)
            s.add(expr != val_z)
        return sorted(results)

    def value_range(self, expr) -> tuple:
        """Return `(lo, hi)` — the tight unsigned bounds for `expr`
        under the current path condition, found via z3.Optimize.

        Returns `None` if the path is UNSAT. Both bounds are Python ints.
        """
        z3 = _z3_module()
        bounds = []
        for minimize in (True, False):
            opt = z3.Optimize()
            for c in self.path_condition:
                opt.add(c)
            if minimize:
                opt.minimize(z3.ZeroExt(64, expr)
                             if expr.size() < 64 else expr)
            else:
                opt.maximize(z3.ZeroExt(64, expr)
                             if expr.size() < 64 else expr)
            if opt.check() != z3.sat:
                return None
            m = opt.model()
            val = m.eval(expr, model_completion=True).as_long()
            bounds.append(val)
        return (bounds[0], bounds[1])

    def taint_sources(self, expr) -> frozenset:
        """Return the frozenset of `fresh_int` variable names whose values
        flow into `expr`. Unknown variables (created outside `fresh_int`)
        are excluded. Returns an empty frozenset for concrete expressions.
        """
        return frozenset(
            r["name"]
            for r in self.origin(expr)
            if r.get("kind") == "fresh_int"
        )

    def is_tainted(self, expr) -> bool:
        """Return True if any `fresh_int` variable contributes to `expr`."""
        return bool(self.taint_sources(expr))

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
        """Render a Graphviz string of the blocks this path visited.

        Walks `BLOCK_ENTER` and `BRANCH` events in step order. Each
        consecutive block visit becomes a solid edge labeled with the
        step counter; branch events overlay the taken edge with a
        direction label and emit a dashed not-taken edge for the
        un-followed successor. Paths with no recorded events still
        emit a placeholder digraph.
        """
        events = self.events.where(kind__in=(BRANCH, BLOCK_ENTER))
        if not events:
            return (f"digraph path_{self.id} {{\n"
                    f"  empty [label=\"no events recorded\"];\n"
                    f"}}\n")

        lines = [f"digraph path_{self.id} {{"]
        prev_block = None
        for entry in events:
            kind = entry.get("kind")
            step = entry.get("step", "?")
            if kind == BLOCK_ENTER:
                block = entry.get("block")
                if prev_block is not None and prev_block != block:
                    lines.append(
                        f"  block_{prev_block} -> block_{block} "
                        f"[label=\"step {step}\"];")
                prev_block = block
                continue
            # kind == BRANCH
            direction = entry.get("direction", BranchDirection.UNKNOWN)
            true_block = entry.get("true_block")
            false_block = entry.get("false_block")
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
            # Subsequent BLOCK_ENTERs continue from the taken branch's
            # target.
            prev_block = taken
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
                 "fresh_vars", "symbolic_shadow",
                 # Phase 6
                 "findings", "region_at_suspension", "lazy_regions_used",
                 # Phase 8f
                 "entry_func",
                 # Phase 9
                 "tls_base", "tls_shadow",
                 # Phase 10
                 "origin_by_name")

    def __init__(self, *, state, events, tags, path_condition, terminal,
                 return_value, error_kind, loop_iters, func_name,
                 fresh_vars, symbolic_shadow,
                 findings, region_at_suspension, lazy_regions_used,
                 entry_func, tls_base, tls_shadow, origin_by_name):
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
        self.symbolic_shadow = symbolic_shadow
        self.findings = findings
        self.region_at_suspension = region_at_suspension
        self.lazy_regions_used = lazy_regions_used
        self.entry_func = entry_func
        self.tls_base = tls_base
        self.tls_shadow = tls_shadow
        self.origin_by_name = origin_by_name
