// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class LinkageSpecDeclLanguageIDs : unsigned char {
  C,
  CXX,
};

inline static const char *EnumerationName(LinkageSpecDeclLanguageIDs) {
  return "LinkageSpecDeclLanguageIDs";
}

inline static constexpr unsigned NumEnumerators(LinkageSpecDeclLanguageIDs) {
  return 2;
}

const char *EnumeratorName(LinkageSpecDeclLanguageIDs);

} // namespace mx
