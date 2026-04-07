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

  // Sizeof
  SIZE_OF = 43,

  // Call
  CALL = 44,

  // Compound
  INC_DEC = 45,
  COMPOUND_ASSIGN = 46,

  // Misc
  SELECT = 47,
  COPY = 48,

  // Terminators
  COND_BRANCH = 49,
  SWITCH = 50,
  RET = 51,
  UNREACHABLE = 52,
  BREAK = 53,
  CONTINUE = 54,
  GOTO = 55,              // explicit goto label;
  IMPLICIT_GOTO = 56,     // structural CFG edge (e.g., end of if-then → merge)
  FALLTHROUGH = 57,       // explicit [[fallthrough]]
  IMPLICIT_FALLTHROUGH = 58, // implicit (no break at end of case)
  IMPLICIT_UNREACHABLE = 59, // structurally unreachable (patched empty block)

  // Variadic argument handling
  VA_PACK = 60,           // groups variadic args at call site; operands = the packed args
  VA_START = 61,          // binds va_list to function's variadic pack; op[0] = va_list
  VA_ARG = 62,            // reads next value from va_list; op[0] = va_list; typeEntityId = result type
  VA_COPY = 63,           // copies va_list; op[0] = dest, op[1] = src
  VA_END = 64,            // releases va_list; op[0] = va_list

  // Aggregate initialization
  INIT_LIST = 65,          // {a, b, c} -- operands are the initializer values

  // Scope entry/exit markers (not terminators).
  ENTER_SCOPE = 66,        // marks scope entry; extra = IRStructureId of scope
  EXIT_SCOPE = 67,         // marks scope exit; extra = IRStructureId of scope

  // Unknown / unhandled expression
  UNKNOWN = 68,
};

// Returns the human-readable name of an opcode.
inline static const char *EnumerationName(OpCode) {
  return "OpCode";
}

const char *EnumeratorName(OpCode op) noexcept;

inline static constexpr unsigned NumEnumerators(OpCode) {
  return 69u;
}

// Classification helpers.
inline bool IsTerminator(OpCode op) {
  return op >= OpCode::COND_BRANCH && op <= OpCode::IMPLICIT_UNREACHABLE;
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
