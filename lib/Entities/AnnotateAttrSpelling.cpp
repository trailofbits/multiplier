// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AnnotateAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AnnotateAttrSpelling e) {
  switch (e) {
    case AnnotateAttrSpelling::GNU_ANNOTATE: return "GNU_ANNOTATE";
    case AnnotateAttrSpelling::CXX11_CLANG_ANNOTATE: return "CXX11_CLANG_ANNOTATE";
    case AnnotateAttrSpelling::C2X_CLANG_ANNOTATE: return "C2X_CLANG_ANNOTATE";
    case AnnotateAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
