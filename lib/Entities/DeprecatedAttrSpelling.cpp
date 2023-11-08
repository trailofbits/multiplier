// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DeprecatedAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DeprecatedAttrSpelling e) {
  switch (e) {
    case DeprecatedAttrSpelling::GNU_DEPRECATED: return "GNU_DEPRECATED";
    case DeprecatedAttrSpelling::CXX11_GNU_DEPRECATED: return "CXX11_GNU_DEPRECATED";
    case DeprecatedAttrSpelling::C23_GNU_DEPRECATED: return "C23_GNU_DEPRECATED";
    case DeprecatedAttrSpelling::DECLSPEC_DEPRECATED: return "DECLSPEC_DEPRECATED";
    case DeprecatedAttrSpelling::CXX11_DEPRECATED: return "CXX11_DEPRECATED";
    case DeprecatedAttrSpelling::C23_DEPRECATED: return "C23_DEPRECATED";
    case DeprecatedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
