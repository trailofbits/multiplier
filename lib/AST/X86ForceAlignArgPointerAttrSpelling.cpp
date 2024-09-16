// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/X86ForceAlignArgPointerAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(X86ForceAlignArgPointerAttrSpelling e) {
  switch (e) {
    case X86ForceAlignArgPointerAttrSpelling::GNU_FORCE_ALIGN_ARGUMENT_POINTER: return "GNU_FORCE_ALIGN_ARGUMENT_POINTER";
    case X86ForceAlignArgPointerAttrSpelling::CXX11_GNU_FORCE_ALIGN_ARGUMENT_POINTER: return "CXX11_GNU_FORCE_ALIGN_ARGUMENT_POINTER";
    case X86ForceAlignArgPointerAttrSpelling::C23_GNU_FORCE_ALIGN_ARGUMENT_POINTER: return "C23_GNU_FORCE_ALIGN_ARGUMENT_POINTER";
    case X86ForceAlignArgPointerAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
