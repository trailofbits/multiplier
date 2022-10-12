// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class PcsAttrPCSType : unsigned char {
  AAPCS,
  VFP,
};

inline static const char *EnumerationName(PcsAttrPCSType) {
  return "PcsAttrPCSType";
}

inline static constexpr unsigned NumEnumerators(PcsAttrPCSType) {
  return 2;
}

const char *EnumeratorName(PcsAttrPCSType);

} // namespace mx
