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

  // Memory operations.
  MEMSET = 65,             // op[0] = dest, op[1] = byte value, op[2] = size
  MEMCPY = 66,             // op[0] = dest, op[1] = src, op[2] = size (UB if overlapping)
  MEMMOVE = 67,            // op[0] = dest, op[1] = src, op[2] = size (safe for overlap)

  // Parameter read: reads the Nth function parameter.
  PARAM_READ = 68,

  // Address-of for globals and functions (external to the current frame).
  GLOBAL_ADDR = 69,        // pointer to a global or static variable
  FUNC_ADDR = 70,          // pointer to a function

  // Bitwise/intrinsic operations. Sub-opcode in int_pool[0] selects the
  // specific operation (see BitwiseOp enum). op[0] = primary operand.
  BITWISE_OP = 71,

  // Undefined/poison value. Represents a value that is architecturally
  // undefined (e.g., __builtin_clz(0)). An analyzer should flag any use.
  UNDEFINED = 72,

  // Overflow-checked arithmetic (only used as RMW underlying opcodes).
  // RMW returns bool (overflow flag), stores the arithmetic result.
  ADD_OVERFLOW = 74,
  SUB_OVERFLOW = 75,
  MUL_OVERFLOW = 76,

  // Unknown / unhandled expression
  UNKNOWN = 77,
};

// Returns the human-readable name of an opcode.
inline static const char *EnumerationName(OpCode) {
  return "OpCode";
}

const char *EnumeratorName(OpCode op) noexcept;

inline static constexpr unsigned NumEnumerators(OpCode) {
  return 78u;
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
