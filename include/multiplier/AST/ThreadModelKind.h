// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ThreadModelKind : unsigned char {
  POSIX,
  SINGLE,
};

inline static const char *EnumerationName(ThreadModelKind) {
  return "ThreadModelKind";
}

inline static constexpr unsigned NumEnumerators(ThreadModelKind) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(ThreadModelKind);

} // namespace mx
