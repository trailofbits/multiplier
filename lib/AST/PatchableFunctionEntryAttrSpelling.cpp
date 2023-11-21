// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/PatchableFunctionEntryAttrSpelling.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(PatchableFunctionEntryAttrSpelling e) {
  switch (e) {
    case PatchableFunctionEntryAttrSpelling::GNU_PATCHABLE_FUNCTION_ENTRY: return "GNU_PATCHABLE_FUNCTION_ENTRY";
    case PatchableFunctionEntryAttrSpelling::CXX11_GNU_PATCHABLE_FUNCTION_ENTRY: return "CXX11_GNU_PATCHABLE_FUNCTION_ENTRY";
    case PatchableFunctionEntryAttrSpelling::C2X_GNU_PATCHABLE_FUNCTION_ENTRY: return "C2X_GNU_PATCHABLE_FUNCTION_ENTRY";
    case PatchableFunctionEntryAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
