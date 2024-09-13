// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OMPDeclareTargetDeclAttrDevTypeTy : unsigned char {
  HOST,
  NO_HOST,
  ANY,
};

inline static const char *EnumerationName(OMPDeclareTargetDeclAttrDevTypeTy) {
  return "OMPDeclareTargetDeclAttrDevTypeTy";
}

inline static constexpr unsigned NumEnumerators(OMPDeclareTargetDeclAttrDevTypeTy) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(OMPDeclareTargetDeclAttrDevTypeTy);

} // namespace mx
