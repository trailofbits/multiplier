// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BuiltinAliasAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(BuiltinAliasAttrSpelling e) {
  switch (e) {
    case BuiltinAliasAttrSpelling::CXX11_CLANG_BUILTIN_ALIAS: return "CXX11_CLANG_BUILTIN_ALIAS";
    case BuiltinAliasAttrSpelling::C23_CLANG_BUILTIN_ALIAS: return "C23_CLANG_BUILTIN_ALIAS";
    case BuiltinAliasAttrSpelling::GNU_CLANG_BUILTIN_ALIAS: return "GNU_CLANG_BUILTIN_ALIAS";
    case BuiltinAliasAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
