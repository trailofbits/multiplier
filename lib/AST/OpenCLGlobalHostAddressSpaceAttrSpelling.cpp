// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenCLGlobalHostAddressSpaceAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLGlobalHostAddressSpaceAttrSpelling e) {
  switch (e) {
    case OpenCLGlobalHostAddressSpaceAttrSpelling::GNU_OPENCL_GLOBAL_HOST: return "GNU_OPENCL_GLOBAL_HOST";
    case OpenCLGlobalHostAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GLOBAL_HOST: return "CXX11_CLANG_OPENCL_GLOBAL_HOST";
    case OpenCLGlobalHostAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_GLOBAL_HOST: return "C2X_CLANG_OPENCL_GLOBAL_HOST";
    case OpenCLGlobalHostAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
