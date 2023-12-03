// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class OnOffSwitch : unsigned char {
  ON,
  OFF,
  DEFAULT,
};

inline static const char *EnumerationName(OnOffSwitch) {
  return "OnOffSwitch";
}

inline static constexpr unsigned NumEnumerators(OnOffSwitch) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(OnOffSwitch);

} // namespace mx
