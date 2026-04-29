# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 12 tests: Path SMT query helpers (can_be, must_be,
possible_values, value_range)."""

import pytest

try:
    import z3
    _Z3_AVAILABLE = True
except ImportError:
    _Z3_AVAILABLE = False

pytestmark = pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")


def _make_path():
    from unittest.mock import MagicMock
    from multiplier.symex.path import Path
    state = MagicMock()
    state.steps = 0
    return Path(state, MagicMock())


# ---------------------------------------------------------------------------
# P12.1  can_be: True for unconstrained variable
# ---------------------------------------------------------------------------

def test_p12_1_can_be_unconstrained():
    path = _make_path()
    path.solver.fresh_int("x", size=4)
    x = path.solver._fresh_vars["x"]
    assert path.can_be(x, 42)


# ---------------------------------------------------------------------------
# P12.2  can_be: False when path condition rules out the value
# ---------------------------------------------------------------------------

def test_p12_2_can_be_false():
    path = _make_path()
    path.solver.fresh_int("x", size=4)
    x = path.solver._fresh_vars["x"]
    # Force x > 10
    path.path_condition.append(z3.UGT(x, z3.BitVecVal(10, 32)))
    assert not path.can_be(x, 5)


# ---------------------------------------------------------------------------
# P12.3  must_be: True when fully constrained
# ---------------------------------------------------------------------------

def test_p12_3_must_be_true():
    path = _make_path()
    path.solver.fresh_int("y", size=4)
    y = path.solver._fresh_vars["y"]
    path.path_condition.append(y == z3.BitVecVal(7, 32))
    assert path.must_be(y, 7)


# ---------------------------------------------------------------------------
# P12.4  must_be: False for unconstrained variable
# ---------------------------------------------------------------------------

def test_p12_4_must_be_false():
    path = _make_path()
    path.solver.fresh_int("y", size=4)
    y = path.solver._fresh_vars["y"]
    assert not path.must_be(y, 7)


# ---------------------------------------------------------------------------
# P12.5  must_be: False for partially constrained (range, not single value)
# ---------------------------------------------------------------------------

def test_p12_5_must_be_partial():
    path = _make_path()
    path.solver.fresh_int("z", size=4)
    z_ = path.solver._fresh_vars["z"]
    path.path_condition.append(z3.UGE(z_, z3.BitVecVal(3, 32)))
    path.path_condition.append(z3.ULE(z_, z3.BitVecVal(9, 32)))
    assert not path.must_be(z_, 5)  # can also be 3, 4, 6, ...


# ---------------------------------------------------------------------------
# P12.6  possible_values: returns multiple distinct values for unconstrained
# ---------------------------------------------------------------------------

def test_p12_6_possible_values_multiple():
    path = _make_path()
    path.solver.fresh_int("v", size=1)  # 8-bit: 0..255
    v = path.solver._fresh_vars["v"]
    vals = path.possible_values(v, limit=5)
    assert len(vals) == 5
    assert len(set(vals)) == 5  # all distinct


# ---------------------------------------------------------------------------
# P12.7  possible_values: exactly one element when fully constrained
# ---------------------------------------------------------------------------

def test_p12_7_possible_values_constrained():
    path = _make_path()
    path.solver.fresh_int("w", size=4)
    w = path.solver._fresh_vars["w"]
    path.path_condition.append(w == z3.BitVecVal(99, 32))
    vals = path.possible_values(w)
    assert vals == [99]


# ---------------------------------------------------------------------------
# P12.8  possible_values: empty list for UNSAT path
# ---------------------------------------------------------------------------

def test_p12_8_possible_values_unsat():
    path = _make_path()
    path.solver.fresh_int("u", size=4)
    u = path.solver._fresh_vars["u"]
    # Contradictory: u > 10 AND u < 5
    path.path_condition.append(z3.UGT(u, z3.BitVecVal(10, 32)))
    path.path_condition.append(z3.ULT(u, z3.BitVecVal(5, 32)))
    assert path.possible_values(u) == []


# ---------------------------------------------------------------------------
# P12.9  possible_values: sorted output
# ---------------------------------------------------------------------------

def test_p12_9_possible_values_sorted():
    path = _make_path()
    path.solver.fresh_int("s", size=1)  # 8-bit
    s = path.solver._fresh_vars["s"]
    # Constrain to {1, 3, 5} only — but z3 won't enumerate exactly
    # those without more constraints, so just verify sorted invariant.
    vals = path.possible_values(s, limit=8)
    assert vals == sorted(vals)


# ---------------------------------------------------------------------------
# P12.10  value_range: tight bounds for a constrained variable
# ---------------------------------------------------------------------------

def test_p12_10_value_range_bounded():
    path = _make_path()
    path.solver.fresh_int("r", size=4)
    r = path.solver._fresh_vars["r"]
    path.path_condition.append(z3.UGE(r, z3.BitVecVal(3, 32)))
    path.path_condition.append(z3.ULE(r, z3.BitVecVal(7, 32)))
    lo, hi = path.value_range(r)
    assert lo == 3
    assert hi == 7


# ---------------------------------------------------------------------------
# P12.11  value_range: unconstrained 8-bit → (0, 255)
# ---------------------------------------------------------------------------

def test_p12_11_value_range_unconstrained():
    path = _make_path()
    path.solver.fresh_int("b", size=1)  # 8-bit
    b = path.solver._fresh_vars["b"]
    lo, hi = path.value_range(b)
    assert lo == 0
    assert hi == 255


# ---------------------------------------------------------------------------
# P12.12  value_range: None for UNSAT path
# ---------------------------------------------------------------------------

def test_p12_12_value_range_unsat():
    path = _make_path()
    path.solver.fresh_int("q", size=4)
    q = path.solver._fresh_vars["q"]
    path.path_condition.append(z3.UGT(q, z3.BitVecVal(100, 32)))
    path.path_condition.append(z3.ULT(q, z3.BitVecVal(50, 32)))
    assert path.value_range(q) is None


# ---------------------------------------------------------------------------
# P12.13  can_be on a compound expression
# ---------------------------------------------------------------------------

def test_p12_13_can_be_compound():
    path = _make_path()
    path.solver.fresh_int("a", size=4)
    path.solver.fresh_int("b", size=4)
    a = path.solver._fresh_vars["a"]
    b = path.solver._fresh_vars["b"]
    # No constraints: a + b can be 10
    assert path.can_be(a + b, 10)


# ---------------------------------------------------------------------------
# P12.14  can_be is non-destructive (path condition unchanged)
# ---------------------------------------------------------------------------

def test_p12_14_can_be_nondestructive():
    path = _make_path()
    path.solver.fresh_int("x", size=4)
    x = path.solver._fresh_vars["x"]
    path.path_condition.append(z3.UGT(x, z3.BitVecVal(10, 32)))
    before = len(path.path_condition)
    path.can_be(x, 5)   # should be False but must not mutate
    path.can_be(x, 15)  # should be True
    assert len(path.path_condition) == before
