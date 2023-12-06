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
enum class NameKind : unsigned char {
  TEMPLATE,
  OVERLOADED_TEMPLATE,
  ASSUMED_TEMPLATE,
  QUALIFIED_TEMPLATE,
  DEPENDENT_TEMPLATE,
  SUBST_TEMPLATE_TEMPLATE_PARM,
  SUBST_TEMPLATE_TEMPLATE_PARM_PACK,
  USING_TEMPLATE,
};

inline static const char *EnumerationName(NameKind) {
  return "NameKind";
}

inline static constexpr unsigned NumEnumerators(NameKind) {
  return 8;
}

MX_EXPORT const char *EnumeratorName(NameKind);

} // namespace mx
