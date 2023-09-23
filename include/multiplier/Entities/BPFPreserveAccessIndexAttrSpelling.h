// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class BPFPreserveAccessIndexAttrSpelling : unsigned char {
  GNU_PRESERVE_ACCESS_INDEX,
  CXX11_CLANG_PRESERVE_ACCESS_INDEX,
  C23_CLANG_PRESERVE_ACCESS_INDEX,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(BPFPreserveAccessIndexAttrSpelling) {
  return "BPFPreserveAccessIndexAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(BPFPreserveAccessIndexAttrSpelling) {
  return 4;
}

const char *EnumeratorName(BPFPreserveAccessIndexAttrSpelling);

} // namespace mx
