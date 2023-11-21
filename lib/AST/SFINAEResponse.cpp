// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/SFINAEResponse.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SFINAEResponse e) {
  switch (e) {
    case SFINAEResponse::SUBSTITUTION_FAILURE: return "SUBSTITUTION_FAILURE";
    case SFINAEResponse::SUPPRESS: return "SUPPRESS";
    case SFINAEResponse::REPORT: return "REPORT";
    case SFINAEResponse::ACCESS_CONTROL: return "ACCESS_CONTROL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
