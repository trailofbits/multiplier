// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DeclCategory : unsigned char {
  UNKNOWN,
  LOCAL_VARIABLE,
  GLOBAL_VARIABLE,
  PARAMETER_VARIABLE,
  FUNCTION,
  INSTANCE_METHOD,
  INSTANCE_MEMBER,
  CLASS_METHOD,
  CLASS_MEMBER,
  THIS,
  CLASS,
  STRUCTURE,
  UNION,
  CONCEPT,
  INTERFACE,
  ENUMERATION,
  ENUMERATOR,
  NAMESPACE,
  TYPE_ALIAS,
  TEMPLATE_TYPE_PARAMETER,
  TEMPLATE_VALUE_PARAMETER,
  LABEL,
};

inline static const char *EnumerationName(DeclCategory) {
  return "DeclCategory";
}

inline static constexpr unsigned NumEnumerators(DeclCategory) {
  return 22;
}

const char *EnumeratorName(DeclCategory);

} // namespace mx
