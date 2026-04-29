"""Phase 1 — analyst-facing skeleton tests.

P1.1 layout addresses
P1.2 concrete-only explore
P1.3 path objects expose .id, .events, .solver, .tags, .snapshot()
P1.4 branch event recorded per fork
P1.5 z3 named global (deferred to Phase 4)
P1.6 ExploreUntil.path_count
P1.7 ExploreUntil.steps
"""

import pytest

import multiplier as mx
from multiplier.symex import (
    Layout,
    SymExEngine,
    ExploreUntil,
)
from conftest import ForkOnSymbolicBranchPolicy, SymExpr


# --- P1.1 Layout ---------------------------------------------------------

def test_p1_1_layout_basic():
    layout = Layout()
    layout.place_global("g_users", addr=0x20000, size=8 * 64)
    layout.place_global("g_lock", addr=0x21000, size=8, init=0)
    layout.place_global("g_counter", addr=0x22000, size=4, init=42)
    layout.place_function("process_users", addr=0x10000)

    assert layout["g_users"] == 0x20000
    assert layout["g_lock"] == 0x21000
    assert layout["g_counter"] == 0x22000
    assert layout["process_users"] == 0x10000

    assert layout.address_range("g_users") == (0x20000, 0x20000 + 512)
    assert layout.address_range("g_counter") == (0x22000, 0x22004)

    assert layout.function_at(0x10000) == "process_users"
    assert layout.function_at(0x10010) is None

    counter_bytes = layout.memory.read_bytes(0x22000, 4)
    assert int.from_bytes(counter_bytes, "little") == 42


# --- P1.2 concrete-only explore ------------------------------------------

def test_p1_2_engine_explore_concrete_only(index):
    engine = SymExEngine(index)
    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    assert len(paths) == 1
    p = paths[0]
    assert p.terminal == "completed"
    assert p.return_value == 5


# --- P1.3 path objects ---------------------------------------------------

def test_p1_3_explore_returns_path_objects(index):
    engine = SymExEngine(index)
    paths = engine.explore("symbolic_test_add_i32", args=[7, 8])
    assert paths
    p = paths[0]
    assert isinstance(p.id, int)
    assert hasattr(p, "events")
    assert hasattr(p, "tags")
    assert hasattr(p, "solver")
    snap = p.snapshot()
    assert snap is not None
    # snapshot/restore are no-ops in Phase 1; the round-trip should
    # still leave the path serviceable for the driver to keep using.
    p.tags.add("touched")
    p.restore(snap)
    assert "touched" not in p.tags


# --- P1.4 branch event log -----------------------------------------------

def test_p1_4_path_event_log_records_branches(index):
    engine = SymExEngine(index)
    paths = engine.explore(
        "factorial",
        args=[SymExpr("input", ("n",))],
        policy=ForkOnSymbolicBranchPolicy(),
        until=ExploreUntil.path_count(2),
        slice_steps=400,
    )
    assert len(paths) == 2
    directions = sorted(p.events[-1]["direction"] for p in paths
                        if p.events)
    assert directions == ["false", "true"], directions
    for p in paths:
        last = p.events[-1]
        assert last["kind"] == "branch"
        assert "true_block" in last
        assert "false_block" in last


# --- P1.5 z3 named global ------------------------------------------------

def test_p1_5_z3_named_global(index):
    """Phase 4 z3 wiring: an intercept.memory_read returns a fresh
    z3 BitVec ("the named global is symbolic"), the cmp on it forks
    the path, and each child carries the branch condition. Solving on
    one fork gives a satisfying input."""
    z3 = pytest.importorskip("z3")

    engine = SymExEngine(index)
    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("g", size=size, lo=0, hi=255)
        return next_hook(ctx, addr, size)

    paths = engine.explore("factorial",
                           args=[5],
                           until=ExploreUntil.path_count(2),
                           slice_steps=400)
    branched = paths.where(events__contains_kind="branch")
    assert len(branched) >= 1
    p = branched[0]
    model = p.solver.model()
    assert model is not None and "g" in model
    assert 0 <= model["g"] <= 255


# --- P1.6 ExploreUntil.path_count ----------------------------------------

def test_p1_6_explore_until_path_count(index):
    engine = SymExEngine(index)
    paths = engine.explore(
        "factorial",
        args=[SymExpr("input", ("n",))],
        policy=ForkOnSymbolicBranchPolicy(),
        until=ExploreUntil.path_count(3),
        slice_steps=400,
    )
    # Each branch fork yields 2 paths from one parent; once we have 3
    # the predicate trips. The driver may overshoot by one within a
    # tick (a single fork creates two children at once), but never by
    # more than that.
    assert 3 <= len(paths) <= 4


# --- P1.7 ExploreUntil.steps ---------------------------------------------

def test_p1_7_explore_until_steps(index):
    engine = SymExEngine(index)
    budget = 100
    paths = engine.explore(
        "factorial",
        args=[SymExpr("input", ("n",))],
        policy=ForkOnSymbolicBranchPolicy(),
        until=ExploreUntil.steps(budget),
        slice_steps=20,
    )
    # The predicate fires once total accumulated steps >= budget.
    # The slice can overshoot by up to slice_steps - 1, so allow some
    # slack but ensure we didn't run unbounded.
    total = sum(p.steps for p in paths)
    assert total >= budget
    assert total < budget * 20  # well under "ran forever"


# --- ExploreUntil composition --------------------------------------------

def test_p1_explore_until_or_composes(index):
    engine = SymExEngine(index)
    # Either limit alone would let the run finish; the disjunction is
    # only meaningful as a smoke test that `|` returns a usable predicate.
    pred = ExploreUntil.path_count(50) | ExploreUntil.steps(100_000)
    paths = engine.explore("symbolic_test_add_i32", args=[1, 2], until=pred)
    assert len(paths) == 1
    assert paths[0].return_value == 3


def test_p1_explore_until_and_composes(index):
    engine = SymExEngine(index)
    pred = ExploreUntil.path_count(50) & ExploreUntil.steps(100_000)
    paths = engine.explore("symbolic_test_add_i32", args=[1, 2], until=pred)
    assert len(paths) == 1
    assert paths[0].return_value == 3
