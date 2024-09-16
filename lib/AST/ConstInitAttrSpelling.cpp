// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConstInitAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ConstInitAttrSpelling e) {
  switch (e) {
    case ConstInitAttrSpelling::KEYWORD_CONSTINIT: return "KEYWORD_CONSTINIT";
    case ConstInitAttrSpelling::GNU_REQUIRE_CONSTANT_INITIALIZATION: return "GNU_REQUIRE_CONSTANT_INITIALIZATION";
    case ConstInitAttrSpelling::CXX11_CLANG_REQUIRE_CONSTANT_INITIALIZATION: return "CXX11_CLANG_REQUIRE_CONSTANT_INITIALIZATION";
    case ConstInitAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
