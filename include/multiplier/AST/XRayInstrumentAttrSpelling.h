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
enum class XRayInstrumentAttrSpelling : unsigned char {
  GNU_XRAY_ALWAYS_INSTRUMENT,
  CXX11_CLANG_XRAY_ALWAYS_INSTRUMENT,
  C2X_CLANG_XRAY_ALWAYS_INSTRUMENT,
  GNU_XRAY_NEVER_INSTRUMENT,
  CXX11_CLANG_XRAY_NEVER_INSTRUMENT,
  C2X_CLANG_XRAY_NEVER_INSTRUMENT,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(XRayInstrumentAttrSpelling) {
  return "XRayInstrumentAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(XRayInstrumentAttrSpelling) {
  return 7;
}

MX_EXPORT const char *EnumeratorName(XRayInstrumentAttrSpelling);

} // namespace mx
