# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 10 tests: path.origin(expr) provenance walk."""

import pytest

try:
    import z3
    _Z3_AVAILABLE = True
except ImportError:
    _Z3_AVAILABLE = False

pytestmark = pytest.mark.skipif(not _Z3_AVAILABLE, reason="z3 not installed")


def _make_path():
    """Return a bare Path with a dummy state and memory."""
    from unittest.mock import MagicMock
    from multiplier.symex.path import Path

    state = MagicMock()
    state.steps = 0
    mem = MagicMock()
    return Path(state, mem)


# ---------------------------------------------------------------------------
# P10.1  fresh_int records origin in _origin_by_name
# ---------------------------------------------------------------------------

def test_p10_1_fresh_int_records_origin():
    path = _make_path()
    var = path.solver.fresh_int("x", size=4)
    assert "x" in path._origin_by_name
    rec = path._origin_by_name["x"]
    assert rec["kind"] == "fresh_int"
    assert rec["name"] == "x"
    assert rec["size"] == 4
    assert rec["path_id"] == path.id


# ---------------------------------------------------------------------------
# P10.2  fresh_int called twice: second call is a no-op for origin table
# ---------------------------------------------------------------------------

def test_p10_2_fresh_int_idempotent():
    path = _make_path()
    path.solver.fresh_int("y", size=2)
    first_rec = dict(path._origin_by_name["y"])
    path.solver.fresh_int("y", size=2)  # second call — hits the early return
    assert path._origin_by_name["y"] == first_rec


# ---------------------------------------------------------------------------
# P10.3  origin() on a single BitVec leaf
# ---------------------------------------------------------------------------

def test_p10_3_origin_single_var():
    path = _make_path()
    path.solver.fresh_int("a", size=4)
    var = path.solver._fresh_vars["a"]
    origins = path.origin(var)
    assert len(origins) == 1
    assert origins[0]["name"] == "a"
    assert origins[0]["kind"] == "fresh_int"


# ---------------------------------------------------------------------------
# P10.4  origin() on a compound expression aggregates both leaves
# ---------------------------------------------------------------------------

def test_p10_4_origin_compound_expr():
    path = _make_path()
    path.solver.fresh_int("p", size=4)
    path.solver.fresh_int("q", size=4)
    p = path.solver._fresh_vars["p"]
    q = path.solver._fresh_vars["q"]
    expr = p + q
    origins = path.origin(expr)
    names = {r["name"] for r in origins}
    assert names == {"p", "q"}
    for r in origins:
        assert r["kind"] == "fresh_int"


# ---------------------------------------------------------------------------
# P10.5  origin() on a concrete (non-variable) expression returns []
# ---------------------------------------------------------------------------

def test_p10_5_origin_concrete_returns_empty():
    path = _make_path()
    const = z3.BitVecVal(42, 32)
    # A concrete literal has no symbolic variables.
    origins = path.origin(const)
    # z3 prints concrete literals as numeric strings; they won't be in
    # _origin_by_name, so each gets {"kind": "unknown"}.
    # The contract is that no "fresh_int" origins appear.
    assert all(r["kind"] == "unknown" for r in origins)


# ---------------------------------------------------------------------------
# P10.6  origin() returns {"kind": "unknown"} for unminted variables
# ---------------------------------------------------------------------------

def test_p10_6_origin_unknown_variable():
    path = _make_path()
    # Create a z3 variable directly without going through fresh_int.
    foreign = z3.BitVec("foreign_var", 32)
    origins = path.origin(foreign)
    assert len(origins) == 1
    assert origins[0]["kind"] == "unknown"
    assert origins[0]["name"] == "foreign_var"


# ---------------------------------------------------------------------------
# P10.7  origin_tree() shape: leaf for single var
# ---------------------------------------------------------------------------

def test_p10_7_origin_tree_leaf():
    path = _make_path()
    path.solver.fresh_int("m", size=8)
    var = path.solver._fresh_vars["m"]
    tree = path.origin_tree(var)
    assert tree["kind"] == "leaf"
    assert tree["name"] == "m"
    assert tree["origin"]["kind"] == "fresh_int"


# ---------------------------------------------------------------------------
# P10.8  origin_tree() shape: op node for compound expression
# ---------------------------------------------------------------------------

def test_p10_8_origin_tree_op():
    path = _make_path()
    path.solver.fresh_int("u", size=4)
    path.solver.fresh_int("v", size=4)
    u = path.solver._fresh_vars["u"]
    v = path.solver._fresh_vars["v"]
    tree = path.origin_tree(u | v)
    assert tree["kind"] == "op"
    assert "op" in tree
    assert len(tree["args"]) == 2
    leaf_names = {child["name"] for child in tree["args"]
                  if child["kind"] == "leaf"}
    assert leaf_names == {"u", "v"}


# ---------------------------------------------------------------------------
# P10.9  _origin_by_name is propagated when path fields are copied manually
#         (simulating what clone() and _fork_child do)
# ---------------------------------------------------------------------------

def test_p10_9_clone_propagates_origins():
    from multiplier.symex.path import Path
    from unittest.mock import MagicMock
    import multiplier as mx

    path = _make_path()
    path.solver.fresh_int("src", size=4)

    # Simulate what clone() does for the origin table without needing a real
    # InterpreterState: build a second path and manually copy the fields.
    state2 = MagicMock()
    state2.steps = 0
    cloned = Path(state2, path.mem, parent_id=path.id)
    cloned._origin_by_name = dict(path._origin_by_name)
    cloned.solver.adopt_fresh_vars(path.solver._fresh_vars)

    assert "src" in cloned._origin_by_name
    assert cloned._origin_by_name["src"] == path._origin_by_name["src"]
    # Independence: new mint on clone does not leak back to parent.
    cloned.solver.fresh_int("clone_only", size=4)
    assert "clone_only" not in path._origin_by_name


# ---------------------------------------------------------------------------
# P10.10  origin() deduplicates repeated leaf variables
# ---------------------------------------------------------------------------

def test_p10_10_origin_deduplication():
    path = _make_path()
    path.solver.fresh_int("dup", size=4)
    d = path.solver._fresh_vars["dup"]
    # d + d: the same variable appears twice in the AST.
    expr = d + d
    origins = path.origin(expr)
    # Should appear exactly once.
    assert len([r for r in origins if r["name"] == "dup"]) == 1
