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
enum class FileType : unsigned char {
  NONE,
  NOT_FOUND,
  REGULAR,
  DIRECTORY,
  SYMBOLIC_LINK,
  BLOCK,
  CHARACTER,
  FIRST_IN_FIRST_OUT,
  SOCKET,
  KNKNOWN,
};

inline static const char *EnumerationName(FileType) {
  return "FileType";
}

inline static constexpr unsigned NumEnumerators(FileType) {
  return 10;
}

MX_EXPORT const char *EnumeratorName(FileType);

} // namespace mx
