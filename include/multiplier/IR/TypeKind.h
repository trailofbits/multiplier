// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

namespace mx {
namespace ir {

enum class TypeKind : unsigned {
  UNKNOWN,
  LLVM_ARRAY,  // "array"
  LLVM_FIXED_VECTOR,  // "vec"
  LLVM_FUNCTION,  // "func"
  LLVM_POINTER,  // "ptr"
  LLVM_SCALABLE_VECTOR,  // "vec"
  LLVM_TARGET_EXT,  // "target"
  ADJUSTED,  // "adjusted"
  ARRAY,  // "array"
  ATTRIBUTED,  // "attributed"
  B_FLOAT16,  // "bfloat16"
  BOOL,  // "bool"
  CHAR,  // "char"
  DECAYED,  // "decayed"
  DOUBLE,  // "double"
  ELABORATED,  // "elaborated"
  ENUM,  // "enum"
  FLOAT128,  // "float128"
  FLOAT,  // "float"
  HALF,  // "half"
  INT128,  // "int128"
  INT,  // "int"
  L_VALUE,  // "lvalue"
  LABEL,  // "label"
  LONG_DOUBLE,  // "longdouble"
  LONG_LONG,  // "longlong"
  LONG,  // "long"
  PAREN,  // "paren"
  POINTER,  // "ptr"
  R_VALUE,  // "rvalue"
  RECORD,  // "record"
  REFERENCE,  // "reference"
  SHORT,  // "short"
  TYPE_OF_EXPR,  // "typeof.expr"
  TYPE_OF_TYPE,  // "typeof.type"
  TYPEDEF,  // "typedef"
  VOID,  // "void"
  FUNCTION,  // "fn"
  UNSUPPORTED,  // "type"
};

}  // namespace ir

inline static const char *EnumerationName(ir::TypeKind) {
  return "TypeKind";
}

inline static constexpr unsigned NumEnumerators(ir::TypeKind) {
  return 38;
}

const char *EnumeratorName(ir::TypeKind);

}  // namespace mx
