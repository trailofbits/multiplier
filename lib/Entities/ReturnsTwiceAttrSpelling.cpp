// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ReturnsTwiceAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReturnsTwiceAttrSpelling e) {
  switch (e) {
    case ReturnsTwiceAttrSpelling::GNU_RETURNS_TWICE: return "GNU_RETURNS_TWICE";
    case ReturnsTwiceAttrSpelling::CXX11_GNU_RETURNS_TWICE: return "CXX11_GNU_RETURNS_TWICE";
    case ReturnsTwiceAttrSpelling::C23_GNU_RETURNS_TWICE: return "C23_GNU_RETURNS_TWICE";
    case ReturnsTwiceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
