"""z3 reference implementations for each opcode family.

Each function takes concrete Python values, performs the operation using z3
bitvector semantics, and returns a Python int result.  The test harness
compares these against the interpreter's output at the bit level.
"""

import z3


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _bv(val, w):
    return z3.BitVecVal(val, w)


def _result(expr):
    """Simplify a z3 bitvector expression and return as unsigned Python int."""
    return z3.simplify(expr).as_long()


def _bool_result(expr):
    """Return 1 if z3 boolean expression is true, 0 otherwise."""
    return 1 if z3.is_true(z3.simplify(expr)) else 0


# ---------------------------------------------------------------------------
# Signed arithmetic
# ---------------------------------------------------------------------------

def bv_add(a, b, w):
    return _result(_bv(a, w) + _bv(b, w))


def bv_sub(a, b, w):
    return _result(_bv(a, w) - _bv(b, w))


def bv_mul(a, b, w):
    return _result(_bv(a, w) * _bv(b, w))


def bv_sdiv(a, b, w):
    """Signed division.  Returns 0 for division by zero."""
    if (b & ((1 << w) - 1)) == 0:
        return 0
    return _result(_bv(a, w) / _bv(b, w))


def bv_srem(a, b, w):
    """Signed remainder (C99 semantics).  Returns 0 for division by zero."""
    if (b & ((1 << w) - 1)) == 0:
        return 0
    return _result(z3.SRem(_bv(a, w), _bv(b, w)))


# ---------------------------------------------------------------------------
# Unsigned arithmetic
# ---------------------------------------------------------------------------

def bv_udiv(a, b, w):
    if (b & ((1 << w) - 1)) == 0:
        return 0
    return _result(z3.UDiv(_bv(a, w), _bv(b, w)))


def bv_urem(a, b, w):
    if (b & ((1 << w) - 1)) == 0:
        return 0
    return _result(z3.URem(_bv(a, w), _bv(b, w)))


# ---------------------------------------------------------------------------
# Bitwise
# ---------------------------------------------------------------------------

def bv_and(a, b, w):
    return _result(_bv(a, w) & _bv(b, w))


def bv_or(a, b, w):
    return _result(_bv(a, w) | _bv(b, w))


def bv_xor(a, b, w):
    return _result(_bv(a, w) ^ _bv(b, w))


# ---------------------------------------------------------------------------
# Shifts  (interpreter masks shift amount by w-1)
# ---------------------------------------------------------------------------

def bv_shl(a, b, w):
    mask = w - 1
    return _result(_bv(a, w) << _bv(b & mask, w))


def bv_ashr(a, b, w):
    mask = w - 1
    return _result(_bv(a, w) >> _bv(b & mask, w))


def bv_lshr(a, b, w):
    mask = w - 1
    return _result(z3.LShR(_bv(a, w), _bv(b & mask, w)))


# ---------------------------------------------------------------------------
# Unary
# ---------------------------------------------------------------------------

def bv_neg(a, w):
    return _result(-_bv(a, w))


def bv_not(a, w):
    return _result(~_bv(a, w))


def bv_abs(a, w):
    va = _bv(a, w)
    zero = _bv(0, w)
    return _result(z3.If(va < zero, -va, va))


def bv_lognot(a, w):
    """Logical NOT: 0 if a != 0, else 1."""
    return 0 if (a & ((1 << w) - 1)) != 0 else 1


# ---------------------------------------------------------------------------
# Signed comparisons
# ---------------------------------------------------------------------------

def bv_eq(a, b, w):
    return _bool_result(_bv(a, w) == _bv(b, w))


def bv_ne(a, b, w):
    return _bool_result(_bv(a, w) != _bv(b, w))


def bv_slt(a, b, w):
    return _bool_result(_bv(a, w) < _bv(b, w))


def bv_sle(a, b, w):
    return _bool_result(_bv(a, w) <= _bv(b, w))


def bv_sgt(a, b, w):
    return _bool_result(_bv(a, w) > _bv(b, w))


def bv_sge(a, b, w):
    return _bool_result(_bv(a, w) >= _bv(b, w))


# ---------------------------------------------------------------------------
# Unsigned comparisons
# ---------------------------------------------------------------------------

def bv_ult(a, b, w):
    return _bool_result(z3.ULT(_bv(a, w), _bv(b, w)))


def bv_ule(a, b, w):
    return _bool_result(z3.ULE(_bv(a, w), _bv(b, w)))


def bv_ugt(a, b, w):
    return _bool_result(z3.UGT(_bv(a, w), _bv(b, w)))


def bv_uge(a, b, w):
    return _bool_result(z3.UGE(_bv(a, w), _bv(b, w)))


# ---------------------------------------------------------------------------
# Casts
# ---------------------------------------------------------------------------

def bv_sext(a, src_w, dst_w):
    return _result(z3.SignExt(dst_w - src_w, _bv(a, src_w)))


def bv_zext(a, src_w, dst_w):
    return _result(z3.ZeroExt(dst_w - src_w, _bv(a, src_w)))


def bv_trunc(a, src_w, dst_w):
    return _result(z3.Extract(dst_w - 1, 0, _bv(a, src_w)))


# ---------------------------------------------------------------------------
# Logical
# ---------------------------------------------------------------------------

def logical_and(a, b):
    return 1 if (a != 0 and b != 0) else 0


def logical_or(a, b):
    return 1 if (a != 0 or b != 0) else 0


def select(cond, a, b):
    return a if cond != 0 else b


# ---------------------------------------------------------------------------
# Bitwise intrinsics  (pure Python -- no z3 needed)
# ---------------------------------------------------------------------------

def bswap(a, w):
    n_bytes = w // 8
    result = 0
    for i in range(n_bytes):
        byte = (a >> (i * 8)) & 0xFF
        result |= byte << ((n_bytes - 1 - i) * 8)
    return result & ((1 << w) - 1)


def popcount(a, w):
    return bin(a & ((1 << w) - 1)).count('1')


def clz(a, w):
    val = a & ((1 << w) - 1)
    if val == 0:
        return w
    count = 0
    for i in range(w - 1, -1, -1):
        if val & (1 << i):
            break
        count += 1
    return count


def ctz(a, w):
    val = a & ((1 << w) - 1)
    if val == 0:
        return w
    count = 0
    for i in range(w):
        if val & (1 << i):
            break
        count += 1
    return count


def ffs(a, w):
    val = a & ((1 << w) - 1)
    if val == 0:
        return 0
    return ctz(a, w) + 1


def parity(a, w):
    return popcount(a, w) & 1


def rotl(a, b, w):
    shift = b & (w - 1)
    val = a & ((1 << w) - 1)
    return ((val << shift) | (val >> (w - shift))) & ((1 << w) - 1)


def rotr(a, b, w):
    shift = b & (w - 1)
    val = a & ((1 << w) - 1)
    return ((val >> shift) | (val << (w - shift))) & ((1 << w) - 1)


# ---------------------------------------------------------------------------
# Overflow detection
# ---------------------------------------------------------------------------

def _to_signed(val, w):
    mask = (1 << w) - 1
    half = 1 << (w - 1)
    v = val & mask
    return v - (1 << w) if v >= half else v


def add_overflow(a, b, w):
    """Returns 1 if signed add overflows, 0 otherwise."""
    half = 1 << (w - 1)
    sa = _to_signed(a, w)
    sb = _to_signed(b, w)
    result = sa + sb
    return 1 if result < -half or result >= half else 0


def sub_overflow(a, b, w):
    half = 1 << (w - 1)
    sa = _to_signed(a, w)
    sb = _to_signed(b, w)
    result = sa - sb
    return 1 if result < -half or result >= half else 0


def mul_overflow(a, b, w):
    half = 1 << (w - 1)
    sa = _to_signed(a, w)
    sb = _to_signed(b, w)
    result = sa * sb
    return 1 if result < -half or result >= half else 0


# ---------------------------------------------------------------------------
# Atomic RMW  (same as regular arithmetic, verifying the atomic path)
# ---------------------------------------------------------------------------

def atomic_add(initial, val, w):
    return _result(_bv(initial, w) + _bv(val, w))


def atomic_sub(initial, val, w):
    return _result(_bv(initial, w) - _bv(val, w))


def atomic_and(initial, val, w):
    return _result(_bv(initial, w) & _bv(val, w))


def atomic_or(initial, val, w):
    return _result(_bv(initial, w) | _bv(val, w))


def atomic_xor(initial, val, w):
    return _result(_bv(initial, w) ^ _bv(val, w))


def atomic_nand(initial, val, w):
    return _result(~(_bv(initial, w) & _bv(val, w)))


def atomic_xchg(initial, val, w):
    return val & ((1 << w) - 1)
