// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ParamTypestateAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ParamTypestateAttrSpelling e) {
  switch (e) {
    case ParamTypestateAttrSpelling::GNU_PARAMETER_TYPESTATE: return "GNU_PARAMETER_TYPESTATE";
    case ParamTypestateAttrSpelling::CXX11_CLANG_PARAMETER_TYPESTATE: return "CXX11_CLANG_PARAMETER_TYPESTATE";
    case ParamTypestateAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
