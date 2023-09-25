// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AddressSpaceAttrSpelling : unsigned char {
  GNU_ADDRESS_SPACE,
  CXX11_CLANG_ADDRESS_SPACE,
  C23_CLANG_ADDRESS_SPACE,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(AddressSpaceAttrSpelling) {
  return "AddressSpaceAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(AddressSpaceAttrSpelling) {
  return 4;
}

const char *EnumeratorName(AddressSpaceAttrSpelling);

} // namespace mx
