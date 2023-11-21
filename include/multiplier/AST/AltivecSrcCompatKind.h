// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class AltivecSrcCompatKind : unsigned char {
  MIXED,
  GCC,
  XL,
  // Skipped repeat pasta::kDefault
};

inline static const char *EnumerationName(AltivecSrcCompatKind) {
  return "AltivecSrcCompatKind";
}

inline static constexpr unsigned NumEnumerators(AltivecSrcCompatKind) {
  return 3;
}

const char *EnumeratorName(AltivecSrcCompatKind);

} // namespace mx
