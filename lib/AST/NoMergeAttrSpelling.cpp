// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NoMergeAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NoMergeAttrSpelling e) {
  switch (e) {
    case NoMergeAttrSpelling::GNU_NOMERGE: return "GNU_NOMERGE";
    case NoMergeAttrSpelling::CXX11_CLANG_NOMERGE: return "CXX11_CLANG_NOMERGE";
    case NoMergeAttrSpelling::C23_CLANG_NOMERGE: return "C23_CLANG_NOMERGE";
    case NoMergeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
