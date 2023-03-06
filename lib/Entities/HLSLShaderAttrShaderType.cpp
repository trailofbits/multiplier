// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/HLSLShaderAttrShaderType.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(HLSLShaderAttrShaderType e) {
  switch (e) {
    case HLSLShaderAttrShaderType::PIXEL: return "PIXEL";
    case HLSLShaderAttrShaderType::VERTEX: return "VERTEX";
    case HLSLShaderAttrShaderType::GEOMETRY: return "GEOMETRY";
    case HLSLShaderAttrShaderType::HULL: return "HULL";
    case HLSLShaderAttrShaderType::DOMAIN_: return "DOMAIN_";
    case HLSLShaderAttrShaderType::COMPUTE: return "COMPUTE";
    case HLSLShaderAttrShaderType::RAY_GENERATION: return "RAY_GENERATION";
    case HLSLShaderAttrShaderType::INTERSECTION: return "INTERSECTION";
    case HLSLShaderAttrShaderType::ANY_HIT: return "ANY_HIT";
    case HLSLShaderAttrShaderType::CLOSEST_HIT: return "CLOSEST_HIT";
    case HLSLShaderAttrShaderType::MISS: return "MISS";
    case HLSLShaderAttrShaderType::CALLABLE: return "CALLABLE";
    case HLSLShaderAttrShaderType::MESH: return "MESH";
    case HLSLShaderAttrShaderType::AMPLIFICATION: return "AMPLIFICATION";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
