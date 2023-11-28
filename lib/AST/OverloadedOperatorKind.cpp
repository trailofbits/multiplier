// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OverloadedOperatorKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OverloadedOperatorKind e) {
  switch (e) {
    case OverloadedOperatorKind::NONE: return "NONE";
    case OverloadedOperatorKind::NEW: return "NEW";
    case OverloadedOperatorKind::DELETE: return "DELETE";
    case OverloadedOperatorKind::ARRAY_NEW: return "ARRAY_NEW";
    case OverloadedOperatorKind::ARRAY_DELETE: return "ARRAY_DELETE";
    case OverloadedOperatorKind::PLUS: return "PLUS";
    case OverloadedOperatorKind::MINUS: return "MINUS";
    case OverloadedOperatorKind::STAR: return "STAR";
    case OverloadedOperatorKind::SLASH: return "SLASH";
    case OverloadedOperatorKind::PERCENT: return "PERCENT";
    case OverloadedOperatorKind::CARET: return "CARET";
    case OverloadedOperatorKind::AMP: return "AMP";
    case OverloadedOperatorKind::PIPE: return "PIPE";
    case OverloadedOperatorKind::TILDE: return "TILDE";
    case OverloadedOperatorKind::EXCLAIM: return "EXCLAIM";
    case OverloadedOperatorKind::EQUAL: return "EQUAL";
    case OverloadedOperatorKind::LESS: return "LESS";
    case OverloadedOperatorKind::GREATER: return "GREATER";
    case OverloadedOperatorKind::PLUS_EQUAL: return "PLUS_EQUAL";
    case OverloadedOperatorKind::MINUS_EQUAL: return "MINUS_EQUAL";
    case OverloadedOperatorKind::STAR_EQUAL: return "STAR_EQUAL";
    case OverloadedOperatorKind::SLASH_EQUAL: return "SLASH_EQUAL";
    case OverloadedOperatorKind::PERCENT_EQUAL: return "PERCENT_EQUAL";
    case OverloadedOperatorKind::CARET_EQUAL: return "CARET_EQUAL";
    case OverloadedOperatorKind::AMP_EQUAL: return "AMP_EQUAL";
    case OverloadedOperatorKind::PIPE_EQUAL: return "PIPE_EQUAL";
    case OverloadedOperatorKind::LESS_LESS: return "LESS_LESS";
    case OverloadedOperatorKind::GREATER_GREATER: return "GREATER_GREATER";
    case OverloadedOperatorKind::LESS_LESS_EQUAL: return "LESS_LESS_EQUAL";
    case OverloadedOperatorKind::GREATER_GREATER_EQUAL: return "GREATER_GREATER_EQUAL";
    case OverloadedOperatorKind::EQUAL_EQUAL: return "EQUAL_EQUAL";
    case OverloadedOperatorKind::EXCLAIM_EQUAL: return "EXCLAIM_EQUAL";
    case OverloadedOperatorKind::LESS_EQUAL: return "LESS_EQUAL";
    case OverloadedOperatorKind::GREATER_EQUAL: return "GREATER_EQUAL";
    case OverloadedOperatorKind::SPACESHIP: return "SPACESHIP";
    case OverloadedOperatorKind::AMP_AMP: return "AMP_AMP";
    case OverloadedOperatorKind::PIPE_PIPE: return "PIPE_PIPE";
    case OverloadedOperatorKind::PLUS_PLUS: return "PLUS_PLUS";
    case OverloadedOperatorKind::MINUS_MINUS: return "MINUS_MINUS";
    case OverloadedOperatorKind::COMMA: return "COMMA";
    case OverloadedOperatorKind::ARROW_STAR: return "ARROW_STAR";
    case OverloadedOperatorKind::ARROW: return "ARROW";
    case OverloadedOperatorKind::CALL: return "CALL";
    case OverloadedOperatorKind::SUBSCRIPT: return "SUBSCRIPT";
    case OverloadedOperatorKind::CONDITIONAL: return "CONDITIONAL";
    case OverloadedOperatorKind::COAWAIT: return "COAWAIT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
