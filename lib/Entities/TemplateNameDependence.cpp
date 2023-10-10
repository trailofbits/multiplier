// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TemplateNameDependence.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TemplateNameDependence e) {
  switch (e) {
    case TemplateNameDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case TemplateNameDependence::INSTANTIATION: return "INSTANTIATION";
    case TemplateNameDependence::DEPENDENT: return "DEPENDENT";
    case TemplateNameDependence::ERROR: return "ERROR";
    case TemplateNameDependence::NONE: return "NONE";
    case TemplateNameDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    case TemplateNameDependence::ALL: return "ALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
