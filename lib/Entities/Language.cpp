// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/Language.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(Language e) {
  switch (e) {
    case Language::UNKNOWN: return "UNKNOWN";
    case Language::ASSEMBLY: return "ASSEMBLY";
    case Language::LLVMIR: return "LLVMIR";
    case Language::C: return "C";
    case Language::CXX: return "CXX";
    case Language::OBJ_C: return "OBJ_C";
    case Language::OBJ_CXX: return "OBJ_CXX";
    case Language::OPEN_CL: return "OPEN_CL";
    case Language::OPEN_CLCXX: return "OPEN_CLCXX";
    case Language::CUDA: return "CUDA";
    case Language::RENDER_SCRIPT: return "RENDER_SCRIPT";
    case Language::HIP: return "HIP";
    case Language::HLSL: return "HLSL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
