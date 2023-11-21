// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoMicroMipsAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoMicroMipsAttrSpelling e) {
  switch (e) {
    case NoMicroMipsAttrSpelling::GNU_NOMICROMIPS: return "GNU_NOMICROMIPS";
    case NoMicroMipsAttrSpelling::CXX11_GNU_NOMICROMIPS: return "CXX11_GNU_NOMICROMIPS";
    case NoMicroMipsAttrSpelling::C2X_GNU_NOMICROMIPS: return "C2X_GNU_NOMICROMIPS";
    case NoMicroMipsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
