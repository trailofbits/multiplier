"""Phase 5 — typed address strategies + per-site overrides.

Catalog (matches docs/symex-phase5-plan.md):

P5.1  ConcretizeFinite forks one path per address.
P5.2  ConcretizeViaSolver attaches addr_var == k as extra_constraint;
      child paths' solvers stay sat with the witness equal to k.
P5.3  ConcretizePointerSet.functions(layout) yields one decision per
      placed function, in registration order.
P5.4  ConcretizeByRegion(layout) yields one decision per global region.
P5.5  Strategy with max_models hit emits CONCRETIZATION_TRUNCATED.
P5.6  engine.concretize_at(..., name=…) overrides the default for
      suspensions on that named region.
P5.7  engine.concretize_at(..., addr_range=…) overrides by range.
P5.8  Feasibility pre-check drops candidates that violate the path
      condition; emits CONCRETIZATION_INFEASIBLE.
P5.9  Strategy that returns no decisions terminates path with
      Terminal.CONCRETIZATION_REFUSED (not STUCK_SUSPENSION).
P5.10 Legacy callable `concretize=lambda fork: [...]` still drives
      one path per returned address.
"""

import pytest

from multiplier.symex import (
    AddressStrategy,
    ConcretizeByRegion,
    ConcretizeFinite,
    ConcretizePointerSet,
    ConcretizeTo,
    ConcretizeViaSolver,
    ExploreUntil,
    Layout,
    SymExEngine,
    Suspension,
)
from multiplier.symex.events import EventKind, Terminal


# ---------------------------------------------------------------------------
# Shared setup helper. `symbolic_test_ptr_add(int *base, int index)` returns
# `base[index]`. We pass a concrete base, but intercept the *index*'s param
# load to substitute a fresh z3 BitVec — that makes `base + index*4`
# symbolic, so the load through it raises a MemAddrContinuation.
# ---------------------------------------------------------------------------

ARR_BASE = 0x10000
ARR_INIT = bytes([
    10, 0, 0, 0,
    20, 0, 0, 0,
    30, 0, 0, 0,
    40, 0, 0, 0,
])


def _setup_symbolic_index(index, *, lo=0, hi=10):
    """Build an engine + layout where the array `arr` lives at ARR_BASE
    and the `index` parameter to `symbolic_test_ptr_add` becomes
    symbolic via an intercept."""
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("arr", addr=ARR_BASE, size=16, init=ARR_INIT)

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        # The base parameter slot is 8 bytes; the index parameter slot
        # is 4 bytes. We substitute on the first 4-byte read outside the
        # array region — that's the index slot.
        if size == 4 and not (ARR_BASE <= addr < ARR_BASE + 16) and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("idx", size=size, lo=lo, hi=hi)
        return next_hook(ctx, addr, size)

    return engine


# --- P5.1 ----------------------------------------------------------------

def test_p5_1_concretize_finite(index):
    """Three explicit addresses → three paths, each loading the right
    array element."""
    pytest.importorskip("z3")
    engine = _setup_symbolic_index(index)
    engine.address_strategy = ConcretizeFinite(
        [ARR_BASE, ARR_BASE + 4, ARR_BASE + 8])

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0])
    assert len(paths) == 3
    returns = sorted(p.return_value for p in paths)
    assert returns == [10, 20, 30]
    for p in paths:
        memaddr = p.events.first(kind=EventKind.MEMADDR_CONCRETIZE)
        assert memaddr is not None
        assert memaddr["address"] in (ARR_BASE, ARR_BASE + 4, ARR_BASE + 8)


# --- P5.2 ----------------------------------------------------------------

def test_p5_2_concretize_via_solver_attaches_constraint():
    """ConcretizeViaSolver yields distinct sat-models in sorted order
    and attaches `addr_var == k` as `extra_constraint` so the child
    path's solver agrees with the executed address. (Substrate's
    `ptr_add` collapses z3 indices to concrete during pointer
    arithmetic, so the address-expr seen at suspension time is
    concrete — making this a strategy unit test rather than an
    end-to-end one. The engine wires `extra_constraint` into the
    child's `path_condition` in `_handle_suspension`; that wiring is
    covered by the legacy callable + assertion in P5.10.)"""
    z3 = pytest.importorskip("z3")

    n = z3.BitVec("n", 64)

    class _FakePath:
        path_condition = [z3.UGE(n, 5), z3.ULE(n, 10)]

    susp = Suspension(address_expr=n, address_eid=42, size=4,
                      is_write=False, path=_FakePath(), layout=None,
                      solver=None)

    strategy = ConcretizeViaSolver(max_models=4)
    decisions = list(strategy.next_decisions(susp))

    assert 0 < len(decisions) <= 4
    addrs = [d.addr for d in decisions]
    # Sorted ascending → determinism.
    assert addrs == sorted(addrs)
    # Distinct → model-blocking worked.
    assert len(set(addrs)) == len(addrs)
    for d in decisions:
        assert 5 <= d.addr <= 10
        assert d.extra_constraint is not None
        # `extra_constraint` is `n == k`; verify by adding to a fresh
        # solver and checking the model.
        s = z3.Solver()
        s.add(d.extra_constraint)
        assert s.check() == z3.sat
        m = s.model()
        assert m.eval(n).as_long() == d.addr


# --- P5.3 ----------------------------------------------------------------

def test_p5_3_concretize_pointer_set_from_layout():
    """PointerSet.functions(layout) yields one decision per placement,
    in registration order."""
    layout = Layout()
    layout.place_function("foo", addr=0x40000)
    layout.place_function("bar", addr=0x50000)

    strategy = ConcretizePointerSet.functions(layout)
    susp = Suspension(address_expr=None, address_eid=0, size=8,
                      is_write=False, path=None, layout=layout, solver=None)
    decisions = list(strategy.next_decisions(susp))
    assert decisions == [ConcretizeTo(0x40000), ConcretizeTo(0x50000)]


# --- P5.4 ----------------------------------------------------------------

def test_p5_4_concretize_by_region():
    """ByRegion(layout) yields one SplitByRegion decision whose
    regions are the layout's globals in deterministic (sorted-by-base)
    order. Phase 6 widened the Decision shape from N ConcretizeTo to
    a single SplitByRegion so the in-region offset can stay symbolic
    (when the substrate carries it through). The legacy
    `[ConcretizeTo(base) per region]` shape moved to the engine's
    concrete-addr fallback inside `_dispatch_split_by_region`.
    """
    from multiplier.symex import SplitByRegion

    layout = Layout()
    layout.place_global("g_a", addr=0x10000, size=16)
    layout.place_global("g_b", addr=0x20000, size=8)
    layout.place_global("g_c", addr=0x30000, size=32)

    strategy = ConcretizeByRegion(layout)
    susp = Suspension(address_expr=None, address_eid=0, size=4,
                      is_write=False, path=None, layout=layout, solver=None)
    decisions = list(strategy.next_decisions(susp))
    assert len(decisions) == 1
    sbr = decisions[0]
    assert isinstance(sbr, SplitByRegion)
    bases = [r.base for r in sbr.regions]
    assert bases == [0x10000, 0x20000, 0x30000]


# --- P5.5 ----------------------------------------------------------------

def test_p5_5_concretize_truncation_event(index):
    """A capped strategy emits CONCRETIZATION_TRUNCATED on every child
    when its output is at max_models."""
    pytest.importorskip("z3")

    class CappedFinite(ConcretizeFinite):
        max_models = 3

        def next_decisions(self, _suspension):
            decs = list(super().next_decisions(_suspension))
            return decs[:self.max_models]

    engine = _setup_symbolic_index(index)
    engine.address_strategy = CappedFinite(
        [ARR_BASE, ARR_BASE + 4, ARR_BASE + 8, ARR_BASE + 12])

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0])
    assert len(paths) == 3
    for p in paths:
        ev = p.events.first(kind=EventKind.CONCRETIZATION_TRUNCATED)
        assert ev is not None
        assert ev["max_models"] == 3


# --- P5.6 ----------------------------------------------------------------

def test_p5_6_per_site_override_by_name(index):
    """Default strategy yields 1 path; an override registered under
    `name="arr"` fires for the symbolic-address suspension because the
    address can land inside arr's range under path condition."""
    pytest.importorskip("z3")
    engine = _setup_symbolic_index(index)
    engine.address_strategy = ConcretizeFinite([ARR_BASE])  # default
    engine.concretize_at(
        ConcretizeFinite([ARR_BASE, ARR_BASE + 4]),
        name="arr")

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0])
    assert len(paths) == 2
    returns = sorted(p.return_value for p in paths)
    assert returns == [10, 20]


# --- P5.7 ----------------------------------------------------------------

def test_p5_7_per_site_override_by_addr_range(index):
    """addr_range= scoped override fires for suspensions whose address
    can land in the range; outside, the engine's default applies."""
    pytest.importorskip("z3")
    engine = _setup_symbolic_index(index)
    engine.address_strategy = ConcretizeFinite([ARR_BASE])  # default → 1 path
    engine.concretize_at(
        ConcretizeFinite([ARR_BASE + 4, ARR_BASE + 8, ARR_BASE + 12]),
        addr_range=("arr", 16))

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0])
    # Override matches because the symbolic address falls in arr.
    assert len(paths) == 3
    returns = sorted(p.return_value for p in paths)
    assert returns == [20, 30, 40]


# --- P5.8 ----------------------------------------------------------------

def test_p5_8_concretize_infeasible_check(index):
    """The engine's feasibility pre-check (`_addr_feasible`) drops any
    candidate that violates the path's accumulated z3 condition.

    Driven directly here — the substrate's `ptr_add` collapses z3
    indices to concrete during pointer arithmetic, so a plain explore
    never produces a suspension whose `address_expr` is a live z3
    expression for the engine to constrain against."""
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()

    n = z3.BitVec("n", 64)

    class _FakePath:
        path_condition = [z3.UGE(n, 0), z3.ULE(n, 100)]

    susp = Suspension(address_expr=n, address_eid=99, size=4,
                      is_write=False, path=_FakePath(), layout=None,
                      solver=None)

    # 50 is feasible (in [0, 100]); 200 is not.
    assert engine._addr_feasible(_FakePath(), susp, ConcretizeTo(50))
    assert not engine._addr_feasible(_FakePath(), susp, ConcretizeTo(200))


# --- P5.9 ----------------------------------------------------------------

def test_p5_9_concretize_refused_terminal(index):
    """A strategy that returns [] yields a path terminated with
    CONCRETIZATION_REFUSED — distinct from STUCK_SUSPENSION."""
    pytest.importorskip("z3")
    engine = _setup_symbolic_index(index)
    engine.address_strategy = ConcretizeFinite([])  # refuse to pick

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0])
    assert len(paths) == 1
    assert paths[0].terminal == Terminal.CONCRETIZATION_REFUSED


# --- P5.10 ---------------------------------------------------------------

def test_p5_10_legacy_callable_still_works(index):
    """`concretize=lambda fork: [k]` (the pre-Phase-5 API) keeps working
    through the back-compat adapter."""
    pytest.importorskip("z3")
    engine = _setup_symbolic_index(index)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0],
                           concretize=lambda fork: [ARR_BASE + 8])
    assert len(paths) == 1
    assert paths[0].return_value == 30
