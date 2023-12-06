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
enum class XRayLogArgsAttrSpelling : unsigned char {
  GNU_XRAY_LOG_ARGUMENTS,
  CXX11_CLANG_XRAY_LOG_ARGUMENTS,
  C2X_CLANG_XRAY_LOG_ARGUMENTS,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(XRayLogArgsAttrSpelling) {
  return "XRayLogArgsAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(XRayLogArgsAttrSpelling) {
  return 4;
}

MX_EXPORT const char *EnumeratorName(XRayLogArgsAttrSpelling);

} // namespace mx
