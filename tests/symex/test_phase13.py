# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 13 tests: _Snapshot completeness — round-trip for all fields
added across Phases 6-10 (findings, region_at_suspension,
lazy_regions_used, entry_func, tls_base, _tls_shadow, _origin_by_name).

snapshot() / restore() must be fully symmetric. Verified via the
restore() path; resume_from() uses getattr() with safe defaults which
is correct for backward-compat with pre-Phase-13 snapshots.
"""

import pytest

try:
    import z3
    _Z3_AVAILABLE = True
except ImportError:
    _Z3_AVAILABLE = False

pytestmark = pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")


def _make_path():
    from unittest.mock import MagicMock
    from symex.path import Path
    state = MagicMock()
    state.steps = 0
    return Path(state, MagicMock())


def _snap_restore(path):
    """snapshot() → restore() round-trip on the same path object.

    Because snapshot() calls _interp.clone_state (which requires a real
    InterpreterState), we test the field-population side of snapshot()
    by inspecting the _Snapshot object directly and then manually
    calling restore() with a fake clone side-effect.
    """
    import multiplier as mx
    import unittest.mock as mock

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
    return snap


# ---------------------------------------------------------------------------
# P13.1  findings round-trip
# ---------------------------------------------------------------------------

def test_p13_1_findings_snapshot():
    path = _make_path()
    f = {"kind": "oob_read", "addr_eid": 0, "step": 1,
         "witness": None, "region": "buf", "mode": "read"}
    path.findings.append(f)
    snap = _snap_restore(path)
    assert len(snap.findings) == 1
    assert snap.findings[0]["kind"] == "oob_read"


def test_p13_1b_findings_restore():
    import unittest.mock as mock
    path = _make_path()
    f = {"kind": "oob_write", "addr_eid": 0, "step": 2,
         "witness": None, "region": "g", "mode": "write"}
    path.findings.append(f)

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
        # Clear findings, then restore.
        path.findings.clear()
        path.restore(snap)

    assert len(path.findings) == 1
    assert path.findings[0]["kind"] == "oob_write"


# ---------------------------------------------------------------------------
# P13.2  region_at_suspension round-trip
# ---------------------------------------------------------------------------

def test_p13_2_region_at_suspension():
    import unittest.mock as mock
    path = _make_path()
    path._region_at_suspension = "heap_buffer"

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
        path._region_at_suspension = None
        path.restore(snap)

    assert path._region_at_suspension == "heap_buffer"


# ---------------------------------------------------------------------------
# P13.3  lazy_regions_used round-trip
# ---------------------------------------------------------------------------

def test_p13_3_lazy_regions_used():
    import unittest.mock as mock
    path = _make_path()
    path._lazy_regions_used = 3

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
        path._lazy_regions_used = 0
        path.restore(snap)

    assert path._lazy_regions_used == 3


# ---------------------------------------------------------------------------
# P13.4  entry_func round-trip
# ---------------------------------------------------------------------------

def test_p13_4_entry_func():
    import unittest.mock as mock
    path = _make_path()
    sentinel = object()
    path.entry_func = sentinel

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
        path.entry_func = None
        path.restore(snap)

    assert path.entry_func is sentinel


# ---------------------------------------------------------------------------
# P13.5  tls_base round-trip
# ---------------------------------------------------------------------------

def test_p13_5_tls_base():
    import unittest.mock as mock
    path = _make_path()
    path.tls_base = 0x6000_0000_0000_0000

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
        path.tls_base = 0
        path.restore(snap)

    assert path.tls_base == 0x6000_0000_0000_0000


# ---------------------------------------------------------------------------
# P13.6  _tls_shadow round-trip
# ---------------------------------------------------------------------------

def test_p13_6_tls_shadow():
    import unittest.mock as mock
    path = _make_path()
    path._tls_shadow[(0x100, 8)] = 42

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
        path._tls_shadow.clear()
        path.restore(snap)

    assert path._tls_shadow[(0x100, 8)] == 42


# ---------------------------------------------------------------------------
# P13.7  _origin_by_name round-trip
# ---------------------------------------------------------------------------

def test_p13_7_origin_by_name():
    import unittest.mock as mock
    path = _make_path()
    path.solver.fresh_int("p", size=4)

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()
        path._origin_by_name.clear()
        path.restore(snap)

    assert "p" in path._origin_by_name
    assert path._origin_by_name["p"]["kind"] == "fresh_int"


# ---------------------------------------------------------------------------
# P13.8  restore() is independent — mutating path after restore
#          does not affect the snapshot
# ---------------------------------------------------------------------------

def test_p13_8_snapshot_independence():
    import unittest.mock as mock
    path = _make_path()
    path.solver.fresh_int("q", size=4)
    path._tls_shadow[(0xABC, 4)] = 99

    with mock.patch("multiplier.ir.interpret.clone_state",
                    side_effect=lambda s: s):
        snap = path.snapshot()

    # Mutate the path after snapshot is taken.
    path.solver.fresh_int("r", size=4)
    path._tls_shadow[(0xDEF, 4)] = 77

    # Snapshot must not reflect the mutations.
    assert "r" not in snap.origin_by_name
    assert (0xDEF, 4) not in snap.tls_shadow


# ---------------------------------------------------------------------------
# P13.9  _Snapshot has all expected slots
# ---------------------------------------------------------------------------

def test_p13_9_snapshot_slots():
    from symex.path import _Snapshot
    required = {
        "state", "events", "tags", "path_condition", "terminal",
        "return_value", "error_kind", "loop_iters", "func_name",
        "fresh_vars", "symbolic_shadow",
        "findings", "region_at_suspension", "lazy_regions_used",
        "entry_func", "tls_base", "tls_shadow", "origin_by_name",
    }
    assert required.issubset(set(_Snapshot.__slots__))
