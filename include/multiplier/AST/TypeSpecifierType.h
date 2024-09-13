// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class TypeSpecifierType : unsigned char {
  UNSPECIFIED,
  VOID,
  CHARACTER,
  WCHAR,
  CHAR8,
  CHAR16,
  CHAR32,
  INT,
  INT128,
  BITINT,
  HALF,
  FLOAT16,
  ACCUM,
  FRACT,
  B_FLOAT16,
  FLOAT,
  DOUBLE,
  FLOAT128,
  IBM128,
  BOOLEAN,
  DECIMAL32,
  DECIMAL64,
  DECIMAL128,
  ENUM,
  UNION,
  STRUCT,
  CLASS,
  INTERFACE,
  TYPENAME,
  TYPEOF_TYPE,
  TYPEOF_EXPRESSION,
  TYPEOF_UNQUALIFIED_TYPE,
  TYPEOF_UNQUALIFIED_EXPRESSION,
  DECLTYPE,
  ADD_LVALUE_REFERENCE,
  ADD_POINTER,
  ADD_RVALUE_REFERENCE,
  DECAY,
  MAKE_SIGNED,
  MAKE_UNSIGNED,
  REMOVE_ALL_EXTENTS,
  REMOVE_CONST,
  REMOVE_CV,
  REMOVE_CVREF,
  REMOVE_EXTENT,
  REMOVE_POINTER,
  REMOVE_REFERENCE_T,
  REMOVE_RESTRICT,
  REMOVE_VOLATILE,
  UNDERLYING_TYPE,
  AUTO,
  DECLTYPE_AUTO,
  AUTO_TYPE,
  UNKNOWN_ANYTYPE,
  ATOMIC,
  IMAGE_1D_T,
  IMAGE_1D_ARRAY_T,
  IMAGE_1D_BUFFER_T,
  IMAGE_2D_T,
  IMAGE_2D_ARRAY_T,
  IMAGE_2D_DEPTH_T,
  IMAGE_2D_ARRAY_DEPTH_T,
  IMAGE_2D_MSAA_T,
  IMAGE_2D_ARRAY_MSAA_T,
  IMAGE_2D_MSAA_DEPTH_T,
  IMAGE_2D_ARRAY_MSAA_DEPTH_T,
  IMAGE_3D_T,
  ERROR,
};

inline static const char *EnumerationName(TypeSpecifierType) {
  return "TypeSpecifierType";
}

inline static constexpr unsigned NumEnumerators(TypeSpecifierType) {
  return 68;
}

MX_EXPORT const char *EnumeratorName(TypeSpecifierType);

} // namespace mx
