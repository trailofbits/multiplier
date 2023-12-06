// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class HLSLResourceAttrResourceKind : unsigned char {
  TEXTURE1_D,
  TEXTURE2_D,
  TEXTURE2_DMS,
  TEXTURE3_D,
  TEXTURE_CUBE,
  TEXTURE1_D_ARRAY,
  TEXTURE2_D_ARRAY,
  TEXTURE2_DMS_ARRAY,
  TEXTURE_CUBE_ARRAY,
  TYPED_BUFFER,
  RAW_BUFFER,
  STRUCTURED_BUFFER,
  C_BUFFER_KIND,
  SAMPLER_KIND,
  T_BUFFER,
  RT_ACCELERATION_STRUCTURE,
  FEEDBACK_TEXTURE2_D,
  FEEDBACK_TEXTURE2_D_ARRAY,
};

inline static const char *EnumerationName(HLSLResourceAttrResourceKind) {
  return "HLSLResourceAttrResourceKind";
}

inline static constexpr unsigned NumEnumerators(HLSLResourceAttrResourceKind) {
  return 18;
}

MX_EXPORT const char *EnumeratorName(HLSLResourceAttrResourceKind);

} // namespace mx
