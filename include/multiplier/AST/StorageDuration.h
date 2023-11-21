// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class StorageDuration : unsigned char {
  FULL_EXPRESSION,
  AUTOMATIC,
  THREAD,
  STATIC,
  DYNAMIC,
};

inline static const char *EnumerationName(StorageDuration) {
  return "StorageDuration";
}

inline static constexpr unsigned NumEnumerators(StorageDuration) {
  return 5;
}

const char *EnumeratorName(StorageDuration);

} // namespace mx
