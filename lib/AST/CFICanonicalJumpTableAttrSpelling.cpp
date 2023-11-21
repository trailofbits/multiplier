// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CFICanonicalJumpTableAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CFICanonicalJumpTableAttrSpelling e) {
  switch (e) {
    case CFICanonicalJumpTableAttrSpelling::GNU_CFI_CANONICAL_JUMP_TABLE: return "GNU_CFI_CANONICAL_JUMP_TABLE";
    case CFICanonicalJumpTableAttrSpelling::CXX11_CLANG_CFI_CANONICAL_JUMP_TABLE: return "CXX11_CLANG_CFI_CANONICAL_JUMP_TABLE";
    case CFICanonicalJumpTableAttrSpelling::C2X_CLANG_CFI_CANONICAL_JUMP_TABLE: return "C2X_CLANG_CFI_CANONICAL_JUMP_TABLE";
    case CFICanonicalJumpTableAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
