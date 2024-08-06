// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/AttributeKind.h>

namespace mx {

const char *EnumeratorName(ir::AttributeKind kind) {
  switch (kind) {
    default: return "UNKNOWN";
    case ir::AttributeKind::BUILTIN_TYPED: return "BUILTIN_TYPED";
    case ir::AttributeKind::BUILTIN_ELEMENTS: return "BUILTIN_ELEMENTS";
    case ir::AttributeKind::BUILTIN_AFFINE_MAP: return "BUILTIN_AFFINE_MAP";
    case ir::AttributeKind::BUILTIN_ARRAY: return "BUILTIN_ARRAY";
    case ir::AttributeKind::BUILTIN_DENSE_ARRAY: return "BUILTIN_DENSE_ARRAY";
    case ir::AttributeKind::BUILTIN_DENSE_INT_OR_FP_ELEMENTS: return "BUILTIN_DENSE_INT_OR_FP_ELEMENTS";
    case ir::AttributeKind::BUILTIN_DENSE_STRING_ELEMENTS: return "BUILTIN_DENSE_STRING_ELEMENTS";
    case ir::AttributeKind::BUILTIN_DENSE_RESOURCE_ELEMENTS: return "BUILTIN_DENSE_RESOURCE_ELEMENTS";
    case ir::AttributeKind::BUILTIN_DICTIONARY: return "BUILTIN_DICTIONARY";
    case ir::AttributeKind::BUILTIN_FLOAT: return "BUILTIN_FLOAT";
    case ir::AttributeKind::BUILTIN_INTEGER: return "BUILTIN_INTEGER";
    case ir::AttributeKind::BUILTIN_INTEGER_SET: return "BUILTIN_INTEGER_SET";
    case ir::AttributeKind::BUILTIN_OPAQUE: return "BUILTIN_OPAQUE";
    case ir::AttributeKind::BUILTIN_SPARSE_ELEMENTS: return "BUILTIN_SPARSE_ELEMENTS";
    case ir::AttributeKind::BUILTIN_STRIDED_LAYOUT: return "BUILTIN_STRIDED_LAYOUT";
    case ir::AttributeKind::BUILTIN_STRING: return "BUILTIN_STRING";
    case ir::AttributeKind::BUILTIN_SYMBOL_REF: return "BUILTIN_SYMBOL_REF";
    case ir::AttributeKind::BUILTIN_TYPE: return "BUILTIN_TYPE";
    case ir::AttributeKind::BUILTIN_UNIT: return "BUILTIN_UNIT";
    case ir::AttributeKind::BUILTIN_BOOL: return "BUILTIN_BOOL";
    case ir::AttributeKind::BUILTIN_FLAT_SYMBOL_REF: return "BUILTIN_FLAT_SYMBOL_REF";
    case ir::AttributeKind::BUILTIN_DENSE_INT_ELEMENTS: return "BUILTIN_DENSE_INT_ELEMENTS";
    case ir::AttributeKind::LLVM_C_CONV: return "LLVM_C_CONV";
    case ir::AttributeKind::LLVM_COMDAT: return "LLVM_COMDAT";
    case ir::AttributeKind::LLVM_LINKAGE: return "LLVM_LINKAGE";
    case ir::AttributeKind::LLVM_FRAME_POINTER_KIND: return "LLVM_FRAME_POINTER_KIND";
    case ir::AttributeKind::LLVM_LOOP_VECTORIZE: return "LLVM_LOOP_VECTORIZE";
    case ir::AttributeKind::LLVM_LOOP_INTERLEAVE: return "LLVM_LOOP_INTERLEAVE";
    case ir::AttributeKind::LLVM_LOOP_UNROLL: return "LLVM_LOOP_UNROLL";
    case ir::AttributeKind::LLVM_LOOP_UNROLL_AND_JAM: return "LLVM_LOOP_UNROLL_AND_JAM";
    case ir::AttributeKind::LLVM_LOOP_LICM: return "LLVM_LOOP_LICM";
    case ir::AttributeKind::LLVM_LOOP_DISTRIBUTE: return "LLVM_LOOP_DISTRIBUTE";
    case ir::AttributeKind::LLVM_LOOP_PIPELINE: return "LLVM_LOOP_PIPELINE";
    case ir::AttributeKind::LLVM_LOOP_PEELED: return "LLVM_LOOP_PEELED";
    case ir::AttributeKind::LLVM_LOOP_UNSWITCH: return "LLVM_LOOP_UNSWITCH";
    case ir::AttributeKind::LLVM_LOOP_ANNOTATION: return "LLVM_LOOP_ANNOTATION";
    case ir::AttributeKind::LLVM_DI_EXPRESSION_ELEM: return "LLVM_DI_EXPRESSION_ELEM";
    case ir::AttributeKind::LLVM_DI_EXPRESSION: return "LLVM_DI_EXPRESSION";
    case ir::AttributeKind::LLVM_DI_NULL_TYPE: return "LLVM_DI_NULL_TYPE";
    case ir::AttributeKind::LLVM_DI_BASIC_TYPE: return "LLVM_DI_BASIC_TYPE";
    case ir::AttributeKind::LLVM_DI_COMPILE_UNIT: return "LLVM_DI_COMPILE_UNIT";
    case ir::AttributeKind::LLVM_DI_COMPOSITE_TYPE: return "LLVM_DI_COMPOSITE_TYPE";
    case ir::AttributeKind::LLVM_DI_DERIVED_TYPE: return "LLVM_DI_DERIVED_TYPE";
    case ir::AttributeKind::LLVM_DI_FILE: return "LLVM_DI_FILE";
    case ir::AttributeKind::LLVM_DI_GLOBAL_VARIABLE_EXPRESSION: return "LLVM_DI_GLOBAL_VARIABLE_EXPRESSION";
    case ir::AttributeKind::LLVM_DI_GLOBAL_VARIABLE: return "LLVM_DI_GLOBAL_VARIABLE";
    case ir::AttributeKind::LLVM_DI_LEXICAL_BLOCK: return "LLVM_DI_LEXICAL_BLOCK";
    case ir::AttributeKind::LLVM_DI_LEXICAL_BLOCK_FILE: return "LLVM_DI_LEXICAL_BLOCK_FILE";
    case ir::AttributeKind::LLVM_DI_LOCAL_VARIABLE: return "LLVM_DI_LOCAL_VARIABLE";
    case ir::AttributeKind::LLVM_DI_SUBPROGRAM: return "LLVM_DI_SUBPROGRAM";
    case ir::AttributeKind::LLVM_DI_MODULE: return "LLVM_DI_MODULE";
    case ir::AttributeKind::LLVM_DI_NAMESPACE: return "LLVM_DI_NAMESPACE";
    case ir::AttributeKind::LLVM_DI_SUBRANGE: return "LLVM_DI_SUBRANGE";
    case ir::AttributeKind::LLVM_DI_SUBROUTINE_TYPE: return "LLVM_DI_SUBROUTINE_TYPE";
    case ir::AttributeKind::LLVM_DI_LABEL: return "LLVM_DI_LABEL";
    case ir::AttributeKind::LLVM_MEMORY_EFFECTS: return "LLVM_MEMORY_EFFECTS";
    case ir::AttributeKind::LLVM_ALIAS_SCOPE_DOMAIN: return "LLVM_ALIAS_SCOPE_DOMAIN";
    case ir::AttributeKind::LLVM_ALIAS_SCOPE: return "LLVM_ALIAS_SCOPE";
    case ir::AttributeKind::LLVM_ACCESS_GROUP: return "LLVM_ACCESS_GROUP";
    case ir::AttributeKind::LLVM_TBAA_ROOT: return "LLVM_TBAA_ROOT";
    case ir::AttributeKind::LLVM_TBAA_MEMBER: return "LLVM_TBAA_MEMBER";
    case ir::AttributeKind::LLVM_TBAA_TYPE_DESCRIPTOR: return "LLVM_TBAA_TYPE_DESCRIPTOR";
    case ir::AttributeKind::LLVM_TBAA_TAG: return "LLVM_TBAA_TAG";
    case ir::AttributeKind::LLVM_V_SCALE_RANGE: return "LLVM_V_SCALE_RANGE";
    case ir::AttributeKind::LLVM_TARGET_FEATURES: return "LLVM_TARGET_FEATURES";
    case ir::AttributeKind::LLVM_INTEGER_OVERFLOW_FLAGS: return "LLVM_INTEGER_OVERFLOW_FLAGS";
    case ir::AttributeKind::LLVM_FASTMATH_FLAGS: return "LLVM_FASTMATH_FLAGS";
    case ir::AttributeKind::HL_ANNOTATION: return "HL_ANNOTATION";
    case ir::AttributeKind::HL_FORMAT: return "HL_FORMAT";
    case ir::AttributeKind::HL_SECTION: return "HL_SECTION";
    case ir::AttributeKind::HL_ALIAS: return "HL_ALIAS";
    case ir::AttributeKind::HL_ALIGNED: return "HL_ALIGNED";
    case ir::AttributeKind::HL_ALWAYS_INLINE: return "HL_ALWAYS_INLINE";
    case ir::AttributeKind::HL_NO_INLINE: return "HL_NO_INLINE";
    case ir::AttributeKind::HL_CONST: return "HL_CONST";
    case ir::AttributeKind::HL_LOADER_UNINITIALIZED: return "HL_LOADER_UNINITIALIZED";
    case ir::AttributeKind::HL_NO_INSTRUMENT_FUNCTION: return "HL_NO_INSTRUMENT_FUNCTION";
    case ir::AttributeKind::HL_PACKED: return "HL_PACKED";
    case ir::AttributeKind::HL_PURE: return "HL_PURE";
    case ir::AttributeKind::HL_WARN_UNUSED_RESULT: return "HL_WARN_UNUSED_RESULT";
    case ir::AttributeKind::HL_RESTRICT: return "HL_RESTRICT";
    case ir::AttributeKind::HL_NO_THROW: return "HL_NO_THROW";
    case ir::AttributeKind::HL_NON_NULL: return "HL_NON_NULL";
    case ir::AttributeKind::HL_LEAF: return "HL_LEAF";
    case ir::AttributeKind::HL_COLD: return "HL_COLD";
    case ir::AttributeKind::HL_TRANSPARENT_UNION: return "HL_TRANSPARENT_UNION";
    case ir::AttributeKind::HL_RETURNS_TWICE: return "HL_RETURNS_TWICE";
    case ir::AttributeKind::HL_MAY_ALIAS: return "HL_MAY_ALIAS";
    case ir::AttributeKind::HL_UNUSED: return "HL_UNUSED";
    case ir::AttributeKind::HL_USED: return "HL_USED";
    case ir::AttributeKind::HL_GNU_INLINE: return "HL_GNU_INLINE";
    case ir::AttributeKind::HL_NO_CF_CHECK: return "HL_NO_CF_CHECK";
    case ir::AttributeKind::HL_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD: return "HL_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD";
    case ir::AttributeKind::HL_AVAILABILITY_ATTR: return "HL_AVAILABILITY_ATTR";
    case ir::AttributeKind::HL_ASM_LABEL: return "HL_ASM_LABEL";
    case ir::AttributeKind::HL_MODE: return "HL_MODE";
    case ir::AttributeKind::HL_BUILTIN: return "HL_BUILTIN";
    case ir::AttributeKind::HL_ALLOC_ALIGN: return "HL_ALLOC_ALIGN";
    case ir::AttributeKind::HL_ALLOC_SIZE: return "HL_ALLOC_SIZE";
    case ir::AttributeKind::HL_DEPRECATED: return "HL_DEPRECATED";
    case ir::AttributeKind::HL_MAX_FIELD_ALIGNMENT: return "HL_MAX_FIELD_ALIGNMENT";
    case ir::AttributeKind::HL_CV_QUALIFIERS: return "HL_CV_QUALIFIERS";
    case ir::AttributeKind::HL_UCV_QUALIFIERS: return "HL_UCV_QUALIFIERS";
    case ir::AttributeKind::HL_CVR_QUALIFIERS: return "HL_CVR_QUALIFIERS";
    case ir::AttributeKind::HL_OFFSET_OF_NODE: return "HL_OFFSET_OF_NODE";
    case ir::AttributeKind::CORE_BOOLEAN: return "CORE_BOOLEAN";
    case ir::AttributeKind::CORE_INTEGER: return "CORE_INTEGER";
    case ir::AttributeKind::CORE_FLOAT: return "CORE_FLOAT";
    case ir::AttributeKind::CORE_VOID: return "CORE_VOID";
    case ir::AttributeKind::CORE_SOURCE_LANGUAGE: return "CORE_SOURCE_LANGUAGE";
    case ir::AttributeKind::CORE_GLOBAL_LINKAGE_KIND: return "CORE_GLOBAL_LINKAGE_KIND";
    case ir::AttributeKind::META_IDENTIFIER: return "META_IDENTIFIER";
  }
}

bool IsBuiltinAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::AttributeKind::BUILTIN_TYPED:
    case mx::ir::AttributeKind::BUILTIN_ELEMENTS:
    case mx::ir::AttributeKind::BUILTIN_AFFINE_MAP:
    case mx::ir::AttributeKind::BUILTIN_ARRAY:
    case mx::ir::AttributeKind::BUILTIN_DENSE_ARRAY:
    case mx::ir::AttributeKind::BUILTIN_DENSE_INT_OR_FP_ELEMENTS:
    case mx::ir::AttributeKind::BUILTIN_DENSE_STRING_ELEMENTS:
    case mx::ir::AttributeKind::BUILTIN_DENSE_RESOURCE_ELEMENTS:
    case mx::ir::AttributeKind::BUILTIN_DICTIONARY:
    case mx::ir::AttributeKind::BUILTIN_FLOAT:
    case mx::ir::AttributeKind::BUILTIN_INTEGER:
    case mx::ir::AttributeKind::BUILTIN_INTEGER_SET:
    case mx::ir::AttributeKind::BUILTIN_OPAQUE:
    case mx::ir::AttributeKind::BUILTIN_SPARSE_ELEMENTS:
    case mx::ir::AttributeKind::BUILTIN_STRIDED_LAYOUT:
    case mx::ir::AttributeKind::BUILTIN_STRING:
    case mx::ir::AttributeKind::BUILTIN_SYMBOL_REF:
    case mx::ir::AttributeKind::BUILTIN_TYPE:
    case mx::ir::AttributeKind::BUILTIN_UNIT:
    case mx::ir::AttributeKind::BUILTIN_BOOL:
    case mx::ir::AttributeKind::BUILTIN_FLAT_SYMBOL_REF:
    case mx::ir::AttributeKind::BUILTIN_DENSE_INT_ELEMENTS:
      return true;
  }
}

bool IsLLVMIRAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::AttributeKind::LLVM_C_CONV:
    case mx::ir::AttributeKind::LLVM_COMDAT:
    case mx::ir::AttributeKind::LLVM_LINKAGE:
    case mx::ir::AttributeKind::LLVM_FRAME_POINTER_KIND:
    case mx::ir::AttributeKind::LLVM_LOOP_VECTORIZE:
    case mx::ir::AttributeKind::LLVM_LOOP_INTERLEAVE:
    case mx::ir::AttributeKind::LLVM_LOOP_UNROLL:
    case mx::ir::AttributeKind::LLVM_LOOP_UNROLL_AND_JAM:
    case mx::ir::AttributeKind::LLVM_LOOP_LICM:
    case mx::ir::AttributeKind::LLVM_LOOP_DISTRIBUTE:
    case mx::ir::AttributeKind::LLVM_LOOP_PIPELINE:
    case mx::ir::AttributeKind::LLVM_LOOP_PEELED:
    case mx::ir::AttributeKind::LLVM_LOOP_UNSWITCH:
    case mx::ir::AttributeKind::LLVM_LOOP_ANNOTATION:
    case mx::ir::AttributeKind::LLVM_DI_EXPRESSION_ELEM:
    case mx::ir::AttributeKind::LLVM_DI_EXPRESSION:
    case mx::ir::AttributeKind::LLVM_DI_NULL_TYPE:
    case mx::ir::AttributeKind::LLVM_DI_BASIC_TYPE:
    case mx::ir::AttributeKind::LLVM_DI_COMPILE_UNIT:
    case mx::ir::AttributeKind::LLVM_DI_COMPOSITE_TYPE:
    case mx::ir::AttributeKind::LLVM_DI_DERIVED_TYPE:
    case mx::ir::AttributeKind::LLVM_DI_FILE:
    case mx::ir::AttributeKind::LLVM_DI_GLOBAL_VARIABLE_EXPRESSION:
    case mx::ir::AttributeKind::LLVM_DI_GLOBAL_VARIABLE:
    case mx::ir::AttributeKind::LLVM_DI_LEXICAL_BLOCK:
    case mx::ir::AttributeKind::LLVM_DI_LEXICAL_BLOCK_FILE:
    case mx::ir::AttributeKind::LLVM_DI_LOCAL_VARIABLE:
    case mx::ir::AttributeKind::LLVM_DI_SUBPROGRAM:
    case mx::ir::AttributeKind::LLVM_DI_MODULE:
    case mx::ir::AttributeKind::LLVM_DI_NAMESPACE:
    case mx::ir::AttributeKind::LLVM_DI_SUBRANGE:
    case mx::ir::AttributeKind::LLVM_DI_SUBROUTINE_TYPE:
    case mx::ir::AttributeKind::LLVM_DI_LABEL:
    case mx::ir::AttributeKind::LLVM_MEMORY_EFFECTS:
    case mx::ir::AttributeKind::LLVM_ALIAS_SCOPE_DOMAIN:
    case mx::ir::AttributeKind::LLVM_ALIAS_SCOPE:
    case mx::ir::AttributeKind::LLVM_ACCESS_GROUP:
    case mx::ir::AttributeKind::LLVM_TBAA_ROOT:
    case mx::ir::AttributeKind::LLVM_TBAA_MEMBER:
    case mx::ir::AttributeKind::LLVM_TBAA_TYPE_DESCRIPTOR:
    case mx::ir::AttributeKind::LLVM_TBAA_TAG:
    case mx::ir::AttributeKind::LLVM_V_SCALE_RANGE:
    case mx::ir::AttributeKind::LLVM_TARGET_FEATURES:
    case mx::ir::AttributeKind::LLVM_INTEGER_OVERFLOW_FLAGS:
    case mx::ir::AttributeKind::LLVM_FASTMATH_FLAGS:
      return true;
  }
}

bool IsMemRefAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsABIAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsLowLevelAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsHighLevelAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::AttributeKind::HL_ANNOTATION:
    case mx::ir::AttributeKind::HL_FORMAT:
    case mx::ir::AttributeKind::HL_SECTION:
    case mx::ir::AttributeKind::HL_ALIAS:
    case mx::ir::AttributeKind::HL_ALIGNED:
    case mx::ir::AttributeKind::HL_ALWAYS_INLINE:
    case mx::ir::AttributeKind::HL_NO_INLINE:
    case mx::ir::AttributeKind::HL_CONST:
    case mx::ir::AttributeKind::HL_LOADER_UNINITIALIZED:
    case mx::ir::AttributeKind::HL_NO_INSTRUMENT_FUNCTION:
    case mx::ir::AttributeKind::HL_PACKED:
    case mx::ir::AttributeKind::HL_PURE:
    case mx::ir::AttributeKind::HL_WARN_UNUSED_RESULT:
    case mx::ir::AttributeKind::HL_RESTRICT:
    case mx::ir::AttributeKind::HL_NO_THROW:
    case mx::ir::AttributeKind::HL_NON_NULL:
    case mx::ir::AttributeKind::HL_LEAF:
    case mx::ir::AttributeKind::HL_COLD:
    case mx::ir::AttributeKind::HL_TRANSPARENT_UNION:
    case mx::ir::AttributeKind::HL_RETURNS_TWICE:
    case mx::ir::AttributeKind::HL_MAY_ALIAS:
    case mx::ir::AttributeKind::HL_UNUSED:
    case mx::ir::AttributeKind::HL_USED:
    case mx::ir::AttributeKind::HL_GNU_INLINE:
    case mx::ir::AttributeKind::HL_NO_CF_CHECK:
    case mx::ir::AttributeKind::HL_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD:
    case mx::ir::AttributeKind::HL_AVAILABILITY_ATTR:
    case mx::ir::AttributeKind::HL_ASM_LABEL:
    case mx::ir::AttributeKind::HL_MODE:
    case mx::ir::AttributeKind::HL_BUILTIN:
    case mx::ir::AttributeKind::HL_ALLOC_ALIGN:
    case mx::ir::AttributeKind::HL_ALLOC_SIZE:
    case mx::ir::AttributeKind::HL_DEPRECATED:
    case mx::ir::AttributeKind::HL_MAX_FIELD_ALIGNMENT:
    case mx::ir::AttributeKind::HL_CV_QUALIFIERS:
    case mx::ir::AttributeKind::HL_UCV_QUALIFIERS:
    case mx::ir::AttributeKind::HL_CVR_QUALIFIERS:
    case mx::ir::AttributeKind::HL_OFFSET_OF_NODE:
      return true;
  }
}

bool IsCoreAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::AttributeKind::CORE_BOOLEAN:
    case mx::ir::AttributeKind::CORE_INTEGER:
    case mx::ir::AttributeKind::CORE_FLOAT:
    case mx::ir::AttributeKind::CORE_VOID:
    case mx::ir::AttributeKind::CORE_SOURCE_LANGUAGE:
    case mx::ir::AttributeKind::CORE_GLOBAL_LINKAGE_KIND:
      return true;
  }
}

bool IsMetaAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::AttributeKind::META_IDENTIFIER:
      return true;
  }
}

bool IsUnsupportedAttributeKind(ir::AttributeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

}  // namespace mx
