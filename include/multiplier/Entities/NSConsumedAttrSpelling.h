// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NSConsumedAttrSpelling : unsigned char {
  GNU_NS_CONSUMED,
  CXX11_CLANG_NS_CONSUMED,
  C23_CLANG_NS_CONSUMED,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NSConsumedAttrSpelling) {
  return "NSConsumedAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NSConsumedAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NSConsumedAttrSpelling);

} // namespace mx
