// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CastKind.h>
namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CastKind e) {
  switch (e) {
    case CastKind::DEPENDENT: return "DEPENDENT";
    case CastKind::BIT_CAST: return "BIT_CAST";
    case CastKind::L_VALUE_BIT_CAST: return "L_VALUE_BIT_CAST";
    case CastKind::L_VALUE_TO_R_VALUE_BIT_CAST: return "L_VALUE_TO_R_VALUE_BIT_CAST";
    case CastKind::L_VALUE_TO_R_VALUE: return "L_VALUE_TO_R_VALUE";
    case CastKind::NO_OPERATION: return "NO_OPERATION";
    case CastKind::BASE_TO_DERIVED: return "BASE_TO_DERIVED";
    case CastKind::DERIVED_TO_BASE: return "DERIVED_TO_BASE";
    case CastKind::UNCHECKED_DERIVED_TO_BASE: return "UNCHECKED_DERIVED_TO_BASE";
    case CastKind::DYNAMIC: return "DYNAMIC";
    case CastKind::TO_UNION: return "TO_UNION";
    case CastKind::ARRAY_TO_POINTER_DECAY: return "ARRAY_TO_POINTER_DECAY";
    case CastKind::FUNCTION_TO_POINTER_DECAY: return "FUNCTION_TO_POINTER_DECAY";
    case CastKind::NULL_TO_POINTER: return "NULL_TO_POINTER";
    case CastKind::NULL_TO_MEMBER_POINTER: return "NULL_TO_MEMBER_POINTER";
    case CastKind::BASE_TO_DERIVED_MEMBER_POINTER: return "BASE_TO_DERIVED_MEMBER_POINTER";
    case CastKind::DERIVED_TO_BASE_MEMBER_POINTER: return "DERIVED_TO_BASE_MEMBER_POINTER";
    case CastKind::MEMBER_POINTER_TO_BOOLEAN: return "MEMBER_POINTER_TO_BOOLEAN";
    case CastKind::REINTERPRET_MEMBER_POINTER: return "REINTERPRET_MEMBER_POINTER";
    case CastKind::USER_DEFINED_CONVERSION: return "USER_DEFINED_CONVERSION";
    case CastKind::CONSTRUCTOR_CONVERSION: return "CONSTRUCTOR_CONVERSION";
    case CastKind::INTEGRAL_TO_POINTER: return "INTEGRAL_TO_POINTER";
    case CastKind::POINTER_TO_INTEGRAL: return "POINTER_TO_INTEGRAL";
    case CastKind::POINTER_TO_BOOLEAN: return "POINTER_TO_BOOLEAN";
    case CastKind::TO_VOID: return "TO_VOID";
    case CastKind::MATRIX_CAST: return "MATRIX_CAST";
    case CastKind::VECTOR_SPLAT: return "VECTOR_SPLAT";
    case CastKind::INTEGRAL_CAST: return "INTEGRAL_CAST";
    case CastKind::INTEGRAL_TO_BOOLEAN: return "INTEGRAL_TO_BOOLEAN";
    case CastKind::INTEGRAL_TO_FLOATING: return "INTEGRAL_TO_FLOATING";
    case CastKind::FLOATING_TO_FIXED_POINT: return "FLOATING_TO_FIXED_POINT";
    case CastKind::FIXED_POINT_TO_FLOATING: return "FIXED_POINT_TO_FLOATING";
    case CastKind::FIXED_POINT_CAST: return "FIXED_POINT_CAST";
    case CastKind::FIXED_POINT_TO_INTEGRAL: return "FIXED_POINT_TO_INTEGRAL";
    case CastKind::INTEGRAL_TO_FIXED_POINT: return "INTEGRAL_TO_FIXED_POINT";
    case CastKind::FIXED_POINT_TO_BOOLEAN: return "FIXED_POINT_TO_BOOLEAN";
    case CastKind::FLOATING_TO_INTEGRAL: return "FLOATING_TO_INTEGRAL";
    case CastKind::FLOATING_TO_BOOLEAN: return "FLOATING_TO_BOOLEAN";
    case CastKind::BOOLEAN_TO_SIGNED_INTEGRAL: return "BOOLEAN_TO_SIGNED_INTEGRAL";
    case CastKind::FLOATING_CAST: return "FLOATING_CAST";
    case CastKind::C_POINTER_TO_OBJ_C_POINTER_CAST: return "C_POINTER_TO_OBJ_C_POINTER_CAST";
    case CastKind::BLOCK_POINTER_TO_OBJ_C_POINTER_CAST: return "BLOCK_POINTER_TO_OBJ_C_POINTER_CAST";
    case CastKind::ANY_POINTER_TO_BLOCK_POINTER_CAST: return "ANY_POINTER_TO_BLOCK_POINTER_CAST";
    case CastKind::OBJ_C_OBJECT_L_VALUE_CAST: return "OBJ_C_OBJECT_L_VALUE_CAST";
    case CastKind::FLOATING_REAL_TO_COMPLEX: return "FLOATING_REAL_TO_COMPLEX";
    case CastKind::FLOATING_COMPLEX_TO_REAL: return "FLOATING_COMPLEX_TO_REAL";
    case CastKind::FLOATING_COMPLEX_TO_BOOLEAN: return "FLOATING_COMPLEX_TO_BOOLEAN";
    case CastKind::FLOATING_COMPLEX_CAST: return "FLOATING_COMPLEX_CAST";
    case CastKind::FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX: return "FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX";
    case CastKind::INTEGRAL_REAL_TO_COMPLEX: return "INTEGRAL_REAL_TO_COMPLEX";
    case CastKind::INTEGRAL_COMPLEX_TO_REAL: return "INTEGRAL_COMPLEX_TO_REAL";
    case CastKind::INTEGRAL_COMPLEX_TO_BOOLEAN: return "INTEGRAL_COMPLEX_TO_BOOLEAN";
    case CastKind::INTEGRAL_COMPLEX_CAST: return "INTEGRAL_COMPLEX_CAST";
    case CastKind::INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX: return "INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX";
    case CastKind::ARC_PRODUCE_OBJECT: return "ARC_PRODUCE_OBJECT";
    case CastKind::ARC_CONSUME_OBJECT: return "ARC_CONSUME_OBJECT";
    case CastKind::ARC_RECLAIM_RETURNED_OBJECT: return "ARC_RECLAIM_RETURNED_OBJECT";
    case CastKind::ARC_EXTEND_BLOCK_OBJECT: return "ARC_EXTEND_BLOCK_OBJECT";
    case CastKind::ATOMIC_TO_NON_ATOMIC: return "ATOMIC_TO_NON_ATOMIC";
    case CastKind::NON_ATOMIC_TO_ATOMIC: return "NON_ATOMIC_TO_ATOMIC";
    case CastKind::COPY_AND_AUTORELEASE_BLOCK_OBJECT: return "COPY_AND_AUTORELEASE_BLOCK_OBJECT";
    case CastKind::BUILTIN_FN_TO_FN_POINTER: return "BUILTIN_FN_TO_FN_POINTER";
    case CastKind::ZERO_TO_OCL_OPAQUE_TYPE: return "ZERO_TO_OCL_OPAQUE_TYPE";
    case CastKind::ADDRESS_SPACE_CONVERSION: return "ADDRESS_SPACE_CONVERSION";
    case CastKind::INT_TO_OCL_SAMPLER: return "INT_TO_OCL_SAMPLER";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
