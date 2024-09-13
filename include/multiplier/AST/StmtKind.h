// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

#include <cstdint>

namespace mx {
enum class StmtKind : unsigned char {
  WHILE_STMT,
  LABEL_STMT,
  VA_ARG_EXPR,
  UNARY_OPERATOR,
  UNARY_EXPR_OR_TYPE_TRAIT_EXPR,
  TYPO_EXPR,
  TYPE_TRAIT_EXPR,
  SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR,
  SUBST_NON_TYPE_TEMPLATE_PARM_EXPR,
  STRING_LITERAL,
  STMT_EXPR,
  SOURCE_LOC_EXPR,
  SIZE_OF_PACK_EXPR,
  SHUFFLE_VECTOR_EXPR,
  SYCL_UNIQUE_STABLE_NAME_EXPR,
  REQUIRES_EXPR,
  RECOVERY_EXPR,
  PSEUDO_OBJECT_EXPR,
  PREDEFINED_EXPR,
  PAREN_LIST_EXPR,
  PAREN_EXPR,
  PACK_EXPANSION_EXPR,
  UNRESOLVED_MEMBER_EXPR,
  UNRESOLVED_LOOKUP_EXPR,
  OPAQUE_VALUE_EXPR,
  OFFSET_OF_EXPR,
  OBJ_C_SUBSCRIPT_REF_EXPR,
  OBJ_C_STRING_LITERAL,
  OBJ_C_SELECTOR_EXPR,
  OBJ_C_PROTOCOL_EXPR,
  OBJ_C_PROPERTY_REF_EXPR,
  OBJ_C_MESSAGE_EXPR,
  OBJ_C_IVAR_REF_EXPR,
  OBJ_C_ISA_EXPR,
  OBJ_C_INDIRECT_COPY_RESTORE_EXPR,
  OBJ_C_ENCODE_EXPR,
  OBJ_C_DICTIONARY_LITERAL,
  OBJ_C_BOXED_EXPR,
  OBJ_C_BOOL_LITERAL_EXPR,
  OBJ_C_AVAILABILITY_CHECK_EXPR,
  OBJ_C_ARRAY_LITERAL,
  OMP_ITERATOR_EXPR,
  OMP_ARRAY_SHAPING_EXPR,
  OMP_ARRAY_SECTION_EXPR,
  NO_INIT_EXPR,
  MEMBER_EXPR,
  MATRIX_SUBSCRIPT_EXPR,
  MATERIALIZE_TEMPORARY_EXPR,
  MS_PROPERTY_SUBSCRIPT_EXPR,
  MS_PROPERTY_REF_EXPR,
  LAMBDA_EXPR,
  INTEGER_LITERAL,
  INIT_LIST_EXPR,
  IMPLICIT_VALUE_INIT_EXPR,
  IMAGINARY_LITERAL,
  GENERIC_SELECTION_EXPR,
  GNU_NULL_EXPR,
  FUNCTION_PARM_PACK_EXPR,
  EXPR_WITH_CLEANUPS,
  CONSTANT_EXPR,
  FLOATING_LITERAL,
  FIXED_POINT_LITERAL,
  EXT_VECTOR_ELEMENT_EXPR,
  EXPRESSION_TRAIT_EXPR,
  DESIGNATED_INIT_UPDATE_EXPR,
  DESIGNATED_INIT_EXPR,
  DEPENDENT_SCOPE_DECL_REF_EXPR,
  DEPENDENT_COAWAIT_EXPR,
  DECL_REF_EXPR,
  COYIELD_EXPR,
  COAWAIT_EXPR,
  CONVERT_VECTOR_EXPR,
  CONCEPT_SPECIALIZATION_EXPR,
  COMPOUND_LITERAL_EXPR,
  CHOOSE_EXPR,
  CHARACTER_LITERAL,
  IMPLICIT_CAST_EXPR,
  OBJ_C_BRIDGED_CAST_EXPR,
  CXX_STATIC_CAST_EXPR,
  CXX_REINTERPRET_CAST_EXPR,
  CXX_DYNAMIC_CAST_EXPR,
  CXX_CONST_CAST_EXPR,
  CXX_ADDRSPACE_CAST_EXPR,
  CXX_FUNCTIONAL_CAST_EXPR,
  C_STYLE_CAST_EXPR,
  BUILTIN_BIT_CAST_EXPR,
  CALL_EXPR,
  USER_DEFINED_LITERAL,
  CXX_OPERATOR_CALL_EXPR,
  CXX_MEMBER_CALL_EXPR,
  CUDA_KERNEL_CALL_EXPR,
  CXX_UUIDOF_EXPR,
  CXX_UNRESOLVED_CONSTRUCT_EXPR,
  CXX_TYPEID_EXPR,
  CXX_THROW_EXPR,
  CXX_THIS_EXPR,
  CXX_STD_INITIALIZER_LIST_EXPR,
  CXX_SCALAR_VALUE_INIT_EXPR,
  CXX_REWRITTEN_BINARY_OPERATOR,
  CXX_PSEUDO_DESTRUCTOR_EXPR,
  CXX_PAREN_LIST_INIT_EXPR,
  CXX_NULL_PTR_LITERAL_EXPR,
  CXX_NOEXCEPT_EXPR,
  CXX_NEW_EXPR,
  CXX_INHERITED_CTOR_INIT_EXPR,
  CXX_FOLD_EXPR,
  CXX_DEPENDENT_SCOPE_MEMBER_EXPR,
  CXX_DELETE_EXPR,
  CXX_DEFAULT_INIT_EXPR,
  CXX_DEFAULT_ARG_EXPR,
  CXX_CONSTRUCT_EXPR,
  CXX_TEMPORARY_OBJECT_EXPR,
  CXX_BOOL_LITERAL_EXPR,
  CXX_BIND_TEMPORARY_EXPR,
  BLOCK_EXPR,
  BINARY_OPERATOR,
  COMPOUND_ASSIGN_OPERATOR,
  ATOMIC_EXPR,
  AS_TYPE_EXPR,
  ARRAY_TYPE_TRAIT_EXPR,
  ARRAY_SUBSCRIPT_EXPR,
  ARRAY_INIT_LOOP_EXPR,
  ARRAY_INIT_INDEX_EXPR,
  ADDR_LABEL_EXPR,
  CONDITIONAL_OPERATOR,
  BINARY_CONDITIONAL_OPERATOR,
  ATTRIBUTED_STMT,
  SWITCH_STMT,
  DEFAULT_STMT,
  CASE_STMT,
  SEH_TRY_STMT,
  SEH_LEAVE_STMT,
  SEH_FINALLY_STMT,
  SEH_EXCEPT_STMT,
  RETURN_STMT,
  OBJ_C_FOR_COLLECTION_STMT,
  OBJ_C_AUTORELEASE_POOL_STMT,
  OBJ_C_AT_TRY_STMT,
  OBJ_C_AT_THROW_STMT,
  OBJ_C_AT_SYNCHRONIZED_STMT,
  OBJ_C_AT_FINALLY_STMT,
  OBJ_C_AT_CATCH_STMT,
  OMP_TEAMS_DIRECTIVE,
  OMP_TASKYIELD_DIRECTIVE,
  OMP_TASKWAIT_DIRECTIVE,
  OMP_TASKGROUP_DIRECTIVE,
  OMP_TASK_DIRECTIVE,
  OMP_TARGET_UPDATE_DIRECTIVE,
  OMP_TARGET_TEAMS_DIRECTIVE,
  OMP_TARGET_PARALLEL_FOR_DIRECTIVE,
  OMP_TARGET_PARALLEL_DIRECTIVE,
  OMP_TARGET_EXIT_DATA_DIRECTIVE,
  OMP_TARGET_ENTER_DATA_DIRECTIVE,
  OMP_TARGET_DIRECTIVE,
  OMP_TARGET_DATA_DIRECTIVE,
  OMP_SINGLE_DIRECTIVE,
  OMP_SECTIONS_DIRECTIVE,
  OMP_SECTION_DIRECTIVE,
  OMP_SCOPE_DIRECTIVE,
  OMP_SCAN_DIRECTIVE,
  OMP_PARALLEL_SECTIONS_DIRECTIVE,
  OMP_PARALLEL_MASTER_DIRECTIVE,
  OMP_PARALLEL_MASKED_DIRECTIVE,
  OMP_PARALLEL_DIRECTIVE,
  OMP_ORDERED_DIRECTIVE,
  OMP_META_DIRECTIVE,
  OMP_MASTER_DIRECTIVE,
  OMP_MASKED_DIRECTIVE,
  OMP_UNROLL_DIRECTIVE,
  OMP_TILE_DIRECTIVE,
  OMP_TEAMS_GENERIC_LOOP_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_DIRECTIVE,
  OMP_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_TASK_LOOP_DIRECTIVE,
  OMP_TARGET_TEAMS_GENERIC_LOOP_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE,
  OMP_TARGET_SIMD_DIRECTIVE,
  OMP_TARGET_PARALLEL_GENERIC_LOOP_DIRECTIVE,
  OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_SIMD_DIRECTIVE,
  OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE,
  OMP_PARALLEL_MASKED_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_PARALLEL_MASKED_TASK_LOOP_DIRECTIVE,
  OMP_PARALLEL_GENERIC_LOOP_DIRECTIVE,
  OMP_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_PARALLEL_FOR_DIRECTIVE,
  OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_MASTER_TASK_LOOP_DIRECTIVE,
  OMP_MASKED_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_MASKED_TASK_LOOP_DIRECTIVE,
  OMP_GENERIC_LOOP_DIRECTIVE,
  OMP_FOR_SIMD_DIRECTIVE,
  OMP_FOR_DIRECTIVE,
  OMP_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_DISTRIBUTE_DIRECTIVE,
  OMP_INTEROP_DIRECTIVE,
  OMP_FLUSH_DIRECTIVE,
  OMP_ERROR_DIRECTIVE,
  OMP_DISPATCH_DIRECTIVE,
  OMP_DEPOBJ_DIRECTIVE,
  OMP_CRITICAL_DIRECTIVE,
  OMP_CANCELLATION_POINT_DIRECTIVE,
  OMP_CANCEL_DIRECTIVE,
  OMP_BARRIER_DIRECTIVE,
  OMP_ATOMIC_DIRECTIVE,
  OMP_CANONICAL_LOOP,
  NULL_STMT,
  MS_DEPENDENT_EXISTS_STMT,
  INDIRECT_GOTO_STMT,
  IF_STMT,
  GOTO_STMT,
  FOR_STMT,
  DO_STMT,
  DECL_STMT,
  COROUTINE_BODY_STMT,
  CORETURN_STMT,
  CONTINUE_STMT,
  COMPOUND_STMT,
  CAPTURED_STMT,
  CXX_TRY_STMT,
  CXX_FOR_RANGE_STMT,
  CXX_CATCH_STMT,
  BREAK_STMT,
  MS_ASM_STMT,
  GCC_ASM_STMT,
};

inline static const char *EnumerationName(StmtKind) {
  return "StmtKind";
}

inline static constexpr unsigned NumEnumerators(StmtKind) {
  return 234;
}

MX_EXPORT const char *EnumeratorName(StmtKind);

} // namespace mx
