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
  // Block argument
  BLOCK_ARG_DEF = 0,

  // Constants
  CONST_INT = 1,
  CONST_FLOAT = 2,
  CONST_NULL = 3,

  // Memory
  ALLOCA = 4,
  LOAD = 5,
  STORE = 6,
  ADDRESS_OF = 7,
  GEP_FIELD = 8,
  GEP_INDEX = 9,
  PTR_ADD = 10,

  // Binary arithmetic/logic
  ADD = 11,
  SUB = 12,
  MUL = 13,
  DIV = 14,
  REM = 15,
  BIT_AND = 16,
  BIT_OR = 17,
  BIT_XOR = 18,
  SHL = 19,
  SHR = 20,
  LOGICAL_AND = 21,
  LOGICAL_OR = 22,
  PTR_DIFF = 23,

  // Comparison
  CMP_EQ = 24,
  CMP_NE = 25,
  CMP_LT = 26,
  CMP_LE = 27,
  CMP_GT = 28,
  CMP_GE = 29,

  // Unary
  NEG = 30,
  BIT_NOT = 31,
  LOGICAL_NOT = 32,

  // Cast
  CAST_SEXT = 33,
  CAST_ZEXT = 34,
  CAST_TRUNC = 35,
  CAST_BITCAST = 36,
  CAST_PTR_TO_INT = 37,
  CAST_INT_TO_PTR = 38,
  CAST_FP_TO_SI = 39,
  CAST_SI_TO_FP = 40,
  CAST_FP_TRUNC = 41,
  CAST_FP_EXT = 42,
  CAST_INT_CAST = 43,
  CAST_FP_CAST = 44,

  // Sizeof
  SIZE_OF = 45,

  // Call
  CALL = 46,

  // Compound
  INC_DEC = 47,
  COMPOUND_ASSIGN = 48,

  // Misc
  SELECT = 49,
  COPY = 50,

  // Terminators
  COND_BRANCH = 51,
  SWITCH = 52,
  RET = 53,
  UNREACHABLE = 54,
  BREAK = 55,
  CONTINUE = 56,
  GOTO = 57,              // explicit goto label;
  IMPLICIT_GOTO = 58,     // structural CFG edge (e.g., end of if-then → merge)
  FALLTHROUGH = 59,       // explicit [[fallthrough]]
  IMPLICIT_FALLTHROUGH = 60, // implicit (no break at end of case)

  // Variadic argument handling
  VA_PACK = 61,           // groups variadic args at call site; operands = the packed args
  VA_START = 62,          // binds va_list to function's variadic pack; op[0] = va_list
  VA_ARG = 63,            // reads next value from va_list; op[0] = va_list; typeEntityId = result type
  VA_COPY = 64,           // copies va_list; op[0] = dest, op[1] = src
  VA_END = 65,            // releases va_list; op[0] = va_list

  // Unknown / unhandled expression
  UNKNOWN = 66,
};

// Returns the human-readable name of an opcode.
inline static const char *EnumerationName(OpCode) {
  return "OpCode";
}

const char *EnumeratorName(OpCode op) noexcept;

inline static constexpr unsigned NumEnumerators(OpCode) {
  return 67u;
}

// Classification helpers.
inline bool IsTerminator(OpCode op) {
  return op >= OpCode::COND_BRANCH && op <= OpCode::IMPLICIT_FALLTHROUGH;
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
