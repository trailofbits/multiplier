// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class FunctionDeclTemplatedKind : unsigned char {
  NON_TEMPLATE,
  FUNCTION_TEMPLATE,
  MEMBER_SPECIALIZATION,
  FUNCTION_TEMPLATE_SPECIALIZATION,
  DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION,
  DEPENDENT_NON_TEMPLATE,
};

inline static const char *EnumerationName(FunctionDeclTemplatedKind) {
  return "FunctionDeclTemplatedKind";
}

inline static constexpr unsigned NumEnumerators(FunctionDeclTemplatedKind) {
  return 6;
}

MX_EXPORT const char *EnumeratorName(FunctionDeclTemplatedKind);

} // namespace mx
