// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class ImplicitParamDeclImplicitParamKind : unsigned char {
  OBJ_C_SELF,
  OBJ_C_CMD,
  CXX_THIS,
  CXXVTT,
  CAPTURED_CONTEXT,
  OTHER,
};

inline static const char *EnumerationName(ImplicitParamDeclImplicitParamKind) {
  return "ImplicitParamDeclImplicitParamKind";
}

inline static constexpr unsigned NumEnumerators(ImplicitParamDeclImplicitParamKind) {
  return 6;
}

const char *EnumeratorName(ImplicitParamDeclImplicitParamKind);

} // namespace mx
