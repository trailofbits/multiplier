// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ReturnTypestateAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ReturnTypestateAttrSpelling e) {
  switch (e) {
    case ReturnTypestateAttrSpelling::GNU_RETURN_TYPESTATE: return "GNU_RETURN_TYPESTATE";
    case ReturnTypestateAttrSpelling::CXX11_CLANG_RETURN_TYPESTATE: return "CXX11_CLANG_RETURN_TYPESTATE";
    case ReturnTypestateAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
