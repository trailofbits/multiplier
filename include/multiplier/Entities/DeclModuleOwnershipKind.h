// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DeclModuleOwnershipKind : unsigned char {
  UNOWNED,
  VISIBLE,
  VISIBLE_WHEN_IMPORTED,
  MODULE_PRIVATE,
};

inline static const char *EnumerationName(DeclModuleOwnershipKind) {
  return "DeclModuleOwnershipKind";
}

inline static constexpr unsigned NumEnumerators(DeclModuleOwnershipKind) {
  return 4;
}

const char *EnumeratorName(DeclModuleOwnershipKind);

} // namespace mx
