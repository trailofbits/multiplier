// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TokenCategory.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TokenCategory e) {
  switch (e) {
    case TokenCategory::UNKNOWN: return "UNKNOWN";
    case TokenCategory::IDENTIFIER: return "IDENTIFIER";
    case TokenCategory::MACRO_NAME: return "MACRO_NAME";
    case TokenCategory::MACRO_PARAMETER_NAME: return "MACRO_PARAMETER_NAME";
    case TokenCategory::MACRO_DIRECTIVE_NAME: return "MACRO_DIRECTIVE_NAME";
    case TokenCategory::KEYWORD: return "KEYWORD";
    case TokenCategory::OBJECTIVE_C_KEYWORD: return "OBJECTIVE_C_KEYWORD";
    case TokenCategory::BUILTIN_TYPE_NAME: return "BUILTIN_TYPE_NAME";
    case TokenCategory::PUNCTUATION: return "PUNCTUATION";
    case TokenCategory::LITERAL: return "LITERAL";
    case TokenCategory::COMMENT: return "COMMENT";
    case TokenCategory::LOCAL_VARIABLE: return "LOCAL_VARIABLE";
    case TokenCategory::GLOBAL_VARIABLE: return "GLOBAL_VARIABLE";
    case TokenCategory::PARAMETER_VARIABLE: return "PARAMETER_VARIABLE";
    case TokenCategory::FUNCTION: return "FUNCTION";
    case TokenCategory::INSTANCE_METHOD: return "INSTANCE_METHOD";
    case TokenCategory::INSTANCE_MEMBER: return "INSTANCE_MEMBER";
    case TokenCategory::CLASS_METHOD: return "CLASS_METHOD";
    case TokenCategory::CLASS_MEMBER: return "CLASS_MEMBER";
    case TokenCategory::THIS: return "THIS";
    case TokenCategory::CLASS: return "CLASS";
    case TokenCategory::STRUCT: return "STRUCT";
    case TokenCategory::UNION: return "UNION";
    case TokenCategory::CONCEPT: return "CONCEPT";
    case TokenCategory::INTERFACE: return "INTERFACE";
    case TokenCategory::ENUM: return "ENUM";
    case TokenCategory::ENUMERATOR: return "ENUMERATOR";
    case TokenCategory::NAMESPACE: return "NAMESPACE";
    case TokenCategory::TYPE_ALIAS: return "TYPE_ALIAS";
    case TokenCategory::TEMPLATE_PARAMETER_TYPE: return "TEMPLATE_PARAMETER_TYPE";
    case TokenCategory::TEMPLATE_PARAMETER_VALUE: return "TEMPLATE_PARAMETER_VALUE";
    case TokenCategory::LABEL: return "LABEL";
    case TokenCategory::WHITESPACE: return "WHITESPACE";
    case TokenCategory::FILE_NAME: return "FILE_NAME";
    case TokenCategory::LINE_NUMBER: return "LINE_NUMBER";
    case TokenCategory::COLUMN_NUMBER: return "COLUMN_NUMBER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
