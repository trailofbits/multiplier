// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SYCLKernelAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SYCLKernelAttrSpelling e) {
  switch (e) {
    case SYCLKernelAttrSpelling::GNU_SYCL_KERNEL: return "GNU_SYCL_KERNEL";
    case SYCLKernelAttrSpelling::CXX11_CLANG_SYCL_KERNEL: return "CXX11_CLANG_SYCL_KERNEL";
    case SYCLKernelAttrSpelling::C23_CLANG_SYCL_KERNEL: return "C23_CLANG_SYCL_KERNEL";
    case SYCLKernelAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
