// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/BPFPreserveAccessIndexAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(BPFPreserveAccessIndexAttrSpelling e) {
  switch (e) {
    case BPFPreserveAccessIndexAttrSpelling::GNU_PRESERVE_ACCESS_INDEX: return "GNU_PRESERVE_ACCESS_INDEX";
    case BPFPreserveAccessIndexAttrSpelling::CXX11_CLANG_PRESERVE_ACCESS_INDEX: return "CXX11_CLANG_PRESERVE_ACCESS_INDEX";
    case BPFPreserveAccessIndexAttrSpelling::C2X_CLANG_PRESERVE_ACCESS_INDEX: return "C2X_CLANG_PRESERVE_ACCESS_INDEX";
    case BPFPreserveAccessIndexAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
