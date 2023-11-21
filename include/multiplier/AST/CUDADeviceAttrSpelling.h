// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CUDADeviceAttrSpelling : unsigned char {
  GNU_DEVICE,
  DECLSPEC_DEVICE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CUDADeviceAttrSpelling) {
  return "CUDADeviceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CUDADeviceAttrSpelling) {
  return 3;
}

const char *EnumeratorName(CUDADeviceAttrSpelling);

} // namespace mx
