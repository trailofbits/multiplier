// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenCLAccessAttrSpelling : unsigned char {
  KEYWORD_READ_ONLY,
  KEYWORD_WRITE_ONLY,
  KEYWORD_READ_WRITE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(OpenCLAccessAttrSpelling) {
  return "OpenCLAccessAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(OpenCLAccessAttrSpelling) {
  return 4;
}

const char *EnumeratorName(OpenCLAccessAttrSpelling);

} // namespace mx
