// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionDeclTemplatedKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FunctionDeclTemplatedKind e) {
  switch (e) {
    case FunctionDeclTemplatedKind::NON_TEMPLATE: return "NON_TEMPLATE";
    case FunctionDeclTemplatedKind::FUNCTION_TEMPLATE: return "FUNCTION_TEMPLATE";
    case FunctionDeclTemplatedKind::MEMBER_SPECIALIZATION: return "MEMBER_SPECIALIZATION";
    case FunctionDeclTemplatedKind::FUNCTION_TEMPLATE_SPECIALIZATION: return "FUNCTION_TEMPLATE_SPECIALIZATION";
    case FunctionDeclTemplatedKind::DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION: return "DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION";
    case FunctionDeclTemplatedKind::DEPENDENT_NON_TEMPLATE: return "DEPENDENT_NON_TEMPLATE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
