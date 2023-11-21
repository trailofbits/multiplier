// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoDuplicateAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoDuplicateAttrSpelling e) {
  switch (e) {
    case NoDuplicateAttrSpelling::GNU_NODUPLICATE: return "GNU_NODUPLICATE";
    case NoDuplicateAttrSpelling::CXX11_CLANG_NODUPLICATE: return "CXX11_CLANG_NODUPLICATE";
    case NoDuplicateAttrSpelling::C2X_CLANG_NODUPLICATE: return "C2X_CLANG_NODUPLICATE";
    case NoDuplicateAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
