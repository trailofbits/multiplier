// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class OpenMPDeviceClauseModifier : unsigned char {
  ANCESTOR,
  DEVICE_NUM,
  UNKNOWN,
};

inline static const char *EnumerationName(OpenMPDeviceClauseModifier) {
  return "OpenMPDeviceClauseModifier";
}

inline static constexpr unsigned NumEnumerators(OpenMPDeviceClauseModifier) {
  return 3;
}

const char *EnumeratorName(OpenMPDeviceClauseModifier);

} // namespace mx
