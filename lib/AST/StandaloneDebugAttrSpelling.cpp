// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/StandaloneDebugAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(StandaloneDebugAttrSpelling e) {
  switch (e) {
    case StandaloneDebugAttrSpelling::GNU_STANDALONE_DEBUG: return "GNU_STANDALONE_DEBUG";
    case StandaloneDebugAttrSpelling::CXX11_CLANG_STANDALONE_DEBUG: return "CXX11_CLANG_STANDALONE_DEBUG";
    case StandaloneDebugAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
