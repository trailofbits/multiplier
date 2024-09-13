// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CUDADeviceAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CUDADeviceAttrSpelling e) {
  switch (e) {
    case CUDADeviceAttrSpelling::GNU_DEVICE: return "GNU_DEVICE";
    case CUDADeviceAttrSpelling::DECLSPEC_DEVICE: return "DECLSPEC_DEVICE";
    case CUDADeviceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
