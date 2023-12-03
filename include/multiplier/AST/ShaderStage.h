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
enum class ShaderStage : unsigned char {
  PIXEL,
  VERTEX,
  GEOMETRY,
  HULL,
  DOMAIN_,
  COMPUTE,
  LIBRARY,
  RAY_GENERATION,
  INTERSECTION,
  ANY_HIT,
  CLOSEST_HIT,
  MISS,
  CALLABLE,
  MESH,
  AMPLIFICATION,
  INVALID,
};

inline static const char *EnumerationName(ShaderStage) {
  return "ShaderStage";
}

inline static constexpr unsigned NumEnumerators(ShaderStage) {
  return 16;
}

MX_EXPORT const char *EnumeratorName(ShaderStage);

} // namespace mx
