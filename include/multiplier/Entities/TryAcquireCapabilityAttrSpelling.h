// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TryAcquireCapabilityAttrSpelling : unsigned char {
  GNU_TRY_ACQUIRE_CAPABILITY,
  CXX11_CLANG_TRY_ACQUIRE_CAPABILITY,
  GNU_TRY_ACQUIRE_SHARED_CAPABILITY,
  CXX11_CLANG_TRY_ACQUIRE_SHARED_CAPABILITY,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TryAcquireCapabilityAttrSpelling) {
  return "TryAcquireCapabilityAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TryAcquireCapabilityAttrSpelling) {
  return 5;
}

const char *EnumeratorName(TryAcquireCapabilityAttrSpelling);

} // namespace mx
