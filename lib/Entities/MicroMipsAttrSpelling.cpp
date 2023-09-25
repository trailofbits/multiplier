// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MicroMipsAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MicroMipsAttrSpelling e) {
  switch (e) {
    case MicroMipsAttrSpelling::GNU_MICROMIPS: return "GNU_MICROMIPS";
    case MicroMipsAttrSpelling::CXX11_GNU_MICROMIPS: return "CXX11_GNU_MICROMIPS";
    case MicroMipsAttrSpelling::C23_GNU_MICROMIPS: return "C23_GNU_MICROMIPS";
    case MicroMipsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
