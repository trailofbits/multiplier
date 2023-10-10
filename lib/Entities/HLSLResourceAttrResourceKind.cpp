// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/HLSLResourceAttrResourceKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(HLSLResourceAttrResourceKind e) {
  switch (e) {
    case HLSLResourceAttrResourceKind::TEXTURE1_D: return "TEXTURE1_D";
    case HLSLResourceAttrResourceKind::TEXTURE2_D: return "TEXTURE2_D";
    case HLSLResourceAttrResourceKind::TEXTURE2_DMS: return "TEXTURE2_DMS";
    case HLSLResourceAttrResourceKind::TEXTURE3_D: return "TEXTURE3_D";
    case HLSLResourceAttrResourceKind::TEXTURE_CUBE: return "TEXTURE_CUBE";
    case HLSLResourceAttrResourceKind::TEXTURE1_D_ARRAY: return "TEXTURE1_D_ARRAY";
    case HLSLResourceAttrResourceKind::TEXTURE2_D_ARRAY: return "TEXTURE2_D_ARRAY";
    case HLSLResourceAttrResourceKind::TEXTURE2_DMS_ARRAY: return "TEXTURE2_DMS_ARRAY";
    case HLSLResourceAttrResourceKind::TEXTURE_CUBE_ARRAY: return "TEXTURE_CUBE_ARRAY";
    case HLSLResourceAttrResourceKind::TYPED_BUFFER: return "TYPED_BUFFER";
    case HLSLResourceAttrResourceKind::RAW_BUFFER: return "RAW_BUFFER";
    case HLSLResourceAttrResourceKind::STRUCTURED_BUFFER: return "STRUCTURED_BUFFER";
    case HLSLResourceAttrResourceKind::C_BUFFER_KIND: return "C_BUFFER_KIND";
    case HLSLResourceAttrResourceKind::SAMPLER_KIND: return "SAMPLER_KIND";
    case HLSLResourceAttrResourceKind::T_BUFFER: return "T_BUFFER";
    case HLSLResourceAttrResourceKind::RT_ACCELERATION_STRUCTURE: return "RT_ACCELERATION_STRUCTURE";
    case HLSLResourceAttrResourceKind::FEEDBACK_TEXTURE2_D: return "FEEDBACK_TEXTURE2_D";
    case HLSLResourceAttrResourceKind::FEEDBACK_TEXTURE2_D_ARRAY: return "FEEDBACK_TEXTURE2_D_ARRAY";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
