// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class QualifiedTypeDestructionKind : unsigned char {
  NONE,
  CXX_DESTRUCTOR,
  OBJC_STRONG_LIFETIME,
  OBJC_WEAK_LIFETIME,
  NONTRIVIAL_C_STRUCT,
};

inline static const char *EnumerationName(QualifiedTypeDestructionKind) {
  return "QualifiedTypeDestructionKind";
}

inline static constexpr unsigned NumEnumerators(QualifiedTypeDestructionKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(QualifiedTypeDestructionKind);

} // namespace mx
