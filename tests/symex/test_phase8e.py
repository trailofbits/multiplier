# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 8e — close the LOCAL_VALUE alloca regression that Phase 8d
surfaced but couldn't fix in scope.

The bug: `PythonPolicy::ptr_offset` and `ptr_add` fall back to the
shared C++ concrete implementation when the InterceptorPolicy returns
NotImplemented (its concrete-input fast path). The fallback used to
funnel results through `value_to_shared`, which lowers a `Value` to a
plain `PyLong`. The pointer "tag" carried by `("ptr", N)` tuples was
lost — and downstream `extract_address` only recognizes tuples, so
every GEP_FIELD-derived address looked symbolic to the substrate. The
default address strategy concretized those to 0, sending all field
stores to address 0 and leaving every `LOCAL_VALUE` slot zero-filled.

The fix wraps both fallback paths in `make_literal_ptr` instead of
`value_to_shared`, preserving the pointer tag.

Catalog:

  P8e.1  `engine.explore("make_large", args=[7])` decodes the return
         slot to `[7, 8, 9, 10, 11]`.
  P8e.2  Functions that exercise LOCAL_VALUE allocas through
         GEP_FIELD (`test_byvalue`, `test_struct_assign`,
         `test_pointers`, `test_init_lists`) match `ConcretePolicy`'s
         return value when run through `engine.explore`.
  P8e.3  `_coerce_store_value` packs Python floats into IEEE bit
         patterns, so a symbolic-overlay float store + load round-
         trips through the bit-pattern.
"""

import struct

import pytest

from multiplier.symex import ConcretizeFinite, Layout, SymExEngine
from multiplier.symex.events import Terminal
from multiplier.symex.dispatch import InterceptorPolicy, _is_z3

from conftest import run_via_concrete_policy


def test_p8e_1_local_value_alloca_resolves(index):
    """`make_large(7)` returns `("ptr", N)` and the slot decodes to the
    five field values. Pre-fix the slot was zero-filled because the
    GEP_FIELD-derived addresses were silently concretized to 0."""
    engine = SymExEngine(index)
    engine.layout = Layout()
    paths = engine.explore("make_large", args=[7])

    assert len(paths) == 1
    p = paths[0]
    assert p.terminal == Terminal.COMPLETED, \
        f"unexpected terminal {p.terminal!r}"

    rv = p.return_value
    assert isinstance(rv, tuple) and len(rv) == 2 and rv[0] == "ptr", \
        f"expected ('ptr', N) tuple; got {rv!r}"
    slot_addr = rv[1]
    assert slot_addr != 0

    data = p.mem.read_bytes(slot_addr, 20)
    fields = [int.from_bytes(data[i * 4:(i + 1) * 4], "little", signed=True)
              for i in range(5)]
    assert fields == [7, 8, 9, 10, 11], \
        f"return slot fields are wrong: {fields!r}"


@pytest.mark.parametrize("name", [
    "test_byvalue",
    "test_struct_assign",
    "test_pointers",
    "test_init_lists",
])
def test_p8e_2_engine_explore_matches_concrete_policy(index, name):
    """The four functions listed in the Phase 8e plan as known-divergent
    between `engine.explore` (Python-policy path) and the C++
    `ConcretePolicy` driver. After the fix, both paths must produce the
    same return value."""
    expected = run_via_concrete_policy(index, name)
    if expected is None:
        pytest.skip(f"{name} not in index or did not complete via "
                    f"ConcretePolicy")

    engine = SymExEngine(index)
    engine.layout = Layout()
    paths = engine.explore(name)

    completed = [p for p in paths if p.terminal == Terminal.COMPLETED]
    assert completed, \
        f"{name}: no path completed via engine.explore"
    actual = completed[0].return_value
    assert actual == expected, \
        f"{name}: engine.explore returned {actual!r} but ConcretePolicy " \
        f"returned {expected!r}"


# ===========================================================================
# Item 2 — float-typed overlay slots
# ===========================================================================

def test_p8e_3_float_overlay_store_and_load(index):
    """Phase 8e Item 2: a Python float store through `symbolic_store`
    packs the IEEE bit pattern into the region overlay; a same-address
    load returns a z3 expression whose 32-bit value matches that bit
    pattern. Pre-fix, `_coerce_store_value` returned None for floats
    and the store dropped silently."""
    z3 = pytest.importorskip("z3")
    BUF = 0x40000
    SIZE = 64
    engine = SymExEngine(index)
    engine.layout = Layout()
    engine.layout.place_global("g_buf", addr=BUF, size=SIZE,
                                init=bytes(SIZE))

    parent_paths = engine.explore("symbolic_test_ptr_add",
                                   args=[BUF, 0],
                                   concretize=ConcretizeFinite([BUF]))
    parent = parent_paths[0]
    parent._region_at_suspension = "g_buf"

    policy = InterceptorPolicy(engine, parent, layout=engine.layout)
    addr_var = z3.BitVec("faddr", 64)

    f32 = 1.5
    expected_pattern = int.from_bytes(struct.pack("<f", f32), "little")

    # Materialize the overlay first so the store has a region to land on.
    _ = policy.symbolic_load(addr_var, 4, True)
    region = engine.layout.region_for_name("g_buf")
    assert region.has_overlay(), \
        "overlay was not materialized — symbolic_load may have refused"

    stored = policy.symbolic_store(addr_var, f32, 4, True)
    assert stored is not NotImplemented, \
        "symbolic_store refused a float; _coerce_store_value still None?"

    read_back = policy.symbolic_load(addr_var, 4, True)
    assert _is_z3(read_back), \
        f"symbolic_load did not return a z3 expression; got {read_back!r}"

    s = z3.Solver()
    s.add(addr_var == BUF)
    s.add(read_back == z3.BitVecVal(expected_pattern, 32))
    assert s.check() == z3.sat, \
        "stored float bit pattern did not round-trip through the overlay"
