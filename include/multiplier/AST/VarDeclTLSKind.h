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
enum class VarDeclTLSKind : unsigned char {
  NONE,
  STATIC,
  DYNAMIC,
};

inline static const char *EnumerationName(VarDeclTLSKind) {
  return "VarDeclTLSKind";
}

inline static constexpr unsigned NumEnumerators(VarDeclTLSKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(VarDeclTLSKind);

} // namespace mx
