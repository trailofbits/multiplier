// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/MSInheritanceModel.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(MSInheritanceModel e) {
  switch (e) {
    case MSInheritanceModel::SINGLE: return "SINGLE";
    case MSInheritanceModel::MULTIPLE: return "MULTIPLE";
    case MSInheritanceModel::VIRTUAL: return "VIRTUAL";
    case MSInheritanceModel::UNSPECIFIED: return "UNSPECIFIED";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
