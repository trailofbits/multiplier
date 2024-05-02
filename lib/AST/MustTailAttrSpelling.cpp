// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MustTailAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MustTailAttrSpelling e) {
  switch (e) {
    case MustTailAttrSpelling::GNU_MUSTTAIL: return "GNU_MUSTTAIL";
    case MustTailAttrSpelling::CXX11_CLANG_MUSTTAIL: return "CXX11_CLANG_MUSTTAIL";
    case MustTailAttrSpelling::C23_CLANG_MUSTTAIL: return "C23_CLANG_MUSTTAIL";
    case MustTailAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
