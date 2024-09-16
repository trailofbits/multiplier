// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OMPDeclareTargetDeclAttrMapTypeTy : unsigned char {
  TO,
  ENTER,
  LINK,
};

inline static const char *EnumerationName(OMPDeclareTargetDeclAttrMapTypeTy) {
  return "OMPDeclareTargetDeclAttrMapTypeTy";
}

inline static constexpr unsigned NumEnumerators(OMPDeclareTargetDeclAttrMapTypeTy) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(OMPDeclareTargetDeclAttrMapTypeTy);

} // namespace mx
