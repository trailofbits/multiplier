// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class DebugSrcHashKind : unsigned char {
  DSHMD5,
  DSHSHA1,
  DSHSHA256,
};

inline static const char *EnumerationName(DebugSrcHashKind) {
  return "DebugSrcHashKind";
}

inline static constexpr unsigned NumEnumerators(DebugSrcHashKind) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(DebugSrcHashKind);

} // namespace mx
