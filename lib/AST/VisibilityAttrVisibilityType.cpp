// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VisibilityAttrVisibilityType.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VisibilityAttrVisibilityType e) {
  switch (e) {
    case VisibilityAttrVisibilityType::DEFAULT: return "DEFAULT";
    case VisibilityAttrVisibilityType::HIDDEN: return "HIDDEN";
    case VisibilityAttrVisibilityType::PROTECTED: return "PROTECTED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
