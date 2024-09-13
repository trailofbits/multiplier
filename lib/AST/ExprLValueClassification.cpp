// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExprLValueClassification.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprLValueClassification e) {
  switch (e) {
    case ExprLValueClassification::VALID: return "VALID";
    case ExprLValueClassification::NOT_OBJECT_TYPE: return "NOT_OBJECT_TYPE";
    case ExprLValueClassification::INCOMPLETE_VOID_TYPE: return "INCOMPLETE_VOID_TYPE";
    case ExprLValueClassification::DUPLICATE_VECTOR_COMPONENTS: return "DUPLICATE_VECTOR_COMPONENTS";
    case ExprLValueClassification::INVALID_EXPRESSION: return "INVALID_EXPRESSION";
    case ExprLValueClassification::INVALID_MESSAGE_EXPRESSION: return "INVALID_MESSAGE_EXPRESSION";
    case ExprLValueClassification::MEMBER_FUNCTION: return "MEMBER_FUNCTION";
    case ExprLValueClassification::SUB_OBJ_C_PROPERTY_SETTING: return "SUB_OBJ_C_PROPERTY_SETTING";
    case ExprLValueClassification::CLASS_TEMPORARY: return "CLASS_TEMPORARY";
    case ExprLValueClassification::ARRAY_TEMPORARY: return "ARRAY_TEMPORARY";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
