// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/BPFPreserveStaticOffsetAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(BPFPreserveStaticOffsetAttrSpelling e) {
  switch (e) {
    case BPFPreserveStaticOffsetAttrSpelling::GNU_PRESERVE_STATIC_OFFSET: return "GNU_PRESERVE_STATIC_OFFSET";
    case BPFPreserveStaticOffsetAttrSpelling::CXX11_CLANG_PRESERVE_STATIC_OFFSET: return "CXX11_CLANG_PRESERVE_STATIC_OFFSET";
    case BPFPreserveStaticOffsetAttrSpelling::C23_CLANG_PRESERVE_STATIC_OFFSET: return "C23_CLANG_PRESERVE_STATIC_OFFSET";
    case BPFPreserveStaticOffsetAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
