// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionReturnThunksAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(FunctionReturnThunksAttrSpelling e) {
  switch (e) {
    case FunctionReturnThunksAttrSpelling::GNU_FUNCTION_RETURN: return "GNU_FUNCTION_RETURN";
    case FunctionReturnThunksAttrSpelling::CXX11_GNU_FUNCTION_RETURN: return "CXX11_GNU_FUNCTION_RETURN";
    case FunctionReturnThunksAttrSpelling::C23_GNU_FUNCTION_RETURN: return "C23_GNU_FUNCTION_RETURN";
    case FunctionReturnThunksAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
