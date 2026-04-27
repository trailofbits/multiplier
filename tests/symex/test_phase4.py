"""Phase 4 — observability.

Catalog (matches docs/symex-phase4-plan.md):

P4.1 events.where filter by kind.
P4.2 events.where addr__between filter.
P4.3 path.summary string mentions function name + return value.
P4.4 paths.first by event predicate.
P4.5 z3 solver model extracts a satisfying input.
P4.6 path.dot_cfg renders a Graphviz string.
"""

import pytest

from symex import (
    Layout,
    SymExEngine,
    ExploreUntil,
    EventLog,
    PathSet,
)


# --- P4.1 ----------------------------------------------------------------

def test_p4_1_events_where_filter(index):
    """An observe.memory_read handler causes the auto-recorder to log
    memory_read events; events.where(kind="memory_read") returns only
    those."""
    engine = SymExEngine(index)

    @engine.observe.memory_read
    def trace(ctx, **payload):
        pass

    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    assert paths[0].return_value == 5

    events = paths[0].events
    assert isinstance(events, EventLog)

    reads = events.where(kind="memory_read")
    assert isinstance(reads, EventLog)
    assert len(reads) > 0
    for entry in reads:
        assert entry["kind"] == "memory_read"

    # `count` returns an integer; matches len of the filtered list.
    assert events.count(kind="memory_read") == len(reads)
    # `first` returns the first matching entry, or None.
    first = events.first(kind="memory_read")
    assert first is not None
    assert first["kind"] == "memory_read"
    assert events.first(kind="this_kind_does_not_exist") is None


# --- P4.2 ----------------------------------------------------------------

def test_p4_2_events_where_addr_between(index):
    """addr__between filters memory_read events by address range. We
    record reads, find the min/max addresses, and confirm the filter
    selects entries within an inclusive sub-range."""
    engine = SymExEngine(index)

    @engine.observe.memory_read
    def trace(ctx, **payload):
        pass

    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    events = paths[0].events
    reads = events.where(kind="memory_read")
    assert len(reads) >= 2

    addrs = sorted(e["addr"] for e in reads)
    lo, hi = addrs[0], addrs[-1]

    in_range = events.where(kind="memory_read", addr__between=(lo, hi))
    assert len(in_range) == len(reads)
    for entry in in_range:
        assert lo <= entry["addr"] <= hi

    # Empty range below the lowest address.
    below = events.where(kind="memory_read", addr__between=(0, lo - 1))
    assert len(below) == 0


# --- P4.3 ----------------------------------------------------------------

def test_p4_3_path_summary_mentions_function_and_return(index):
    engine = SymExEngine(index)
    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    assert paths[0].return_value == 5

    summary = paths[0].summary()
    assert isinstance(summary, str) and summary
    assert "symbolic_test_add_i32" in summary
    assert "completed" in summary
    assert "return=5" in summary


# --- P4.4 ----------------------------------------------------------------

def test_p4_4_paths_query_first_to_target(index):
    """test_globals does many memory_writes during global init and the
    `g_simple = 99` mutation. With observe.memory_write registered,
    every write is auto-logged; a PathSet.first query by
    events__contains_kind="memory_write" returns the path."""
    engine = SymExEngine(index)

    @engine.observe.memory_write
    def trace_w(ctx, **payload):
        pass

    paths = engine.explore("test_globals")
    assert isinstance(paths, PathSet)
    assert paths[0].terminal == "completed"

    hit = paths.first(events__contains_kind="memory_write")
    assert hit is not None
    assert hit is paths[0]

    # PathSet.where returns another PathSet that supports chaining.
    completed = paths.where(terminal="completed")
    assert isinstance(completed, PathSet)
    assert len(completed) == len(paths)

    assert paths.count(terminal="completed") == len(completed)
    assert paths.first(events__contains_kind="never_seen_kind") is None


# --- P4.5 ----------------------------------------------------------------

def test_p4_5_z3_solver_model_extracts_input(index):
    """An intercept.memory_read returns a fresh z3 BitVec for the first
    read; subsequent compares flow through z3, the substrate forks at
    the branch, and each child path accumulates the branch condition.
    On at least one path, solver.model() returns a concrete assignment
    consistent with the recorded path condition."""
    z3 = pytest.importorskip("z3")

    engine = SymExEngine(index)
    fired = []

    @engine.intercept.memory_read
    def first_read(ctx, addr, size, next_hook):
        if not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("n", size=size, lo=0, hi=10)
        return next_hook(ctx, addr, size)

    paths = engine.explore("factorial",
                           args=[5],
                           until=ExploreUntil.path_count(2),
                           slice_steps=400)
    assert fired, "intercept never fired"
    branched = paths.where(events__contains_kind="branch")
    assert len(branched) >= 2

    p = branched[0]
    assert p.path_condition, "branch fork did not accumulate path_condition"

    model = p.solver.model()
    assert model is not None
    assert "n" in model
    n_val = model["n"]
    assert 0 <= n_val <= 10


# --- P4.6 ----------------------------------------------------------------

def test_p4_6_path_dot_cfg_renders(index):
    """dot_cfg returns a Graphviz string starting with `digraph`,
    whether or not the path took any branches. Concrete-only paths
    produce a stub graph; forked paths produce a node per visited
    block transition."""
    z3 = pytest.importorskip("z3")

    engine_a = SymExEngine(index)
    paths_no_branch = engine_a.explore("symbolic_test_add_i32", args=[2, 3])
    dot = paths_no_branch[0].dot_cfg()
    assert dot.startswith("digraph")
    assert "}" in dot
    assert "no branch events" in dot

    engine_b = SymExEngine(index)
    fired = []

    @engine_b.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("g", size=size, lo=0, hi=10)
        return next_hook(ctx, addr, size)

    paths_branch = engine_b.explore("factorial",
                                     args=[5],
                                     until=ExploreUntil.path_count(2),
                                     slice_steps=400)
    branched = paths_branch.where(events__contains_kind="branch")
    assert branched
    dot2 = branched[0].dot_cfg()
    assert dot2.startswith("digraph")
    assert "block_" in dot2
    assert "->" in dot2


# --- assert_ + infeasibility pruning -------------------------------------

def test_p4_path_assert_marks_infeasible(index):
    """path.assert_(False-equivalent) marks the path infeasible. We
    explore concretely so the path completes, then bolt on an
    impossible assertion."""
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    p = paths[0]

    bv = p.solver.fresh_int("x", size=4)
    p.assert_(bv == 0)
    p.assert_(bv == 1)
    assert p.terminal == "infeasible"
