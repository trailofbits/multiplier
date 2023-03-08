// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenCLGlobalDeviceAddressSpaceAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLGlobalDeviceAddressSpaceAttrSpelling e) {
  switch (e) {
    case OpenCLGlobalDeviceAddressSpaceAttrSpelling::GNU_OPENCL_GLOBAL_DEVICE: return "GNU_OPENCL_GLOBAL_DEVICE";
    case OpenCLGlobalDeviceAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GLOBAL_DEVICE: return "CXX11_CLANG_OPENCL_GLOBAL_DEVICE";
    case OpenCLGlobalDeviceAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_GLOBAL_DEVICE: return "C2X_CLANG_OPENCL_GLOBAL_DEVICE";
    case OpenCLGlobalDeviceAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
