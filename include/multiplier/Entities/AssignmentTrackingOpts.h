// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AssignmentTrackingOpts : unsigned char {
  DISABLED,
  ENABLED,
  FORCED,
};

inline static const char *EnumerationName(AssignmentTrackingOpts) {
  return "AssignmentTrackingOpts";
}

inline static constexpr unsigned NumEnumerators(AssignmentTrackingOpts) {
  return 3;
}

const char *EnumeratorName(AssignmentTrackingOpts);

} // namespace mx
