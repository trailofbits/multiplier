// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LoaderUninitializedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LoaderUninitializedAttrSpelling e) {
  switch (e) {
    case LoaderUninitializedAttrSpelling::GNU_LOADER_UNINITIALIZED: return "GNU_LOADER_UNINITIALIZED";
    case LoaderUninitializedAttrSpelling::CXX11_CLANG_LOADER_UNINITIALIZED: return "CXX11_CLANG_LOADER_UNINITIALIZED";
    case LoaderUninitializedAttrSpelling::C2X_CLANG_LOADER_UNINITIALIZED: return "C2X_CLANG_LOADER_UNINITIALIZED";
    case LoaderUninitializedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
