// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenCLLocalAddressSpaceAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLLocalAddressSpaceAttrSpelling e) {
  switch (e) {
    case OpenCLLocalAddressSpaceAttrSpelling::KEYWORD_LOCAL: return "KEYWORD_LOCAL";
    case OpenCLLocalAddressSpaceAttrSpelling::GNU_OPENCL_LOCAL: return "GNU_OPENCL_LOCAL";
    case OpenCLLocalAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_LOCAL: return "CXX11_CLANG_OPENCL_LOCAL";
    case OpenCLLocalAddressSpaceAttrSpelling::C2X_CLANG_OPENCL_LOCAL: return "C2X_CLANG_OPENCL_LOCAL";
    case OpenCLLocalAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
