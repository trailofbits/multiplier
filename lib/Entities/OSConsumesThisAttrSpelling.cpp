// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OSConsumesThisAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OSConsumesThisAttrSpelling e) {
  switch (e) {
    case OSConsumesThisAttrSpelling::GNU_OS_CONSUMES_THIS: return "GNU_OS_CONSUMES_THIS";
    case OSConsumesThisAttrSpelling::CXX11_CLANG_OS_CONSUMES_THIS: return "CXX11_CLANG_OS_CONSUMES_THIS";
    case OSConsumesThisAttrSpelling::C2X_CLANG_OS_CONSUMES_THIS: return "C2X_CLANG_OS_CONSUMES_THIS";
    case OSConsumesThisAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
