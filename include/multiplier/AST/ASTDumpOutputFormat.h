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
enum class ASTDumpOutputFormat : unsigned char {
  DEFAULT,
  JSON,
};

inline static const char *EnumerationName(ASTDumpOutputFormat) {
  return "ASTDumpOutputFormat";
}

inline static constexpr unsigned NumEnumerators(ASTDumpOutputFormat) {
  return 2;
}

MX_EXPORT const char *EnumeratorName(ASTDumpOutputFormat);

} // namespace mx
