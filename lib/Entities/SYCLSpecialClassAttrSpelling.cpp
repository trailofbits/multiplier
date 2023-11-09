// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SYCLSpecialClassAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SYCLSpecialClassAttrSpelling e) {
  switch (e) {
    case SYCLSpecialClassAttrSpelling::GNU_SYCL_SPECIAL_CLASS: return "GNU_SYCL_SPECIAL_CLASS";
    case SYCLSpecialClassAttrSpelling::CXX11_CLANG_SYCL_SPECIAL_CLASS: return "CXX11_CLANG_SYCL_SPECIAL_CLASS";
    case SYCLSpecialClassAttrSpelling::C2X_CLANG_SYCL_SPECIAL_CLASS: return "C2X_CLANG_SYCL_SPECIAL_CLASS";
    case SYCLSpecialClassAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
