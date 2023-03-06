// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/EnumExtensibilityAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(EnumExtensibilityAttrSpelling e) {
  switch (e) {
    case EnumExtensibilityAttrSpelling::GNU_ENUM_EXTENSIBILITY: return "GNU_ENUM_EXTENSIBILITY";
    case EnumExtensibilityAttrSpelling::CXX11_CLANG_ENUM_EXTENSIBILITY: return "CXX11_CLANG_ENUM_EXTENSIBILITY";
    case EnumExtensibilityAttrSpelling::C2X_CLANG_ENUM_EXTENSIBILITY: return "C2X_CLANG_ENUM_EXTENSIBILITY";
    case EnumExtensibilityAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
