// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AVRSignalAttrSpelling : unsigned char {
  GNU_SIGNAL,
  CXX11_GNU_SIGNAL,
  C23_GNU_SIGNAL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AVRSignalAttrSpelling) {
  return "AVRSignalAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AVRSignalAttrSpelling) {
  return 4;
}

const char *EnumeratorName(AVRSignalAttrSpelling);

} // namespace mx
