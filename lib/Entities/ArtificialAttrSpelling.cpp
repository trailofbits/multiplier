// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ArtificialAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ArtificialAttrSpelling e) {
  switch (e) {
    case ArtificialAttrSpelling::GNU_ARTIFICIAL: return "GNU_ARTIFICIAL";
    case ArtificialAttrSpelling::CXX11_GNU_ARTIFICIAL: return "CXX11_GNU_ARTIFICIAL";
    case ArtificialAttrSpelling::C23_GNU_ARTIFICIAL: return "C23_GNU_ARTIFICIAL";
    case ArtificialAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
