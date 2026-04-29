# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Phase 8c — symbolic-capable substrate slots.

Phase 8b worked around a single symptom (symbolic primitive returns
collapsed to 0) by short-circuiting `read_return_value` to the SSA
operand of `RET`. The underlying gap remained: any symbolic write
to a substrate-allocated address (return slot, ALLOCA/ARG,
ALLOCA/LOCAL) was silently dropped by `_make_default_mem_write`,
so a same-address read returned pre-symbolic concrete bytes.

Phase 8c carries a `(addr, size) -> z3 expr` shadow on `Path` and
plumbs it through `InterceptorPolicy` so the dispatcher's default
mem_read / mem_write consult it for substrate-allocated addresses.

Catalog:

  P8c.1   `InterceptorPolicy.mem_write` of a z3 expression to a
          concrete address followed by `mem_read` at the same
          (addr, size) returns the stored z3 — proving the shadow
          round-trips at the dispatcher seam (no IR; the seam is
          the same one that the return slot, ALLOCA/ARG, and
          ALLOCA/LOCAL all hit).
"""

import multiplier as mx

from multiplier.symex import Layout, SymExEngine
from multiplier.symex.dispatch import InterceptorPolicy, _is_z3
from multiplier.symex.path import Path

_interp = mx.ir.interpret


def test_p8c_1_shadow_roundtrips_symbolic_write(index):
    """A z3 store to a concrete substrate-allocated address followed
    by an exact-match z3-shaped read recovers the stored expression.

    Pre-Phase-8c the read returns the slot's pre-symbolic concrete
    bytes (zero for a fresh address); post-fix the shadow round-trips
    the z3 expression so callers see the symbolic value the substrate
    just wrote."""
    import z3

    SLOT = 0x80000  # not inside any layout-named region
    SIZE = 4

    engine = SymExEngine(index)
    engine.layout = Layout()
    # Reserve concrete backing so the lens can read/write — the
    # write itself goes to the shadow, but the lens still wants an
    # addressable byte range for the would-be concrete fallback.
    engine.layout.memory.place_at(SLOT, SIZE, 1)

    # Real Path so the shadow lives somewhere durable; two policies
    # share it via `path._symbolic_shadow`, mirroring the cross-step
    # flow (write in step N, read in step N+1).
    path = Path(state=None, mem=engine.layout.memory)

    sym = z3.BitVec("sym_ret", SIZE * 8)

    writer = InterceptorPolicy(engine, path=path, layout=engine.layout)
    writer.mem_write(("ptr", SLOT), sym, SIZE, False)

    reader = InterceptorPolicy(engine, path=path, layout=engine.layout)
    got = reader.mem_read(("ptr", SLOT), SIZE, False)

    assert _is_z3(got), \
        f"expected z3 expression from shadow read; got {type(got).__name__}"
    # The byte-granular shadow reconstructs via Concat(Extract(...)); z3.simplify
    # collapses that back to the original variable, so structural eq holds.
    import z3 as _z3
    assert _z3.simplify(got).eq(_z3.simplify(sym)), \
        f"shadow returned a different expression: {got!r} vs {sym!r}"
