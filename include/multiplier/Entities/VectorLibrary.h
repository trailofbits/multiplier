// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class VectorLibrary : unsigned char {
  NO_LIBRARY,
  ACCELERATE,
  LIBMVEC,
  MASSV,
  SVML,
  DARWIN_LIBSYSTEM_M,
};

inline static const char *EnumerationName(VectorLibrary) {
  return "VectorLibrary";
}

inline static constexpr unsigned NumEnumerators(VectorLibrary) {
  return 6;
}

const char *EnumeratorName(VectorLibrary);

} // namespace mx
