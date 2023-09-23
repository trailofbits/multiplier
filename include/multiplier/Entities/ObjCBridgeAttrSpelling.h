// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCBridgeAttrSpelling : unsigned char {
  GNU_OBJC_BRIDGE,
  CXX11_CLANG_OBJC_BRIDGE,
  C23_CLANG_OBJC_BRIDGE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ObjCBridgeAttrSpelling) {
  return "ObjCBridgeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ObjCBridgeAttrSpelling) {
  return 4;
}

const char *EnumeratorName(ObjCBridgeAttrSpelling);

} // namespace mx
