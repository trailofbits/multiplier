// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CUDADeviceBuiltinSurfaceTypeAttrSpelling : unsigned char {
  GNU_DEVICE_BUILTIN_SURFACE_TYPE,
  DECLSPEC_DEVICE_BUILTIN_SURFACE_TYPE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CUDADeviceBuiltinSurfaceTypeAttrSpelling) {
  return "CUDADeviceBuiltinSurfaceTypeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CUDADeviceBuiltinSurfaceTypeAttrSpelling) {
  return 3;
}

const char *EnumeratorName(CUDADeviceBuiltinSurfaceTypeAttrSpelling);

} // namespace mx
