// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class NeedExtraManglingDecl : unsigned char {
  NEED_EXTRA_MANGLING_DECLARATION,
};

inline static const char *EnumerationName(NeedExtraManglingDecl) {
  return "NeedExtraManglingDecl";
}

inline static constexpr unsigned NumEnumerators(NeedExtraManglingDecl) {
  return 1;
}

MX_EXPORT const char *EnumeratorName(NeedExtraManglingDecl);

} // namespace mx
