// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class ClangABI : unsigned char {
  VER38,
  VER4,
  VER6,
  VER7,
  VER9,
  VER11,
  VER12,
  VER14,
  VER15,
  VER17,
  LATEST,
};

inline static const char *EnumerationName(ClangABI) {
  return "ClangABI";
}

inline static constexpr unsigned NumEnumerators(ClangABI) {
  return 11;
}

MX_EXPORT const char *EnumeratorName(ClangABI);

} // namespace mx
