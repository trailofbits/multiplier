// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FlagEnumAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FlagEnumAttrSpelling e) {
  switch (e) {
    case FlagEnumAttrSpelling::GNU_FLAG_ENUM: return "GNU_FLAG_ENUM";
    case FlagEnumAttrSpelling::CXX11_CLANG_FLAG_ENUM: return "CXX11_CLANG_FLAG_ENUM";
    case FlagEnumAttrSpelling::C23_CLANG_FLAG_ENUM: return "C23_CLANG_FLAG_ENUM";
    case FlagEnumAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
