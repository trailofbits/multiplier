// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CUDADeviceBuiltinTextureTypeAttrSpelling : unsigned char {
  GNU_DEVICE_BUILTIN_TEXTURE_TYPE,
  DECLSPEC_DEVICE_BUILTIN_TEXTURE_TYPE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CUDADeviceBuiltinTextureTypeAttrSpelling) {
  return "CUDADeviceBuiltinTextureTypeAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CUDADeviceBuiltinTextureTypeAttrSpelling) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CUDADeviceBuiltinTextureTypeAttrSpelling);

} // namespace mx
