// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OpenCLGlobalDeviceAddressSpaceAttrSpelling : unsigned char {
  GNU_OPENCL_GLOBAL_DEVICE,
  CXX11_CLANG_OPENCL_GLOBAL_DEVICE,
  C23_CLANG_OPENCL_GLOBAL_DEVICE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLGlobalDeviceAddressSpaceAttrSpelling) {
  return "OpenCLGlobalDeviceAddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLGlobalDeviceAddressSpaceAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(OpenCLGlobalDeviceAddressSpaceAttrSpelling);

} // namespace mx
