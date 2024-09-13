// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OpenCLPrivateAddressSpaceAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OpenCLPrivateAddressSpaceAttrSpelling e) {
  switch (e) {
    case OpenCLPrivateAddressSpaceAttrSpelling::KEYWORD_PRIVATE: return "KEYWORD_PRIVATE";
    case OpenCLPrivateAddressSpaceAttrSpelling::GNU_OPENCL_PRIVATE: return "GNU_OPENCL_PRIVATE";
    case OpenCLPrivateAddressSpaceAttrSpelling::CXX11_CLANG_OPENCL_PRIVATE: return "CXX11_CLANG_OPENCL_PRIVATE";
    case OpenCLPrivateAddressSpaceAttrSpelling::C23_CLANG_OPENCL_PRIVATE: return "C23_CLANG_OPENCL_PRIVATE";
    case OpenCLPrivateAddressSpaceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
