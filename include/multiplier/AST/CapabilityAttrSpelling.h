// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CapabilityAttrSpelling : unsigned char {
  GNU_CAPABILITY,
  CXX11_CLANG_CAPABILITY,
  GNU_SHARED_CAPABILITY,
  CXX11_CLANG_SHARED_CAPABILITY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(CapabilityAttrSpelling) {
  return "CapabilityAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(CapabilityAttrSpelling) {
  return 5;
}

const char *EnumeratorName(CapabilityAttrSpelling);

} // namespace mx
