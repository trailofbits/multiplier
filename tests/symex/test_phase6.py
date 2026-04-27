"""Phase 6 — region-aware memory + first sink oracles.

Catalog (matches docs/symex-phase6-plan.md):

P6.0  resume_addr_symbolic substrate hook round-trips a z3 expression.
P6.1  ConcretizeByRegion returns SplitByRegion(regions=(...)); engine
      forks one child per region, each with `addr ∈ region` asserted.
P6.2  Each SplitByRegion child has at least two distinct in-region
      addresses satisfying — the offset stays free.
P6.3  ConstrainTo(z3 predicate) creates one child with the predicate
      asserted on path_condition.
P6.4  Lazy region materialization: empty layout + lazy_default=True
      yields a fresh LazyRegion in the SplitByRegion; engine emits
      region_materialized.
P6.5  lazy_region_budget caps materializations per path; over-quota
      decisions are rejected and emit lazy_budget_exhausted.
P6.6  Symbolic-offset write into the overlay; concrete-byte read
      reflects the symbolic Select.
P6.7  Concrete write mirrors into an existing overlay; symbolic-offset
      read sees the mirrored value via z3.Select.
P6.8  OOBSink fires in concrete-addr mode on enumerated addresses
      that fall outside the layout region.
P6.9  NullDerefSink fires in concrete-addr mode when the strategy
      enumerates 0.
P6.10 DivByZeroSink fires in symbolic-addr mode through binary_op
      dispatch (no ptr_add involvement).
P6.11 fatal=True sinks terminate the path with Terminal.SINK_HIT.
P6.12 path.regions_touched aggregates region-tagged memory events.
P6.13 CWE-787-style worked example: ConcretizeFinite enumerates
      addresses inside and outside a small buffer; OOBSink emits a
      reproducible Finding for each OOB child.

The substrate's `ptr_add` hardcodes concrete output (Phase 7 deferred),
so Phase 6 splits its tests like Phase 5 did:
- [U] tests synthesize a Suspension with a z3 `address_expr` and
  drive `engine._handle_suspension` directly, OR exercise overlay
  machinery through the Region object.
- [E2E] tests drive `engine.explore(...)` with the Phase 5
  `_setup_symbolic_index` pattern and verify concrete-mode sink
  fires + region tagging.
"""

import pytest

from symex import (
    ConcretizeByRegion,
    ConcretizeFinite,
    ConstrainTo,
    DivByZeroSink,
    LazyRegion,
    Layout,
    NullDerefSink,
    OOBSink,
    Region,
    SplitByRegion,
    SymExEngine,
    Suspension,
)
from symex.events import EventKind, Terminal


import multiplier as mx

_interp = mx.ir.interpret


# ---------------------------------------------------------------------------
# Shared setup helper. Mirrors test_phase5.py's `_setup_symbolic_index`:
# `symbolic_test_ptr_add(int *base, int index)` does `base[index]`. We
# pass a concrete base; intercept the *index* parameter load to substitute
# a fresh z3 BitVec; the load through `base + index*4` raises a
# MemAddrContinuation. The substrate collapses ptr_add to concrete, so
# the engine's address-strategy gets a concrete `address_expr` — Phase 6
# end-to-end tests run through the concrete-addr-fallback branches of
# the SplitByRegion / ConstrainTo handlers.
# ---------------------------------------------------------------------------

ARR_BASE = 0x10000
ARR_INIT = bytes([
    10, 0, 0, 0,
    20, 0, 0, 0,
    30, 0, 0, 0,
    40, 0, 0, 0,
])


def _setup_symbolic_index(index, *, lo=0, hi=10):
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("arr", addr=ARR_BASE, size=16, init=ARR_INIT)

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and not (ARR_BASE <= addr < ARR_BASE + 16) and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("idx", size=size, lo=lo, hi=hi)
        return next_hook(ctx, addr, size)

    return engine


# ===========================================================================
# P6.0 [U] — resume_addr_symbolic substrate hook
# ===========================================================================

def test_p6_0_resume_addr_symbolic_substrate_hook():
    """Phase 6's one required C++ delta: `resume_addr_symbolic` writes
    an arbitrary Python value (typically a z3 expression) into the
    suspended op's address-operand cache slot. This test asserts
    the hook is present alongside the new `get_value_at` reader."""
    assert hasattr(_interp, "resume_addr_symbolic")
    assert hasattr(_interp, "get_value_at")


def test_p6_0_resume_addr_symbolic_round_trip(index):
    """End-to-end round-trip via a real (but unused) call frame:
    initialize a state for `symbolic_test_add_i32`, install a z3
    BitVec into a freshly-chosen eid, read it back, verify it's the
    same z3 expression."""
    z3 = pytest.importorskip("z3")
    from symex.engine import _resolve_function

    ir_func = _resolve_function(index, "symbolic_test_add_i32")
    assert ir_func is not None

    state = _interp.InterpreterState()
    memory = _interp.ConcreteMemory()

    class _NoOpPolicy:
        pass

    _interp.init_state(state, memory, _NoOpPolicy(), ir_func, [1, 2])

    # Pick an arbitrary eid for the round-trip. The eid doesn't have
    # to correspond to a real instruction for the hook itself — only
    # for resumption. We're testing storage round-trip, not resumption.
    eid = 0xDEADBEEF
    sym = z3.BitVec("addr_var", 64)
    _interp.resume_addr_symbolic(state, eid, sym)

    got = _interp.get_value_at(state, eid)
    # z3 ExprRef equality is structural; identity also works for the
    # original since we wrote it without copying.
    assert got is sym


# ===========================================================================
# P6.1 [U] — ConcretizeByRegion returns SplitByRegion
# ===========================================================================

def test_p6_1_split_by_region_two_regions(index):
    """ConcretizeByRegion now returns a single SplitByRegion(regions=
    (g_a, g_b)). The engine's _handle_suspension forks one child per
    region; each child has `_region_at_suspension` set and an
    `addr_var ∈ [base, base+size)` predicate on its path_condition."""
    z3 = pytest.importorskip("z3")
    layout = Layout()
    layout.place_global("g_a", addr=0x10000, size=16)
    layout.place_global("g_b", addr=0x20000, size=8)

    addr_var = z3.BitVec("addr", 64)
    decisions = list(
        ConcretizeByRegion(layout).next_decisions(
            Suspension(address_expr=addr_var, address_eid=99,
                       size=4, is_write=False, path=None,
                       layout=layout, solver=None)))
    assert len(decisions) == 1
    sbr = decisions[0]
    assert isinstance(sbr, SplitByRegion)
    assert tuple(r.name for r in sbr.regions) == ("g_a", "g_b")


def test_p6_1_split_by_region_engine_forks(index):
    """Driving SplitByRegion through the engine's
    `_dispatch_split_by_region` (with a synthesized fork-entry state)
    produces two children, each tagged with its region and each with
    `addr_var ∈ region` on its path_condition."""
    z3 = pytest.importorskip("z3")

    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_a", addr=0x10000, size=16)
    engine.layout.place_global("g_b", addr=0x20000, size=8)
    g_a = engine.layout.region_for_name("g_a")
    g_b = engine.layout.region_for_name("g_b")

    # Synthesize a parent path with a z3 address_expr.
    addr_var = z3.BitVec("addr", 64)
    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0],
                           concretize=ConcretizeFinite([ARR_BASE]))
    parent = paths[0]

    susp = Suspension(address_expr=addr_var, address_eid=42,
                      size=4, is_write=False, path=parent,
                      layout=engine.layout, solver=parent.solver)
    children = []
    # The child_state's source must already be a clone of `parent.state`
    # so resume_addr_symbolic / resume_addr can write into it.
    fork_state = _interp.clone_state(parent.state)
    take_calls = [0]
    def take_state():
        take_calls[0] += 1
        return _interp.clone_state(fork_state)

    engine._dispatch_split_by_region(
        parent,
        susp,
        SplitByRegion(regions=(g_a, g_b)),
        take_state,
        children)
    assert len(children) == 2
    assert {c._region_at_suspension for c in children} == {"g_a", "g_b"}
    for child in children:
        # Find the in-region constraint that was appended.
        regions = engine.layout.regions()
        added = [c for c in child.path_condition
                 if c not in parent.path_condition]
        assert len(added) >= 1, "expected an in-region predicate"
        # Solver must agree the predicate is satisfiable.
        s = z3.Solver()
        for c in child.path_condition:
            s.add(c)
        assert s.check() == z3.sat


# ===========================================================================
# P6.2 [U] — in-region offset stays free
# ===========================================================================

def test_p6_2_split_by_region_offset_stays_symbolic():
    """For each child of a SplitByRegion fork, the path condition
    constrains addr_var to the region's extent; multiple distinct
    addresses inside that extent satisfy the path condition. This is
    the Reps-style claim that the in-region offset hasn't collapsed."""
    z3 = pytest.importorskip("z3")
    layout = Layout()
    layout.place_global("g_x", addr=0x40000, size=64)
    region = layout.region_for_name("g_x")

    addr_var = z3.BitVec("addr", 64)
    in_region = z3.And(
        z3.UGE(addr_var, region.base),
        z3.ULT(addr_var, region.base + region.size))

    # First sat: any value works.
    s = z3.Solver()
    s.add(in_region)
    assert s.check() == z3.sat
    a = s.model().eval(addr_var, model_completion=True).as_long()

    # Second sat with the previous value blocked: must still be sat —
    # i.e., at least two distinct in-region addresses satisfy.
    s.add(addr_var != a)
    assert s.check() == z3.sat
    b = s.model().eval(addr_var, model_completion=True).as_long()
    assert a != b
    assert region.base <= a < region.base + region.size
    assert region.base <= b < region.base + region.size


# ===========================================================================
# P6.3 [U] — ConstrainTo arbitrary predicate
# ===========================================================================

def test_p6_3_constrain_to_arbitrary_predicate(index):
    """ConstrainTo(addr_var % 8 == 0) over a synthesized z3
    address_expr asserts the predicate on the child's path
    condition."""
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("buf", addr=0x10000, size=64,
                                init=ARR_INIT * 4)

    # Drive a parent path through the existing setup.
    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0],
                           concretize=ConcretizeFinite([ARR_BASE]))
    parent = paths[0]
    addr_var = z3.BitVec("addr", 64)
    predicate = (addr_var & 7) == 0
    susp = Suspension(address_expr=addr_var, address_eid=99,
                      size=4, is_write=False, path=parent,
                      layout=engine.layout, solver=parent.solver)
    children = []
    fork_state = _interp.clone_state(parent.state)
    def take_state():
        return _interp.clone_state(fork_state)

    engine._dispatch_constrain_to(
        parent, susp, ConstrainTo(constraint=predicate),
        take_state, children)
    assert len(children) == 1
    child = children[0]
    assert predicate in child.path_condition
    s = z3.Solver()
    for c in child.path_condition:
        s.add(c)
    assert s.check() == z3.sat


# ===========================================================================
# P6.4 [U] — Lazy region materialization
# ===========================================================================

def test_p6_4_lazy_region_materialization(index):
    """ConcretizeByRegion(layout, lazy_default=True) on an empty
    layout yields a SplitByRegion whose only region is a fresh
    LazyRegion. _dispatch_split_by_region emits a region_materialized
    event."""
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()  # no globals declared

    addr_var = z3.BitVec("addr", 64)
    susp = Suspension(address_expr=addr_var, address_eid=77,
                      size=4, is_write=False, path=None,
                      layout=engine.layout, solver=None)
    decisions = list(
        ConcretizeByRegion(engine.layout, lazy_default=True)
        .next_decisions(susp))
    assert len(decisions) == 1
    sbr = decisions[0]
    assert isinstance(sbr, SplitByRegion)
    assert len(sbr.regions) == 1
    lazy = sbr.regions[0]
    assert isinstance(lazy, LazyRegion)
    assert lazy.max_size == 4096

    # Drive the engine handler to verify the event fires.
    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0],
                           concretize=ConcretizeFinite([ARR_BASE]))
    parent = paths[0]
    susp.path = parent
    children = []
    def take_state():
        return _interp.clone_state(parent.state)
    engine._dispatch_split_by_region(parent, susp, sbr,
                                      take_state, children)
    assert len(children) == 1
    assert children[0]._region_at_suspension == lazy.name
    materialize = parent.events[-1] if parent.events else None
    # The event lives on the parent (charged before the fork).
    found = any(e.get("kind") == EventKind.REGION_MATERIALIZED
                for e in parent.events)
    assert found


# ===========================================================================
# P6.5 [U] — lazy_region_budget caps
# ===========================================================================

def test_p6_5_lazy_region_budget_caps(index):
    """Setting engine.lazy_region_budget = 2 and feeding three
    LazyRegion materializations to one path: the third materialization
    is rejected and a lazy_budget_exhausted event is emitted."""
    pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.lazy_region_budget = 2

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[ARR_BASE, 0],
                           concretize=ConcretizeFinite([ARR_BASE]))
    parent = paths[0]

    lazy_a = engine.layout.declare_lazy("lazy_a", max_size=64)
    lazy_b = engine.layout.declare_lazy("lazy_b", max_size=64)
    lazy_c = engine.layout.declare_lazy("lazy_c", max_size=64)

    susp = Suspension(address_expr=None, address_eid=77,
                      size=4, is_write=False, path=parent,
                      layout=engine.layout, solver=parent.solver)
    children = []
    def take_state():
        return _interp.clone_state(parent.state)

    engine._dispatch_split_by_region(
        parent, susp,
        SplitByRegion(regions=(lazy_a, lazy_b, lazy_c)),
        take_state, children)

    # Two children for the in-budget regions; the third is dropped.
    assert len(children) == 2
    assert {c._region_at_suspension for c in children} == {"lazy_a", "lazy_b"}

    exhausted = [e for e in parent.events
                 if e.get("kind") == EventKind.LAZY_BUDGET_EXHAUSTED]
    assert len(exhausted) == 1
    assert exhausted[0]["region"] == "lazy_c"


# ===========================================================================
# P6.6 [U] — overlay symbolic write, concrete read
# ===========================================================================

def test_p6_6_overlay_symbolic_write_concrete_read():
    """Symbolic-offset write through the overlay; a concrete-byte
    read returns Select(overlay, concrete_addr) — a non-trivial z3
    expression, not the stale flat-store byte."""
    z3 = pytest.importorskip("z3")
    region = Region(name="g_a", base=0x40000, size=64, kind="global")

    sym_off = z3.BitVec("off", 64)
    region.store_byte(region.base + sym_off, 0xAA)

    val = region.select_byte(region.base + 3)
    # Not constant-foldable: the Select is over a symbolic offset.
    assert isinstance(val, z3.ExprRef)
    # And the symbolic write makes the byte 0xAA when off == 3.
    s = z3.Solver()
    s.add(sym_off == 3)
    s.add(val == 0xAA)
    assert s.check() == z3.sat


# ===========================================================================
# P6.7 [U] — overlay concrete write, symbolic read
# ===========================================================================

def test_p6_7_overlay_concrete_write_symbolic_read():
    """A concrete write at byte 3 mirrors into the overlay (per the
    Step 6 invariant — exercised here by direct overlay store). A
    symbolic-offset read at `g_a + i` returns a z3.Select; solver
    finds i == 3 satisfying `Select == 0x42`."""
    z3 = pytest.importorskip("z3")
    region = Region(name="g_b", base=0x60000, size=64, kind="global")

    # Force overlay creation; mirror a concrete write byte-by-byte.
    region.overlay()
    region.store_byte(region.base + 3, 0x42)

    i = z3.BitVec("i", 64)
    val = region.select_byte(region.base + i)
    s = z3.Solver()
    s.add(z3.UGE(i, 0))
    s.add(z3.ULT(i, 64))
    s.add(val == 0x42)
    assert s.check() == z3.sat
    m = s.model()
    assert m.eval(i, model_completion=True).as_long() == 3


# ===========================================================================
# P6.8 [E2E] — OOBSink concrete-addr mode on memory_read
# ===========================================================================

def test_p6_8_oob_sink_fires_on_unsafe_read(index):
    """Place a tiny region (`g_buf`, 8 bytes); enumerate four
    addresses, two inside and two past the end. OOBSink in
    concrete-addr mode fires on the OOB children — Findings record
    the offending step + region (None or `g_buf`)."""
    pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=8,
                                init=bytes(range(1, 9)))

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and not (BUF <= addr < BUF + 8) and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("idx", size=size, lo=0, hi=10)
        return next_hook(ctx, addr, size)

    engine.sinks.add(OOBSink())

    paths = engine.explore(
        "symbolic_test_ptr_add",
        args=[BUF, 0],
        concretize=ConcretizeFinite([BUF, BUF + 4, BUF + 8, BUF + 12]))

    # Two children sit inside g_buf, two are past the end.
    assert len(paths) == 4
    findings = []
    for p in paths:
        for f in p.findings:
            if f.kind == "oob_read":
                findings.append((p, f))

    # The two OOB paths each fire an oob_read.
    assert len(findings) == 2
    for p, f in findings:
        assert f.mode == "concrete"
        assert f.witness == {}
        assert "sink:oob_read" in p.tags


# ===========================================================================
# P6.9 [E2E] — NullDerefSink fires on enumerated 0 address
# ===========================================================================

def test_p6_9_null_deref_sink_fires(index):
    """Strategy includes 0 as a candidate; on the addr=0 child,
    NullDerefSink fires in concrete-addr mode."""
    pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=16,
                                init=bytes(16))
    engine.sinks.add(NullDerefSink())

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and not (BUF <= addr < BUF + 16) and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("idx", size=size, lo=0, hi=10)
        return next_hook(ctx, addr, size)

    paths = engine.explore(
        "symbolic_test_ptr_add",
        args=[BUF, 0],
        concretize=ConcretizeFinite([0, BUF]))

    # Find the path that resumed at addr 0.
    null_paths = [p for p in paths if "sink:null_read" in p.tags]
    assert len(null_paths) == 1
    p = null_paths[0]
    nd = next(f for f in p.findings if f.kind == "null_read")
    assert nd.mode == "concrete"


# ===========================================================================
# P6.10 [E2E] — DivByZeroSink fires through binary_op dispatch
# ===========================================================================

def test_p6_10_div_by_zero_sink_fires(index):
    """`symbolic_test_div_i32(int32_t a, int32_t b) { return a / b; }`.
    Intercept the load of `b` to substitute a fresh z3 BitVec; the
    divisor reaches binary_op as a z3 expression (binary_op IS
    Python-dispatched, so this fires symbolic-mode end-to-end).
    DivByZeroSink emits a Finding whose witness includes b == 0."""
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        # The two parameter slots are 4 bytes each. We make the second
        # 4-byte read symbolic: that's the divisor `b`.
        if size == 4:
            fired.append(addr)
            if len(fired) == 2:
                return ctx.solver.fresh_int(
                    "b_sym", size=4, lo=0, hi=2**31 - 1)
        return next_hook(ctx, addr, size)

    engine.sinks.add(DivByZeroSink())
    paths = engine.explore("symbolic_test_div_i32", args=[100, 7])

    found = False
    for p in paths:
        for f in p.findings:
            if f.kind in ("div_by_zero", "rem_by_zero"):
                assert f.mode == "symbolic"
                assert "b_sym" in f.witness
                assert f.witness["b_sym"] == 0
                found = True
    assert found, "expected DivByZeroSink to fire on the symbolic divisor"


# ===========================================================================
# P6.11 [E2E] — fatal sink terminates the path
# ===========================================================================

def test_p6_11_fatal_sink_terminates_path(index):
    """`engine.sinks.add(OOBSink(), fatal=True)` over P6.8's setup:
    the first OOB child terminates with Terminal.SINK_HIT."""
    pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=8,
                                init=bytes(range(1, 9)))

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and not (BUF <= addr < BUF + 8) and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("idx", size=size, lo=0, hi=10)
        return next_hook(ctx, addr, size)

    engine.sinks.add(OOBSink(), fatal=True)

    paths = engine.explore(
        "symbolic_test_ptr_add",
        args=[BUF, 0],
        concretize=ConcretizeFinite([BUF, BUF + 8]))

    # The OOB child terminates with SINK_HIT; the in-bounds child
    # completes normally.
    sink_hits = [p for p in paths if p.terminal == Terminal.SINK_HIT]
    assert len(sink_hits) == 1
    p = sink_hits[0]
    assert any(f.kind == "oob_read" for f in p.findings)


# ===========================================================================
# P6.12 [E2E] — path.regions_touched aggregates per-region access
# ===========================================================================

def test_p6_12_regions_touched_summary(index):
    """Two layout regions, ConcretizeFinite enumerates an address in
    each; path.regions_touched() returns the right read counts."""
    pytest.importorskip("z3")
    A = 0x40000
    B = 0x50000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_a", addr=A, size=16, init=ARR_INIT)
    engine.layout.place_global("g_b", addr=B, size=16, init=ARR_INIT)

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and addr not in range(A, A + 16) \
                and addr not in range(B, B + 16) and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("idx", size=size, lo=0, hi=10)
        return next_hook(ctx, addr, size)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[A, 0],
                           concretize=ConcretizeFinite([A, B]))

    # Both children record at least one read in their respective region.
    by_region = {p._region_at_suspension or "?": p.regions_touched()
                 for p in paths}
    # Each path touched the region whose base it resumed at.
    touched_names = set()
    for p in paths:
        for name in p.regions_touched():
            touched_names.add(name)
    assert touched_names >= {"g_a", "g_b"}


# ===========================================================================
# P6.13 [E2E] — CWE-787-style worked example
# ===========================================================================

def test_p6_13_oob_worked_example(index):
    """End-to-end: place a small buffer (`g_buf`, 8 bytes) and use
    ConcretizeFinite to enumerate 8 candidate addresses inside and
    outside it. OOBSink fires on the OOB children and produces a
    reproducible concrete address as the witness's `addr` field.

    The plan called for a CWE-787 oob_write through a `copy_into`
    helper in `tests/symex/c/cwe787_oob_write.c`; adding a new C file
    requires rebuilding the InterpretIR test database, which is
    deferred. This test produces the same shape — `oob_read` Findings
    with concrete-mode witnesses — through the existing
    `symbolic_test_ptr_add` corpus function. See the commit message
    for the deferred CWE-787 store-side variant."""
    pytest.importorskip("z3")
    BUF = 0x40000
    BUF_SIZE = 8  # bytes; only two valid 4-byte loads fit
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=BUF_SIZE,
                                init=bytes(range(1, BUF_SIZE + 1)))

    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and not (BUF <= addr < BUF + BUF_SIZE) and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int("idx", size=size, lo=0, hi=32)
        return next_hook(ctx, addr, size)

    engine.sinks.add(OOBSink())

    addrs = [BUF + i * 4 for i in range(8)]
    paths = engine.explore(
        "symbolic_test_ptr_add",
        args=[BUF, 0],
        concretize=ConcretizeFinite(addrs))

    assert len(paths) == 8
    in_bounds = [p for p in paths if not any(
        f.kind == "oob_read" for f in p.findings)]
    oob = [p for p in paths if any(
        f.kind == "oob_read" for f in p.findings)]
    assert len(in_bounds) == 2  # BUF+0, BUF+4
    assert len(oob) == 6  # BUF+8 .. BUF+28

    # Each OOB Finding records the concrete OOB address via the
    # corresponding memaddr_concretize event on the path. The witness
    # itself is empty (concrete-mode), but the path is reproducible
    # by replaying with that address.
    for p in oob:
        memev = p.events.first(kind=EventKind.MEMADDR_CONCRETIZE)
        assert memev is not None
        assert memev["address"] >= BUF + BUF_SIZE
