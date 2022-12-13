// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class MacroNodeKind : unsigned char {
  INVALID,
  TOKEN,
  EXPANSION,
  SUBSTITUTION,
  DIRECTIVE,
  DEFINE,
  INCLUDE,
  ARGUMENT,
};

inline static const char *EnumerationName(MacroNodeKind) {
  return "MacroNodeKind";
}

inline static constexpr unsigned NumEnumerators(MacroNodeKind) {
  return 8;
}

const char *EnumeratorName(MacroNodeKind);

} // namespace mx
