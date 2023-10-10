// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MacroKind.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MacroKind e) {
  switch (e) {
    case MacroKind::SUBSTITUTION: return "SUBSTITUTION";
    case MacroKind::EXPANSION: return "EXPANSION";
    case MacroKind::ARGUMENT: return "ARGUMENT";
    case MacroKind::PARAMETER: return "PARAMETER";
    case MacroKind::OTHER_DIRECTIVE: return "OTHER_DIRECTIVE";
    case MacroKind::IF_DIRECTIVE: return "IF_DIRECTIVE";
    case MacroKind::IF_DEFINED_DIRECTIVE: return "IF_DEFINED_DIRECTIVE";
    case MacroKind::IF_NOT_DEFINED_DIRECTIVE: return "IF_NOT_DEFINED_DIRECTIVE";
    case MacroKind::ELSE_IF_DIRECTIVE: return "ELSE_IF_DIRECTIVE";
    case MacroKind::ELSE_IF_DEFINED_DIRECTIVE: return "ELSE_IF_DEFINED_DIRECTIVE";
    case MacroKind::ELSE_IF_NOT_DEFINED_DIRECTIVE: return "ELSE_IF_NOT_DEFINED_DIRECTIVE";
    case MacroKind::ELSE_DIRECTIVE: return "ELSE_DIRECTIVE";
    case MacroKind::END_IF_DIRECTIVE: return "END_IF_DIRECTIVE";
    case MacroKind::DEFINE_DIRECTIVE: return "DEFINE_DIRECTIVE";
    case MacroKind::UNDEFINE_DIRECTIVE: return "UNDEFINE_DIRECTIVE";
    case MacroKind::PRAGMA_DIRECTIVE: return "PRAGMA_DIRECTIVE";
    case MacroKind::INCLUDE_DIRECTIVE: return "INCLUDE_DIRECTIVE";
    case MacroKind::INCLUDE_NEXT_DIRECTIVE: return "INCLUDE_NEXT_DIRECTIVE";
    case MacroKind::INCLUDE_MACROS_DIRECTIVE: return "INCLUDE_MACROS_DIRECTIVE";
    case MacroKind::IMPORT_DIRECTIVE: return "IMPORT_DIRECTIVE";
    case MacroKind::PARAMETER_SUBSTITUTION: return "PARAMETER_SUBSTITUTION";
    case MacroKind::STRINGIFY: return "STRINGIFY";
    case MacroKind::CONCATENATE: return "CONCATENATE";
    case MacroKind::VA_OPT: return "VA_OPT";
    case MacroKind::VA_OPT_ARGUMENT: return "VA_OPT_ARGUMENT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
