// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ErrorAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ErrorAttrSpelling e) {
  switch (e) {
    case ErrorAttrSpelling::GNU_ERROR: return "GNU_ERROR";
    case ErrorAttrSpelling::CXX11_GNU_ERROR: return "CXX11_GNU_ERROR";
    case ErrorAttrSpelling::C23_GNU_ERROR: return "C23_GNU_ERROR";
    case ErrorAttrSpelling::GNU_WARNING: return "GNU_WARNING";
    case ErrorAttrSpelling::CXX11_GNU_WARNING: return "CXX11_GNU_WARNING";
    case ErrorAttrSpelling::C23_GNU_WARNING: return "C23_GNU_WARNING";
    case ErrorAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
