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
  GEP_INDEX = 8,
  PTR_ADD = 9,

  // Binary arithmetic/logic
  ADD = 10,
  SUB = 11,
  MUL = 12,
  DIV = 13,
  REM = 14,
  BIT_AND = 15,
  BIT_OR = 16,
  BIT_XOR = 17,
  SHL = 18,
  SHR = 19,
  LOGICAL_AND = 20,
  LOGICAL_OR = 21,
  PTR_DIFF = 22,

  // Comparison
  CMP_EQ = 23,
  CMP_NE = 24,
  CMP_LT = 25,
  CMP_LE = 26,
  CMP_GT = 27,
  CMP_GE = 28,

  // Unary
  NEG = 29,
  BIT_NOT = 30,
  LOGICAL_NOT = 31,

  // Cast
  CAST_SEXT = 32,
  CAST_ZEXT = 33,
  CAST_TRUNC = 34,
  CAST_BITCAST = 35,
  CAST_PTR_TO_INT = 36,
  CAST_INT_TO_PTR = 37,
  CAST_FP_TO_SI = 38,
  CAST_SI_TO_FP = 39,
  CAST_FP_TRUNC = 40,
  CAST_FP_EXT = 41,
  CAST_INT_CAST = 42,
  CAST_FP_CAST = 43,

  // Sizeof
  SIZE_OF = 44,

  // Call
  CALL = 45,

  // Compound
  INC_DEC = 46,
  COMPOUND_ASSIGN = 47,

  // Misc
  SELECT = 48,
  COPY = 49,

  // Terminators
  COND_BRANCH = 50,
  SWITCH = 51,
  RET = 52,
  UNREACHABLE = 53,
  BREAK = 54,
  CONTINUE = 55,
  GOTO = 56,              // explicit goto label;
  IMPLICIT_GOTO = 57,     // structural CFG edge (e.g., end of if-then → merge)
  FALLTHROUGH = 58,       // explicit [[fallthrough]]
  IMPLICIT_FALLTHROUGH = 59, // implicit (no break at end of case)

  // Variadic argument handling
  VA_PACK = 60,           // groups variadic args at call site; operands = the packed args
  VA_START = 61,          // binds va_list to function's variadic pack; op[0] = va_list
  VA_ARG = 62,            // reads next value from va_list; op[0] = va_list; typeEntityId = result type
  VA_COPY = 63,           // copies va_list; op[0] = dest, op[1] = src
  VA_END = 64,            // releases va_list; op[0] = va_list

  // Aggregate initialization
  INIT_LIST = 65,          // {a, b, c} -- operands are the initializer values

  // Method calls (C++ instance/member function)
  // op[0] = this/base object, op[1..] = arguments
  // targetEntityId = CXXMethodDecl
  METHOD_CALL = 66,          // non-virtual method call
  VIRTUAL_METHOD_CALL = 67,  // virtual/override method call (dynamic dispatch)

  // C++ new/delete
  NEW = 68,                  // typeEntityId = allocated type
  NEW_ARRAY = 69,            // op[0] = array size; typeEntityId = element type
  PLACEMENT_NEW = 70,        // op[0] = placement address, op[1..] = other placement args; typeEntityId = allocated type
  PLACEMENT_NEW_ARRAY = 71,  // op[0] = array size, op[1] = placement address, op[2..] = other placement args
  DELETE = 72,               // op[0] = pointer to delete
  DELETE_ARRAY = 73,         // op[0] = pointer to delete

  // Unknown / unhandled expression
  UNKNOWN = 74,
};

// Returns the human-readable name of an opcode.
inline static const char *EnumerationName(OpCode) {
  return "OpCode";
}

const char *EnumeratorName(OpCode op) noexcept;

inline static constexpr unsigned NumEnumerators(OpCode) {
  return 75u;
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
