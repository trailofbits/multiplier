// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/UnavailableAttrImplicitReason.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(UnavailableAttrImplicitReason e) {
  switch (e) {
    case UnavailableAttrImplicitReason::NONE: return "NONE";
    case UnavailableAttrImplicitReason::ARC_FORBIDDEN_TYPE: return "ARC_FORBIDDEN_TYPE";
    case UnavailableAttrImplicitReason::FORBIDDEN_WEAK: return "FORBIDDEN_WEAK";
    case UnavailableAttrImplicitReason::ARC_FORBIDDEN_CONVERSION: return "ARC_FORBIDDEN_CONVERSION";
    case UnavailableAttrImplicitReason::ARC_INIT_RETURNS_UNRELATED: return "ARC_INIT_RETURNS_UNRELATED";
    case UnavailableAttrImplicitReason::ARC_FIELD_WITH_OWNERSHIP: return "ARC_FIELD_WITH_OWNERSHIP";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
