// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/VisibilityForcedKinds.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(VisibilityForcedKinds e) {
  switch (e) {
    case VisibilityForcedKinds::FORCE_HIDDEN: return "FORCE_HIDDEN";
    case VisibilityForcedKinds::FORCE_PROTECTED: return "FORCE_PROTECTED";
    case VisibilityForcedKinds::FORCE_DEFAULT: return "FORCE_DEFAULT";
    case VisibilityForcedKinds::SOURCE: return "SOURCE";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
