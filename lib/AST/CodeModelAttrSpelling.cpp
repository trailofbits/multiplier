// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CodeModelAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CodeModelAttrSpelling e) {
  switch (e) {
    case CodeModelAttrSpelling::GNU_MODEL: return "GNU_MODEL";
    case CodeModelAttrSpelling::CXX11_GNU_MODEL: return "CXX11_GNU_MODEL";
    case CodeModelAttrSpelling::C23_GNU_MODEL: return "C23_GNU_MODEL";
    case CodeModelAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
