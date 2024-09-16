// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateSpecializationKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TemplateSpecializationKind e) {
  switch (e) {
    case TemplateSpecializationKind::UNDECLARED: return "UNDECLARED";
    case TemplateSpecializationKind::IMPLICIT_INSTANTIATION: return "IMPLICIT_INSTANTIATION";
    case TemplateSpecializationKind::EXPLICIT_SPECIALIZATION: return "EXPLICIT_SPECIALIZATION";
    case TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DECLARATION: return "EXPLICIT_INSTANTIATION_DECLARATION";
    case TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DEFINITION: return "EXPLICIT_INSTANTIATION_DEFINITION";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
