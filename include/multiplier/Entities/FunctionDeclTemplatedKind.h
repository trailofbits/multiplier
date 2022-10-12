// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class FunctionDeclTemplatedKind : unsigned char {
  NON_TEMPLATE,
  FUNCTION_TEMPLATE,
  MEMBER_SPECIALIZATION,
  FUNCTION_TEMPLATE_SPECIALIZATION,
  DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION,
};

inline static const char *EnumerationName(FunctionDeclTemplatedKind) {
  return "FunctionDeclTemplatedKind";
}

inline static constexpr unsigned NumEnumerators(FunctionDeclTemplatedKind) {
  return 5;
}

const char *EnumeratorName(FunctionDeclTemplatedKind);

} // namespace mx
