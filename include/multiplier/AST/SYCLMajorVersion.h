// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class SYCLMajorVersion : unsigned char {
  VERSION_NONE,
  VERSION2017,
  VERSION2020,
  // Skipped repeat pasta::kDefault
};

inline static const char *EnumerationName(SYCLMajorVersion) {
  return "SYCLMajorVersion";
}

inline static constexpr unsigned NumEnumerators(SYCLMajorVersion) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(SYCLMajorVersion);

} // namespace mx
