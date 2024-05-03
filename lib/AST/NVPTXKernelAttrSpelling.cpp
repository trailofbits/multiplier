// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NVPTXKernelAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(NVPTXKernelAttrSpelling e) {
  switch (e) {
    case NVPTXKernelAttrSpelling::GNU_NVPTX_KERNEL: return "GNU_NVPTX_KERNEL";
    case NVPTXKernelAttrSpelling::CXX11_CLANG_NVPTX_KERNEL: return "CXX11_CLANG_NVPTX_KERNEL";
    case NVPTXKernelAttrSpelling::C23_CLANG_NVPTX_KERNEL: return "C23_CLANG_NVPTX_KERNEL";
    case NVPTXKernelAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
