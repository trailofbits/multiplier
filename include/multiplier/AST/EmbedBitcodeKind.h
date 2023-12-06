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
enum class EmbedBitcodeKind : unsigned char {
  EMBED_OFF,
  EMBED_ALL,
  EMBED_BITCODE,
  EMBED_MARKER,
};

inline static const char *EnumerationName(EmbedBitcodeKind) {
  return "EmbedBitcodeKind";
}

inline static constexpr unsigned NumEnumerators(EmbedBitcodeKind) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(EmbedBitcodeKind);

} // namespace mx
