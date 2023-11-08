// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class DiagnoseAsBuiltinAttrSpelling : unsigned char {
  GNU_DIAGNOSE_AS_BUILTIN,
  CXX11_CLANG_DIAGNOSE_AS_BUILTIN,
  C23_CLANG_DIAGNOSE_AS_BUILTIN,
  SPELLING_NOT_CALCULATED,
};

inline static const char *EnumerationName(DiagnoseAsBuiltinAttrSpelling) {
  return "DiagnoseAsBuiltinAttrSpelling";
}

inline static constexpr unsigned NumEnumerators(DiagnoseAsBuiltinAttrSpelling) {
  return 4;
}

const char *EnumeratorName(DiagnoseAsBuiltinAttrSpelling);

} // namespace mx
