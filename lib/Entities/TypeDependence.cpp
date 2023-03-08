// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/TypeDependence.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TypeDependence e) {
  switch (e) {
    case TypeDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case TypeDependence::INSTANTIATION: return "INSTANTIATION";
    case TypeDependence::DEPENDENT: return "DEPENDENT";
    case TypeDependence::VARIABLY_MODIFIED: return "VARIABLY_MODIFIED";
    case TypeDependence::ERROR: return "ERROR";
    case TypeDependence::NONE: return "NONE";
    case TypeDependence::ALL: return "ALL";
    case TypeDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
