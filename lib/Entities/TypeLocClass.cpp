// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeLocClass.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeLocClass e) {
  switch (e) {
    case TypeLocClass::ADJUSTED: return "ADJUSTED";
    case TypeLocClass::DECAYED: return "DECAYED";
    case TypeLocClass::CONSTANT_ARRAY: return "CONSTANT_ARRAY";
    case TypeLocClass::DEPENDENT_SIZED_ARRAY: return "DEPENDENT_SIZED_ARRAY";
    case TypeLocClass::INCOMPLETE_ARRAY: return "INCOMPLETE_ARRAY";
    case TypeLocClass::VARIABLE_ARRAY: return "VARIABLE_ARRAY";
    case TypeLocClass::ATOMIC: return "ATOMIC";
    case TypeLocClass::ATTRIBUTED: return "ATTRIBUTED";
    case TypeLocClass::BTF_TAG_ATTRIBUTED: return "BTF_TAG_ATTRIBUTED";
    case TypeLocClass::BIT_INT: return "BIT_INT";
    case TypeLocClass::BLOCK_POINTER: return "BLOCK_POINTER";
    case TypeLocClass::BUILTIN: return "BUILTIN";
    case TypeLocClass::COMPLEX: return "COMPLEX";
    case TypeLocClass::DECLTYPE: return "DECLTYPE";
    case TypeLocClass::AUTO: return "AUTO";
    case TypeLocClass::DEDUCED_TEMPLATE_SPECIALIZATION: return "DEDUCED_TEMPLATE_SPECIALIZATION";
    case TypeLocClass::DEPENDENT_ADDRESS_SPACE: return "DEPENDENT_ADDRESS_SPACE";
    case TypeLocClass::DEPENDENT_BIT_INT: return "DEPENDENT_BIT_INT";
    case TypeLocClass::DEPENDENT_NAME: return "DEPENDENT_NAME";
    case TypeLocClass::DEPENDENT_SIZED_EXT_VECTOR: return "DEPENDENT_SIZED_EXT_VECTOR";
    case TypeLocClass::DEPENDENT_TEMPLATE_SPECIALIZATION: return "DEPENDENT_TEMPLATE_SPECIALIZATION";
    case TypeLocClass::DEPENDENT_VECTOR: return "DEPENDENT_VECTOR";
    case TypeLocClass::ELABORATED: return "ELABORATED";
    case TypeLocClass::FUNCTION_NO_PROTO: return "FUNCTION_NO_PROTO";
    case TypeLocClass::FUNCTION_PROTO: return "FUNCTION_PROTO";
    case TypeLocClass::INJECTED_CLASS_NAME: return "INJECTED_CLASS_NAME";
    case TypeLocClass::MACRO_QUALIFIED: return "MACRO_QUALIFIED";
    case TypeLocClass::CONSTANT_MATRIX: return "CONSTANT_MATRIX";
    case TypeLocClass::DEPENDENT_SIZED_MATRIX: return "DEPENDENT_SIZED_MATRIX";
    case TypeLocClass::MEMBER_POINTER: return "MEMBER_POINTER";
    case TypeLocClass::OBJ_C_OBJECT_POINTER: return "OBJ_C_OBJECT_POINTER";
    case TypeLocClass::OBJ_C_OBJECT: return "OBJ_C_OBJECT";
    case TypeLocClass::OBJ_C_INTERFACE: return "OBJ_C_INTERFACE";
    case TypeLocClass::OBJ_C_TYPE_PARAMETER: return "OBJ_C_TYPE_PARAMETER";
    case TypeLocClass::PACK_EXPANSION: return "PACK_EXPANSION";
    case TypeLocClass::PARENTHESIS: return "PARENTHESIS";
    case TypeLocClass::PIPE: return "PIPE";
    case TypeLocClass::POINTER: return "POINTER";
    case TypeLocClass::L_VALUE_REFERENCE: return "L_VALUE_REFERENCE";
    case TypeLocClass::R_VALUE_REFERENCE: return "R_VALUE_REFERENCE";
    case TypeLocClass::SUBST_TEMPLATE_TYPE_PARM_PACK: return "SUBST_TEMPLATE_TYPE_PARM_PACK";
    case TypeLocClass::SUBST_TEMPLATE_TYPE_PARM: return "SUBST_TEMPLATE_TYPE_PARM";
    case TypeLocClass::ENUM: return "ENUM";
    case TypeLocClass::RECORD: return "RECORD";
    case TypeLocClass::TEMPLATE_SPECIALIZATION: return "TEMPLATE_SPECIALIZATION";
    case TypeLocClass::TEMPLATE_TYPE_PARM: return "TEMPLATE_TYPE_PARM";
    case TypeLocClass::TYPE_OF_EXPRESSION: return "TYPE_OF_EXPRESSION";
    case TypeLocClass::TYPE_OF: return "TYPE_OF";
    case TypeLocClass::TYPEDEF: return "TYPEDEF";
    case TypeLocClass::UNARY_TRANSFORM: return "UNARY_TRANSFORM";
    case TypeLocClass::UNRESOLVED_USING: return "UNRESOLVED_USING";
    case TypeLocClass::USING: return "USING";
    case TypeLocClass::VECTOR: return "VECTOR";
    case TypeLocClass::EXT_VECTOR: return "EXT_VECTOR";
    case TypeLocClass::QUALIFIED: return "QUALIFIED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
