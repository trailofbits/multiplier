// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PreserveAllAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PreserveAllAttrSpelling e) {
  switch (e) {
    case PreserveAllAttrSpelling::GNU_PRESERVE_ALL: return "GNU_PRESERVE_ALL";
    case PreserveAllAttrSpelling::CXX11_CLANG_PRESERVE_ALL: return "CXX11_CLANG_PRESERVE_ALL";
    case PreserveAllAttrSpelling::C23_CLANG_PRESERVE_ALL: return "C23_CLANG_PRESERVE_ALL";
    case PreserveAllAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
