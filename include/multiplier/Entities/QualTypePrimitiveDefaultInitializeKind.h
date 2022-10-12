// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class QualTypePrimitiveDefaultInitializeKind : unsigned char {
  TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
};

inline static const char *EnumerationName(QualTypePrimitiveDefaultInitializeKind) {
  return "QualTypePrimitiveDefaultInitializeKind";
}

inline static constexpr unsigned NumEnumerators(QualTypePrimitiveDefaultInitializeKind) {
  return 4;
}

const char *EnumeratorName(QualTypePrimitiveDefaultInitializeKind);

} // namespace mx
