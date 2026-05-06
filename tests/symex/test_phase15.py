# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 15 — symbolic SWITCH selector forking.

When a SWITCH instruction's selector is a symbolic z3 BitVec, the
substrate emits a SwitchContinuation instead of falling through to
case-zero. The driver realizes one forked path per case (and one for
the default), each carrying a path-condition constraint that pins the
selector into the case's range.

Tests:
  P15.1  Symbolic 3-case + default switch produces 4 paths.
  P15.2  Each path's path_condition contains the right z3 constraint.
  P15.3  GNU range case [2..5] adds the range constraint.
  P15.4  No-default switch produces exactly N case paths.
  P15.5  Concrete selector still picks exactly one path (regression).
  P15.6  Infeasible case (pre-constrained selector) is dropped.
"""

import pytest

z3 = pytest.importorskip("z3")

from multiplier.symex.engine import SymExEngine
from multiplier.symex.layout import Layout
from multiplier.symex.events import (
    Terminal, EventKind, SWITCH_CASE, SWITCH_DEFAULT,
)


def _engine(symex_index):
    e = SymExEngine(symex_index)
    e.layout = Layout()
    return e


def _completed(paths):
    return [p for p in paths if p.terminal == Terminal.COMPLETED]


# ---------------------------------------------------------------------------
# P15.1 — three single-value cases + default → 4 paths
# ---------------------------------------------------------------------------

def test_p15_1_symbolic_switch_three_cases_plus_default(symex_index):
    e = _engine(symex_index)
    sel = z3.BitVec("sel", 32)
    paths = e.explore("si_switch_three", args=[sel])
    completed = _completed(paths)
    # Three single-value cases (1, 2, 3) + default → exactly 4 completed paths.
    assert len(completed) == 4, \
        f"expected 4 paths, got {len(completed)}: " \
        f"{[p.return_value for p in completed]}"


# ---------------------------------------------------------------------------
# P15.2 — path conditions identify the chosen case
# ---------------------------------------------------------------------------

def test_p15_2_symbolic_switch_path_conditions(symex_index):
    e = _engine(symex_index)
    sel = z3.BitVec("sel", 32)
    paths = e.explore("si_switch_three", args=[sel])
    completed = _completed(paths)

    # For each completed path, ask the solver what `sel` must be.
    case_witnesses = {}
    for p in completed:
        s = z3.Solver()
        for c in p.path_condition:
            s.add(c)
        if s.check() == z3.sat:
            m = s.model()
            sel_val = m.eval(sel, model_completion=True).as_long()
            case_witnesses.setdefault(p.return_value, []).append(sel_val)

    # Every case path picks exactly its case value; default picks
    # something that is not 1, 2, or 3.
    assert any(p.return_value == 10 for p in completed), \
        "case 1 (sel == 1 → return 10) must produce a path"
    assert any(p.return_value == 20 for p in completed)
    assert any(p.return_value == 30 for p in completed)
    assert any(p.return_value in (-1, 0xFFFFFFFF) for p in completed), \
        "default path (return -1) must exist"

    # Path condition must constrain `sel` to the matching case value.
    for p in completed:
        if p.return_value == 10:
            assert p.must_be(sel, 1), \
                f"return=10 path must force sel==1, got conditions={p.condition_str()}"
        elif p.return_value == 20:
            assert p.must_be(sel, 2)
        elif p.return_value == 30:
            assert p.must_be(sel, 3)
        elif p.return_value in (-1, 0xFFFFFFFF):
            # Default path: sel is none of {1, 2, 3}.
            for forbidden in (1, 2, 3):
                assert not p.can_be(sel, forbidden), \
                    f"default path must forbid sel=={forbidden}, " \
                    f"conditions={p.condition_str()}"


# ---------------------------------------------------------------------------
# P15.3 — range case [2..5] adds the right constraint
# ---------------------------------------------------------------------------

def test_p15_3_symbolic_switch_range_case(symex_index):
    e = _engine(symex_index)
    sel = z3.BitVec("sel", 32)
    paths = e.explore("si_switch_range", args=[sel])
    completed = _completed(paths)
    # One path for the [2..5] range, one for default → 2 paths.
    assert len(completed) == 2, \
        f"expected 2 paths, got {len(completed)}"

    range_paths = [p for p in completed if p.return_value == 100]
    default_paths = [p for p in completed if p.return_value in (-1, 0xFFFFFFFF)]
    assert len(range_paths) == 1
    assert len(default_paths) == 1

    p_range = range_paths[0]
    # On the range path, sel can be any value in [2, 5] but nothing else.
    for v in (2, 3, 4, 5):
        assert p_range.can_be(sel, v), \
            f"range path must admit sel=={v}, " \
            f"conditions={p_range.condition_str()}"
    for v in (1, 6):
        assert not p_range.can_be(sel, v), \
            f"range path must forbid sel=={v}, " \
            f"conditions={p_range.condition_str()}"

    p_def = default_paths[0]
    for v in (2, 3, 4, 5):
        assert not p_def.can_be(sel, v), \
            f"default path must forbid sel=={v}, " \
            f"conditions={p_def.condition_str()}"
    assert p_def.can_be(sel, 0) or p_def.can_be(sel, 6)


# ---------------------------------------------------------------------------
# P15.4 — switch without default produces only the case forks
# ---------------------------------------------------------------------------

def test_p15_4_symbolic_switch_no_default(symex_index):
    e = _engine(symex_index)
    sel = z3.BitVec("sel", 32)
    paths = e.explore("si_switch_no_default", args=[sel])
    completed = _completed(paths)
    # Three paths: case 1 (r=10), case 2 (r=20), and the implicit
    # default that falls through to `return r` with r still at its
    # initializer value 0. C "no `default:` label" doesn't remove the
    # IR's default edge — the SwitchInst has three successors and the
    # third is reachable for any sel ∉ {1, 2}.
    assert len(completed) == 3, \
        f"expected 3 paths (case 1, case 2, fall-through), " \
        f"got {len(completed)}: {[p.return_value for p in completed]}"
    return_values = {p.return_value for p in completed}
    assert return_values == {10, 20, 0}, \
        f"return values must be {{10, 20, 0}}, got {return_values}"


# ---------------------------------------------------------------------------
# P15.5 — concrete selector still picks exactly one path (regression)
# ---------------------------------------------------------------------------

def test_p15_5_concrete_switch_unchanged(symex_index):
    e = _engine(symex_index)
    paths = e.explore("si_switch_three", args=[2])
    completed = _completed(paths)
    assert len(completed) == 1, \
        f"concrete selector must yield exactly 1 path, got {len(completed)}"
    assert completed[0].return_value == 20, \
        f"concrete sel=2 must return 20, got {completed[0].return_value}"


# ---------------------------------------------------------------------------
# P15.6 — switch_case events recorded with selector_eid + range
# ---------------------------------------------------------------------------

def test_p15_6_switch_case_events_recorded(symex_index):
    e = _engine(symex_index)
    sel = z3.BitVec("sel", 32)
    paths = e.explore("si_switch_three", args=[sel])
    completed = _completed(paths)

    # Each non-default path has exactly one switch_case event with matching range.
    case_events = []
    default_events = []
    for p in completed:
        for ev in p.events:
            if ev.get("kind") == SWITCH_CASE:
                case_events.append(ev)
            elif ev.get("kind") == SWITCH_DEFAULT:
                default_events.append(ev)

    assert len(case_events) == 3, \
        f"expected 3 switch_case events across paths, got {len(case_events)}"
    assert len(default_events) == 1, \
        f"expected 1 switch_default event, got {len(default_events)}"

    case_ranges = sorted(((e["low"], e["high"]) for e in case_events))
    assert case_ranges == [(1, 1), (2, 2), (3, 3)], \
        f"unexpected case ranges {case_ranges}"

    # Selector-eid is consistent across all events.
    eids = {ev["selector_eid"] for ev in case_events + default_events}
    assert len(eids) == 1


# ---------------------------------------------------------------------------
# P15.7 — pre-constrained selector drops infeasible cases
# ---------------------------------------------------------------------------

def test_p15_7_symbolic_switch_infeasible_dropped(symex_index):
    """si_switch_constrained's early `if (sel > 1) return -2` narrows
    `sel <= 1` on the surviving switch path. Case 2 (sel == 2) is
    UNSAT under that constraint and must be dropped — without that
    drop, every fork would reach exec_ret regardless of feasibility."""
    e = _engine(symex_index)
    sel = z3.BitVec("sel", 32)
    paths = e.explore("si_switch_constrained", args=[sel])
    completed = _completed(paths)

    return_values = sorted(p.return_value for p in completed)
    # Cases 0 and 1 are feasible; case 2 is not (sel == 2 conflicts with
    # the prior `sel <= 1`). The default path is feasible because
    # `sel <= 1` admits negative values that aren't 0 or 1.
    assert 100 in return_values, \
        f"case 0 path must survive, got {return_values}"
    assert 200 in return_values, \
        f"case 1 path must survive, got {return_values}"
    assert 300 not in return_values, \
        f"case 2 must be dropped as infeasible, got {return_values}"
