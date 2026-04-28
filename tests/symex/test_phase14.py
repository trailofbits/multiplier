# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 14 tests: EventLog groupby/last/unique, Layout.name_for,
path.condition_str."""

import pytest

try:
    import z3
    _Z3_AVAILABLE = True
except ImportError:
    _Z3_AVAILABLE = False


def _make_path():
    from unittest.mock import MagicMock
    from symex.path import Path
    state = MagicMock()
    state.steps = 0
    return Path(state, MagicMock())


def _make_log(*entries):
    from symex.events import EventLog
    return EventLog(entries)


# ---------------------------------------------------------------------------
# EventLog.last
# ---------------------------------------------------------------------------

def test_p14_1_last_no_filter():
    log = _make_log({"kind": "a", "step": 1}, {"kind": "b", "step": 2})
    assert log.last()["step"] == 2


def test_p14_2_last_with_filter():
    log = _make_log(
        {"kind": "memory_read", "step": 1},
        {"kind": "branch", "step": 2},
        {"kind": "memory_read", "step": 3},
    )
    entry = log.last(kind="memory_read")
    assert entry["step"] == 3


def test_p14_3_last_no_match_returns_none():
    log = _make_log({"kind": "a", "step": 1})
    assert log.last(kind="missing") is None


def test_p14_4_last_empty_log():
    from symex.events import EventLog
    assert EventLog().last() is None


# ---------------------------------------------------------------------------
# EventLog.groupby
# ---------------------------------------------------------------------------

def test_p14_5_groupby_kind():
    from symex.events import EventLog
    log = _make_log(
        {"kind": "memory_read",  "step": 1},
        {"kind": "branch",       "step": 2},
        {"kind": "memory_read",  "step": 3},
        {"kind": "memory_write", "step": 4},
    )
    groups = log.groupby("kind")
    assert set(groups.keys()) == {"memory_read", "branch", "memory_write"}
    assert len(groups["memory_read"]) == 2
    assert len(groups["branch"]) == 1
    # Subclass type is preserved.
    assert isinstance(groups["memory_read"], EventLog)


def test_p14_6_groupby_preserves_order():
    log = _make_log(
        {"kind": "a", "step": 1},
        {"kind": "b", "step": 2},
        {"kind": "a", "step": 3},
    )
    groups = log.groupby("kind")
    steps_a = [e["step"] for e in groups["a"]]
    assert steps_a == [1, 3]


def test_p14_7_groupby_missing_field_groups_under_none():
    log = _make_log({"kind": "a"}, {"step": 2})
    groups = log.groupby("kind")
    assert None in groups
    assert len(groups[None]) == 1


# ---------------------------------------------------------------------------
# EventLog.unique
# ---------------------------------------------------------------------------

def test_p14_8_unique_kinds():
    log = _make_log(
        {"kind": "a"}, {"kind": "b"}, {"kind": "a"}, {"kind": "c"},
    )
    assert log.unique("kind") == {"a", "b", "c"}


def test_p14_9_unique_empty():
    from symex.events import EventLog
    assert EventLog().unique("kind") == set()


def test_p14_10_unique_none_field():
    log = _make_log({"kind": "a", "region": None}, {"kind": "b"})
    assert log.unique("region") == {None}


# ---------------------------------------------------------------------------
# PathSet.groupby (same base class, different item type)
# ---------------------------------------------------------------------------

def test_p14_11_pathset_groupby_terminal():
    from symex.engine import PathSet
    from symex.events import Terminal

    paths = []
    for t in [Terminal.COMPLETED, Terminal.COMPLETED, Terminal.ERROR]:
        p = _make_path()
        p.terminal = t
        paths.append(p)
    ps = PathSet(paths)
    groups = ps.groupby("terminal")
    assert len(groups[Terminal.COMPLETED]) == 2
    assert len(groups[Terminal.ERROR]) == 1
    assert isinstance(groups[Terminal.COMPLETED], PathSet)


# ---------------------------------------------------------------------------
# Layout.name_for
# ---------------------------------------------------------------------------

def test_p14_12_name_for_global():
    from symex.layout import Layout
    layout = Layout()
    layout.place_global("my_buf", 0x1000, 64)
    assert layout.name_for(0x1000) == "my_buf"
    assert layout.name_for(0x103F) == "my_buf"   # inside the region


def test_p14_13_name_for_unmapped():
    from symex.layout import Layout
    layout = Layout()
    layout.place_global("buf", 0x2000, 32)
    assert layout.name_for(0xDEAD) is None


def test_p14_14_name_for_function():
    from symex.layout import Layout
    layout = Layout()
    layout.place_function("foo", 0x4000_0000_0000_0000)
    assert layout.name_for(0x4000_0000_0000_0000) == "foo"


# ---------------------------------------------------------------------------
# path.condition_str
# ---------------------------------------------------------------------------

@pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")
def test_p14_15_condition_str_empty():
    path = _make_path()
    assert path.condition_str() == "True"


@pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")
def test_p14_16_condition_str_single():
    path = _make_path()
    path.solver.fresh_int("x", size=4)
    x = path.solver._fresh_vars["x"]
    path.path_condition.append(z3.UGT(x, z3.BitVecVal(5, 32)))
    s = path.condition_str()
    assert "x" in s
    assert s != "True"


@pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")
def test_p14_17_condition_str_multi_joined():
    path = _make_path()
    path.solver.fresh_int("y", size=4)
    y = path.solver._fresh_vars["y"]
    path.path_condition.append(z3.UGT(y, z3.BitVecVal(0, 32)))
    path.path_condition.append(z3.ULE(y, z3.BitVecVal(10, 32)))
    s = path.condition_str()
    assert "AND" in s
    assert s.count("y") >= 2


@pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")
def test_p14_18_condition_str_custom_sep():
    path = _make_path()
    path.solver.fresh_int("z", size=4)
    z_ = path.solver._fresh_vars["z"]
    path.path_condition.append(z3.UGT(z_, z3.BitVecVal(0, 32)))
    path.path_condition.append(z3.ULE(z_, z3.BitVecVal(5, 32)))
    s = path.condition_str(sep=" & ")
    assert " & " in s
