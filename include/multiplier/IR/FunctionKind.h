// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx::ir {

enum class FunctionKind : uint8_t {
  NORMAL = 0,
  GLOBAL_INITIALIZER = 1,
};

inline static const char *EnumerationName(FunctionKind) {
  return "FunctionKind";
}

const char *EnumeratorName(FunctionKind kind) noexcept;

inline static constexpr unsigned NumEnumerators(FunctionKind) {
  return 2u;
}

}  // namespace mx::ir
