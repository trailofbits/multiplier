// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateArgumentKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TemplateArgumentKind e) {
  switch (e) {
    case TemplateArgumentKind::EMPTY: return "EMPTY";
    case TemplateArgumentKind::TYPE: return "TYPE";
    case TemplateArgumentKind::DECLARATION: return "DECLARATION";
    case TemplateArgumentKind::NULL_POINTER: return "NULL_POINTER";
    case TemplateArgumentKind::INTEGRAL: return "INTEGRAL";
    case TemplateArgumentKind::TEMPLATE: return "TEMPLATE";
    case TemplateArgumentKind::TEMPLATE_EXPANSION: return "TEMPLATE_EXPANSION";
    case TemplateArgumentKind::EXPRESSION: return "EXPRESSION";
    case TemplateArgumentKind::PACK: return "PACK";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
