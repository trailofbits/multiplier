// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/AlignRequirementKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AlignRequirementKind e) {
  switch (e) {
    case AlignRequirementKind::NONE: return "NONE";
    case AlignRequirementKind::REQUIRED_BY_TYPEDEF: return "REQUIRED_BY_TYPEDEF";
    case AlignRequirementKind::REQUIRED_BY_RECORD: return "REQUIRED_BY_RECORD";
    case AlignRequirementKind::REQUIRED_BY_ENUM: return "REQUIRED_BY_ENUM";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
