// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExprisModifiableLvalueResult.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprisModifiableLvalueResult e) {
  switch (e) {
    case ExprisModifiableLvalueResult::VALID: return "VALID";
    case ExprisModifiableLvalueResult::NOT_OBJECT_TYPE: return "NOT_OBJECT_TYPE";
    case ExprisModifiableLvalueResult::INCOMPLETE_VOID_TYPE: return "INCOMPLETE_VOID_TYPE";
    case ExprisModifiableLvalueResult::DUPLICATE_VECTOR_COMPONENTS: return "DUPLICATE_VECTOR_COMPONENTS";
    case ExprisModifiableLvalueResult::INVALID_EXPRESSION: return "INVALID_EXPRESSION";
    case ExprisModifiableLvalueResult::L_VALUE_CAST: return "L_VALUE_CAST";
    case ExprisModifiableLvalueResult::INCOMPLETE_TYPE: return "INCOMPLETE_TYPE";
    case ExprisModifiableLvalueResult::CONST_QUALIFIED: return "CONST_QUALIFIED";
    case ExprisModifiableLvalueResult::CONST_QUALIFIED_FIELD: return "CONST_QUALIFIED_FIELD";
    case ExprisModifiableLvalueResult::CONST_ADDRESS_SPACE: return "CONST_ADDRESS_SPACE";
    case ExprisModifiableLvalueResult::ARRAY_TYPE: return "ARRAY_TYPE";
    case ExprisModifiableLvalueResult::NO_SETTER_PROPERTY: return "NO_SETTER_PROPERTY";
    case ExprisModifiableLvalueResult::MEMBER_FUNCTION: return "MEMBER_FUNCTION";
    case ExprisModifiableLvalueResult::SUB_OBJ_C_PROPERTY_SETTING: return "SUB_OBJ_C_PROPERTY_SETTING";
    case ExprisModifiableLvalueResult::INVALID_MESSAGE_EXPRESSION: return "INVALID_MESSAGE_EXPRESSION";
    case ExprisModifiableLvalueResult::CLASS_TEMPORARY: return "CLASS_TEMPORARY";
    case ExprisModifiableLvalueResult::ARRAY_TEMPORARY: return "ARRAY_TEMPORARY";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
