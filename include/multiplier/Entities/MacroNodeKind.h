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
  OTHER_DIRECTIVE,
  IF_DIRECTIVE,
  IF_DEFINED_DIRECTIVE,
  IF_NOT_DEFINED_DIRECTIVE,
  ELSE_IF_DIRECTIVE,
  ELSE_IF_DEFINED_DIRECTIVE,
  ELSE_IF_NOT_DEFINED_DIRECTIVE,
  ELSE_DIRECTIVE,
  END_IF_DIRECTIVE,
  DEFINE_DIRECTIVE,
  UNDEFINE_DIRECTIVE,
  PRAGMA_DIRECTIVE,
  INCLUDE_DIRECTIVE,
  INCLUDE_NEXT_DIRECTIVE,
  INCLUDE_MACROS_DIRECTIVE,
  IMPORT_DIRECTIVE,
  ARGUMENT,
  PARAMETER,
};

inline static const char *EnumerationName(MacroNodeKind) {
  return "MacroNodeKind";
}

inline static constexpr unsigned NumEnumerators(MacroNodeKind) {
  return 22;
}

const char *EnumeratorName(MacroNodeKind);

} // namespace mx
