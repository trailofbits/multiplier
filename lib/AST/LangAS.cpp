// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/LangAS.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(LangAS e) {
  switch (e) {
    case LangAS::DEFAULT: return "DEFAULT";
    case LangAS::OPENCL_GLOBAL: return "OPENCL_GLOBAL";
    case LangAS::OPENCL_LOCAL: return "OPENCL_LOCAL";
    case LangAS::OPENCL_CONSTANT: return "OPENCL_CONSTANT";
    case LangAS::OPENCL_PRIVATE: return "OPENCL_PRIVATE";
    case LangAS::OPENCL_GENERIC: return "OPENCL_GENERIC";
    case LangAS::OPENCL_GLOBAL_DEVICE: return "OPENCL_GLOBAL_DEVICE";
    case LangAS::OPENCL_GLOBAL_HOST: return "OPENCL_GLOBAL_HOST";
    case LangAS::CUDA_DEVICE: return "CUDA_DEVICE";
    case LangAS::CUDA_CONSTANT: return "CUDA_CONSTANT";
    case LangAS::CUDA_SHARED: return "CUDA_SHARED";
    case LangAS::SYCL_GLOBAL: return "SYCL_GLOBAL";
    case LangAS::SYCL_GLOBAL_DEVICE: return "SYCL_GLOBAL_DEVICE";
    case LangAS::SYCL_GLOBAL_HOST: return "SYCL_GLOBAL_HOST";
    case LangAS::SYCL_LOCAL: return "SYCL_LOCAL";
    case LangAS::SYCL_PRIVATE: return "SYCL_PRIVATE";
    case LangAS::PTR32_SPTR: return "PTR32_SPTR";
    case LangAS::PTR32_UPTR: return "PTR32_UPTR";
    case LangAS::PTR64: return "PTR64";
    case LangAS::HLSL_GROUPSHARED: return "HLSL_GROUPSHARED";
    case LangAS::WASM_FUNCREF: return "WASM_FUNCREF";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
