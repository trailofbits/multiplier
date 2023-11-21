// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class HLSLLangStd : unsigned char {
  HLSL_UNSET,
  HLSL2015,
  HLSL2016,
  HLSL2017,
  HLSL2018,
  HLSL2021,
  HLSL202X,
};

inline static const char *EnumerationName(HLSLLangStd) {
  return "HLSLLangStd";
}

inline static constexpr unsigned NumEnumerators(HLSLLangStd) {
  return 7;
}

const char *EnumeratorName(HLSLLangStd);

} // namespace mx
