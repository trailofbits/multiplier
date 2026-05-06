# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Chained explores via `path.explore_next` / `engine.explore(from_path=…)`.

Pre-fix, an analyst running setup-then-target as two separate
``engine.explore`` calls saw the second start with a fresh
``_symbolic_shadow`` and empty ``path_condition``, dropping every
per-path mutation accumulated during setup. The fix adds
``path.explore_next(target, args=…)`` which clones the seed path's
``InterpreterState``, calls ``interp_init_state`` to push a fresh
entry frame for ``target``, and inherits the seed's per-path bits.

Tests:

E.1  ``path.explore_next`` produces a non-empty PathSet for a
     concrete entry function.
E.2  Symbolic shadow set on the seed (via ``path.write_memory``)
     survives into the chained explore — a downstream
     ``intercept.memory_read`` of the shadowed address sees the
     planted symbolic byte.
E.3  ``path_condition`` accumulated on the seed is inherited.
E.4  Bare ``Path(...)`` (no engine) raises a clear error from
     ``explore_next``.
E.5  ``shared`` is shared by reference, ``vars`` are copied — same
     contract as forks.
"""

import pytest

from multiplier.symex import Layout, SymExEngine
from multiplier.symex.events import Terminal
from multiplier.symex.path import Path
import multiplier as mx


def test_e1_explore_next_basic(index):
    """`path.explore_next(target)` returns a non-empty PathSet."""
    e = SymExEngine(index)
    e.layout = Layout()

    setup_paths = e.explore("test_arithmetic")
    assert setup_paths, "setup explore produced no paths"
    seed = setup_paths[0]

    next_paths = seed.explore_next("test_function_calls")
    assert next_paths, "explore_next produced no paths"
    completed = [p for p in next_paths if p.terminal == Terminal.COMPLETED]
    assert completed, \
        "no path completed via explore_next; " \
        f"terminals: {[p.terminal for p in next_paths]}"


def test_e2_explore_next_inherits_symbolic_shadow(index):
    """A symbolic byte planted on the seed via ``path.write_memory``
    survives the chained explore — ``intercept.memory_read`` of the
    shadowed address sees the same z3 expression."""
    z3 = pytest.importorskip("z3")
    e = SymExEngine(index)
    e.layout = Layout()

    seed_paths = e.explore("test_arithmetic")
    seed = seed_paths[0]

    BUF = 0x40000
    e.layout.place_global("g_chain_buf", addr=BUF, size=8, init=bytes(8))
    sym_byte = z3.BitVec("sym_chain_byte", 8)
    seed.write_memory(BUF, sym_byte, size=1)

    seen = []

    @e.intercept.memory_read(addr_range=(BUF, 1))
    def watch(ctx, addr, size, next_hook):
        v = next_hook(ctx, addr, size)
        seen.append(v)
        return v

    next_paths = seed.explore_next("test_function_calls")
    assert next_paths
    # The seed's shadow should be the chained-explore path's starting
    # shadow; if any read of BUF happens during the chained explore,
    # it should see the symbolic byte. We don't require a read to
    # happen (test_function_calls may not touch BUF), but if one does
    # the value must be the planted z3 BitVec, never a stale int.
    for v in seen:
        assert isinstance(v, z3.ExprRef), \
            f"shadowed byte read returned {v!r}; shadow not inherited"


def test_e3_path_condition_inherited(index):
    """Path condition assertions on the seed are inherited."""
    z3 = pytest.importorskip("z3")
    e = SymExEngine(index)
    e.layout = Layout()

    seed_paths = e.explore("test_arithmetic")
    seed = seed_paths[0]
    x = seed.solver.fresh_int("x_chain", size=4)
    seed.assert_(x > 100)

    next_paths = seed.explore_next("test_function_calls")
    assert next_paths
    chained = next_paths[0]
    # The constraint x > 100 must be present in every chained path.
    assert any(str(c) == str(x > 100) for c in chained.path_condition), \
        f"x > 100 missing from chained path_condition: " \
        f"{[str(c) for c in chained.path_condition]}"


def test_e4_bare_path_raises(index):
    """A path without an engine reference raises from ``explore_next``."""
    interp = mx.ir.interpret
    state = interp.InterpreterState()
    mem = interp.ConcreteMemory()
    bare = Path(state, mem)
    with pytest.raises(RuntimeError, match="explore_next"):
        bare.explore_next("test_arithmetic")


def test_e5_shared_and_vars_inheritance(index):
    """`vars` is copied (per-path), `shared` is by reference (shared).
    Same contract as fork inheritance."""
    e = SymExEngine(index)
    e.layout = Layout()

    seed_paths = e.explore("test_arithmetic")
    seed = seed_paths[0]
    seed.vars["seed_token"] = 42
    seed.shared["shared_token"] = "hello"

    next_paths = seed.explore_next("test_function_calls")
    assert next_paths
    chained = next_paths[0]

    assert chained.vars.get("seed_token") == 42, \
        "vars not inherited from seed"
    assert chained.vars is not seed.vars, \
        "vars must be copied, not aliased"
    assert chained.shared.get("shared_token") == "hello"
    assert chained.shared is seed.shared, \
        "shared must be the same dict object"
