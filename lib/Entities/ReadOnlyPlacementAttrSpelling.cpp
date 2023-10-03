// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ReadOnlyPlacementAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReadOnlyPlacementAttrSpelling e) {
  switch (e) {
    case ReadOnlyPlacementAttrSpelling::GNU_ENFORCE_READ_ONLY_PLACEMENT: return "GNU_ENFORCE_READ_ONLY_PLACEMENT";
    case ReadOnlyPlacementAttrSpelling::CXX11_CLANG_ENFORCE_READ_ONLY_PLACEMENT: return "CXX11_CLANG_ENFORCE_READ_ONLY_PLACEMENT";
    case ReadOnlyPlacementAttrSpelling::C23_CLANG_ENFORCE_READ_ONLY_PLACEMENT: return "C23_CLANG_ENFORCE_READ_ONLY_PLACEMENT";
    case ReadOnlyPlacementAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
