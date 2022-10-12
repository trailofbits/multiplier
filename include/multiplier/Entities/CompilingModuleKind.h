// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class CompilingModuleKind : unsigned char {
  NONE,
  MODULE_MAP,
  HEADER_MODULE,
  MODULE_INTERFACE,
};

inline static const char *EnumerationName(CompilingModuleKind) {
  return "CompilingModuleKind";
}

inline static constexpr unsigned NumEnumerators(CompilingModuleKind) {
  return 4;
}

const char *EnumeratorName(CompilingModuleKind);

} // namespace mx
