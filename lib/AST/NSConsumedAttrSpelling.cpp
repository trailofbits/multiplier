// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NSConsumedAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NSConsumedAttrSpelling e) {
  switch (e) {
    case NSConsumedAttrSpelling::GNU_NS_CONSUMED: return "GNU_NS_CONSUMED";
    case NSConsumedAttrSpelling::CXX11_CLANG_NS_CONSUMED: return "CXX11_CLANG_NS_CONSUMED";
    case NSConsumedAttrSpelling::C2X_CLANG_NS_CONSUMED: return "C2X_CLANG_NS_CONSUMED";
    case NSConsumedAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
