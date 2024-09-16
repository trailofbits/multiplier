// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ZeroCallUsedRegsAttrZeroCallUsedRegsKind : unsigned char {
  SKIP,
  USED_GPR_ARG,
  USED_GPR,
  USED_ARGUMENT,
  USED,
  ALL_GPR_ARG,
  ALL_GPR,
  ALL_ARGUMENT,
  ALL,
};

inline static const char *EnumerationName(ZeroCallUsedRegsAttrZeroCallUsedRegsKind) {
  return "ZeroCallUsedRegsAttrZeroCallUsedRegsKind";
}

inline static constexpr unsigned NumEnumerators(ZeroCallUsedRegsAttrZeroCallUsedRegsKind) {
  return 9;
}

MX_EXPORT const char *EnumeratorName(ZeroCallUsedRegsAttrZeroCallUsedRegsKind);

} // namespace mx
