// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AArch64VectorPcsAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AArch64VectorPcsAttrSpelling e) {
  switch (e) {
    case AArch64VectorPcsAttrSpelling::GNU_AARCH64_VECTOR_PCS: return "GNU_AARCH64_VECTOR_PCS";
    case AArch64VectorPcsAttrSpelling::CXX11_CLANG_AARCH64_VECTOR_PCS: return "CXX11_CLANG_AARCH64_VECTOR_PCS";
    case AArch64VectorPcsAttrSpelling::C23_CLANG_AARCH64_VECTOR_PCS: return "C23_CLANG_AARCH64_VECTOR_PCS";
    case AArch64VectorPcsAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
