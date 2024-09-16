// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MaybeUndefAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MaybeUndefAttrSpelling e) {
  switch (e) {
    case MaybeUndefAttrSpelling::GNU_MAYBE_UNDEF: return "GNU_MAYBE_UNDEF";
    case MaybeUndefAttrSpelling::CXX11_CLANG_MAYBE_UNDEF: return "CXX11_CLANG_MAYBE_UNDEF";
    case MaybeUndefAttrSpelling::C23_CLANG_MAYBE_UNDEF: return "C23_CLANG_MAYBE_UNDEF";
    case MaybeUndefAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
