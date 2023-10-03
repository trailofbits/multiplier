// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SwiftErrorResultAttrSpelling : unsigned char {
  GNU_SWIFT_ERROR_RESULT,
  CXX11_CLANG_SWIFT_ERROR_RESULT,
  C23_CLANG_SWIFT_ERROR_RESULT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(SwiftErrorResultAttrSpelling) {
  return "SwiftErrorResultAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(SwiftErrorResultAttrSpelling) {
  return 4;
}

const char *EnumeratorName(SwiftErrorResultAttrSpelling);

} // namespace mx
