// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class QualifiedTypeNonConstantStorageReason : unsigned char {
  MUTABLE_FIELD,
  NON_CONST_NON_REFERENCE_TYPE,
  NON_TRIVIAL_CONSTRUCTOR,
  NON_TRIVIAL_DESTRUCTOR,
};

inline static const char *EnumerationName(QualifiedTypeNonConstantStorageReason) {
  return "QualifiedTypeNonConstantStorageReason";
}

inline static constexpr unsigned NumEnumerators(QualifiedTypeNonConstantStorageReason) {
  return 4;
}

const char *EnumeratorName(QualifiedTypeNonConstantStorageReason);

} // namespace mx
