// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class TemplateArgumentKind : unsigned char {
  EMPTY,
  TYPE,
  DECLARATION,
  NULL_POINTER,
  INTEGRAL,
  TEMPLATE,
  TEMPLATE_EXPANSION,
  EXPRESSION,
  PACK,
};

inline static const char *EnumerationName(TemplateArgumentKind) {
  return "TemplateArgumentKind";
}

inline static constexpr unsigned NumEnumerators(TemplateArgumentKind) {
  return 9;
}

const char *EnumeratorName(TemplateArgumentKind);

} // namespace mx
