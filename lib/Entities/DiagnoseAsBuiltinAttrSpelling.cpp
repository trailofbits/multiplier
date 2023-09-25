// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/DiagnoseAsBuiltinAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(DiagnoseAsBuiltinAttrSpelling e) {
  switch (e) {
    case DiagnoseAsBuiltinAttrSpelling::GNU_DIAGNOSE_AS_BUILTIN: return "GNU_DIAGNOSE_AS_BUILTIN";
    case DiagnoseAsBuiltinAttrSpelling::CXX11_CLANG_DIAGNOSE_AS_BUILTIN: return "CXX11_CLANG_DIAGNOSE_AS_BUILTIN";
    case DiagnoseAsBuiltinAttrSpelling::C23_CLANG_DIAGNOSE_AS_BUILTIN: return "C23_CLANG_DIAGNOSE_AS_BUILTIN";
    case DiagnoseAsBuiltinAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
