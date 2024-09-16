// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AvailabilityAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AvailabilityAttrSpelling e) {
  switch (e) {
    case AvailabilityAttrSpelling::GNU_AVAILABILITY: return "GNU_AVAILABILITY";
    case AvailabilityAttrSpelling::CXX11_CLANG_AVAILABILITY: return "CXX11_CLANG_AVAILABILITY";
    case AvailabilityAttrSpelling::C23_CLANG_AVAILABILITY: return "C23_CLANG_AVAILABILITY";
    case AvailabilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
