// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ExcludeFromExplicitInstantiationAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ExcludeFromExplicitInstantiationAttrSpelling e) {
  switch (e) {
    case ExcludeFromExplicitInstantiationAttrSpelling::GNU_EXCLUDE_FROM_EXPLICIT_INSTANTIATION: return "GNU_EXCLUDE_FROM_EXPLICIT_INSTANTIATION";
    case ExcludeFromExplicitInstantiationAttrSpelling::CXX11_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION: return "CXX11_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION";
    case ExcludeFromExplicitInstantiationAttrSpelling::C23_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION: return "C23_CLANG_EXCLUDE_FROM_EXPLICIT_INSTANTIATION";
    case ExcludeFromExplicitInstantiationAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
