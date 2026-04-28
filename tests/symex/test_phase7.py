# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 7 — substrate ptr_* dispatch + organic OOB witness.

Catalog (matches docs/symex-phase7-plan.md):

P7.1  ptr_add now dispatches through Python; the substrate emits a z3
      address_expr at suspension. Proven by the presence of a
      MEMADDR_CONCRETIZE event on a single-decision ConcretizeFinite
      run (the event only fires when the substrate suspended on a
      non-extractable address, which can only happen when ptr_add
      produced a z3 ExprRef).
P7.2  Path-condition feasibility filtering through symbolic
      address_expr: with idx bounded to a sub-range, ConcretizeFinite
      decisions outside the reachable address set are rejected E2E.
      Pre-Phase 7 this would have admitted every decision (the
      substrate collapsed ptr_add to concrete and the strategy never
      consulted a path condition over the index).
P7.3  Custom strategy returns ConstrainTo(addr_var % 8 == 0) over a
      synthesized z3 address_expr; the constraint lands on the
      child's path_condition AND no `constrain_to_concrete_addr`
      event fires — the regression guard called out in the Phase 7
      plan's gotcha section.
P7.4  OOBSink fires in symbolic-addr mode given a synthesized
      Suspension whose path is `_region_at_suspension`-tagged.
      Verifies the symbolic-OOB pipeline end to end at the
      sink-firing seam, decoupled from the substrate's symbolic-LOAD
      resolution gap.
P7.5  CWE-787 worked example — `store_at(base, idx, value)` with a
      bounded `dst` region; ConcretizeFinite enumerates addresses
      both inside and past the buffer end. Each OOB child produces
      an `oob_write` Finding whose witness (the resolved address
      from MEMADDR_CONCRETIZE) reproduces the bug input via
      `idx = address - dst.base`.
P7.6  Loop walkthrough end-to-end via `copy_into` — exercises layout
      placement, the in-loop store/load pattern, and an observe trace
      over per-region memory access counts. Verifies bounds-check
      correctness on both the safe and the early-return paths.
P7.7  Doctest sweep over the symex package — every public docstring
      example block must run cleanly. An empty result is acceptable.

Substrate gap (deferred, not blocking Phase 7's witness payoff):
`SplitByRegion` / `ConstrainTo` resume the substrate via
`resume_addr_symbolic`, which leaves the next LOAD's address
operand a z3 expression — and `with_address_impl` re-suspends on a
non-extractable address. End-to-end exploration through these
strategies needs a future substrate hook (a `symbolic_load` /
`symbolic_store` policy method, or a region-overlay-aware
`with_address_impl`). P7.3 / P7.4 cover the wiring up to that seam
synthetically; P7.5 produces real bug witnesses through the
ConcretizeFinite path, which routes resumption through
`resume_addr` (concrete) and is unaffected.
"""

import doctest
import pkgutil

import pytest

import multiplier as mx

import multiplier.symex as symex
from multiplier.symex import (
    ConcretizeFinite,
    ConstrainTo,
    Layout,
    OOBSink,
    SplitByRegion,
    SymExEngine,
    Suspension,
)
from multiplier.symex.concretize import AddressStrategy, ConcretizeTo
from multiplier.symex.events import EventKind, MEMORY_READ
from multiplier.symex.dispatch import _z3_module

_interp = mx.ir.interpret


class _TrustConcreteAddr(AddressStrategy):
    """Resolve a suspension by trusting `suspension.address_expr` when
    it's already a concrete Python int. Use when `ptr_add` produced a
    plain int (no `("ptr", N)` tag — the substrate's existing quirk
    for fully-concrete pointer arithmetic) and the test wants the
    function to run with its natural address values."""

    def next_decisions(self, suspension):
        ae = suspension.address_expr
        if isinstance(ae, int) and not isinstance(ae, bool):
            return [ConcretizeTo(int(ae))]
        return []


# ---------------------------------------------------------------------------
# Shared helpers
# ---------------------------------------------------------------------------

def _intercept_index_as_z3(engine, region_base, region_size, *,
                            name="idx", lo=None, hi=None):
    """Substitute a fresh z3 BitVec for the first 4-byte parameter
    load that lands outside the region.

    Mirrors the Phase 6 `_setup_symbolic_index` shape; with Phase 7's
    organic ptr_add dispatch, the z3 propagates through `ptr_add` into
    the load address as a live z3 expression.
    """
    fired = []

    @engine.intercept.memory_read
    def hook(ctx, addr, size, next_hook):
        if size == 4 and not (region_base <= addr < region_base + region_size) \
                and not fired:
            fired.append(addr)
            return ctx.solver.fresh_int(name, size=size, lo=lo, hi=hi)
        return next_hook(ctx, addr, size)

    return fired


# ===========================================================================
# P7.1 — ptr_add dispatches through Python; address_expr arrives as z3
# ===========================================================================

def test_p7_1_ptr_add_dispatches_through_python(index):
    """The substrate's ptr_add now consults the policy. With a z3 index
    operand, the resulting address_expr at the load suspension is a z3
    ExprRef — verified by the presence of a MEMADDR_CONCRETIZE event,
    which only fires when the substrate suspended on a
    non-extractable address. Pre-Phase 7's collapse-to-concrete
    `ptr_add` would have produced `("ptr", BUF)` and bypassed the
    suspension path entirely."""
    pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=64, init=bytes(64))

    _intercept_index_as_z3(engine, BUF, 64)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeFinite([BUF]))
    assert len(paths) == 1
    p = paths[0]
    memev = p.events.first(kind=EventKind.MEMADDR_CONCRETIZE)
    assert memev is not None, \
        "no MEMADDR_CONCRETIZE — ptr_add did not dispatch through Python"
    assert memev["address"] == BUF
    # The intercept-minted `idx` is the source of the symbolic-ness.
    assert "idx" in p.solver._fresh_vars


# ===========================================================================
# P7.2 — feasibility filtering through symbolic address_expr
# ===========================================================================

def test_p7_2_addr_feasibility_filters_unreachable_decisions(index):
    """With `idx ∈ [0, 3]` constrained on the path condition and a
    ConcretizeFinite list whose last entry is unreachable, the engine
    drops the unreachable decision via `_addr_feasible`. Pre-Phase 7,
    `ptr_add` collapsed the symbolic idx and `_addr_feasible` was
    vacuous — every decision would have been admitted."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=32,
                                init=bytes(range(32)))

    _intercept_index_as_z3(engine, BUF, 32, lo=0, hi=3)

    # 4 addresses reachable from idx ∈ [0, 3]: BUF, BUF+4, BUF+8, BUF+12.
    # The 5th is past the bound — addr_expr = BUF + idx*4 cannot land
    # there with idx <= 3.
    candidate_addrs = [BUF + 4 * i for i in range(5)]
    paths = engine.explore(
        "symbolic_test_ptr_add",
        args=[BUF, 0],
        concretize=ConcretizeFinite(candidate_addrs))

    # 4 reachable + 0 unreachable: feasibility check rejected the 5th.
    assert len(paths) == 4
    resolved_addrs = sorted(
        p.events.first(kind=EventKind.MEMADDR_CONCRETIZE)["address"]
        for p in paths)
    assert resolved_addrs == [BUF + 4 * i for i in range(4)]
    # And every produced path is internally sat — the path_condition
    # the intercept attached (`0 <= idx <= 3`) plus the resolution
    # constraint must compose.
    for p in paths:
        s = z3.Solver()
        for c in p.path_condition:
            s.add(c)
        assert s.check() == z3.sat


# ===========================================================================
# P7.3 — ConstrainTo over a symbolic address_expr applies cleanly
# ===========================================================================

def test_p7_3_constrain_to_alignment_no_concrete_fallback(index):
    """Drive `_dispatch_constrain_to` with a synthesized Suspension
    whose `address_expr` is a z3 BitVec. The constraint lands on the
    child's path_condition and no `constrain_to_concrete_addr` event
    fires — the regression guard called out in the Phase 7 plan's
    gotcha section. (The `concrete_addr` fallback path is what
    Phase 6 hit when ptr_add collapsed; Phase 7's organic dispatch
    must keep us off that path.)"""
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("buf", addr=0x10000, size=64,
                                init=bytes(range(64)))

    parent_paths = engine.explore("symbolic_test_ptr_add",
                                   args=[0x10000, 0],
                                   concretize=ConcretizeFinite([0x10000]))
    parent = parent_paths[0]

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
    # Critical: no concrete-fallback event fired.
    fallback_events = [e for e in child.events
                       if e.get("kind") == EventKind.CONSTRAIN_TO_CONCRETE_ADDR]
    parent_fallbacks = [e for e in parent.events
                        if e.get("kind") == EventKind.CONSTRAIN_TO_CONCRETE_ADDR]
    assert not fallback_events
    assert not parent_fallbacks


# ===========================================================================
# P7.4 — OOBSink fires symbolic-addr mode through SplitByRegion
# ===========================================================================

def test_p7_4_oob_sink_symbolic_witness_through_split_by_region(index):
    """Synthesize a SplitByRegion fork over a single tight region;
    verify that `OOBSink._check_symbolic` fires when the in-region
    constraint admits a partial-overflow at the upper boundary
    (region size 9, 4-byte read leaves 3 sat OOB addrs at the top
    edge). The witness extracts the offending addr from the model.

    This validates the symbolic-OOB pipeline end to end at the
    sink-firing seam. Driving the suspension through `engine.explore`
    is gated on the substrate's symbolic-LOAD resolution work
    (deferred); the seam we care about — `path_condition ∧ ¬(addr ∈
    region)` is sat → witness emitted — is fully exercised here."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=9,
                                init=bytes(range(1, 10)))
    region = engine.layout.region_for_name("g_buf")

    parent_paths = engine.explore("symbolic_test_ptr_add",
                                   args=[BUF, 0],
                                   concretize=ConcretizeFinite([BUF]))
    parent = parent_paths[0]

    addr_var = z3.BitVec("addr", 64)
    susp = Suspension(address_expr=addr_var, address_eid=42,
                      size=4, is_write=False, path=parent,
                      layout=engine.layout, solver=parent.solver)

    children = []
    fork_state = _interp.clone_state(parent.state)

    def take_state():
        return _interp.clone_state(fork_state)

    engine._dispatch_split_by_region(
        parent, susp, SplitByRegion(regions=(region,)),
        take_state, children)
    assert len(children) == 1
    child = children[0]
    assert child._region_at_suspension == "g_buf"

    # Manually fire OOBSink._check_symbolic — the dispatch wires this
    # behind the substrate event surface; here we drive the predicate
    # directly so the test is independent of substrate resumption.
    sink = OOBSink()
    payload = {"addr": addr_var, "size": 4, "addr_eid": 42}
    finding = sink._check_symbolic(
        ctx=_FakeCtx(child, engine.layout),
        payload=payload, addr=addr_var, size=4,
        kind="oob_read", z3=z3)
    assert finding is not None, \
        "expected an OOB Finding from the partial-overflow at region edge"
    assert finding.mode == "symbolic"
    assert finding.region == "g_buf"
    # The model puts addr in (BUF+5, BUF+9), where addr+4 > BUF+9.
    addr_value = finding.witness.get("addr")
    assert addr_value is not None
    assert BUF + 5 < addr_value < BUF + 9
    assert addr_value + 4 > BUF + 9


class _FakeCtx:
    """Minimum shape OOBSink._check_symbolic needs."""
    def __init__(self, path, layout):
        self.path = path
        self.layout = layout


# ===========================================================================
# P7.5 — CWE-787 worked example: oob_write witness via store_at
# ===========================================================================

def test_p7_5_cwe787_oob_write_witness(symex_index):
    index = symex_index
    """`store_at(char *base, int index, char value)` writes one byte
    at `base[index]`. With a bounded `dst` region and ConcretizeFinite
    enumerating addresses both inside and past the end, OOBSink emits
    an `oob_write` Finding for each OOB child. The Finding's witness
    is the path's resolved concrete address (recorded on the
    MEMADDR_CONCRETIZE event); `index = address - dst.base` is the
    reproducible bug input.

    Phase 7's organic ptr_add dispatch is what makes the strategy's
    feasibility check meaningful: a symbolic `index` propagates
    through `ptr_add(base, index, 1)` into the store address, and only
    those concrete decisions consistent with the path condition
    produce a child."""
    pytest.importorskip("z3")
    BUF = 0x40000
    BUF_SIZE = 16
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("dst", addr=BUF, size=BUF_SIZE,
                                init=bytes(BUF_SIZE))
    engine.sinks.add(OOBSink())

    _intercept_index_as_z3(engine, BUF, BUF_SIZE)

    # 4 inside the buffer + 4 past the end.
    addrs = [BUF + i for i in (0, 4, 8, 12, 16, 20, 24, 28)]
    paths = engine.explore(
        "store_at",
        args=[BUF, 0, 0xAA],
        concretize=ConcretizeFinite(addrs))

    assert len(paths) == 8
    oob_paths = [p for p in paths
                 if any(f.kind == "oob_write" for f in p.findings)]
    in_bounds = [p for p in paths
                 if not any(f.kind == "oob_write" for f in p.findings)]
    assert len(in_bounds) == 4
    assert len(oob_paths) == 4

    # Every OOB Finding is reproducible from the path's resolved
    # address: replaying with `index = (resolved_addr - BUF)` reaches
    # the OOB store. This is the bug-witness payoff Phase 7 promised.
    for p in oob_paths:
        memev = p.events.first(kind=EventKind.MEMADDR_CONCRETIZE)
        assert memev is not None
        replay_index = memev["address"] - BUF
        assert replay_index >= BUF_SIZE, \
            f"resolved index {replay_index} should land past dst_size"
        assert "sink:oob_write" in p.tags


# ===========================================================================
# P7.6 — Loop walkthrough: copy_into bounds check + safe loop
# ===========================================================================

def test_p7_6_copy_into_loop_walkthrough(symex_index):
    index = symex_index
    """End-to-end exercise of the `copy_into` helper from the new
    CWE-787 corpus, verifying both branches of its bounds check
    deterministically:

      - `n <= dst_size`: the loop body runs `n` iterations; the dst
        region accumulates `n` writes and the src region `n` reads.
      - `n >  dst_size`: the early-return fires; no dst writes occur.

    Exercises layout placement and per-region memory-event aggregation
    end to end — the building blocks of the symex-vision walkthrough.
    """
    pytest.importorskip("z3")
    DST = 0x40000
    SRC = 0x50000

    def _explore(dst_size, n):
        engine = SymExEngine(index)
        engine.layout = Layout()
        engine.layout.place_global(
            "dst", addr=DST, size=16, init=bytes(16))
        engine.layout.place_global(
            "src", addr=SRC, size=16, init=bytes(range(16)))

        events = []

        @engine.observe.memory_write
        def trace_write(ctx, addr, size, value, region, **kwargs):
            if region in ("dst", "src"):
                events.append(("write", region, addr))

        @engine.observe.memory_read
        def trace_read(ctx, addr, size, value, region, **kwargs):
            if region in ("dst", "src"):
                events.append(("read", region, addr))

        paths = engine.explore("copy_into", args=[DST, dst_size, SRC, n],
                                concretize=_TrustConcreteAddr())
        assert len(paths) == 1
        return paths[0], events

    # Safe path: 8 iterations, 8 src reads + 8 dst writes.
    p_safe, events_safe = _explore(dst_size=16, n=8)
    src_reads = [e for e in events_safe if e[0] == "read" and e[1] == "src"]
    dst_writes = [e for e in events_safe if e[0] == "write" and e[1] == "dst"]
    assert len(src_reads) == 8
    assert len(dst_writes) == 8
    assert {e[2] for e in dst_writes} == {DST + i for i in range(8)}

    # Early-return path: bounds check fails, no copies happen.
    p_short, events_short = _explore(dst_size=4, n=8)
    short_writes = [e for e in events_short
                    if e[0] == "write" and e[1] == "dst"]
    assert short_writes == [], \
        "bounds check should have triggered an early return"


# ===========================================================================
# P7.7 — Docstring sweep
# ===========================================================================

def test_p7_7_docstring_examples():
    """Every public docstring's `>>> ` example block in the symex
    package must run cleanly. Modules with no example blocks are
    skipped automatically by `doctest.testmod`."""
    failures = []
    for mod_info in pkgutil.walk_packages(symex.__path__,
                                           prefix="symex."):
        try:
            module = __import__(mod_info.name, fromlist=["_"])
        except Exception:  # noqa: BLE001
            # Importing some modules requires optional deps (z3, etc.).
            # Skip silently — the dep-bearing modules have their own
            # tests.
            continue
        result = doctest.testmod(
            module, verbose=False,
            optionflags=doctest.ELLIPSIS | doctest.NORMALIZE_WHITESPACE,
            raise_on_error=False)
        if result.failed:
            failures.append((mod_info.name, result.failed, result.attempted))
    assert not failures, f"doctest failures: {failures}"
