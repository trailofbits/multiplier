// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/TrivialABIAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(TrivialABIAttrSpelling e) {
  switch (e) {
    case TrivialABIAttrSpelling::GNU_TRIVIAL_ABI: return "GNU_TRIVIAL_ABI";
    case TrivialABIAttrSpelling::CXX11_CLANG_TRIVIAL_ABI: return "CXX11_CLANG_TRIVIAL_ABI";
    case TrivialABIAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
