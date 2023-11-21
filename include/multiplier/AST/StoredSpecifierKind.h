// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class StoredSpecifierKind : unsigned char {
  STORED_IDENTIFIER,
  STORED_DECLARATION,
  STORED_TYPE_SPEC,
  STORED_TYPE_SPEC_WITH_TEMPLATE,
};

inline static const char *EnumerationName(StoredSpecifierKind) {
  return "StoredSpecifierKind";
}

inline static constexpr unsigned NumEnumerators(StoredSpecifierKind) {
  return 4;
}

const char *EnumeratorName(StoredSpecifierKind);

} // namespace mx
