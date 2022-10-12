// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class NoProfileFunctionAttrSpelling : unsigned char {
  GNU_NO_PROFILE_INSTRUMENT_FUNCTION,
  CXX11_GNU_NO_PROFILE_INSTRUMENT_FUNCTION,
  C2X_GNU_NO_PROFILE_INSTRUMENT_FUNCTION,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(NoProfileFunctionAttrSpelling) {
  return "NoProfileFunctionAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(NoProfileFunctionAttrSpelling) {
  return 4;
}

const char *EnumeratorName(NoProfileFunctionAttrSpelling);

} // namespace mx
