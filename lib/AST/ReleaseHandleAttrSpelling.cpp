// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ReleaseHandleAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReleaseHandleAttrSpelling e) {
  switch (e) {
    case ReleaseHandleAttrSpelling::GNU_RELEASE_HANDLE: return "GNU_RELEASE_HANDLE";
    case ReleaseHandleAttrSpelling::CXX11_CLANG_RELEASE_HANDLE: return "CXX11_CLANG_RELEASE_HANDLE";
    case ReleaseHandleAttrSpelling::C23_CLANG_RELEASE_HANDLE: return "C23_CLANG_RELEASE_HANDLE";
    case ReleaseHandleAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
