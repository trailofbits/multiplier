// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx::ir {

// Single unified opcode enum for all IR instruction types. The C++ class
// hierarchy on the read side is derived from this enum.
enum class OpCode : uint8_t {
  // Constants
  CONST_INT = 0,
  CONST_FLOAT = 1,
  CONST_NULL = 2,

  // Memory
  ALLOCA = 3,
  LOAD = 4,
  STORE = 5,
  ADDRESS_OF = 6,
  GEP_FIELD = 7,
  PTR_ADD = 8,       // pointer + index; op[0]=base, op[1]=index

  // Binary arithmetic/logic
  ADD = 9,
  SUB = 10,
  MUL = 11,
  DIV = 12,
  REM = 13,
  BIT_AND = 14,
  BIT_OR = 15,
  BIT_XOR = 16,
  SHL = 17,
  SHR = 18,
  LOGICAL_AND = 19,
  LOGICAL_OR = 20,
  PTR_DIFF = 21,

  // Comparison
  CMP_EQ = 22,
  CMP_NE = 23,
  CMP_LT = 24,
  CMP_LE = 25,
  CMP_GT = 26,
  CMP_GE = 27,

  // Unary
  NEG = 28,
  BIT_NOT = 29,
  LOGICAL_NOT = 30,

  // Cast
  CAST_SEXT = 31,
  CAST_ZEXT = 32,
  CAST_TRUNC = 33,
  CAST_BITCAST = 34,
  CAST_PTR_TO_INT = 35,
  CAST_INT_TO_PTR = 36,
  CAST_FP_TO_SI = 37,
  CAST_SI_TO_FP = 38,
  CAST_FP_TRUNC = 39,
  CAST_FP_EXT = 40,
  CAST_INT_CAST = 41,
  CAST_FP_CAST = 42,

  // Call
  CALL = 43,

  // Read-modify-write: atomically reads from address, applies an operation,
  // and writes back. operands = [address, rhs_operand0, rhs_operand1, ...].
  // The loaded value is the implicit LHS of the underlying op.
  // flags: bit 0 = returns new value (1) or old value (0, post-increment).
  // int_pool[0] = underlying opcode (ADD, SUB, PTR_ADD, SHL, etc.)
  // int_pool[1] = element size (for PTR_ADD only, 0 otherwise)
  READ_MODIFY_WRITE = 44,

  // Misc
  SELECT = 45,
  COPY = 46,

  // Terminators
  COND_BRANCH = 47,
  SWITCH = 48,
  RET = 49,
  UNREACHABLE = 50,
  BREAK = 51,
  CONTINUE = 52,
  GOTO = 53,              // explicit goto label;
  IMPLICIT_GOTO = 54,     // structural CFG edge (e.g., end of if-then → merge)
  FALLTHROUGH = 55,       // explicit [[fallthrough]]
  IMPLICIT_FALLTHROUGH = 56, // implicit (no break at end of case)
  IMPLICIT_UNREACHABLE = 57, // structurally unreachable (patched empty block)

  // Variadic argument handling
  VA_PACK = 58,           // groups variadic args at call site; operands = the packed args
  VA_START = 59,          // binds va_list to function's variadic pack; op[0] = va_list
  VA_ARG = 60,            // reads next value from va_list; op[0] = va_list; typeEntityId = result type
  VA_COPY = 61,           // copies va_list; op[0] = dest, op[1] = src
  VA_END = 62,            // releases va_list; op[0] = va_list

  // Scope entry/exit markers (not terminators).
  ENTER_SCOPE = 63,        // marks scope entry; extra = IRStructureId of scope
  EXIT_SCOPE = 64,         // marks scope exit; extra = IRStructureId of scope

  // Unified memory/string operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see MemoryOp enum).
  MULTIMEM = 65,

  // Parameter read: reads the Nth function parameter.
  PARAM_READ = 66,

  // Address-of for globals and functions (external to the current frame).
  GLOBAL_ADDR = 67,        // pointer to a global or static variable
  FUNC_ADDR = 68,          // pointer to a function

  // Bitwise/intrinsic operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see BitwiseOp enum). op[0] = primary operand.
  BITWISE_OP = 69,

  // Floating-point operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see FloatOp enum). op[0] = primary operand.
  FLOAT_OP = 70,

  // Undefined/poison value. Represents a value that is architecturally
  // undefined (e.g., __builtin_clz(0)). An analyzer should flag any use.
  UNDEFINED = 71,

  // Dynamic stack allocation.
  DYNAMIC_ALLOCA = 72,     // op[0] = size. Returns pointer to stack allocation.

  // Frame/return address intrinsics.
  FRAME_ADDRESS = 73,      // op[0] = level (CONST_INT, usually 0). Returns frame ptr.
  RETURN_ADDRESS = 74,     // op[0] = level (CONST_INT, usually 0). Returns return addr.

  // Atomic operations.
  ATOMIC_LOAD = 75,        // op[0] = address. Loads with atomic semantics.
  ATOMIC_STORE = 76,       // op[0] = address, op[1] = value.
  ATOMIC_CMPXCHG = 77,     // op[0] = target, op[1] = expected_ptr, op[2] = desired. Returns bool.

  // Overflow-checked arithmetic (only used as RMW underlying opcodes).
  // RMW returns bool (overflow flag), stores the arithmetic result.
  ADD_OVERFLOW = 78,
  SUB_OVERFLOW = 79,
  MUL_OVERFLOW = 80,

  // Atomic RMW underlying opcodes (only valid as RMW underlying ops).
  ATOMIC_ADD = 81,
  ATOMIC_SUB = 82,
  ATOMIC_AND = 83,
  ATOMIC_OR = 84,
  ATOMIC_XOR = 85,
  ATOMIC_NAND = 86,
  ATOMIC_EXCHANGE = 87,

  // Unknown / unhandled expression
  UNKNOWN = 88,
};

// Returns the human-readable name of an opcode.
inline static const char *EnumerationName(OpCode) {
  return "OpCode";
}

const char *EnumeratorName(OpCode op) noexcept;

inline static constexpr unsigned NumEnumerators(OpCode) {
  return 89u;
}

// Sub-opcodes for BITWISE_OP. Stored in the int pool.
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
};

// Sub-opcodes for FLOAT_OP. Stored in the int pool.
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
  FLOAT_HUGE = 14,  // No operands. Returns HUGE_VAL (+inf).
};

// Classification helpers.
inline bool IsTerminator(OpCode op) {
  return op >= OpCode::COND_BRANCH && op <= OpCode::IMPLICIT_UNREACHABLE;
}

inline bool IsReadModifyWrite(OpCode op) {
  return op == OpCode::READ_MODIFY_WRITE;
}

inline bool IsConstant(OpCode op) {
  return op >= OpCode::CONST_INT && op <= OpCode::CONST_NULL;
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
  return op >= OpCode::CAST_SEXT && op <= OpCode::CAST_FP_CAST;
}

inline bool IsMemoryOp(OpCode op) {
  return op >= OpCode::ALLOCA && op <= OpCode::PTR_ADD;
}

}  // namespace mx::ir
