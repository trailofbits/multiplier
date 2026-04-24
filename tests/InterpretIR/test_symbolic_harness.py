"""Concrete differential testing: interpreter vs z3 bitvector semantics.

For 8-bit operations, every input pair is tested exhaustively (65,536 pairs
for binary ops, 256 values for unary).  For wider types, edge cases plus
random sampling are used.
"""

import math
import random
import struct

import pytest
import z3

import z3_oracle
from conftest import find_ir_function, run_ir_function


WIDTHS = [8, 16, 32, 64]


# ---------------------------------------------------------------------------
# Input generators
# ---------------------------------------------------------------------------

def int_test_inputs(width):
    """Signed integer pairs.  Exhaustive for 8-bit."""
    half = 1 << (width - 1)
    if width == 8:
        return [(a - half, b - half)
                for a in range(1 << width) for b in range(1 << width)]
    edges = [0, 1, -1, 2, -2, half - 1, -half, half - 2, -(half - 1), 42, -42]
    pairs = [(a, b) for a in edges for b in edges]
    rng = random.Random(42)
    pairs += [(rng.randint(-half, half - 1), rng.randint(-half, half - 1))
              for _ in range(500)]
    return pairs


def uint_test_inputs(width):
    """Unsigned integer pairs.  Exhaustive for 8-bit."""
    mx = (1 << width) - 1
    if width == 8:
        return [(a, b) for a in range(256) for b in range(256)]
    edges = [0, 1, 2, mx, mx - 1, mx // 2, mx // 2 + 1, 42, 255]
    pairs = [(a, b) for a in edges for b in edges]
    rng = random.Random(42)
    pairs += [(rng.randint(0, mx), rng.randint(0, mx)) for _ in range(500)]
    return pairs


def div_test_inputs(width, signed=True):
    """Like int/uint inputs but always includes b=0 cases."""
    half = 1 << (width - 1)
    mx = (1 << width) - 1
    if signed:
        if width == 8:
            return [(a - half, b - half)
                    for a in range(1 << width) for b in range(1 << width)]
        edges = [0, 1, -1, 2, -2, half - 1, -half, half - 2, -(half - 1),
                 42, -42]
    else:
        if width == 8:
            return [(a, b) for a in range(256) for b in range(256)]
        edges = [0, 1, 2, mx, mx - 1, mx // 2, mx // 2 + 1, 42, 255]
    pairs = [(a, b) for a in edges for b in edges]
    rng = random.Random(42)
    if signed:
        pairs += [(rng.randint(-half, half - 1), rng.randint(-half, half - 1))
                  for _ in range(500)]
    else:
        pairs += [(rng.randint(0, mx), rng.randint(0, mx))
                  for _ in range(500)]
    return pairs


def unary_test_inputs(width):
    """Signed unary inputs.  Exhaustive for 8-bit."""
    half = 1 << (width - 1)
    if width == 8:
        return [a - half for a in range(1 << width)]
    edges = [0, 1, -1, 2, -2, half - 1, -half, half - 2, -(half - 1), 42, -42]
    rng = random.Random(42)
    edges += [rng.randint(-half, half - 1) for _ in range(200)]
    return edges


def uint_unary_test_inputs(width):
    """Unsigned unary inputs.  Exhaustive for 8-bit."""
    mx = (1 << width) - 1
    if width == 8:
        return list(range(256))
    edges = [0, 1, 2, mx, mx - 1, mx // 2, mx // 2 + 1, 42, 255]
    rng = random.Random(42)
    edges += [rng.randint(0, mx) for _ in range(200)]
    return edges


def shift_test_inputs(width):
    """Pairs for shift operations -- shift amounts in [0, width-1] only.

    Over-width shifts are UB in C for the operand's promoted type, and
    narrow types (8/16-bit) promote to int, making the IR behavior
    dependent on compiler codegen.  We only test defined behavior.
    """
    half = 1 << (width - 1)
    mx = (1 << width) - 1
    vals = [0, 1, mx, mx - 1, mx // 2, mx // 2 + 1, 42]
    shifts = [0, 1, width - 1]
    if width == 8:
        return [(a, s) for a in range(256) for s in shifts]
    pairs = [(v, s) for v in vals for s in shifts]
    rng = random.Random(42)
    pairs += [(rng.randint(0, mx), rng.randint(0, width - 1))
              for _ in range(500)]
    return pairs


def float_binary_inputs(width):
    """Edge-case + random float pairs."""
    if width == 32:
        edges = [0.0, -0.0, 1.0, -1.0, 0.5, -0.5,
                 float('inf'), float('-inf'), float('nan'),
                 1e-38, -1e-38, 3.4028235e+38, -3.4028235e+38,
                 1.1754944e-38, 1.4012985e-45]
    else:
        edges = [0.0, -0.0, 1.0, -1.0, 0.5, -0.5,
                 float('inf'), float('-inf'), float('nan'),
                 1e-308, -1e-308, 1.7976931348623157e+308,
                 -1.7976931348623157e+308,
                 2.2250738585072014e-308, 5e-324]
    pairs = [(a, b) for a in edges for b in edges]
    rng = random.Random(42)
    pairs += [(rng.uniform(-1000, 1000), rng.uniform(-1000, 1000))
              for _ in range(50)]
    return pairs


def float_unary_inputs(width):
    """Edge-case + random float values."""
    if width == 32:
        edges = [0.0, -0.0, 1.0, -1.0, 0.5, -0.5,
                 float('inf'), float('-inf'), float('nan'),
                 1e-38, -1e-38, 3.4028235e+38, -3.4028235e+38]
    else:
        edges = [0.0, -0.0, 1.0, -1.0, 0.5, -0.5,
                 float('inf'), float('-inf'), float('nan'),
                 1e-308, -1e-308, 1.7976931348623157e+308,
                 -1.7976931348623157e+308]
    rng = random.Random(42)
    edges += [rng.uniform(-1000, 1000) for _ in range(50)]
    return edges


# ---------------------------------------------------------------------------
# f32 precision helpers -- the interpreter does true f32 arithmetic, so the
# oracle must narrow to f32 precision before comparing.
# ---------------------------------------------------------------------------

def _f32_narrow(v):
    """Round a Python float to f32 precision."""
    try:
        return struct.unpack('<f', struct.pack('<f', v))[0]
    except (struct.error, OverflowError):
        return math.copysign(float('inf'), v)


def _f32_binary(op):
    """Wrap a binary op to compute at f32 precision."""
    def fn(a, b):
        fa = _f32_narrow(a)
        fb = _f32_narrow(b)
        return _f32_narrow(op(fa, fb))
    return fn


# ---------------------------------------------------------------------------
# Verification helpers
# ---------------------------------------------------------------------------

def verify_int(result, expected, width):
    """Compare two values at the given bit width (sign-agnostic)."""
    mask = (1 << width) - 1
    return (int(result) & mask) == (int(expected) & mask)


def verify_float(result, expected, width):
    """Bit-exact float comparison (handles NaN)."""
    if isinstance(expected, float) and math.isnan(expected):
        return isinstance(result, float) and math.isnan(result)
    if isinstance(result, float) and math.isnan(result):
        return False
    fmt = '<f' if width == 32 else '<d'
    try:
        ir_bits = struct.pack(fmt, result)
        ex_bits = struct.pack(fmt, expected)
    except (struct.error, OverflowError):
        return result == expected
    return ir_bits == ex_bits


# ---------------------------------------------------------------------------
# Generic test runners
# ---------------------------------------------------------------------------

def _run_binary(index, func_resolver, global_resolver, width,
                fname_pattern, oracle_fn, inputs):
    fname = fname_pattern.format(width)
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a, b in inputs:
        result = run_ir_function(ir, [a, b], func_resolver, global_resolver)
        expected = oracle_fn(a, b, width)
        assert verify_int(result, expected, width), \
            f"{fname}({a}, {b}): 0x{int(result) & ((1<<width)-1):x} != " \
            f"0x{int(expected) & ((1<<width)-1):x}"


def _run_unary(index, func_resolver, global_resolver, width,
               fname_pattern, oracle_fn, inputs):
    fname = fname_pattern.format(width)
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in inputs:
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = oracle_fn(a, width)
        assert verify_int(result, expected, width), \
            f"{fname}({a}): 0x{int(result) & ((1<<width)-1):x} != " \
            f"0x{int(expected) & ((1<<width)-1):x}"


# ===================================================================
# Signed arithmetic
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_add(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_add_i{}", z3_oracle.bv_add,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_sub(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_sub_i{}", z3_oracle.bv_sub,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_mul(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_mul_i{}", z3_oracle.bv_mul,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_div(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_div_i{}", z3_oracle.bv_sdiv,
                div_test_inputs(width, signed=True))


@pytest.mark.parametrize("width", WIDTHS)
def test_rem(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_rem_i{}", z3_oracle.bv_srem,
                div_test_inputs(width, signed=True))


# ===================================================================
# Unsigned arithmetic
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_udiv(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_udiv_u{}", z3_oracle.bv_udiv,
                div_test_inputs(width, signed=False))


@pytest.mark.parametrize("width", WIDTHS)
def test_urem(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_urem_u{}", z3_oracle.bv_urem,
                div_test_inputs(width, signed=False))


# ===================================================================
# Bitwise
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_and(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_and_u{}", z3_oracle.bv_and,
                uint_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_or(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_or_u{}", z3_oracle.bv_or,
                uint_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_xor(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_xor_u{}", z3_oracle.bv_xor,
                uint_test_inputs(width))


# ===================================================================
# Shifts
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_shl(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_shl_u{}", z3_oracle.bv_shl,
                shift_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_shr(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_shr_i{}", z3_oracle.bv_ashr,
                shift_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_ushr(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_ushr_u{}", z3_oracle.bv_lshr,
                shift_test_inputs(width))


# ===================================================================
# Unary
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_neg(index, func_resolver, global_resolver, width):
    _run_unary(index, func_resolver, global_resolver, width,
               "symbolic_test_neg_i{}", z3_oracle.bv_neg,
               unary_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_bitnot(index, func_resolver, global_resolver, width):
    _run_unary(index, func_resolver, global_resolver, width,
               "symbolic_test_bitnot_u{}", z3_oracle.bv_not,
               uint_unary_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_abs(index, func_resolver, global_resolver, width):
    _run_unary(index, func_resolver, global_resolver, width,
               "symbolic_test_abs_i{}", z3_oracle.bv_abs,
               unary_test_inputs(width))


def test_lognot(index, func_resolver, global_resolver):
    fname = "symbolic_test_lognot_i32"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in unary_test_inputs(32):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.bv_lognot(a, 32)
        assert verify_int(result, expected, 32), \
            f"{fname}({a}): {result} != {expected}"


# ===================================================================
# Signed comparisons
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_eq(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_eq_i{}", z3_oracle.bv_eq,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_ne(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_ne_i{}", z3_oracle.bv_ne,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_lt(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_lt_i{}", z3_oracle.bv_slt,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_le(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_le_i{}", z3_oracle.bv_sle,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_gt(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_gt_i{}", z3_oracle.bv_sgt,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_ge(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_ge_i{}", z3_oracle.bv_sge,
                int_test_inputs(width))


# ===================================================================
# Unsigned comparisons
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_ult(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_ult_u{}", z3_oracle.bv_ult,
                uint_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_ule(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_ule_u{}", z3_oracle.bv_ule,
                uint_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_ugt(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_ugt_u{}", z3_oracle.bv_ugt,
                uint_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_uge(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_uge_u{}", z3_oracle.bv_uge,
                uint_test_inputs(width))


# ===================================================================
# Float arithmetic
# ===================================================================

def _run_float_binary(index, func_resolver, global_resolver, width,
                      fname, py_op, inputs):
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a, b in inputs:
        result = run_ir_function(ir, [a, b], func_resolver, global_resolver)
        expected = py_op(a, b)
        assert verify_float(result, expected, width), \
            f"{fname}({a}, {b}): {result} != {expected}"


def _run_float_unary(index, func_resolver, global_resolver, width,
                     fname, py_op, inputs):
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in inputs:
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = py_op(a)
        assert verify_float(result, expected, width), \
            f"{fname}({a}): {result} != {expected}"


@pytest.mark.parametrize("width", [32, 64])
def test_fadd(index, func_resolver, global_resolver, width):
    suffix = "f32" if width == 32 else "f64"
    op = _f32_binary(lambda a, b: a + b) if width == 32 else lambda a, b: a + b
    _run_float_binary(
        index, func_resolver, global_resolver, width,
        f"symbolic_test_fadd_{suffix}", op,
        float_binary_inputs(width))


@pytest.mark.parametrize("width", [32, 64])
def test_fsub(index, func_resolver, global_resolver, width):
    suffix = "f32" if width == 32 else "f64"
    op = _f32_binary(lambda a, b: a - b) if width == 32 else lambda a, b: a - b
    _run_float_binary(
        index, func_resolver, global_resolver, width,
        f"symbolic_test_fsub_{suffix}", op,
        float_binary_inputs(width))


@pytest.mark.parametrize("width", [32, 64])
def test_fmul(index, func_resolver, global_resolver, width):
    suffix = "f32" if width == 32 else "f64"
    op = _f32_binary(lambda a, b: a * b) if width == 32 else lambda a, b: a * b
    _run_float_binary(
        index, func_resolver, global_resolver, width,
        f"symbolic_test_fmul_{suffix}", op,
        float_binary_inputs(width))


@pytest.mark.parametrize("width", [32, 64])
def test_fdiv(index, func_resolver, global_resolver, width):
    suffix = "f32" if width == 32 else "f64"

    def ieee_div(a, b):
        """IEEE 754 division — Python raises ZeroDivisionError, C doesn't."""
        try:
            return a / b
        except ZeroDivisionError:
            if a == 0.0 or math.isnan(a):
                return float('nan')
            return math.copysign(float('inf'), math.copysign(1.0, a) * math.copysign(1.0, b))

    op = _f32_binary(ieee_div) if width == 32 else ieee_div
    _run_float_binary(
        index, func_resolver, global_resolver, width,
        f"symbolic_test_fdiv_{suffix}", op,
        float_binary_inputs(width))


@pytest.mark.parametrize("width", [32, 64])
def test_frem(index, func_resolver, global_resolver, width):
    suffix = "f32" if width == 32 else "f64"
    op = _f32_binary(math.fmod) if width == 32 else math.fmod
    _run_float_binary(
        index, func_resolver, global_resolver, width,
        f"symbolic_test_frem_{suffix}", op,
        # Skip pairs where b==0 or either is inf/nan (fmod is undefined)
        [(a, b) for a, b in float_binary_inputs(width)
         if b != 0.0 and not math.isinf(a) and not math.isnan(a)
         and not math.isinf(b) and not math.isnan(b)])


@pytest.mark.parametrize("width", [32, 64])
def test_fneg(index, func_resolver, global_resolver, width):
    suffix = "f32" if width == 32 else "f64"
    _run_float_unary(
        index, func_resolver, global_resolver, width,
        f"symbolic_test_fneg_{suffix}", lambda a: -a,
        float_unary_inputs(width))


# ===================================================================
# Float comparisons
# ===================================================================

@pytest.mark.parametrize("width", [32, 64])
@pytest.mark.parametrize("op,py_op", [
    ("eq", lambda a, b: 1 if a == b else 0),
    ("ne", lambda a, b: 1 if a != b else 0),
    ("lt", lambda a, b: 1 if a < b else 0),
    ("le", lambda a, b: 1 if a <= b else 0),
    ("gt", lambda a, b: 1 if a > b else 0),
    ("ge", lambda a, b: 1 if a >= b else 0),
], ids=["eq", "ne", "lt", "le", "gt", "ge"])
def test_fcmp(index, func_resolver, global_resolver, width, op, py_op):
    suffix = "f32" if width == 32 else "f64"
    fname = f"symbolic_test_fcmp_{op}_{suffix}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a, b in float_binary_inputs(width):
        result = run_ir_function(ir, [a, b], func_resolver, global_resolver)
        expected = py_op(a, b)
        assert int(result) == expected, \
            f"{fname}({a}, {b}): {result} != {expected}"


# ===================================================================
# Casts -- sign extension
# ===================================================================

SEXT_CASES = [
    (8, 16), (8, 32), (8, 64), (16, 32), (16, 64), (32, 64),
]


@pytest.mark.parametrize("src_w,dst_w", SEXT_CASES,
                         ids=[f"i{s}_i{d}" for s, d in SEXT_CASES])
def test_sext(index, func_resolver, global_resolver, src_w, dst_w):
    fname = f"symbolic_test_sext_i{src_w}_i{dst_w}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in unary_test_inputs(src_w):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.bv_sext(a, src_w, dst_w)
        assert verify_int(result, expected, dst_w), \
            f"{fname}({a}): 0x{int(result) & ((1<<dst_w)-1):x} != " \
            f"0x{expected & ((1<<dst_w)-1):x}"


# ===================================================================
# Casts -- zero extension
# ===================================================================

ZEXT_CASES = [
    (8, 16), (8, 32), (8, 64), (16, 32), (16, 64), (32, 64),
]


@pytest.mark.parametrize("src_w,dst_w", ZEXT_CASES,
                         ids=[f"u{s}_u{d}" for s, d in ZEXT_CASES])
def test_zext(index, func_resolver, global_resolver, src_w, dst_w):
    fname = f"symbolic_test_zext_u{src_w}_u{dst_w}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in uint_unary_test_inputs(src_w):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.bv_zext(a, src_w, dst_w)
        assert verify_int(result, expected, dst_w), \
            f"{fname}({a}): 0x{int(result) & ((1<<dst_w)-1):x} != " \
            f"0x{expected & ((1<<dst_w)-1):x}"


# ===================================================================
# Casts -- truncation
# ===================================================================

TRUNC_CASES = [
    (16, 8), (32, 8), (64, 8), (32, 16), (64, 16), (64, 32),
]


@pytest.mark.parametrize("src_w,dst_w", TRUNC_CASES,
                         ids=[f"i{s}_i{d}" for s, d in TRUNC_CASES])
def test_trunc(index, func_resolver, global_resolver, src_w, dst_w):
    fname = f"symbolic_test_trunc_i{src_w}_i{dst_w}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in unary_test_inputs(src_w):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.bv_trunc(a, src_w, dst_w)
        assert verify_int(result, expected, dst_w), \
            f"{fname}({a}): 0x{int(result) & ((1<<dst_w)-1):x} != " \
            f"0x{expected & ((1<<dst_w)-1):x}"


# ===================================================================
# Casts -- int to float, float to int, float to float
# ===================================================================

def test_si_to_fp(index, func_resolver, global_resolver):
    """Signed int -> float conversions."""
    cases = [
        ("symbolic_test_si_to_fp_i8_f32",  8, 32),
        ("symbolic_test_si_to_fp_i8_f64",  8, 64),
        ("symbolic_test_si_to_fp_i16_f32", 16, 32),
        ("symbolic_test_si_to_fp_i16_f64", 16, 64),
        ("symbolic_test_si_to_fp_i32_f32", 32, 32),
        ("symbolic_test_si_to_fp_i32_f64", 32, 64),
        ("symbolic_test_si_to_fp_i64_f32", 64, 32),
        ("symbolic_test_si_to_fp_i64_f64", 64, 64),
    ]
    for fname, src_w, dst_w in cases:
        ir = find_ir_function(index, fname)
        if ir is None:
            continue
        for a in unary_test_inputs(src_w):
            result = run_ir_function(ir, [a], func_resolver, global_resolver)
            expected = float(a)
            assert verify_float(result, expected, dst_w), \
                f"{fname}({a}): {result} != {expected}"


def test_ui_to_fp(index, func_resolver, global_resolver):
    """Unsigned int -> float conversions."""
    cases = [
        ("symbolic_test_ui_to_fp_u8_f32",  8, 32),
        ("symbolic_test_ui_to_fp_u8_f64",  8, 64),
        ("symbolic_test_ui_to_fp_u16_f32", 16, 32),
        ("symbolic_test_ui_to_fp_u16_f64", 16, 64),
        ("symbolic_test_ui_to_fp_u32_f32", 32, 32),
        ("symbolic_test_ui_to_fp_u32_f64", 32, 64),
        ("symbolic_test_ui_to_fp_u64_f32", 64, 32),
        ("symbolic_test_ui_to_fp_u64_f64", 64, 64),
    ]
    for fname, src_w, dst_w in cases:
        ir = find_ir_function(index, fname)
        if ir is None:
            continue
        for a in uint_unary_test_inputs(src_w):
            result = run_ir_function(ir, [a], func_resolver, global_resolver)
            expected = float(a)
            assert verify_float(result, expected, dst_w), \
                f"{fname}({a}): {result} != {expected}"


def test_fp_to_si(index, func_resolver, global_resolver):
    """Float -> signed int conversions."""
    safe_values = [0.0, 1.0, -1.0, 42.0, -42.0, 0.5, -0.5, 127.0, -128.0,
                   100.7, -100.3]
    cases = [
        ("symbolic_test_fp_to_si_f32_i8",  8),
        ("symbolic_test_fp_to_si_f32_i16", 16),
        ("symbolic_test_fp_to_si_f32_i32", 32),
        ("symbolic_test_fp_to_si_f32_i64", 64),
        ("symbolic_test_fp_to_si_f64_i8",  8),
        ("symbolic_test_fp_to_si_f64_i16", 16),
        ("symbolic_test_fp_to_si_f64_i32", 32),
        ("symbolic_test_fp_to_si_f64_i64", 64),
    ]
    for fname, dst_w in cases:
        ir = find_ir_function(index, fname)
        if ir is None:
            continue
        half = 1 << (dst_w - 1)
        for a in safe_values:
            iv = int(a)
            if iv < -half or iv >= half:
                continue
            result = run_ir_function(ir, [a], func_resolver, global_resolver)
            expected = int(a)
            assert verify_int(result, expected, dst_w), \
                f"{fname}({a}): {result} != {expected}"


def test_fp_to_ui(index, func_resolver, global_resolver):
    """Float -> unsigned int conversions."""
    safe_values = [0.0, 1.0, 42.0, 0.5, 127.0, 200.0, 100.7]
    cases = [
        ("symbolic_test_fp_to_ui_f32_u8",  8),
        ("symbolic_test_fp_to_ui_f32_u16", 16),
        ("symbolic_test_fp_to_ui_f32_u32", 32),
        ("symbolic_test_fp_to_ui_f32_u64", 64),
        ("symbolic_test_fp_to_ui_f64_u8",  8),
        ("symbolic_test_fp_to_ui_f64_u16", 16),
        ("symbolic_test_fp_to_ui_f64_u32", 32),
        ("symbolic_test_fp_to_ui_f64_u64", 64),
    ]
    for fname, dst_w in cases:
        ir = find_ir_function(index, fname)
        if ir is None:
            continue
        mx = (1 << dst_w) - 1
        for a in safe_values:
            iv = int(a)
            if iv < 0 or iv > mx:
                continue
            result = run_ir_function(ir, [a], func_resolver, global_resolver)
            expected = int(a)
            assert verify_int(result, expected, dst_w), \
                f"{fname}({a}): {result} != {expected}"


def test_fptrunc(index, func_resolver, global_resolver):
    fname = "symbolic_test_fptrunc_f64_f32"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in float_unary_inputs(64):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = _f32_narrow(a)
        assert verify_float(result, expected, 32), \
            f"{fname}({a}): {result} != {expected}"


def test_fpext(index, func_resolver, global_resolver):
    fname = "symbolic_test_fpext_f32_f64"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in float_unary_inputs(32):
        f32 = struct.unpack('<f', struct.pack('<f', a))[0]
        result = run_ir_function(ir, [f32], func_resolver, global_resolver)
        assert verify_float(result, float(f32), 64), \
            f"{fname}({f32}): {result} != {float(f32)}"


def test_identity(index, func_resolver, global_resolver):
    fname = "symbolic_test_identity_i32"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in unary_test_inputs(32):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        assert verify_int(result, a, 32), \
            f"{fname}({a}): {result} != {a}"


# ===================================================================
# Logical
# ===================================================================

def test_logical_and(index, func_resolver, global_resolver):
    fname = "symbolic_test_logical_and"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a, b in int_test_inputs(32):
        result = run_ir_function(ir, [a, b], func_resolver, global_resolver)
        expected = z3_oracle.logical_and(a, b)
        assert int(result) == expected, \
            f"{fname}({a}, {b}): {result} != {expected}"


def test_logical_or(index, func_resolver, global_resolver):
    fname = "symbolic_test_logical_or"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a, b in int_test_inputs(32):
        result = run_ir_function(ir, [a, b], func_resolver, global_resolver)
        expected = z3_oracle.logical_or(a, b)
        assert int(result) == expected, \
            f"{fname}({a}, {b}): {result} != {expected}"


def test_select(index, func_resolver, global_resolver):
    fname = "symbolic_test_select_i32"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    cases = [(0, 10, 20), (1, 10, 20), (-1, 10, 20),
             (0, 0, 0), (42, -5, 5), (0, -5, 5)]
    for cond, a, b in cases:
        result = run_ir_function(ir, [cond, a, b],
                                 func_resolver, global_resolver)
        expected = z3_oracle.select(cond, a, b)
        assert verify_int(result, expected, 32), \
            f"{fname}({cond}, {a}, {b}): {result} != {expected}"


# ===================================================================
# Bitwise intrinsics
# ===================================================================

@pytest.mark.parametrize("width", [16, 32, 64])
def test_bswap(index, func_resolver, global_resolver, width):
    fname = f"symbolic_test_bswap_{width}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in uint_unary_test_inputs(width):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.bswap(a, width)
        assert verify_int(result, expected, width), \
            f"{fname}({a}): 0x{int(result)&((1<<width)-1):x} != " \
            f"0x{expected:x}"


@pytest.mark.parametrize("width", WIDTHS)
def test_popcount(index, func_resolver, global_resolver, width):
    fname = f"symbolic_test_popcount_{width}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in uint_unary_test_inputs(width):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.popcount(a, width)
        assert int(result) == expected, \
            f"{fname}({a}): {result} != {expected}"


@pytest.mark.parametrize("width", WIDTHS)
def test_clz(index, func_resolver, global_resolver, width):
    fname = f"symbolic_test_clz_{width}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in uint_unary_test_inputs(width):
        if (a & ((1 << width) - 1)) == 0:
            continue  # clz undefined for 0
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.clz(a, width)
        assert int(result) == expected, \
            f"{fname}({a}): {result} != {expected}"


@pytest.mark.parametrize("width", [32, 64])
def test_ctz(index, func_resolver, global_resolver, width):
    fname = f"symbolic_test_ctz_{width}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in uint_unary_test_inputs(width):
        if (a & ((1 << width) - 1)) == 0:
            continue  # ctz undefined for 0
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.ctz(a, width)
        assert int(result) == expected, \
            f"{fname}({a}): {result} != {expected}"


@pytest.mark.parametrize("width", [32, 64])
def test_ffs(index, func_resolver, global_resolver, width):
    fname = f"symbolic_test_ffs_{width}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in uint_unary_test_inputs(width):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.ffs(a, width)
        assert int(result) == expected, \
            f"{fname}({a}): {result} != {expected}"


@pytest.mark.parametrize("width", [32, 64])
def test_parity(index, func_resolver, global_resolver, width):
    fname = f"symbolic_test_parity_{width}"
    ir = find_ir_function(index, fname)
    if ir is None:
        pytest.skip(f"{fname} not in index")
    for a in uint_unary_test_inputs(width):
        result = run_ir_function(ir, [a], func_resolver, global_resolver)
        expected = z3_oracle.parity(a, width)
        assert int(result) == expected, \
            f"{fname}({a}): {result} != {expected}"


@pytest.mark.parametrize("width", [32, 64])
def test_rotl(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_rotl_{}", z3_oracle.rotl,
                shift_test_inputs(width))


@pytest.mark.parametrize("width", [32, 64])
def test_rotr(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_rotr_{}", z3_oracle.rotr,
                shift_test_inputs(width))


# ===================================================================
# Overflow-checked arithmetic
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_add_overflow(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_add_overflow_i{}",
                z3_oracle.add_overflow,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_sub_overflow(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_sub_overflow_i{}",
                z3_oracle.sub_overflow,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_mul_overflow(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_mul_overflow_i{}",
                z3_oracle.mul_overflow,
                int_test_inputs(width))


# ===================================================================
# Atomic RMW
# ===================================================================

@pytest.mark.parametrize("width", WIDTHS)
def test_atomic_add(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_atomic_add_i{}",
                z3_oracle.atomic_add,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_atomic_sub(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_atomic_sub_i{}",
                z3_oracle.atomic_sub,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_atomic_and(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_atomic_and_i{}",
                z3_oracle.atomic_and,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_atomic_or(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_atomic_or_i{}",
                z3_oracle.atomic_or,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_atomic_xor(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_atomic_xor_i{}",
                z3_oracle.atomic_xor,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_atomic_nand(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_atomic_nand_i{}",
                z3_oracle.atomic_nand,
                int_test_inputs(width))


@pytest.mark.parametrize("width", WIDTHS)
def test_atomic_xchg(index, func_resolver, global_resolver, width):
    _run_binary(index, func_resolver, global_resolver, width,
                "symbolic_test_atomic_xchg_i{}",
                z3_oracle.atomic_xchg,
                int_test_inputs(width))


# ===================================================================
# z3 universal proofs (sanity checks on z3 itself)
# ===================================================================

def _z3_prove(claim):
    s = z3.Solver()
    s.add(z3.Not(claim))
    result = s.check()
    if result == z3.sat:
        raise AssertionError(f"z3 counterexample: {s.model()}")
    assert result == z3.unsat


@pytest.mark.parametrize("width", WIDTHS)
def test_z3_add_commutative(width):
    a, b = z3.BitVecs("a b", width)
    _z3_prove(a + b == b + a)


@pytest.mark.parametrize("width", WIDTHS)
def test_z3_sub_negation(width):
    a, b = z3.BitVecs("a b", width)
    _z3_prove(a - b == a + (-b))


@pytest.mark.parametrize("width", WIDTHS)
def test_z3_and_idempotent(width):
    a = z3.BitVec("a", width)
    _z3_prove((a & a) == a)
