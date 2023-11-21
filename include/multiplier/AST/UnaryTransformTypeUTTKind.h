// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class UnaryTransformTypeUTTKind : unsigned char {
  ADD_LVALUE_REFERENCE,
  ADD_POINTER,
  ADD_RVALUE_REFERENCE,
  DECAY,
  MAKE_SIGNED,
  MAKE_UNSIGNED,
  REMOVE_ALL_EXTENTS,
  REMOVE_CONST,
  REMOVE_CV,
  REMOVE_CV_REFERENCE,
  REMOVE_EXTENT,
  REMOVE_POINTER,
  REMOVE_REFERENCE,
  REMOVE_RESTRICT,
  REMOVE_VOLATILE,
  ENUM_UNDERLYING_TYPE,
};

inline static const char *EnumerationName(UnaryTransformTypeUTTKind) {
  return "UnaryTransformTypeUTTKind";
}

inline static constexpr unsigned NumEnumerators(UnaryTransformTypeUTTKind) {
  return 16;
}

const char *EnumeratorName(UnaryTransformTypeUTTKind);

} // namespace mx
