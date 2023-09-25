// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TLSModelAttrSpelling : unsigned char {
  GNU_TLS_MODEL,
  CXX11_GNU_TLS_MODEL,
  C23_GNU_TLS_MODEL,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(TLSModelAttrSpelling) {
  return "TLSModelAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(TLSModelAttrSpelling) {
  return 4;
}

const char *EnumeratorName(TLSModelAttrSpelling);

} // namespace mx
