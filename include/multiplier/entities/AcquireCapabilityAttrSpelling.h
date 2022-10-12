// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AcquireCapabilityAttrSpelling : unsigned char {
  GNU_ACQUIRE_CAPABILITY,
  CXX11_CLANG_ACQUIRE_CAPABILITY,
  GNU_ACQUIRE_SHARED_CAPABILITY,
  CXX11_CLANG_ACQUIRE_SHARED_CAPABILITY,
  GNU_EXCLUSIVE_LOCK_FUNCTION,
  GNU_SHARED_LOCK_FUNCTION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AcquireCapabilityAttrSpelling) {
  return "AcquireCapabilityAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AcquireCapabilityAttrSpelling) {
  return 7;
}

const char *EnumeratorName(AcquireCapabilityAttrSpelling);

} // namespace mx
