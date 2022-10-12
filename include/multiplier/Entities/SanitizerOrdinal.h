// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
enum class SanitizerOrdinal : unsigned char {
  ADDRESS,
  POINTER_COMPARE,
  POINTER_SUBTRACT,
  KERNEL_ADDRESS,
  HW_ADDRESS,
  KERNEL_HW_ADDRESS,
  MEMORY_TAG,
  MEMORY,
  KERNEL_MEMORY,
  FUZZER,
  FUZZER_NO_LINK,
  THREAD,
  LEAK,
  ALIGNMENT,
  ARRAY_BOUNDS,
  BOOLEAN,
  BUILTIN,
  ENUM,
  FLOAT_CAST_OVERFLOW,
  FLOAT_DIVIDE_BY_ZERO,
  FUNCTION,
  INTEGER_DIVIDE_BY_ZERO,
  NONNULL_ATTRIBUTE,
  NULL_,
  NULLABILITY_ARGUMENT,
  NULLABILITY_ASSIGN,
  NULLABILITY_RETURN,
  NULLABILITY_GROUP,
  OBJECT_SIZE,
  POINTER_OVERFLOW,
  RETURN,
  RETURNS_NONNULL_ATTRIBUTE,
  SHIFT_BASE,
  SHIFT_EXPONENT,
  SHIFT_GROUP,
  SIGNED_INTEGER_OVERFLOW,
  UNREACHABLE,
  VLA_BOUND,
  VPTR,
  UNSIGNED_INTEGER_OVERFLOW,
  UNSIGNED_SHIFT_BASE,
  DATA_FLOW,
  CFI_CAST_STRICT,
  CFI_DERIVED_CAST,
  CFII_CALL,
  CFIMF_CALL,
  CFI_UNRELATED_CAST,
  CFINV_CALL,
  CFIV_CALL,
  CFI_GROUP,
  SAFE_STACK,
  SHADOW_CALL_STACK,
  UNDEFINED_GROUP,
  UNDEFINED_TRAP_GROUP,
  IMPLICIT_UNSIGNED_INTEGER_TRUNCATION,
  IMPLICIT_SIGNED_INTEGER_TRUNCATION,
  IMPLICIT_INTEGER_TRUNCATION_GROUP,
  IMPLICIT_INTEGER_SIGN_CHANGE,
  IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP,
  OBJ_C_CAST,
  IMPLICIT_CONVERSION_GROUP,
  INTEGER_GROUP,
  LOCAL_BOUNDS,
  BOUNDS_GROUP,
  SCUDO,
  ALL_GROUP,
  COUNT,
};

inline static const char *EnumerationName(SanitizerOrdinal) {
  return "SanitizerOrdinal";
}

inline static constexpr unsigned NumEnumerators(SanitizerOrdinal) {
  return 67;
}

const char *EnumeratorName(SanitizerOrdinal);

} // namespace mx
