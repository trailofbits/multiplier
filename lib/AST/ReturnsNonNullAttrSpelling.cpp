// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ReturnsNonNullAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReturnsNonNullAttrSpelling e) {
  switch (e) {
    case ReturnsNonNullAttrSpelling::GNU_RETURNS_NONNULL: return "GNU_RETURNS_NONNULL";
    case ReturnsNonNullAttrSpelling::CXX11_GNU_RETURNS_NONNULL: return "CXX11_GNU_RETURNS_NONNULL";
    case ReturnsNonNullAttrSpelling::C23_GNU_RETURNS_NONNULL: return "C23_GNU_RETURNS_NONNULL";
    case ReturnsNonNullAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
