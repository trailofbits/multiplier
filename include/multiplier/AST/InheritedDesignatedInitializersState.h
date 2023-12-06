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
enum class InheritedDesignatedInitializersState : unsigned char {
  UNKNOWN,
  INHERITED,
  NOT_INHERITED,
};

inline static const char *EnumerationName(InheritedDesignatedInitializersState) {
  return "InheritedDesignatedInitializersState";
}

inline static constexpr unsigned NumEnumerators(InheritedDesignatedInitializersState) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(InheritedDesignatedInitializersState);

} // namespace mx
