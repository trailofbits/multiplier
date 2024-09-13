// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class StoredNameKind : unsigned char {
  STORED_IDENTIFIER,
  STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR,
  STORED_OBJ_C_ONE_ARGUMENT_SELECTOR,
  STORED_CXX_CONSTRUCTOR_NAME,
  STORED_CXX_DESTRUCTOR_NAME,
  STORED_CXX_CONVERSION_FUNCTION_NAME,
  STORED_CXX_OPERATOR_NAME,
  STORED_DECLARATION_NAME_EXTRA,
  // Skipped repeat pasta::kPointerMask
  UNCOMMON_NAME_KIND_OFFSET,
};

inline static const char *EnumerationName(StoredNameKind) {
  return "StoredNameKind";
}

inline static constexpr unsigned NumEnumerators(StoredNameKind) {
  return 9;
}

MX_EXPORT const char *EnumeratorName(StoredNameKind);

} // namespace mx
