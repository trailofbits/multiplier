// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OSConsumedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OSConsumedAttrSpelling e) {
  switch (e) {
    case OSConsumedAttrSpelling::GNU_OS_CONSUMED: return "GNU_OS_CONSUMED";
    case OSConsumedAttrSpelling::CXX11_CLANG_OS_CONSUMED: return "CXX11_CLANG_OS_CONSUMED";
    case OSConsumedAttrSpelling::C23_CLANG_OS_CONSUMED: return "C23_CLANG_OS_CONSUMED";
    case OSConsumedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
