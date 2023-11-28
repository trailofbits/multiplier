// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CarriesDependencyAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CarriesDependencyAttrSpelling e) {
  switch (e) {
    case CarriesDependencyAttrSpelling::GNU_CARRIES_DEPENDENCY: return "GNU_CARRIES_DEPENDENCY";
    case CarriesDependencyAttrSpelling::CXX11_CARRIES_DEPENDENCY: return "CXX11_CARRIES_DEPENDENCY";
    case CarriesDependencyAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
