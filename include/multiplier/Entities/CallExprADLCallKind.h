// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CallExprADLCallKind : unsigned char {
  NOT_ADL,
  USES_ADL,
};

inline static const char *EnumerationName(CallExprADLCallKind) {
  return "CallExprADLCallKind";
}

inline static constexpr unsigned NumEnumerators(CallExprADLCallKind) {
  return 2;
}

const char *EnumeratorName(CallExprADLCallKind);

} // namespace mx
