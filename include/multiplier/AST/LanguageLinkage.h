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
enum class LanguageLinkage : unsigned char {
  C_LANGUAGE_LINKAGE,
  CXX_LANGUAGE_LINKAGE,
  NO_LANGUAGE_LINKAGE,
};

inline static const char *EnumerationName(LanguageLinkage) {
  return "LanguageLinkage";
}

inline static constexpr unsigned NumEnumerators(LanguageLinkage) {
  return 3;
}

MX_EXPORT const char *EnumeratorName(LanguageLinkage);

} // namespace mx
