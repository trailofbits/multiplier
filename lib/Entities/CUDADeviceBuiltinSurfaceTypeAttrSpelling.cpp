// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CUDADeviceBuiltinSurfaceTypeAttrSpelling.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CUDADeviceBuiltinSurfaceTypeAttrSpelling e) {
  switch (e) {
    case CUDADeviceBuiltinSurfaceTypeAttrSpelling::GNU_DEVICE_BUILTIN_SURFACE_TYPE: return "GNU_DEVICE_BUILTIN_SURFACE_TYPE";
    case CUDADeviceBuiltinSurfaceTypeAttrSpelling::DECLSPEC_DEVICE_BUILTIN_SURFACE_TYPE: return "DECLSPEC_DEVICE_BUILTIN_SURFACE_TYPE";
    case CUDADeviceBuiltinSurfaceTypeAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
