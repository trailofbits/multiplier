// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class CommentKind : unsigned char {
  INVALID,
  ORDINARY_BCPL,
  ORDINARY_C,
  BCPL_SLASH,
  BCPL_EXCL,
  JAVA_DOC,
  QT,
  MERGED,
};

inline static const char *EnumerationName(CommentKind) {
  return "CommentKind";
}

inline static constexpr unsigned NumEnumerators(CommentKind) {
  return 8;
}

MX_EXPORT const char *EnumeratorName(CommentKind);

} // namespace mx
