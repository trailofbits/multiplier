// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AlignedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AlignedAttrSpelling e) {
  switch (e) {
    case AlignedAttrSpelling::GNU_ALIGNED: return "GNU_ALIGNED";
    case AlignedAttrSpelling::CXX11_GNU_ALIGNED: return "CXX11_GNU_ALIGNED";
    case AlignedAttrSpelling::C23_GNU_ALIGNED: return "C23_GNU_ALIGNED";
    case AlignedAttrSpelling::DECLSPEC_ALIGN: return "DECLSPEC_ALIGN";
    case AlignedAttrSpelling::KEYWORD_ALIGNAS: return "KEYWORD_ALIGNAS";
    case AlignedAttrSpelling::KEYWORD__ALIGNAS: return "KEYWORD__ALIGNAS";
    case AlignedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
