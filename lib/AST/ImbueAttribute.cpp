// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ImbueAttribute.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(ImbueAttribute e) {
  switch (e) {
    case ImbueAttribute::NONE: return "NONE";
    case ImbueAttribute::ALWAYS: return "ALWAYS";
    case ImbueAttribute::NEVER: return "NEVER";
    case ImbueAttribute::ALWAYSARG1: return "ALWAYSARG1";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
