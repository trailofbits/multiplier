// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/FormatArgAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FormatArgAttrSpelling e) {
  switch (e) {
    case FormatArgAttrSpelling::GNU_FORMAT_ARGUMENT: return "GNU_FORMAT_ARGUMENT";
    case FormatArgAttrSpelling::CXX11_GNU_FORMAT_ARGUMENT: return "CXX11_GNU_FORMAT_ARGUMENT";
    case FormatArgAttrSpelling::C2X_GNU_FORMAT_ARGUMENT: return "C2X_GNU_FORMAT_ARGUMENT";
    case FormatArgAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
