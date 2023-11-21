// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class VarDeclDefinitionKind : unsigned char {
  DECLARATION_ONLY,
  TENTATIVE_DEFINITION,
  DEFINITION,
};

inline static const char *EnumerationName(VarDeclDefinitionKind) {
  return "VarDeclDefinitionKind";
}

inline static constexpr unsigned NumEnumerators(VarDeclDefinitionKind) {
  return 3;
}

const char *EnumeratorName(VarDeclDefinitionKind);

} // namespace mx
