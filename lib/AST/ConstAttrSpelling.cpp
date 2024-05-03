// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ConstAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ConstAttrSpelling e) {
  switch (e) {
    case ConstAttrSpelling::GNU_CONST: return "GNU_CONST";
    case ConstAttrSpelling::CXX11_GNU_CONST: return "CXX11_GNU_CONST";
    case ConstAttrSpelling::C23_GNU_CONST: return "C23_GNU_CONST";
    case ConstAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
