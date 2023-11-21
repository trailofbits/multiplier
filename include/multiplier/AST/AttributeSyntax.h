// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AttributeSyntax : unsigned char {
  GNU,
  CXX11,
  C2X,
  DECLSPEC,
  MICROSOFT,
  KEYWORD,
  PRAGMA,
  CONTEXT_SENSITIVE_KEYWORD,
};

inline static const char *EnumerationName(AttributeSyntax) {
  return "AttributeSyntax";
}

inline static constexpr unsigned NumEnumerators(AttributeSyntax) {
  return 8;
}

const char *EnumeratorName(AttributeSyntax);

} // namespace mx
