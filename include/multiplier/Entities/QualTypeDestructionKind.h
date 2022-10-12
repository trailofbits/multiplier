// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class QualTypeDestructionKind : unsigned char {
  NONE,
  CXX_DESTRUCTOR,
  OBJC_STRONG_LIFETIME,
  OBJC_WEAK_LIFETIME,
  NONTRIVIAL_C_STRUCT,
};

inline static const char *EnumerationName(QualTypeDestructionKind) {
  return "QualTypeDestructionKind";
}

inline static constexpr unsigned NumEnumerators(QualTypeDestructionKind) {
  return 5;
}

const char *EnumeratorName(QualTypeDestructionKind);

} // namespace mx
