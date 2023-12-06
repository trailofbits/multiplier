// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class QualifiedTypePrimitiveDefaultInitializeKind : unsigned char {
  TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
};

inline static const char *EnumerationName(QualifiedTypePrimitiveDefaultInitializeKind) {
  return "QualifiedTypePrimitiveDefaultInitializeKind";
}

inline static constexpr unsigned NumEnumerators(QualifiedTypePrimitiveDefaultInitializeKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(QualifiedTypePrimitiveDefaultInitializeKind);

} // namespace mx
