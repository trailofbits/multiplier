# Copyright (c) 2026-present, Trail of Bits, Inc.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.

"""Structural Concat-fold and shadow round-trip tests.

The shadow store/load pipeline must recover the original parent
expression on a full-width round trip. `z3.simplify` can't do this —
it folds the low byte through byte arithmetic asymmetrically (the low
byte of `1492 - zext_32(b)` becomes `212 + 255*b`), which destroys
the parent identity for the high bytes. The structural Concat-fold
in `dispatch._z3_concat_fold` keeps the parent reachable.
"""

import pytest

z3 = pytest.importorskip("z3")

from multiplier.symex.dispatch import (
    _z3_concat_fold, _shadow_write, _shadow_read, _z3_byte_at,
)


def _bv(val, w):
    return z3.BitVecVal(val, w)


# ---------------------------------------------------------------------------
# Direct fold tests: structural rewrites only.
# ---------------------------------------------------------------------------

def test_concat_fold_full_width_round_trip():
    """Concat of all four byte-Extracts of a 32-bit term collapses to
    the term itself (rule: full-coverage Extract → identity)."""
    b = z3.BitVec("b", 8)
    x = z3.BitVecVal(1492, 32) - z3.ZeroExt(24, b)
    parts = [z3.Extract(8 * (i + 1) - 1, 8 * i, x) for i in range(4)]
    # MSB-first concat (matching _shadow_read's layout).
    expr = z3.Concat(*reversed(parts))
    out = _z3_concat_fold(z3, expr)
    assert out.eq(x), f"expected parent recovery, got {out}"


def test_concat_fold_partial_width_to_extract():
    """Concat of two consecutive Extracts of the same parent collapses
    to one Extract spanning both."""
    x = z3.BitVec("x", 32)
    expr = z3.Concat(z3.Extract(15, 8, x), z3.Extract(7, 0, x))
    out = _z3_concat_fold(z3, expr)
    assert out.eq(z3.Extract(15, 0, x)), f"got {out}"


def test_concat_fold_mixed_parents_stays_split():
    """Different parents → fold leaves the Concat alone."""
    x = z3.BitVec("x", 32)
    y = z3.BitVec("y", 32)
    expr = z3.Concat(z3.Extract(31, 8, y), z3.Extract(7, 0, x))
    out = _z3_concat_fold(z3, expr)
    # Must be a Concat with two operands (not collapsed).
    assert z3.is_app(out) and out.decl().kind() == z3.Z3_OP_CONCAT
    assert out.num_args() == 2


def test_concat_fold_simplify_does_NOT_recover_parent():
    """Demonstrates the bug `_z3_concat_fold` exists to avoid: with
    `z3.simplify`, the low byte is folded through arithmetic and the
    full-Concat-collapse rule no longer matches."""
    b = z3.BitVec("b", 8)
    x = z3.BitVecVal(1492, 32) - z3.ZeroExt(24, b)
    parts = [z3.Extract(8 * (i + 1) - 1, 8 * i, x) for i in range(4)]
    expr = z3.Concat(*reversed(parts))
    # Naive z3.simplify: bytes 1-3 collapse, byte 0 turns into byte arith.
    naive = z3.simplify(expr)
    assert not naive.eq(x), \
        "z3.simplify unexpectedly recovered the parent — the asymmetric" \
        " byte-fold isn't firing in this z3 build, so this test no" \
        " longer guards what it was written for."
    # Our structural fold recovers the parent regardless.
    structural = _z3_concat_fold(z3, expr)
    assert structural.eq(x), f"structural fold lost the parent: {structural}"


# ---------------------------------------------------------------------------
# Shadow round-trip: STORE + LOAD via the actual helpers.
# ---------------------------------------------------------------------------

def test_shadow_round_trip_recovers_parent_32bit():
    """Storing a 32-bit symbolic term then reading it back yields the
    same term, not a byte-split residue."""
    b = z3.BitVec("b", 8)
    x = z3.BitVecVal(1492, 32) - z3.ZeroExt(24, b)

    shadow = {}
    _shadow_write(shadow, addr=0x100, val=x, size=4)
    # Concrete fallback bytes — _shadow_read prefers shadow entries
    # over these, so the actual values don't matter for this test.
    data = bytes(4)
    out = _shadow_read(shadow, addr=0x100, size=4, data=data, buf=[])
    assert out is not None
    assert out.eq(x), f"round trip lost parent identity: {out}"


def test_shadow_partial_overwrite_keeps_minimal_concat():
    """Overwriting byte 0 of a 4-byte symbolic term with a new
    8-bit value yields `Concat(Extract(31, 8, X), new_byte)` — the
    high bytes still reference X, the low byte is the new value, and
    no further fold collapses across the parent boundary."""
    b = z3.BitVec("b", 8)
    new_byte = z3.BitVec("new_byte", 8)
    x = z3.BitVecVal(1492, 32) - z3.ZeroExt(24, b)

    shadow = {}
    _shadow_write(shadow, addr=0x100, val=x, size=4)
    # Now overwrite byte 0 with a fresh symbolic byte.
    _shadow_write(shadow, addr=0x100, val=new_byte, size=1)

    data = bytes(4)
    out = _shadow_read(shadow, addr=0x100, size=4, data=data, buf=[])
    assert out is not None
    expected = z3.Concat(z3.Extract(31, 8, x), new_byte)
    assert out.eq(expected), f"got {out}, expected {expected}"