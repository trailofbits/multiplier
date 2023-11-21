// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ShaderStage.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ShaderStage e) {
  switch (e) {
    case ShaderStage::PIXEL: return "PIXEL";
    case ShaderStage::VERTEX: return "VERTEX";
    case ShaderStage::GEOMETRY: return "GEOMETRY";
    case ShaderStage::HULL: return "HULL";
    case ShaderStage::DOMAIN_: return "DOMAIN_";
    case ShaderStage::COMPUTE: return "COMPUTE";
    case ShaderStage::LIBRARY: return "LIBRARY";
    case ShaderStage::RAY_GENERATION: return "RAY_GENERATION";
    case ShaderStage::INTERSECTION: return "INTERSECTION";
    case ShaderStage::ANY_HIT: return "ANY_HIT";
    case ShaderStage::CLOSEST_HIT: return "CLOSEST_HIT";
    case ShaderStage::MISS: return "MISS";
    case ShaderStage::CALLABLE: return "CALLABLE";
    case ShaderStage::MESH: return "MESH";
    case ShaderStage::AMPLIFICATION: return "AMPLIFICATION";
    case ShaderStage::INVALID: return "INVALID";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
