// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ArcWeakrefUnavailableAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ArcWeakrefUnavailableAttrSpelling e) {
  switch (e) {
    case ArcWeakrefUnavailableAttrSpelling::GNU_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE: return "GNU_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE";
    case ArcWeakrefUnavailableAttrSpelling::CXX11_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE: return "CXX11_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE";
    case ArcWeakrefUnavailableAttrSpelling::C23_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE: return "C23_CLANG_OBJC_ARC_WEAK_REFERENCE_UNAVAILABLE";
    case ArcWeakrefUnavailableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
