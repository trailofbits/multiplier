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
enum class QualifiedTypePrimitiveCopyKind : unsigned char {
  TRIVIAL,
  VOLATILE_TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
};

inline static const char *EnumerationName(QualifiedTypePrimitiveCopyKind) {
  return "QualifiedTypePrimitiveCopyKind";
}

inline static constexpr unsigned NumEnumerators(QualifiedTypePrimitiveCopyKind) {
  return 5;
}

MX_EXPORT const char *EnumeratorName(QualifiedTypePrimitiveCopyKind);

} // namespace mx
