// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/RandomizeLayoutAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(RandomizeLayoutAttrSpelling e) {
  switch (e) {
    case RandomizeLayoutAttrSpelling::GNU_RANDOMIZE_LAYOUT: return "GNU_RANDOMIZE_LAYOUT";
    case RandomizeLayoutAttrSpelling::CXX11_GNU_RANDOMIZE_LAYOUT: return "CXX11_GNU_RANDOMIZE_LAYOUT";
    case RandomizeLayoutAttrSpelling::C23_GNU_RANDOMIZE_LAYOUT: return "C23_GNU_RANDOMIZE_LAYOUT";
    case RandomizeLayoutAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
