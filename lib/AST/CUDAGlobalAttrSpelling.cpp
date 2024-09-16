// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CUDAGlobalAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CUDAGlobalAttrSpelling e) {
  switch (e) {
    case CUDAGlobalAttrSpelling::GNU_GLOBAL: return "GNU_GLOBAL";
    case CUDAGlobalAttrSpelling::DECLSPEC_GLOBAL: return "DECLSPEC_GLOBAL";
    case CUDAGlobalAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
