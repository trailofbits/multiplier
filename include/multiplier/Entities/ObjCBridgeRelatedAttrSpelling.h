// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCBridgeRelatedAttrSpelling : unsigned char {
  GNU_OBJC_BRIDGE_RELATED,
  CXX11_CLANG_OBJC_BRIDGE_RELATED,
  C23_CLANG_OBJC_BRIDGE_RELATED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCBridgeRelatedAttrSpelling) {
  return "ObjCBridgeRelatedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCBridgeRelatedAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCBridgeRelatedAttrSpelling);

} // namespace mx
