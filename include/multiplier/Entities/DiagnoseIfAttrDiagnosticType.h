// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DiagnoseIfAttrDiagnosticType : unsigned char {
  ERROR,
  WARNING,
};

inline static const char *EnumerationName(DiagnoseIfAttrDiagnosticType) {
  return "DiagnoseIfAttrDiagnosticType";
}

inline static constexpr unsigned NumEnumerators(DiagnoseIfAttrDiagnosticType) {
  return 2;
}

const char *EnumeratorName(DiagnoseIfAttrDiagnosticType);

} // namespace mx
