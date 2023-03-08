// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/SanitizerOrdinal.h>


#include "../API.h"
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(SanitizerOrdinal e) {
  switch (e) {
    case SanitizerOrdinal::ADDRESS: return "ADDRESS";
    case SanitizerOrdinal::POINTER_COMPARE: return "POINTER_COMPARE";
    case SanitizerOrdinal::POINTER_SUBTRACT: return "POINTER_SUBTRACT";
    case SanitizerOrdinal::KERNEL_ADDRESS: return "KERNEL_ADDRESS";
    case SanitizerOrdinal::HW_ADDRESS: return "HW_ADDRESS";
    case SanitizerOrdinal::KERNEL_HW_ADDRESS: return "KERNEL_HW_ADDRESS";
    case SanitizerOrdinal::MEMTAG_STACK: return "MEMTAG_STACK";
    case SanitizerOrdinal::MEMTAG_HEAP: return "MEMTAG_HEAP";
    case SanitizerOrdinal::MEMTAG_GLOBALS: return "MEMTAG_GLOBALS";
    case SanitizerOrdinal::MEMORY_TAG_GROUP: return "MEMORY_TAG_GROUP";
    case SanitizerOrdinal::MEMORY: return "MEMORY";
    case SanitizerOrdinal::KERNEL_MEMORY: return "KERNEL_MEMORY";
    case SanitizerOrdinal::FUZZER: return "FUZZER";
    case SanitizerOrdinal::FUZZER_NO_LINK: return "FUZZER_NO_LINK";
    case SanitizerOrdinal::THREAD: return "THREAD";
    case SanitizerOrdinal::LEAK: return "LEAK";
    case SanitizerOrdinal::ALIGNMENT: return "ALIGNMENT";
    case SanitizerOrdinal::ARRAY_BOUNDS: return "ARRAY_BOUNDS";
    case SanitizerOrdinal::BOOLEAN: return "BOOLEAN";
    case SanitizerOrdinal::BUILTIN: return "BUILTIN";
    case SanitizerOrdinal::ENUM: return "ENUM";
    case SanitizerOrdinal::FLOAT_CAST_OVERFLOW: return "FLOAT_CAST_OVERFLOW";
    case SanitizerOrdinal::FLOAT_DIVIDE_BY_ZERO: return "FLOAT_DIVIDE_BY_ZERO";
    case SanitizerOrdinal::FUNCTION: return "FUNCTION";
    case SanitizerOrdinal::INTEGER_DIVIDE_BY_ZERO: return "INTEGER_DIVIDE_BY_ZERO";
    case SanitizerOrdinal::NONNULL_ATTRIBUTE: return "NONNULL_ATTRIBUTE";
    case SanitizerOrdinal::NULL_: return "NULL_";
    case SanitizerOrdinal::NULLABILITY_ARGUMENT: return "NULLABILITY_ARGUMENT";
    case SanitizerOrdinal::NULLABILITY_ASSIGN: return "NULLABILITY_ASSIGN";
    case SanitizerOrdinal::NULLABILITY_RETURN: return "NULLABILITY_RETURN";
    case SanitizerOrdinal::NULLABILITY_GROUP: return "NULLABILITY_GROUP";
    case SanitizerOrdinal::OBJECT_SIZE: return "OBJECT_SIZE";
    case SanitizerOrdinal::POINTER_OVERFLOW: return "POINTER_OVERFLOW";
    case SanitizerOrdinal::RETURN: return "RETURN";
    case SanitizerOrdinal::RETURNS_NONNULL_ATTRIBUTE: return "RETURNS_NONNULL_ATTRIBUTE";
    case SanitizerOrdinal::SHIFT_BASE: return "SHIFT_BASE";
    case SanitizerOrdinal::SHIFT_EXPONENT: return "SHIFT_EXPONENT";
    case SanitizerOrdinal::SHIFT_GROUP: return "SHIFT_GROUP";
    case SanitizerOrdinal::SIGNED_INTEGER_OVERFLOW: return "SIGNED_INTEGER_OVERFLOW";
    case SanitizerOrdinal::UNREACHABLE: return "UNREACHABLE";
    case SanitizerOrdinal::VLA_BOUND: return "VLA_BOUND";
    case SanitizerOrdinal::VPTR: return "VPTR";
    case SanitizerOrdinal::UNSIGNED_INTEGER_OVERFLOW: return "UNSIGNED_INTEGER_OVERFLOW";
    case SanitizerOrdinal::UNSIGNED_SHIFT_BASE: return "UNSIGNED_SHIFT_BASE";
    case SanitizerOrdinal::DATA_FLOW: return "DATA_FLOW";
    case SanitizerOrdinal::CFI_CAST_STRICT: return "CFI_CAST_STRICT";
    case SanitizerOrdinal::CFI_DERIVED_CAST: return "CFI_DERIVED_CAST";
    case SanitizerOrdinal::CFII_CALL: return "CFII_CALL";
    case SanitizerOrdinal::CFIMF_CALL: return "CFIMF_CALL";
    case SanitizerOrdinal::CFI_UNRELATED_CAST: return "CFI_UNRELATED_CAST";
    case SanitizerOrdinal::CFINV_CALL: return "CFINV_CALL";
    case SanitizerOrdinal::CFIV_CALL: return "CFIV_CALL";
    case SanitizerOrdinal::CFI_GROUP: return "CFI_GROUP";
    case SanitizerOrdinal::SAFE_STACK: return "SAFE_STACK";
    case SanitizerOrdinal::SHADOW_CALL_STACK: return "SHADOW_CALL_STACK";
    case SanitizerOrdinal::UNDEFINED_GROUP: return "UNDEFINED_GROUP";
    case SanitizerOrdinal::UNDEFINED_TRAP_GROUP: return "UNDEFINED_TRAP_GROUP";
    case SanitizerOrdinal::IMPLICIT_UNSIGNED_INTEGER_TRUNCATION: return "IMPLICIT_UNSIGNED_INTEGER_TRUNCATION";
    case SanitizerOrdinal::IMPLICIT_SIGNED_INTEGER_TRUNCATION: return "IMPLICIT_SIGNED_INTEGER_TRUNCATION";
    case SanitizerOrdinal::IMPLICIT_INTEGER_TRUNCATION_GROUP: return "IMPLICIT_INTEGER_TRUNCATION_GROUP";
    case SanitizerOrdinal::IMPLICIT_INTEGER_SIGN_CHANGE: return "IMPLICIT_INTEGER_SIGN_CHANGE";
    case SanitizerOrdinal::IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP: return "IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP";
    case SanitizerOrdinal::OBJ_C_CAST: return "OBJ_C_CAST";
    case SanitizerOrdinal::IMPLICIT_CONVERSION_GROUP: return "IMPLICIT_CONVERSION_GROUP";
    case SanitizerOrdinal::INTEGER_GROUP: return "INTEGER_GROUP";
    case SanitizerOrdinal::LOCAL_BOUNDS: return "LOCAL_BOUNDS";
    case SanitizerOrdinal::BOUNDS_GROUP: return "BOUNDS_GROUP";
    case SanitizerOrdinal::SCUDO: return "SCUDO";
    case SanitizerOrdinal::ALL_GROUP: return "ALL_GROUP";
    case SanitizerOrdinal::COUNT: return "COUNT";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
