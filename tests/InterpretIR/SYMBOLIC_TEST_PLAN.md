# Comprehensive Symbolic Executor Testing

## Context

The IR interpreter has a symbolic execution path (`sym_init_state`/`sym_step`) that delegates value operations to a Python policy. Currently, values flow through C++ as the `Value` variant type (int64/pointer/null/undef). z3 expressions cannot flow through the interpreter directly — they would hit `python_to_value` and become `Undefined`. 

The testing strategy is **concrete differential testing**: for each opcode, run concrete inputs through the interpreter, then verify each result against z3's evaluation of the same operation. For 8-bit operations (65,536 pairs), test exhaustively. For wider types, use z3-generated edge cases plus random sampling.

This proves that the interpreter's concrete semantics are bit-exact matches for z3's bitvector semantics — the foundation required before any symbolic value can be trusted.

## Architecture

```
tests/InterpretIR/
├── symbolic_test_arith.c          # Signed arithmetic (ADD/SUB/MUL/DIV/REM) x {8,16,32,64}
├── symbolic_test_unsigned_arith.c # Unsigned arithmetic (UDIV/UREM) x {8,16,32,64}
├── symbolic_test_bitwise.c        # Bitwise (AND/OR/XOR) x {8,16,32,64}
├── symbolic_test_shifts.c         # Shifts (SHL/SHR/USHR) x {8,16,32,64}
├── symbolic_test_unary.c          # Unary (NEG/BIT_NOT/ABS/LOGICAL_NOT) x {8,16,32,64}
├── symbolic_test_cmp_signed.c     # Signed comparisons (EQ/NE/LT/LE/GT/GE) x {8,16,32,64}
├── symbolic_test_cmp_unsigned.c   # Unsigned comparisons (UCMP_LT/LE/GT/GE) x {8,16,32,64}
├── symbolic_test_float_arith.c    # Float arithmetic (FADD/FSUB/FMUL/FDIV/FREM/FNEG) x {32,64}
├── symbolic_test_float_cmp.c      # Float comparisons (FCMP_EQ/NE/LT/LE/GT/GE) x {32,64}
├── symbolic_test_casts.c          # All 58 CastOp variants
├── symbolic_test_logical.c        # LOGICAL_AND, LOGICAL_OR, SELECT
├── symbolic_test_bitwise_intrinsics.c  # BSWAP/POPCOUNT/CLZ/CTZ/FFS/PARITY/ROTL/ROTR
├── symbolic_test_overflow.c       # ADD_OVERFLOW/SUB_OVERFLOW/MUL_OVERFLOW x {8,16,32,64}
├── symbolic_test_pointers.c       # PTR_ADD, PTR_DIFF, GEP_FIELD
├── symbolic_test_atomic_rmw.c     # ATOMIC_ADD/SUB/AND/OR/XOR/NAND/EXCHANGE x {8,16,32,64}
│
├── test_symbolic_harness.py       # Pytest-based harness
├── conftest.py                    # Fixtures: index, func lookup, interpreter driver
└── z3_oracle.py                   # z3-based oracle for each opcode family
```

After creating C files, rebuild the mx-index.db:
```
mx-index --db tests/InterpretIR/mx-index.db tests/InterpretIR/compile_commands.json
```

## C Test Function Design

### Pattern

Every C function:
- Named `symbolic_test_<op>_<type>` (e.g., `symbolic_test_add_i32`)
- Takes typed parameters matching the operation width
- Performs exactly ONE IR operation (the target opcode)
- Returns the result in a type that preserves the full width

```c
// symbolic_test_arith.c
#include <stdint.h>

// --- ADD ---
int8_t  symbolic_test_add_i8 (int8_t a,  int8_t b)  { return a + b; }
int16_t symbolic_test_add_i16(int16_t a, int16_t b) { return a + b; }
int32_t symbolic_test_add_i32(int32_t a, int32_t b) { return a + b; }
int64_t symbolic_test_add_i64(int64_t a, int64_t b) { return a + b; }
```

The compiler emits width-specific opcodes (ADD_8, ADD_16, ADD_32, ADD_64) because the types are explicit.

### File 1: `symbolic_test_arith.c` — Signed Integer Arithmetic

**Functions (20 total: 5 ops x 4 widths):**
| Function | Opcode | z3 equivalent |
|---|---|---|
| `symbolic_test_add_i{8,16,32,64}(a, b)` | ADD_{8,16,32,64} | `bvadd(a, b)` |
| `symbolic_test_sub_i{8,16,32,64}(a, b)` | SUB_{8,16,32,64} | `bvsub(a, b)` |
| `symbolic_test_mul_i{8,16,32,64}(a, b)` | MUL_{8,16,32,64} | `bvmul(a, b)` |
| `symbolic_test_div_i{8,16,32,64}(a, b)` | DIV_{8,16,32,64} | `bvsdiv(a, b)` (b!=0) |
| `symbolic_test_rem_i{8,16,32,64}(a, b)` | REM_{8,16,32,64} | `bvsrem(a, b)` (b!=0) |

### File 2: `symbolic_test_unsigned_arith.c` — Unsigned Integer Arithmetic

**Functions (8 total: 2 ops x 4 widths):**
| Function | Opcode | z3 equivalent |
|---|---|---|
| `symbolic_test_udiv_u{8,16,32,64}(a, b)` | UDIV_{8,16,32,64} | `bvudiv(a, b)` (b!=0) |
| `symbolic_test_urem_u{8,16,32,64}(a, b)` | UREM_{8,16,32,64} | `bvurem(a, b)` (b!=0) |

### File 3: `symbolic_test_bitwise.c` — Bitwise Operations

**Functions (12 total: 3 ops x 4 widths):**
| Function | Opcode | z3 equivalent |
|---|---|---|
| `symbolic_test_and_u{8,16,32,64}(a, b)` | BIT_AND_{8,16,32,64} | `a & b` |
| `symbolic_test_or_u{8,16,32,64}(a, b)` | BIT_OR_{8,16,32,64} | `a \| b` |
| `symbolic_test_xor_u{8,16,32,64}(a, b)` | BIT_XOR_{8,16,32,64} | `a ^ b` |

### File 4: `symbolic_test_shifts.c` — Shift Operations

**Functions (12 total: 3 ops x 4 widths):**
| Function | Opcode | z3 equivalent |
|---|---|---|
| `symbolic_test_shl_u{8,16,32,64}(a, b)` | SHL_{8,16,32,64} | `bvshl(a, b & mask)` |
| `symbolic_test_shr_i{8,16,32,64}(a, b)` | SHR_{8,16,32,64} | `bvashr(a, b & mask)` |
| `symbolic_test_ushr_u{8,16,32,64}(a, b)` | USHR_{8,16,32,64} | `bvlshr(a, b & mask)` |

Note: The interpreter masks shift amounts. `mask = {7, 15, 31, 63}` for widths {8, 16, 32, 64}. z3 oracle must apply the same mask.

### File 5: `symbolic_test_unary.c` — Unary Operations

**Functions (16 total: 4 ops x 4 widths):**
| Function | Opcode | z3 equivalent |
|---|---|---|
| `symbolic_test_neg_i{8,16,32,64}(a)` | NEG_{8,16,32,64} | `bvneg(a)` |
| `symbolic_test_bitnot_u{8,16,32,64}(a)` | BIT_NOT_{8,16,32,64} | `~a` |
| `symbolic_test_abs_i{8,16,32,64}(a)` | ABS_{8,16,32,64} | `If(a < 0, -a, a)` |
| `symbolic_test_lognot_i32(a)` | LOGICAL_NOT | `If(a != 0, 0, 1)` (one width sufficient) |

### File 6: `symbolic_test_cmp_signed.c` — Signed Comparisons

**Functions (24 total: 6 ops x 4 widths):**
| Function | Opcode | z3 equivalent |
|---|---|---|
| `symbolic_test_eq_i{8,16,32,64}(a, b)` | CMP_EQ_{8,16,32,64} | `If(a == b, 1, 0)` |
| `symbolic_test_ne_i{8,16,32,64}(a, b)` | CMP_NE_{8,16,32,64} | `If(a != b, 1, 0)` |
| `symbolic_test_lt_i{8,16,32,64}(a, b)` | CMP_LT_{8,16,32,64} | `If(bvslt(a, b), 1, 0)` |
| `symbolic_test_le_i{8,16,32,64}(a, b)` | CMP_LE_{8,16,32,64} | `If(bvsle(a, b), 1, 0)` |
| `symbolic_test_gt_i{8,16,32,64}(a, b)` | CMP_GT_{8,16,32,64} | `If(bvsgt(a, b), 1, 0)` |
| `symbolic_test_ge_i{8,16,32,64}(a, b)` | CMP_GE_{8,16,32,64} | `If(bvsge(a, b), 1, 0)` |

### File 7: `symbolic_test_cmp_unsigned.c` — Unsigned Comparisons

**Functions (16 total: 4 ops x 4 widths):**
| Function | Opcode | z3 equivalent |
|---|---|---|
| `symbolic_test_ult_u{8,16,32,64}(a, b)` | UCMP_LT_{8,16,32,64} | `If(bvult(a, b), 1, 0)` |
| `symbolic_test_ule_u{8,16,32,64}(a, b)` | UCMP_LE_{8,16,32,64} | `If(bvule(a, b), 1, 0)` |
| `symbolic_test_ugt_u{8,16,32,64}(a, b)` | UCMP_GT_{8,16,32,64} | `If(bvugt(a, b), 1, 0)` |
| `symbolic_test_uge_u{8,16,32,64}(a, b)` | UCMP_GE_{8,16,32,64} | `If(bvuge(a, b), 1, 0)` |

### File 8: `symbolic_test_float_arith.c` — Float Arithmetic

**Functions (12 total: 6 ops x 2 widths):**
| Function | Opcode | Verification |
|---|---|---|
| `symbolic_test_fadd_f{32,64}(a, b)` | FADD_{32,64} | IEEE 754 addition |
| `symbolic_test_fsub_f{32,64}(a, b)` | FSUB_{32,64} | IEEE 754 subtraction |
| `symbolic_test_fmul_f{32,64}(a, b)` | FMUL_{32,64} | IEEE 754 multiplication |
| `symbolic_test_fdiv_f{32,64}(a, b)` | FDIV_{32,64} | IEEE 754 division |
| `symbolic_test_frem_f{32,64}(a, b)` | FREM_{32,64} | `fmod(a, b)` |
| `symbolic_test_fneg_f{32,64}(a)` | FNEG_{32,64} | `-a` |

Note: Float verification uses `z3.FPVal`/`z3.fpAdd` etc. or direct Python `struct` comparison for bit-exact checks.

### File 9: `symbolic_test_float_cmp.c` — Float Comparisons

**Functions (12 total: 6 ops x 2 widths):**
| Function | Opcode |
|---|---|
| `symbolic_test_fcmp_eq_f{32,64}(a, b)` | FCMP_EQ_{32,64} |
| `symbolic_test_fcmp_ne_f{32,64}(a, b)` | FCMP_NE_{32,64} |
| `symbolic_test_fcmp_lt_f{32,64}(a, b)` | FCMP_LT_{32,64} |
| `symbolic_test_fcmp_le_f{32,64}(a, b)` | FCMP_LE_{32,64} |
| `symbolic_test_fcmp_gt_f{32,64}(a, b)` | FCMP_GT_{32,64} |
| `symbolic_test_fcmp_ge_f{32,64}(a, b)` | FCMP_GE_{32,64} |

### File 10: `symbolic_test_casts.c` — All Cast Operations

**Functions (58 total — one per CastOp):**

Sign extension (6):
```c
int16_t symbolic_test_sext_i8_i16(int8_t a)   { return a; }
int32_t symbolic_test_sext_i8_i32(int8_t a)   { return a; }
int64_t symbolic_test_sext_i8_i64(int8_t a)   { return a; }
int32_t symbolic_test_sext_i16_i32(int16_t a) { return a; }
int64_t symbolic_test_sext_i16_i64(int16_t a) { return a; }
int64_t symbolic_test_sext_i32_i64(int32_t a) { return a; }
```

Zero extension (6):
```c
uint16_t symbolic_test_zext_u8_u16(uint8_t a)   { return a; }
// ... etc
```

Truncation (6):
```c
int8_t  symbolic_test_trunc_i16_i8(int16_t a)  { return (int8_t)a; }
// ... etc
```

Float conversions (26): int<->float, float<->float variants.

Pointer conversions (4): ptr<->int via casts.

Identity + bitcast (2).

### File 11: `symbolic_test_logical.c` — Logical Operations and SELECT

**Functions (3 total):**
```c
int symbolic_test_logical_and(int a, int b) { return a && b; }
int symbolic_test_logical_or(int a, int b)  { return a || b; }
int symbolic_test_select_i32(int cond, int a, int b) { return cond ? a : b; }
```

### File 12: `symbolic_test_bitwise_intrinsics.c` — Bitwise Intrinsics

**Functions (26 total across applicable widths):**
| Function | BitwiseOp | Widths |
|---|---|---|
| `symbolic_test_bswap_{16,32,64}(a)` | BSWAP | 16,32,64 |
| `symbolic_test_popcount_{8,16,32,64}(a)` | POPCOUNT | 8,16,32,64 |
| `symbolic_test_clz_{8,16,32,64}(a)` | CLZ | 8,16,32,64 |
| `symbolic_test_ctz_{32,64}(a)` | CTZ | 32,64 |
| `symbolic_test_ffs_{32,64}(a)` | FFS | 32,64 |
| `symbolic_test_parity_{32,64}(a)` | PARITY | 32,64 |
| `symbolic_test_rotl_{32,64}(a, b)` | ROTL | 32,64 |
| `symbolic_test_rotr_{32,64}(a, b)` | ROTR | 32,64 |

Uses `__builtin_bswap*`, `__builtin_popcount*`, `__builtin_clz*`, etc.

### File 13: `symbolic_test_overflow.c` — Overflow-Checked Arithmetic

**Functions (12 total: 3 ops x 4 widths):**
These use `__builtin_add_overflow` etc. to produce ADD_OVERFLOW/SUB_OVERFLOW/MUL_OVERFLOW opcodes. The function returns 1 if overflow occurred, 0 if not, and stores the result through a pointer.

### File 14: `symbolic_test_pointers.c` — Pointer Arithmetic

**Functions (4 total):**
```c
int symbolic_test_ptr_add(int *base, int index) { return base[index]; }
long symbolic_test_ptr_diff(int *p, int *q)     { return p - q; }
int symbolic_test_gep_field(struct S *s)        { return s->y; }
int symbolic_test_ptr_offset(int *base)         { return *(base + 1); }
```

### File 15: `symbolic_test_atomic_rmw.c` — Atomic RMW Operations

**Functions (28 total: 7 ops x 4 widths):**
Uses `_Atomic` types with `__atomic_fetch_add`, etc. to produce ATOMIC_ADD/SUB/AND/OR/XOR/NAND/EXCHANGE opcodes.

## Python Test Harness Design

### `conftest.py` — Shared Fixtures

```python
import pytest
import multiplier as mx

@pytest.fixture(scope="session")
def index():
    return mx.Index.from_database("tests/InterpretIR/mx-index.db")

@pytest.fixture(scope="session")
def func_resolver(index):
    def resolve(eid):
        entity = mx.Entity.FROM(index, eid)
        if entity:
            fd = mx.ast.FunctionDecl.FROM(entity)
            if fd:
                return mx.ir.IRFunction.FROM(fd)
        return None
    return resolve

@pytest.fixture(scope="session")
def global_resolver(index):
    ...

def find_ir_function(index, name):
    """Find IRFunction by name."""
    for frag in mx.Fragment.IN(index):
        for decl in mx.ast.Decl.IN(frag):
            fd = mx.ast.FunctionDecl.FROM(decl)
            if fd and str(fd.name) == name:
                ir = mx.ir.IRFunction.FROM(fd)
                if ir:
                    return ir
    return None

def run_function(index, name, args, func_resolver, global_resolver,
                 max_steps=100000):
    """Run a symbolic_test_* function, return the integer result."""
    interp = mx.ir.interpret
    ir_func = find_ir_function(index, name)
    assert ir_func is not None, f"Function {name} not found"
    mem = interp.ConcreteMemory()
    state = interp.InterpreterState()
    class PassthroughPolicy:
        pass
    interp.sym_init_state(state, mem, PassthroughPolicy(), ir_func,
                          list(args), func_resolver, global_resolver)
    result = interp.sym_step(state, mem, PassthroughPolicy(), max_steps,
                             func_resolver, global_resolver)
    res = result.get("result")
    assert res is not None and res[0] == "completed", f"{name}: {res}"
    return res[1]
```

### `z3_oracle.py` — z3 Reference Implementations

Provides one function per opcode family. Each takes concrete Python ints, builds z3 bitvectors at the target width, performs the z3 operation, and returns the simplified result as a Python int.

```python
import z3

def bv_add(a, b, w):
    return z3.simplify(z3.BitVecVal(a, w) + z3.BitVecVal(b, w)).as_signed_long()

def bv_sub(a, b, w):
    return z3.simplify(z3.BitVecVal(a, w) - z3.BitVecVal(b, w)).as_signed_long()

def bv_mul(a, b, w): ...
def bv_sdiv(a, b, w): ...    # NOTE: interpreter returns 0 for b==0
def bv_srem(a, b, w): ...    # NOTE: interpreter returns 0 for b==0
def bv_udiv(a, b, w): ...
def bv_urem(a, b, w): ...
def bv_and(a, b, w): ...
def bv_or(a, b, w): ...
def bv_xor(a, b, w): ...
def bv_shl(a, b, w):  ...    # masks shift by {7,15,31,63}
def bv_ashr(a, b, w): ...    # masks shift
def bv_lshr(a, b, w): ...    # masks shift
def bv_neg(a, w): ...
def bv_not(a, w): ...
def bv_abs(a, w): ...         # If(a < 0, -a, a) in signed bitvector
def bv_sext(a, src_w, dst_w): ...
def bv_zext(a, src_w, dst_w): ...
def bv_trunc(a, src_w, dst_w): ...
# ... all comparisons, etc.
```

### `test_symbolic_harness.py` — Parameterized Tests

```python
import pytest
import z3
from conftest import run_function
from z3_oracle import *

WIDTHS = [8, 16, 32, 64]

def int_test_inputs(width):
    """Exhaustive for 8-bit, edge+random for wider."""
    if width == 8:
        return [(a - 128, b - 128) for a in range(256) for b in range(256)]
    half = 1 << (width - 1)
    edges = [0, 1, -1, 2, -2, half - 1, -half, half - 2, -(half - 1), 42, -42]
    pairs = [(a, b) for a in edges for b in edges]
    import random; rng = random.Random(42)
    pairs += [(rng.randint(-half, half-1), rng.randint(-half, half-1))
              for _ in range(500)]
    return pairs

def uint_test_inputs(width):
    """Unsigned variant."""
    if width == 8:
        return [(a, b) for a in range(256) for b in range(256)]
    mx = (1 << width) - 1
    edges = [0, 1, 2, mx, mx - 1, mx // 2, mx // 2 + 1, 42, 255]
    pairs = [(a, b) for a in edges for b in edges]
    import random; rng = random.Random(42)
    pairs += [(rng.randint(0, mx), rng.randint(0, mx)) for _ in range(500)]
    return pairs

def sign_extend(val, width):
    """Sign-extend a width-bit value to Python int."""
    mask = (1 << width) - 1
    val &= mask
    if val >= (1 << (width - 1)):
        val -= (1 << width)
    return val

def to_unsigned(val, width):
    """Convert signed Python int to unsigned for the given width."""
    mask = (1 << width) - 1
    return val & mask

# ---------- Signed arithmetic ----------

@pytest.mark.parametrize("width", WIDTHS)
def test_add(index, func_resolver, global_resolver, width):
    for a, b in int_test_inputs(width):
        result = run_function(index, f"symbolic_test_add_i{width}",
                              [a, b], func_resolver, global_resolver)
        expected = bv_add(a, b, width)
        ir = sign_extend(result, width)
        ex = sign_extend(expected, width)
        assert ir == ex, f"add_i{width}({a}, {b}): got {ir}, expected {ex}"

@pytest.mark.parametrize("width", WIDTHS)
def test_sub(index, func_resolver, global_resolver, width):
    ...  # same pattern

# ... one function per opcode family ...

# ---------- z3 universal proofs ----------

@pytest.mark.parametrize("width", WIDTHS)
def test_z3_add_commutative(width):
    a, b = z3.BitVecs("a b", width)
    z3.prove(a + b == b + a)

@pytest.mark.parametrize("width", WIDTHS)
def test_z3_sub_negation(width):
    a, b = z3.BitVecs("a b", width)
    z3.prove(a - b == a + (-b))

@pytest.mark.parametrize("width", WIDTHS)
def test_z3_and_idempotent(width):
    a = z3.BitVec("a", width)
    z3.prove((a & a) == a)
```

## Input Generation Strategy

| Width | Binary ops | Unary ops | Strategy |
|-------|-----------|-----------|----------|
| 8-bit | 65,536 pairs | 256 values | Exhaustive |
| 16-bit | ~300 edge + 500 random | ~100 edge + 200 random | Edge + random |
| 32-bit | ~300 edge + 500 random | ~100 edge + 200 random | Edge + random |
| 64-bit | ~300 edge + 500 random | ~100 edge + 200 random | Edge + random |

Edge case values for signed width W:
```
0, 1, -1, 2, -2, MAX (2^(W-1)-1), MIN (-2^(W-1)), MAX-1, MIN+1, 42, -42
```

For unsigned: `0, 1, 2, MAX (2^W-1), MAX-1, MAX/2, MAX/2+1, 42, 255`.

For shifts: shift amount b from `{0, 1, W-1, W, W+1}` (tests mask behavior).

For div/rem: includes `b=0` to verify interpreter's zero-division behavior (returns 0).

## Verification Assertions

### Integer operations
```python
def verify_int(interp_result, expected, a, b, width, op_name):
    mask = (1 << width) - 1
    ir = interp_result & mask
    ex = expected & mask
    assert ir == ex, f"{op_name}({a}, {b}) at {width}-bit: 0x{ir:x} != 0x{ex:x}"
```

### Float operations
```python
import struct, math
def verify_float(interp_result, expected, width, op_name, a, b=None):
    if math.isnan(expected):
        assert math.isnan(interp_result), f"{op_name}: expected NaN"
        return
    fmt = '<f' if width == 32 else '<d'
    ir_bits = struct.pack(fmt, interp_result)
    ex_bits = struct.pack(fmt, expected)
    assert ir_bits == ex_bits, f"{op_name}: bit mismatch"
```

## Test Count Summary

| File | Ops | Widths | Functions | Approx cases |
|------|-----|--------|-----------|--------------|
| arith | 5 | 4 | 20 | 16K |
| unsigned_arith | 2 | 4 | 8 | 6.4K |
| bitwise | 3 | 4 | 12 | 9.6K |
| shifts | 3 | 4 | 12 | 9.6K |
| unary | 4 | 4 | 13+ | 3.9K |
| cmp_signed | 6 | 4 | 24 | 19.2K |
| cmp_unsigned | 4 | 4 | 16 | 12.8K |
| float_arith | 6 | 2 | 12 | 2.4K |
| float_cmp | 6 | 2 | 12 | 2.4K |
| casts | 58 | varies | 58 | 11.6K |
| logical | 3 | 1 | 3 | 600 |
| bitwise_intrinsics | 8 | varies | 26 | 5.2K |
| overflow | 3 | 4 | 12 | 9.6K |
| pointers | 4 | 1 | 4 | 200 |
| atomic_rmw | 7 | 4 | 28 | 5.6K |
| **Total** | | | **~260** | **~115K** |

## Execution

```bash
# From project root, after rebuilding mx-index.db:
cd tests/InterpretIR
PYTHONPATH=~/Build/multiplier/Debug/multiplier/lib/python3.14/site-packages \
    python3.14 -m pytest test_symbolic_harness.py -v --tb=short -x

# 8-bit exhaustive only:
python3.14 -m pytest test_symbolic_harness.py -v -k "width8"

# Specific opcode:
python3.14 -m pytest test_symbolic_harness.py -v -k "test_add"
```

## Critical Files

| File | Change |
|------|--------|
| `tests/InterpretIR/symbolic_test_arith.c` | New: 20 functions |
| `tests/InterpretIR/symbolic_test_unsigned_arith.c` | New: 8 functions |
| `tests/InterpretIR/symbolic_test_bitwise.c` | New: 12 functions |
| `tests/InterpretIR/symbolic_test_shifts.c` | New: 12 functions |
| `tests/InterpretIR/symbolic_test_unary.c` | New: 13+ functions |
| `tests/InterpretIR/symbolic_test_cmp_signed.c` | New: 24 functions |
| `tests/InterpretIR/symbolic_test_cmp_unsigned.c` | New: 16 functions |
| `tests/InterpretIR/symbolic_test_float_arith.c` | New: 12 functions |
| `tests/InterpretIR/symbolic_test_float_cmp.c` | New: 12 functions |
| `tests/InterpretIR/symbolic_test_casts.c` | New: 58 functions |
| `tests/InterpretIR/symbolic_test_logical.c` | New: 3 functions |
| `tests/InterpretIR/symbolic_test_bitwise_intrinsics.c` | New: 26 functions |
| `tests/InterpretIR/symbolic_test_overflow.c` | New: 12 functions |
| `tests/InterpretIR/symbolic_test_pointers.c` | New: 4 functions |
| `tests/InterpretIR/symbolic_test_atomic_rmw.c` | New: 28 functions |
| `tests/InterpretIR/conftest.py` | New: pytest fixtures + run_function helper |
| `tests/InterpretIR/z3_oracle.py` | New: z3 reference for every opcode |
| `tests/InterpretIR/test_symbolic_harness.py` | New: parameterized pytest tests |
| `tests/InterpretIR/compile_commands.json` | Update: add new .c files |
| `tests/InterpretIR/mx-index.db` | Rebuild after indexing new files |
