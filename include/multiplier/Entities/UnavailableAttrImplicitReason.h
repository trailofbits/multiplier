// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UnavailableAttrImplicitReason : unsigned char {
  NONE,
  ARC_FORBIDDEN_TYPE,
  FORBIDDEN_WEAK,
  ARC_FORBIDDEN_CONVERSION,
  ARC_INIT_RETURNS_UNRELATED,
  ARC_FIELD_WITH_OWNERSHIP,
};

inline static const char *EnumerationName(UnavailableAttrImplicitReason) {
  return "UnavailableAttrImplicitReason";
}

inline static constexpr unsigned NumEnumerators(UnavailableAttrImplicitReason) {
  return 6;
}

const char *EnumeratorName(UnavailableAttrImplicitReason);

} // namespace mx
