# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 11 tests: PathSet analysis + Path taint helpers."""

import pytest

try:
    import z3
    _Z3_AVAILABLE = True
except ImportError:
    _Z3_AVAILABLE = False

pytestmark = pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _make_path(steps=0):
    from unittest.mock import MagicMock
    from multiplier.symex.path import Path
    state = MagicMock()
    state.steps = steps
    return Path(state, MagicMock())


def _make_pathset(terminals):
    """Build a PathSet whose paths have the given terminal strings (or None)."""
    from multiplier.symex.engine import PathSet
    from multiplier.symex.events import Terminal
    paths = []
    for t in terminals:
        p = _make_path()
        p.terminal = t
        paths.append(p)
    return PathSet(paths)


# ---------------------------------------------------------------------------
# P11.1  taint_sources returns fresh_int names contributing to expr
# ---------------------------------------------------------------------------

def test_p11_1_taint_sources_basic():
    path = _make_path()
    path.solver.fresh_int("x", size=4)
    path.solver.fresh_int("y", size=4)
    x = path.solver._fresh_vars["x"]
    y = path.solver._fresh_vars["y"]
    sources = path.taint_sources(x + y)
    assert sources == frozenset({"x", "y"})


# ---------------------------------------------------------------------------
# P11.2  taint_sources excludes unknown (externally created) variables
# ---------------------------------------------------------------------------

def test_p11_2_taint_sources_excludes_unknown():
    path = _make_path()
    foreign = z3.BitVec("foreign", 32)
    sources = path.taint_sources(foreign)
    assert sources == frozenset()


# ---------------------------------------------------------------------------
# P11.3  is_tainted: True when any fresh_int contributes
# ---------------------------------------------------------------------------

def test_p11_3_is_tainted_true():
    path = _make_path()
    path.solver.fresh_int("a", size=4)
    a = path.solver._fresh_vars["a"]
    assert path.is_tainted(a + z3.BitVecVal(1, 32))


# ---------------------------------------------------------------------------
# P11.4  is_tainted: False for pure foreign / concrete expressions
# ---------------------------------------------------------------------------

def test_p11_4_is_tainted_false():
    path = _make_path()
    foreign = z3.BitVec("not_mine", 32)
    assert not path.is_tainted(foreign)
    assert not path.is_tainted(z3.BitVecVal(42, 32))


# ---------------------------------------------------------------------------
# P11.5  PathSet.all_terminal — True when all paths have non-None terminal
# ---------------------------------------------------------------------------

def test_p11_5_all_terminal_true():
    from multiplier.symex.events import Terminal
    ps = _make_pathset([Terminal.COMPLETED, Terminal.COMPLETED])
    assert ps.all_terminal()


# ---------------------------------------------------------------------------
# P11.6  PathSet.all_terminal — False when any path is live
# ---------------------------------------------------------------------------

def test_p11_6_all_terminal_false():
    from multiplier.symex.events import Terminal
    ps = _make_pathset([Terminal.COMPLETED, None])
    assert not ps.all_terminal()


# ---------------------------------------------------------------------------
# P11.7  PathSet.terminals groups correctly
# ---------------------------------------------------------------------------

def test_p11_7_terminals_groups():
    from multiplier.symex.events import Terminal
    ps = _make_pathset([Terminal.COMPLETED, Terminal.COMPLETED, None, Terminal.ERROR])
    groups = ps.terminals()
    assert len(groups[Terminal.COMPLETED]) == 2
    assert len(groups[None]) == 1
    assert len(groups[Terminal.ERROR]) == 1


# ---------------------------------------------------------------------------
# P11.8  PathSet.findings aggregates across paths and injects path_id
# ---------------------------------------------------------------------------

def test_p11_8_findings_aggregation():
    from multiplier.symex.engine import PathSet

    p1 = _make_path()
    p2 = _make_path()

    f1 = {"kind": "oob_write", "addr_eid": 0, "step": 1,
          "witness": None, "region": "buf", "mode": "write"}
    f2 = {"kind": "null_deref", "addr_eid": 0, "step": 2,
          "witness": None, "region": None, "mode": "read"}
    p1.findings.append(f1)
    p2.findings.append(f2)

    ps = PathSet([p1, p2])
    all_findings = ps.findings()
    assert len(all_findings) == 2
    ids = {f["path_id"] for f in all_findings}
    assert ids == {p1.id, p2.id}


# ---------------------------------------------------------------------------
# P11.9  PathSet.findings returns empty FindingsList when no findings
# ---------------------------------------------------------------------------

def test_p11_9_findings_empty():
    ps = _make_pathset(["returned", "returned"])
    assert len(ps.findings()) == 0


# ---------------------------------------------------------------------------
# P11.10  PathSet.summary_table contains terminal labels and counts
# ---------------------------------------------------------------------------

def test_p11_10_summary_table():
    from multiplier.symex.events import Terminal
    ps = _make_pathset([Terminal.COMPLETED, Terminal.COMPLETED, None])
    table = ps.summary_table()
    assert "3" in table or "path" in table.lower()
    assert str(Terminal.COMPLETED) in table
    assert "live" in table


# ---------------------------------------------------------------------------
# P11.11  PathSet.counter_example returns (path, model) for matching path
# ---------------------------------------------------------------------------

def test_p11_11_counter_example_found():
    from multiplier.symex.engine import PathSet
    from multiplier.symex.events import Terminal

    p = _make_path()
    p.terminal = Terminal.COMPLETED
    p.solver.fresh_int("n", size=4)
    n = p.solver._fresh_vars["n"]
    # Assert n > 5 so the model must be satisfiable.
    p.path_condition.append(z3.UGT(n, z3.BitVecVal(5, 32)))
    p.solver.invalidate()

    ps = PathSet([p])
    result = ps.counter_example(lambda path: path.terminal == Terminal.COMPLETED)
    assert result is not None
    path_out, model = result
    assert path_out is p
    assert "n" in model
    assert model["n"] > 5


# ---------------------------------------------------------------------------
# P11.12  PathSet.counter_example returns None when no path matches pred
# ---------------------------------------------------------------------------

def test_p11_12_counter_example_none():
    from multiplier.symex.events import Terminal
    ps = _make_pathset([Terminal.COMPLETED])
    result = ps.counter_example(lambda p: False)
    assert result is None


# ---------------------------------------------------------------------------
# P11.13  PathSet.counter_example skips UNSAT paths
# ---------------------------------------------------------------------------

def test_p11_13_counter_example_skips_unsat():
    from multiplier.symex.engine import PathSet
    from multiplier.symex.events import Terminal

    p = _make_path()
    p.terminal = Terminal.COMPLETED
    p.solver.fresh_int("m", size=4)
    m = p.solver._fresh_vars["m"]
    # Contradictory: m > 10 AND m < 5.
    p.path_condition.append(z3.UGT(m, z3.BitVecVal(10, 32)))
    p.path_condition.append(z3.ULT(m, z3.BitVecVal(5, 32)))
    p.solver.invalidate()

    ps = PathSet([p])
    result = ps.counter_example(lambda path: True)
    assert result is None


# ---------------------------------------------------------------------------
# P11.14  PathSet.summary_table includes finding count when present
# ---------------------------------------------------------------------------

def test_p11_14_summary_table_shows_findings():
    from multiplier.symex.engine import PathSet

    p = _make_path()
    p.terminal = "completed"
    p.findings.append({"kind": "oob_write", "addr_eid": 0, "step": 1,
                       "witness": None, "region": "buf", "mode": "write"})

    ps = PathSet([p])
    table = ps.summary_table()
    assert "finding" in table.lower()
