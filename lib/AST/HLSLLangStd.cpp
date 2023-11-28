// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/HLSLLangStd.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(HLSLLangStd e) {
  switch (e) {
    case HLSLLangStd::HLSL_UNSET: return "HLSL_UNSET";
    case HLSLLangStd::HLSL2015: return "HLSL2015";
    case HLSLLangStd::HLSL2016: return "HLSL2016";
    case HLSLLangStd::HLSL2017: return "HLSL2017";
    case HLSLLangStd::HLSL2018: return "HLSL2018";
    case HLSLLangStd::HLSL2021: return "HLSL2021";
    case HLSLLangStd::HLSL202X: return "HLSL202X";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
