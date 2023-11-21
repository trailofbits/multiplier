// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BlocksAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(BlocksAttrSpelling e) {
  switch (e) {
    case BlocksAttrSpelling::GNU_BLOCKS: return "GNU_BLOCKS";
    case BlocksAttrSpelling::CXX11_CLANG_BLOCKS: return "CXX11_CLANG_BLOCKS";
    case BlocksAttrSpelling::C2X_CLANG_BLOCKS: return "C2X_CLANG_BLOCKS";
    case BlocksAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
