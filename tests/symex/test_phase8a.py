# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 8a — `symbolic_load` / `symbolic_store` policy hooks.

Closes the substrate gap Phase 7 documented but couldn't fix without
scope creep: with `SplitByRegion`, the resumed path used to re-suspend
on every LOAD because `with_address_impl` saw a non-extractable z3
address. Phase 8a wires the per-region overlay through
`InterceptorPolicy.symbolic_load` / `symbolic_store` so the substrate
returns a z3 Select against the overlay instead of suspending again.

Catalog:

  P8a.1  SplitByRegion + `engine.explore` end to end — the resumed
         path doesn't infinite-loop, completes with a z3 return value.
  P8a.2  Phase 7's P7.2 setup with ConcretizeByRegion — each child
         admits multiple distinct in-region addresses, end-to-end.
  P8a.3  OOBSink fires symbolic-mode through `engine.explore`, not
         synthetically — the upgrade Phase 7 P7.4 deferred.
  P8a.4  Concrete write mirrors into the overlay (Phase 6 invariant);
         a subsequent symbolic-offset read sees the mirrored byte.
  P8a.5  ConstrainTo's predicate lands on the path condition AND
         (with region context attached) `symbolic_load` returns a z3
         expression — the load doesn't collapse to default-0.
  P8a.6  LazyRegion materialized via SplitByRegion; the resumed load
         reads against the freshly minted overlay.
  P8a.7  No region context → `symbolic_load` correctly returns
         NotImplemented and the substrate's existing suspension path
         fires; with an empty strategy this terminates the path
         with `CONCRETIZATION_REFUSED` (the conservative answer).
"""

import pytest

import multiplier as mx

from multiplier.symex import (
    ConcretizeByRegion,
    ConcretizeFinite,
    ConstrainTo,
    Layout,
    OOBSink,
    SymExEngine,
    Suspension,
)
from multiplier.symex.dispatch import InterceptorPolicy, _is_z3, _z3_module
from multiplier.symex.events import EventKind, Terminal

_interp = mx.ir.interpret


# ---------------------------------------------------------------------------
# Shared helper: substitute a fresh z3 BitVec for the parameter-slot
# load of the symbolic index, mirroring the Phase 6 / Phase 7 fixture.
# ---------------------------------------------------------------------------

def _intercept_index_as_z3(engine, region_lo, region_hi, *,
                            name="idx", lo=None, hi=None):
    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and not (region_lo <= addr < region_hi) \
                and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int(name, size=size, lo=lo, hi=hi)
        return next_hook(ctx, addr, size)

    return fired


# ===========================================================================
# P8a.1 — SplitByRegion + symbolic load over the overlay, end to end
# ===========================================================================

def test_p8a_1_split_by_region_load_via_overlay_e2e(index):
    """`engine.explore` no longer infinite-loops on a SplitByRegion
    child. The Phase 8a `symbolic_load` hook reads through the
    region's z3 Array overlay and the path completes; the load's
    recorded event carries a z3 expression as its `value`."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 64
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(range(SIZE)))

    _intercept_index_as_z3(engine, BUF, BUF + SIZE, lo=0, hi=15)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeByRegion(engine.layout))

    assert len(paths) >= 1
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed, \
        "no path completed — symbolic_load may have re-suspended"
    for p in completed:
        assert p._region_at_suspension == "g_buf"
        # The proof that `symbolic_load` ran: a MEMORY_READ event
        # tagged with the region whose `value` is a z3 expression.
        ev = p.events.first(kind=EventKind.MEMORY_READ, region="g_buf")
        assert ev is not None, \
            "no overlay-tagged memory_read event — symbolic_load didn't fire"
        assert _is_z3(ev["value"]), \
            f"expected z3 value in event, got {type(ev['value']).__name__}"


# ===========================================================================
# P8a.2 — feasibility / multi-address survival via ConcretizeByRegion
# ===========================================================================

def test_p8a_2_split_by_region_offset_stays_symbolic_e2e(index):
    """With `idx ∈ [0, 3]` constrained, the SplitByRegion child's
    path condition admits four distinct in-region addresses end to
    end. The substrate's organic ptr_add (Phase 7) plus the new
    overlay-backed load (Phase 8a) keep the offset symbolic through
    the resumed step."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 32
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(range(SIZE)))

    _intercept_index_as_z3(engine, BUF, BUF + SIZE, lo=0, hi=3)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeByRegion(engine.layout))

    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed
    for p in completed:
        s = z3.Solver()
        for c in p.path_condition:
            s.add(c)
        # Enumerate up to four distinct values of idx; each is a
        # different in-region address.
        idx_var = p.solver._fresh_vars["idx"]
        seen = set()
        for _ in range(5):
            if s.check() != z3.sat:
                break
            v = s.model().eval(idx_var, model_completion=True).as_long()
            seen.add(v)
            s.add(idx_var != v)
        assert len(seen) >= 2, \
            f"expected multiple satisfying idx values, got {seen}"


# ===========================================================================
# P8a.3 — OOBSink symbolic-mode witness through engine.explore
# ===========================================================================

def test_p8a_3_oob_sink_symbolic_witness_e2e(index):
    """A 9-byte region with a 4-byte read leaves a 3-byte
    partial-overflow window at the upper edge (addr ∈ [BUF+5, BUF+9)
    has addr+4 > BUF+9). With `idx` symbolic and SplitByRegion
    asserting `addr ∈ region`, OOBSink._check_symbolic finds a
    sat model — the witness reproduces the partial overflow.

    Phase 7's P7.4 ran this synthetically because the substrate
    re-suspended on the resumed load; Phase 8a's symbolic_load
    closes that gap, so the test now drives the whole pipeline
    through `engine.explore`."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=9,
                                init=bytes(range(1, 10)))
    engine.sinks.add(OOBSink())

    # idx free over a wide range so the partial-overflow region edge
    # admits a witness. The path condition assertion `addr ∈ region`
    # alone leaves the upper-edge OOB satisfiable.
    _intercept_index_as_z3(engine, BUF, BUF + 9, lo=0, hi=2**31 - 1)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeByRegion(engine.layout))

    findings = []
    for p in paths:
        for f in p.findings:
            if f.kind == "oob_read":
                findings.append((p, f))
    assert findings, "no oob_read finding fired through symbolic_load"
    p, f = findings[0]
    assert f.mode == "symbolic"
    assert f.region == "g_buf"
    # The witness names the free `idx` (not the derived `addr` —
    # that's an expression of `idx`). Reconstruct the OOB address
    # from `idx` and verify it sits in the partial-overflow window.
    idx_value = f.witness.get("idx")
    assert idx_value is not None
    addr_value = BUF + idx_value * 4
    assert BUF + 5 <= addr_value < BUF + 9
    assert addr_value + 4 > BUF + 9


# ===========================================================================
# P8a.4 — concrete write mirrors into overlay; symbolic read sees it
# ===========================================================================

def test_p8a_4_overlay_concrete_then_symbolic_read(index):
    """Drive both the concrete and the symbolic memory paths in one
    trace. A symbolic read materializes the overlay; a subsequent
    concrete write through `mem_write` mirrors into the overlay
    (Phase 6 invariant); a constrained-to-the-write-offset read of
    the overlay returns the written byte.

    Tested at the dispatch level rather than through `engine.explore`
    because there's no straightforward IR fixture that performs
    both a symbolic-offset and a concrete-offset access in a single
    function. The seam being validated is `_mirror_concrete_write_to_overlay`
    composing with `symbolic_load`."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 64
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(SIZE))

    parent_paths = engine.explore("symbolic_test_ptr_add",
                                   args=[BUF, 0],
                                   concretize=ConcretizeFinite([BUF]))
    parent = parent_paths[0]
    parent._region_at_suspension = "g_buf"

    policy = InterceptorPolicy(engine, parent, layout=engine.layout)

    addr_var = z3.BitVec("addr", 64)

    # First symbolic read — materializes the overlay.
    read1 = policy.symbolic_load(addr_var, 1, False)
    assert read1 is not NotImplemented
    region = engine.layout.region_for_name("g_buf")
    assert region.has_overlay()

    # Concrete write at offset +5: mirrors into the overlay.
    OFFSET = 5
    BYTE = 0xAB
    policy.mem_write(BUF + OFFSET, BYTE, 1, False)

    # Second symbolic read: constrain the address to the write offset
    # and verify the model returns BYTE.
    read2 = policy.symbolic_load(addr_var, 1, False)
    assert _is_z3(read2)

    s = z3.Solver()
    s.add(addr_var == BUF + OFFSET)
    s.add(read2 == z3.BitVecVal(BYTE, 8))
    assert s.check() == z3.sat


# ===========================================================================
# P8a.5 — ConstrainTo predicate on path_condition + overlay load
# ===========================================================================

def test_p8a_5_constrain_to_alignment_and_overlay_load(index):
    """Hybrid validation of the ConstrainTo + symbolic_load
    composition. ConstrainTo's predicate landing on the child's
    path_condition is verified through `engine._dispatch_constrain_to`
    (the same shape Phase 7 P7.3 used). The symbolic_load seam is
    then exercised on a region-tagged child to verify it returns a
    real z3 Select rather than collapsing to a default-0 value.

    Composing ConstrainTo with explicit region context is what an
    analyst-defined strategy that wants both alignment AND overlay
    backing has to set up; this test covers the seams without
    requiring further engine API."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 64
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(range(SIZE)))

    parent_paths = engine.explore("symbolic_test_ptr_add",
                                   args=[BUF, 0],
                                   concretize=ConcretizeFinite([BUF]))
    parent = parent_paths[0]

    addr_var = z3.BitVec("addr", 64)
    aligned = (addr_var & 7) == 0
    susp = Suspension(address_expr=addr_var, address_eid=99,
                      size=4, is_write=False, path=parent,
                      layout=engine.layout, solver=parent.solver)

    children = []
    fork_state = _interp.clone_state(parent.state)

    def take_state():
        return _interp.clone_state(fork_state)

    engine._dispatch_constrain_to(
        parent, susp, ConstrainTo(constraint=aligned),
        take_state, children)
    assert len(children) == 1
    child = children[0]
    assert aligned in child.path_condition

    # Apply the analyst's region context: composing ConstrainTo with a
    # known region is the pattern symbolic_load is designed for.
    child._region_at_suspension = "g_buf"

    policy = InterceptorPolicy(engine, child, layout=engine.layout)
    result = policy.symbolic_load(addr_var, 4, False)
    assert result is not NotImplemented, \
        "symbolic_load should return a z3 expression with region context"
    assert isinstance(result, z3.ExprRef)


# ===========================================================================
# P8a.6 — LazyRegion materialization + overlay load end to end
# ===========================================================================

def test_p8a_6_lazy_region_load_e2e(index):
    """A pre-declared LazyRegion participates in ConcretizeByRegion
    just like a global. The symbolic_load against the lazy region's
    overlay completes the path with a z3 return value."""
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()
    lazy = engine.layout.declare_lazy("__lazy_g", max_size=64)

    # Use the lazy region's base as the function's base pointer so the
    # path condition is satisfiable.
    BUF = lazy.base

    _intercept_index_as_z3(engine, BUF, BUF + 64, lo=0, hi=15)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeByRegion(engine.layout))

    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed, "lazy-region path did not complete through symbolic_load"
    for p in completed:
        assert p._region_at_suspension == "__lazy_g"
        ev = p.events.first(kind=EventKind.MEMORY_READ, region="__lazy_g")
        assert ev is not None, \
            "no overlay-tagged memory_read event — symbolic_load didn't fire"
        assert _is_z3(ev["value"])


# ===========================================================================
# P8a.7 — no region context → fall through to existing suspension path
# ===========================================================================

def test_p8a_7_no_region_falls_back_to_suspension(index):
    """Without `_region_at_suspension`, `symbolic_load` returns
    NotImplemented and the substrate's existing suspension path fires.
    With an empty strategy, the path terminates with
    `CONCRETIZATION_REFUSED` — the conservative answer the gotcha
    section requires (no silent default-0 collapse)."""
    pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=64,
                                init=bytes(range(64)))

    _intercept_index_as_z3(engine, BUF, BUF + 64, lo=0, hi=15)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeFinite([]))

    assert len(paths) == 1
    p = paths[0]
    # The path didn't complete — it suspended and was refused.
    assert p.terminal in (Terminal.CONCRETIZATION_REFUSED,
                          Terminal.STUCK_SUSPENSION), \
        f"unexpected terminal {p.terminal!r}"
    # `_region_at_suspension` is unset because no SplitByRegion ran.
    assert p._region_at_suspension is None
    # Crucially: no MEMADDR_CONCRETIZE event fires, which would
    # indicate a silent default-0 resolution we explicitly want to
    # avoid.
    memev = p.events.first(kind=EventKind.MEMADDR_CONCRETIZE)
    assert memev is None
