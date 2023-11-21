// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class LaxVectorConversionKind : unsigned char {
  NONE,
  INTEGER,
  ALL,
};

inline static const char *EnumerationName(LaxVectorConversionKind) {
  return "LaxVectorConversionKind";
}

inline static constexpr unsigned NumEnumerators(LaxVectorConversionKind) {
  return 3;
}

const char *EnumeratorName(LaxVectorConversionKind);

} // namespace mx
