// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx::ir {

// Sub-opcodes for CONST. Stored in the int pool (int_pool[0]).
// Encodes both the type and width of the constant.
enum class ConstOp : uint8_t {
  INT8 = 0,
  INT16 = 1,
  INT32 = 2,
  INT64 = 3,
  UINT8 = 4,
  UINT16 = 5,
  UINT32 = 6,
  UINT64 = 7,
  FLOAT32 = 8,
  FLOAT64 = 9,
  FLOAT16 = 10,
  NULL_PTR = 11,
  INF32 = 12,
  INF64 = 13,
  NAN32 = 14,
  NAN64 = 15,
  WCHAR16 = 16,
  WCHAR32 = 17,
  BOOL = 18,
};

// Sub-opcodes for CAST. Stored in the int pool (int_pool[0]).
enum class CastOp : uint8_t {
  // Sign-extend
  SEXT_I8_I16 = 0,
  SEXT_I8_I32,
  SEXT_I8_I64,
  SEXT_I16_I32,
  SEXT_I16_I64,
  SEXT_I32_I64,

  // Zero-extend
  ZEXT_I8_I16,
  ZEXT_I8_I32,
  ZEXT_I8_I64,
  ZEXT_I16_I32,
  ZEXT_I16_I64,
  ZEXT_I32_I64,

  // Truncate
  TRUNC_I16_I8,
  TRUNC_I32_I8,
  TRUNC_I64_I8,
  TRUNC_I32_I16,
  TRUNC_I64_I16,
  TRUNC_I64_I32,

  // Float widening/narrowing
  F32_TO_F64,
  F64_TO_F32,

  // Signed int to float
  SI8_TO_F32,
  SI8_TO_F64,
  SI16_TO_F32,
  SI16_TO_F64,
  SI32_TO_F32,
  SI32_TO_F64,
  SI64_TO_F32,
  SI64_TO_F64,

  // Unsigned int to float
  UI8_TO_F32,
  UI8_TO_F64,
  UI16_TO_F32,
  UI16_TO_F64,
  UI32_TO_F32,
  UI32_TO_F64,
  UI64_TO_F32,
  UI64_TO_F64,

  // Float to signed int
  F32_TO_SI8,
  F32_TO_SI16,
  F32_TO_SI32,
  F32_TO_SI64,
  F64_TO_SI8,
  F64_TO_SI16,
  F64_TO_SI32,
  F64_TO_SI64,

  // Float to unsigned int
  F32_TO_UI8,
  F32_TO_UI16,
  F32_TO_UI32,
  F32_TO_UI64,
  F64_TO_UI8,
  F64_TO_UI16,
  F64_TO_UI32,
  F64_TO_UI64,

  // Pointer conversions
  PTR_TO_I32,
  PTR_TO_I64,
  I32_TO_PTR,
  I64_TO_PTR,

  // Bitcast (reinterpret bits, same size)
  BITCAST,

  // Identity (no-op, replaces COPY for implicit conversions)
  IDENTITY,
};

// CastOp classification helpers.
inline bool IsSignExtend(CastOp op) {
  return op >= CastOp::SEXT_I8_I16 && op <= CastOp::SEXT_I32_I64;
}

inline bool IsZeroExtend(CastOp op) {
  return op >= CastOp::ZEXT_I8_I16 && op <= CastOp::ZEXT_I32_I64;
}

inline bool IsTruncate(CastOp op) {
  return op >= CastOp::TRUNC_I16_I8 && op <= CastOp::TRUNC_I64_I32;
}

inline bool IsIntToFloat(CastOp op) {
  return op >= CastOp::SI8_TO_F32 && op <= CastOp::UI64_TO_F64;
}

inline bool IsFloatToInt(CastOp op) {
  return op >= CastOp::F32_TO_SI8 && op <= CastOp::F64_TO_UI64;
}

// Single unified opcode enum for all IR instruction types. The C++ class
// hierarchy on the read side is derived from this enum.
enum class OpCode : uint8_t {
  // Constant (sub-opcode in int_pool[0] selects ConstOp).
  CONST = 0,

  // Memory
  ALLOCA = 1,
  MEM = 2,             // Unified load/store (sub-opcode in int_pool[0] selects MemAccessOp).
  GEP_FIELD = 3,
  PTR_ADD = 4,         // pointer + index; op[0]=base, op[1]=index

  // Binary arithmetic/logic
  ADD = 5,
  SUB = 6,
  MUL = 7,
  DIV = 8,
  REM = 9,
  BIT_AND = 10,
  BIT_OR = 11,
  BIT_XOR = 12,
  SHL = 13,
  SHR = 14,
  LOGICAL_AND = 15,
  LOGICAL_OR = 16,
  PTR_DIFF = 17,

  // Comparison
  CMP_EQ = 18,
  CMP_NE = 19,
  CMP_LT = 20,
  CMP_LE = 21,
  CMP_GT = 22,
  CMP_GE = 23,

  // Unary
  NEG = 24,
  BIT_NOT = 25,
  LOGICAL_NOT = 26,

  // Cast (sub-opcode in int_pool[0] selects CastOp).
  CAST = 27,

  // Call
  CALL = 28,

  // Read-modify-write: atomically reads from address, applies an operation,
  // and writes back. operands = [address, rhs_operand0, rhs_operand1, ...].
  // The loaded value is the implicit LHS of the underlying op.
  // flags: bit 0 = returns new value (1) or old value (0, post-increment).
  // int_pool[0] = underlying opcode (ADD, SUB, PTR_ADD, SHL, etc.)
  // int_pool[1] = element size (for PTR_ADD only, 0 otherwise)
  READ_MODIFY_WRITE = 29,

  // Misc
  SELECT = 30,

  // Terminators
  COND_BRANCH = 31,
  SWITCH = 32,
  RET = 33,
  UNREACHABLE = 34,
  BREAK = 35,
  CONTINUE = 36,
  GOTO = 37,              // explicit goto label;
  IMPLICIT_GOTO = 38,     // structural CFG edge (e.g., end of if-then → merge)
  FALLTHROUGH = 39,       // explicit [[fallthrough]]
  IMPLICIT_FALLTHROUGH = 40, // implicit (no break at end of case)
  IMPLICIT_UNREACHABLE = 41, // structurally unreachable (patched empty block)

  // Variadic argument handling
  VA_PACK = 42,           // groups variadic args at call site; operands = the packed args
  VA_START = 43,          // binds va_list to function's variadic pack; op[0] = va_list
  VA_ARG = 44,            // reads next value from va_list; op[0] = va_list; typeEntityId = result type
  VA_COPY = 45,           // copies va_list; op[0] = dest, op[1] = src
  VA_END = 46,            // releases va_list; op[0] = va_list

  // Scope entry/exit markers (not terminators).
  ENTER_SCOPE = 47,        // marks scope entry; extra = IRStructureId of scope
  EXIT_SCOPE = 48,         // marks scope exit; extra = IRStructureId of scope

  // Unified memory/string operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see MemoryOp enum).
  MULTIMEM = 49,

  // Parameter read: reads the Nth function parameter.
  PARAM_READ = 50,

  // Address-of for globals and functions (external to the current frame).
  GLOBAL_PTR = 51,        // pointer to a global or static variable
  FUNC_PTR = 52,          // pointer to a function

  // Bitwise/intrinsic operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see BitwiseOp enum). op[0] = primary operand.
  BITWISE = 53,

  // Floating-point operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see FloatOp enum). op[0] = primary operand.
  FLOAT = 54,

  // Undefined/poison value. Represents a value that is architecturally
  // undefined (e.g., __builtin_clz(0)). An analyzer should flag any use.
  UNDEFINED = 55,

  // Dynamic stack allocation.
  DYNAMIC_ALLOCA = 56,     // op[0] = size. Returns pointer to stack allocation.

  // Frame/return address intrinsics.
  FRAME_PTR = 57,      // op[0] = level (CONST, usually 0). Returns frame ptr.
  RETURN_PTR = 58,     // op[0] = level (CONST, usually 0). Returns return addr.

  // Atomic operations.
  ATOMIC_CMPXCHG = 59,     // op[0] = target, op[1] = expected_ptr, op[2] = desired. Returns bool.

  // Overflow-checked arithmetic (only used as RMW underlying opcodes).
  // RMW returns bool (overflow flag), stores the arithmetic result.
  ADD_OVERFLOW = 60,
  SUB_OVERFLOW = 61,
  MUL_OVERFLOW = 62,

  // Atomic RMW underlying opcodes (only valid as RMW underlying ops).
  ATOMIC_ADD = 63,
  ATOMIC_SUB = 64,
  ATOMIC_AND = 65,
  ATOMIC_OR = 66,
  ATOMIC_XOR = 67,
  ATOMIC_NAND = 68,
  ATOMIC_EXCHANGE = 69,

  // Evaluate all operands, return the last one's value.
  // Used for comma operator (a, b) and similar "sequence point" patterns.
  LAST_VALUE = 70,

  // Unknown / unhandled expression
  UNKNOWN = 71,
};

// Returns the human-readable name of an opcode.
inline static const char *EnumerationName(OpCode) {
  return "OpCode";
}

const char *EnumeratorName(OpCode op) noexcept;

inline static constexpr unsigned NumEnumerators(OpCode) {
  return 72u;
}

// Sub-opcodes for MEM. Stored in the int pool (int_pool[0]).
// Encodes direction (load/store), atomicity, endianness, and access width.
enum class MemAccessOp : uint8_t {
  // Non-atomic loads (little-endian)
  LOAD_LE_8 = 0,   LOAD_LE_16 = 1,  LOAD_LE_32 = 2,  LOAD_LE_64 = 3,
  // Non-atomic loads (big-endian)
  LOAD_BE_8 = 4,   LOAD_BE_16 = 5,  LOAD_BE_32 = 6,  LOAD_BE_64 = 7,
  // Non-atomic stores (little-endian)
  STORE_LE_8 = 8,  STORE_LE_16 = 9, STORE_LE_32 = 10, STORE_LE_64 = 11,
  // Non-atomic stores (big-endian)
  STORE_BE_8 = 12, STORE_BE_16 = 13, STORE_BE_32 = 14, STORE_BE_64 = 15,
  // Atomic loads (little-endian)
  ATOMIC_LOAD_LE_8 = 16, ATOMIC_LOAD_LE_16 = 17, ATOMIC_LOAD_LE_32 = 18, ATOMIC_LOAD_LE_64 = 19,
  // Atomic loads (big-endian)
  ATOMIC_LOAD_BE_8 = 20, ATOMIC_LOAD_BE_16 = 21, ATOMIC_LOAD_BE_32 = 22, ATOMIC_LOAD_BE_64 = 23,
  // Atomic stores (little-endian)
  ATOMIC_STORE_LE_8 = 24, ATOMIC_STORE_LE_16 = 25, ATOMIC_STORE_LE_32 = 26, ATOMIC_STORE_LE_64 = 27,
  // Atomic stores (big-endian)
  ATOMIC_STORE_BE_8 = 28, ATOMIC_STORE_BE_16 = 29, ATOMIC_STORE_BE_32 = 30, ATOMIC_STORE_BE_64 = 31,
};

// MemAccessOp classification helpers.
inline bool IsLoad(MemAccessOp op) { return static_cast<uint8_t>(op) < 8; }
inline bool IsStore(MemAccessOp op) { auto v = static_cast<uint8_t>(op); return v >= 8 && v < 16; }
inline bool IsAtomicLoad(MemAccessOp op) { auto v = static_cast<uint8_t>(op); return v >= 16 && v < 24; }
inline bool IsAtomicStore(MemAccessOp op) { auto v = static_cast<uint8_t>(op); return v >= 24; }
inline bool IsAnyLoad(MemAccessOp op) { return IsLoad(op) || IsAtomicLoad(op); }
inline bool IsAnyStore(MemAccessOp op) { return IsStore(op) || IsAtomicStore(op); }
inline bool IsAtomic(MemAccessOp op) { return static_cast<uint8_t>(op) >= 16; }
inline bool IsBigEndian(MemAccessOp op) { return (static_cast<uint8_t>(op) % 8) >= 4; }
inline unsigned AccessSize(MemAccessOp op) {
  switch (static_cast<uint8_t>(op) % 4) {
    case 0: return 1; case 1: return 2; case 2: return 4; case 3: return 8;
  }
  return 0;
}

// Sub-opcodes for BITWISE. Stored in the int pool.
enum class BitwiseOp : uint8_t {
  // Byte swap.
  BSWAP16 = 0,            // Reverse bytes of 16-bit value.
  BSWAP32 = 1,            // Reverse bytes of 32-bit value.
  BSWAP64 = 2,            // Reverse bytes of 64-bit value.

  // Population count: number of set bits.
  POPCOUNT = 3,            // Result is defined for all inputs including 0.

  // Count leading zeros. UNDEFINED for input == 0.
  CLZ = 4,                 // __builtin_clz (32-bit), __builtin_clzl, __builtin_clzll
  // Count trailing zeros. UNDEFINED for input == 0.
  CTZ = 5,                 // __builtin_ctz, __builtin_ctzl, __builtin_ctzll

  // Find first set bit (1-indexed from LSB). Returns 0 for input == 0.
  FFS = 6,                 // __builtin_ffs, __builtin_ffsl, __builtin_ffsll

  // Parity: 1 if odd number of set bits, 0 if even.
  PARITY = 7,              // __builtin_parity

  // Bit rotation.
  ROTL = 8,                // Rotate left. op[0] = value, op[1] = amount.
  ROTR = 9,                // Rotate right. op[0] = value, op[1] = amount.

  // Absolute value (integer).
  ABS = 10,                // __builtin_abs. UNDEFINED for INT_MIN (signed overflow).

  // Expect (optimization hint, semantically identity on op[0]).
  EXPECT = 11,             // __builtin_expect(x, v) → x

  // Assume (optimization hint, no-op).
  ASSUME = 12,             // __builtin_assume(x)
};

// Sub-opcodes for MULTIMEM. Stored in the int pool.
enum class MemoryOp : uint8_t {
  // Memory operations.
  MEMSET = 0,      // op[0]=dest, op[1]=byte, op[2]=size. Returns dest.
  MEMCPY = 1,      // op[0]=dest, op[1]=src, op[2]=size. UB on overlap. Returns dest.
  MEMMOVE = 2,     // op[0]=dest, op[1]=src, op[2]=size. Safe for overlap. Returns dest.
  MEMCMP = 3,      // op[0]=s1, op[1]=s2, op[2]=size. Returns int (<0, 0, >0).
  MEMCHR = 4,      // op[0]=ptr, op[1]=byte, op[2]=size. Returns ptr or null.
  BZERO = 5,       // op[0]=dest, op[1]=size. Equivalent to memset(dest,0,size).

  // String operations. All operate on null-terminated strings.
  STRLEN = 6,      // op[0]=str. Returns length (not including null).
  STRNLEN = 7,     // op[0]=str, op[1]=maxlen. Returns min(strlen, maxlen).
  STRCMP = 8,       // op[0]=s1, op[1]=s2. Returns int (<0, 0, >0).
  STRNCMP = 9,     // op[0]=s1, op[1]=s2, op[2]=n. Compare at most n chars.
  STRCHR = 10,     // op[0]=str, op[1]=char. Returns ptr to first occurrence or null.
  STRRCHR = 11,    // op[0]=str, op[1]=char. Returns ptr to last occurrence or null.
  STRSTR = 12,     // op[0]=haystack, op[1]=needle. Returns ptr or null.
  STRCPY = 13,     // op[0]=dest, op[1]=src. Returns dest. UB if overlap.
  STRNCPY = 14,    // op[0]=dest, op[1]=src, op[2]=n. Returns dest.
  STRCAT = 15,     // op[0]=dest, op[1]=src. Returns dest.
  STRNCAT = 16,    // op[0]=dest, op[1]=src, op[2]=n. Returns dest.
  STPCPY = 17,     // op[0]=dest, op[1]=src. Returns pointer to null terminator.
  STPNCPY = 18,    // op[0]=dest, op[1]=src, op[2]=n. Returns dest+written or dest+n.

  // String-to-number conversions. Size-specific to avoid platform ambiguity.
  // "Simple" variants: op[0]=str. Returns the number.
  // "Full" variants: op[0]=str, op[1]=endptr, op[2]=base. Returns the number.
  STRTOI32 = 19,   // String → signed 32-bit. (atoi, strtol on 32-bit long)
  STRTOI64 = 20,   // String → signed 64-bit. (atoll, strtol on 64-bit long)
  STRTOU32 = 21,   // String → unsigned 32-bit. (strtoul on 32-bit long)
  STRTOU64 = 22,   // String → unsigned 64-bit. (strtoull, strtoul on 64-bit long)
  STRTOF32 = 23,   // String → float. (strtof)
  STRTOF64 = 24,   // String → double. (atof, strtod)

};

// Sub-opcodes for FLOAT. Stored in the int pool.
enum class FloatOp : uint8_t {
  ISNAN = 0,       // op[0]=x. Returns bool.
  ISINF = 1,       // op[0]=x. Returns bool.
  ISFINITE = 2,    // op[0]=x. Returns bool.
  FABS = 3,        // op[0]=x. Returns |x|.
  COPYSIGN = 4,    // op[0]=x, op[1]=y. Returns x with sign of y.
  FMIN = 5,        // op[0]=x, op[1]=y. Returns min.
  FMAX = 6,        // op[0]=x, op[1]=y. Returns max.
  CEIL = 7,        // op[0]=x. Returns ceil(x).
  FLOOR = 8,       // op[0]=x. Returns floor(x).
  ROUND = 9,       // op[0]=x. Returns round(x).
  TRUNC = 10,      // op[0]=x. Returns trunc(x).
  SQRT = 11,       // op[0]=x. Returns sqrt(x). UNDEFINED for negative.
  INF = 12,        // No operands. Returns +infinity.
  NAN_VAL = 13,    // No operands. Returns NaN.
  FLOAT_HUGE = 14, // No operands. Returns HUGE_VAL (+inf).

  // Trigonometric.
  SIN = 15,        // op[0]=x. Returns sin(x).
  COS = 16,        // op[0]=x. Returns cos(x).
  TAN = 17,        // op[0]=x. Returns tan(x).
  ASIN = 18,       // op[0]=x. Returns asin(x). UNDEFINED for |x|>1.
  ACOS = 19,       // op[0]=x. Returns acos(x). UNDEFINED for |x|>1.
  ATAN = 20,       // op[0]=x. Returns atan(x).
  ATAN2 = 21,      // op[0]=y, op[1]=x. Returns atan2(y,x).

  // Exponential/logarithmic.
  EXP = 22,        // op[0]=x. Returns e^x.
  EXP2 = 23,       // op[0]=x. Returns 2^x.
  LOG = 24,        // op[0]=x. Returns ln(x). UNDEFINED for x<=0.
  LOG2 = 25,       // op[0]=x. Returns log2(x). UNDEFINED for x<=0.
  LOG10 = 26,      // op[0]=x. Returns log10(x). UNDEFINED for x<=0.

  // Power/modular.
  POW = 27,        // op[0]=base, op[1]=exp. Returns base^exp.
  FMOD = 28,       // op[0]=x, op[1]=y. Returns fmod(x,y).
  REMAINDER = 29,  // op[0]=x, op[1]=y. Returns IEEE remainder.
  FMA = 30,        // op[0]=x, op[1]=y, op[2]=z. Returns x*y+z (fused).

  // Hyperbolic.
  SINH = 31,       // op[0]=x.
  COSH = 32,       // op[0]=x.
  TANH = 33,       // op[0]=x.

  // Other.
  HYPOT = 34,      // op[0]=x, op[1]=y. Returns sqrt(x^2+y^2).
  ERF = 35,        // op[0]=x. Error function.
  ERFC = 36,       // op[0]=x. Complementary error function.
  TGAMMA = 37,     // op[0]=x. Gamma function.
  LGAMMA = 38,     // op[0]=x. Log-gamma function.
  FDIM = 39,       // op[0]=x, op[1]=y. Returns max(x-y, 0).
  SIGNBIT = 40,    // op[0]=x. Returns bool (sign bit set).
};

// Classification helpers.
inline bool IsTerminator(OpCode op) {
  return op >= OpCode::COND_BRANCH && op <= OpCode::IMPLICIT_UNREACHABLE;
}

inline bool IsReadModifyWrite(OpCode op) {
  return op == OpCode::READ_MODIFY_WRITE;
}

inline bool IsConstant(OpCode op) {
  return op == OpCode::CONST;
}

inline bool IsBinaryOp(OpCode op) {
  return op >= OpCode::ADD && op <= OpCode::PTR_DIFF;
}

inline bool IsComparison(OpCode op) {
  return op >= OpCode::CMP_EQ && op <= OpCode::CMP_GE;
}

inline bool IsUnaryOp(OpCode op) {
  return op >= OpCode::NEG && op <= OpCode::LOGICAL_NOT;
}

inline bool IsCast(OpCode op) {
  return op == OpCode::CAST;
}

inline bool IsMemoryOp(OpCode op) {
  return op == OpCode::MEM || op == OpCode::ALLOCA ||
         op == OpCode::GEP_FIELD || op == OpCode::PTR_ADD;
}

// MemoryOp classification helpers.
inline bool IsStringToNumber(MemoryOp op) {
  return op >= MemoryOp::STRTOI32 && op <= MemoryOp::STRTOF64;
}

inline bool IsMemoryWrite(MemoryOp op) {
  return op == MemoryOp::MEMSET || op == MemoryOp::MEMCPY ||
         op == MemoryOp::MEMMOVE || op == MemoryOp::BZERO ||
         op == MemoryOp::STRCPY || op == MemoryOp::STRNCPY ||
         op == MemoryOp::STRCAT || op == MemoryOp::STRNCAT ||
         op == MemoryOp::STPCPY || op == MemoryOp::STPNCPY;
}

inline bool IsStringOp(MemoryOp op) {
  return op >= MemoryOp::STRLEN && op <= MemoryOp::STPNCPY;
}

}  // namespace mx::ir
