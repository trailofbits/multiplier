// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CXXRecordDeclLambdaDependencyKind : unsigned char {
  UNKNOWN,
  ALWAYS_DEPENDENT,
  NEVER_DEPENDENT,
};

inline static const char *EnumerationName(CXXRecordDeclLambdaDependencyKind) {
  return "CXXRecordDeclLambdaDependencyKind";
}

inline static constexpr unsigned NumEnumerators(CXXRecordDeclLambdaDependencyKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(CXXRecordDeclLambdaDependencyKind);

} // namespace mx
