// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenCLGlobalAddressSpaceAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLGlobalAddressSpaceAttrSpelling e) {
  switch (e) {
    case OpenCLGlobalAddressSpaceAttrSpelling::KEYWORD_GLOBAL: return "KEYWORD_GLOBAL";
    case OpenCLGlobalAddressSpaceAttrSpelling::GNU_OPENCL_GLOBAL: return "GNU_OPENCL_GLOBAL";
    case OpenCLGlobalAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GLOBAL: return "CXX11_CLANG_OPENCL_GLOBAL";
    case OpenCLGlobalAddressSpaceAttrSpelling::C23_CLANG_OPENCL_GLOBAL: return "C23_CLANG_OPENCL_GLOBAL";
    case OpenCLGlobalAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
