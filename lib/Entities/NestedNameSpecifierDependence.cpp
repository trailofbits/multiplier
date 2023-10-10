// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/NestedNameSpecifierDependence.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NestedNameSpecifierDependence e) {
  switch (e) {
    case NestedNameSpecifierDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case NestedNameSpecifierDependence::INSTANTIATION: return "INSTANTIATION";
    case NestedNameSpecifierDependence::DEPENDENT: return "DEPENDENT";
    case NestedNameSpecifierDependence::ERROR: return "ERROR";
    case NestedNameSpecifierDependence::NONE: return "NONE";
    case NestedNameSpecifierDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    case NestedNameSpecifierDependence::ALL: return "ALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
