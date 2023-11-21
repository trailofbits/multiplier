// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TypeKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeKind e) {
  switch (e) {
    case TypeKind::ADJUSTED: return "ADJUSTED";
    case TypeKind::DECAYED: return "DECAYED";
    case TypeKind::CONSTANT_ARRAY: return "CONSTANT_ARRAY";
    case TypeKind::DEPENDENT_SIZED_ARRAY: return "DEPENDENT_SIZED_ARRAY";
    case TypeKind::INCOMPLETE_ARRAY: return "INCOMPLETE_ARRAY";
    case TypeKind::VARIABLE_ARRAY: return "VARIABLE_ARRAY";
    case TypeKind::ATOMIC: return "ATOMIC";
    case TypeKind::ATTRIBUTED: return "ATTRIBUTED";
    case TypeKind::BTF_TAG_ATTRIBUTED: return "BTF_TAG_ATTRIBUTED";
    case TypeKind::BIT_INT: return "BIT_INT";
    case TypeKind::BLOCK_POINTER: return "BLOCK_POINTER";
    case TypeKind::BUILTIN: return "BUILTIN";
    case TypeKind::COMPLEX: return "COMPLEX";
    case TypeKind::DECLTYPE: return "DECLTYPE";
    case TypeKind::AUTO: return "AUTO";
    case TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION: return "DEDUCED_TEMPLATE_SPECIALIZATION";
    case TypeKind::DEPENDENT_ADDRESS_SPACE: return "DEPENDENT_ADDRESS_SPACE";
    case TypeKind::DEPENDENT_BIT_INT: return "DEPENDENT_BIT_INT";
    case TypeKind::DEPENDENT_NAME: return "DEPENDENT_NAME";
    case TypeKind::DEPENDENT_SIZED_EXT_VECTOR: return "DEPENDENT_SIZED_EXT_VECTOR";
    case TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION: return "DEPENDENT_TEMPLATE_SPECIALIZATION";
    case TypeKind::DEPENDENT_VECTOR: return "DEPENDENT_VECTOR";
    case TypeKind::ELABORATED: return "ELABORATED";
    case TypeKind::FUNCTION_NO_PROTO: return "FUNCTION_NO_PROTO";
    case TypeKind::FUNCTION_PROTO: return "FUNCTION_PROTO";
    case TypeKind::INJECTED_CLASS_NAME: return "INJECTED_CLASS_NAME";
    case TypeKind::MACRO_QUALIFIED: return "MACRO_QUALIFIED";
    case TypeKind::CONSTANT_MATRIX: return "CONSTANT_MATRIX";
    case TypeKind::DEPENDENT_SIZED_MATRIX: return "DEPENDENT_SIZED_MATRIX";
    case TypeKind::MEMBER_POINTER: return "MEMBER_POINTER";
    case TypeKind::OBJ_C_OBJECT_POINTER: return "OBJ_C_OBJECT_POINTER";
    case TypeKind::OBJ_C_OBJECT: return "OBJ_C_OBJECT";
    case TypeKind::OBJ_C_INTERFACE: return "OBJ_C_INTERFACE";
    case TypeKind::OBJ_C_TYPE_PARAM: return "OBJ_C_TYPE_PARAM";
    case TypeKind::PACK_EXPANSION: return "PACK_EXPANSION";
    case TypeKind::PAREN: return "PAREN";
    case TypeKind::PIPE: return "PIPE";
    case TypeKind::POINTER: return "POINTER";
    case TypeKind::L_VALUE_REFERENCE: return "L_VALUE_REFERENCE";
    case TypeKind::R_VALUE_REFERENCE: return "R_VALUE_REFERENCE";
    case TypeKind::SUBST_TEMPLATE_TYPE_PARM_PACK: return "SUBST_TEMPLATE_TYPE_PARM_PACK";
    case TypeKind::SUBST_TEMPLATE_TYPE_PARM: return "SUBST_TEMPLATE_TYPE_PARM";
    case TypeKind::ENUM: return "ENUM";
    case TypeKind::RECORD: return "RECORD";
    case TypeKind::TEMPLATE_SPECIALIZATION: return "TEMPLATE_SPECIALIZATION";
    case TypeKind::TEMPLATE_TYPE_PARM: return "TEMPLATE_TYPE_PARM";
    case TypeKind::TYPE_OF_EXPR: return "TYPE_OF_EXPR";
    case TypeKind::TYPE_OF: return "TYPE_OF";
    case TypeKind::TYPEDEF: return "TYPEDEF";
    case TypeKind::UNARY_TRANSFORM: return "UNARY_TRANSFORM";
    case TypeKind::UNRESOLVED_USING: return "UNRESOLVED_USING";
    case TypeKind::USING: return "USING";
    case TypeKind::VECTOR: return "VECTOR";
    case TypeKind::EXT_VECTOR: return "EXT_VECTOR";
    case TypeKind::QUALIFIED: return "QUALIFIED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
