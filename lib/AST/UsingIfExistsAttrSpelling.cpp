// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/UsingIfExistsAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UsingIfExistsAttrSpelling e) {
  switch (e) {
    case UsingIfExistsAttrSpelling::GNU_USING_IF_EXISTS: return "GNU_USING_IF_EXISTS";
    case UsingIfExistsAttrSpelling::CXX11_CLANG_USING_IF_EXISTS: return "CXX11_CLANG_USING_IF_EXISTS";
    case UsingIfExistsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
