// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ObjCBridgeCastKind : unsigned char {
  BRIDGE,
  BRIDGE_TRANSFER,
  BRIDGE_RETAINED,
};

inline static const char *EnumerationName(ObjCBridgeCastKind) {
  return "ObjCBridgeCastKind";
}

inline static constexpr unsigned NumEnumerators(ObjCBridgeCastKind) {
  return 3;
}

const char *EnumeratorName(ObjCBridgeCastKind);

} // namespace mx
