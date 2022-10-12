// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class RecordDeclArgPassingKind : unsigned char {
  CAN_PASS_IN_REGS,
  CANNOT_PASS_IN_REGS,
  CAN_NEVER_PASS_IN_REGS,
};

inline static const char *EnumerationName(RecordDeclArgPassingKind) {
  return "RecordDeclArgPassingKind";
}

inline static constexpr unsigned NumEnumerators(RecordDeclArgPassingKind) {
  return 3;
}

const char *EnumeratorName(RecordDeclArgPassingKind);

} // namespace mx
