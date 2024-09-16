// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class MacroKind : unsigned char {
  SUBSTITUTION,
  EXPANSION,
  ARGUMENT,
  PARAMETER,
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
  PARAMETER_SUBSTITUTION,
  STRINGIFY,
  CONCATENATE,
  VA_OPT,
  VA_OPT_ARGUMENT,
};

inline static const char *EnumerationName(MacroKind) {
  return "MacroKind";
}

inline static constexpr unsigned NumEnumerators(MacroKind) {
  return 25;
}

MX_EXPORT const char *EnumeratorName(MacroKind);

} // namespace mx
