// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TypeKind : unsigned char {
  ADJUSTED,
  DECAYED,
  CONSTANT_ARRAY,
  DEPENDENT_SIZED_ARRAY,
  INCOMPLETE_ARRAY,
  VARIABLE_ARRAY,
  ATOMIC,
  ATTRIBUTED,
  BTF_TAG_ATTRIBUTED,
  BIT_INT,
  BLOCK_POINTER,
  BUILTIN,
  COMPLEX,
  DECLTYPE,
  AUTO,
  DEDUCED_TEMPLATE_SPECIALIZATION,
  DEPENDENT_ADDRESS_SPACE,
  DEPENDENT_BIT_INT,
  DEPENDENT_NAME,
  DEPENDENT_SIZED_EXT_VECTOR,
  DEPENDENT_TEMPLATE_SPECIALIZATION,
  DEPENDENT_VECTOR,
  ELABORATED,
  FUNCTION_NO_PROTO,
  FUNCTION_PROTO,
  INJECTED_CLASS_NAME,
  MACRO_QUALIFIED,
  CONSTANT_MATRIX,
  DEPENDENT_SIZED_MATRIX,
  MEMBER_POINTER,
  OBJ_C_OBJECT_POINTER,
  OBJ_C_OBJECT,
  OBJ_C_INTERFACE,
  OBJ_C_TYPE_PARAM,
  PACK_EXPANSION,
  PAREN,
  PIPE,
  POINTER,
  L_VALUE_REFERENCE,
  R_VALUE_REFERENCE,
  SUBST_TEMPLATE_TYPE_PARM_PACK,
  SUBST_TEMPLATE_TYPE_PARM,
  ENUM,
  RECORD,
  TEMPLATE_SPECIALIZATION,
  TEMPLATE_TYPE_PARM,
  TYPE_OF_EXPR,
  TYPE_OF,
  TYPEDEF,
  UNARY_TRANSFORM,
  UNRESOLVED_USING,
  USING,
  VECTOR,
  EXT_VECTOR,
  QUALIFIED,
};

inline static const char *EnumerationName(TypeKind) {
  return "TypeKind";
}

inline static constexpr unsigned NumEnumerators(TypeKind) {
  return 55;
}

const char *EnumeratorName(TypeKind);

} // namespace mx
