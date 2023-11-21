// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ReleaseCapabilityAttrSpelling : unsigned char {
  GNU_RELEASE_CAPABILITY,
  CXX11_CLANG_RELEASE_CAPABILITY,
  GNU_RELEASE_SHARED_CAPABILITY,
  CXX11_CLANG_RELEASE_SHARED_CAPABILITY,
  GNU_RELEASE_GENERIC_CAPABILITY,
  CXX11_CLANG_RELEASE_GENERIC_CAPABILITY,
  GNU_UNLOCK_FUNCTION,
  CXX11_CLANG_UNLOCK_FUNCTION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(ReleaseCapabilityAttrSpelling) {
  return "ReleaseCapabilityAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(ReleaseCapabilityAttrSpelling) {
  return 9;
}

const char *EnumeratorName(ReleaseCapabilityAttrSpelling);

} // namespace mx
