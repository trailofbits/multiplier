// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MSInheritanceAttrSpelling.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MSInheritanceAttrSpelling e) {
  switch (e) {
    case MSInheritanceAttrSpelling::KEYWORD_SINGLE_INHERITANCE: return "KEYWORD_SINGLE_INHERITANCE";
    case MSInheritanceAttrSpelling::KEYWORD_MULTIPLE_INHERITANCE: return "KEYWORD_MULTIPLE_INHERITANCE";
    case MSInheritanceAttrSpelling::KEYWORD_VIRTUAL_INHERITANCE: return "KEYWORD_VIRTUAL_INHERITANCE";
    case MSInheritanceAttrSpelling::KEYWORD_UNSPECIFIED_INHERITANCE: return "KEYWORD_UNSPECIFIED_INHERITANCE";
    case MSInheritanceAttrSpelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
