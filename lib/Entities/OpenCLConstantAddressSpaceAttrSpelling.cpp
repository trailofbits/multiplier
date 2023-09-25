// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenCLConstantAddressSpaceAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLConstantAddressSpaceAttrSpelling e) {
  switch (e) {
    case OpenCLConstantAddressSpaceAttrSpelling::KEYWORD_CONSTANT: return "KEYWORD_CONSTANT";
    case OpenCLConstantAddressSpaceAttrSpelling::GNU_OPENCL_CONSTANT: return "GNU_OPENCL_CONSTANT";
    case OpenCLConstantAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_CONSTANT: return "CXX11_CLANG_OPENCL_CONSTANT";
    case OpenCLConstantAddressSpaceAttrSpelling::C23_CLANG_OPENCL_CONSTANT: return "C23_CLANG_OPENCL_CONSTANT";
    case OpenCLConstantAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
