// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MSABIAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MSABIAttrSpelling e) {
  switch (e) {
    case MSABIAttrSpelling::GNU_MS_ABI: return "GNU_MS_ABI";
    case MSABIAttrSpelling::CXX11_GNU_MS_ABI: return "CXX11_GNU_MS_ABI";
    case MSABIAttrSpelling::C23_GNU_MS_ABI: return "C23_GNU_MS_ABI";
    case MSABIAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
