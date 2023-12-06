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
enum class DeclIdentifierNamespace : unsigned char {
  LABEL,
  TAG,
  TYPE,
  MEMBER,
  NAMESPACE,
  ORDINARY,
  OBJ_C_PROTOCOL,
  ORDINARY_FRIEND,
  TAG_FRIEND,
  USING,
  NON_MEMBER_OPERATOR,
  LOCAL_EXTERN,
  OMP_REDUCTION,
  OMP_MAPPER,
};

inline static const char *EnumerationName(DeclIdentifierNamespace) {
  return "DeclIdentifierNamespace";
}

inline static constexpr unsigned NumEnumerators(DeclIdentifierNamespace) {
  return 14;
}

MX_EXPORT const char *EnumeratorName(DeclIdentifierNamespace);

} // namespace mx
