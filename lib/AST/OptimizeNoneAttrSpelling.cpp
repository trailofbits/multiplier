// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/OptimizeNoneAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(OptimizeNoneAttrSpelling e) {
  switch (e) {
    case OptimizeNoneAttrSpelling::GNU_OPTNONE: return "GNU_OPTNONE";
    case OptimizeNoneAttrSpelling::CXX11_CLANG_OPTNONE: return "CXX11_CLANG_OPTNONE";
    case OptimizeNoneAttrSpelling::C23_CLANG_OPTNONE: return "C23_CLANG_OPTNONE";
    case OptimizeNoneAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
