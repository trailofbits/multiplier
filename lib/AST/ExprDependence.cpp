// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ExprDependence.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExprDependence e) {
  switch (e) {
    case ExprDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case ExprDependence::INSTANTIATION: return "INSTANTIATION";
    case ExprDependence::TYPE: return "TYPE";
    case ExprDependence::VALUE: return "VALUE";
    case ExprDependence::ERROR: return "ERROR";
    case ExprDependence::NONE: return "NONE";
    case ExprDependence::ALL: return "ALL";
    case ExprDependence::TYPE_VALUE: return "TYPE_VALUE";
    case ExprDependence::TYPE_INSTANTIATION: return "TYPE_INSTANTIATION";
    case ExprDependence::VALUE_INSTANTIATION: return "VALUE_INSTANTIATION";
    case ExprDependence::TYPE_VALUE_INSTANTIATION: return "TYPE_VALUE_INSTANTIATION";
    case ExprDependence::ERROR_DEPENDENT: return "ERROR_DEPENDENT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
