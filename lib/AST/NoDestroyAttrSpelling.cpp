// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoDestroyAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoDestroyAttrSpelling e) {
  switch (e) {
    case NoDestroyAttrSpelling::GNU_NO_DESTROY: return "GNU_NO_DESTROY";
    case NoDestroyAttrSpelling::CXX11_CLANG_NO_DESTROY: return "CXX11_CLANG_NO_DESTROY";
    case NoDestroyAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
