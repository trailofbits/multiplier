// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TemplateArgumentDependence.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TemplateArgumentDependence e) {
  switch (e) {
    case TemplateArgumentDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case TemplateArgumentDependence::INSTANTIATION: return "INSTANTIATION";
    case TemplateArgumentDependence::DEPENDENT: return "DEPENDENT";
    case TemplateArgumentDependence::ERROR: return "ERROR";
    case TemplateArgumentDependence::NONE: return "NONE";
    case TemplateArgumentDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    case TemplateArgumentDependence::ALL: return "ALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
