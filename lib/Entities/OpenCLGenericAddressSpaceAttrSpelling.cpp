// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/OpenCLGenericAddressSpaceAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLGenericAddressSpaceAttrSpelling e) {
  switch (e) {
    case OpenCLGenericAddressSpaceAttrSpelling::KEYWORD_GENERIC: return "KEYWORD_GENERIC";
    case OpenCLGenericAddressSpaceAttrSpelling::GNU_OPENCL_GENERIC: return "GNU_OPENCL_GENERIC";
    case OpenCLGenericAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_GENERIC: return "CXX11_CLANG_OPENCL_GENERIC";
    case OpenCLGenericAddressSpaceAttrSpelling::C23_CLANG_OPENCL_GENERIC: return "C23_CLANG_OPENCL_GENERIC";
    case OpenCLGenericAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
