// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ArmBuiltinAliasAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ArmBuiltinAliasAttrSpelling e) {
  switch (e) {
    case ArmBuiltinAliasAttrSpelling::GNU_CLANG_ARM_BUILTIN_ALIAS: return "GNU_CLANG_ARM_BUILTIN_ALIAS";
    case ArmBuiltinAliasAttrSpelling::CXX11_CLANG_CLANG_ARM_BUILTIN_ALIAS: return "CXX11_CLANG_CLANG_ARM_BUILTIN_ALIAS";
    case ArmBuiltinAliasAttrSpelling::C23_CLANG_CLANG_ARM_BUILTIN_ALIAS: return "C23_CLANG_CLANG_ARM_BUILTIN_ALIAS";
    case ArmBuiltinAliasAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
