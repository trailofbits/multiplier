// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoDebugAttrSpelling : unsigned char {
  GNU_NODEBUG,
  CXX11_GNU_NODEBUG,
  C2X_GNU_NODEBUG,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoDebugAttrSpelling) {
  return "NoDebugAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoDebugAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NoDebugAttrSpelling);

} // namespace mx
