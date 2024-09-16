// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ThreadStorageClassSpecifier : unsigned char {
  UNSPECIFIED,
  __THREAD,
  THREAD_LOCAL,
  _THREAD_LOCAL,
};

inline static const char *EnumerationName(ThreadStorageClassSpecifier) {
  return "ThreadStorageClassSpecifier";
}

inline static constexpr unsigned NumEnumerators(ThreadStorageClassSpecifier) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(ThreadStorageClassSpecifier);

} // namespace mx
