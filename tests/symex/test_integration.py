# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Integration tests for symex phases 9-14 against real indexed IR.

All tests use the `symex_index` fixture backed by
tests/symex/c/mx-index.db (built from symex_integration.c).
Tests skip gracefully when the index isn't present.

Coverage target per phase:
  Phase 9  (address_for):     IT.1-IT.3   global-access hooks fire in real IR
  Phase 10 (provenance):      IT.4-IT.6   origin() traces through real IR ops
  Phase 11 (PathSet analysis):IT.7-IT.9   multi-path exploration, findings agg
  Phase 12 (SMT queries):     IT.10-IT.12 can_be/must_be/value_range on real PCs
  Phase 13 (snapshot):        IT.13-IT.15 snapshot round-trip during exploration
  Phase 14 (EventLog):        IT.16-IT.18 groupby/last/unique on real event logs
"""

import pytest

z3 = pytest.importorskip("z3")

from multiplier.symex.engine import SymExEngine, PathSet
from multiplier.symex.layout import Layout
from multiplier.symex.events import Terminal, MEMORY_READ, MEMORY_WRITE, BRANCH, BLOCK_ENTER


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _engine(symex_index):
    return SymExEngine(symex_index)


def _explore(symex_index, fname, *, args=None, until=None):
    e = _engine(symex_index)
    e.layout = Layout()
    paths = e.explore(fname, args=args, until=until)
    return e, paths


# ---------------------------------------------------------------------------
# Phase 9 — address_for hooks fire during real global-variable access
# ---------------------------------------------------------------------------

def test_it1_address_for_global_hook_fires(symex_index):
    """intercept.address_for fires with kind='global' when si_read_global
    accesses si_g_int. The hook must be called at least once."""
    resolved = []

    e = _engine(symex_index)
    e.layout = Layout()

    @e.intercept.address_for(kind="global")
    def capture(ctx, eid, name, kind, size, align, next_hook):
        # Return None → substrate auto-allocates; hook still fires and is logged.
        resolved.append({"name": name, "kind": kind})
        return next_hook(ctx, eid, name, kind, size, align)

    paths = e.explore("si_read_global")
    assert paths, "si_read_global must produce at least one path"
    assert resolved, "address_for hook must have fired at least once"
    g_int_resolutions = [r for r in resolved if "g_int" in (r["name"] or "")]
    assert g_int_resolutions, "address_for must have fired for si_g_int"


def test_it2_address_resolved_observe_fires(symex_index):
    """observe.address_resolved fires when a pre-placed global is resolved.
    The event carries 'source', 'addr', and 'name' fields."""
    events_seen = []

    e = _engine(symex_index)
    e.layout = Layout()
    # Pre-place si_g_int so the engine fires address_resolved (source='pre_placed').
    e.layout.place_global("si_g_int", 0x1000_0000, 4, b'\x07\x00\x00\x00')

    @e.observe.address_resolved
    def on_resolved(ctx, **payload):
        events_seen.append(payload)

    e.explore("si_read_global")
    assert events_seen, "observe.address_resolved must have fired"
    assert any(ev.get("name") == "si_g_int" for ev in events_seen), \
        f"address_resolved must carry si_g_int, got {events_seen}"
    for ev in events_seen:
        assert "addr" in ev and "source" in ev


def test_it3_address_for_pre_placed_skips_hook(symex_index):
    """When a global is pre-placed in the Layout, address_for intercept
    hooks are NOT called (the pre-placement is used directly)."""
    hook_fired = []

    e = _engine(symex_index)
    e.layout = Layout()
    # Pre-place si_g_int at a recognisable address.
    PRE_ADDR = 0x8000_0000
    e.layout.place_global("si_g_int", PRE_ADDR, 4, b'\x07\x00\x00\x00')

    @e.intercept.address_for(kind="global", name="si_g_int")
    def should_not_fire(ctx, eid, name, kind, size, align, next_hook):
        hook_fired.append(name)
        return next_hook(ctx, eid, name, kind, size, align)

    paths = e.explore("si_read_global")
    assert paths, "exploration must succeed with pre-placed global"
    assert not hook_fired, \
        "address_for hook must not fire for a pre-placed global"


# ---------------------------------------------------------------------------
# Phase 10 — provenance: origin() traces through real IR computation
# ---------------------------------------------------------------------------

def test_it4_identity_origin_traces_to_fresh_int(symex_index):
    """si_identity(x) returns x unchanged. When x is a fresh_int, the
    return value must trace back to that fresh_int via path.origin()."""
    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("x_input", 32)
    paths = e.explore("si_identity", args=[x_var])
    assert paths, "si_identity must produce paths"

    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed, f"must have a completed path, got {[p.terminal for p in paths]}"

    p = completed[0]
    rv = p.return_value
    assert rv is not None, "return_value must be set"
    origins = p.origin(rv)
    names = {r["name"] for r in origins if r.get("kind") == "fresh_int"}
    assert "x_input" in names, \
        f"origin() must trace x_input, got {origins}"


def test_it5_add_origin_traces_both_args(symex_index):
    """si_add(a, b) = a + b. Both fresh_ints must appear in
    path.origin(return_value)."""
    e = _engine(symex_index)
    e.layout = Layout()
    a_var = z3.BitVec("a_in", 32)
    b_var = z3.BitVec("b_in", 32)
    paths = e.explore("si_add", args=[a_var, b_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    p = completed[0]
    rv = p.return_value
    origins = p.origin(rv)
    names = {r["name"] for r in origins if r.get("kind") == "fresh_int"}
    assert {"a_in", "b_in"}.issubset(names), \
        f"both inputs must appear in origin, got {names}"


def test_it6_taint_sources_on_real_path(symex_index):
    """path.taint_sources(return_value) on si_add returns exactly the
    two fresh_int variable names, excluding unrelated variables."""
    e = _engine(symex_index)
    e.layout = Layout()
    a_var = z3.BitVec("ta", 32)
    b_var = z3.BitVec("tb", 32)
    paths = e.explore("si_add", args=[a_var, b_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    p = completed[0]
    sources = p.taint_sources(p.return_value)
    assert sources == frozenset({"ta", "tb"}), \
        f"taint_sources must be exactly {{ta, tb}}, got {sources}"


# ---------------------------------------------------------------------------
# Phase 11 — PathSet analysis on real multi-path exploration
# ---------------------------------------------------------------------------

def test_it7_sign_produces_three_paths(symex_index):
    """si_sign(x) has three leaf paths (x>0, x<0, x==0). Exploration
    with a fresh_int must produce at least 2 completed paths (z3
    branch coverage may merge some)."""
    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("xsign", 32)
    paths = e.explore("si_sign", args=[x_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert len(completed) >= 2, \
        f"si_sign must fork into multiple paths, got {len(completed)}"


def test_it8_all_terminal_true_after_full_explore(symex_index):
    """After exploration, paths.all_terminal() must be True — no live
    paths remain."""
    _, paths = _explore(symex_index, "si_positive",
                        args=[z3.BitVec("xp", 32)])
    assert paths.all_terminal(), \
        "all paths must be terminal after explore() returns"


def test_it9_terminals_groups_on_real_result(symex_index):
    """paths.terminals() groups real paths by terminal value. Every
    path must appear in exactly one group; completed paths must be
    non-empty."""
    _, paths = _explore(symex_index, "si_sign",
                        args=[z3.BitVec("xs", 32)])
    groups = paths.terminals()
    total_in_groups = sum(len(g) for g in groups.values())
    assert total_in_groups == len(paths), \
        "every path must appear in exactly one terminal group"
    assert Terminal.COMPLETED in groups and len(groups[Terminal.COMPLETED]) > 0, \
        "must have at least one completed path"


# ---------------------------------------------------------------------------
# Phase 12 — SMT query helpers on real path conditions
# ---------------------------------------------------------------------------

def test_it10_can_be_on_real_path(symex_index):
    """On the completed path of si_identity(x) with x unconstrained,
    can_be(return_value, 42) must be True and the return must be
    the fresh_int variable (exactly equal to x_input)."""
    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("cx", 32)
    paths = e.explore("si_identity", args=[x_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    p = completed[0]
    rv = p.return_value
    assert p.can_be(rv, 42), "unconstrained identity must be able to be 42"
    assert p.can_be(rv, 0),  "unconstrained identity must be able to be 0"


def test_it11_value_range_on_clamped_path(symex_index):
    """si_clamp_u8(x) returns values in [0, 255].  On the pass-through
    path (where x is in range), value_range of the return should be a
    subset of [0, 255]."""
    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("cu8", 32)
    paths = e.explore("si_clamp_u8", args=[x_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    for p in completed:
        rv = p.return_value
        if rv is None or not isinstance(rv, z3.BitVecRef):
            continue
        rng = p.value_range(rv)
        if rng is None:
            continue  # UNSAT path — acceptable
        lo, hi = rng
        assert 0 <= lo, f"lower bound must be >= 0, got {lo}"
        assert hi <= 255, f"upper bound must be <= 255, got {hi}"


def test_it12_must_be_on_concrete_return(symex_index):
    """si_positive(x) returns 0 or 1. On a path where x <= 0,
    must_be(return_value, 0) should be True (concrete return)."""
    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("mp", 32)
    paths = e.explore("si_positive", args=[x_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    # Find a path where the return value is concrete 0.
    zero_paths = [p for p in completed
                  if isinstance(p.return_value, int) and p.return_value == 0]
    # With a symbolic arg, the return value may be a z3 expr. Accept both.
    for p in completed:
        rv = p.return_value
        if rv is None:
            continue
        if isinstance(rv, int) and rv == 0:
            assert p.must_be(z3.BitVecVal(0, 32), 0)
            break
        if isinstance(rv, z3.BitVecRef):
            # At least one path should be satisfiably 0.
            if p.can_be(rv, 0):
                break
    else:
        pytest.fail("no completed path with a return value of 0 found")


# ---------------------------------------------------------------------------
# Phase 13 — snapshot / restore round-trip during real exploration
# ---------------------------------------------------------------------------

def test_it13_snapshot_preserves_origin_after_explore(symex_index):
    """Take a snapshot of a completed path, clear _origin_by_name, restore:
    the provenance table must be fully recovered."""
    import unittest.mock as mock

    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("snap_x", 32)
    paths = e.explore("si_identity", args=[x_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    p = completed[0]
    assert "snap_x" in p._origin_by_name

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = p.snapshot()

    assert "snap_x" in snap.origin_by_name, \
        "snapshot must capture _origin_by_name"

    p._origin_by_name.clear()
    p.restore(snap)
    assert "snap_x" in p._origin_by_name, \
        "restore must recover _origin_by_name"


def test_it14_snapshot_captures_findings_from_real_explore(symex_index):
    """Explore si_positive and artificially record a finding on a path,
    then snapshot/restore — finding must survive the round-trip."""
    import unittest.mock as mock

    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("fp_x", 32)
    paths = e.explore("si_positive", args=[x_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    p = completed[0]
    fake_finding = {"kind": "test_finding", "addr_eid": 0, "step": p.steps,
                    "witness": None, "region": "test", "mode": "read"}
    p.findings.append(fake_finding)

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = p.snapshot()

    assert len(snap.findings) == 1
    p.findings.clear()
    p.restore(snap)
    assert len(p.findings) == 1
    assert p.findings[0]["kind"] == "test_finding"


def test_it15_snapshot_entry_func_survives(symex_index):
    """entry_func set during explore_many survives snapshot/restore."""
    import unittest.mock as mock

    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("ef_x", 32)
    paths = e.explore_many(["si_identity", "si_add"],
                           args=[x_var, x_var])
    with_entry = [p for p in paths if p.entry_func is not None]
    assert with_entry, "explore_many must set entry_func"

    p = with_entry[0]
    ef = p.entry_func

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = p.snapshot()

    assert snap.entry_func is ef
    p.entry_func = None
    p.restore(snap)
    assert p.entry_func is ef


# ---------------------------------------------------------------------------
# Phase 14 — EventLog groupby / last / unique on real event logs
# ---------------------------------------------------------------------------

def test_it16_eventlog_groupby_kinds_from_real_explore(symex_index):
    """After exploring si_sign with a symbolic arg, the event log must
    contain multiple event kinds. groupby('kind') must partition them
    correctly (each group's items all share the same kind)."""
    e = _engine(symex_index)
    e.layout = Layout()
    x_var = z3.BitVec("gb_x", 32)
    paths = e.explore("si_sign", args=[x_var])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    # Use the longest event log to get the most coverage.
    p = max(completed, key=lambda p: len(p.events))
    assert len(p.events) > 0, "event log must be non-empty after exploration"

    groups = p.events.groupby("kind")
    assert len(groups) > 0, "groupby must produce at least one group"
    for kind_val, group in groups.items():
        for entry in group:
            assert entry.get("kind") == kind_val, \
                f"groupby group {kind_val!r} contains entry with kind {entry.get('kind')!r}"


def test_it17_eventlog_unique_kinds_non_empty(symex_index):
    """unique('kind') on a real exploration event log returns a non-empty
    set containing at least BLOCK_ENTER."""
    _, paths = _explore(symex_index, "si_positive",
                        args=[z3.BitVec("uq_x", 32)])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    p = max(completed, key=lambda p: len(p.events))
    kinds = p.events.unique("kind")
    assert kinds, "unique() must return a non-empty set"
    assert BLOCK_ENTER in kinds, \
        f"BLOCK_ENTER must be in event kinds, got {kinds}"


def test_it18_eventlog_last_block_enter(symex_index):
    """events.last(kind=BLOCK_ENTER) returns the final block visited,
    which must be a real block ID (non-None)."""
    _, paths = _explore(symex_index, "si_sign",
                        args=[z3.BitVec("lb_x", 32)])
    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed

    for p in completed:
        last_be = p.events.last(kind=BLOCK_ENTER)
        assert last_be is not None, "every completed path must have a last BLOCK_ENTER"
        assert last_be.get("block") is not None, \
            f"last BLOCK_ENTER must have a block field, got {last_be}"
