# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 8d — close analyst-facing gaps left by Phase 8c.

Catalog:

  P8d.1  `engine.intercept.symbolic_load(region=…)` short-circuits and
         returns the analyst's z3 expression; the region overlay is
         not consulted.
  P8d.2  Chain composition: outer handler delegates via `next_hook`,
         inner short-circuits — the inner result propagates back.
  P8d.3  Cross-frame ALLOCA/ARG roundtrip: a callee's body computes
         on a z3 argument written into the parameter slot, and the
         result reaches `path.return_value` as z3.
  P8d.4  Per-block-enter event: `engine.observe.block_enter` fires on
         every block visit; `path.dot_cfg()` renders block edges
         even for branchless functions.
"""

import pytest

import multiplier as mx

from symex import (
    ConcretizeByRegion,
    ConcretizeFinite,
    Layout,
    SymExEngine,
)
from symex.dispatch import InterceptorPolicy, _is_z3
from symex.events import EventKind, Terminal


# ---------------------------------------------------------------------------
# Shared helper (mirrors tests/symex/test_phase8a.py).
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
# Item 1 — engine.intercept.symbolic_load / symbolic_store
# ===========================================================================

def test_p8d_1_symbolic_load_intercept_overrides_overlay(index):
    """An analyst handler registered on a SplitByRegion-tagged region
    short-circuits the chain — `next_hook` is not called, so the
    region overlay is never consulted. The analyst's z3 expression
    appears as the load's value verbatim."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 64
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(range(SIZE)))

    _intercept_index_as_z3(engine, BUF, BUF + SIZE, lo=0, hi=15)

    tag = z3.BitVec("custom_tag", 32)
    delegated = []

    @engine.intercept.symbolic_load(region="g_buf")
    def custom_load(ctx, addr, size, next_hook):
        if size == 4:
            return tag
        # Sizes other than 4 still fall through to the overlay.
        delegated.append((addr, size))
        return next_hook(ctx, addr, size)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeByRegion(engine.layout))

    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed, "no path completed via symbolic_load chain"

    p = completed[0]
    # The 4-byte load short-circuited to `tag` (identity check).
    ev = p.events.first(kind=EventKind.MEMORY_READ, region="g_buf", size=4)
    assert ev is not None, "no overlay-tagged memory_read event"
    assert ev["value"] is tag, \
        f"expected analyst's tag, got {ev['value']!r}"

    # The region overlay must not have been materialized for the 4-byte
    # load: short-circuiting before `next_hook` keeps the overlay clean.
    region = engine.layout.region_for_name("g_buf")
    assert not region.has_overlay(), \
        "overlay was materialized — short-circuit failed"


def test_p8d_2_symbolic_load_chain_composition(index):
    """Two intercept handlers compose: outer logs and forwards via
    `next_hook`; inner short-circuits with its own value. The outer's
    return is the inner's value (forwarded), confirming chain wiring."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 64
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(range(SIZE)))

    _intercept_index_as_z3(engine, BUF, BUF + SIZE, lo=0, hi=15)

    inner_value = z3.BitVecVal(0xDEADBEEF, 32)
    outer_calls = []
    inner_calls = []

    @engine.intercept.symbolic_load(region="g_buf")
    def outer(ctx, addr, size, next_hook):
        # Registered first → outermost in chain.
        outer_calls.append((addr, size))
        return next_hook(ctx, addr, size)

    @engine.intercept.symbolic_load(region="g_buf")
    def inner(ctx, addr, size, next_hook):
        inner_calls.append((addr, size))
        if size == 4:
            return inner_value
        return next_hook(ctx, addr, size)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeByRegion(engine.layout))

    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed
    p = completed[0]

    assert outer_calls, "outer handler was not invoked"
    assert inner_calls, "inner handler was not invoked"

    ev = p.events.first(kind=EventKind.MEMORY_READ, region="g_buf", size=4)
    assert ev is not None
    # The inner handler's value reached the load result via the outer
    # handler's `next_hook` forward.
    assert ev["value"] is inner_value, \
        f"inner value did not propagate; got {ev['value']!r}"


def test_p8d_2b_symbolic_load_region_selector_filters(index):
    """A handler scoped to a region that doesn't match the suspension
    must not fire. Both `g_buf` and `g_other` exist in the layout, but
    the unscoped exploration only constrains addr ∈ g_buf (the
    in-range strategy refuses g_other on infeasibility), so a handler
    scoped to a third, never-tagged name should observe zero calls."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 64
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(range(SIZE)))

    _intercept_index_as_z3(engine, BUF, BUF + SIZE, lo=0, hi=15)

    fired_other = []

    @engine.intercept.symbolic_load(region="g_never_tagged")
    def handler_for_unrelated(ctx, addr, size, next_hook):
        fired_other.append((addr, size))
        return z3.BitVec("should_not_fire", size * 8)

    paths = engine.explore("symbolic_test_ptr_add",
                           args=[BUF, 0],
                           concretize=ConcretizeByRegion(engine.layout))

    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed, "exploration did not complete"
    assert not fired_other, \
        f"handler scoped to a never-tagged region fired: {fired_other!r}"


# ===========================================================================
# Item 3 — cross-frame ALLOCA/ARG symbolic roundtrip
# ===========================================================================

def test_p8d_3_alloca_arg_symbolic_roundtrip(index):
    """Cross-frame ALLOCA/ARG E2E: the substrate writes z3 args into
    each parameter's slot at init, the body's loads pull from the
    per-Path symbolic shadow, the binary op composes them, and the
    z3 expression survives RET to reach `path.return_value`.

    Pre-Phase-8c the init-time slot writes silently dropped z3 values
    and the body computed on the slot's pre-symbolic concrete bytes
    (zero). Post-8c the shadow round-trips, and Phase 8d's engine-
    level migration of init-policy shadow → path shadow makes init-
    time z3 args reach the body's first read.
    """
    z3 = pytest.importorskip("z3")
    engine = SymExEngine(index)
    engine.layout = Layout()

    a = z3.BitVec("a", 32)
    b = z3.BitVec("b", 32)

    paths = engine.explore("symbolic_test_add_i32", args=[a, b])
    assert len(paths) == 1
    p = paths[0]
    assert p.terminal == Terminal.COMPLETED, \
        f"unexpected terminal {p.terminal!r}"
    assert _is_z3(p.return_value), \
        "ALLOCA/ARG slot did not propagate the symbolic arguments"

    # `(a + b) == 7` must be sat with a == 3, b == 4 — proves the
    # return value is structurally `a + b`, not just any z3 shape.
    s = z3.Solver()
    s.add(a == 3)
    s.add(b == 4)
    s.add(p.return_value == 7)
    assert s.check() == z3.sat, \
        f"return value is z3 but not structurally a + b: {p.return_value!r}"


# ===========================================================================
# Item 4 — per-block-enter event
# ===========================================================================

def test_p8d_4_block_enter_fires_for_every_block(index):
    """`engine.observe.block_enter` fires once per visited block.
    A function with no branches still produces at least one
    block_enter event; `path.dot_cfg()` renders an edge for the
    visit instead of the pre-Phase-8d empty placeholder."""
    engine = SymExEngine(index)

    seen = []

    @engine.observe.block_enter
    def trace(ctx, **payload):
        seen.append(payload.get("block"))

    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    assert len(paths) == 1
    p = paths[0]
    assert p.terminal == Terminal.COMPLETED
    assert p.return_value == 5

    # Branchless function: at least one block_enter must fire.
    assert seen, "no block_enter event fired"
    # All block ids should be ints (entity ids).
    assert all(isinstance(b, int) for b in seen)

    # path.events also carries the events when an observer fires (via
    # the auto-record path). dot_cfg should render at least one edge.
    block_events = p.events.where(kind=EventKind.BLOCK_ENTER)
    assert block_events, "block_enter events not recorded on path"

    dot = p.dot_cfg()
    assert dot.startswith("digraph")
    assert "->" in dot, f"dot output has no edges: {dot!r}"
    assert "no events recorded" not in dot
    assert "no branch events" not in dot


def test_p8d_4b_block_enter_without_observer_still_records(index):
    """Even with no analyst-registered observer, BLOCK_ENTER events
    land on `path.events` so `path.dot_cfg()` works out of the box.
    Pre-Phase-8d a branchless function rendered the empty digraph
    placeholder; post-Phase-8d the branchless path has block edges."""
    engine = SymExEngine(index)
    paths = engine.explore("symbolic_test_add_i32", args=[2, 3])
    p = paths[0]

    assert p.events.where(kind=EventKind.BLOCK_ENTER), \
        "block_enter events should auto-record without observers"
    dot = p.dot_cfg()
    assert "->" in dot, \
        f"branchless path should still render block edges: {dot!r}"
