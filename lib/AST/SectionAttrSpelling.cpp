// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SectionAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SectionAttrSpelling e) {
  switch (e) {
    case SectionAttrSpelling::GNU_SECTION: return "GNU_SECTION";
    case SectionAttrSpelling::CXX11_GNU_SECTION: return "CXX11_GNU_SECTION";
    case SectionAttrSpelling::C23_GNU_SECTION: return "C23_GNU_SECTION";
    case SectionAttrSpelling::DECLSPEC_ALLOCATE: return "DECLSPEC_ALLOCATE";
    case SectionAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
