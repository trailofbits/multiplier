// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "API.h"

namespace mx {
DeclKind FromPasta(pasta::DeclKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclKind::ACCESS_SPEC;
    case 1: return DeclKind::BASE_USING;
    case 2: return DeclKind::BINDING;
    case 3: return DeclKind::BLOCK;
    case 4: return DeclKind::BUILTIN_TEMPLATE;
    case 5: return DeclKind::CXX_CONSTRUCTOR;
    case 6: return DeclKind::CXX_CONVERSION;
    case 7: return DeclKind::CXX_DEDUCTION_GUIDE;
    case 8: return DeclKind::CXX_DESTRUCTOR;
    case 9: return DeclKind::CXX_METHOD;
    case 10: return DeclKind::CXX_RECORD;
    case 11: return DeclKind::CAPTURED;
    case 12: return DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION;
    case 13: return DeclKind::CLASS_TEMPLATE;
    case 14: return DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION;
    case 15: return DeclKind::CLASS_TEMPLATE_SPECIALIZATION;
    case 16: return DeclKind::CONCEPT;
    case 17: return DeclKind::CONSTRUCTOR_USING_SHADOW;
    case 18: return DeclKind::DECLARATOR;
    case 19: return DeclKind::DECOMPOSITION;
    case 20: return DeclKind::EMPTY;
    case 21: return DeclKind::ENUM_CONSTANT;
    case 22: return DeclKind::ENUM;
    case 23: return DeclKind::EXPORT;
    case 24: return DeclKind::EXTERN_C_CONTEXT;
    case 25: return DeclKind::FIELD;
    case 26: return DeclKind::FILE_SCOPE_ASM;
    case 27: return DeclKind::FRIEND;
    case 28: return DeclKind::FRIEND_TEMPLATE;
    case 29: return DeclKind::FUNCTION;
    case 30: return DeclKind::FUNCTION_TEMPLATE;
    case 31: return DeclKind::IMPLICIT_PARAM;
    case 32: return DeclKind::IMPORT;
    case 33: return DeclKind::INDIRECT_FIELD;
    case 34: return DeclKind::LABEL;
    case 35: return DeclKind::LIFETIME_EXTENDED_TEMPORARY;
    case 36: return DeclKind::LINKAGE_SPEC;
    case 37: return DeclKind::MS_GUID;
    case 38: return DeclKind::MS_PROPERTY;
    case 39: return DeclKind::NAMED;
    case 40: return DeclKind::NAMESPACE_ALIAS;
    case 41: return DeclKind::NAMESPACE;
    case 42: return DeclKind::NON_TYPE_TEMPLATE_PARM;
    case 43: return DeclKind::OMP_ALLOCATE;
    case 44: return DeclKind::OMP_CAPTURED_EXPR;
    case 45: return DeclKind::OMP_DECLARE_MAPPER;
    case 46: return DeclKind::OMP_DECLARE_REDUCTION;
    case 47: return DeclKind::OMP_REQUIRES;
    case 48: return DeclKind::OMP_THREAD_PRIVATE;
    case 49: return DeclKind::OBJ_C_AT_DEFS_FIELD;
    case 50: return DeclKind::OBJ_C_CATEGORY;
    case 51: return DeclKind::OBJ_C_CATEGORY_IMPL;
    case 52: return DeclKind::OBJ_C_COMPATIBLE_ALIAS;
    case 53: return DeclKind::OBJ_C_CONTAINER;
    case 54: return DeclKind::OBJ_C_IMPL;
    case 55: return DeclKind::OBJ_C_IMPLEMENTATION;
    case 56: return DeclKind::OBJ_C_INTERFACE;
    case 57: return DeclKind::OBJ_C_IVAR;
    case 58: return DeclKind::OBJ_C_METHOD;
    case 59: return DeclKind::OBJ_C_PROPERTY;
    case 60: return DeclKind::OBJ_C_PROPERTY_IMPL;
    case 61: return DeclKind::OBJ_C_PROTOCOL;
    case 62: return DeclKind::OBJ_C_TYPE_PARAM;
    case 63: return DeclKind::PARM_VAR;
    case 64: return DeclKind::PRAGMA_COMMENT;
    case 65: return DeclKind::PRAGMA_DETECT_MISMATCH;
    case 66: return DeclKind::RECORD;
    case 67: return DeclKind::REDECLARABLE_TEMPLATE;
    case 68: return DeclKind::REQUIRES_EXPR_BODY;
    case 69: return DeclKind::STATIC_ASSERT;
    case 70: return DeclKind::TAG;
    case 71: return DeclKind::TEMPLATE;
    case 72: return DeclKind::TEMPLATE_PARAM_OBJECT;
    case 73: return DeclKind::TEMPLATE_TEMPLATE_PARM;
    case 74: return DeclKind::TEMPLATE_TYPE_PARM;
    case 75: return DeclKind::TRANSLATION_UNIT;
    case 76: return DeclKind::TYPE_ALIAS;
    case 77: return DeclKind::TYPE_ALIAS_TEMPLATE;
    case 78: return DeclKind::TYPE;
    case 79: return DeclKind::TYPEDEF;
    case 80: return DeclKind::TYPEDEF_NAME;
    case 81: return DeclKind::UNRESOLVED_USING_IF_EXISTS;
    case 82: return DeclKind::UNRESOLVED_USING_TYPENAME;
    case 83: return DeclKind::UNRESOLVED_USING_VALUE;
    case 84: return DeclKind::USING;
    case 85: return DeclKind::USING_DIRECTIVE;
    case 86: return DeclKind::USING_ENUM;
    case 87: return DeclKind::USING_PACK;
    case 88: return DeclKind::USING_SHADOW;
    case 89: return DeclKind::VALUE;
    case 90: return DeclKind::VAR;
    case 91: return DeclKind::VAR_TEMPLATE;
    case 92: return DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION;
    case 93: return DeclKind::VAR_TEMPLATE_SPECIALIZATION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DeclKind e) {
  switch (e) {
    case DeclKind::ACCESS_SPEC: return "ACCESS_SPEC";
    case DeclKind::BASE_USING: return "BASE_USING";
    case DeclKind::BINDING: return "BINDING";
    case DeclKind::BLOCK: return "BLOCK";
    case DeclKind::BUILTIN_TEMPLATE: return "BUILTIN_TEMPLATE";
    case DeclKind::CXX_CONSTRUCTOR: return "CXX_CONSTRUCTOR";
    case DeclKind::CXX_CONVERSION: return "CXX_CONVERSION";
    case DeclKind::CXX_DEDUCTION_GUIDE: return "CXX_DEDUCTION_GUIDE";
    case DeclKind::CXX_DESTRUCTOR: return "CXX_DESTRUCTOR";
    case DeclKind::CXX_METHOD: return "CXX_METHOD";
    case DeclKind::CXX_RECORD: return "CXX_RECORD";
    case DeclKind::CAPTURED: return "CAPTURED";
    case DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION: return "CLASS_SCOPE_FUNCTION_SPECIALIZATION";
    case DeclKind::CLASS_TEMPLATE: return "CLASS_TEMPLATE";
    case DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION: return "CLASS_TEMPLATE_PARTIAL_SPECIALIZATION";
    case DeclKind::CLASS_TEMPLATE_SPECIALIZATION: return "CLASS_TEMPLATE_SPECIALIZATION";
    case DeclKind::CONCEPT: return "CONCEPT";
    case DeclKind::CONSTRUCTOR_USING_SHADOW: return "CONSTRUCTOR_USING_SHADOW";
    case DeclKind::DECLARATOR: return "DECLARATOR";
    case DeclKind::DECOMPOSITION: return "DECOMPOSITION";
    case DeclKind::EMPTY: return "EMPTY";
    case DeclKind::ENUM_CONSTANT: return "ENUM_CONSTANT";
    case DeclKind::ENUM: return "ENUM";
    case DeclKind::EXPORT: return "EXPORT";
    case DeclKind::EXTERN_C_CONTEXT: return "EXTERN_C_CONTEXT";
    case DeclKind::FIELD: return "FIELD";
    case DeclKind::FILE_SCOPE_ASM: return "FILE_SCOPE_ASM";
    case DeclKind::FRIEND: return "FRIEND";
    case DeclKind::FRIEND_TEMPLATE: return "FRIEND_TEMPLATE";
    case DeclKind::FUNCTION: return "FUNCTION";
    case DeclKind::FUNCTION_TEMPLATE: return "FUNCTION_TEMPLATE";
    case DeclKind::IMPLICIT_PARAM: return "IMPLICIT_PARAM";
    case DeclKind::IMPORT: return "IMPORT";
    case DeclKind::INDIRECT_FIELD: return "INDIRECT_FIELD";
    case DeclKind::LABEL: return "LABEL";
    case DeclKind::LIFETIME_EXTENDED_TEMPORARY: return "LIFETIME_EXTENDED_TEMPORARY";
    case DeclKind::LINKAGE_SPEC: return "LINKAGE_SPEC";
    case DeclKind::MS_GUID: return "MS_GUID";
    case DeclKind::MS_PROPERTY: return "MS_PROPERTY";
    case DeclKind::NAMED: return "NAMED";
    case DeclKind::NAMESPACE_ALIAS: return "NAMESPACE_ALIAS";
    case DeclKind::NAMESPACE: return "NAMESPACE";
    case DeclKind::NON_TYPE_TEMPLATE_PARM: return "NON_TYPE_TEMPLATE_PARM";
    case DeclKind::OMP_ALLOCATE: return "OMP_ALLOCATE";
    case DeclKind::OMP_CAPTURED_EXPR: return "OMP_CAPTURED_EXPR";
    case DeclKind::OMP_DECLARE_MAPPER: return "OMP_DECLARE_MAPPER";
    case DeclKind::OMP_DECLARE_REDUCTION: return "OMP_DECLARE_REDUCTION";
    case DeclKind::OMP_REQUIRES: return "OMP_REQUIRES";
    case DeclKind::OMP_THREAD_PRIVATE: return "OMP_THREAD_PRIVATE";
    case DeclKind::OBJ_C_AT_DEFS_FIELD: return "OBJ_C_AT_DEFS_FIELD";
    case DeclKind::OBJ_C_CATEGORY: return "OBJ_C_CATEGORY";
    case DeclKind::OBJ_C_CATEGORY_IMPL: return "OBJ_C_CATEGORY_IMPL";
    case DeclKind::OBJ_C_COMPATIBLE_ALIAS: return "OBJ_C_COMPATIBLE_ALIAS";
    case DeclKind::OBJ_C_CONTAINER: return "OBJ_C_CONTAINER";
    case DeclKind::OBJ_C_IMPL: return "OBJ_C_IMPL";
    case DeclKind::OBJ_C_IMPLEMENTATION: return "OBJ_C_IMPLEMENTATION";
    case DeclKind::OBJ_C_INTERFACE: return "OBJ_C_INTERFACE";
    case DeclKind::OBJ_C_IVAR: return "OBJ_C_IVAR";
    case DeclKind::OBJ_C_METHOD: return "OBJ_C_METHOD";
    case DeclKind::OBJ_C_PROPERTY: return "OBJ_C_PROPERTY";
    case DeclKind::OBJ_C_PROPERTY_IMPL: return "OBJ_C_PROPERTY_IMPL";
    case DeclKind::OBJ_C_PROTOCOL: return "OBJ_C_PROTOCOL";
    case DeclKind::OBJ_C_TYPE_PARAM: return "OBJ_C_TYPE_PARAM";
    case DeclKind::PARM_VAR: return "PARM_VAR";
    case DeclKind::PRAGMA_COMMENT: return "PRAGMA_COMMENT";
    case DeclKind::PRAGMA_DETECT_MISMATCH: return "PRAGMA_DETECT_MISMATCH";
    case DeclKind::RECORD: return "RECORD";
    case DeclKind::REDECLARABLE_TEMPLATE: return "REDECLARABLE_TEMPLATE";
    case DeclKind::REQUIRES_EXPR_BODY: return "REQUIRES_EXPR_BODY";
    case DeclKind::STATIC_ASSERT: return "STATIC_ASSERT";
    case DeclKind::TAG: return "TAG";
    case DeclKind::TEMPLATE: return "TEMPLATE";
    case DeclKind::TEMPLATE_PARAM_OBJECT: return "TEMPLATE_PARAM_OBJECT";
    case DeclKind::TEMPLATE_TEMPLATE_PARM: return "TEMPLATE_TEMPLATE_PARM";
    case DeclKind::TEMPLATE_TYPE_PARM: return "TEMPLATE_TYPE_PARM";
    case DeclKind::TRANSLATION_UNIT: return "TRANSLATION_UNIT";
    case DeclKind::TYPE_ALIAS: return "TYPE_ALIAS";
    case DeclKind::TYPE_ALIAS_TEMPLATE: return "TYPE_ALIAS_TEMPLATE";
    case DeclKind::TYPE: return "TYPE";
    case DeclKind::TYPEDEF: return "TYPEDEF";
    case DeclKind::TYPEDEF_NAME: return "TYPEDEF_NAME";
    case DeclKind::UNRESOLVED_USING_IF_EXISTS: return "UNRESOLVED_USING_IF_EXISTS";
    case DeclKind::UNRESOLVED_USING_TYPENAME: return "UNRESOLVED_USING_TYPENAME";
    case DeclKind::UNRESOLVED_USING_VALUE: return "UNRESOLVED_USING_VALUE";
    case DeclKind::USING: return "USING";
    case DeclKind::USING_DIRECTIVE: return "USING_DIRECTIVE";
    case DeclKind::USING_ENUM: return "USING_ENUM";
    case DeclKind::USING_PACK: return "USING_PACK";
    case DeclKind::USING_SHADOW: return "USING_SHADOW";
    case DeclKind::VALUE: return "VALUE";
    case DeclKind::VAR: return "VAR";
    case DeclKind::VAR_TEMPLATE: return "VAR_TEMPLATE";
    case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION: return "VAR_TEMPLATE_PARTIAL_SPECIALIZATION";
    case DeclKind::VAR_TEMPLATE_SPECIALIZATION: return "VAR_TEMPLATE_SPECIALIZATION";
    default: return "<invalid>";
  }
}

ArrayTypeArraySizeModifier FromPasta(pasta::ArrayTypeArraySizeModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArrayTypeArraySizeModifier::NORMAL;
    case 1: return ArrayTypeArraySizeModifier::STATIC;
    case 2: return ArrayTypeArraySizeModifier::STAR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ArrayTypeArraySizeModifier e) {
  switch (e) {
    case ArrayTypeArraySizeModifier::NORMAL: return "NORMAL";
    case ArrayTypeArraySizeModifier::STATIC: return "STATIC";
    case ArrayTypeArraySizeModifier::STAR: return "STAR";
    default: return "<invalid>";
  }
}

AtomicExprAtomicOp FromPasta(pasta::AtomicExprAtomicOp e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AtomicExprAtomicOp::C11_ATOMIC_INITIALIZER;
    case 1: return AtomicExprAtomicOp::C11_ATOMIC_LOAD;
    case 2: return AtomicExprAtomicOp::C11_ATOMIC_STORE;
    case 3: return AtomicExprAtomicOp::C11_ATOMIC_EXCHANGE;
    case 4: return AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_STRONG;
    case 5: return AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_WEAK;
    case 6: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_ADD;
    case 7: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_SUB;
    case 8: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_AND;
    case 9: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_OR;
    case 10: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_XOR;
    case 11: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_MAX;
    case 12: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_MIN;
    case 13: return AtomicExprAtomicOp::ATOMIC_LOAD;
    case 14: return AtomicExprAtomicOp::ATOMIC_LOAD_N;
    case 15: return AtomicExprAtomicOp::ATOMIC_STORE;
    case 16: return AtomicExprAtomicOp::ATOMIC_STORE_N;
    case 17: return AtomicExprAtomicOp::ATOMIC_EXCHANGE;
    case 18: return AtomicExprAtomicOp::ATOMIC_EXCHANGE_N;
    case 19: return AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE;
    case 20: return AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE_N;
    case 21: return AtomicExprAtomicOp::ATOMIC_FETCH_ADD;
    case 22: return AtomicExprAtomicOp::ATOMIC_FETCH_SUB;
    case 23: return AtomicExprAtomicOp::ATOMIC_FETCH_AND;
    case 24: return AtomicExprAtomicOp::ATOMIC_FETCH_OR;
    case 25: return AtomicExprAtomicOp::ATOMIC_FETCH_XOR;
    case 26: return AtomicExprAtomicOp::ATOMIC_FETCH_NAND;
    case 27: return AtomicExprAtomicOp::ATOMIC_ADD_FETCH;
    case 28: return AtomicExprAtomicOp::ATOMIC_SUB_FETCH;
    case 29: return AtomicExprAtomicOp::ATOMIC_AND_FETCH;
    case 30: return AtomicExprAtomicOp::ATOMIC_OR_FETCH;
    case 31: return AtomicExprAtomicOp::ATOMIC_XOR_FETCH;
    case 32: return AtomicExprAtomicOp::ATOMIC_MAX_FETCH;
    case 33: return AtomicExprAtomicOp::ATOMIC_MIN_FETCH;
    case 34: return AtomicExprAtomicOp::ATOMIC_NAND_FETCH;
    case 35: return AtomicExprAtomicOp::OPENCL_ATOMIC_INITIALIZER;
    case 36: return AtomicExprAtomicOp::OPENCL_ATOMIC_LOAD;
    case 37: return AtomicExprAtomicOp::OPENCL_ATOMIC_STORE;
    case 38: return AtomicExprAtomicOp::OPENCL_ATOMIC_EXCHANGE;
    case 39: return AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG;
    case 40: return AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK;
    case 41: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_ADD;
    case 42: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_SUB;
    case 43: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_AND;
    case 44: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_OR;
    case 45: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_XOR;
    case 46: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MIN;
    case 47: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MAX;
    case 48: return AtomicExprAtomicOp::ATOMIC_FETCH_MIN;
    case 49: return AtomicExprAtomicOp::ATOMIC_FETCH_MAX;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AtomicExprAtomicOp e) {
  switch (e) {
    case AtomicExprAtomicOp::C11_ATOMIC_INITIALIZER: return "C11_ATOMIC_INITIALIZER";
    case AtomicExprAtomicOp::C11_ATOMIC_LOAD: return "C11_ATOMIC_LOAD";
    case AtomicExprAtomicOp::C11_ATOMIC_STORE: return "C11_ATOMIC_STORE";
    case AtomicExprAtomicOp::C11_ATOMIC_EXCHANGE: return "C11_ATOMIC_EXCHANGE";
    case AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_STRONG: return "C11_ATOMIC_COMPARE_EXCHANGE_STRONG";
    case AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_WEAK: return "C11_ATOMIC_COMPARE_EXCHANGE_WEAK";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_ADD: return "C11_ATOMIC_FETCH_ADD";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_SUB: return "C11_ATOMIC_FETCH_SUB";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_AND: return "C11_ATOMIC_FETCH_AND";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_OR: return "C11_ATOMIC_FETCH_OR";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_XOR: return "C11_ATOMIC_FETCH_XOR";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_MAX: return "C11_ATOMIC_FETCH_MAX";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_MIN: return "C11_ATOMIC_FETCH_MIN";
    case AtomicExprAtomicOp::ATOMIC_LOAD: return "ATOMIC_LOAD";
    case AtomicExprAtomicOp::ATOMIC_LOAD_N: return "ATOMIC_LOAD_N";
    case AtomicExprAtomicOp::ATOMIC_STORE: return "ATOMIC_STORE";
    case AtomicExprAtomicOp::ATOMIC_STORE_N: return "ATOMIC_STORE_N";
    case AtomicExprAtomicOp::ATOMIC_EXCHANGE: return "ATOMIC_EXCHANGE";
    case AtomicExprAtomicOp::ATOMIC_EXCHANGE_N: return "ATOMIC_EXCHANGE_N";
    case AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE: return "ATOMIC_COMPARE_EXCHANGE";
    case AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE_N: return "ATOMIC_COMPARE_EXCHANGE_N";
    case AtomicExprAtomicOp::ATOMIC_FETCH_ADD: return "ATOMIC_FETCH_ADD";
    case AtomicExprAtomicOp::ATOMIC_FETCH_SUB: return "ATOMIC_FETCH_SUB";
    case AtomicExprAtomicOp::ATOMIC_FETCH_AND: return "ATOMIC_FETCH_AND";
    case AtomicExprAtomicOp::ATOMIC_FETCH_OR: return "ATOMIC_FETCH_OR";
    case AtomicExprAtomicOp::ATOMIC_FETCH_XOR: return "ATOMIC_FETCH_XOR";
    case AtomicExprAtomicOp::ATOMIC_FETCH_NAND: return "ATOMIC_FETCH_NAND";
    case AtomicExprAtomicOp::ATOMIC_ADD_FETCH: return "ATOMIC_ADD_FETCH";
    case AtomicExprAtomicOp::ATOMIC_SUB_FETCH: return "ATOMIC_SUB_FETCH";
    case AtomicExprAtomicOp::ATOMIC_AND_FETCH: return "ATOMIC_AND_FETCH";
    case AtomicExprAtomicOp::ATOMIC_OR_FETCH: return "ATOMIC_OR_FETCH";
    case AtomicExprAtomicOp::ATOMIC_XOR_FETCH: return "ATOMIC_XOR_FETCH";
    case AtomicExprAtomicOp::ATOMIC_MAX_FETCH: return "ATOMIC_MAX_FETCH";
    case AtomicExprAtomicOp::ATOMIC_MIN_FETCH: return "ATOMIC_MIN_FETCH";
    case AtomicExprAtomicOp::ATOMIC_NAND_FETCH: return "ATOMIC_NAND_FETCH";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_INITIALIZER: return "OPENCL_ATOMIC_INITIALIZER";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_LOAD: return "OPENCL_ATOMIC_LOAD";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_STORE: return "OPENCL_ATOMIC_STORE";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_EXCHANGE: return "OPENCL_ATOMIC_EXCHANGE";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG: return "OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK: return "OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_ADD: return "OPENCL_ATOMIC_FETCH_ADD";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_SUB: return "OPENCL_ATOMIC_FETCH_SUB";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_AND: return "OPENCL_ATOMIC_FETCH_AND";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_OR: return "OPENCL_ATOMIC_FETCH_OR";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_XOR: return "OPENCL_ATOMIC_FETCH_XOR";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MIN: return "OPENCL_ATOMIC_FETCH_MIN";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MAX: return "OPENCL_ATOMIC_FETCH_MAX";
    case AtomicExprAtomicOp::ATOMIC_FETCH_MIN: return "ATOMIC_FETCH_MIN";
    case AtomicExprAtomicOp::ATOMIC_FETCH_MAX: return "ATOMIC_FETCH_MAX";
    default: return "<invalid>";
  }
}

BuiltinTypeKind FromPasta(pasta::BuiltinTypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BuiltinTypeKind::OCL_IMAGE1_DRO;
    case 1: return BuiltinTypeKind::OCL_IMAGE1_DARRAY_RO;
    case 2: return BuiltinTypeKind::OCL_IMAGE1_DBUFFER_RO;
    case 3: return BuiltinTypeKind::OCL_IMAGE2_DRO;
    case 4: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_RO;
    case 5: return BuiltinTypeKind::OCL_IMAGE2_DDEPTH_RO;
    case 6: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_RO;
    case 7: return BuiltinTypeKind::OCL_IMAGE2_DMSAARO;
    case 8: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAARO;
    case 9: return BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_RO;
    case 10: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_RO;
    case 11: return BuiltinTypeKind::OCL_IMAGE3_DRO;
    case 12: return BuiltinTypeKind::OCL_IMAGE1_DWO;
    case 13: return BuiltinTypeKind::OCL_IMAGE1_DARRAY_WO;
    case 14: return BuiltinTypeKind::OCL_IMAGE1_DBUFFER_WO;
    case 15: return BuiltinTypeKind::OCL_IMAGE2_DWO;
    case 16: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_WO;
    case 17: return BuiltinTypeKind::OCL_IMAGE2_DDEPTH_WO;
    case 18: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_WO;
    case 19: return BuiltinTypeKind::OCL_IMAGE2_DMSAAWO;
    case 20: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAAWO;
    case 21: return BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_WO;
    case 22: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_WO;
    case 23: return BuiltinTypeKind::OCL_IMAGE3_DWO;
    case 24: return BuiltinTypeKind::OCL_IMAGE1_DRW;
    case 25: return BuiltinTypeKind::OCL_IMAGE1_DARRAY_RW;
    case 26: return BuiltinTypeKind::OCL_IMAGE1_DBUFFER_RW;
    case 27: return BuiltinTypeKind::OCL_IMAGE2_DRW;
    case 28: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_RW;
    case 29: return BuiltinTypeKind::OCL_IMAGE2_DDEPTH_RW;
    case 30: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_RW;
    case 31: return BuiltinTypeKind::OCL_IMAGE2_DMSAARW;
    case 32: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAARW;
    case 33: return BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_RW;
    case 34: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_RW;
    case 35: return BuiltinTypeKind::OCL_IMAGE3_DRW;
    case 36: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD;
    case 37: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD;
    case 38: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD;
    case 39: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD;
    case 40: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_RESULT;
    case 41: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT;
    case 42: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_RESULT;
    case 43: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_RESULT;
    case 44: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT;
    case 45: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT;
    case 46: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN;
    case 47: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN;
    case 48: return BuiltinTypeKind::SVE_INT8;
    case 49: return BuiltinTypeKind::SVE_INT16;
    case 50: return BuiltinTypeKind::SVE_INT32;
    case 51: return BuiltinTypeKind::SVE_INT64;
    case 52: return BuiltinTypeKind::SVE_UINT8;
    case 53: return BuiltinTypeKind::SVE_UINT16;
    case 54: return BuiltinTypeKind::SVE_UINT32;
    case 55: return BuiltinTypeKind::SVE_UINT64;
    case 56: return BuiltinTypeKind::SVE_FLOAT16;
    case 57: return BuiltinTypeKind::SVE_FLOAT32;
    case 58: return BuiltinTypeKind::SVE_FLOAT64;
    case 59: return BuiltinTypeKind::SVE_B_FLOAT16;
    case 60: return BuiltinTypeKind::SVE_INT8_X2;
    case 61: return BuiltinTypeKind::SVE_INT16_X2;
    case 62: return BuiltinTypeKind::SVE_INT32_X2;
    case 63: return BuiltinTypeKind::SVE_INT64_X2;
    case 64: return BuiltinTypeKind::SVE_UINT8_X2;
    case 65: return BuiltinTypeKind::SVE_UINT16_X2;
    case 66: return BuiltinTypeKind::SVE_UINT32_X2;
    case 67: return BuiltinTypeKind::SVE_UINT64_X2;
    case 68: return BuiltinTypeKind::SVE_FLOAT16_X2;
    case 69: return BuiltinTypeKind::SVE_FLOAT32_X2;
    case 70: return BuiltinTypeKind::SVE_FLOAT64_X2;
    case 71: return BuiltinTypeKind::SVE_B_FLOAT16_X2;
    case 72: return BuiltinTypeKind::SVE_INT8_X3;
    case 73: return BuiltinTypeKind::SVE_INT16_X3;
    case 74: return BuiltinTypeKind::SVE_INT32_X3;
    case 75: return BuiltinTypeKind::SVE_INT64_X3;
    case 76: return BuiltinTypeKind::SVE_UINT8_X3;
    case 77: return BuiltinTypeKind::SVE_UINT16_X3;
    case 78: return BuiltinTypeKind::SVE_UINT32_X3;
    case 79: return BuiltinTypeKind::SVE_UINT64_X3;
    case 80: return BuiltinTypeKind::SVE_FLOAT16_X3;
    case 81: return BuiltinTypeKind::SVE_FLOAT32_X3;
    case 82: return BuiltinTypeKind::SVE_FLOAT64_X3;
    case 83: return BuiltinTypeKind::SVE_B_FLOAT16_X3;
    case 84: return BuiltinTypeKind::SVE_INT8_X4;
    case 85: return BuiltinTypeKind::SVE_INT16_X4;
    case 86: return BuiltinTypeKind::SVE_INT32_X4;
    case 87: return BuiltinTypeKind::SVE_INT64_X4;
    case 88: return BuiltinTypeKind::SVE_UINT8_X4;
    case 89: return BuiltinTypeKind::SVE_UINT16_X4;
    case 90: return BuiltinTypeKind::SVE_UINT32_X4;
    case 91: return BuiltinTypeKind::SVE_UINT64_X4;
    case 92: return BuiltinTypeKind::SVE_FLOAT16_X4;
    case 93: return BuiltinTypeKind::SVE_FLOAT32_X4;
    case 94: return BuiltinTypeKind::SVE_FLOAT64_X4;
    case 95: return BuiltinTypeKind::SVE_B_FLOAT16_X4;
    case 96: return BuiltinTypeKind::SVE_BOOLEAN;
    case 97: return BuiltinTypeKind::VECTOR_QUAD;
    case 98: return BuiltinTypeKind::VECTOR_PAIR;
    case 99: return BuiltinTypeKind::RVV_INT8_MF8;
    case 100: return BuiltinTypeKind::RVV_INT8_MF4;
    case 101: return BuiltinTypeKind::RVV_INT8_MF2;
    case 102: return BuiltinTypeKind::RVV_INT8_M1;
    case 103: return BuiltinTypeKind::RVV_INT8_M2;
    case 104: return BuiltinTypeKind::RVV_INT8_M4;
    case 105: return BuiltinTypeKind::RVV_INT8_M8;
    case 106: return BuiltinTypeKind::RVV_UINT8_MF8;
    case 107: return BuiltinTypeKind::RVV_UINT8_MF4;
    case 108: return BuiltinTypeKind::RVV_UINT8_MF2;
    case 109: return BuiltinTypeKind::RVV_UINT8_M1;
    case 110: return BuiltinTypeKind::RVV_UINT8_M2;
    case 111: return BuiltinTypeKind::RVV_UINT8_M4;
    case 112: return BuiltinTypeKind::RVV_UINT8_M8;
    case 113: return BuiltinTypeKind::RVV_INT16_MF4;
    case 114: return BuiltinTypeKind::RVV_INT16_MF2;
    case 115: return BuiltinTypeKind::RVV_INT16_M1;
    case 116: return BuiltinTypeKind::RVV_INT16_M2;
    case 117: return BuiltinTypeKind::RVV_INT16_M4;
    case 118: return BuiltinTypeKind::RVV_INT16_M8;
    case 119: return BuiltinTypeKind::RVV_UINT16_MF4;
    case 120: return BuiltinTypeKind::RVV_UINT16_MF2;
    case 121: return BuiltinTypeKind::RVV_UINT16_M1;
    case 122: return BuiltinTypeKind::RVV_UINT16_M2;
    case 123: return BuiltinTypeKind::RVV_UINT16_M4;
    case 124: return BuiltinTypeKind::RVV_UINT16_M8;
    case 125: return BuiltinTypeKind::RVV_INT32_MF2;
    case 126: return BuiltinTypeKind::RVV_INT32_M1;
    case 127: return BuiltinTypeKind::RVV_INT32_M2;
    case 128: return BuiltinTypeKind::RVV_INT32_M4;
    case 129: return BuiltinTypeKind::RVV_INT32_M8;
    case 130: return BuiltinTypeKind::RVV_UINT32_MF2;
    case 131: return BuiltinTypeKind::RVV_UINT32_M1;
    case 132: return BuiltinTypeKind::RVV_UINT32_M2;
    case 133: return BuiltinTypeKind::RVV_UINT32_M4;
    case 134: return BuiltinTypeKind::RVV_UINT32_M8;
    case 135: return BuiltinTypeKind::RVV_INT64_M1;
    case 136: return BuiltinTypeKind::RVV_INT64_M2;
    case 137: return BuiltinTypeKind::RVV_INT64_M4;
    case 138: return BuiltinTypeKind::RVV_INT64_M8;
    case 139: return BuiltinTypeKind::RVV_UINT64_M1;
    case 140: return BuiltinTypeKind::RVV_UINT64_M2;
    case 141: return BuiltinTypeKind::RVV_UINT64_M4;
    case 142: return BuiltinTypeKind::RVV_UINT64_M8;
    case 143: return BuiltinTypeKind::RVV_FLOAT16_MF4;
    case 144: return BuiltinTypeKind::RVV_FLOAT16_MF2;
    case 145: return BuiltinTypeKind::RVV_FLOAT16_M1;
    case 146: return BuiltinTypeKind::RVV_FLOAT16_M2;
    case 147: return BuiltinTypeKind::RVV_FLOAT16_M4;
    case 148: return BuiltinTypeKind::RVV_FLOAT16_M8;
    case 149: return BuiltinTypeKind::RVV_FLOAT32_MF2;
    case 150: return BuiltinTypeKind::RVV_FLOAT32_M1;
    case 151: return BuiltinTypeKind::RVV_FLOAT32_M2;
    case 152: return BuiltinTypeKind::RVV_FLOAT32_M4;
    case 153: return BuiltinTypeKind::RVV_FLOAT32_M8;
    case 154: return BuiltinTypeKind::RVV_FLOAT64_M1;
    case 155: return BuiltinTypeKind::RVV_FLOAT64_M2;
    case 156: return BuiltinTypeKind::RVV_FLOAT64_M4;
    case 157: return BuiltinTypeKind::RVV_FLOAT64_M8;
    case 158: return BuiltinTypeKind::RVV_BOOL1;
    case 159: return BuiltinTypeKind::RVV_BOOL2;
    case 160: return BuiltinTypeKind::RVV_BOOL4;
    case 161: return BuiltinTypeKind::RVV_BOOL8;
    case 162: return BuiltinTypeKind::RVV_BOOL16;
    case 163: return BuiltinTypeKind::RVV_BOOL32;
    case 164: return BuiltinTypeKind::RVV_BOOL64;
    case 165: return BuiltinTypeKind::VOID;
    case 166: return BuiltinTypeKind::BOOLEAN;
    case 167: return BuiltinTypeKind::CHARACTER_U;
    case 168: return BuiltinTypeKind::U_CHAR;
    case 169: return BuiltinTypeKind::W_CHAR_U;
    case 170: return BuiltinTypeKind::CHAR8;
    case 171: return BuiltinTypeKind::CHAR16;
    case 172: return BuiltinTypeKind::CHAR32;
    case 173: return BuiltinTypeKind::U_SHORT;
    case 174: return BuiltinTypeKind::U_INT;
    case 175: return BuiltinTypeKind::U_LONG;
    case 176: return BuiltinTypeKind::U_LONG_LONG;
    case 177: return BuiltinTypeKind::U_INT128;
    case 178: return BuiltinTypeKind::CHARACTER_S;
    case 179: return BuiltinTypeKind::S_CHAR;
    case 180: return BuiltinTypeKind::W_CHAR_S;
    case 181: return BuiltinTypeKind::SHORT;
    case 182: return BuiltinTypeKind::INT;
    case 183: return BuiltinTypeKind::LONG;
    case 184: return BuiltinTypeKind::LONG_LONG;
    case 185: return BuiltinTypeKind::INT128;
    case 186: return BuiltinTypeKind::SHORT_ACCUM;
    case 187: return BuiltinTypeKind::ACCUM;
    case 188: return BuiltinTypeKind::LONG_ACCUM;
    case 189: return BuiltinTypeKind::U_SHORT_ACCUM;
    case 190: return BuiltinTypeKind::U_ACCUM;
    case 191: return BuiltinTypeKind::U_LONG_ACCUM;
    case 192: return BuiltinTypeKind::SHORT_FRACT;
    case 193: return BuiltinTypeKind::FRACT;
    case 194: return BuiltinTypeKind::LONG_FRACT;
    case 195: return BuiltinTypeKind::U_SHORT_FRACT;
    case 196: return BuiltinTypeKind::U_FRACT;
    case 197: return BuiltinTypeKind::U_LONG_FRACT;
    case 198: return BuiltinTypeKind::SAT_SHORT_ACCUM;
    case 199: return BuiltinTypeKind::SAT_ACCUM;
    case 200: return BuiltinTypeKind::SAT_LONG_ACCUM;
    case 201: return BuiltinTypeKind::SAT_U_SHORT_ACCUM;
    case 202: return BuiltinTypeKind::SAT_U_ACCUM;
    case 203: return BuiltinTypeKind::SAT_U_LONG_ACCUM;
    case 204: return BuiltinTypeKind::SAT_SHORT_FRACT;
    case 205: return BuiltinTypeKind::SAT_FRACT;
    case 206: return BuiltinTypeKind::SAT_LONG_FRACT;
    case 207: return BuiltinTypeKind::SAT_U_SHORT_FRACT;
    case 208: return BuiltinTypeKind::SAT_U_FRACT;
    case 209: return BuiltinTypeKind::SAT_U_LONG_FRACT;
    case 210: return BuiltinTypeKind::HALF;
    case 211: return BuiltinTypeKind::FLOAT;
    case 212: return BuiltinTypeKind::DOUBLE;
    case 213: return BuiltinTypeKind::LONG_DOUBLE;
    case 214: return BuiltinTypeKind::FLOAT16;
    case 215: return BuiltinTypeKind::B_FLOAT16;
    case 216: return BuiltinTypeKind::FLOAT128;
    case 217: return BuiltinTypeKind::NULL_POINTER;
    case 218: return BuiltinTypeKind::OBJ_C_ID;
    case 219: return BuiltinTypeKind::OBJ_C_CLASS;
    case 220: return BuiltinTypeKind::OBJ_C_SEL;
    case 221: return BuiltinTypeKind::OCL_SAMPLER;
    case 222: return BuiltinTypeKind::OCL_EVENT;
    case 223: return BuiltinTypeKind::OCL_CLK_EVENT;
    case 224: return BuiltinTypeKind::OCL_QUEUE;
    case 225: return BuiltinTypeKind::OCL_RESERVE_ID;
    case 226: return BuiltinTypeKind::DEPENDENT;
    case 227: return BuiltinTypeKind::OVERLOAD;
    case 228: return BuiltinTypeKind::BOUND_MEMBER;
    case 229: return BuiltinTypeKind::PSEUDO_OBJECT;
    case 230: return BuiltinTypeKind::UNKNOWN_ANY;
    case 231: return BuiltinTypeKind::BUILTIN_FN;
    case 232: return BuiltinTypeKind::ARC_UNBRIDGED_CAST;
    case 233: return BuiltinTypeKind::INCOMPLETE_MATRIX_INDEX;
    case 234: return BuiltinTypeKind::OMP_ARRAY_SECTION;
    case 235: return BuiltinTypeKind::OMP_ARRAY_SHAPING;
    case 236: return BuiltinTypeKind::OMP_ITERATOR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(BuiltinTypeKind e) {
  switch (e) {
    case BuiltinTypeKind::OCL_IMAGE1_DRO: return "OCL_IMAGE1_DRO";
    case BuiltinTypeKind::OCL_IMAGE1_DARRAY_RO: return "OCL_IMAGE1_DARRAY_RO";
    case BuiltinTypeKind::OCL_IMAGE1_DBUFFER_RO: return "OCL_IMAGE1_DBUFFER_RO";
    case BuiltinTypeKind::OCL_IMAGE2_DRO: return "OCL_IMAGE2_DRO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_RO: return "OCL_IMAGE2_DARRAY_RO";
    case BuiltinTypeKind::OCL_IMAGE2_DDEPTH_RO: return "OCL_IMAGE2_DDEPTH_RO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_RO: return "OCL_IMAGE2_DARRAY_DEPTH_RO";
    case BuiltinTypeKind::OCL_IMAGE2_DMSAARO: return "OCL_IMAGE2_DMSAARO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAARO: return "OCL_IMAGE2_DARRAY_MSAARO";
    case BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_RO: return "OCL_IMAGE2_DMSAA_DEPTH_RO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_RO: return "OCL_IMAGE2_DARRAY_MSAA_DEPTH_RO";
    case BuiltinTypeKind::OCL_IMAGE3_DRO: return "OCL_IMAGE3_DRO";
    case BuiltinTypeKind::OCL_IMAGE1_DWO: return "OCL_IMAGE1_DWO";
    case BuiltinTypeKind::OCL_IMAGE1_DARRAY_WO: return "OCL_IMAGE1_DARRAY_WO";
    case BuiltinTypeKind::OCL_IMAGE1_DBUFFER_WO: return "OCL_IMAGE1_DBUFFER_WO";
    case BuiltinTypeKind::OCL_IMAGE2_DWO: return "OCL_IMAGE2_DWO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_WO: return "OCL_IMAGE2_DARRAY_WO";
    case BuiltinTypeKind::OCL_IMAGE2_DDEPTH_WO: return "OCL_IMAGE2_DDEPTH_WO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_WO: return "OCL_IMAGE2_DARRAY_DEPTH_WO";
    case BuiltinTypeKind::OCL_IMAGE2_DMSAAWO: return "OCL_IMAGE2_DMSAAWO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAAWO: return "OCL_IMAGE2_DARRAY_MSAAWO";
    case BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_WO: return "OCL_IMAGE2_DMSAA_DEPTH_WO";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_WO: return "OCL_IMAGE2_DARRAY_MSAA_DEPTH_WO";
    case BuiltinTypeKind::OCL_IMAGE3_DWO: return "OCL_IMAGE3_DWO";
    case BuiltinTypeKind::OCL_IMAGE1_DRW: return "OCL_IMAGE1_DRW";
    case BuiltinTypeKind::OCL_IMAGE1_DARRAY_RW: return "OCL_IMAGE1_DARRAY_RW";
    case BuiltinTypeKind::OCL_IMAGE1_DBUFFER_RW: return "OCL_IMAGE1_DBUFFER_RW";
    case BuiltinTypeKind::OCL_IMAGE2_DRW: return "OCL_IMAGE2_DRW";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_RW: return "OCL_IMAGE2_DARRAY_RW";
    case BuiltinTypeKind::OCL_IMAGE2_DDEPTH_RW: return "OCL_IMAGE2_DDEPTH_RW";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_RW: return "OCL_IMAGE2_DARRAY_DEPTH_RW";
    case BuiltinTypeKind::OCL_IMAGE2_DMSAARW: return "OCL_IMAGE2_DMSAARW";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAARW: return "OCL_IMAGE2_DARRAY_MSAARW";
    case BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_RW: return "OCL_IMAGE2_DMSAA_DEPTH_RW";
    case BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_RW: return "OCL_IMAGE2_DARRAY_MSAA_DEPTH_RW";
    case BuiltinTypeKind::OCL_IMAGE3_DRW: return "OCL_IMAGE3_DRW";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD: return "OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD: return "OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD: return "OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD: return "OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_RESULT: return "OCL_INTEL_SUBGROUP_AVC_MCE_RESULT";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT: return "OCL_INTEL_SUBGROUP_AVC_IME_RESULT";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_RESULT: return "OCL_INTEL_SUBGROUP_AVC_REF_RESULT";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_RESULT: return "OCL_INTEL_SUBGROUP_AVC_SIC_RESULT";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT: return "OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT: return "OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN: return "OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN";
    case BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN: return "OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN";
    case BuiltinTypeKind::SVE_INT8: return "SVE_INT8";
    case BuiltinTypeKind::SVE_INT16: return "SVE_INT16";
    case BuiltinTypeKind::SVE_INT32: return "SVE_INT32";
    case BuiltinTypeKind::SVE_INT64: return "SVE_INT64";
    case BuiltinTypeKind::SVE_UINT8: return "SVE_UINT8";
    case BuiltinTypeKind::SVE_UINT16: return "SVE_UINT16";
    case BuiltinTypeKind::SVE_UINT32: return "SVE_UINT32";
    case BuiltinTypeKind::SVE_UINT64: return "SVE_UINT64";
    case BuiltinTypeKind::SVE_FLOAT16: return "SVE_FLOAT16";
    case BuiltinTypeKind::SVE_FLOAT32: return "SVE_FLOAT32";
    case BuiltinTypeKind::SVE_FLOAT64: return "SVE_FLOAT64";
    case BuiltinTypeKind::SVE_B_FLOAT16: return "SVE_B_FLOAT16";
    case BuiltinTypeKind::SVE_INT8_X2: return "SVE_INT8_X2";
    case BuiltinTypeKind::SVE_INT16_X2: return "SVE_INT16_X2";
    case BuiltinTypeKind::SVE_INT32_X2: return "SVE_INT32_X2";
    case BuiltinTypeKind::SVE_INT64_X2: return "SVE_INT64_X2";
    case BuiltinTypeKind::SVE_UINT8_X2: return "SVE_UINT8_X2";
    case BuiltinTypeKind::SVE_UINT16_X2: return "SVE_UINT16_X2";
    case BuiltinTypeKind::SVE_UINT32_X2: return "SVE_UINT32_X2";
    case BuiltinTypeKind::SVE_UINT64_X2: return "SVE_UINT64_X2";
    case BuiltinTypeKind::SVE_FLOAT16_X2: return "SVE_FLOAT16_X2";
    case BuiltinTypeKind::SVE_FLOAT32_X2: return "SVE_FLOAT32_X2";
    case BuiltinTypeKind::SVE_FLOAT64_X2: return "SVE_FLOAT64_X2";
    case BuiltinTypeKind::SVE_B_FLOAT16_X2: return "SVE_B_FLOAT16_X2";
    case BuiltinTypeKind::SVE_INT8_X3: return "SVE_INT8_X3";
    case BuiltinTypeKind::SVE_INT16_X3: return "SVE_INT16_X3";
    case BuiltinTypeKind::SVE_INT32_X3: return "SVE_INT32_X3";
    case BuiltinTypeKind::SVE_INT64_X3: return "SVE_INT64_X3";
    case BuiltinTypeKind::SVE_UINT8_X3: return "SVE_UINT8_X3";
    case BuiltinTypeKind::SVE_UINT16_X3: return "SVE_UINT16_X3";
    case BuiltinTypeKind::SVE_UINT32_X3: return "SVE_UINT32_X3";
    case BuiltinTypeKind::SVE_UINT64_X3: return "SVE_UINT64_X3";
    case BuiltinTypeKind::SVE_FLOAT16_X3: return "SVE_FLOAT16_X3";
    case BuiltinTypeKind::SVE_FLOAT32_X3: return "SVE_FLOAT32_X3";
    case BuiltinTypeKind::SVE_FLOAT64_X3: return "SVE_FLOAT64_X3";
    case BuiltinTypeKind::SVE_B_FLOAT16_X3: return "SVE_B_FLOAT16_X3";
    case BuiltinTypeKind::SVE_INT8_X4: return "SVE_INT8_X4";
    case BuiltinTypeKind::SVE_INT16_X4: return "SVE_INT16_X4";
    case BuiltinTypeKind::SVE_INT32_X4: return "SVE_INT32_X4";
    case BuiltinTypeKind::SVE_INT64_X4: return "SVE_INT64_X4";
    case BuiltinTypeKind::SVE_UINT8_X4: return "SVE_UINT8_X4";
    case BuiltinTypeKind::SVE_UINT16_X4: return "SVE_UINT16_X4";
    case BuiltinTypeKind::SVE_UINT32_X4: return "SVE_UINT32_X4";
    case BuiltinTypeKind::SVE_UINT64_X4: return "SVE_UINT64_X4";
    case BuiltinTypeKind::SVE_FLOAT16_X4: return "SVE_FLOAT16_X4";
    case BuiltinTypeKind::SVE_FLOAT32_X4: return "SVE_FLOAT32_X4";
    case BuiltinTypeKind::SVE_FLOAT64_X4: return "SVE_FLOAT64_X4";
    case BuiltinTypeKind::SVE_B_FLOAT16_X4: return "SVE_B_FLOAT16_X4";
    case BuiltinTypeKind::SVE_BOOLEAN: return "SVE_BOOLEAN";
    case BuiltinTypeKind::VECTOR_QUAD: return "VECTOR_QUAD";
    case BuiltinTypeKind::VECTOR_PAIR: return "VECTOR_PAIR";
    case BuiltinTypeKind::RVV_INT8_MF8: return "RVV_INT8_MF8";
    case BuiltinTypeKind::RVV_INT8_MF4: return "RVV_INT8_MF4";
    case BuiltinTypeKind::RVV_INT8_MF2: return "RVV_INT8_MF2";
    case BuiltinTypeKind::RVV_INT8_M1: return "RVV_INT8_M1";
    case BuiltinTypeKind::RVV_INT8_M2: return "RVV_INT8_M2";
    case BuiltinTypeKind::RVV_INT8_M4: return "RVV_INT8_M4";
    case BuiltinTypeKind::RVV_INT8_M8: return "RVV_INT8_M8";
    case BuiltinTypeKind::RVV_UINT8_MF8: return "RVV_UINT8_MF8";
    case BuiltinTypeKind::RVV_UINT8_MF4: return "RVV_UINT8_MF4";
    case BuiltinTypeKind::RVV_UINT8_MF2: return "RVV_UINT8_MF2";
    case BuiltinTypeKind::RVV_UINT8_M1: return "RVV_UINT8_M1";
    case BuiltinTypeKind::RVV_UINT8_M2: return "RVV_UINT8_M2";
    case BuiltinTypeKind::RVV_UINT8_M4: return "RVV_UINT8_M4";
    case BuiltinTypeKind::RVV_UINT8_M8: return "RVV_UINT8_M8";
    case BuiltinTypeKind::RVV_INT16_MF4: return "RVV_INT16_MF4";
    case BuiltinTypeKind::RVV_INT16_MF2: return "RVV_INT16_MF2";
    case BuiltinTypeKind::RVV_INT16_M1: return "RVV_INT16_M1";
    case BuiltinTypeKind::RVV_INT16_M2: return "RVV_INT16_M2";
    case BuiltinTypeKind::RVV_INT16_M4: return "RVV_INT16_M4";
    case BuiltinTypeKind::RVV_INT16_M8: return "RVV_INT16_M8";
    case BuiltinTypeKind::RVV_UINT16_MF4: return "RVV_UINT16_MF4";
    case BuiltinTypeKind::RVV_UINT16_MF2: return "RVV_UINT16_MF2";
    case BuiltinTypeKind::RVV_UINT16_M1: return "RVV_UINT16_M1";
    case BuiltinTypeKind::RVV_UINT16_M2: return "RVV_UINT16_M2";
    case BuiltinTypeKind::RVV_UINT16_M4: return "RVV_UINT16_M4";
    case BuiltinTypeKind::RVV_UINT16_M8: return "RVV_UINT16_M8";
    case BuiltinTypeKind::RVV_INT32_MF2: return "RVV_INT32_MF2";
    case BuiltinTypeKind::RVV_INT32_M1: return "RVV_INT32_M1";
    case BuiltinTypeKind::RVV_INT32_M2: return "RVV_INT32_M2";
    case BuiltinTypeKind::RVV_INT32_M4: return "RVV_INT32_M4";
    case BuiltinTypeKind::RVV_INT32_M8: return "RVV_INT32_M8";
    case BuiltinTypeKind::RVV_UINT32_MF2: return "RVV_UINT32_MF2";
    case BuiltinTypeKind::RVV_UINT32_M1: return "RVV_UINT32_M1";
    case BuiltinTypeKind::RVV_UINT32_M2: return "RVV_UINT32_M2";
    case BuiltinTypeKind::RVV_UINT32_M4: return "RVV_UINT32_M4";
    case BuiltinTypeKind::RVV_UINT32_M8: return "RVV_UINT32_M8";
    case BuiltinTypeKind::RVV_INT64_M1: return "RVV_INT64_M1";
    case BuiltinTypeKind::RVV_INT64_M2: return "RVV_INT64_M2";
    case BuiltinTypeKind::RVV_INT64_M4: return "RVV_INT64_M4";
    case BuiltinTypeKind::RVV_INT64_M8: return "RVV_INT64_M8";
    case BuiltinTypeKind::RVV_UINT64_M1: return "RVV_UINT64_M1";
    case BuiltinTypeKind::RVV_UINT64_M2: return "RVV_UINT64_M2";
    case BuiltinTypeKind::RVV_UINT64_M4: return "RVV_UINT64_M4";
    case BuiltinTypeKind::RVV_UINT64_M8: return "RVV_UINT64_M8";
    case BuiltinTypeKind::RVV_FLOAT16_MF4: return "RVV_FLOAT16_MF4";
    case BuiltinTypeKind::RVV_FLOAT16_MF2: return "RVV_FLOAT16_MF2";
    case BuiltinTypeKind::RVV_FLOAT16_M1: return "RVV_FLOAT16_M1";
    case BuiltinTypeKind::RVV_FLOAT16_M2: return "RVV_FLOAT16_M2";
    case BuiltinTypeKind::RVV_FLOAT16_M4: return "RVV_FLOAT16_M4";
    case BuiltinTypeKind::RVV_FLOAT16_M8: return "RVV_FLOAT16_M8";
    case BuiltinTypeKind::RVV_FLOAT32_MF2: return "RVV_FLOAT32_MF2";
    case BuiltinTypeKind::RVV_FLOAT32_M1: return "RVV_FLOAT32_M1";
    case BuiltinTypeKind::RVV_FLOAT32_M2: return "RVV_FLOAT32_M2";
    case BuiltinTypeKind::RVV_FLOAT32_M4: return "RVV_FLOAT32_M4";
    case BuiltinTypeKind::RVV_FLOAT32_M8: return "RVV_FLOAT32_M8";
    case BuiltinTypeKind::RVV_FLOAT64_M1: return "RVV_FLOAT64_M1";
    case BuiltinTypeKind::RVV_FLOAT64_M2: return "RVV_FLOAT64_M2";
    case BuiltinTypeKind::RVV_FLOAT64_M4: return "RVV_FLOAT64_M4";
    case BuiltinTypeKind::RVV_FLOAT64_M8: return "RVV_FLOAT64_M8";
    case BuiltinTypeKind::RVV_BOOL1: return "RVV_BOOL1";
    case BuiltinTypeKind::RVV_BOOL2: return "RVV_BOOL2";
    case BuiltinTypeKind::RVV_BOOL4: return "RVV_BOOL4";
    case BuiltinTypeKind::RVV_BOOL8: return "RVV_BOOL8";
    case BuiltinTypeKind::RVV_BOOL16: return "RVV_BOOL16";
    case BuiltinTypeKind::RVV_BOOL32: return "RVV_BOOL32";
    case BuiltinTypeKind::RVV_BOOL64: return "RVV_BOOL64";
    case BuiltinTypeKind::VOID: return "VOID";
    case BuiltinTypeKind::BOOLEAN: return "BOOLEAN";
    case BuiltinTypeKind::CHARACTER_U: return "CHARACTER_U";
    case BuiltinTypeKind::U_CHAR: return "U_CHAR";
    case BuiltinTypeKind::W_CHAR_U: return "W_CHAR_U";
    case BuiltinTypeKind::CHAR8: return "CHAR8";
    case BuiltinTypeKind::CHAR16: return "CHAR16";
    case BuiltinTypeKind::CHAR32: return "CHAR32";
    case BuiltinTypeKind::U_SHORT: return "U_SHORT";
    case BuiltinTypeKind::U_INT: return "U_INT";
    case BuiltinTypeKind::U_LONG: return "U_LONG";
    case BuiltinTypeKind::U_LONG_LONG: return "U_LONG_LONG";
    case BuiltinTypeKind::U_INT128: return "U_INT128";
    case BuiltinTypeKind::CHARACTER_S: return "CHARACTER_S";
    case BuiltinTypeKind::S_CHAR: return "S_CHAR";
    case BuiltinTypeKind::W_CHAR_S: return "W_CHAR_S";
    case BuiltinTypeKind::SHORT: return "SHORT";
    case BuiltinTypeKind::INT: return "INT";
    case BuiltinTypeKind::LONG: return "LONG";
    case BuiltinTypeKind::LONG_LONG: return "LONG_LONG";
    case BuiltinTypeKind::INT128: return "INT128";
    case BuiltinTypeKind::SHORT_ACCUM: return "SHORT_ACCUM";
    case BuiltinTypeKind::ACCUM: return "ACCUM";
    case BuiltinTypeKind::LONG_ACCUM: return "LONG_ACCUM";
    case BuiltinTypeKind::U_SHORT_ACCUM: return "U_SHORT_ACCUM";
    case BuiltinTypeKind::U_ACCUM: return "U_ACCUM";
    case BuiltinTypeKind::U_LONG_ACCUM: return "U_LONG_ACCUM";
    case BuiltinTypeKind::SHORT_FRACT: return "SHORT_FRACT";
    case BuiltinTypeKind::FRACT: return "FRACT";
    case BuiltinTypeKind::LONG_FRACT: return "LONG_FRACT";
    case BuiltinTypeKind::U_SHORT_FRACT: return "U_SHORT_FRACT";
    case BuiltinTypeKind::U_FRACT: return "U_FRACT";
    case BuiltinTypeKind::U_LONG_FRACT: return "U_LONG_FRACT";
    case BuiltinTypeKind::SAT_SHORT_ACCUM: return "SAT_SHORT_ACCUM";
    case BuiltinTypeKind::SAT_ACCUM: return "SAT_ACCUM";
    case BuiltinTypeKind::SAT_LONG_ACCUM: return "SAT_LONG_ACCUM";
    case BuiltinTypeKind::SAT_U_SHORT_ACCUM: return "SAT_U_SHORT_ACCUM";
    case BuiltinTypeKind::SAT_U_ACCUM: return "SAT_U_ACCUM";
    case BuiltinTypeKind::SAT_U_LONG_ACCUM: return "SAT_U_LONG_ACCUM";
    case BuiltinTypeKind::SAT_SHORT_FRACT: return "SAT_SHORT_FRACT";
    case BuiltinTypeKind::SAT_FRACT: return "SAT_FRACT";
    case BuiltinTypeKind::SAT_LONG_FRACT: return "SAT_LONG_FRACT";
    case BuiltinTypeKind::SAT_U_SHORT_FRACT: return "SAT_U_SHORT_FRACT";
    case BuiltinTypeKind::SAT_U_FRACT: return "SAT_U_FRACT";
    case BuiltinTypeKind::SAT_U_LONG_FRACT: return "SAT_U_LONG_FRACT";
    case BuiltinTypeKind::HALF: return "HALF";
    case BuiltinTypeKind::FLOAT: return "FLOAT";
    case BuiltinTypeKind::DOUBLE: return "DOUBLE";
    case BuiltinTypeKind::LONG_DOUBLE: return "LONG_DOUBLE";
    case BuiltinTypeKind::FLOAT16: return "FLOAT16";
    case BuiltinTypeKind::B_FLOAT16: return "B_FLOAT16";
    case BuiltinTypeKind::FLOAT128: return "FLOAT128";
    case BuiltinTypeKind::NULL_POINTER: return "NULL_POINTER";
    case BuiltinTypeKind::OBJ_C_ID: return "OBJ_C_ID";
    case BuiltinTypeKind::OBJ_C_CLASS: return "OBJ_C_CLASS";
    case BuiltinTypeKind::OBJ_C_SEL: return "OBJ_C_SEL";
    case BuiltinTypeKind::OCL_SAMPLER: return "OCL_SAMPLER";
    case BuiltinTypeKind::OCL_EVENT: return "OCL_EVENT";
    case BuiltinTypeKind::OCL_CLK_EVENT: return "OCL_CLK_EVENT";
    case BuiltinTypeKind::OCL_QUEUE: return "OCL_QUEUE";
    case BuiltinTypeKind::OCL_RESERVE_ID: return "OCL_RESERVE_ID";
    case BuiltinTypeKind::DEPENDENT: return "DEPENDENT";
    case BuiltinTypeKind::OVERLOAD: return "OVERLOAD";
    case BuiltinTypeKind::BOUND_MEMBER: return "BOUND_MEMBER";
    case BuiltinTypeKind::PSEUDO_OBJECT: return "PSEUDO_OBJECT";
    case BuiltinTypeKind::UNKNOWN_ANY: return "UNKNOWN_ANY";
    case BuiltinTypeKind::BUILTIN_FN: return "BUILTIN_FN";
    case BuiltinTypeKind::ARC_UNBRIDGED_CAST: return "ARC_UNBRIDGED_CAST";
    case BuiltinTypeKind::INCOMPLETE_MATRIX_INDEX: return "INCOMPLETE_MATRIX_INDEX";
    case BuiltinTypeKind::OMP_ARRAY_SECTION: return "OMP_ARRAY_SECTION";
    case BuiltinTypeKind::OMP_ARRAY_SHAPING: return "OMP_ARRAY_SHAPING";
    case BuiltinTypeKind::OMP_ITERATOR: return "OMP_ITERATOR";
    default: return "<invalid>";
  }
}

CXXConstructExprConstructionKind FromPasta(pasta::CXXConstructExprConstructionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CXXConstructExprConstructionKind::COMPLETE;
    case 1: return CXXConstructExprConstructionKind::NON_VIRTUAL_BASE;
    case 2: return CXXConstructExprConstructionKind::VIRTUAL_BASE;
    case 3: return CXXConstructExprConstructionKind::DELEGATING;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CXXConstructExprConstructionKind e) {
  switch (e) {
    case CXXConstructExprConstructionKind::COMPLETE: return "COMPLETE";
    case CXXConstructExprConstructionKind::NON_VIRTUAL_BASE: return "NON_VIRTUAL_BASE";
    case CXXConstructExprConstructionKind::VIRTUAL_BASE: return "VIRTUAL_BASE";
    case CXXConstructExprConstructionKind::DELEGATING: return "DELEGATING";
    default: return "<invalid>";
  }
}

CXXNewExprInitializationStyle FromPasta(pasta::CXXNewExprInitializationStyle e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CXXNewExprInitializationStyle::NO_INITIALIZER;
    case 1: return CXXNewExprInitializationStyle::CALL_INITIALIZER;
    case 2: return CXXNewExprInitializationStyle::LIST_INITIALIZER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CXXNewExprInitializationStyle e) {
  switch (e) {
    case CXXNewExprInitializationStyle::NO_INITIALIZER: return "NO_INITIALIZER";
    case CXXNewExprInitializationStyle::CALL_INITIALIZER: return "CALL_INITIALIZER";
    case CXXNewExprInitializationStyle::LIST_INITIALIZER: return "LIST_INITIALIZER";
    default: return "<invalid>";
  }
}

CallExprADLCallKind FromPasta(pasta::CallExprADLCallKind e) {
  switch (static_cast<int>(e)) {
    case 0: return CallExprADLCallKind::NOT_ADL;
    case 1: return CallExprADLCallKind::USES_ADL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CallExprADLCallKind e) {
  switch (e) {
    case CallExprADLCallKind::NOT_ADL: return "NOT_ADL";
    case CallExprADLCallKind::USES_ADL: return "USES_ADL";
    default: return "<invalid>";
  }
}

CapturedStmtVariableCaptureKind FromPasta(pasta::CapturedStmtVariableCaptureKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CapturedStmtVariableCaptureKind::THIS;
    case 1: return CapturedStmtVariableCaptureKind::BY_REFERENCE;
    case 2: return CapturedStmtVariableCaptureKind::BY_COPY;
    case 3: return CapturedStmtVariableCaptureKind::VLA_TYPE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CapturedStmtVariableCaptureKind e) {
  switch (e) {
    case CapturedStmtVariableCaptureKind::THIS: return "THIS";
    case CapturedStmtVariableCaptureKind::BY_REFERENCE: return "BY_REFERENCE";
    case CapturedStmtVariableCaptureKind::BY_COPY: return "BY_COPY";
    case CapturedStmtVariableCaptureKind::VLA_TYPE: return "VLA_TYPE";
    default: return "<invalid>";
  }
}

CharacterLiteralCharacterKind FromPasta(pasta::CharacterLiteralCharacterKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CharacterLiteralCharacterKind::ASCII;
    case 1: return CharacterLiteralCharacterKind::WIDE;
    case 2: return CharacterLiteralCharacterKind::UTF8;
    case 3: return CharacterLiteralCharacterKind::UTF16;
    case 4: return CharacterLiteralCharacterKind::UTF32;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CharacterLiteralCharacterKind e) {
  switch (e) {
    case CharacterLiteralCharacterKind::ASCII: return "ASCII";
    case CharacterLiteralCharacterKind::WIDE: return "WIDE";
    case CharacterLiteralCharacterKind::UTF8: return "UTF8";
    case CharacterLiteralCharacterKind::UTF16: return "UTF16";
    case CharacterLiteralCharacterKind::UTF32: return "UTF32";
    default: return "<invalid>";
  }
}

ConstantExprResultStorageKind FromPasta(pasta::ConstantExprResultStorageKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConstantExprResultStorageKind::NONE;
    case 1: return ConstantExprResultStorageKind::INT64;
    case 2: return ConstantExprResultStorageKind::AP_VALUE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ConstantExprResultStorageKind e) {
  switch (e) {
    case ConstantExprResultStorageKind::NONE: return "NONE";
    case ConstantExprResultStorageKind::INT64: return "INT64";
    case ConstantExprResultStorageKind::AP_VALUE: return "AP_VALUE";
    default: return "<invalid>";
  }
}

DeclFriendObjectKind FromPasta(pasta::DeclFriendObjectKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclFriendObjectKind::NONE;
    case 1: return DeclFriendObjectKind::DECLARED;
    case 2: return DeclFriendObjectKind::UNDECLARED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DeclFriendObjectKind e) {
  switch (e) {
    case DeclFriendObjectKind::NONE: return "NONE";
    case DeclFriendObjectKind::DECLARED: return "DECLARED";
    case DeclFriendObjectKind::UNDECLARED: return "UNDECLARED";
    default: return "<invalid>";
  }
}

DeclIdentifierNamespace FromPasta(pasta::DeclIdentifierNamespace e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return DeclIdentifierNamespace::LABEL;
    case 2: return DeclIdentifierNamespace::TAG;
    case 4: return DeclIdentifierNamespace::TYPE;
    case 8: return DeclIdentifierNamespace::MEMBER;
    case 16: return DeclIdentifierNamespace::NAMESPACE;
    case 32: return DeclIdentifierNamespace::ORDINARY;
    case 64: return DeclIdentifierNamespace::OBJ_C_PROTOCOL;
    case 128: return DeclIdentifierNamespace::ORDINARY_FRIEND;
    case 256: return DeclIdentifierNamespace::TAG_FRIEND;
    case 512: return DeclIdentifierNamespace::USING;
    case 1024: return DeclIdentifierNamespace::NON_MEMBER_OPERATOR;
    case 2048: return DeclIdentifierNamespace::LOCAL_EXTERN;
    case 4096: return DeclIdentifierNamespace::OMP_REDUCTION;
    case 8192: return DeclIdentifierNamespace::OMP_MAPPER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DeclIdentifierNamespace e) {
  switch (e) {
    case DeclIdentifierNamespace::LABEL: return "LABEL";
    case DeclIdentifierNamespace::TAG: return "TAG";
    case DeclIdentifierNamespace::TYPE: return "TYPE";
    case DeclIdentifierNamespace::MEMBER: return "MEMBER";
    case DeclIdentifierNamespace::NAMESPACE: return "NAMESPACE";
    case DeclIdentifierNamespace::ORDINARY: return "ORDINARY";
    case DeclIdentifierNamespace::OBJ_C_PROTOCOL: return "OBJ_C_PROTOCOL";
    case DeclIdentifierNamespace::ORDINARY_FRIEND: return "ORDINARY_FRIEND";
    case DeclIdentifierNamespace::TAG_FRIEND: return "TAG_FRIEND";
    case DeclIdentifierNamespace::USING: return "USING";
    case DeclIdentifierNamespace::NON_MEMBER_OPERATOR: return "NON_MEMBER_OPERATOR";
    case DeclIdentifierNamespace::LOCAL_EXTERN: return "LOCAL_EXTERN";
    case DeclIdentifierNamespace::OMP_REDUCTION: return "OMP_REDUCTION";
    case DeclIdentifierNamespace::OMP_MAPPER: return "OMP_MAPPER";
    default: return "<invalid>";
  }
}

DeclModuleOwnershipKind FromPasta(pasta::DeclModuleOwnershipKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclModuleOwnershipKind::UNOWNED;
    case 1: return DeclModuleOwnershipKind::VISIBLE;
    case 2: return DeclModuleOwnershipKind::VISIBLE_WHEN_IMPORTED;
    case 3: return DeclModuleOwnershipKind::MODULE_PRIVATE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DeclModuleOwnershipKind e) {
  switch (e) {
    case DeclModuleOwnershipKind::UNOWNED: return "UNOWNED";
    case DeclModuleOwnershipKind::VISIBLE: return "VISIBLE";
    case DeclModuleOwnershipKind::VISIBLE_WHEN_IMPORTED: return "VISIBLE_WHEN_IMPORTED";
    case DeclModuleOwnershipKind::MODULE_PRIVATE: return "MODULE_PRIVATE";
    default: return "<invalid>";
  }
}

DeclObjCDeclQualifier FromPasta(pasta::DeclObjCDeclQualifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclObjCDeclQualifier::NONE;
    case 1: return DeclObjCDeclQualifier::IN;
    case 2: return DeclObjCDeclQualifier::INOUT;
    case 4: return DeclObjCDeclQualifier::OUT;
    case 8: return DeclObjCDeclQualifier::BYCOPY;
    case 16: return DeclObjCDeclQualifier::BYREF;
    case 32: return DeclObjCDeclQualifier::ONEWAY;
    case 64: return DeclObjCDeclQualifier::CS_NULLABILITY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DeclObjCDeclQualifier e) {
  switch (e) {
    case DeclObjCDeclQualifier::NONE: return "NONE";
    case DeclObjCDeclQualifier::IN: return "IN";
    case DeclObjCDeclQualifier::INOUT: return "INOUT";
    case DeclObjCDeclQualifier::OUT: return "OUT";
    case DeclObjCDeclQualifier::BYCOPY: return "BYCOPY";
    case DeclObjCDeclQualifier::BYREF: return "BYREF";
    case DeclObjCDeclQualifier::ONEWAY: return "ONEWAY";
    case DeclObjCDeclQualifier::CS_NULLABILITY: return "CS_NULLABILITY";
    default: return "<invalid>";
  }
}

ExprConstantExprKind FromPasta(pasta::ExprConstantExprKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExprConstantExprKind::NORMAL;
    case 1: return ExprConstantExprKind::NON_CLASS_TEMPLATE_ARGUMENT;
    case 2: return ExprConstantExprKind::CLASS_TEMPLATE_ARGUMENT;
    case 3: return ExprConstantExprKind::IMMEDIATE_INVOCATION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprConstantExprKind e) {
  switch (e) {
    case ExprConstantExprKind::NORMAL: return "NORMAL";
    case ExprConstantExprKind::NON_CLASS_TEMPLATE_ARGUMENT: return "NON_CLASS_TEMPLATE_ARGUMENT";
    case ExprConstantExprKind::CLASS_TEMPLATE_ARGUMENT: return "CLASS_TEMPLATE_ARGUMENT";
    case ExprConstantExprKind::IMMEDIATE_INVOCATION: return "IMMEDIATE_INVOCATION";
    default: return "<invalid>";
  }
}

ExprLValueClassification FromPasta(pasta::ExprLValueClassification e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprLValueClassification::VALID;
    case 1: return ExprLValueClassification::NOT_OBJECT_TYPE;
    case 2: return ExprLValueClassification::INCOMPLETE_VOID_TYPE;
    case 3: return ExprLValueClassification::DUPLICATE_VECTOR_COMPONENTS;
    case 4: return ExprLValueClassification::INVALID_EXPRESSION;
    case 5: return ExprLValueClassification::INVALID_MESSAGE_EXPRESSION;
    case 6: return ExprLValueClassification::MEMBER_FUNCTION;
    case 7: return ExprLValueClassification::SUB_OBJ_C_PROPERTY_SETTING;
    case 8: return ExprLValueClassification::CLASS_TEMPORARY;
    case 9: return ExprLValueClassification::ARRAY_TEMPORARY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprLValueClassification e) {
  switch (e) {
    case ExprLValueClassification::VALID: return "VALID";
    case ExprLValueClassification::NOT_OBJECT_TYPE: return "NOT_OBJECT_TYPE";
    case ExprLValueClassification::INCOMPLETE_VOID_TYPE: return "INCOMPLETE_VOID_TYPE";
    case ExprLValueClassification::DUPLICATE_VECTOR_COMPONENTS: return "DUPLICATE_VECTOR_COMPONENTS";
    case ExprLValueClassification::INVALID_EXPRESSION: return "INVALID_EXPRESSION";
    case ExprLValueClassification::INVALID_MESSAGE_EXPRESSION: return "INVALID_MESSAGE_EXPRESSION";
    case ExprLValueClassification::MEMBER_FUNCTION: return "MEMBER_FUNCTION";
    case ExprLValueClassification::SUB_OBJ_C_PROPERTY_SETTING: return "SUB_OBJ_C_PROPERTY_SETTING";
    case ExprLValueClassification::CLASS_TEMPORARY: return "CLASS_TEMPORARY";
    case ExprLValueClassification::ARRAY_TEMPORARY: return "ARRAY_TEMPORARY";
    default: return "<invalid>";
  }
}

ExprNullPointerConstantKind FromPasta(pasta::ExprNullPointerConstantKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprNullPointerConstantKind::NOT_NULL;
    case 1: return ExprNullPointerConstantKind::ZERO_EXPRESSION;
    case 2: return ExprNullPointerConstantKind::ZERO_LITERAL;
    case 3: return ExprNullPointerConstantKind::CXX11_NULLPTR;
    case 4: return ExprNullPointerConstantKind::GNU_NULL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprNullPointerConstantKind e) {
  switch (e) {
    case ExprNullPointerConstantKind::NOT_NULL: return "NOT_NULL";
    case ExprNullPointerConstantKind::ZERO_EXPRESSION: return "ZERO_EXPRESSION";
    case ExprNullPointerConstantKind::ZERO_LITERAL: return "ZERO_LITERAL";
    case ExprNullPointerConstantKind::CXX11_NULLPTR: return "CXX11_NULLPTR";
    case ExprNullPointerConstantKind::GNU_NULL: return "GNU_NULL";
    default: return "<invalid>";
  }
}

ExprNullPointerConstantValueDependence FromPasta(pasta::ExprNullPointerConstantValueDependence e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprNullPointerConstantValueDependence::NEVER_VALUE_DEPENDENT;
    case 1: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NULL;
    case 2: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NOT_NULL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprNullPointerConstantValueDependence e) {
  switch (e) {
    case ExprNullPointerConstantValueDependence::NEVER_VALUE_DEPENDENT: return "NEVER_VALUE_DEPENDENT";
    case ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NULL: return "VALUE_DEPENDENT_IS_NULL";
    case ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NOT_NULL: return "VALUE_DEPENDENT_IS_NOT_NULL";
    default: return "<invalid>";
  }
}

ExprSideEffectsKind FromPasta(pasta::ExprSideEffectsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprSideEffectsKind::NO_SIDE_EFFECTS;
    case 1: return ExprSideEffectsKind::ALLOW_UNDEFINED_BEHAVIOR;
    case 2: return ExprSideEffectsKind::ALLOW_SIDE_EFFECTS;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprSideEffectsKind e) {
  switch (e) {
    case ExprSideEffectsKind::NO_SIDE_EFFECTS: return "NO_SIDE_EFFECTS";
    case ExprSideEffectsKind::ALLOW_UNDEFINED_BEHAVIOR: return "ALLOW_UNDEFINED_BEHAVIOR";
    case ExprSideEffectsKind::ALLOW_SIDE_EFFECTS: return "ALLOW_SIDE_EFFECTS";
    default: return "<invalid>";
  }
}

ExprisModifiableLvalueResult FromPasta(pasta::ExprisModifiableLvalueResult e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprisModifiableLvalueResult::VALID;
    case 1: return ExprisModifiableLvalueResult::NOT_OBJECT_TYPE;
    case 2: return ExprisModifiableLvalueResult::INCOMPLETE_VOID_TYPE;
    case 3: return ExprisModifiableLvalueResult::DUPLICATE_VECTOR_COMPONENTS;
    case 4: return ExprisModifiableLvalueResult::INVALID_EXPRESSION;
    case 5: return ExprisModifiableLvalueResult::L_VALUE_CAST;
    case 6: return ExprisModifiableLvalueResult::INCOMPLETE_TYPE;
    case 7: return ExprisModifiableLvalueResult::CONST_QUALIFIED;
    case 8: return ExprisModifiableLvalueResult::CONST_QUALIFIED_FIELD;
    case 9: return ExprisModifiableLvalueResult::CONST_ADDR_SPACE;
    case 10: return ExprisModifiableLvalueResult::ARRAY_TYPE;
    case 11: return ExprisModifiableLvalueResult::NO_SETTER_PROPERTY;
    case 12: return ExprisModifiableLvalueResult::MEMBER_FUNCTION;
    case 13: return ExprisModifiableLvalueResult::SUB_OBJ_C_PROPERTY_SETTING;
    case 14: return ExprisModifiableLvalueResult::INVALID_MESSAGE_EXPRESSION;
    case 15: return ExprisModifiableLvalueResult::CLASS_TEMPORARY;
    case 16: return ExprisModifiableLvalueResult::ARRAY_TEMPORARY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprisModifiableLvalueResult e) {
  switch (e) {
    case ExprisModifiableLvalueResult::VALID: return "VALID";
    case ExprisModifiableLvalueResult::NOT_OBJECT_TYPE: return "NOT_OBJECT_TYPE";
    case ExprisModifiableLvalueResult::INCOMPLETE_VOID_TYPE: return "INCOMPLETE_VOID_TYPE";
    case ExprisModifiableLvalueResult::DUPLICATE_VECTOR_COMPONENTS: return "DUPLICATE_VECTOR_COMPONENTS";
    case ExprisModifiableLvalueResult::INVALID_EXPRESSION: return "INVALID_EXPRESSION";
    case ExprisModifiableLvalueResult::L_VALUE_CAST: return "L_VALUE_CAST";
    case ExprisModifiableLvalueResult::INCOMPLETE_TYPE: return "INCOMPLETE_TYPE";
    case ExprisModifiableLvalueResult::CONST_QUALIFIED: return "CONST_QUALIFIED";
    case ExprisModifiableLvalueResult::CONST_QUALIFIED_FIELD: return "CONST_QUALIFIED_FIELD";
    case ExprisModifiableLvalueResult::CONST_ADDR_SPACE: return "CONST_ADDR_SPACE";
    case ExprisModifiableLvalueResult::ARRAY_TYPE: return "ARRAY_TYPE";
    case ExprisModifiableLvalueResult::NO_SETTER_PROPERTY: return "NO_SETTER_PROPERTY";
    case ExprisModifiableLvalueResult::MEMBER_FUNCTION: return "MEMBER_FUNCTION";
    case ExprisModifiableLvalueResult::SUB_OBJ_C_PROPERTY_SETTING: return "SUB_OBJ_C_PROPERTY_SETTING";
    case ExprisModifiableLvalueResult::INVALID_MESSAGE_EXPRESSION: return "INVALID_MESSAGE_EXPRESSION";
    case ExprisModifiableLvalueResult::CLASS_TEMPORARY: return "CLASS_TEMPORARY";
    case ExprisModifiableLvalueResult::ARRAY_TEMPORARY: return "ARRAY_TEMPORARY";
    default: return "<invalid>";
  }
}

FunctionDeclTemplatedKind FromPasta(pasta::FunctionDeclTemplatedKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FunctionDeclTemplatedKind::NON_TEMPLATE;
    case 1: return FunctionDeclTemplatedKind::FUNCTION_TEMPLATE;
    case 2: return FunctionDeclTemplatedKind::MEMBER_SPECIALIZATION;
    case 3: return FunctionDeclTemplatedKind::FUNCTION_TEMPLATE_SPECIALIZATION;
    case 4: return FunctionDeclTemplatedKind::DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(FunctionDeclTemplatedKind e) {
  switch (e) {
    case FunctionDeclTemplatedKind::NON_TEMPLATE: return "NON_TEMPLATE";
    case FunctionDeclTemplatedKind::FUNCTION_TEMPLATE: return "FUNCTION_TEMPLATE";
    case FunctionDeclTemplatedKind::MEMBER_SPECIALIZATION: return "MEMBER_SPECIALIZATION";
    case FunctionDeclTemplatedKind::FUNCTION_TEMPLATE_SPECIALIZATION: return "FUNCTION_TEMPLATE_SPECIALIZATION";
    case FunctionDeclTemplatedKind::DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION: return "DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION";
    default: return "<invalid>";
  }
}

ImplicitCastExprOnStack FromPasta(pasta::ImplicitCastExprOnStack e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ImplicitCastExprOnStack::ON_STACK;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ImplicitCastExprOnStack e) {
  switch (e) {
    case ImplicitCastExprOnStack::ON_STACK: return "ON_STACK";
    default: return "<invalid>";
  }
}

ImplicitParamDeclImplicitParamKind FromPasta(pasta::ImplicitParamDeclImplicitParamKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ImplicitParamDeclImplicitParamKind::OBJ_C_SELF;
    case 1: return ImplicitParamDeclImplicitParamKind::OBJ_C_CMD;
    case 2: return ImplicitParamDeclImplicitParamKind::CXX_THIS;
    case 3: return ImplicitParamDeclImplicitParamKind::CXXVTT;
    case 4: return ImplicitParamDeclImplicitParamKind::CAPTURED_CONTEXT;
    case 5: return ImplicitParamDeclImplicitParamKind::OTHER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ImplicitParamDeclImplicitParamKind e) {
  switch (e) {
    case ImplicitParamDeclImplicitParamKind::OBJ_C_SELF: return "OBJ_C_SELF";
    case ImplicitParamDeclImplicitParamKind::OBJ_C_CMD: return "OBJ_C_CMD";
    case ImplicitParamDeclImplicitParamKind::CXX_THIS: return "CXX_THIS";
    case ImplicitParamDeclImplicitParamKind::CXXVTT: return "CXXVTT";
    case ImplicitParamDeclImplicitParamKind::CAPTURED_CONTEXT: return "CAPTURED_CONTEXT";
    case ImplicitParamDeclImplicitParamKind::OTHER: return "OTHER";
    default: return "<invalid>";
  }
}

LinkageSpecDeclLanguageIDs FromPasta(pasta::LinkageSpecDeclLanguageIDs e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return LinkageSpecDeclLanguageIDs::C;
    case 2: return LinkageSpecDeclLanguageIDs::CXX;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LinkageSpecDeclLanguageIDs e) {
  switch (e) {
    case LinkageSpecDeclLanguageIDs::C: return "C";
    case LinkageSpecDeclLanguageIDs::CXX: return "CXX";
    default: return "<invalid>";
  }
}

NamedDeclExplicitVisibilityKind FromPasta(pasta::NamedDeclExplicitVisibilityKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_TYPE;
    case 1: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_VALUE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NamedDeclExplicitVisibilityKind e) {
  switch (e) {
    case NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_TYPE: return "VISIBILITY_FOR_TYPE";
    case NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_VALUE: return "VISIBILITY_FOR_VALUE";
    default: return "<invalid>";
  }
}

OMPDeclareReductionDeclInitKind FromPasta(pasta::OMPDeclareReductionDeclInitKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OMPDeclareReductionDeclInitKind::CALL_INITIALIZER;
    case 1: return OMPDeclareReductionDeclInitKind::DIRECT_INITIALIZER;
    case 2: return OMPDeclareReductionDeclInitKind::COPY_INITIALIZER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OMPDeclareReductionDeclInitKind e) {
  switch (e) {
    case OMPDeclareReductionDeclInitKind::CALL_INITIALIZER: return "CALL_INITIALIZER";
    case OMPDeclareReductionDeclInitKind::DIRECT_INITIALIZER: return "DIRECT_INITIALIZER";
    case OMPDeclareReductionDeclInitKind::COPY_INITIALIZER: return "COPY_INITIALIZER";
    default: return "<invalid>";
  }
}

ObjCIvarDeclAccessControl FromPasta(pasta::ObjCIvarDeclAccessControl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCIvarDeclAccessControl::NONE;
    case 1: return ObjCIvarDeclAccessControl::PRIVATE;
    case 2: return ObjCIvarDeclAccessControl::PROTECTED;
    case 3: return ObjCIvarDeclAccessControl::PUBLIC;
    case 4: return ObjCIvarDeclAccessControl::PACKAGE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCIvarDeclAccessControl e) {
  switch (e) {
    case ObjCIvarDeclAccessControl::NONE: return "NONE";
    case ObjCIvarDeclAccessControl::PRIVATE: return "PRIVATE";
    case ObjCIvarDeclAccessControl::PROTECTED: return "PROTECTED";
    case ObjCIvarDeclAccessControl::PUBLIC: return "PUBLIC";
    case ObjCIvarDeclAccessControl::PACKAGE: return "PACKAGE";
    default: return "<invalid>";
  }
}

ObjCMessageExprReceiverKind FromPasta(pasta::ObjCMessageExprReceiverKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMessageExprReceiverKind::CLASS;
    case 1: return ObjCMessageExprReceiverKind::INSTANCE;
    case 2: return ObjCMessageExprReceiverKind::SUPER_CLASS;
    case 3: return ObjCMessageExprReceiverKind::SUPER_INSTANCE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCMessageExprReceiverKind e) {
  switch (e) {
    case ObjCMessageExprReceiverKind::CLASS: return "CLASS";
    case ObjCMessageExprReceiverKind::INSTANCE: return "INSTANCE";
    case ObjCMessageExprReceiverKind::SUPER_CLASS: return "SUPER_CLASS";
    case ObjCMessageExprReceiverKind::SUPER_INSTANCE: return "SUPER_INSTANCE";
    default: return "<invalid>";
  }
}

ObjCMethodDeclImplementationControl FromPasta(pasta::ObjCMethodDeclImplementationControl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMethodDeclImplementationControl::NONE;
    case 1: return ObjCMethodDeclImplementationControl::REQUIRED;
    case 2: return ObjCMethodDeclImplementationControl::OPTIONAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCMethodDeclImplementationControl e) {
  switch (e) {
    case ObjCMethodDeclImplementationControl::NONE: return "NONE";
    case ObjCMethodDeclImplementationControl::REQUIRED: return "REQUIRED";
    case ObjCMethodDeclImplementationControl::OPTIONAL: return "OPTIONAL";
    default: return "<invalid>";
  }
}

ObjCPropertyDeclPropertyControl FromPasta(pasta::ObjCPropertyDeclPropertyControl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyDeclPropertyControl::NONE;
    case 1: return ObjCPropertyDeclPropertyControl::REQUIRED;
    case 2: return ObjCPropertyDeclPropertyControl::OPTIONAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCPropertyDeclPropertyControl e) {
  switch (e) {
    case ObjCPropertyDeclPropertyControl::NONE: return "NONE";
    case ObjCPropertyDeclPropertyControl::REQUIRED: return "REQUIRED";
    case ObjCPropertyDeclPropertyControl::OPTIONAL: return "OPTIONAL";
    default: return "<invalid>";
  }
}

ObjCPropertyDeclSetterKind FromPasta(pasta::ObjCPropertyDeclSetterKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyDeclSetterKind::ASSIGN;
    case 1: return ObjCPropertyDeclSetterKind::RETAIN;
    case 2: return ObjCPropertyDeclSetterKind::COPY;
    case 3: return ObjCPropertyDeclSetterKind::WEAK;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCPropertyDeclSetterKind e) {
  switch (e) {
    case ObjCPropertyDeclSetterKind::ASSIGN: return "ASSIGN";
    case ObjCPropertyDeclSetterKind::RETAIN: return "RETAIN";
    case ObjCPropertyDeclSetterKind::COPY: return "COPY";
    case ObjCPropertyDeclSetterKind::WEAK: return "WEAK";
    default: return "<invalid>";
  }
}

ObjCPropertyImplDeclKind FromPasta(pasta::ObjCPropertyImplDeclKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyImplDeclKind::SYNTHESIZE;
    case 1: return ObjCPropertyImplDeclKind::DYNAMIC;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCPropertyImplDeclKind e) {
  switch (e) {
    case ObjCPropertyImplDeclKind::SYNTHESIZE: return "SYNTHESIZE";
    case ObjCPropertyImplDeclKind::DYNAMIC: return "DYNAMIC";
    default: return "<invalid>";
  }
}

PredefinedExprIdentKind FromPasta(pasta::PredefinedExprIdentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PredefinedExprIdentKind::FUNC;
    case 1: return PredefinedExprIdentKind::FUNCTION;
    case 2: return PredefinedExprIdentKind::L_FUNCTION;
    case 3: return PredefinedExprIdentKind::FUNC_D_NAME;
    case 4: return PredefinedExprIdentKind::FUNC_SIG;
    case 5: return PredefinedExprIdentKind::L_FUNC_SIG;
    case 6: return PredefinedExprIdentKind::PRETTY_FUNCTION;
    case 7: return PredefinedExprIdentKind::PRETTY_FUNCTION_NO_VIRTUAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PredefinedExprIdentKind e) {
  switch (e) {
    case PredefinedExprIdentKind::FUNC: return "FUNC";
    case PredefinedExprIdentKind::FUNCTION: return "FUNCTION";
    case PredefinedExprIdentKind::L_FUNCTION: return "L_FUNCTION";
    case PredefinedExprIdentKind::FUNC_D_NAME: return "FUNC_D_NAME";
    case PredefinedExprIdentKind::FUNC_SIG: return "FUNC_SIG";
    case PredefinedExprIdentKind::L_FUNC_SIG: return "L_FUNC_SIG";
    case PredefinedExprIdentKind::PRETTY_FUNCTION: return "PRETTY_FUNCTION";
    case PredefinedExprIdentKind::PRETTY_FUNCTION_NO_VIRTUAL: return "PRETTY_FUNCTION_NO_VIRTUAL";
    default: return "<invalid>";
  }
}

QualTypeDestructionKind FromPasta(pasta::QualTypeDestructionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return QualTypeDestructionKind::NONE;
    case 1: return QualTypeDestructionKind::CXX_DESTRUCTOR;
    case 2: return QualTypeDestructionKind::OBJC_STRONG_LIFETIME;
    case 3: return QualTypeDestructionKind::OBJC_WEAK_LIFETIME;
    case 4: return QualTypeDestructionKind::NONTRIVIAL_C_STRUCT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(QualTypeDestructionKind e) {
  switch (e) {
    case QualTypeDestructionKind::NONE: return "NONE";
    case QualTypeDestructionKind::CXX_DESTRUCTOR: return "CXX_DESTRUCTOR";
    case QualTypeDestructionKind::OBJC_STRONG_LIFETIME: return "OBJC_STRONG_LIFETIME";
    case QualTypeDestructionKind::OBJC_WEAK_LIFETIME: return "OBJC_WEAK_LIFETIME";
    case QualTypeDestructionKind::NONTRIVIAL_C_STRUCT: return "NONTRIVIAL_C_STRUCT";
    default: return "<invalid>";
  }
}

QualTypePrimitiveCopyKind FromPasta(pasta::QualTypePrimitiveCopyKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return QualTypePrimitiveCopyKind::TRIVIAL;
    case 1: return QualTypePrimitiveCopyKind::VOLATILE_TRIVIAL;
    case 2: return QualTypePrimitiveCopyKind::ARC_STRONG;
    case 3: return QualTypePrimitiveCopyKind::ARC_WEAK;
    case 4: return QualTypePrimitiveCopyKind::STRUCT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(QualTypePrimitiveCopyKind e) {
  switch (e) {
    case QualTypePrimitiveCopyKind::TRIVIAL: return "TRIVIAL";
    case QualTypePrimitiveCopyKind::VOLATILE_TRIVIAL: return "VOLATILE_TRIVIAL";
    case QualTypePrimitiveCopyKind::ARC_STRONG: return "ARC_STRONG";
    case QualTypePrimitiveCopyKind::ARC_WEAK: return "ARC_WEAK";
    case QualTypePrimitiveCopyKind::STRUCT: return "STRUCT";
    default: return "<invalid>";
  }
}

QualTypePrimitiveDefaultInitializeKind FromPasta(pasta::QualTypePrimitiveDefaultInitializeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return QualTypePrimitiveDefaultInitializeKind::TRIVIAL;
    case 1: return QualTypePrimitiveDefaultInitializeKind::ARC_STRONG;
    case 2: return QualTypePrimitiveDefaultInitializeKind::ARC_WEAK;
    case 3: return QualTypePrimitiveDefaultInitializeKind::STRUCT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(QualTypePrimitiveDefaultInitializeKind e) {
  switch (e) {
    case QualTypePrimitiveDefaultInitializeKind::TRIVIAL: return "TRIVIAL";
    case QualTypePrimitiveDefaultInitializeKind::ARC_STRONG: return "ARC_STRONG";
    case QualTypePrimitiveDefaultInitializeKind::ARC_WEAK: return "ARC_WEAK";
    case QualTypePrimitiveDefaultInitializeKind::STRUCT: return "STRUCT";
    default: return "<invalid>";
  }
}

RecordDeclArgPassingKind FromPasta(pasta::RecordDeclArgPassingKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RecordDeclArgPassingKind::CAN_PASS_IN_REGS;
    case 1: return RecordDeclArgPassingKind::CANNOT_PASS_IN_REGS;
    case 2: return RecordDeclArgPassingKind::CAN_NEVER_PASS_IN_REGS;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(RecordDeclArgPassingKind e) {
  switch (e) {
    case RecordDeclArgPassingKind::CAN_PASS_IN_REGS: return "CAN_PASS_IN_REGS";
    case RecordDeclArgPassingKind::CANNOT_PASS_IN_REGS: return "CANNOT_PASS_IN_REGS";
    case RecordDeclArgPassingKind::CAN_NEVER_PASS_IN_REGS: return "CAN_NEVER_PASS_IN_REGS";
    default: return "<invalid>";
  }
}

SourceLocExprIdentKind FromPasta(pasta::SourceLocExprIdentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SourceLocExprIdentKind::FUNCTION;
    case 1: return SourceLocExprIdentKind::FILE;
    case 2: return SourceLocExprIdentKind::LINE;
    case 3: return SourceLocExprIdentKind::COLUMN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SourceLocExprIdentKind e) {
  switch (e) {
    case SourceLocExprIdentKind::FUNCTION: return "FUNCTION";
    case SourceLocExprIdentKind::FILE: return "FILE";
    case SourceLocExprIdentKind::LINE: return "LINE";
    case SourceLocExprIdentKind::COLUMN: return "COLUMN";
    default: return "<invalid>";
  }
}

StmtLikelihood FromPasta(pasta::StmtLikelihood e) {
  switch (static_cast<int>(e)) {
    case -1: return StmtLikelihood::UNLIKELY;
    case 0: return StmtLikelihood::NONE;
    case 1: return StmtLikelihood::LIKELY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StmtLikelihood e) {
  switch (e) {
    case StmtLikelihood::UNLIKELY: return "UNLIKELY";
    case StmtLikelihood::NONE: return "NONE";
    case StmtLikelihood::LIKELY: return "LIKELY";
    default: return "<invalid>";
  }
}

StmtKind FromPasta(pasta::StmtKind e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return StmtKind::GCC_ASM_STMT;
    case 2: return StmtKind::MS_ASM_STMT;
    case 3: return StmtKind::BREAK_STMT;
    case 4: return StmtKind::CXX_CATCH_STMT;
    case 5: return StmtKind::CXX_FOR_RANGE_STMT;
    case 6: return StmtKind::CXX_TRY_STMT;
    case 7: return StmtKind::CAPTURED_STMT;
    case 8: return StmtKind::COMPOUND_STMT;
    case 9: return StmtKind::CONTINUE_STMT;
    case 10: return StmtKind::CORETURN_STMT;
    case 11: return StmtKind::COROUTINE_BODY_STMT;
    case 12: return StmtKind::DECL_STMT;
    case 13: return StmtKind::DO_STMT;
    case 14: return StmtKind::FOR_STMT;
    case 15: return StmtKind::GOTO_STMT;
    case 16: return StmtKind::IF_STMT;
    case 17: return StmtKind::INDIRECT_GOTO_STMT;
    case 18: return StmtKind::MS_DEPENDENT_EXISTS_STMT;
    case 19: return StmtKind::NULL_STMT;
    case 20: return StmtKind::OMP_CANONICAL_LOOP;
    case 21: return StmtKind::OMP_ATOMIC_DIRECTIVE;
    case 22: return StmtKind::OMP_BARRIER_DIRECTIVE;
    case 23: return StmtKind::OMP_CANCEL_DIRECTIVE;
    case 24: return StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE;
    case 25: return StmtKind::OMP_CRITICAL_DIRECTIVE;
    case 26: return StmtKind::OMP_DEPOBJ_DIRECTIVE;
    case 27: return StmtKind::OMP_DISPATCH_DIRECTIVE;
    case 28: return StmtKind::OMP_FLUSH_DIRECTIVE;
    case 29: return StmtKind::OMP_INTEROP_DIRECTIVE;
    case 30: return StmtKind::OMP_DISTRIBUTE_DIRECTIVE;
    case 31: return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case 32: return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 33: return StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE;
    case 34: return StmtKind::OMP_FOR_DIRECTIVE;
    case 35: return StmtKind::OMP_FOR_SIMD_DIRECTIVE;
    case 36: return StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE;
    case 37: return StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
    case 38: return StmtKind::OMP_PARALLEL_FOR_DIRECTIVE;
    case 39: return StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 40: return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE;
    case 41: return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
    case 42: return StmtKind::OMP_SIMD_DIRECTIVE;
    case 43: return StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 44: return StmtKind::OMP_TARGET_SIMD_DIRECTIVE;
    case 45: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE;
    case 46: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case 47: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 48: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE;
    case 49: return StmtKind::OMP_TASK_LOOP_DIRECTIVE;
    case 50: return StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE;
    case 51: return StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE;
    case 52: return StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case 53: return StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case 54: return StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE;
    case 55: return StmtKind::OMP_TILE_DIRECTIVE;
    case 56: return StmtKind::OMP_UNROLL_DIRECTIVE;
    case 57: return StmtKind::OMP_MASKED_DIRECTIVE;
    case 58: return StmtKind::OMP_MASTER_DIRECTIVE;
    case 59: return StmtKind::OMP_ORDERED_DIRECTIVE;
    case 60: return StmtKind::OMP_PARALLEL_DIRECTIVE;
    case 61: return StmtKind::OMP_PARALLEL_MASTER_DIRECTIVE;
    case 62: return StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE;
    case 63: return StmtKind::OMP_SCAN_DIRECTIVE;
    case 64: return StmtKind::OMP_SECTION_DIRECTIVE;
    case 65: return StmtKind::OMP_SECTIONS_DIRECTIVE;
    case 66: return StmtKind::OMP_SINGLE_DIRECTIVE;
    case 67: return StmtKind::OMP_TARGET_DATA_DIRECTIVE;
    case 68: return StmtKind::OMP_TARGET_DIRECTIVE;
    case 69: return StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE;
    case 70: return StmtKind::OMP_TARGET_EXIT_DATA_DIRECTIVE;
    case 71: return StmtKind::OMP_TARGET_PARALLEL_DIRECTIVE;
    case 72: return StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE;
    case 73: return StmtKind::OMP_TARGET_TEAMS_DIRECTIVE;
    case 74: return StmtKind::OMP_TARGET_UPDATE_DIRECTIVE;
    case 75: return StmtKind::OMP_TASK_DIRECTIVE;
    case 76: return StmtKind::OMP_TASKGROUP_DIRECTIVE;
    case 77: return StmtKind::OMP_TASKWAIT_DIRECTIVE;
    case 78: return StmtKind::OMP_TASKYIELD_DIRECTIVE;
    case 79: return StmtKind::OMP_TEAMS_DIRECTIVE;
    case 80: return StmtKind::OBJ_C_AT_CATCH_STMT;
    case 81: return StmtKind::OBJ_C_AT_FINALLY_STMT;
    case 82: return StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT;
    case 83: return StmtKind::OBJ_C_AT_THROW_STMT;
    case 84: return StmtKind::OBJ_C_AT_TRY_STMT;
    case 85: return StmtKind::OBJ_C_AUTORELEASE_POOL_STMT;
    case 86: return StmtKind::OBJ_C_FOR_COLLECTION_STMT;
    case 87: return StmtKind::RETURN_STMT;
    case 88: return StmtKind::SEH_EXCEPT_STMT;
    case 89: return StmtKind::SEH_FINALLY_STMT;
    case 90: return StmtKind::SEH_LEAVE_STMT;
    case 91: return StmtKind::SEH_TRY_STMT;
    case 92: return StmtKind::CASE_STMT;
    case 93: return StmtKind::DEFAULT_STMT;
    case 94: return StmtKind::SWITCH_STMT;
    case 95: return StmtKind::ATTRIBUTED_STMT;
    case 96: return StmtKind::BINARY_CONDITIONAL_OPERATOR;
    case 97: return StmtKind::CONDITIONAL_OPERATOR;
    case 98: return StmtKind::ADDR_LABEL_EXPR;
    case 99: return StmtKind::ARRAY_INIT_INDEX_EXPR;
    case 100: return StmtKind::ARRAY_INIT_LOOP_EXPR;
    case 101: return StmtKind::ARRAY_SUBSCRIPT_EXPR;
    case 102: return StmtKind::ARRAY_TYPE_TRAIT_EXPR;
    case 103: return StmtKind::AS_TYPE_EXPR;
    case 104: return StmtKind::ATOMIC_EXPR;
    case 105: return StmtKind::BINARY_OPERATOR;
    case 106: return StmtKind::COMPOUND_ASSIGN_OPERATOR;
    case 107: return StmtKind::BLOCK_EXPR;
    case 108: return StmtKind::CXX_BIND_TEMPORARY_EXPR;
    case 109: return StmtKind::CXX_BOOL_LITERAL_EXPR;
    case 110: return StmtKind::CXX_CONSTRUCT_EXPR;
    case 111: return StmtKind::CXX_TEMPORARY_OBJECT_EXPR;
    case 112: return StmtKind::CXX_DEFAULT_ARG_EXPR;
    case 113: return StmtKind::CXX_DEFAULT_INIT_EXPR;
    case 114: return StmtKind::CXX_DELETE_EXPR;
    case 115: return StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR;
    case 116: return StmtKind::CXX_FOLD_EXPR;
    case 117: return StmtKind::CXX_INHERITED_CTOR_INIT_EXPR;
    case 118: return StmtKind::CXX_NEW_EXPR;
    case 119: return StmtKind::CXX_NOEXCEPT_EXPR;
    case 120: return StmtKind::CXX_NULL_PTR_LITERAL_EXPR;
    case 121: return StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR;
    case 122: return StmtKind::CXX_REWRITTEN_BINARY_OPERATOR;
    case 123: return StmtKind::CXX_SCALAR_VALUE_INIT_EXPR;
    case 124: return StmtKind::CXX_STD_INITIALIZER_LIST_EXPR;
    case 125: return StmtKind::CXX_THIS_EXPR;
    case 126: return StmtKind::CXX_THROW_EXPR;
    case 127: return StmtKind::CXX_TYPEID_EXPR;
    case 128: return StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR;
    case 129: return StmtKind::CXX_UUIDOF_EXPR;
    case 130: return StmtKind::CALL_EXPR;
    case 131: return StmtKind::CUDA_KERNEL_CALL_EXPR;
    case 132: return StmtKind::CXX_MEMBER_CALL_EXPR;
    case 133: return StmtKind::CXX_OPERATOR_CALL_EXPR;
    case 134: return StmtKind::USER_DEFINED_LITERAL;
    case 135: return StmtKind::BUILTIN_BIT_CAST_EXPR;
    case 136: return StmtKind::C_STYLE_CAST_EXPR;
    case 137: return StmtKind::CXX_FUNCTIONAL_CAST_EXPR;
    case 138: return StmtKind::CXX_ADDRSPACE_CAST_EXPR;
    case 139: return StmtKind::CXX_CONST_CAST_EXPR;
    case 140: return StmtKind::CXX_DYNAMIC_CAST_EXPR;
    case 141: return StmtKind::CXX_REINTERPRET_CAST_EXPR;
    case 142: return StmtKind::CXX_STATIC_CAST_EXPR;
    case 143: return StmtKind::OBJ_C_BRIDGED_CAST_EXPR;
    case 144: return StmtKind::IMPLICIT_CAST_EXPR;
    case 145: return StmtKind::CHARACTER_LITERAL;
    case 146: return StmtKind::CHOOSE_EXPR;
    case 147: return StmtKind::COMPOUND_LITERAL_EXPR;
    case 148: return StmtKind::CONCEPT_SPECIALIZATION_EXPR;
    case 149: return StmtKind::CONVERT_VECTOR_EXPR;
    case 150: return StmtKind::COAWAIT_EXPR;
    case 151: return StmtKind::COYIELD_EXPR;
    case 152: return StmtKind::DECL_REF_EXPR;
    case 153: return StmtKind::DEPENDENT_COAWAIT_EXPR;
    case 154: return StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR;
    case 155: return StmtKind::DESIGNATED_INIT_EXPR;
    case 156: return StmtKind::DESIGNATED_INIT_UPDATE_EXPR;
    case 157: return StmtKind::EXPRESSION_TRAIT_EXPR;
    case 158: return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
    case 159: return StmtKind::FIXED_POINT_LITERAL;
    case 160: return StmtKind::FLOATING_LITERAL;
    case 161: return StmtKind::CONSTANT_EXPR;
    case 162: return StmtKind::EXPR_WITH_CLEANUPS;
    case 163: return StmtKind::FUNCTION_PARM_PACK_EXPR;
    case 164: return StmtKind::GNU_NULL_EXPR;
    case 165: return StmtKind::GENERIC_SELECTION_EXPR;
    case 166: return StmtKind::IMAGINARY_LITERAL;
    case 167: return StmtKind::IMPLICIT_VALUE_INIT_EXPR;
    case 168: return StmtKind::INIT_LIST_EXPR;
    case 169: return StmtKind::INTEGER_LITERAL;
    case 170: return StmtKind::LAMBDA_EXPR;
    case 171: return StmtKind::MS_PROPERTY_REF_EXPR;
    case 172: return StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR;
    case 173: return StmtKind::MATERIALIZE_TEMPORARY_EXPR;
    case 174: return StmtKind::MATRIX_SUBSCRIPT_EXPR;
    case 175: return StmtKind::MEMBER_EXPR;
    case 176: return StmtKind::NO_INIT_EXPR;
    case 177: return StmtKind::OMP_ARRAY_SECTION_EXPR;
    case 178: return StmtKind::OMP_ARRAY_SHAPING_EXPR;
    case 179: return StmtKind::OMP_ITERATOR_EXPR;
    case 180: return StmtKind::OBJ_C_ARRAY_LITERAL;
    case 181: return StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR;
    case 182: return StmtKind::OBJ_C_BOOL_LITERAL_EXPR;
    case 183: return StmtKind::OBJ_C_BOXED_EXPR;
    case 184: return StmtKind::OBJ_C_DICTIONARY_LITERAL;
    case 185: return StmtKind::OBJ_C_ENCODE_EXPR;
    case 186: return StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR;
    case 187: return StmtKind::OBJ_C_ISA_EXPR;
    case 188: return StmtKind::OBJ_C_IVAR_REF_EXPR;
    case 189: return StmtKind::OBJ_C_MESSAGE_EXPR;
    case 190: return StmtKind::OBJ_C_PROPERTY_REF_EXPR;
    case 191: return StmtKind::OBJ_C_PROTOCOL_EXPR;
    case 192: return StmtKind::OBJ_C_SELECTOR_EXPR;
    case 193: return StmtKind::OBJ_C_STRING_LITERAL;
    case 194: return StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR;
    case 195: return StmtKind::OFFSET_OF_EXPR;
    case 196: return StmtKind::OPAQUE_VALUE_EXPR;
    case 197: return StmtKind::UNRESOLVED_LOOKUP_EXPR;
    case 198: return StmtKind::UNRESOLVED_MEMBER_EXPR;
    case 199: return StmtKind::PACK_EXPANSION_EXPR;
    case 200: return StmtKind::PAREN_EXPR;
    case 201: return StmtKind::PAREN_LIST_EXPR;
    case 202: return StmtKind::PREDEFINED_EXPR;
    case 203: return StmtKind::PSEUDO_OBJECT_EXPR;
    case 204: return StmtKind::RECOVERY_EXPR;
    case 205: return StmtKind::REQUIRES_EXPR;
    case 206: return StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR;
    case 207: return StmtKind::SHUFFLE_VECTOR_EXPR;
    case 208: return StmtKind::SIZE_OF_PACK_EXPR;
    case 209: return StmtKind::SOURCE_LOC_EXPR;
    case 210: return StmtKind::STMT_EXPR;
    case 211: return StmtKind::STRING_LITERAL;
    case 212: return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR;
    case 213: return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR;
    case 214: return StmtKind::TYPE_TRAIT_EXPR;
    case 215: return StmtKind::TYPO_EXPR;
    case 216: return StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR;
    case 217: return StmtKind::UNARY_OPERATOR;
    case 218: return StmtKind::VA_ARG_EXPR;
    case 219: return StmtKind::LABEL_STMT;
    case 220: return StmtKind::WHILE_STMT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StmtKind e) {
  switch (e) {
    case StmtKind::GCC_ASM_STMT: return "GCC_ASM_STMT";
    case StmtKind::MS_ASM_STMT: return "MS_ASM_STMT";
    case StmtKind::BREAK_STMT: return "BREAK_STMT";
    case StmtKind::CXX_CATCH_STMT: return "CXX_CATCH_STMT";
    case StmtKind::CXX_FOR_RANGE_STMT: return "CXX_FOR_RANGE_STMT";
    case StmtKind::CXX_TRY_STMT: return "CXX_TRY_STMT";
    case StmtKind::CAPTURED_STMT: return "CAPTURED_STMT";
    case StmtKind::COMPOUND_STMT: return "COMPOUND_STMT";
    case StmtKind::CONTINUE_STMT: return "CONTINUE_STMT";
    case StmtKind::CORETURN_STMT: return "CORETURN_STMT";
    case StmtKind::COROUTINE_BODY_STMT: return "COROUTINE_BODY_STMT";
    case StmtKind::DECL_STMT: return "DECL_STMT";
    case StmtKind::DO_STMT: return "DO_STMT";
    case StmtKind::FOR_STMT: return "FOR_STMT";
    case StmtKind::GOTO_STMT: return "GOTO_STMT";
    case StmtKind::IF_STMT: return "IF_STMT";
    case StmtKind::INDIRECT_GOTO_STMT: return "INDIRECT_GOTO_STMT";
    case StmtKind::MS_DEPENDENT_EXISTS_STMT: return "MS_DEPENDENT_EXISTS_STMT";
    case StmtKind::NULL_STMT: return "NULL_STMT";
    case StmtKind::OMP_CANONICAL_LOOP: return "OMP_CANONICAL_LOOP";
    case StmtKind::OMP_ATOMIC_DIRECTIVE: return "OMP_ATOMIC_DIRECTIVE";
    case StmtKind::OMP_BARRIER_DIRECTIVE: return "OMP_BARRIER_DIRECTIVE";
    case StmtKind::OMP_CANCEL_DIRECTIVE: return "OMP_CANCEL_DIRECTIVE";
    case StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE: return "OMP_CANCELLATION_POINT_DIRECTIVE";
    case StmtKind::OMP_CRITICAL_DIRECTIVE: return "OMP_CRITICAL_DIRECTIVE";
    case StmtKind::OMP_DEPOBJ_DIRECTIVE: return "OMP_DEPOBJ_DIRECTIVE";
    case StmtKind::OMP_DISPATCH_DIRECTIVE: return "OMP_DISPATCH_DIRECTIVE";
    case StmtKind::OMP_FLUSH_DIRECTIVE: return "OMP_FLUSH_DIRECTIVE";
    case StmtKind::OMP_INTEROP_DIRECTIVE: return "OMP_INTEROP_DIRECTIVE";
    case StmtKind::OMP_DISTRIBUTE_DIRECTIVE: return "OMP_DISTRIBUTE_DIRECTIVE";
    case StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE: return "OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE";
    case StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE: return "OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE";
    case StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE: return "OMP_DISTRIBUTE_SIMD_DIRECTIVE";
    case StmtKind::OMP_FOR_DIRECTIVE: return "OMP_FOR_DIRECTIVE";
    case StmtKind::OMP_FOR_SIMD_DIRECTIVE: return "OMP_FOR_SIMD_DIRECTIVE";
    case StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE: return "OMP_MASTER_TASK_LOOP_DIRECTIVE";
    case StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE: return "OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE";
    case StmtKind::OMP_PARALLEL_FOR_DIRECTIVE: return "OMP_PARALLEL_FOR_DIRECTIVE";
    case StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE: return "OMP_PARALLEL_FOR_SIMD_DIRECTIVE";
    case StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE: return "OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE";
    case StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE: return "OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE";
    case StmtKind::OMP_SIMD_DIRECTIVE: return "OMP_SIMD_DIRECTIVE";
    case StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE: return "OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE";
    case StmtKind::OMP_TARGET_SIMD_DIRECTIVE: return "OMP_TARGET_SIMD_DIRECTIVE";
    case StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE: return "OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE";
    case StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE: return "OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE";
    case StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE: return "OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE";
    case StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE: return "OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE";
    case StmtKind::OMP_TASK_LOOP_DIRECTIVE: return "OMP_TASK_LOOP_DIRECTIVE";
    case StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE: return "OMP_TASK_LOOP_SIMD_DIRECTIVE";
    case StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE: return "OMP_TEAMS_DISTRIBUTE_DIRECTIVE";
    case StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE: return "OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE";
    case StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE: return "OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE";
    case StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE: return "OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE";
    case StmtKind::OMP_TILE_DIRECTIVE: return "OMP_TILE_DIRECTIVE";
    case StmtKind::OMP_UNROLL_DIRECTIVE: return "OMP_UNROLL_DIRECTIVE";
    case StmtKind::OMP_MASKED_DIRECTIVE: return "OMP_MASKED_DIRECTIVE";
    case StmtKind::OMP_MASTER_DIRECTIVE: return "OMP_MASTER_DIRECTIVE";
    case StmtKind::OMP_ORDERED_DIRECTIVE: return "OMP_ORDERED_DIRECTIVE";
    case StmtKind::OMP_PARALLEL_DIRECTIVE: return "OMP_PARALLEL_DIRECTIVE";
    case StmtKind::OMP_PARALLEL_MASTER_DIRECTIVE: return "OMP_PARALLEL_MASTER_DIRECTIVE";
    case StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE: return "OMP_PARALLEL_SECTIONS_DIRECTIVE";
    case StmtKind::OMP_SCAN_DIRECTIVE: return "OMP_SCAN_DIRECTIVE";
    case StmtKind::OMP_SECTION_DIRECTIVE: return "OMP_SECTION_DIRECTIVE";
    case StmtKind::OMP_SECTIONS_DIRECTIVE: return "OMP_SECTIONS_DIRECTIVE";
    case StmtKind::OMP_SINGLE_DIRECTIVE: return "OMP_SINGLE_DIRECTIVE";
    case StmtKind::OMP_TARGET_DATA_DIRECTIVE: return "OMP_TARGET_DATA_DIRECTIVE";
    case StmtKind::OMP_TARGET_DIRECTIVE: return "OMP_TARGET_DIRECTIVE";
    case StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE: return "OMP_TARGET_ENTER_DATA_DIRECTIVE";
    case StmtKind::OMP_TARGET_EXIT_DATA_DIRECTIVE: return "OMP_TARGET_EXIT_DATA_DIRECTIVE";
    case StmtKind::OMP_TARGET_PARALLEL_DIRECTIVE: return "OMP_TARGET_PARALLEL_DIRECTIVE";
    case StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE: return "OMP_TARGET_PARALLEL_FOR_DIRECTIVE";
    case StmtKind::OMP_TARGET_TEAMS_DIRECTIVE: return "OMP_TARGET_TEAMS_DIRECTIVE";
    case StmtKind::OMP_TARGET_UPDATE_DIRECTIVE: return "OMP_TARGET_UPDATE_DIRECTIVE";
    case StmtKind::OMP_TASK_DIRECTIVE: return "OMP_TASK_DIRECTIVE";
    case StmtKind::OMP_TASKGROUP_DIRECTIVE: return "OMP_TASKGROUP_DIRECTIVE";
    case StmtKind::OMP_TASKWAIT_DIRECTIVE: return "OMP_TASKWAIT_DIRECTIVE";
    case StmtKind::OMP_TASKYIELD_DIRECTIVE: return "OMP_TASKYIELD_DIRECTIVE";
    case StmtKind::OMP_TEAMS_DIRECTIVE: return "OMP_TEAMS_DIRECTIVE";
    case StmtKind::OBJ_C_AT_CATCH_STMT: return "OBJ_C_AT_CATCH_STMT";
    case StmtKind::OBJ_C_AT_FINALLY_STMT: return "OBJ_C_AT_FINALLY_STMT";
    case StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT: return "OBJ_C_AT_SYNCHRONIZED_STMT";
    case StmtKind::OBJ_C_AT_THROW_STMT: return "OBJ_C_AT_THROW_STMT";
    case StmtKind::OBJ_C_AT_TRY_STMT: return "OBJ_C_AT_TRY_STMT";
    case StmtKind::OBJ_C_AUTORELEASE_POOL_STMT: return "OBJ_C_AUTORELEASE_POOL_STMT";
    case StmtKind::OBJ_C_FOR_COLLECTION_STMT: return "OBJ_C_FOR_COLLECTION_STMT";
    case StmtKind::RETURN_STMT: return "RETURN_STMT";
    case StmtKind::SEH_EXCEPT_STMT: return "SEH_EXCEPT_STMT";
    case StmtKind::SEH_FINALLY_STMT: return "SEH_FINALLY_STMT";
    case StmtKind::SEH_LEAVE_STMT: return "SEH_LEAVE_STMT";
    case StmtKind::SEH_TRY_STMT: return "SEH_TRY_STMT";
    case StmtKind::CASE_STMT: return "CASE_STMT";
    case StmtKind::DEFAULT_STMT: return "DEFAULT_STMT";
    case StmtKind::SWITCH_STMT: return "SWITCH_STMT";
    case StmtKind::ATTRIBUTED_STMT: return "ATTRIBUTED_STMT";
    case StmtKind::BINARY_CONDITIONAL_OPERATOR: return "BINARY_CONDITIONAL_OPERATOR";
    case StmtKind::CONDITIONAL_OPERATOR: return "CONDITIONAL_OPERATOR";
    case StmtKind::ADDR_LABEL_EXPR: return "ADDR_LABEL_EXPR";
    case StmtKind::ARRAY_INIT_INDEX_EXPR: return "ARRAY_INIT_INDEX_EXPR";
    case StmtKind::ARRAY_INIT_LOOP_EXPR: return "ARRAY_INIT_LOOP_EXPR";
    case StmtKind::ARRAY_SUBSCRIPT_EXPR: return "ARRAY_SUBSCRIPT_EXPR";
    case StmtKind::ARRAY_TYPE_TRAIT_EXPR: return "ARRAY_TYPE_TRAIT_EXPR";
    case StmtKind::AS_TYPE_EXPR: return "AS_TYPE_EXPR";
    case StmtKind::ATOMIC_EXPR: return "ATOMIC_EXPR";
    case StmtKind::BINARY_OPERATOR: return "BINARY_OPERATOR";
    case StmtKind::COMPOUND_ASSIGN_OPERATOR: return "COMPOUND_ASSIGN_OPERATOR";
    case StmtKind::BLOCK_EXPR: return "BLOCK_EXPR";
    case StmtKind::CXX_BIND_TEMPORARY_EXPR: return "CXX_BIND_TEMPORARY_EXPR";
    case StmtKind::CXX_BOOL_LITERAL_EXPR: return "CXX_BOOL_LITERAL_EXPR";
    case StmtKind::CXX_CONSTRUCT_EXPR: return "CXX_CONSTRUCT_EXPR";
    case StmtKind::CXX_TEMPORARY_OBJECT_EXPR: return "CXX_TEMPORARY_OBJECT_EXPR";
    case StmtKind::CXX_DEFAULT_ARG_EXPR: return "CXX_DEFAULT_ARG_EXPR";
    case StmtKind::CXX_DEFAULT_INIT_EXPR: return "CXX_DEFAULT_INIT_EXPR";
    case StmtKind::CXX_DELETE_EXPR: return "CXX_DELETE_EXPR";
    case StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR: return "CXX_DEPENDENT_SCOPE_MEMBER_EXPR";
    case StmtKind::CXX_FOLD_EXPR: return "CXX_FOLD_EXPR";
    case StmtKind::CXX_INHERITED_CTOR_INIT_EXPR: return "CXX_INHERITED_CTOR_INIT_EXPR";
    case StmtKind::CXX_NEW_EXPR: return "CXX_NEW_EXPR";
    case StmtKind::CXX_NOEXCEPT_EXPR: return "CXX_NOEXCEPT_EXPR";
    case StmtKind::CXX_NULL_PTR_LITERAL_EXPR: return "CXX_NULL_PTR_LITERAL_EXPR";
    case StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR: return "CXX_PSEUDO_DESTRUCTOR_EXPR";
    case StmtKind::CXX_REWRITTEN_BINARY_OPERATOR: return "CXX_REWRITTEN_BINARY_OPERATOR";
    case StmtKind::CXX_SCALAR_VALUE_INIT_EXPR: return "CXX_SCALAR_VALUE_INIT_EXPR";
    case StmtKind::CXX_STD_INITIALIZER_LIST_EXPR: return "CXX_STD_INITIALIZER_LIST_EXPR";
    case StmtKind::CXX_THIS_EXPR: return "CXX_THIS_EXPR";
    case StmtKind::CXX_THROW_EXPR: return "CXX_THROW_EXPR";
    case StmtKind::CXX_TYPEID_EXPR: return "CXX_TYPEID_EXPR";
    case StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR: return "CXX_UNRESOLVED_CONSTRUCT_EXPR";
    case StmtKind::CXX_UUIDOF_EXPR: return "CXX_UUIDOF_EXPR";
    case StmtKind::CALL_EXPR: return "CALL_EXPR";
    case StmtKind::CUDA_KERNEL_CALL_EXPR: return "CUDA_KERNEL_CALL_EXPR";
    case StmtKind::CXX_MEMBER_CALL_EXPR: return "CXX_MEMBER_CALL_EXPR";
    case StmtKind::CXX_OPERATOR_CALL_EXPR: return "CXX_OPERATOR_CALL_EXPR";
    case StmtKind::USER_DEFINED_LITERAL: return "USER_DEFINED_LITERAL";
    case StmtKind::BUILTIN_BIT_CAST_EXPR: return "BUILTIN_BIT_CAST_EXPR";
    case StmtKind::C_STYLE_CAST_EXPR: return "C_STYLE_CAST_EXPR";
    case StmtKind::CXX_FUNCTIONAL_CAST_EXPR: return "CXX_FUNCTIONAL_CAST_EXPR";
    case StmtKind::CXX_ADDRSPACE_CAST_EXPR: return "CXX_ADDRSPACE_CAST_EXPR";
    case StmtKind::CXX_CONST_CAST_EXPR: return "CXX_CONST_CAST_EXPR";
    case StmtKind::CXX_DYNAMIC_CAST_EXPR: return "CXX_DYNAMIC_CAST_EXPR";
    case StmtKind::CXX_REINTERPRET_CAST_EXPR: return "CXX_REINTERPRET_CAST_EXPR";
    case StmtKind::CXX_STATIC_CAST_EXPR: return "CXX_STATIC_CAST_EXPR";
    case StmtKind::OBJ_C_BRIDGED_CAST_EXPR: return "OBJ_C_BRIDGED_CAST_EXPR";
    case StmtKind::IMPLICIT_CAST_EXPR: return "IMPLICIT_CAST_EXPR";
    case StmtKind::CHARACTER_LITERAL: return "CHARACTER_LITERAL";
    case StmtKind::CHOOSE_EXPR: return "CHOOSE_EXPR";
    case StmtKind::COMPOUND_LITERAL_EXPR: return "COMPOUND_LITERAL_EXPR";
    case StmtKind::CONCEPT_SPECIALIZATION_EXPR: return "CONCEPT_SPECIALIZATION_EXPR";
    case StmtKind::CONVERT_VECTOR_EXPR: return "CONVERT_VECTOR_EXPR";
    case StmtKind::COAWAIT_EXPR: return "COAWAIT_EXPR";
    case StmtKind::COYIELD_EXPR: return "COYIELD_EXPR";
    case StmtKind::DECL_REF_EXPR: return "DECL_REF_EXPR";
    case StmtKind::DEPENDENT_COAWAIT_EXPR: return "DEPENDENT_COAWAIT_EXPR";
    case StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR: return "DEPENDENT_SCOPE_DECL_REF_EXPR";
    case StmtKind::DESIGNATED_INIT_EXPR: return "DESIGNATED_INIT_EXPR";
    case StmtKind::DESIGNATED_INIT_UPDATE_EXPR: return "DESIGNATED_INIT_UPDATE_EXPR";
    case StmtKind::EXPRESSION_TRAIT_EXPR: return "EXPRESSION_TRAIT_EXPR";
    case StmtKind::EXT_VECTOR_ELEMENT_EXPR: return "EXT_VECTOR_ELEMENT_EXPR";
    case StmtKind::FIXED_POINT_LITERAL: return "FIXED_POINT_LITERAL";
    case StmtKind::FLOATING_LITERAL: return "FLOATING_LITERAL";
    case StmtKind::CONSTANT_EXPR: return "CONSTANT_EXPR";
    case StmtKind::EXPR_WITH_CLEANUPS: return "EXPR_WITH_CLEANUPS";
    case StmtKind::FUNCTION_PARM_PACK_EXPR: return "FUNCTION_PARM_PACK_EXPR";
    case StmtKind::GNU_NULL_EXPR: return "GNU_NULL_EXPR";
    case StmtKind::GENERIC_SELECTION_EXPR: return "GENERIC_SELECTION_EXPR";
    case StmtKind::IMAGINARY_LITERAL: return "IMAGINARY_LITERAL";
    case StmtKind::IMPLICIT_VALUE_INIT_EXPR: return "IMPLICIT_VALUE_INIT_EXPR";
    case StmtKind::INIT_LIST_EXPR: return "INIT_LIST_EXPR";
    case StmtKind::INTEGER_LITERAL: return "INTEGER_LITERAL";
    case StmtKind::LAMBDA_EXPR: return "LAMBDA_EXPR";
    case StmtKind::MS_PROPERTY_REF_EXPR: return "MS_PROPERTY_REF_EXPR";
    case StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR: return "MS_PROPERTY_SUBSCRIPT_EXPR";
    case StmtKind::MATERIALIZE_TEMPORARY_EXPR: return "MATERIALIZE_TEMPORARY_EXPR";
    case StmtKind::MATRIX_SUBSCRIPT_EXPR: return "MATRIX_SUBSCRIPT_EXPR";
    case StmtKind::MEMBER_EXPR: return "MEMBER_EXPR";
    case StmtKind::NO_INIT_EXPR: return "NO_INIT_EXPR";
    case StmtKind::OMP_ARRAY_SECTION_EXPR: return "OMP_ARRAY_SECTION_EXPR";
    case StmtKind::OMP_ARRAY_SHAPING_EXPR: return "OMP_ARRAY_SHAPING_EXPR";
    case StmtKind::OMP_ITERATOR_EXPR: return "OMP_ITERATOR_EXPR";
    case StmtKind::OBJ_C_ARRAY_LITERAL: return "OBJ_C_ARRAY_LITERAL";
    case StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR: return "OBJ_C_AVAILABILITY_CHECK_EXPR";
    case StmtKind::OBJ_C_BOOL_LITERAL_EXPR: return "OBJ_C_BOOL_LITERAL_EXPR";
    case StmtKind::OBJ_C_BOXED_EXPR: return "OBJ_C_BOXED_EXPR";
    case StmtKind::OBJ_C_DICTIONARY_LITERAL: return "OBJ_C_DICTIONARY_LITERAL";
    case StmtKind::OBJ_C_ENCODE_EXPR: return "OBJ_C_ENCODE_EXPR";
    case StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR: return "OBJ_C_INDIRECT_COPY_RESTORE_EXPR";
    case StmtKind::OBJ_C_ISA_EXPR: return "OBJ_C_ISA_EXPR";
    case StmtKind::OBJ_C_IVAR_REF_EXPR: return "OBJ_C_IVAR_REF_EXPR";
    case StmtKind::OBJ_C_MESSAGE_EXPR: return "OBJ_C_MESSAGE_EXPR";
    case StmtKind::OBJ_C_PROPERTY_REF_EXPR: return "OBJ_C_PROPERTY_REF_EXPR";
    case StmtKind::OBJ_C_PROTOCOL_EXPR: return "OBJ_C_PROTOCOL_EXPR";
    case StmtKind::OBJ_C_SELECTOR_EXPR: return "OBJ_C_SELECTOR_EXPR";
    case StmtKind::OBJ_C_STRING_LITERAL: return "OBJ_C_STRING_LITERAL";
    case StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR: return "OBJ_C_SUBSCRIPT_REF_EXPR";
    case StmtKind::OFFSET_OF_EXPR: return "OFFSET_OF_EXPR";
    case StmtKind::OPAQUE_VALUE_EXPR: return "OPAQUE_VALUE_EXPR";
    case StmtKind::UNRESOLVED_LOOKUP_EXPR: return "UNRESOLVED_LOOKUP_EXPR";
    case StmtKind::UNRESOLVED_MEMBER_EXPR: return "UNRESOLVED_MEMBER_EXPR";
    case StmtKind::PACK_EXPANSION_EXPR: return "PACK_EXPANSION_EXPR";
    case StmtKind::PAREN_EXPR: return "PAREN_EXPR";
    case StmtKind::PAREN_LIST_EXPR: return "PAREN_LIST_EXPR";
    case StmtKind::PREDEFINED_EXPR: return "PREDEFINED_EXPR";
    case StmtKind::PSEUDO_OBJECT_EXPR: return "PSEUDO_OBJECT_EXPR";
    case StmtKind::RECOVERY_EXPR: return "RECOVERY_EXPR";
    case StmtKind::REQUIRES_EXPR: return "REQUIRES_EXPR";
    case StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR: return "SYCL_UNIQUE_STABLE_NAME_EXPR";
    case StmtKind::SHUFFLE_VECTOR_EXPR: return "SHUFFLE_VECTOR_EXPR";
    case StmtKind::SIZE_OF_PACK_EXPR: return "SIZE_OF_PACK_EXPR";
    case StmtKind::SOURCE_LOC_EXPR: return "SOURCE_LOC_EXPR";
    case StmtKind::STMT_EXPR: return "STMT_EXPR";
    case StmtKind::STRING_LITERAL: return "STRING_LITERAL";
    case StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR: return "SUBST_NON_TYPE_TEMPLATE_PARM_EXPR";
    case StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR: return "SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR";
    case StmtKind::TYPE_TRAIT_EXPR: return "TYPE_TRAIT_EXPR";
    case StmtKind::TYPO_EXPR: return "TYPO_EXPR";
    case StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR: return "UNARY_EXPR_OR_TYPE_TRAIT_EXPR";
    case StmtKind::UNARY_OPERATOR: return "UNARY_OPERATOR";
    case StmtKind::VA_ARG_EXPR: return "VA_ARG_EXPR";
    case StmtKind::LABEL_STMT: return "LABEL_STMT";
    case StmtKind::WHILE_STMT: return "WHILE_STMT";
    default: return "<invalid>";
  }
}

StringLiteralStringKind FromPasta(pasta::StringLiteralStringKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StringLiteralStringKind::ASCII;
    case 1: return StringLiteralStringKind::WIDE;
    case 2: return StringLiteralStringKind::UTF8;
    case 3: return StringLiteralStringKind::UTF16;
    case 4: return StringLiteralStringKind::UTF32;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StringLiteralStringKind e) {
  switch (e) {
    case StringLiteralStringKind::ASCII: return "ASCII";
    case StringLiteralStringKind::WIDE: return "WIDE";
    case StringLiteralStringKind::UTF8: return "UTF8";
    case StringLiteralStringKind::UTF16: return "UTF16";
    case StringLiteralStringKind::UTF32: return "UTF32";
    default: return "<invalid>";
  }
}

TemplateArgumentKind FromPasta(pasta::TemplateArgumentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TemplateArgumentKind::EMPTY;
    case 1: return TemplateArgumentKind::TYPE;
    case 2: return TemplateArgumentKind::DECLARATION;
    case 3: return TemplateArgumentKind::NULL_POINTER;
    case 4: return TemplateArgumentKind::INTEGRAL;
    case 5: return TemplateArgumentKind::TEMPLATE;
    case 6: return TemplateArgumentKind::TEMPLATE_EXPANSION;
    case 7: return TemplateArgumentKind::EXPRESSION;
    case 8: return TemplateArgumentKind::PACK;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TemplateArgumentKind e) {
  switch (e) {
    case TemplateArgumentKind::EMPTY: return "EMPTY";
    case TemplateArgumentKind::TYPE: return "TYPE";
    case TemplateArgumentKind::DECLARATION: return "DECLARATION";
    case TemplateArgumentKind::NULL_POINTER: return "NULL_POINTER";
    case TemplateArgumentKind::INTEGRAL: return "INTEGRAL";
    case TemplateArgumentKind::TEMPLATE: return "TEMPLATE";
    case TemplateArgumentKind::TEMPLATE_EXPANSION: return "TEMPLATE_EXPANSION";
    case TemplateArgumentKind::EXPRESSION: return "EXPRESSION";
    case TemplateArgumentKind::PACK: return "PACK";
    default: return "<invalid>";
  }
}

TypeScalarTypeKind FromPasta(pasta::TypeScalarTypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeScalarTypeKind::C_POINTER;
    case 1: return TypeScalarTypeKind::BLOCK_POINTER;
    case 2: return TypeScalarTypeKind::OBJ_C_OBJECT_POINTER;
    case 3: return TypeScalarTypeKind::MEMBER_POINTER;
    case 4: return TypeScalarTypeKind::BOOLEAN;
    case 5: return TypeScalarTypeKind::INTEGRAL;
    case 6: return TypeScalarTypeKind::FLOATING;
    case 7: return TypeScalarTypeKind::INTEGRAL_COMPLEX;
    case 8: return TypeScalarTypeKind::FLOATING_COMPLEX;
    case 9: return TypeScalarTypeKind::FIXED_POINT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeScalarTypeKind e) {
  switch (e) {
    case TypeScalarTypeKind::C_POINTER: return "C_POINTER";
    case TypeScalarTypeKind::BLOCK_POINTER: return "BLOCK_POINTER";
    case TypeScalarTypeKind::OBJ_C_OBJECT_POINTER: return "OBJ_C_OBJECT_POINTER";
    case TypeScalarTypeKind::MEMBER_POINTER: return "MEMBER_POINTER";
    case TypeScalarTypeKind::BOOLEAN: return "BOOLEAN";
    case TypeScalarTypeKind::INTEGRAL: return "INTEGRAL";
    case TypeScalarTypeKind::FLOATING: return "FLOATING";
    case TypeScalarTypeKind::INTEGRAL_COMPLEX: return "INTEGRAL_COMPLEX";
    case TypeScalarTypeKind::FLOATING_COMPLEX: return "FLOATING_COMPLEX";
    case TypeScalarTypeKind::FIXED_POINT: return "FIXED_POINT";
    default: return "<invalid>";
  }
}

TypeKind FromPasta(pasta::TypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeKind::ADJUSTED;
    case 1: return TypeKind::DECAYED;
    case 2: return TypeKind::CONSTANT_ARRAY;
    case 3: return TypeKind::DEPENDENT_SIZED_ARRAY;
    case 4: return TypeKind::INCOMPLETE_ARRAY;
    case 5: return TypeKind::VARIABLE_ARRAY;
    case 6: return TypeKind::ATOMIC;
    case 7: return TypeKind::ATTRIBUTED;
    case 8: return TypeKind::BLOCK_POINTER;
    case 9: return TypeKind::BUILTIN;
    case 10: return TypeKind::COMPLEX;
    case 11: return TypeKind::DECLTYPE;
    case 12: return TypeKind::AUTO;
    case 13: return TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION;
    case 14: return TypeKind::DEPENDENT_ADDRESS_SPACE;
    case 15: return TypeKind::DEPENDENT_EXT_INT;
    case 16: return TypeKind::DEPENDENT_NAME;
    case 17: return TypeKind::DEPENDENT_SIZED_EXT_VECTOR;
    case 18: return TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION;
    case 19: return TypeKind::DEPENDENT_VECTOR;
    case 20: return TypeKind::ELABORATED;
    case 21: return TypeKind::EXT_INT;
    case 22: return TypeKind::FUNCTION_NO_PROTO;
    case 23: return TypeKind::FUNCTION_PROTO;
    case 24: return TypeKind::INJECTED_CLASS_NAME;
    case 25: return TypeKind::MACRO_QUALIFIED;
    case 26: return TypeKind::CONSTANT_MATRIX;
    case 27: return TypeKind::DEPENDENT_SIZED_MATRIX;
    case 28: return TypeKind::MEMBER_POINTER;
    case 29: return TypeKind::OBJ_C_OBJECT_POINTER;
    case 30: return TypeKind::OBJ_C_OBJECT;
    case 31: return TypeKind::OBJ_C_INTERFACE;
    case 32: return TypeKind::OBJ_C_TYPE_PARAM;
    case 33: return TypeKind::PACK_EXPANSION;
    case 34: return TypeKind::PAREN;
    case 35: return TypeKind::PIPE;
    case 36: return TypeKind::POINTER;
    case 37: return TypeKind::L_VALUE_REFERENCE;
    case 38: return TypeKind::R_VALUE_REFERENCE;
    case 39: return TypeKind::SUBST_TEMPLATE_TYPE_PARM_PACK;
    case 40: return TypeKind::SUBST_TEMPLATE_TYPE_PARM;
    case 41: return TypeKind::ENUM;
    case 42: return TypeKind::RECORD;
    case 43: return TypeKind::TEMPLATE_SPECIALIZATION;
    case 44: return TypeKind::TEMPLATE_TYPE_PARM;
    case 45: return TypeKind::TYPE_OF_EXPR;
    case 46: return TypeKind::TYPE_OF;
    case 47: return TypeKind::TYPEDEF;
    case 48: return TypeKind::UNARY_TRANSFORM;
    case 49: return TypeKind::UNRESOLVED_USING;
    case 50: return TypeKind::VECTOR;
    case 51: return TypeKind::EXT_VECTOR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeKind e) {
  switch (e) {
    case TypeKind::ADJUSTED: return "ADJUSTED";
    case TypeKind::DECAYED: return "DECAYED";
    case TypeKind::CONSTANT_ARRAY: return "CONSTANT_ARRAY";
    case TypeKind::DEPENDENT_SIZED_ARRAY: return "DEPENDENT_SIZED_ARRAY";
    case TypeKind::INCOMPLETE_ARRAY: return "INCOMPLETE_ARRAY";
    case TypeKind::VARIABLE_ARRAY: return "VARIABLE_ARRAY";
    case TypeKind::ATOMIC: return "ATOMIC";
    case TypeKind::ATTRIBUTED: return "ATTRIBUTED";
    case TypeKind::BLOCK_POINTER: return "BLOCK_POINTER";
    case TypeKind::BUILTIN: return "BUILTIN";
    case TypeKind::COMPLEX: return "COMPLEX";
    case TypeKind::DECLTYPE: return "DECLTYPE";
    case TypeKind::AUTO: return "AUTO";
    case TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION: return "DEDUCED_TEMPLATE_SPECIALIZATION";
    case TypeKind::DEPENDENT_ADDRESS_SPACE: return "DEPENDENT_ADDRESS_SPACE";
    case TypeKind::DEPENDENT_EXT_INT: return "DEPENDENT_EXT_INT";
    case TypeKind::DEPENDENT_NAME: return "DEPENDENT_NAME";
    case TypeKind::DEPENDENT_SIZED_EXT_VECTOR: return "DEPENDENT_SIZED_EXT_VECTOR";
    case TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION: return "DEPENDENT_TEMPLATE_SPECIALIZATION";
    case TypeKind::DEPENDENT_VECTOR: return "DEPENDENT_VECTOR";
    case TypeKind::ELABORATED: return "ELABORATED";
    case TypeKind::EXT_INT: return "EXT_INT";
    case TypeKind::FUNCTION_NO_PROTO: return "FUNCTION_NO_PROTO";
    case TypeKind::FUNCTION_PROTO: return "FUNCTION_PROTO";
    case TypeKind::INJECTED_CLASS_NAME: return "INJECTED_CLASS_NAME";
    case TypeKind::MACRO_QUALIFIED: return "MACRO_QUALIFIED";
    case TypeKind::CONSTANT_MATRIX: return "CONSTANT_MATRIX";
    case TypeKind::DEPENDENT_SIZED_MATRIX: return "DEPENDENT_SIZED_MATRIX";
    case TypeKind::MEMBER_POINTER: return "MEMBER_POINTER";
    case TypeKind::OBJ_C_OBJECT_POINTER: return "OBJ_C_OBJECT_POINTER";
    case TypeKind::OBJ_C_OBJECT: return "OBJ_C_OBJECT";
    case TypeKind::OBJ_C_INTERFACE: return "OBJ_C_INTERFACE";
    case TypeKind::OBJ_C_TYPE_PARAM: return "OBJ_C_TYPE_PARAM";
    case TypeKind::PACK_EXPANSION: return "PACK_EXPANSION";
    case TypeKind::PAREN: return "PAREN";
    case TypeKind::PIPE: return "PIPE";
    case TypeKind::POINTER: return "POINTER";
    case TypeKind::L_VALUE_REFERENCE: return "L_VALUE_REFERENCE";
    case TypeKind::R_VALUE_REFERENCE: return "R_VALUE_REFERENCE";
    case TypeKind::SUBST_TEMPLATE_TYPE_PARM_PACK: return "SUBST_TEMPLATE_TYPE_PARM_PACK";
    case TypeKind::SUBST_TEMPLATE_TYPE_PARM: return "SUBST_TEMPLATE_TYPE_PARM";
    case TypeKind::ENUM: return "ENUM";
    case TypeKind::RECORD: return "RECORD";
    case TypeKind::TEMPLATE_SPECIALIZATION: return "TEMPLATE_SPECIALIZATION";
    case TypeKind::TEMPLATE_TYPE_PARM: return "TEMPLATE_TYPE_PARM";
    case TypeKind::TYPE_OF_EXPR: return "TYPE_OF_EXPR";
    case TypeKind::TYPE_OF: return "TYPE_OF";
    case TypeKind::TYPEDEF: return "TYPEDEF";
    case TypeKind::UNARY_TRANSFORM: return "UNARY_TRANSFORM";
    case TypeKind::UNRESOLVED_USING: return "UNRESOLVED_USING";
    case TypeKind::VECTOR: return "VECTOR";
    case TypeKind::EXT_VECTOR: return "EXT_VECTOR";
    default: return "<invalid>";
  }
}

UnaryTransformTypeUTTKind FromPasta(pasta::UnaryTransformTypeUTTKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnaryTransformTypeUTTKind::ENUM_UNDERLYING_TYPE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(UnaryTransformTypeUTTKind e) {
  switch (e) {
    case UnaryTransformTypeUTTKind::ENUM_UNDERLYING_TYPE: return "ENUM_UNDERLYING_TYPE";
    default: return "<invalid>";
  }
}

UserDefinedLiteralLiteralOperatorKind FromPasta(pasta::UserDefinedLiteralLiteralOperatorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UserDefinedLiteralLiteralOperatorKind::RAW;
    case 1: return UserDefinedLiteralLiteralOperatorKind::TEMPLATE;
    case 2: return UserDefinedLiteralLiteralOperatorKind::INTEGER;
    case 3: return UserDefinedLiteralLiteralOperatorKind::FLOATING;
    case 4: return UserDefinedLiteralLiteralOperatorKind::STRING;
    case 5: return UserDefinedLiteralLiteralOperatorKind::CHARACTER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(UserDefinedLiteralLiteralOperatorKind e) {
  switch (e) {
    case UserDefinedLiteralLiteralOperatorKind::RAW: return "RAW";
    case UserDefinedLiteralLiteralOperatorKind::TEMPLATE: return "TEMPLATE";
    case UserDefinedLiteralLiteralOperatorKind::INTEGER: return "INTEGER";
    case UserDefinedLiteralLiteralOperatorKind::FLOATING: return "FLOATING";
    case UserDefinedLiteralLiteralOperatorKind::STRING: return "STRING";
    case UserDefinedLiteralLiteralOperatorKind::CHARACTER: return "CHARACTER";
    default: return "<invalid>";
  }
}

VarDeclDefinitionKind FromPasta(pasta::VarDeclDefinitionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclDefinitionKind::DECLARATION_ONLY;
    case 1: return VarDeclDefinitionKind::TENTATIVE_DEFINITION;
    case 2: return VarDeclDefinitionKind::DEFINITION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(VarDeclDefinitionKind e) {
  switch (e) {
    case VarDeclDefinitionKind::DECLARATION_ONLY: return "DECLARATION_ONLY";
    case VarDeclDefinitionKind::TENTATIVE_DEFINITION: return "TENTATIVE_DEFINITION";
    case VarDeclDefinitionKind::DEFINITION: return "DEFINITION";
    default: return "<invalid>";
  }
}

VarDeclInitializationStyle FromPasta(pasta::VarDeclInitializationStyle e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclInitializationStyle::C_INIT;
    case 1: return VarDeclInitializationStyle::CALL_INITIALIZER;
    case 2: return VarDeclInitializationStyle::LIST_INITIALIZER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(VarDeclInitializationStyle e) {
  switch (e) {
    case VarDeclInitializationStyle::C_INIT: return "C_INIT";
    case VarDeclInitializationStyle::CALL_INITIALIZER: return "CALL_INITIALIZER";
    case VarDeclInitializationStyle::LIST_INITIALIZER: return "LIST_INITIALIZER";
    default: return "<invalid>";
  }
}

VarDeclTLSKind FromPasta(pasta::VarDeclTLSKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclTLSKind::NONE;
    case 1: return VarDeclTLSKind::STATIC;
    case 2: return VarDeclTLSKind::DYNAMIC;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(VarDeclTLSKind e) {
  switch (e) {
    case VarDeclTLSKind::NONE: return "NONE";
    case VarDeclTLSKind::STATIC: return "STATIC";
    case VarDeclTLSKind::DYNAMIC: return "DYNAMIC";
    default: return "<invalid>";
  }
}

VectorTypeVectorKind FromPasta(pasta::VectorTypeVectorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VectorTypeVectorKind::GENERIC_VECTOR;
    case 1: return VectorTypeVectorKind::ALTI_VEC_VECTOR;
    case 2: return VectorTypeVectorKind::ALTI_VEC_PIXEL;
    case 3: return VectorTypeVectorKind::ALTI_VEC_BOOLEAN;
    case 4: return VectorTypeVectorKind::NEON_VECTOR;
    case 5: return VectorTypeVectorKind::NEON_POLY_VECTOR;
    case 6: return VectorTypeVectorKind::SVE_FIXED_LENGTH_DATA_VECTOR;
    case 7: return VectorTypeVectorKind::SVE_FIXED_LENGTH_PREDICATE_VECTOR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(VectorTypeVectorKind e) {
  switch (e) {
    case VectorTypeVectorKind::GENERIC_VECTOR: return "GENERIC_VECTOR";
    case VectorTypeVectorKind::ALTI_VEC_VECTOR: return "ALTI_VEC_VECTOR";
    case VectorTypeVectorKind::ALTI_VEC_PIXEL: return "ALTI_VEC_PIXEL";
    case VectorTypeVectorKind::ALTI_VEC_BOOLEAN: return "ALTI_VEC_BOOLEAN";
    case VectorTypeVectorKind::NEON_VECTOR: return "NEON_VECTOR";
    case VectorTypeVectorKind::NEON_POLY_VECTOR: return "NEON_POLY_VECTOR";
    case VectorTypeVectorKind::SVE_FIXED_LENGTH_DATA_VECTOR: return "SVE_FIXED_LENGTH_DATA_VECTOR";
    case VectorTypeVectorKind::SVE_FIXED_LENGTH_PREDICATE_VECTOR: return "SVE_FIXED_LENGTH_PREDICATE_VECTOR";
    default: return "<invalid>";
  }
}

ASTDumpOutputFormat FromPasta(pasta::ASTDumpOutputFormat e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ASTDumpOutputFormat::DEFAULT;
    case 1: return ASTDumpOutputFormat::JSON;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ASTDumpOutputFormat e) {
  switch (e) {
    case ASTDumpOutputFormat::DEFAULT: return "DEFAULT";
    case ASTDumpOutputFormat::JSON: return "JSON";
    default: return "<invalid>";
  }
}

AccessSpecifier FromPasta(pasta::AccessSpecifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AccessSpecifier::PUBLIC;
    case 1: return AccessSpecifier::PROTECTED;
    case 2: return AccessSpecifier::PRIVATE;
    case 3: return AccessSpecifier::NONE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AccessSpecifier e) {
  switch (e) {
    case AccessSpecifier::PUBLIC: return "PUBLIC";
    case AccessSpecifier::PROTECTED: return "PROTECTED";
    case AccessSpecifier::PRIVATE: return "PRIVATE";
    case AccessSpecifier::NONE: return "NONE";
    default: return "<invalid>";
  }
}

AddrSpaceMapMangling FromPasta(pasta::AddrSpaceMapMangling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AddrSpaceMapMangling::TARGET;
    case 1: return AddrSpaceMapMangling::ON;
    case 2: return AddrSpaceMapMangling::OFF;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AddrSpaceMapMangling e) {
  switch (e) {
    case AddrSpaceMapMangling::TARGET: return "TARGET";
    case AddrSpaceMapMangling::ON: return "ON";
    case AddrSpaceMapMangling::OFF: return "OFF";
    default: return "<invalid>";
  }
}

AllocatorTypeTy FromPasta(pasta::AllocatorTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AllocatorTypeTy::OMP_NULL_MEMORY_ALLOC;
    case 1: return AllocatorTypeTy::OMP_DEFAULT_MEMORY_ALLOC;
    case 2: return AllocatorTypeTy::OMP_LARGE_CAP_MEMORY_ALLOC;
    case 3: return AllocatorTypeTy::OMP_CONST_MEMORY_ALLOC;
    case 4: return AllocatorTypeTy::OMP_HIGH_BW_MEMORY_ALLOC;
    case 5: return AllocatorTypeTy::OMP_LOW_LAT_MEMORY_ALLOC;
    case 6: return AllocatorTypeTy::OMPC_GROUP_MEMORY_ALLOC;
    case 7: return AllocatorTypeTy::OMPP_TEAM_MEMORY_ALLOC;
    case 8: return AllocatorTypeTy::OMP_THREAD_MEMORY_ALLOC;
    case 9: return AllocatorTypeTy::OMP_USER_DEFINED_MEMORY_ALLOC;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AllocatorTypeTy e) {
  switch (e) {
    case AllocatorTypeTy::OMP_NULL_MEMORY_ALLOC: return "OMP_NULL_MEMORY_ALLOC";
    case AllocatorTypeTy::OMP_DEFAULT_MEMORY_ALLOC: return "OMP_DEFAULT_MEMORY_ALLOC";
    case AllocatorTypeTy::OMP_LARGE_CAP_MEMORY_ALLOC: return "OMP_LARGE_CAP_MEMORY_ALLOC";
    case AllocatorTypeTy::OMP_CONST_MEMORY_ALLOC: return "OMP_CONST_MEMORY_ALLOC";
    case AllocatorTypeTy::OMP_HIGH_BW_MEMORY_ALLOC: return "OMP_HIGH_BW_MEMORY_ALLOC";
    case AllocatorTypeTy::OMP_LOW_LAT_MEMORY_ALLOC: return "OMP_LOW_LAT_MEMORY_ALLOC";
    case AllocatorTypeTy::OMPC_GROUP_MEMORY_ALLOC: return "OMPC_GROUP_MEMORY_ALLOC";
    case AllocatorTypeTy::OMPP_TEAM_MEMORY_ALLOC: return "OMPP_TEAM_MEMORY_ALLOC";
    case AllocatorTypeTy::OMP_THREAD_MEMORY_ALLOC: return "OMP_THREAD_MEMORY_ALLOC";
    case AllocatorTypeTy::OMP_USER_DEFINED_MEMORY_ALLOC: return "OMP_USER_DEFINED_MEMORY_ALLOC";
    default: return "<invalid>";
  }
}

AltivecSrcCompatKind FromPasta(pasta::AltivecSrcCompatKind e) {
  switch (static_cast<int>(e)) {
    case 0: return AltivecSrcCompatKind::MIXED;
    case 1: return AltivecSrcCompatKind::GCC;
    case 2: return AltivecSrcCompatKind::XL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AltivecSrcCompatKind e) {
  switch (e) {
    case AltivecSrcCompatKind::MIXED: return "MIXED";
    case AltivecSrcCompatKind::GCC: return "GCC";
    case AltivecSrcCompatKind::XL: return "XL";
    default: return "<invalid>";
  }
}

ArgumentKind FromPasta(pasta::ArgumentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArgumentKind::STD_STRING;
    case 1: return ArgumentKind::C_STRING;
    case 2: return ArgumentKind::SINT;
    case 3: return ArgumentKind::UINT;
    case 4: return ArgumentKind::TOKENKIND;
    case 5: return ArgumentKind::IDENTIFIERINFO;
    case 6: return ArgumentKind::ADDRSPACE;
    case 7: return ArgumentKind::QUALIFIED;
    case 8: return ArgumentKind::QUALTYPE;
    case 9: return ArgumentKind::DECLARATIONNAME;
    case 10: return ArgumentKind::NAMEDDECL;
    case 11: return ArgumentKind::NESTEDNAMESPEC;
    case 12: return ArgumentKind::DECLCONTEXT;
    case 13: return ArgumentKind::QUALTYPE_PAIR;
    case 14: return ArgumentKind::ATTRIBUTE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ArgumentKind e) {
  switch (e) {
    case ArgumentKind::STD_STRING: return "STD_STRING";
    case ArgumentKind::C_STRING: return "C_STRING";
    case ArgumentKind::SINT: return "SINT";
    case ArgumentKind::UINT: return "UINT";
    case ArgumentKind::TOKENKIND: return "TOKENKIND";
    case ArgumentKind::IDENTIFIERINFO: return "IDENTIFIERINFO";
    case ArgumentKind::ADDRSPACE: return "ADDRSPACE";
    case ArgumentKind::QUALIFIED: return "QUALIFIED";
    case ArgumentKind::QUALTYPE: return "QUALTYPE";
    case ArgumentKind::DECLARATIONNAME: return "DECLARATIONNAME";
    case ArgumentKind::NAMEDDECL: return "NAMEDDECL";
    case ArgumentKind::NESTEDNAMESPEC: return "NESTEDNAMESPEC";
    case ArgumentKind::DECLCONTEXT: return "DECLCONTEXT";
    case ArgumentKind::QUALTYPE_PAIR: return "QUALTYPE_PAIR";
    case ArgumentKind::ATTRIBUTE: return "ATTRIBUTE";
    default: return "<invalid>";
  }
}

ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArrayTypeTrait::ARRAY_RANK;
    case 1: return ArrayTypeTrait::ARRAY_EXTENT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ArrayTypeTrait e) {
  switch (e) {
    case ArrayTypeTrait::ARRAY_RANK: return "ARRAY_RANK";
    case ArrayTypeTrait::ARRAY_EXTENT: return "ARRAY_EXTENT";
    default: return "<invalid>";
  }
}

AtomicScopeModelKind FromPasta(pasta::AtomicScopeModelKind e) {
  switch (static_cast<int>(e)) {
    case 0: return AtomicScopeModelKind::NONE;
    case 1: return AtomicScopeModelKind::OPEN_CL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AtomicScopeModelKind e) {
  switch (e) {
    case AtomicScopeModelKind::NONE: return "NONE";
    case AtomicScopeModelKind::OPEN_CL: return "OPEN_CL";
    default: return "<invalid>";
  }
}

AttributeKind FromPasta(pasta::AttributeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AttributeKind::ADDRESS_SPACE;
    case 1: return AttributeKind::ARM_MVE_STRICT_POLYMORPHISM;
    case 2: return AttributeKind::CMSE_NS_CALL;
    case 3: return AttributeKind::NO_DEREF;
    case 4: return AttributeKind::OBJ_CGC;
    case 5: return AttributeKind::OBJ_C_INERT_UNSAFE_UNRETAINED;
    case 6: return AttributeKind::OBJ_C_KIND_OF;
    case 7: return AttributeKind::OPEN_CL_CONSTANT_ADDRESS_SPACE;
    case 8: return AttributeKind::OPEN_CL_GENERIC_ADDRESS_SPACE;
    case 9: return AttributeKind::OPEN_CL_GLOBAL_ADDRESS_SPACE;
    case 10: return AttributeKind::OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE;
    case 11: return AttributeKind::OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE;
    case 12: return AttributeKind::OPEN_CL_LOCAL_ADDRESS_SPACE;
    case 13: return AttributeKind::OPEN_CL_PRIVATE_ADDRESS_SPACE;
    case 14: return AttributeKind::PTR32;
    case 15: return AttributeKind::PTR64;
    case 16: return AttributeKind::S_PTR;
    case 17: return AttributeKind::TYPE_NON_NULL;
    case 18: return AttributeKind::TYPE_NULL_UNSPECIFIED;
    case 19: return AttributeKind::TYPE_NULLABLE;
    case 20: return AttributeKind::TYPE_NULLABLE_RESULT;
    case 21: return AttributeKind::U_PTR;
    case 22: return AttributeKind::FALL_THROUGH;
    case 23: return AttributeKind::LIKELY;
    case 24: return AttributeKind::MUST_TAIL;
    case 25: return AttributeKind::OPEN_CL_UNROLL_HINT;
    case 26: return AttributeKind::SUPPRESS;
    case 27: return AttributeKind::UNLIKELY;
    case 28: return AttributeKind::NO_MERGE;
    case 29: return AttributeKind::A_ARCH64_VECTOR_PCS;
    case 30: return AttributeKind::ACQUIRE_HANDLE;
    case 31: return AttributeKind::ANY_X86_NO_CF_CHECK;
    case 32: return AttributeKind::C_DECL;
    case 33: return AttributeKind::FAST_CALL;
    case 34: return AttributeKind::INTEL_OCL_BICC;
    case 35: return AttributeKind::LIFETIME_BOUND;
    case 36: return AttributeKind::MSABI;
    case 37: return AttributeKind::NS_RETURNS_RETAINED;
    case 38: return AttributeKind::OBJ_C_OWNERSHIP;
    case 39: return AttributeKind::PASCAL;
    case 40: return AttributeKind::PCS;
    case 41: return AttributeKind::PRESERVE_ALL;
    case 42: return AttributeKind::PRESERVE_MOST;
    case 43: return AttributeKind::REG_CALL;
    case 44: return AttributeKind::STD_CALL;
    case 45: return AttributeKind::SWIFT_ASYNC_CALL;
    case 46: return AttributeKind::SWIFT_CALL;
    case 47: return AttributeKind::SYS_VABI;
    case 48: return AttributeKind::THIS_CALL;
    case 49: return AttributeKind::VECTOR_CALL;
    case 50: return AttributeKind::SWIFT_ASYNC_CONTEXT;
    case 51: return AttributeKind::SWIFT_CONTEXT;
    case 52: return AttributeKind::SWIFT_ERROR_RESULT;
    case 53: return AttributeKind::SWIFT_INDIRECT_RESULT;
    case 54: return AttributeKind::ANNOTATE;
    case 55: return AttributeKind::CF_CONSUMED;
    case 56: return AttributeKind::CARRIES_DEPENDENCY;
    case 57: return AttributeKind::NS_CONSUMED;
    case 58: return AttributeKind::NON_NULL;
    case 59: return AttributeKind::OS_CONSUMED;
    case 60: return AttributeKind::PASS_OBJECT_SIZE;
    case 61: return AttributeKind::RELEASE_HANDLE;
    case 62: return AttributeKind::USE_HANDLE;
    case 63: return AttributeKind::AMDGPU_FLAT_WORK_GROUP_SIZE;
    case 64: return AttributeKind::AMDGPU_NUM_SGPR;
    case 65: return AttributeKind::AMDGPU_NUM_VGPR;
    case 66: return AttributeKind::AMDGPU_WAVES_PER_EU;
    case 67: return AttributeKind::ARM_INTERRUPT;
    case 68: return AttributeKind::AVR_INTERRUPT;
    case 69: return AttributeKind::AVR_SIGNAL;
    case 70: return AttributeKind::ACQUIRE_CAPABILITY;
    case 71: return AttributeKind::ACQUIRED_AFTER;
    case 72: return AttributeKind::ACQUIRED_BEFORE;
    case 73: return AttributeKind::ALIGN_MAC68_K;
    case 74: return AttributeKind::ALIGN_NATURAL;
    case 75: return AttributeKind::ALIGNED;
    case 76: return AttributeKind::ALLOC_ALIGN;
    case 77: return AttributeKind::ALLOC_SIZE;
    case 78: return AttributeKind::ALWAYS_DESTROY;
    case 79: return AttributeKind::ALWAYS_INLINE;
    case 80: return AttributeKind::ANALYZER_NO_RETURN;
    case 81: return AttributeKind::ANY_X86_INTERRUPT;
    case 82: return AttributeKind::ANY_X86_NO_CALLER_SAVED_REGISTERS;
    case 83: return AttributeKind::ARC_WEAKREF_UNAVAILABLE;
    case 84: return AttributeKind::ARGUMENT_WITH_TYPE_TAG;
    case 85: return AttributeKind::ARM_BUILTIN_ALIAS;
    case 86: return AttributeKind::ARTIFICIAL;
    case 87: return AttributeKind::ASSEMBLY_LABEL;
    case 88: return AttributeKind::ASSERT_CAPABILITY;
    case 89: return AttributeKind::ASSERT_EXCLUSIVE_LOCK;
    case 90: return AttributeKind::ASSERT_SHARED_LOCK;
    case 91: return AttributeKind::ASSUME_ALIGNED;
    case 92: return AttributeKind::ASSUMPTION;
    case 93: return AttributeKind::AVAILABILITY;
    case 94: return AttributeKind::BPF_PRESERVE_ACCESS_INDEX;
    case 95: return AttributeKind::BLOCKS;
    case 96: return AttributeKind::BUILTIN;
    case 97: return AttributeKind::C11_NO_RETURN;
    case 98: return AttributeKind::CF_AUDITED_TRANSFER;
    case 99: return AttributeKind::CF_GUARD;
    case 100: return AttributeKind::CFI_CANONICAL_JUMP_TABLE;
    case 101: return AttributeKind::CF_RETURNS_NOT_RETAINED;
    case 102: return AttributeKind::CF_RETURNS_RETAINED;
    case 103: return AttributeKind::CF_UNKNOWN_TRANSFER;
    case 104: return AttributeKind::CPU_DISPATCH;
    case 105: return AttributeKind::CPU_SPECIFIC;
    case 106: return AttributeKind::CUDA_CONSTANT;
    case 107: return AttributeKind::CUDA_DEVICE;
    case 108: return AttributeKind::CUDA_DEVICE_BUILTIN_SURFACE_TYPE;
    case 109: return AttributeKind::CUDA_DEVICE_BUILTIN_TEXTURE_TYPE;
    case 110: return AttributeKind::CUDA_GLOBAL;
    case 111: return AttributeKind::CUDA_HOST;
    case 112: return AttributeKind::CUDA_INVALID_TARGET;
    case 113: return AttributeKind::CUDA_LAUNCH_BOUNDS;
    case 114: return AttributeKind::CUDA_SHARED;
    case 115: return AttributeKind::CXX11_NO_RETURN;
    case 116: return AttributeKind::CALLABLE_WHEN;
    case 117: return AttributeKind::CALLBACK;
    case 118: return AttributeKind::CAPABILITY;
    case 119: return AttributeKind::CAPTURED_RECORD;
    case 120: return AttributeKind::CLEANUP;
    case 121: return AttributeKind::CMSE_NS_ENTRY;
    case 122: return AttributeKind::CODE_SEG;
    case 123: return AttributeKind::COLD;
    case 124: return AttributeKind::COMMON;
    case 125: return AttributeKind::CONST;
    case 126: return AttributeKind::CONST_INITIALIZER;
    case 127: return AttributeKind::CONSTRUCTOR;
    case 128: return AttributeKind::CONSUMABLE;
    case 129: return AttributeKind::CONSUMABLE_AUTO_CAST;
    case 130: return AttributeKind::CONSUMABLE_SET_ON_READ;
    case 131: return AttributeKind::CONVERGENT;
    case 132: return AttributeKind::DLL_EXPORT;
    case 133: return AttributeKind::DLL_EXPORT_STATIC_LOCAL;
    case 134: return AttributeKind::DLL_IMPORT;
    case 135: return AttributeKind::DLL_IMPORT_STATIC_LOCAL;
    case 136: return AttributeKind::DEPRECATED;
    case 137: return AttributeKind::DESTRUCTOR;
    case 138: return AttributeKind::DIAGNOSE_IF;
    case 139: return AttributeKind::DISABLE_TAIL_CALLS;
    case 140: return AttributeKind::EMPTY_BASES;
    case 141: return AttributeKind::ENABLE_IF;
    case 142: return AttributeKind::ENFORCE_TCB;
    case 143: return AttributeKind::ENFORCE_TCB_LEAF;
    case 144: return AttributeKind::ENUM_EXTENSIBILITY;
    case 145: return AttributeKind::EXCLUDE_FROM_EXPLICIT_INSTANTIATION;
    case 146: return AttributeKind::EXCLUSIVE_TRYLOCK_FUNCTION;
    case 147: return AttributeKind::EXTERNAL_SOURCE_SYMBOL;
    case 148: return AttributeKind::FINAL;
    case 149: return AttributeKind::FLAG_ENUM;
    case 150: return AttributeKind::FLATTEN;
    case 151: return AttributeKind::FORMAT;
    case 152: return AttributeKind::FORMAT_ARGUMENT;
    case 153: return AttributeKind::GNU_INLINE;
    case 154: return AttributeKind::GUARDED_BY;
    case 155: return AttributeKind::GUARDED_VARIABLE;
    case 156: return AttributeKind::HIP_MANAGED;
    case 157: return AttributeKind::HOT;
    case 158: return AttributeKind::IB_ACTION;
    case 159: return AttributeKind::IB_OUTLET;
    case 160: return AttributeKind::IB_OUTLET_COLLECTION;
    case 161: return AttributeKind::INITIALIZER_PRIORITY;
    case 162: return AttributeKind::INTERNAL_LINKAGE;
    case 163: return AttributeKind::LTO_VISIBILITY_PUBLIC;
    case 164: return AttributeKind::LAYOUT_VERSION;
    case 165: return AttributeKind::LEAF;
    case 166: return AttributeKind::LOCK_RETURNED;
    case 167: return AttributeKind::LOCKS_EXCLUDED;
    case 168: return AttributeKind::M68_KINTERRUPT;
    case 169: return AttributeKind::MIG_SERVER_ROUTINE;
    case 170: return AttributeKind::MS_ALLOCATOR;
    case 171: return AttributeKind::MS_INHERITANCE;
    case 172: return AttributeKind::MS_NO_V_TABLE;
    case 173: return AttributeKind::MSP430_INTERRUPT;
    case 174: return AttributeKind::MS_STRUCT;
    case 175: return AttributeKind::MS_VTOR_DISP;
    case 176: return AttributeKind::MAX_FIELD_ALIGNMENT;
    case 177: return AttributeKind::MAY_ALIAS;
    case 178: return AttributeKind::MICRO_MIPS;
    case 179: return AttributeKind::MIN_SIZE;
    case 180: return AttributeKind::MIN_VECTOR_WIDTH;
    case 181: return AttributeKind::MIPS16;
    case 182: return AttributeKind::MIPS_INTERRUPT;
    case 183: return AttributeKind::MIPS_LONG_CALL;
    case 184: return AttributeKind::MIPS_SHORT_CALL;
    case 185: return AttributeKind::NS_CONSUMES_SELF;
    case 186: return AttributeKind::NS_ERROR_DOMAIN;
    case 187: return AttributeKind::NS_RETURNS_AUTORELEASED;
    case 188: return AttributeKind::NS_RETURNS_NOT_RETAINED;
    case 189: return AttributeKind::NAKED;
    case 190: return AttributeKind::NO_ALIAS;
    case 191: return AttributeKind::NO_COMMON;
    case 192: return AttributeKind::NO_DEBUG;
    case 193: return AttributeKind::NO_DESTROY;
    case 194: return AttributeKind::NO_DUPLICATE;
    case 195: return AttributeKind::NO_INLINE;
    case 196: return AttributeKind::NO_INSTRUMENT_FUNCTION;
    case 197: return AttributeKind::NO_MICRO_MIPS;
    case 198: return AttributeKind::NO_MIPS16;
    case 199: return AttributeKind::NO_PROFILE_FUNCTION;
    case 200: return AttributeKind::NO_RETURN;
    case 201: return AttributeKind::NO_SANITIZE;
    case 202: return AttributeKind::NO_SPECULATIVE_LOAD_HARDENING;
    case 203: return AttributeKind::NO_SPLIT_STACK;
    case 204: return AttributeKind::NO_STACK_PROTECTOR;
    case 205: return AttributeKind::NO_THREAD_SAFETY_ANALYSIS;
    case 206: return AttributeKind::NO_THROW;
    case 207: return AttributeKind::NO_UNIQUE_ADDRESS;
    case 208: return AttributeKind::NOT_TAIL_CALLED;
    case 209: return AttributeKind::OMP_ALLOCATE_DECLARATION;
    case 210: return AttributeKind::OMP_CAPTURE_NO_INITIALIZER;
    case 211: return AttributeKind::OMP_DECLARE_TARGET_DECLARATION;
    case 212: return AttributeKind::OMP_DECLARE_VARIANT;
    case 213: return AttributeKind::OMP_THREAD_PRIVATE_DECLARATION;
    case 214: return AttributeKind::OS_CONSUMES_THIS;
    case 215: return AttributeKind::OS_RETURNS_NOT_RETAINED;
    case 216: return AttributeKind::OS_RETURNS_RETAINED;
    case 217: return AttributeKind::OS_RETURNS_RETAINED_ON_NON_ZERO;
    case 218: return AttributeKind::OS_RETURNS_RETAINED_ON_ZERO;
    case 219: return AttributeKind::OBJ_C_BRIDGE;
    case 220: return AttributeKind::OBJ_C_BRIDGE_MUTABLE;
    case 221: return AttributeKind::OBJ_C_BRIDGE_RELATED;
    case 222: return AttributeKind::OBJ_C_EXCEPTION;
    case 223: return AttributeKind::OBJ_C_EXPLICIT_PROTOCOL_IMPLEMENTATION;
    case 224: return AttributeKind::OBJ_C_EXTERNALLY_RETAINED;
    case 225: return AttributeKind::OBJ_C_INDEPENDENT_CLASS;
    case 226: return AttributeKind::OBJ_C_METHOD_FAMILY;
    case 227: return AttributeKind::OBJ_CNS_OBJECT;
    case 228: return AttributeKind::OBJ_C_PRECISE_LIFETIME;
    case 229: return AttributeKind::OBJ_C_REQUIRES_PROPERTY_DEFINITIONS;
    case 230: return AttributeKind::OBJ_C_REQUIRES_SUPER;
    case 231: return AttributeKind::OBJ_C_RETURNS_INNER_POINTER;
    case 232: return AttributeKind::OBJ_C_ROOT_CLASS;
    case 233: return AttributeKind::OBJ_C_SUBCLASSING_RESTRICTED;
    case 234: return AttributeKind::OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE;
    case 235: return AttributeKind::OPEN_CL_KERNEL;
    case 236: return AttributeKind::OPTIMIZE_NONE;
    case 237: return AttributeKind::OVERRIDE;
    case 238: return AttributeKind::OWNER;
    case 239: return AttributeKind::OWNERSHIP;
    case 240: return AttributeKind::PACKED;
    case 241: return AttributeKind::PARAMETER_TYPESTATE;
    case 242: return AttributeKind::PATCHABLE_FUNCTION_ENTRY;
    case 243: return AttributeKind::POINTER;
    case 244: return AttributeKind::PRAGMA_CLANG_BSS_SECTION;
    case 245: return AttributeKind::PRAGMA_CLANG_DATA_SECTION;
    case 246: return AttributeKind::PRAGMA_CLANG_RELRO_SECTION;
    case 247: return AttributeKind::PRAGMA_CLANG_RODATA_SECTION;
    case 248: return AttributeKind::PRAGMA_CLANG_TEXT_SECTION;
    case 249: return AttributeKind::PREFERRED_NAME;
    case 250: return AttributeKind::PT_GUARDED_BY;
    case 251: return AttributeKind::PT_GUARDED_VARIABLE;
    case 252: return AttributeKind::PURE;
    case 253: return AttributeKind::RISCV_INTERRUPT;
    case 254: return AttributeKind::REINITIALIZES;
    case 255: return AttributeKind::RELEASE_CAPABILITY;
    case 256: return AttributeKind::REQD_WORK_GROUP_SIZE;
    case 257: return AttributeKind::REQUIRES_CAPABILITY;
    case 258: return AttributeKind::RESTRICT;
    case 259: return AttributeKind::RETAIN;
    case 260: return AttributeKind::RETURN_TYPESTATE;
    case 261: return AttributeKind::RETURNS_NON_NULL;
    case 262: return AttributeKind::RETURNS_TWICE;
    case 263: return AttributeKind::SYCL_KERNEL;
    case 264: return AttributeKind::SCOPED_LOCKABLE;
    case 265: return AttributeKind::SECTION;
    case 266: return AttributeKind::SELECT_ANY;
    case 267: return AttributeKind::SENTINEL;
    case 268: return AttributeKind::SET_TYPESTATE;
    case 269: return AttributeKind::SHARED_TRYLOCK_FUNCTION;
    case 270: return AttributeKind::SPECULATIVE_LOAD_HARDENING;
    case 271: return AttributeKind::STANDALONE_DEBUG;
    case 272: return AttributeKind::STRICT_FP;
    case 273: return AttributeKind::SWIFT_ASYNC;
    case 274: return AttributeKind::SWIFT_ASYNC_ERROR;
    case 275: return AttributeKind::SWIFT_ASYNC_NAME;
    case 276: return AttributeKind::SWIFT_ATTRIBUTE;
    case 277: return AttributeKind::SWIFT_BRIDGE;
    case 278: return AttributeKind::SWIFT_BRIDGED_TYPEDEF;
    case 279: return AttributeKind::SWIFT_ERROR;
    case 280: return AttributeKind::SWIFT_NAME;
    case 281: return AttributeKind::SWIFT_NEW_TYPE;
    case 282: return AttributeKind::SWIFT_PRIVATE;
    case 283: return AttributeKind::TLS_MODEL;
    case 284: return AttributeKind::TARGET;
    case 285: return AttributeKind::TEST_TYPESTATE;
    case 286: return AttributeKind::TRANSPARENT_UNION;
    case 287: return AttributeKind::TRIVIAL_ABI;
    case 288: return AttributeKind::TRY_ACQUIRE_CAPABILITY;
    case 289: return AttributeKind::TYPE_TAG_FOR_DATATYPE;
    case 290: return AttributeKind::TYPE_VISIBILITY;
    case 291: return AttributeKind::UNAVAILABLE;
    case 292: return AttributeKind::UNINITIALIZED;
    case 293: return AttributeKind::UNUSED;
    case 294: return AttributeKind::USED;
    case 295: return AttributeKind::USING_IF_EXISTS;
    case 296: return AttributeKind::UUID;
    case 297: return AttributeKind::VEC_RETURN;
    case 298: return AttributeKind::VEC_TYPE_HINT;
    case 299: return AttributeKind::VISIBILITY;
    case 300: return AttributeKind::WARN_UNUSED;
    case 301: return AttributeKind::WARN_UNUSED_RESULT;
    case 302: return AttributeKind::WEAK;
    case 303: return AttributeKind::WEAK_IMPORT;
    case 304: return AttributeKind::WEAK_REFERENCE;
    case 305: return AttributeKind::WEB_ASSEMBLY_EXPORT_NAME;
    case 306: return AttributeKind::WEB_ASSEMBLY_IMPORT_MODULE;
    case 307: return AttributeKind::WEB_ASSEMBLY_IMPORT_NAME;
    case 308: return AttributeKind::WORK_GROUP_SIZE_HINT;
    case 309: return AttributeKind::X86_FORCE_ALIGN_ARGUMENT_POINTER;
    case 310: return AttributeKind::X_RAY_INSTRUMENT;
    case 311: return AttributeKind::X_RAY_LOG_ARGUMENTS;
    case 312: return AttributeKind::ABI_TAG;
    case 313: return AttributeKind::ALIAS;
    case 314: return AttributeKind::ALIGN_VALUE;
    case 315: return AttributeKind::BUILTIN_ALIAS;
    case 316: return AttributeKind::CALLED_ONCE;
    case 317: return AttributeKind::I_FUNC;
    case 318: return AttributeKind::INITIALIZER_SEG;
    case 319: return AttributeKind::LOADER_UNINITIALIZED;
    case 320: return AttributeKind::LOOP_HINT;
    case 321: return AttributeKind::MODE;
    case 322: return AttributeKind::NO_BUILTIN;
    case 323: return AttributeKind::NO_ESCAPE;
    case 324: return AttributeKind::OMP_CAPTURE_KIND;
    case 325: return AttributeKind::OMP_DECLARE_SIMD_DECLARATION;
    case 326: return AttributeKind::OMP_REFERENCED_VARIABLE;
    case 327: return AttributeKind::OBJ_C_BOXABLE;
    case 328: return AttributeKind::OBJ_C_CLASS_STUB;
    case 329: return AttributeKind::OBJ_C_DESIGNATED_INITIALIZER;
    case 330: return AttributeKind::OBJ_C_DIRECT;
    case 331: return AttributeKind::OBJ_C_DIRECT_MEMBERS;
    case 332: return AttributeKind::OBJ_C_NON_LAZY_CLASS;
    case 333: return AttributeKind::OBJ_C_NON_RUNTIME_PROTOCOL;
    case 334: return AttributeKind::OBJ_C_RUNTIME_NAME;
    case 335: return AttributeKind::OBJ_C_RUNTIME_VISIBLE;
    case 336: return AttributeKind::OPEN_CL_ACCESS;
    case 337: return AttributeKind::OVERLOADABLE;
    case 338: return AttributeKind::RENDER_SCRIPT_KERNEL;
    case 339: return AttributeKind::SWIFT_OBJ_C_MEMBERS;
    case 340: return AttributeKind::THREAD;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AttributeKind e) {
  switch (e) {
    case AttributeKind::ADDRESS_SPACE: return "ADDRESS_SPACE";
    case AttributeKind::ARM_MVE_STRICT_POLYMORPHISM: return "ARM_MVE_STRICT_POLYMORPHISM";
    case AttributeKind::CMSE_NS_CALL: return "CMSE_NS_CALL";
    case AttributeKind::NO_DEREF: return "NO_DEREF";
    case AttributeKind::OBJ_CGC: return "OBJ_CGC";
    case AttributeKind::OBJ_C_INERT_UNSAFE_UNRETAINED: return "OBJ_C_INERT_UNSAFE_UNRETAINED";
    case AttributeKind::OBJ_C_KIND_OF: return "OBJ_C_KIND_OF";
    case AttributeKind::OPEN_CL_CONSTANT_ADDRESS_SPACE: return "OPEN_CL_CONSTANT_ADDRESS_SPACE";
    case AttributeKind::OPEN_CL_GENERIC_ADDRESS_SPACE: return "OPEN_CL_GENERIC_ADDRESS_SPACE";
    case AttributeKind::OPEN_CL_GLOBAL_ADDRESS_SPACE: return "OPEN_CL_GLOBAL_ADDRESS_SPACE";
    case AttributeKind::OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE: return "OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE";
    case AttributeKind::OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE: return "OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE";
    case AttributeKind::OPEN_CL_LOCAL_ADDRESS_SPACE: return "OPEN_CL_LOCAL_ADDRESS_SPACE";
    case AttributeKind::OPEN_CL_PRIVATE_ADDRESS_SPACE: return "OPEN_CL_PRIVATE_ADDRESS_SPACE";
    case AttributeKind::PTR32: return "PTR32";
    case AttributeKind::PTR64: return "PTR64";
    case AttributeKind::S_PTR: return "S_PTR";
    case AttributeKind::TYPE_NON_NULL: return "TYPE_NON_NULL";
    case AttributeKind::TYPE_NULL_UNSPECIFIED: return "TYPE_NULL_UNSPECIFIED";
    case AttributeKind::TYPE_NULLABLE: return "TYPE_NULLABLE";
    case AttributeKind::TYPE_NULLABLE_RESULT: return "TYPE_NULLABLE_RESULT";
    case AttributeKind::U_PTR: return "U_PTR";
    case AttributeKind::FALL_THROUGH: return "FALL_THROUGH";
    case AttributeKind::LIKELY: return "LIKELY";
    case AttributeKind::MUST_TAIL: return "MUST_TAIL";
    case AttributeKind::OPEN_CL_UNROLL_HINT: return "OPEN_CL_UNROLL_HINT";
    case AttributeKind::SUPPRESS: return "SUPPRESS";
    case AttributeKind::UNLIKELY: return "UNLIKELY";
    case AttributeKind::NO_MERGE: return "NO_MERGE";
    case AttributeKind::A_ARCH64_VECTOR_PCS: return "A_ARCH64_VECTOR_PCS";
    case AttributeKind::ACQUIRE_HANDLE: return "ACQUIRE_HANDLE";
    case AttributeKind::ANY_X86_NO_CF_CHECK: return "ANY_X86_NO_CF_CHECK";
    case AttributeKind::C_DECL: return "C_DECL";
    case AttributeKind::FAST_CALL: return "FAST_CALL";
    case AttributeKind::INTEL_OCL_BICC: return "INTEL_OCL_BICC";
    case AttributeKind::LIFETIME_BOUND: return "LIFETIME_BOUND";
    case AttributeKind::MSABI: return "MSABI";
    case AttributeKind::NS_RETURNS_RETAINED: return "NS_RETURNS_RETAINED";
    case AttributeKind::OBJ_C_OWNERSHIP: return "OBJ_C_OWNERSHIP";
    case AttributeKind::PASCAL: return "PASCAL";
    case AttributeKind::PCS: return "PCS";
    case AttributeKind::PRESERVE_ALL: return "PRESERVE_ALL";
    case AttributeKind::PRESERVE_MOST: return "PRESERVE_MOST";
    case AttributeKind::REG_CALL: return "REG_CALL";
    case AttributeKind::STD_CALL: return "STD_CALL";
    case AttributeKind::SWIFT_ASYNC_CALL: return "SWIFT_ASYNC_CALL";
    case AttributeKind::SWIFT_CALL: return "SWIFT_CALL";
    case AttributeKind::SYS_VABI: return "SYS_VABI";
    case AttributeKind::THIS_CALL: return "THIS_CALL";
    case AttributeKind::VECTOR_CALL: return "VECTOR_CALL";
    case AttributeKind::SWIFT_ASYNC_CONTEXT: return "SWIFT_ASYNC_CONTEXT";
    case AttributeKind::SWIFT_CONTEXT: return "SWIFT_CONTEXT";
    case AttributeKind::SWIFT_ERROR_RESULT: return "SWIFT_ERROR_RESULT";
    case AttributeKind::SWIFT_INDIRECT_RESULT: return "SWIFT_INDIRECT_RESULT";
    case AttributeKind::ANNOTATE: return "ANNOTATE";
    case AttributeKind::CF_CONSUMED: return "CF_CONSUMED";
    case AttributeKind::CARRIES_DEPENDENCY: return "CARRIES_DEPENDENCY";
    case AttributeKind::NS_CONSUMED: return "NS_CONSUMED";
    case AttributeKind::NON_NULL: return "NON_NULL";
    case AttributeKind::OS_CONSUMED: return "OS_CONSUMED";
    case AttributeKind::PASS_OBJECT_SIZE: return "PASS_OBJECT_SIZE";
    case AttributeKind::RELEASE_HANDLE: return "RELEASE_HANDLE";
    case AttributeKind::USE_HANDLE: return "USE_HANDLE";
    case AttributeKind::AMDGPU_FLAT_WORK_GROUP_SIZE: return "AMDGPU_FLAT_WORK_GROUP_SIZE";
    case AttributeKind::AMDGPU_NUM_SGPR: return "AMDGPU_NUM_SGPR";
    case AttributeKind::AMDGPU_NUM_VGPR: return "AMDGPU_NUM_VGPR";
    case AttributeKind::AMDGPU_WAVES_PER_EU: return "AMDGPU_WAVES_PER_EU";
    case AttributeKind::ARM_INTERRUPT: return "ARM_INTERRUPT";
    case AttributeKind::AVR_INTERRUPT: return "AVR_INTERRUPT";
    case AttributeKind::AVR_SIGNAL: return "AVR_SIGNAL";
    case AttributeKind::ACQUIRE_CAPABILITY: return "ACQUIRE_CAPABILITY";
    case AttributeKind::ACQUIRED_AFTER: return "ACQUIRED_AFTER";
    case AttributeKind::ACQUIRED_BEFORE: return "ACQUIRED_BEFORE";
    case AttributeKind::ALIGN_MAC68_K: return "ALIGN_MAC68_K";
    case AttributeKind::ALIGN_NATURAL: return "ALIGN_NATURAL";
    case AttributeKind::ALIGNED: return "ALIGNED";
    case AttributeKind::ALLOC_ALIGN: return "ALLOC_ALIGN";
    case AttributeKind::ALLOC_SIZE: return "ALLOC_SIZE";
    case AttributeKind::ALWAYS_DESTROY: return "ALWAYS_DESTROY";
    case AttributeKind::ALWAYS_INLINE: return "ALWAYS_INLINE";
    case AttributeKind::ANALYZER_NO_RETURN: return "ANALYZER_NO_RETURN";
    case AttributeKind::ANY_X86_INTERRUPT: return "ANY_X86_INTERRUPT";
    case AttributeKind::ANY_X86_NO_CALLER_SAVED_REGISTERS: return "ANY_X86_NO_CALLER_SAVED_REGISTERS";
    case AttributeKind::ARC_WEAKREF_UNAVAILABLE: return "ARC_WEAKREF_UNAVAILABLE";
    case AttributeKind::ARGUMENT_WITH_TYPE_TAG: return "ARGUMENT_WITH_TYPE_TAG";
    case AttributeKind::ARM_BUILTIN_ALIAS: return "ARM_BUILTIN_ALIAS";
    case AttributeKind::ARTIFICIAL: return "ARTIFICIAL";
    case AttributeKind::ASSEMBLY_LABEL: return "ASSEMBLY_LABEL";
    case AttributeKind::ASSERT_CAPABILITY: return "ASSERT_CAPABILITY";
    case AttributeKind::ASSERT_EXCLUSIVE_LOCK: return "ASSERT_EXCLUSIVE_LOCK";
    case AttributeKind::ASSERT_SHARED_LOCK: return "ASSERT_SHARED_LOCK";
    case AttributeKind::ASSUME_ALIGNED: return "ASSUME_ALIGNED";
    case AttributeKind::ASSUMPTION: return "ASSUMPTION";
    case AttributeKind::AVAILABILITY: return "AVAILABILITY";
    case AttributeKind::BPF_PRESERVE_ACCESS_INDEX: return "BPF_PRESERVE_ACCESS_INDEX";
    case AttributeKind::BLOCKS: return "BLOCKS";
    case AttributeKind::BUILTIN: return "BUILTIN";
    case AttributeKind::C11_NO_RETURN: return "C11_NO_RETURN";
    case AttributeKind::CF_AUDITED_TRANSFER: return "CF_AUDITED_TRANSFER";
    case AttributeKind::CF_GUARD: return "CF_GUARD";
    case AttributeKind::CFI_CANONICAL_JUMP_TABLE: return "CFI_CANONICAL_JUMP_TABLE";
    case AttributeKind::CF_RETURNS_NOT_RETAINED: return "CF_RETURNS_NOT_RETAINED";
    case AttributeKind::CF_RETURNS_RETAINED: return "CF_RETURNS_RETAINED";
    case AttributeKind::CF_UNKNOWN_TRANSFER: return "CF_UNKNOWN_TRANSFER";
    case AttributeKind::CPU_DISPATCH: return "CPU_DISPATCH";
    case AttributeKind::CPU_SPECIFIC: return "CPU_SPECIFIC";
    case AttributeKind::CUDA_CONSTANT: return "CUDA_CONSTANT";
    case AttributeKind::CUDA_DEVICE: return "CUDA_DEVICE";
    case AttributeKind::CUDA_DEVICE_BUILTIN_SURFACE_TYPE: return "CUDA_DEVICE_BUILTIN_SURFACE_TYPE";
    case AttributeKind::CUDA_DEVICE_BUILTIN_TEXTURE_TYPE: return "CUDA_DEVICE_BUILTIN_TEXTURE_TYPE";
    case AttributeKind::CUDA_GLOBAL: return "CUDA_GLOBAL";
    case AttributeKind::CUDA_HOST: return "CUDA_HOST";
    case AttributeKind::CUDA_INVALID_TARGET: return "CUDA_INVALID_TARGET";
    case AttributeKind::CUDA_LAUNCH_BOUNDS: return "CUDA_LAUNCH_BOUNDS";
    case AttributeKind::CUDA_SHARED: return "CUDA_SHARED";
    case AttributeKind::CXX11_NO_RETURN: return "CXX11_NO_RETURN";
    case AttributeKind::CALLABLE_WHEN: return "CALLABLE_WHEN";
    case AttributeKind::CALLBACK: return "CALLBACK";
    case AttributeKind::CAPABILITY: return "CAPABILITY";
    case AttributeKind::CAPTURED_RECORD: return "CAPTURED_RECORD";
    case AttributeKind::CLEANUP: return "CLEANUP";
    case AttributeKind::CMSE_NS_ENTRY: return "CMSE_NS_ENTRY";
    case AttributeKind::CODE_SEG: return "CODE_SEG";
    case AttributeKind::COLD: return "COLD";
    case AttributeKind::COMMON: return "COMMON";
    case AttributeKind::CONST: return "CONST";
    case AttributeKind::CONST_INITIALIZER: return "CONST_INITIALIZER";
    case AttributeKind::CONSTRUCTOR: return "CONSTRUCTOR";
    case AttributeKind::CONSUMABLE: return "CONSUMABLE";
    case AttributeKind::CONSUMABLE_AUTO_CAST: return "CONSUMABLE_AUTO_CAST";
    case AttributeKind::CONSUMABLE_SET_ON_READ: return "CONSUMABLE_SET_ON_READ";
    case AttributeKind::CONVERGENT: return "CONVERGENT";
    case AttributeKind::DLL_EXPORT: return "DLL_EXPORT";
    case AttributeKind::DLL_EXPORT_STATIC_LOCAL: return "DLL_EXPORT_STATIC_LOCAL";
    case AttributeKind::DLL_IMPORT: return "DLL_IMPORT";
    case AttributeKind::DLL_IMPORT_STATIC_LOCAL: return "DLL_IMPORT_STATIC_LOCAL";
    case AttributeKind::DEPRECATED: return "DEPRECATED";
    case AttributeKind::DESTRUCTOR: return "DESTRUCTOR";
    case AttributeKind::DIAGNOSE_IF: return "DIAGNOSE_IF";
    case AttributeKind::DISABLE_TAIL_CALLS: return "DISABLE_TAIL_CALLS";
    case AttributeKind::EMPTY_BASES: return "EMPTY_BASES";
    case AttributeKind::ENABLE_IF: return "ENABLE_IF";
    case AttributeKind::ENFORCE_TCB: return "ENFORCE_TCB";
    case AttributeKind::ENFORCE_TCB_LEAF: return "ENFORCE_TCB_LEAF";
    case AttributeKind::ENUM_EXTENSIBILITY: return "ENUM_EXTENSIBILITY";
    case AttributeKind::EXCLUDE_FROM_EXPLICIT_INSTANTIATION: return "EXCLUDE_FROM_EXPLICIT_INSTANTIATION";
    case AttributeKind::EXCLUSIVE_TRYLOCK_FUNCTION: return "EXCLUSIVE_TRYLOCK_FUNCTION";
    case AttributeKind::EXTERNAL_SOURCE_SYMBOL: return "EXTERNAL_SOURCE_SYMBOL";
    case AttributeKind::FINAL: return "FINAL";
    case AttributeKind::FLAG_ENUM: return "FLAG_ENUM";
    case AttributeKind::FLATTEN: return "FLATTEN";
    case AttributeKind::FORMAT: return "FORMAT";
    case AttributeKind::FORMAT_ARGUMENT: return "FORMAT_ARGUMENT";
    case AttributeKind::GNU_INLINE: return "GNU_INLINE";
    case AttributeKind::GUARDED_BY: return "GUARDED_BY";
    case AttributeKind::GUARDED_VARIABLE: return "GUARDED_VARIABLE";
    case AttributeKind::HIP_MANAGED: return "HIP_MANAGED";
    case AttributeKind::HOT: return "HOT";
    case AttributeKind::IB_ACTION: return "IB_ACTION";
    case AttributeKind::IB_OUTLET: return "IB_OUTLET";
    case AttributeKind::IB_OUTLET_COLLECTION: return "IB_OUTLET_COLLECTION";
    case AttributeKind::INITIALIZER_PRIORITY: return "INITIALIZER_PRIORITY";
    case AttributeKind::INTERNAL_LINKAGE: return "INTERNAL_LINKAGE";
    case AttributeKind::LTO_VISIBILITY_PUBLIC: return "LTO_VISIBILITY_PUBLIC";
    case AttributeKind::LAYOUT_VERSION: return "LAYOUT_VERSION";
    case AttributeKind::LEAF: return "LEAF";
    case AttributeKind::LOCK_RETURNED: return "LOCK_RETURNED";
    case AttributeKind::LOCKS_EXCLUDED: return "LOCKS_EXCLUDED";
    case AttributeKind::M68_KINTERRUPT: return "M68_KINTERRUPT";
    case AttributeKind::MIG_SERVER_ROUTINE: return "MIG_SERVER_ROUTINE";
    case AttributeKind::MS_ALLOCATOR: return "MS_ALLOCATOR";
    case AttributeKind::MS_INHERITANCE: return "MS_INHERITANCE";
    case AttributeKind::MS_NO_V_TABLE: return "MS_NO_V_TABLE";
    case AttributeKind::MSP430_INTERRUPT: return "MSP430_INTERRUPT";
    case AttributeKind::MS_STRUCT: return "MS_STRUCT";
    case AttributeKind::MS_VTOR_DISP: return "MS_VTOR_DISP";
    case AttributeKind::MAX_FIELD_ALIGNMENT: return "MAX_FIELD_ALIGNMENT";
    case AttributeKind::MAY_ALIAS: return "MAY_ALIAS";
    case AttributeKind::MICRO_MIPS: return "MICRO_MIPS";
    case AttributeKind::MIN_SIZE: return "MIN_SIZE";
    case AttributeKind::MIN_VECTOR_WIDTH: return "MIN_VECTOR_WIDTH";
    case AttributeKind::MIPS16: return "MIPS16";
    case AttributeKind::MIPS_INTERRUPT: return "MIPS_INTERRUPT";
    case AttributeKind::MIPS_LONG_CALL: return "MIPS_LONG_CALL";
    case AttributeKind::MIPS_SHORT_CALL: return "MIPS_SHORT_CALL";
    case AttributeKind::NS_CONSUMES_SELF: return "NS_CONSUMES_SELF";
    case AttributeKind::NS_ERROR_DOMAIN: return "NS_ERROR_DOMAIN";
    case AttributeKind::NS_RETURNS_AUTORELEASED: return "NS_RETURNS_AUTORELEASED";
    case AttributeKind::NS_RETURNS_NOT_RETAINED: return "NS_RETURNS_NOT_RETAINED";
    case AttributeKind::NAKED: return "NAKED";
    case AttributeKind::NO_ALIAS: return "NO_ALIAS";
    case AttributeKind::NO_COMMON: return "NO_COMMON";
    case AttributeKind::NO_DEBUG: return "NO_DEBUG";
    case AttributeKind::NO_DESTROY: return "NO_DESTROY";
    case AttributeKind::NO_DUPLICATE: return "NO_DUPLICATE";
    case AttributeKind::NO_INLINE: return "NO_INLINE";
    case AttributeKind::NO_INSTRUMENT_FUNCTION: return "NO_INSTRUMENT_FUNCTION";
    case AttributeKind::NO_MICRO_MIPS: return "NO_MICRO_MIPS";
    case AttributeKind::NO_MIPS16: return "NO_MIPS16";
    case AttributeKind::NO_PROFILE_FUNCTION: return "NO_PROFILE_FUNCTION";
    case AttributeKind::NO_RETURN: return "NO_RETURN";
    case AttributeKind::NO_SANITIZE: return "NO_SANITIZE";
    case AttributeKind::NO_SPECULATIVE_LOAD_HARDENING: return "NO_SPECULATIVE_LOAD_HARDENING";
    case AttributeKind::NO_SPLIT_STACK: return "NO_SPLIT_STACK";
    case AttributeKind::NO_STACK_PROTECTOR: return "NO_STACK_PROTECTOR";
    case AttributeKind::NO_THREAD_SAFETY_ANALYSIS: return "NO_THREAD_SAFETY_ANALYSIS";
    case AttributeKind::NO_THROW: return "NO_THROW";
    case AttributeKind::NO_UNIQUE_ADDRESS: return "NO_UNIQUE_ADDRESS";
    case AttributeKind::NOT_TAIL_CALLED: return "NOT_TAIL_CALLED";
    case AttributeKind::OMP_ALLOCATE_DECLARATION: return "OMP_ALLOCATE_DECLARATION";
    case AttributeKind::OMP_CAPTURE_NO_INITIALIZER: return "OMP_CAPTURE_NO_INITIALIZER";
    case AttributeKind::OMP_DECLARE_TARGET_DECLARATION: return "OMP_DECLARE_TARGET_DECLARATION";
    case AttributeKind::OMP_DECLARE_VARIANT: return "OMP_DECLARE_VARIANT";
    case AttributeKind::OMP_THREAD_PRIVATE_DECLARATION: return "OMP_THREAD_PRIVATE_DECLARATION";
    case AttributeKind::OS_CONSUMES_THIS: return "OS_CONSUMES_THIS";
    case AttributeKind::OS_RETURNS_NOT_RETAINED: return "OS_RETURNS_NOT_RETAINED";
    case AttributeKind::OS_RETURNS_RETAINED: return "OS_RETURNS_RETAINED";
    case AttributeKind::OS_RETURNS_RETAINED_ON_NON_ZERO: return "OS_RETURNS_RETAINED_ON_NON_ZERO";
    case AttributeKind::OS_RETURNS_RETAINED_ON_ZERO: return "OS_RETURNS_RETAINED_ON_ZERO";
    case AttributeKind::OBJ_C_BRIDGE: return "OBJ_C_BRIDGE";
    case AttributeKind::OBJ_C_BRIDGE_MUTABLE: return "OBJ_C_BRIDGE_MUTABLE";
    case AttributeKind::OBJ_C_BRIDGE_RELATED: return "OBJ_C_BRIDGE_RELATED";
    case AttributeKind::OBJ_C_EXCEPTION: return "OBJ_C_EXCEPTION";
    case AttributeKind::OBJ_C_EXPLICIT_PROTOCOL_IMPLEMENTATION: return "OBJ_C_EXPLICIT_PROTOCOL_IMPLEMENTATION";
    case AttributeKind::OBJ_C_EXTERNALLY_RETAINED: return "OBJ_C_EXTERNALLY_RETAINED";
    case AttributeKind::OBJ_C_INDEPENDENT_CLASS: return "OBJ_C_INDEPENDENT_CLASS";
    case AttributeKind::OBJ_C_METHOD_FAMILY: return "OBJ_C_METHOD_FAMILY";
    case AttributeKind::OBJ_CNS_OBJECT: return "OBJ_CNS_OBJECT";
    case AttributeKind::OBJ_C_PRECISE_LIFETIME: return "OBJ_C_PRECISE_LIFETIME";
    case AttributeKind::OBJ_C_REQUIRES_PROPERTY_DEFINITIONS: return "OBJ_C_REQUIRES_PROPERTY_DEFINITIONS";
    case AttributeKind::OBJ_C_REQUIRES_SUPER: return "OBJ_C_REQUIRES_SUPER";
    case AttributeKind::OBJ_C_RETURNS_INNER_POINTER: return "OBJ_C_RETURNS_INNER_POINTER";
    case AttributeKind::OBJ_C_ROOT_CLASS: return "OBJ_C_ROOT_CLASS";
    case AttributeKind::OBJ_C_SUBCLASSING_RESTRICTED: return "OBJ_C_SUBCLASSING_RESTRICTED";
    case AttributeKind::OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE: return "OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE";
    case AttributeKind::OPEN_CL_KERNEL: return "OPEN_CL_KERNEL";
    case AttributeKind::OPTIMIZE_NONE: return "OPTIMIZE_NONE";
    case AttributeKind::OVERRIDE: return "OVERRIDE";
    case AttributeKind::OWNER: return "OWNER";
    case AttributeKind::OWNERSHIP: return "OWNERSHIP";
    case AttributeKind::PACKED: return "PACKED";
    case AttributeKind::PARAMETER_TYPESTATE: return "PARAMETER_TYPESTATE";
    case AttributeKind::PATCHABLE_FUNCTION_ENTRY: return "PATCHABLE_FUNCTION_ENTRY";
    case AttributeKind::POINTER: return "POINTER";
    case AttributeKind::PRAGMA_CLANG_BSS_SECTION: return "PRAGMA_CLANG_BSS_SECTION";
    case AttributeKind::PRAGMA_CLANG_DATA_SECTION: return "PRAGMA_CLANG_DATA_SECTION";
    case AttributeKind::PRAGMA_CLANG_RELRO_SECTION: return "PRAGMA_CLANG_RELRO_SECTION";
    case AttributeKind::PRAGMA_CLANG_RODATA_SECTION: return "PRAGMA_CLANG_RODATA_SECTION";
    case AttributeKind::PRAGMA_CLANG_TEXT_SECTION: return "PRAGMA_CLANG_TEXT_SECTION";
    case AttributeKind::PREFERRED_NAME: return "PREFERRED_NAME";
    case AttributeKind::PT_GUARDED_BY: return "PT_GUARDED_BY";
    case AttributeKind::PT_GUARDED_VARIABLE: return "PT_GUARDED_VARIABLE";
    case AttributeKind::PURE: return "PURE";
    case AttributeKind::RISCV_INTERRUPT: return "RISCV_INTERRUPT";
    case AttributeKind::REINITIALIZES: return "REINITIALIZES";
    case AttributeKind::RELEASE_CAPABILITY: return "RELEASE_CAPABILITY";
    case AttributeKind::REQD_WORK_GROUP_SIZE: return "REQD_WORK_GROUP_SIZE";
    case AttributeKind::REQUIRES_CAPABILITY: return "REQUIRES_CAPABILITY";
    case AttributeKind::RESTRICT: return "RESTRICT";
    case AttributeKind::RETAIN: return "RETAIN";
    case AttributeKind::RETURN_TYPESTATE: return "RETURN_TYPESTATE";
    case AttributeKind::RETURNS_NON_NULL: return "RETURNS_NON_NULL";
    case AttributeKind::RETURNS_TWICE: return "RETURNS_TWICE";
    case AttributeKind::SYCL_KERNEL: return "SYCL_KERNEL";
    case AttributeKind::SCOPED_LOCKABLE: return "SCOPED_LOCKABLE";
    case AttributeKind::SECTION: return "SECTION";
    case AttributeKind::SELECT_ANY: return "SELECT_ANY";
    case AttributeKind::SENTINEL: return "SENTINEL";
    case AttributeKind::SET_TYPESTATE: return "SET_TYPESTATE";
    case AttributeKind::SHARED_TRYLOCK_FUNCTION: return "SHARED_TRYLOCK_FUNCTION";
    case AttributeKind::SPECULATIVE_LOAD_HARDENING: return "SPECULATIVE_LOAD_HARDENING";
    case AttributeKind::STANDALONE_DEBUG: return "STANDALONE_DEBUG";
    case AttributeKind::STRICT_FP: return "STRICT_FP";
    case AttributeKind::SWIFT_ASYNC: return "SWIFT_ASYNC";
    case AttributeKind::SWIFT_ASYNC_ERROR: return "SWIFT_ASYNC_ERROR";
    case AttributeKind::SWIFT_ASYNC_NAME: return "SWIFT_ASYNC_NAME";
    case AttributeKind::SWIFT_ATTRIBUTE: return "SWIFT_ATTRIBUTE";
    case AttributeKind::SWIFT_BRIDGE: return "SWIFT_BRIDGE";
    case AttributeKind::SWIFT_BRIDGED_TYPEDEF: return "SWIFT_BRIDGED_TYPEDEF";
    case AttributeKind::SWIFT_ERROR: return "SWIFT_ERROR";
    case AttributeKind::SWIFT_NAME: return "SWIFT_NAME";
    case AttributeKind::SWIFT_NEW_TYPE: return "SWIFT_NEW_TYPE";
    case AttributeKind::SWIFT_PRIVATE: return "SWIFT_PRIVATE";
    case AttributeKind::TLS_MODEL: return "TLS_MODEL";
    case AttributeKind::TARGET: return "TARGET";
    case AttributeKind::TEST_TYPESTATE: return "TEST_TYPESTATE";
    case AttributeKind::TRANSPARENT_UNION: return "TRANSPARENT_UNION";
    case AttributeKind::TRIVIAL_ABI: return "TRIVIAL_ABI";
    case AttributeKind::TRY_ACQUIRE_CAPABILITY: return "TRY_ACQUIRE_CAPABILITY";
    case AttributeKind::TYPE_TAG_FOR_DATATYPE: return "TYPE_TAG_FOR_DATATYPE";
    case AttributeKind::TYPE_VISIBILITY: return "TYPE_VISIBILITY";
    case AttributeKind::UNAVAILABLE: return "UNAVAILABLE";
    case AttributeKind::UNINITIALIZED: return "UNINITIALIZED";
    case AttributeKind::UNUSED: return "UNUSED";
    case AttributeKind::USED: return "USED";
    case AttributeKind::USING_IF_EXISTS: return "USING_IF_EXISTS";
    case AttributeKind::UUID: return "UUID";
    case AttributeKind::VEC_RETURN: return "VEC_RETURN";
    case AttributeKind::VEC_TYPE_HINT: return "VEC_TYPE_HINT";
    case AttributeKind::VISIBILITY: return "VISIBILITY";
    case AttributeKind::WARN_UNUSED: return "WARN_UNUSED";
    case AttributeKind::WARN_UNUSED_RESULT: return "WARN_UNUSED_RESULT";
    case AttributeKind::WEAK: return "WEAK";
    case AttributeKind::WEAK_IMPORT: return "WEAK_IMPORT";
    case AttributeKind::WEAK_REFERENCE: return "WEAK_REFERENCE";
    case AttributeKind::WEB_ASSEMBLY_EXPORT_NAME: return "WEB_ASSEMBLY_EXPORT_NAME";
    case AttributeKind::WEB_ASSEMBLY_IMPORT_MODULE: return "WEB_ASSEMBLY_IMPORT_MODULE";
    case AttributeKind::WEB_ASSEMBLY_IMPORT_NAME: return "WEB_ASSEMBLY_IMPORT_NAME";
    case AttributeKind::WORK_GROUP_SIZE_HINT: return "WORK_GROUP_SIZE_HINT";
    case AttributeKind::X86_FORCE_ALIGN_ARGUMENT_POINTER: return "X86_FORCE_ALIGN_ARGUMENT_POINTER";
    case AttributeKind::X_RAY_INSTRUMENT: return "X_RAY_INSTRUMENT";
    case AttributeKind::X_RAY_LOG_ARGUMENTS: return "X_RAY_LOG_ARGUMENTS";
    case AttributeKind::ABI_TAG: return "ABI_TAG";
    case AttributeKind::ALIAS: return "ALIAS";
    case AttributeKind::ALIGN_VALUE: return "ALIGN_VALUE";
    case AttributeKind::BUILTIN_ALIAS: return "BUILTIN_ALIAS";
    case AttributeKind::CALLED_ONCE: return "CALLED_ONCE";
    case AttributeKind::I_FUNC: return "I_FUNC";
    case AttributeKind::INITIALIZER_SEG: return "INITIALIZER_SEG";
    case AttributeKind::LOADER_UNINITIALIZED: return "LOADER_UNINITIALIZED";
    case AttributeKind::LOOP_HINT: return "LOOP_HINT";
    case AttributeKind::MODE: return "MODE";
    case AttributeKind::NO_BUILTIN: return "NO_BUILTIN";
    case AttributeKind::NO_ESCAPE: return "NO_ESCAPE";
    case AttributeKind::OMP_CAPTURE_KIND: return "OMP_CAPTURE_KIND";
    case AttributeKind::OMP_DECLARE_SIMD_DECLARATION: return "OMP_DECLARE_SIMD_DECLARATION";
    case AttributeKind::OMP_REFERENCED_VARIABLE: return "OMP_REFERENCED_VARIABLE";
    case AttributeKind::OBJ_C_BOXABLE: return "OBJ_C_BOXABLE";
    case AttributeKind::OBJ_C_CLASS_STUB: return "OBJ_C_CLASS_STUB";
    case AttributeKind::OBJ_C_DESIGNATED_INITIALIZER: return "OBJ_C_DESIGNATED_INITIALIZER";
    case AttributeKind::OBJ_C_DIRECT: return "OBJ_C_DIRECT";
    case AttributeKind::OBJ_C_DIRECT_MEMBERS: return "OBJ_C_DIRECT_MEMBERS";
    case AttributeKind::OBJ_C_NON_LAZY_CLASS: return "OBJ_C_NON_LAZY_CLASS";
    case AttributeKind::OBJ_C_NON_RUNTIME_PROTOCOL: return "OBJ_C_NON_RUNTIME_PROTOCOL";
    case AttributeKind::OBJ_C_RUNTIME_NAME: return "OBJ_C_RUNTIME_NAME";
    case AttributeKind::OBJ_C_RUNTIME_VISIBLE: return "OBJ_C_RUNTIME_VISIBLE";
    case AttributeKind::OPEN_CL_ACCESS: return "OPEN_CL_ACCESS";
    case AttributeKind::OVERLOADABLE: return "OVERLOADABLE";
    case AttributeKind::RENDER_SCRIPT_KERNEL: return "RENDER_SCRIPT_KERNEL";
    case AttributeKind::SWIFT_OBJ_C_MEMBERS: return "SWIFT_OBJ_C_MEMBERS";
    case AttributeKind::THREAD: return "THREAD";
    default: return "<invalid>";
  }
}

AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword e) {
  switch (static_cast<int>(e)) {
    case 0: return AutoTypeKeyword::AUTO;
    case 1: return AutoTypeKeyword::DECLTYPE_AUTO;
    case 2: return AutoTypeKeyword::GNU_AUTO_TYPE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AutoTypeKeyword e) {
  switch (e) {
    case AutoTypeKeyword::AUTO: return "AUTO";
    case AutoTypeKeyword::DECLTYPE_AUTO: return "DECLTYPE_AUTO";
    case AutoTypeKeyword::GNU_AUTO_TYPE: return "GNU_AUTO_TYPE";
    default: return "<invalid>";
  }
}

AvailabilityResult FromPasta(pasta::AvailabilityResult e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AvailabilityResult::AVAILABLE;
    case 1: return AvailabilityResult::NOT_YET_INTRODUCED;
    case 2: return AvailabilityResult::DEPRECATED;
    case 3: return AvailabilityResult::UNAVAILABLE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(AvailabilityResult e) {
  switch (e) {
    case AvailabilityResult::AVAILABLE: return "AVAILABLE";
    case AvailabilityResult::NOT_YET_INTRODUCED: return "NOT_YET_INTRODUCED";
    case AvailabilityResult::DEPRECATED: return "DEPRECATED";
    case AvailabilityResult::UNAVAILABLE: return "UNAVAILABLE";
    default: return "<invalid>";
  }
}

BinaryOperatorKind FromPasta(pasta::BinaryOperatorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BinaryOperatorKind::POINTER_MEMORY_D;
    case 1: return BinaryOperatorKind::POINTER_MEMORY_I;
    case 2: return BinaryOperatorKind::MUL;
    case 3: return BinaryOperatorKind::DIV;
    case 4: return BinaryOperatorKind::REM;
    case 5: return BinaryOperatorKind::ADD;
    case 6: return BinaryOperatorKind::SUB;
    case 7: return BinaryOperatorKind::SHL;
    case 8: return BinaryOperatorKind::SHR;
    case 9: return BinaryOperatorKind::CMP;
    case 10: return BinaryOperatorKind::LT;
    case 11: return BinaryOperatorKind::GT;
    case 12: return BinaryOperatorKind::LE;
    case 13: return BinaryOperatorKind::GE;
    case 14: return BinaryOperatorKind::EQ;
    case 15: return BinaryOperatorKind::NE;
    case 16: return BinaryOperatorKind::AND;
    case 17: return BinaryOperatorKind::XOR;
    case 18: return BinaryOperatorKind::OR;
    case 19: return BinaryOperatorKind::L_AND;
    case 20: return BinaryOperatorKind::L_OR;
    case 21: return BinaryOperatorKind::ASSIGN;
    case 22: return BinaryOperatorKind::MUL_ASSIGN;
    case 23: return BinaryOperatorKind::DIV_ASSIGN;
    case 24: return BinaryOperatorKind::REM_ASSIGN;
    case 25: return BinaryOperatorKind::ADD_ASSIGN;
    case 26: return BinaryOperatorKind::SUB_ASSIGN;
    case 27: return BinaryOperatorKind::SHL_ASSIGN;
    case 28: return BinaryOperatorKind::SHR_ASSIGN;
    case 29: return BinaryOperatorKind::AND_ASSIGN;
    case 30: return BinaryOperatorKind::XOR_ASSIGN;
    case 31: return BinaryOperatorKind::OR_ASSIGN;
    case 32: return BinaryOperatorKind::COMMA;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(BinaryOperatorKind e) {
  switch (e) {
    case BinaryOperatorKind::POINTER_MEMORY_D: return "POINTER_MEMORY_D";
    case BinaryOperatorKind::POINTER_MEMORY_I: return "POINTER_MEMORY_I";
    case BinaryOperatorKind::MUL: return "MUL";
    case BinaryOperatorKind::DIV: return "DIV";
    case BinaryOperatorKind::REM: return "REM";
    case BinaryOperatorKind::ADD: return "ADD";
    case BinaryOperatorKind::SUB: return "SUB";
    case BinaryOperatorKind::SHL: return "SHL";
    case BinaryOperatorKind::SHR: return "SHR";
    case BinaryOperatorKind::CMP: return "CMP";
    case BinaryOperatorKind::LT: return "LT";
    case BinaryOperatorKind::GT: return "GT";
    case BinaryOperatorKind::LE: return "LE";
    case BinaryOperatorKind::GE: return "GE";
    case BinaryOperatorKind::EQ: return "EQ";
    case BinaryOperatorKind::NE: return "NE";
    case BinaryOperatorKind::AND: return "AND";
    case BinaryOperatorKind::XOR: return "XOR";
    case BinaryOperatorKind::OR: return "OR";
    case BinaryOperatorKind::L_AND: return "L_AND";
    case BinaryOperatorKind::L_OR: return "L_OR";
    case BinaryOperatorKind::ASSIGN: return "ASSIGN";
    case BinaryOperatorKind::MUL_ASSIGN: return "MUL_ASSIGN";
    case BinaryOperatorKind::DIV_ASSIGN: return "DIV_ASSIGN";
    case BinaryOperatorKind::REM_ASSIGN: return "REM_ASSIGN";
    case BinaryOperatorKind::ADD_ASSIGN: return "ADD_ASSIGN";
    case BinaryOperatorKind::SUB_ASSIGN: return "SUB_ASSIGN";
    case BinaryOperatorKind::SHL_ASSIGN: return "SHL_ASSIGN";
    case BinaryOperatorKind::SHR_ASSIGN: return "SHR_ASSIGN";
    case BinaryOperatorKind::AND_ASSIGN: return "AND_ASSIGN";
    case BinaryOperatorKind::XOR_ASSIGN: return "XOR_ASSIGN";
    case BinaryOperatorKind::OR_ASSIGN: return "OR_ASSIGN";
    case BinaryOperatorKind::COMMA: return "COMMA";
    default: return "<invalid>";
  }
}

Bits FromPasta(pasta::Bits e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return Bits::NONE;
    case 1: return Bits::UNEXPANDED_PACK;
    case 2: return Bits::INSTANTIATION;
    case 4: return Bits::TYPE;
    case 8: return Bits::VALUE;
    case 12: return Bits::DEPENDENT;
    case 16: return Bits::ERROR;
    case 32: return Bits::VARIABLY_MODIFIED;
    case 19: return Bits::SYNTACTIC;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Bits e) {
  switch (e) {
    case Bits::NONE: return "NONE";
    case Bits::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case Bits::INSTANTIATION: return "INSTANTIATION";
    case Bits::TYPE: return "TYPE";
    case Bits::VALUE: return "VALUE";
    case Bits::DEPENDENT: return "DEPENDENT";
    case Bits::ERROR: return "ERROR";
    case Bits::VARIABLY_MODIFIED: return "VARIABLY_MODIFIED";
    case Bits::SYNTACTIC: return "SYNTACTIC";
    default: return "<invalid>";
  }
}

BlockType FromPasta(pasta::BlockType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BlockType::BY_REFERENCE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(BlockType e) {
  switch (e) {
    case BlockType::BY_REFERENCE: return "BY_REFERENCE";
    default: return "<invalid>";
  }
}

BranchStateTy FromPasta(pasta::BranchStateTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BranchStateTy::UNDEFINED;
    case 1: return BranchStateTy::INBRANCH;
    case 2: return BranchStateTy::NOTINBRANCH;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(BranchStateTy e) {
  switch (e) {
    case BranchStateTy::UNDEFINED: return "UNDEFINED";
    case BranchStateTy::INBRANCH: return "INBRANCH";
    case BranchStateTy::NOTINBRANCH: return "NOTINBRANCH";
    default: return "<invalid>";
  }
}

CallingConv FromPasta(pasta::CallingConv e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CallingConv::C;
    case 1: return CallingConv::X86_STD_CALL;
    case 2: return CallingConv::X86_FAST_CALL;
    case 3: return CallingConv::X86_THIS_CALL;
    case 4: return CallingConv::X86_VECTOR_CALL;
    case 5: return CallingConv::X86_PASCAL;
    case 6: return CallingConv::WIN64;
    case 7: return CallingConv::X8664_SYS_V;
    case 8: return CallingConv::X86_REG_CALL;
    case 9: return CallingConv::AAPCS;
    case 10: return CallingConv::AAPCSVFP;
    case 11: return CallingConv::INTEL_OCL_BICC;
    case 12: return CallingConv::SPIR_FUNCTION;
    case 13: return CallingConv::OPEN_CL_KERNEL;
    case 14: return CallingConv::SWIFT;
    case 15: return CallingConv::SWIFT_ASYNC;
    case 16: return CallingConv::PRESERVE_MOST;
    case 17: return CallingConv::PRESERVE_ALL;
    case 18: return CallingConv::A_ARCH64_VECTOR_CALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CallingConv e) {
  switch (e) {
    case CallingConv::C: return "C";
    case CallingConv::X86_STD_CALL: return "X86_STD_CALL";
    case CallingConv::X86_FAST_CALL: return "X86_FAST_CALL";
    case CallingConv::X86_THIS_CALL: return "X86_THIS_CALL";
    case CallingConv::X86_VECTOR_CALL: return "X86_VECTOR_CALL";
    case CallingConv::X86_PASCAL: return "X86_PASCAL";
    case CallingConv::WIN64: return "WIN64";
    case CallingConv::X8664_SYS_V: return "X8664_SYS_V";
    case CallingConv::X86_REG_CALL: return "X86_REG_CALL";
    case CallingConv::AAPCS: return "AAPCS";
    case CallingConv::AAPCSVFP: return "AAPCSVFP";
    case CallingConv::INTEL_OCL_BICC: return "INTEL_OCL_BICC";
    case CallingConv::SPIR_FUNCTION: return "SPIR_FUNCTION";
    case CallingConv::OPEN_CL_KERNEL: return "OPEN_CL_KERNEL";
    case CallingConv::SWIFT: return "SWIFT";
    case CallingConv::SWIFT_ASYNC: return "SWIFT_ASYNC";
    case CallingConv::PRESERVE_MOST: return "PRESERVE_MOST";
    case CallingConv::PRESERVE_ALL: return "PRESERVE_ALL";
    case CallingConv::A_ARCH64_VECTOR_CALL: return "A_ARCH64_VECTOR_CALL";
    default: return "<invalid>";
  }
}

CanThrowResult FromPasta(pasta::CanThrowResult e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CanThrowResult::CANNOT;
    case 1: return CanThrowResult::DEPENDENT;
    case 2: return CanThrowResult::CAN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CanThrowResult e) {
  switch (e) {
    case CanThrowResult::CANNOT: return "CANNOT";
    case CanThrowResult::DEPENDENT: return "DEPENDENT";
    case CanThrowResult::CAN: return "CAN";
    default: return "<invalid>";
  }
}

CapturedRegionKind FromPasta(pasta::CapturedRegionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CapturedRegionKind::DEFAULT;
    case 1: return CapturedRegionKind::OBJ_C_AT_FINALLY;
    case 2: return CapturedRegionKind::OPEN_MP;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CapturedRegionKind e) {
  switch (e) {
    case CapturedRegionKind::DEFAULT: return "DEFAULT";
    case CapturedRegionKind::OBJ_C_AT_FINALLY: return "OBJ_C_AT_FINALLY";
    case CapturedRegionKind::OPEN_MP: return "OPEN_MP";
    default: return "<invalid>";
  }
}

CastKind FromPasta(pasta::CastKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CastKind::DEPENDENT;
    case 1: return CastKind::BIT_CAST;
    case 2: return CastKind::L_VALUE_BIT_CAST;
    case 3: return CastKind::L_VALUE_TO_R_VALUE_BIT_CAST;
    case 4: return CastKind::L_VALUE_TO_R_VALUE;
    case 5: return CastKind::NO_OPERATION;
    case 6: return CastKind::BASE_TO_DERIVED;
    case 7: return CastKind::DERIVED_TO_BASE;
    case 8: return CastKind::UNCHECKED_DERIVED_TO_BASE;
    case 9: return CastKind::DYNAMIC;
    case 10: return CastKind::TO_UNION;
    case 11: return CastKind::ARRAY_TO_POINTER_DECAY;
    case 12: return CastKind::FUNCTION_TO_POINTER_DECAY;
    case 13: return CastKind::NULL_TO_POINTER;
    case 14: return CastKind::NULL_TO_MEMBER_POINTER;
    case 15: return CastKind::BASE_TO_DERIVED_MEMBER_POINTER;
    case 16: return CastKind::DERIVED_TO_BASE_MEMBER_POINTER;
    case 17: return CastKind::MEMBER_POINTER_TO_BOOLEAN;
    case 18: return CastKind::REINTERPRET_MEMBER_POINTER;
    case 19: return CastKind::USER_DEFINED_CONVERSION;
    case 20: return CastKind::CONSTRUCTOR_CONVERSION;
    case 21: return CastKind::INTEGRAL_TO_POINTER;
    case 22: return CastKind::POINTER_TO_INTEGRAL;
    case 23: return CastKind::POINTER_TO_BOOLEAN;
    case 24: return CastKind::TO_VOID;
    case 25: return CastKind::MATRIX_CAST;
    case 26: return CastKind::VECTOR_SPLAT;
    case 27: return CastKind::INTEGRAL_CAST;
    case 28: return CastKind::INTEGRAL_TO_BOOLEAN;
    case 29: return CastKind::INTEGRAL_TO_FLOATING;
    case 30: return CastKind::FLOATING_TO_FIXED_POINT;
    case 31: return CastKind::FIXED_POINT_TO_FLOATING;
    case 32: return CastKind::FIXED_POINT_CAST;
    case 33: return CastKind::FIXED_POINT_TO_INTEGRAL;
    case 34: return CastKind::INTEGRAL_TO_FIXED_POINT;
    case 35: return CastKind::FIXED_POINT_TO_BOOLEAN;
    case 36: return CastKind::FLOATING_TO_INTEGRAL;
    case 37: return CastKind::FLOATING_TO_BOOLEAN;
    case 38: return CastKind::BOOLEAN_TO_SIGNED_INTEGRAL;
    case 39: return CastKind::FLOATING_CAST;
    case 40: return CastKind::C_POINTER_TO_OBJ_C_POINTER_CAST;
    case 41: return CastKind::BLOCK_POINTER_TO_OBJ_C_POINTER_CAST;
    case 42: return CastKind::ANY_POINTER_TO_BLOCK_POINTER_CAST;
    case 43: return CastKind::OBJ_C_OBJECT_L_VALUE_CAST;
    case 44: return CastKind::FLOATING_REAL_TO_COMPLEX;
    case 45: return CastKind::FLOATING_COMPLEX_TO_REAL;
    case 46: return CastKind::FLOATING_COMPLEX_TO_BOOLEAN;
    case 47: return CastKind::FLOATING_COMPLEX_CAST;
    case 48: return CastKind::FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX;
    case 49: return CastKind::INTEGRAL_REAL_TO_COMPLEX;
    case 50: return CastKind::INTEGRAL_COMPLEX_TO_REAL;
    case 51: return CastKind::INTEGRAL_COMPLEX_TO_BOOLEAN;
    case 52: return CastKind::INTEGRAL_COMPLEX_CAST;
    case 53: return CastKind::INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX;
    case 54: return CastKind::ARC_PRODUCE_OBJECT;
    case 55: return CastKind::ARC_CONSUME_OBJECT;
    case 56: return CastKind::ARC_RECLAIM_RETURNED_OBJECT;
    case 57: return CastKind::ARC_EXTEND_BLOCK_OBJECT;
    case 58: return CastKind::ATOMIC_TO_NON_ATOMIC;
    case 59: return CastKind::NON_ATOMIC_TO_ATOMIC;
    case 60: return CastKind::COPY_AND_AUTORELEASE_BLOCK_OBJECT;
    case 61: return CastKind::BUILTIN_FN_TO_FN_POINTER;
    case 62: return CastKind::ZERO_TO_OCL_OPAQUE_TYPE;
    case 63: return CastKind::ADDRESS_SPACE_CONVERSION;
    case 64: return CastKind::INT_TO_OCL_SAMPLER;
    default: __builtin_unreachable();
  }
}

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

ClangABI FromPasta(pasta::ClangABI e) {
  switch (static_cast<int>(e)) {
    case 0: return ClangABI::VER38;
    case 1: return ClangABI::VER4;
    case 2: return ClangABI::VER6;
    case 3: return ClangABI::VER7;
    case 4: return ClangABI::VER9;
    case 5: return ClangABI::VER11;
    case 6: return ClangABI::VER12;
    case 7: return ClangABI::LATEST;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ClangABI e) {
  switch (e) {
    case ClangABI::VER38: return "VER38";
    case ClangABI::VER4: return "VER4";
    case ClangABI::VER6: return "VER6";
    case ClangABI::VER7: return "VER7";
    case ClangABI::VER9: return "VER9";
    case ClangABI::VER11: return "VER11";
    case ClangABI::VER12: return "VER12";
    case ClangABI::LATEST: return "LATEST";
    default: return "<invalid>";
  }
}

CommentKind FromPasta(pasta::CommentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CommentKind::INVALID;
    case 1: return CommentKind::ORDINARY_BCPL;
    case 2: return CommentKind::ORDINARY_C;
    case 3: return CommentKind::BCPL_SLASH;
    case 4: return CommentKind::BCPL_EXCL;
    case 5: return CommentKind::JAVA_DOC;
    case 6: return CommentKind::QT;
    case 7: return CommentKind::MERGED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CommentKind e) {
  switch (e) {
    case CommentKind::INVALID: return "INVALID";
    case CommentKind::ORDINARY_BCPL: return "ORDINARY_BCPL";
    case CommentKind::ORDINARY_C: return "ORDINARY_C";
    case CommentKind::BCPL_SLASH: return "BCPL_SLASH";
    case CommentKind::BCPL_EXCL: return "BCPL_EXCL";
    case CommentKind::JAVA_DOC: return "JAVA_DOC";
    case CommentKind::QT: return "QT";
    case CommentKind::MERGED: return "MERGED";
    default: return "<invalid>";
  }
}

ComparisonCategoryResult FromPasta(pasta::ComparisonCategoryResult e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ComparisonCategoryResult::EQUAL;
    case 1: return ComparisonCategoryResult::EQUIVALENT;
    case 2: return ComparisonCategoryResult::LESS;
    case 3: return ComparisonCategoryResult::GREATER;
    case 4: return ComparisonCategoryResult::UNORDERED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ComparisonCategoryResult e) {
  switch (e) {
    case ComparisonCategoryResult::EQUAL: return "EQUAL";
    case ComparisonCategoryResult::EQUIVALENT: return "EQUIVALENT";
    case ComparisonCategoryResult::LESS: return "LESS";
    case ComparisonCategoryResult::GREATER: return "GREATER";
    case ComparisonCategoryResult::UNORDERED: return "UNORDERED";
    default: return "<invalid>";
  }
}

ComparisonCategoryType FromPasta(pasta::ComparisonCategoryType e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ComparisonCategoryType::PARTIAL_ORDERING;
    case 1: return ComparisonCategoryType::WEAK_ORDERING;
    case 2: return ComparisonCategoryType::STRONG_ORDERING;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ComparisonCategoryType e) {
  switch (e) {
    case ComparisonCategoryType::PARTIAL_ORDERING: return "PARTIAL_ORDERING";
    case ComparisonCategoryType::WEAK_ORDERING: return "WEAK_ORDERING";
    case ComparisonCategoryType::STRONG_ORDERING: return "STRONG_ORDERING";
    default: return "<invalid>";
  }
}

CompilingModuleKind FromPasta(pasta::CompilingModuleKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CompilingModuleKind::NONE;
    case 1: return CompilingModuleKind::MODULE_MAP;
    case 2: return CompilingModuleKind::HEADER_MODULE;
    case 3: return CompilingModuleKind::MODULE_INTERFACE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CompilingModuleKind e) {
  switch (e) {
    case CompilingModuleKind::NONE: return "NONE";
    case CompilingModuleKind::MODULE_MAP: return "MODULE_MAP";
    case CompilingModuleKind::HEADER_MODULE: return "HEADER_MODULE";
    case CompilingModuleKind::MODULE_INTERFACE: return "MODULE_INTERFACE";
    default: return "<invalid>";
  }
}

ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ConstexprSpecKind::UNSPECIFIED;
    case 1: return ConstexprSpecKind::CONSTEXPR;
    case 2: return ConstexprSpecKind::CONSTEVAL;
    case 3: return ConstexprSpecKind::CONSTINIT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ConstexprSpecKind e) {
  switch (e) {
    case ConstexprSpecKind::UNSPECIFIED: return "UNSPECIFIED";
    case ConstexprSpecKind::CONSTEXPR: return "CONSTEXPR";
    case ConstexprSpecKind::CONSTEVAL: return "CONSTEVAL";
    case ConstexprSpecKind::CONSTINIT: return "CONSTINIT";
    default: return "<invalid>";
  }
}

ConsumedState FromPasta(pasta::ConsumedState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConsumedState::UNKNOWN;
    case 1: return ConsumedState::CONSUMED;
    case 2: return ConsumedState::UNCONSUMED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ConsumedState e) {
  switch (e) {
    case ConsumedState::UNKNOWN: return "UNKNOWN";
    case ConsumedState::CONSUMED: return "CONSUMED";
    case ConsumedState::UNCONSUMED: return "UNCONSUMED";
    default: return "<invalid>";
  }
}

ConventionKind FromPasta(pasta::ConventionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConventionKind::NONE;
    case 1: return ConventionKind::NON_NULL_ERROR;
    case 2: return ConventionKind::ZERO_ARGUMENT;
    case 3: return ConventionKind::NON_ZERO_ARGUMENT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ConventionKind e) {
  switch (e) {
    case ConventionKind::NONE: return "NONE";
    case ConventionKind::NON_NULL_ERROR: return "NON_NULL_ERROR";
    case ConventionKind::ZERO_ARGUMENT: return "ZERO_ARGUMENT";
    case ConventionKind::NON_ZERO_ARGUMENT: return "NON_ZERO_ARGUMENT";
    default: return "<invalid>";
  }
}

CoreFoundationABI FromPasta(pasta::CoreFoundationABI e) {
  switch (static_cast<int>(e)) {
    case 0: return CoreFoundationABI::UNSPECIFIED;
    case 1: return CoreFoundationABI::STANDALONE;
    case 2: return CoreFoundationABI::OBJECTIVE_C;
    case 3: return CoreFoundationABI::SWIFT;
    case 4: return CoreFoundationABI::SWIFT50;
    case 5: return CoreFoundationABI::SWIFT42;
    case 6: return CoreFoundationABI::SWIFT41;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CoreFoundationABI e) {
  switch (e) {
    case CoreFoundationABI::UNSPECIFIED: return "UNSPECIFIED";
    case CoreFoundationABI::STANDALONE: return "STANDALONE";
    case CoreFoundationABI::OBJECTIVE_C: return "OBJECTIVE_C";
    case CoreFoundationABI::SWIFT: return "SWIFT";
    case CoreFoundationABI::SWIFT50: return "SWIFT50";
    case CoreFoundationABI::SWIFT42: return "SWIFT42";
    case CoreFoundationABI::SWIFT41: return "SWIFT41";
    default: return "<invalid>";
  }
}

DefaultArgKind FromPasta(pasta::DefaultArgKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DefaultArgKind::NONE;
    case 1: return DefaultArgKind::UNPARSED;
    case 2: return DefaultArgKind::UNINSTANTIATED;
    case 3: return DefaultArgKind::NORMAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DefaultArgKind e) {
  switch (e) {
    case DefaultArgKind::NONE: return "NONE";
    case DefaultArgKind::UNPARSED: return "UNPARSED";
    case DefaultArgKind::UNINSTANTIATED: return "UNINSTANTIATED";
    case DefaultArgKind::NORMAL: return "NORMAL";
    default: return "<invalid>";
  }
}

DefaultCallingConvention FromPasta(pasta::DefaultCallingConvention e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DefaultCallingConvention::NONE;
    case 1: return DefaultCallingConvention::C_DECL;
    case 2: return DefaultCallingConvention::FAST_CALL;
    case 3: return DefaultCallingConvention::STD_CALL;
    case 4: return DefaultCallingConvention::VECTOR_CALL;
    case 5: return DefaultCallingConvention::REG_CALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DefaultCallingConvention e) {
  switch (e) {
    case DefaultCallingConvention::NONE: return "NONE";
    case DefaultCallingConvention::C_DECL: return "C_DECL";
    case DefaultCallingConvention::FAST_CALL: return "FAST_CALL";
    case DefaultCallingConvention::STD_CALL: return "STD_CALL";
    case DefaultCallingConvention::VECTOR_CALL: return "VECTOR_CALL";
    case DefaultCallingConvention::REG_CALL: return "REG_CALL";
    default: return "<invalid>";
  }
}

DevTypeTy FromPasta(pasta::DevTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DevTypeTy::HOST;
    case 1: return DevTypeTy::NO_HOST;
    case 2: return DevTypeTy::ANY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DevTypeTy e) {
  switch (e) {
    case DevTypeTy::HOST: return "HOST";
    case DevTypeTy::NO_HOST: return "NO_HOST";
    case DevTypeTy::ANY: return "ANY";
    default: return "<invalid>";
  }
}

DiagnosticLevelMask FromPasta(pasta::DiagnosticLevelMask e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DiagnosticLevelMask::NONE;
    case 1: return DiagnosticLevelMask::NOTE;
    case 2: return DiagnosticLevelMask::REMARK;
    case 4: return DiagnosticLevelMask::WARNING;
    case 8: return DiagnosticLevelMask::ERROR;
    case 15: return DiagnosticLevelMask::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DiagnosticLevelMask e) {
  switch (e) {
    case DiagnosticLevelMask::NONE: return "NONE";
    case DiagnosticLevelMask::NOTE: return "NOTE";
    case DiagnosticLevelMask::REMARK: return "REMARK";
    case DiagnosticLevelMask::WARNING: return "WARNING";
    case DiagnosticLevelMask::ERROR: return "ERROR";
    case DiagnosticLevelMask::ALL: return "ALL";
    default: return "<invalid>";
  }
}

DiagnosticType FromPasta(pasta::DiagnosticType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DiagnosticType::ERROR;
    case 1: return DiagnosticType::WARNING;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(DiagnosticType e) {
  switch (e) {
    case DiagnosticType::ERROR: return "ERROR";
    case DiagnosticType::WARNING: return "WARNING";
    default: return "<invalid>";
  }
}

ElaboratedTypeKeyword FromPasta(pasta::ElaboratedTypeKeyword e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ElaboratedTypeKeyword::STRUCT;
    case 1: return ElaboratedTypeKeyword::INTERFACE;
    case 2: return ElaboratedTypeKeyword::UNION;
    case 3: return ElaboratedTypeKeyword::CLASS;
    case 4: return ElaboratedTypeKeyword::ENUM;
    case 5: return ElaboratedTypeKeyword::TYPENAME;
    case 6: return ElaboratedTypeKeyword::NONE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ElaboratedTypeKeyword e) {
  switch (e) {
    case ElaboratedTypeKeyword::STRUCT: return "STRUCT";
    case ElaboratedTypeKeyword::INTERFACE: return "INTERFACE";
    case ElaboratedTypeKeyword::UNION: return "UNION";
    case ElaboratedTypeKeyword::CLASS: return "CLASS";
    case ElaboratedTypeKeyword::ENUM: return "ENUM";
    case ElaboratedTypeKeyword::TYPENAME: return "TYPENAME";
    case ElaboratedTypeKeyword::NONE: return "NONE";
    default: return "<invalid>";
  }
}

EmbedBitcodeKind FromPasta(pasta::EmbedBitcodeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return EmbedBitcodeKind::EMBED_OFF;
    case 1: return EmbedBitcodeKind::EMBED_ALL;
    case 2: return EmbedBitcodeKind::EMBED_BITCODE;
    case 3: return EmbedBitcodeKind::EMBED_MARKER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(EmbedBitcodeKind e) {
  switch (e) {
    case EmbedBitcodeKind::EMBED_OFF: return "EMBED_OFF";
    case EmbedBitcodeKind::EMBED_ALL: return "EMBED_ALL";
    case EmbedBitcodeKind::EMBED_BITCODE: return "EMBED_BITCODE";
    case EmbedBitcodeKind::EMBED_MARKER: return "EMBED_MARKER";
    default: return "<invalid>";
  }
}

ExceptionHandlingKind FromPasta(pasta::ExceptionHandlingKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExceptionHandlingKind::NONE;
    case 1: return ExceptionHandlingKind::SJ_LJ;
    case 2: return ExceptionHandlingKind::WIN_EH;
    case 3: return ExceptionHandlingKind::DWARF_CFI;
    case 4: return ExceptionHandlingKind::WASM;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExceptionHandlingKind e) {
  switch (e) {
    case ExceptionHandlingKind::NONE: return "NONE";
    case ExceptionHandlingKind::SJ_LJ: return "SJ_LJ";
    case ExceptionHandlingKind::WIN_EH: return "WIN_EH";
    case ExceptionHandlingKind::DWARF_CFI: return "DWARF_CFI";
    case ExceptionHandlingKind::WASM: return "WASM";
    default: return "<invalid>";
  }
}

ExceptionSpecificationType FromPasta(pasta::ExceptionSpecificationType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExceptionSpecificationType::NONE;
    case 1: return ExceptionSpecificationType::DYNAMIC_NONE;
    case 2: return ExceptionSpecificationType::DYNAMIC;
    case 3: return ExceptionSpecificationType::MS_ANY;
    case 4: return ExceptionSpecificationType::NO_THROW;
    case 5: return ExceptionSpecificationType::BASIC_NOEXCEPT;
    case 6: return ExceptionSpecificationType::DEPENDENT_NOEXCEPT;
    case 7: return ExceptionSpecificationType::NOEXCEPT_FALSE;
    case 8: return ExceptionSpecificationType::NOEXCEPT_TRUE;
    case 9: return ExceptionSpecificationType::UNEVALUATED;
    case 10: return ExceptionSpecificationType::UNINSTANTIATED;
    case 11: return ExceptionSpecificationType::UNPARSED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExceptionSpecificationType e) {
  switch (e) {
    case ExceptionSpecificationType::NONE: return "NONE";
    case ExceptionSpecificationType::DYNAMIC_NONE: return "DYNAMIC_NONE";
    case ExceptionSpecificationType::DYNAMIC: return "DYNAMIC";
    case ExceptionSpecificationType::MS_ANY: return "MS_ANY";
    case ExceptionSpecificationType::NO_THROW: return "NO_THROW";
    case ExceptionSpecificationType::BASIC_NOEXCEPT: return "BASIC_NOEXCEPT";
    case ExceptionSpecificationType::DEPENDENT_NOEXCEPT: return "DEPENDENT_NOEXCEPT";
    case ExceptionSpecificationType::NOEXCEPT_FALSE: return "NOEXCEPT_FALSE";
    case ExceptionSpecificationType::NOEXCEPT_TRUE: return "NOEXCEPT_TRUE";
    case ExceptionSpecificationType::UNEVALUATED: return "UNEVALUATED";
    case ExceptionSpecificationType::UNINSTANTIATED: return "UNINSTANTIATED";
    case ExceptionSpecificationType::UNPARSED: return "UNPARSED";
    default: return "<invalid>";
  }
}

ExplicitSpecKind FromPasta(pasta::ExplicitSpecKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExplicitSpecKind::RESOLVED_FALSE;
    case 1: return ExplicitSpecKind::RESOLVED_TRUE;
    case 2: return ExplicitSpecKind::UNRESOLVED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExplicitSpecKind e) {
  switch (e) {
    case ExplicitSpecKind::RESOLVED_FALSE: return "RESOLVED_FALSE";
    case ExplicitSpecKind::RESOLVED_TRUE: return "RESOLVED_TRUE";
    case ExplicitSpecKind::UNRESOLVED: return "UNRESOLVED";
    default: return "<invalid>";
  }
}

ExprDependence FromPasta(pasta::ExprDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return ExprDependence::UNEXPANDED_PACK;
    case 2: return ExprDependence::INSTANTIATION;
    case 4: return ExprDependence::TYPE;
    case 8: return ExprDependence::VALUE;
    case 16: return ExprDependence::ERROR;
    case 0: return ExprDependence::NONE;
    case 31: return ExprDependence::ALL;
    case 12: return ExprDependence::TYPE_VALUE;
    case 6: return ExprDependence::TYPE_INSTANTIATION;
    case 10: return ExprDependence::VALUE_INSTANTIATION;
    case 14: return ExprDependence::TYPE_VALUE_INSTANTIATION;
    case 26: return ExprDependence::ERROR_DEPENDENT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprDependence e) {
  switch (e) {
    case ExprDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case ExprDependence::INSTANTIATION: return "INSTANTIATION";
    case ExprDependence::TYPE: return "TYPE";
    case ExprDependence::VALUE: return "VALUE";
    case ExprDependence::ERROR: return "ERROR";
    case ExprDependence::NONE: return "NONE";
    case ExprDependence::ALL: return "ALL";
    case ExprDependence::TYPE_VALUE: return "TYPE_VALUE";
    case ExprDependence::TYPE_INSTANTIATION: return "TYPE_INSTANTIATION";
    case ExprDependence::VALUE_INSTANTIATION: return "VALUE_INSTANTIATION";
    case ExprDependence::TYPE_VALUE_INSTANTIATION: return "TYPE_VALUE_INSTANTIATION";
    case ExprDependence::ERROR_DEPENDENT: return "ERROR_DEPENDENT";
    default: return "<invalid>";
  }
}

ExprObjectKind FromPasta(pasta::ExprObjectKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprObjectKind::ORDINARY;
    case 1: return ExprObjectKind::BIT_FIELD;
    case 2: return ExprObjectKind::VECTOR_COMPONENT;
    case 3: return ExprObjectKind::OBJ_C_PROPERTY;
    case 4: return ExprObjectKind::OBJ_C_SUBSCRIPT;
    case 5: return ExprObjectKind::MATRIX_COMPONENT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprObjectKind e) {
  switch (e) {
    case ExprObjectKind::ORDINARY: return "ORDINARY";
    case ExprObjectKind::BIT_FIELD: return "BIT_FIELD";
    case ExprObjectKind::VECTOR_COMPONENT: return "VECTOR_COMPONENT";
    case ExprObjectKind::OBJ_C_PROPERTY: return "OBJ_C_PROPERTY";
    case ExprObjectKind::OBJ_C_SUBSCRIPT: return "OBJ_C_SUBSCRIPT";
    case ExprObjectKind::MATRIX_COMPONENT: return "MATRIX_COMPONENT";
    default: return "<invalid>";
  }
}

ExprOffsets FromPasta(pasta::ExprOffsets e) {
  switch (static_cast<int>(e)) {
    case 0: return ExprOffsets::ALLOCATOR;
    case 1: return ExprOffsets::ALLOCATOR_TRAITS;
    case 2: return ExprOffsets::TOTAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprOffsets e) {
  switch (e) {
    case ExprOffsets::ALLOCATOR: return "ALLOCATOR";
    case ExprOffsets::ALLOCATOR_TRAITS: return "ALLOCATOR_TRAITS";
    case ExprOffsets::TOTAL: return "TOTAL";
    default: return "<invalid>";
  }
}

ExprValueKind FromPasta(pasta::ExprValueKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprValueKind::PR_VALUE;
    case 1: return ExprValueKind::L_VALUE;
    case 2: return ExprValueKind::X_VALUE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExprValueKind e) {
  switch (e) {
    case ExprValueKind::PR_VALUE: return "PR_VALUE";
    case ExprValueKind::L_VALUE: return "L_VALUE";
    case ExprValueKind::X_VALUE: return "X_VALUE";
    default: return "<invalid>";
  }
}

ExpressionTrait FromPasta(pasta::ExpressionTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExpressionTrait::IS_L_VALUE_EXPRESSION;
    case 1: return ExpressionTrait::IS_R_VALUE_EXPRESSION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExpressionTrait e) {
  switch (e) {
    case ExpressionTrait::IS_L_VALUE_EXPRESSION: return "IS_L_VALUE_EXPRESSION";
    case ExpressionTrait::IS_R_VALUE_EXPRESSION: return "IS_R_VALUE_EXPRESSION";
    default: return "<invalid>";
  }
}

ExtKind FromPasta(pasta::ExtKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExtKind::ALWAYS;
    case 1: return ExtKind::NEVER;
    case 2: return ExtKind::REPLY_HAZY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExtKind e) {
  switch (e) {
    case ExtKind::ALWAYS: return "ALWAYS";
    case ExtKind::NEVER: return "NEVER";
    case ExtKind::REPLY_HAZY: return "REPLY_HAZY";
    default: return "<invalid>";
  }
}

ExtendArgsKind FromPasta(pasta::ExtendArgsKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExtendArgsKind::EXTEND_TO32;
    case 1: return ExtendArgsKind::EXTEND_TO64;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ExtendArgsKind e) {
  switch (e) {
    case ExtendArgsKind::EXTEND_TO32: return "EXTEND_TO32";
    case ExtendArgsKind::EXTEND_TO64: return "EXTEND_TO64";
    default: return "<invalid>";
  }
}

FPExceptionModeKind FromPasta(pasta::FPExceptionModeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FPExceptionModeKind::IGNORE;
    case 1: return FPExceptionModeKind::MAY_TRAP;
    case 2: return FPExceptionModeKind::STRICT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(FPExceptionModeKind e) {
  switch (e) {
    case FPExceptionModeKind::IGNORE: return "IGNORE";
    case FPExceptionModeKind::MAY_TRAP: return "MAY_TRAP";
    case FPExceptionModeKind::STRICT: return "STRICT";
    default: return "<invalid>";
  }
}

FPModeKind FromPasta(pasta::FPModeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FPModeKind::OFF;
    case 1: return FPModeKind::ON;
    case 2: return FPModeKind::FAST;
    case 3: return FPModeKind::FAST_HONOR_PRAGMAS;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(FPModeKind e) {
  switch (e) {
    case FPModeKind::OFF: return "OFF";
    case FPModeKind::ON: return "ON";
    case FPModeKind::FAST: return "FAST";
    case FPModeKind::FAST_HONOR_PRAGMAS: return "FAST_HONOR_PRAGMAS";
    default: return "<invalid>";
  }
}

FamilyKind FromPasta(pasta::FamilyKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FamilyKind::NONE;
    case 1: return FamilyKind::ALLOC;
    case 2: return FamilyKind::COPY;
    case 3: return FamilyKind::INITIALIZER;
    case 4: return FamilyKind::MUTABLE_COPY;
    case 5: return FamilyKind::NEW;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(FamilyKind e) {
  switch (e) {
    case FamilyKind::NONE: return "NONE";
    case FamilyKind::ALLOC: return "ALLOC";
    case FamilyKind::COPY: return "COPY";
    case FamilyKind::INITIALIZER: return "INITIALIZER";
    case FamilyKind::MUTABLE_COPY: return "MUTABLE_COPY";
    case FamilyKind::NEW: return "NEW";
    default: return "<invalid>";
  }
}

FiniteLoopsKind FromPasta(pasta::FiniteLoopsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FiniteLoopsKind::LANGUAGE;
    case 1: return FiniteLoopsKind::ALWAYS;
    case 2: return FiniteLoopsKind::NEVER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(FiniteLoopsKind e) {
  switch (e) {
    case FiniteLoopsKind::LANGUAGE: return "LANGUAGE";
    case FiniteLoopsKind::ALWAYS: return "ALWAYS";
    case FiniteLoopsKind::NEVER: return "NEVER";
    default: return "<invalid>";
  }
}

FramePointerKind FromPasta(pasta::FramePointerKind e) {
  switch (static_cast<int>(e)) {
    case 0: return FramePointerKind::NONE;
    case 1: return FramePointerKind::NON_LEAF;
    case 2: return FramePointerKind::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(FramePointerKind e) {
  switch (e) {
    case FramePointerKind::NONE: return "NONE";
    case FramePointerKind::NON_LEAF: return "NON_LEAF";
    case FramePointerKind::ALL: return "ALL";
    default: return "<invalid>";
  }
}

GC FromPasta(pasta::GC e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GC::GC_NONE;
    case 1: return GC::WEAK;
    case 2: return GC::STRONG;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(GC e) {
  switch (e) {
    case GC::GC_NONE: return "GC_NONE";
    case GC::WEAK: return "WEAK";
    case GC::STRONG: return "STRONG";
    default: return "<invalid>";
  }
}

GCMode FromPasta(pasta::GCMode e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GCMode::NON_GC;
    case 1: return GCMode::GC_ONLY;
    case 2: return GCMode::HYBRID_GC;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(GCMode e) {
  switch (e) {
    case GCMode::NON_GC: return "NON_GC";
    case GCMode::GC_ONLY: return "GC_ONLY";
    case GCMode::HYBRID_GC: return "HYBRID_GC";
    default: return "<invalid>";
  }
}

GVALinkage FromPasta(pasta::GVALinkage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GVALinkage::INTERNAL;
    case 1: return GVALinkage::AVAILABLE_EXTERNALLY;
    case 2: return GVALinkage::DISCARDABLE_ODR;
    case 3: return GVALinkage::STRONG_EXTERNAL;
    case 4: return GVALinkage::STRONG_ODR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(GVALinkage e) {
  switch (e) {
    case GVALinkage::INTERNAL: return "INTERNAL";
    case GVALinkage::AVAILABLE_EXTERNALLY: return "AVAILABLE_EXTERNALLY";
    case GVALinkage::DISCARDABLE_ODR: return "DISCARDABLE_ODR";
    case GVALinkage::STRONG_EXTERNAL: return "STRONG_EXTERNAL";
    case GVALinkage::STRONG_ODR: return "STRONG_ODR";
    default: return "<invalid>";
  }
}

GetBuiltinTypeError FromPasta(pasta::GetBuiltinTypeError e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GetBuiltinTypeError::NONE;
    case 1: return GetBuiltinTypeError::MISSING_TYPE;
    case 2: return GetBuiltinTypeError::MISSING_STDIO;
    case 3: return GetBuiltinTypeError::MISSING;
    case 4: return GetBuiltinTypeError::MISSING_UCONTEXT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(GetBuiltinTypeError e) {
  switch (e) {
    case GetBuiltinTypeError::NONE: return "NONE";
    case GetBuiltinTypeError::MISSING_TYPE: return "MISSING_TYPE";
    case GetBuiltinTypeError::MISSING_STDIO: return "MISSING_STDIO";
    case GetBuiltinTypeError::MISSING: return "MISSING";
    case GetBuiltinTypeError::MISSING_UCONTEXT: return "MISSING_UCONTEXT";
    default: return "<invalid>";
  }
}

GuardArg FromPasta(pasta::GuardArg e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GuardArg::NOCF;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(GuardArg e) {
  switch (e) {
    case GuardArg::NOCF: return "NOCF";
    default: return "<invalid>";
  }
}

ID FromPasta(pasta::ID e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return ID::WORK_GROUP;
    case 2: return ID::DEVICE;
    case 3: return ID::ALL_SVM_DEVICES;
    case 4: return ID::SUB_GROUP;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ID e) {
  switch (e) {
    case ID::WORK_GROUP: return "WORK_GROUP";
    case ID::DEVICE: return "DEVICE";
    case ID::ALL_SVM_DEVICES: return "ALL_SVM_DEVICES";
    case ID::SUB_GROUP: return "SUB_GROUP";
    default: return "<invalid>";
  }
}

IdentifierInfoFlag FromPasta(pasta::IdentifierInfoFlag e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return IdentifierInfoFlag::ZERO_ARGUMENT;
    case 2: return IdentifierInfoFlag::ONE_ARGUMENT;
    case 7: return IdentifierInfoFlag::MULTI_ARGUMENT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(IdentifierInfoFlag e) {
  switch (e) {
    case IdentifierInfoFlag::ZERO_ARGUMENT: return "ZERO_ARGUMENT";
    case IdentifierInfoFlag::ONE_ARGUMENT: return "ONE_ARGUMENT";
    case IdentifierInfoFlag::MULTI_ARGUMENT: return "MULTI_ARGUMENT";
    default: return "<invalid>";
  }
}

ImbueAttribute FromPasta(pasta::ImbueAttribute e) {
  switch (static_cast<int>(e)) {
    case 0: return ImbueAttribute::NONE;
    case 1: return ImbueAttribute::ALWAYS;
    case 2: return ImbueAttribute::NEVER;
    case 3: return ImbueAttribute::ALWAYSARG1;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ImbueAttribute e) {
  switch (e) {
    case ImbueAttribute::NONE: return "NONE";
    case ImbueAttribute::ALWAYS: return "ALWAYS";
    case ImbueAttribute::NEVER: return "NEVER";
    case ImbueAttribute::ALWAYSARG1: return "ALWAYSARG1";
    default: return "<invalid>";
  }
}

ImplicitReason FromPasta(pasta::ImplicitReason e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ImplicitReason::NONE;
    case 1: return ImplicitReason::ARC_FORBIDDEN_TYPE;
    case 2: return ImplicitReason::FORBIDDEN_WEAK;
    case 3: return ImplicitReason::ARC_FORBIDDEN_CONVERSION;
    case 4: return ImplicitReason::ARC_INIT_RETURNS_UNRELATED;
    case 5: return ImplicitReason::ARC_FIELD_WITH_OWNERSHIP;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ImplicitReason e) {
  switch (e) {
    case ImplicitReason::NONE: return "NONE";
    case ImplicitReason::ARC_FORBIDDEN_TYPE: return "ARC_FORBIDDEN_TYPE";
    case ImplicitReason::FORBIDDEN_WEAK: return "FORBIDDEN_WEAK";
    case ImplicitReason::ARC_FORBIDDEN_CONVERSION: return "ARC_FORBIDDEN_CONVERSION";
    case ImplicitReason::ARC_INIT_RETURNS_UNRELATED: return "ARC_INIT_RETURNS_UNRELATED";
    case ImplicitReason::ARC_FIELD_WITH_OWNERSHIP: return "ARC_FIELD_WITH_OWNERSHIP";
    default: return "<invalid>";
  }
}

InClassInitStyle FromPasta(pasta::InClassInitStyle e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InClassInitStyle::NO_INITIALIZER;
    case 1: return InClassInitStyle::COPY_INITIALIZER;
    case 2: return InClassInitStyle::LIST_INITIALIZER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(InClassInitStyle e) {
  switch (e) {
    case InClassInitStyle::NO_INITIALIZER: return "NO_INITIALIZER";
    case InClassInitStyle::COPY_INITIALIZER: return "COPY_INITIALIZER";
    case InClassInitStyle::LIST_INITIALIZER: return "LIST_INITIALIZER";
    default: return "<invalid>";
  }
}

InheritedDesignatedInitializersState FromPasta(pasta::InheritedDesignatedInitializersState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InheritedDesignatedInitializersState::UNKNOWN;
    case 1: return InheritedDesignatedInitializersState::INHERITED;
    case 2: return InheritedDesignatedInitializersState::NOT_INHERITED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(InheritedDesignatedInitializersState e) {
  switch (e) {
    case InheritedDesignatedInitializersState::UNKNOWN: return "UNKNOWN";
    case InheritedDesignatedInitializersState::INHERITED: return "INHERITED";
    case InheritedDesignatedInitializersState::NOT_INHERITED: return "NOT_INHERITED";
    default: return "<invalid>";
  }
}

InitStorageKind FromPasta(pasta::InitStorageKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InitStorageKind::NO_INITIALIZER;
    case 1: return InitStorageKind::IN_CLASS_COPY_INITIALIZER;
    case 2: return InitStorageKind::IN_CLASS_LIST_INITIALIZER;
    case 3: return InitStorageKind::CAPTURED_VLA_TYPE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(InitStorageKind e) {
  switch (e) {
    case InitStorageKind::NO_INITIALIZER: return "NO_INITIALIZER";
    case InitStorageKind::IN_CLASS_COPY_INITIALIZER: return "IN_CLASS_COPY_INITIALIZER";
    case InitStorageKind::IN_CLASS_LIST_INITIALIZER: return "IN_CLASS_LIST_INITIALIZER";
    case InitStorageKind::CAPTURED_VLA_TYPE: return "CAPTURED_VLA_TYPE";
    default: return "<invalid>";
  }
}

InlineVariableDefinitionKind FromPasta(pasta::InlineVariableDefinitionKind e) {
  switch (static_cast<int>(e)) {
    case 0: return InlineVariableDefinitionKind::NONE;
    case 1: return InlineVariableDefinitionKind::WEAK;
    case 2: return InlineVariableDefinitionKind::WEAK_UNKNOWN;
    case 3: return InlineVariableDefinitionKind::STRONG;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(InlineVariableDefinitionKind e) {
  switch (e) {
    case InlineVariableDefinitionKind::NONE: return "NONE";
    case InlineVariableDefinitionKind::WEAK: return "WEAK";
    case InlineVariableDefinitionKind::WEAK_UNKNOWN: return "WEAK_UNKNOWN";
    case InlineVariableDefinitionKind::STRONG: return "STRONG";
    default: return "<invalid>";
  }
}

InliningMethod FromPasta(pasta::InliningMethod e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InliningMethod::NORMAL_INLINING;
    case 1: return InliningMethod::ONLY_HINT_INLINING;
    case 2: return InliningMethod::ONLY_ALWAYS_INLINING;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(InliningMethod e) {
  switch (e) {
    case InliningMethod::NORMAL_INLINING: return "NORMAL_INLINING";
    case InliningMethod::ONLY_HINT_INLINING: return "ONLY_HINT_INLINING";
    case InliningMethod::ONLY_ALWAYS_INLINING: return "ONLY_ALWAYS_INLINING";
    default: return "<invalid>";
  }
}

InterruptType FromPasta(pasta::InterruptType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InterruptType::IRQ;
    case 1: return InterruptType::FIQ;
    case 2: return InterruptType::SWI;
    case 3: return InterruptType::ABORT;
    case 4: return InterruptType::UNDEF;
    case 5: return InterruptType::GENERIC;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(InterruptType e) {
  switch (e) {
    case InterruptType::IRQ: return "IRQ";
    case InterruptType::FIQ: return "FIQ";
    case InterruptType::SWI: return "SWI";
    case InterruptType::ABORT: return "ABORT";
    case InterruptType::UNDEF: return "UNDEF";
    case InterruptType::GENERIC: return "GENERIC";
    default: return "<invalid>";
  }
}

Kinds FromPasta(pasta::Kinds e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Kinds::L_VALUE;
    case 1: return Kinds::X_VALUE;
    case 2: return Kinds::FUNCTION;
    case 3: return Kinds::VOID;
    case 4: return Kinds::ADDRESSABLE_VOID;
    case 5: return Kinds::DUPLICATE_VECTOR_COMPONENTS;
    case 6: return Kinds::MEMBER_FUNCTION;
    case 7: return Kinds::SUB_OBJ_C_PROPERTY_SETTING;
    case 8: return Kinds::CLASS_TEMPORARY;
    case 9: return Kinds::ARRAY_TEMPORARY;
    case 10: return Kinds::OBJ_C_MESSAGE_R_VALUE;
    case 11: return Kinds::PR_VALUE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Kinds e) {
  switch (e) {
    case Kinds::L_VALUE: return "L_VALUE";
    case Kinds::X_VALUE: return "X_VALUE";
    case Kinds::FUNCTION: return "FUNCTION";
    case Kinds::VOID: return "VOID";
    case Kinds::ADDRESSABLE_VOID: return "ADDRESSABLE_VOID";
    case Kinds::DUPLICATE_VECTOR_COMPONENTS: return "DUPLICATE_VECTOR_COMPONENTS";
    case Kinds::MEMBER_FUNCTION: return "MEMBER_FUNCTION";
    case Kinds::SUB_OBJ_C_PROPERTY_SETTING: return "SUB_OBJ_C_PROPERTY_SETTING";
    case Kinds::CLASS_TEMPORARY: return "CLASS_TEMPORARY";
    case Kinds::ARRAY_TEMPORARY: return "ARRAY_TEMPORARY";
    case Kinds::OBJ_C_MESSAGE_R_VALUE: return "OBJ_C_MESSAGE_R_VALUE";
    case Kinds::PR_VALUE: return "PR_VALUE";
    default: return "<invalid>";
  }
}

LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LambdaCaptureDefault::NONE;
    case 1: return LambdaCaptureDefault::BY_COPY;
    case 2: return LambdaCaptureDefault::BY_REFERENCE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LambdaCaptureDefault e) {
  switch (e) {
    case LambdaCaptureDefault::NONE: return "NONE";
    case LambdaCaptureDefault::BY_COPY: return "BY_COPY";
    case LambdaCaptureDefault::BY_REFERENCE: return "BY_REFERENCE";
    default: return "<invalid>";
  }
}

LambdaCaptureKind FromPasta(pasta::LambdaCaptureKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LambdaCaptureKind::THIS;
    case 1: return LambdaCaptureKind::STAR_THIS;
    case 2: return LambdaCaptureKind::BY_COPY;
    case 3: return LambdaCaptureKind::BY_REFERENCE;
    case 4: return LambdaCaptureKind::VLA_TYPE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LambdaCaptureKind e) {
  switch (e) {
    case LambdaCaptureKind::THIS: return "THIS";
    case LambdaCaptureKind::STAR_THIS: return "STAR_THIS";
    case LambdaCaptureKind::BY_COPY: return "BY_COPY";
    case LambdaCaptureKind::BY_REFERENCE: return "BY_REFERENCE";
    case LambdaCaptureKind::VLA_TYPE: return "VLA_TYPE";
    default: return "<invalid>";
  }
}

LangAS FromPasta(pasta::LangAS e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LangAS::DEFAULT;
    case 1: return LangAS::OPENCL_GLOBAL;
    case 2: return LangAS::OPENCL_LOCAL;
    case 3: return LangAS::OPENCL_CONSTANT;
    case 4: return LangAS::OPENCL_PRIVATE;
    case 5: return LangAS::OPENCL_GENERIC;
    case 6: return LangAS::OPENCL_GLOBAL_DEVICE;
    case 7: return LangAS::OPENCL_GLOBAL_HOST;
    case 8: return LangAS::CUDA_DEVICE;
    case 9: return LangAS::CUDA_CONSTANT;
    case 10: return LangAS::CUDA_SHARED;
    case 11: return LangAS::SYCL_GLOBAL;
    case 12: return LangAS::SYCL_GLOBAL_DEVICE;
    case 13: return LangAS::SYCL_GLOBAL_HOST;
    case 14: return LangAS::SYCL_LOCAL;
    case 15: return LangAS::SYCL_PRIVATE;
    case 16: return LangAS::PTR32_SPTR;
    case 17: return LangAS::PTR32_UPTR;
    case 18: return LangAS::PTR64;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LangAS e) {
  switch (e) {
    case LangAS::DEFAULT: return "DEFAULT";
    case LangAS::OPENCL_GLOBAL: return "OPENCL_GLOBAL";
    case LangAS::OPENCL_LOCAL: return "OPENCL_LOCAL";
    case LangAS::OPENCL_CONSTANT: return "OPENCL_CONSTANT";
    case LangAS::OPENCL_PRIVATE: return "OPENCL_PRIVATE";
    case LangAS::OPENCL_GENERIC: return "OPENCL_GENERIC";
    case LangAS::OPENCL_GLOBAL_DEVICE: return "OPENCL_GLOBAL_DEVICE";
    case LangAS::OPENCL_GLOBAL_HOST: return "OPENCL_GLOBAL_HOST";
    case LangAS::CUDA_DEVICE: return "CUDA_DEVICE";
    case LangAS::CUDA_CONSTANT: return "CUDA_CONSTANT";
    case LangAS::CUDA_SHARED: return "CUDA_SHARED";
    case LangAS::SYCL_GLOBAL: return "SYCL_GLOBAL";
    case LangAS::SYCL_GLOBAL_DEVICE: return "SYCL_GLOBAL_DEVICE";
    case LangAS::SYCL_GLOBAL_HOST: return "SYCL_GLOBAL_HOST";
    case LangAS::SYCL_LOCAL: return "SYCL_LOCAL";
    case LangAS::SYCL_PRIVATE: return "SYCL_PRIVATE";
    case LangAS::PTR32_SPTR: return "PTR32_SPTR";
    case LangAS::PTR32_UPTR: return "PTR32_UPTR";
    case LangAS::PTR64: return "PTR64";
    default: return "<invalid>";
  }
}

LangFeatures FromPasta(pasta::LangFeatures e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return LangFeatures::LINE_COMMENT;
    case 2: return LangFeatures::C99;
    case 4: return LangFeatures::C11;
    case 8: return LangFeatures::C17;
    case 16: return LangFeatures::C2_X;
    case 32: return LangFeatures::C_PLUS_PLUS;
    case 64: return LangFeatures::C_PLUS_PLUS11;
    case 128: return LangFeatures::C_PLUS_PLUS14;
    case 256: return LangFeatures::C_PLUS_PLUS17;
    case 512: return LangFeatures::C_PLUS_PLUS20;
    case 1024: return LangFeatures::C_PLUS_PLUS2_B;
    case 2048: return LangFeatures::DIGRAPHS;
    case 4096: return LangFeatures::GNU_MODE;
    case 8192: return LangFeatures::HEX_FLOAT;
    case 16384: return LangFeatures::IMPLICIT_INT;
    case 32768: return LangFeatures::OPEN_CL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LangFeatures e) {
  switch (e) {
    case LangFeatures::LINE_COMMENT: return "LINE_COMMENT";
    case LangFeatures::C99: return "C99";
    case LangFeatures::C11: return "C11";
    case LangFeatures::C17: return "C17";
    case LangFeatures::C2_X: return "C2_X";
    case LangFeatures::C_PLUS_PLUS: return "C_PLUS_PLUS";
    case LangFeatures::C_PLUS_PLUS11: return "C_PLUS_PLUS11";
    case LangFeatures::C_PLUS_PLUS14: return "C_PLUS_PLUS14";
    case LangFeatures::C_PLUS_PLUS17: return "C_PLUS_PLUS17";
    case LangFeatures::C_PLUS_PLUS20: return "C_PLUS_PLUS20";
    case LangFeatures::C_PLUS_PLUS2_B: return "C_PLUS_PLUS2_B";
    case LangFeatures::DIGRAPHS: return "DIGRAPHS";
    case LangFeatures::GNU_MODE: return "GNU_MODE";
    case LangFeatures::HEX_FLOAT: return "HEX_FLOAT";
    case LangFeatures::IMPLICIT_INT: return "IMPLICIT_INT";
    case LangFeatures::OPEN_CL: return "OPEN_CL";
    default: return "<invalid>";
  }
}

Language FromPasta(pasta::Language e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return Language::UNKNOWN;
    case 1: return Language::ASSEMBLY;
    case 2: return Language::LLVMIR;
    case 3: return Language::C;
    case 4: return Language::CXX;
    case 5: return Language::OBJ_C;
    case 6: return Language::OBJ_CXX;
    case 7: return Language::OPEN_CL;
    case 8: return Language::OPEN_CLCXX;
    case 9: return Language::CUDA;
    case 10: return Language::RENDER_SCRIPT;
    case 11: return Language::HIP;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Language e) {
  switch (e) {
    case Language::UNKNOWN: return "UNKNOWN";
    case Language::ASSEMBLY: return "ASSEMBLY";
    case Language::LLVMIR: return "LLVMIR";
    case Language::C: return "C";
    case Language::CXX: return "CXX";
    case Language::OBJ_C: return "OBJ_C";
    case Language::OBJ_CXX: return "OBJ_CXX";
    case Language::OPEN_CL: return "OPEN_CL";
    case Language::OPEN_CLCXX: return "OPEN_CLCXX";
    case Language::CUDA: return "CUDA";
    case Language::RENDER_SCRIPT: return "RENDER_SCRIPT";
    case Language::HIP: return "HIP";
    default: return "<invalid>";
  }
}

LanguageLinkage FromPasta(pasta::LanguageLinkage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LanguageLinkage::C_LANGUAGE_LINKAGE;
    case 1: return LanguageLinkage::CXX_LANGUAGE_LINKAGE;
    case 2: return LanguageLinkage::NO_LANGUAGE_LINKAGE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LanguageLinkage e) {
  switch (e) {
    case LanguageLinkage::C_LANGUAGE_LINKAGE: return "C_LANGUAGE_LINKAGE";
    case LanguageLinkage::CXX_LANGUAGE_LINKAGE: return "CXX_LANGUAGE_LINKAGE";
    case LanguageLinkage::NO_LANGUAGE_LINKAGE: return "NO_LANGUAGE_LINKAGE";
    default: return "<invalid>";
  }
}

LaxVectorConversionKind FromPasta(pasta::LaxVectorConversionKind e) {
  switch (static_cast<int>(e)) {
    case 0: return LaxVectorConversionKind::NONE;
    case 1: return LaxVectorConversionKind::INTEGER;
    case 2: return LaxVectorConversionKind::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LaxVectorConversionKind e) {
  switch (e) {
    case LaxVectorConversionKind::NONE: return "NONE";
    case LaxVectorConversionKind::INTEGER: return "INTEGER";
    case LaxVectorConversionKind::ALL: return "ALL";
    default: return "<invalid>";
  }
}

Level FromPasta(pasta::Level e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Level::IGNORED;
    case 1: return Level::NOTE;
    case 2: return Level::REMARK;
    case 3: return Level::WARNING;
    case 4: return Level::ERROR;
    case 5: return Level::FATAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Level e) {
  switch (e) {
    case Level::IGNORED: return "IGNORED";
    case Level::NOTE: return "NOTE";
    case Level::REMARK: return "REMARK";
    case Level::WARNING: return "WARNING";
    case Level::ERROR: return "ERROR";
    case Level::FATAL: return "FATAL";
    default: return "<invalid>";
  }
}

Linkage FromPasta(pasta::Linkage e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return Linkage::NO_LINKAGE;
    case 1: return Linkage::INTERNAL_LINKAGE;
    case 2: return Linkage::UNIQUE_EXTERNAL_LINKAGE;
    case 3: return Linkage::VISIBLE_NO_LINKAGE;
    case 4: return Linkage::MODULE_INTERNAL_LINKAGE;
    case 5: return Linkage::MODULE_LINKAGE;
    case 6: return Linkage::EXTERNAL_LINKAGE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Linkage e) {
  switch (e) {
    case Linkage::NO_LINKAGE: return "NO_LINKAGE";
    case Linkage::INTERNAL_LINKAGE: return "INTERNAL_LINKAGE";
    case Linkage::UNIQUE_EXTERNAL_LINKAGE: return "UNIQUE_EXTERNAL_LINKAGE";
    case Linkage::VISIBLE_NO_LINKAGE: return "VISIBLE_NO_LINKAGE";
    case Linkage::MODULE_INTERNAL_LINKAGE: return "MODULE_INTERNAL_LINKAGE";
    case Linkage::MODULE_LINKAGE: return "MODULE_LINKAGE";
    case Linkage::EXTERNAL_LINKAGE: return "EXTERNAL_LINKAGE";
    default: return "<invalid>";
  }
}

LoopHintState FromPasta(pasta::LoopHintState e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LoopHintState::ENABLE;
    case 1: return LoopHintState::DISABLE;
    case 2: return LoopHintState::NUMERIC;
    case 3: return LoopHintState::FIXED_WIDTH;
    case 4: return LoopHintState::SCALABLE_WIDTH;
    case 5: return LoopHintState::ASSUME_SAFETY;
    case 6: return LoopHintState::FULL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(LoopHintState e) {
  switch (e) {
    case LoopHintState::ENABLE: return "ENABLE";
    case LoopHintState::DISABLE: return "DISABLE";
    case LoopHintState::NUMERIC: return "NUMERIC";
    case LoopHintState::FIXED_WIDTH: return "FIXED_WIDTH";
    case LoopHintState::SCALABLE_WIDTH: return "SCALABLE_WIDTH";
    case LoopHintState::ASSUME_SAFETY: return "ASSUME_SAFETY";
    case LoopHintState::FULL: return "FULL";
    default: return "<invalid>";
  }
}

MSInheritanceModel FromPasta(pasta::MSInheritanceModel e) {
  switch (static_cast<int>(e)) {
    case 0: return MSInheritanceModel::SINGLE;
    case 1: return MSInheritanceModel::MULTIPLE;
    case 2: return MSInheritanceModel::VIRTUAL;
    case 3: return MSInheritanceModel::UNSPECIFIED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(MSInheritanceModel e) {
  switch (e) {
    case MSInheritanceModel::SINGLE: return "SINGLE";
    case MSInheritanceModel::MULTIPLE: return "MULTIPLE";
    case MSInheritanceModel::VIRTUAL: return "VIRTUAL";
    case MSInheritanceModel::UNSPECIFIED: return "UNSPECIFIED";
    default: return "<invalid>";
  }
}

MSVCMajorVersion FromPasta(pasta::MSVCMajorVersion e) {
  switch (static_cast<unsigned>(e)) {
    case 1600: return MSVCMajorVersion::MSVC2010;
    case 1700: return MSVCMajorVersion::MSVC2012;
    case 1800: return MSVCMajorVersion::MSVC2013;
    case 1900: return MSVCMajorVersion::MSVC2015;
    case 1910: return MSVCMajorVersion::MSVC2017;
    case 1912: return MSVCMajorVersion::MSVC20175;
    case 1914: return MSVCMajorVersion::MSVC20177;
    case 1920: return MSVCMajorVersion::MSVC2019;
    case 1928: return MSVCMajorVersion::MSVC20198;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(MSVCMajorVersion e) {
  switch (e) {
    case MSVCMajorVersion::MSVC2010: return "MSVC2010";
    case MSVCMajorVersion::MSVC2012: return "MSVC2012";
    case MSVCMajorVersion::MSVC2013: return "MSVC2013";
    case MSVCMajorVersion::MSVC2015: return "MSVC2015";
    case MSVCMajorVersion::MSVC2017: return "MSVC2017";
    case MSVCMajorVersion::MSVC20175: return "MSVC20175";
    case MSVCMajorVersion::MSVC20177: return "MSVC20177";
    case MSVCMajorVersion::MSVC2019: return "MSVC2019";
    case MSVCMajorVersion::MSVC20198: return "MSVC20198";
    default: return "<invalid>";
  }
}

MSVtorDispMode FromPasta(pasta::MSVtorDispMode e) {
  switch (static_cast<int>(e)) {
    case 0: return MSVtorDispMode::NEVER;
    case 1: return MSVtorDispMode::FOR_VIRTUAL_BASE_OVERRIDE;
    case 2: return MSVtorDispMode::FOR_VF_TABLE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(MSVtorDispMode e) {
  switch (e) {
    case MSVtorDispMode::NEVER: return "NEVER";
    case MSVtorDispMode::FOR_VIRTUAL_BASE_OVERRIDE: return "FOR_VIRTUAL_BASE_OVERRIDE";
    case MSVtorDispMode::FOR_VF_TABLE: return "FOR_VF_TABLE";
    default: return "<invalid>";
  }
}

MapTypeTy FromPasta(pasta::MapTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MapTypeTy::TO;
    case 1: return MapTypeTy::LINK;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(MapTypeTy e) {
  switch (e) {
    case MapTypeTy::TO: return "TO";
    case MapTypeTy::LINK: return "LINK";
    default: return "<invalid>";
  }
}

MethodRefFlags FromPasta(pasta::MethodRefFlags e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MethodRefFlags::METHOD_REFERENCE_NONE;
    case 1: return MethodRefFlags::METHOD_REFERENCE_GETTER;
    case 2: return MethodRefFlags::METHOD_REFERENCE_SETTER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(MethodRefFlags e) {
  switch (e) {
    case MethodRefFlags::METHOD_REFERENCE_NONE: return "METHOD_REFERENCE_NONE";
    case MethodRefFlags::METHOD_REFERENCE_GETTER: return "METHOD_REFERENCE_GETTER";
    case MethodRefFlags::METHOD_REFERENCE_SETTER: return "METHOD_REFERENCE_SETTER";
    default: return "<invalid>";
  }
}

ModifiableType FromPasta(pasta::ModifiableType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ModifiableType::UNTESTED;
    case 1: return ModifiableType::MODIFIABLE;
    case 2: return ModifiableType::R_VALUE;
    case 3: return ModifiableType::FUNCTION;
    case 4: return ModifiableType::L_VALUE_CAST;
    case 5: return ModifiableType::NO_SETTER_PROPERTY;
    case 6: return ModifiableType::CONST_QUALIFIED;
    case 7: return ModifiableType::CONST_QUALIFIED_FIELD;
    case 8: return ModifiableType::CONST_ADDR_SPACE;
    case 9: return ModifiableType::ARRAY_TYPE;
    case 10: return ModifiableType::INCOMPLETE_TYPE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ModifiableType e) {
  switch (e) {
    case ModifiableType::UNTESTED: return "UNTESTED";
    case ModifiableType::MODIFIABLE: return "MODIFIABLE";
    case ModifiableType::R_VALUE: return "R_VALUE";
    case ModifiableType::FUNCTION: return "FUNCTION";
    case ModifiableType::L_VALUE_CAST: return "L_VALUE_CAST";
    case ModifiableType::NO_SETTER_PROPERTY: return "NO_SETTER_PROPERTY";
    case ModifiableType::CONST_QUALIFIED: return "CONST_QUALIFIED";
    case ModifiableType::CONST_QUALIFIED_FIELD: return "CONST_QUALIFIED_FIELD";
    case ModifiableType::CONST_ADDR_SPACE: return "CONST_ADDR_SPACE";
    case ModifiableType::ARRAY_TYPE: return "ARRAY_TYPE";
    case ModifiableType::INCOMPLETE_TYPE: return "INCOMPLETE_TYPE";
    default: return "<invalid>";
  }
}

MultiVersionKind FromPasta(pasta::MultiVersionKind e) {
  switch (static_cast<int>(e)) {
    case 0: return MultiVersionKind::NONE;
    case 1: return MultiVersionKind::TARGET;
    case 2: return MultiVersionKind::CPU_SPECIFIC;
    case 3: return MultiVersionKind::CPU_DISPATCH;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(MultiVersionKind e) {
  switch (e) {
    case MultiVersionKind::NONE: return "NONE";
    case MultiVersionKind::TARGET: return "TARGET";
    case MultiVersionKind::CPU_SPECIFIC: return "CPU_SPECIFIC";
    case MultiVersionKind::CPU_DISPATCH: return "CPU_DISPATCH";
    default: return "<invalid>";
  }
}

NameKind FromPasta(pasta::NameKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NameKind::TEMPLATE;
    case 1: return NameKind::OVERLOADED_TEMPLATE;
    case 2: return NameKind::ASSUMED_TEMPLATE;
    case 3: return NameKind::QUALIFIED_TEMPLATE;
    case 4: return NameKind::DEPENDENT_TEMPLATE;
    case 5: return NameKind::SUBST_TEMPLATE_TEMPLATE_PARM;
    case 6: return NameKind::SUBST_TEMPLATE_TEMPLATE_PARM_PACK;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NameKind e) {
  switch (e) {
    case NameKind::TEMPLATE: return "TEMPLATE";
    case NameKind::OVERLOADED_TEMPLATE: return "OVERLOADED_TEMPLATE";
    case NameKind::ASSUMED_TEMPLATE: return "ASSUMED_TEMPLATE";
    case NameKind::QUALIFIED_TEMPLATE: return "QUALIFIED_TEMPLATE";
    case NameKind::DEPENDENT_TEMPLATE: return "DEPENDENT_TEMPLATE";
    case NameKind::SUBST_TEMPLATE_TEMPLATE_PARM: return "SUBST_TEMPLATE_TEMPLATE_PARM";
    case NameKind::SUBST_TEMPLATE_TEMPLATE_PARM_PACK: return "SUBST_TEMPLATE_TEMPLATE_PARM_PACK";
    default: return "<invalid>";
  }
}

NeedExtraManglingDecl FromPasta(pasta::NeedExtraManglingDecl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NeedExtraManglingDecl::NEED_EXTRA_MANGLING_DECLARATION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NeedExtraManglingDecl e) {
  switch (e) {
    case NeedExtraManglingDecl::NEED_EXTRA_MANGLING_DECLARATION: return "NEED_EXTRA_MANGLING_DECLARATION";
    default: return "<invalid>";
  }
}

NestedNameSpecifierDependence FromPasta(pasta::NestedNameSpecifierDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return NestedNameSpecifierDependence::UNEXPANDED_PACK;
    case 2: return NestedNameSpecifierDependence::INSTANTIATION;
    case 4: return NestedNameSpecifierDependence::DEPENDENT;
    case 8: return NestedNameSpecifierDependence::ERROR;
    case 0: return NestedNameSpecifierDependence::NONE;
    case 6: return NestedNameSpecifierDependence::DEPENDENT_INSTANTIATION;
    case 15: return NestedNameSpecifierDependence::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NestedNameSpecifierDependence e) {
  switch (e) {
    case NestedNameSpecifierDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case NestedNameSpecifierDependence::INSTANTIATION: return "INSTANTIATION";
    case NestedNameSpecifierDependence::DEPENDENT: return "DEPENDENT";
    case NestedNameSpecifierDependence::ERROR: return "ERROR";
    case NestedNameSpecifierDependence::NONE: return "NONE";
    case NestedNameSpecifierDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    case NestedNameSpecifierDependence::ALL: return "ALL";
    default: return "<invalid>";
  }
}

NewtypeKind FromPasta(pasta::NewtypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NewtypeKind::STRUCT;
    case 1: return NewtypeKind::ENUM;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NewtypeKind e) {
  switch (e) {
    case NewtypeKind::STRUCT: return "STRUCT";
    case NewtypeKind::ENUM: return "ENUM";
    default: return "<invalid>";
  }
}

NonOdrUseReason FromPasta(pasta::NonOdrUseReason e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NonOdrUseReason::NONE;
    case 1: return NonOdrUseReason::UNEVALUATED;
    case 2: return NonOdrUseReason::CONSTANT;
    case 3: return NonOdrUseReason::DISCARDED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NonOdrUseReason e) {
  switch (e) {
    case NonOdrUseReason::NONE: return "NONE";
    case NonOdrUseReason::UNEVALUATED: return "UNEVALUATED";
    case NonOdrUseReason::CONSTANT: return "CONSTANT";
    case NonOdrUseReason::DISCARDED: return "DISCARDED";
    default: return "<invalid>";
  }
}

NonceObjCInterface FromPasta(pasta::NonceObjCInterface e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NonceObjCInterface::OBJ_C_INTERFACE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NonceObjCInterface e) {
  switch (e) {
    case NonceObjCInterface::OBJ_C_INTERFACE: return "OBJ_C_INTERFACE";
    default: return "<invalid>";
  }
}

NullabilityKind FromPasta(pasta::NullabilityKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return NullabilityKind::NON_NULL;
    case 1: return NullabilityKind::NULLABLE;
    case 2: return NullabilityKind::UNSPECIFIED;
    case 3: return NullabilityKind::NULLABLE_RESULT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(NullabilityKind e) {
  switch (e) {
    case NullabilityKind::NON_NULL: return "NON_NULL";
    case NullabilityKind::NULLABLE: return "NULLABLE";
    case NullabilityKind::UNSPECIFIED: return "UNSPECIFIED";
    case NullabilityKind::NULLABLE_RESULT: return "NULLABLE_RESULT";
    default: return "<invalid>";
  }
}

ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCBridgeCastKind::BRIDGE;
    case 1: return ObjCBridgeCastKind::BRIDGE_TRANSFER;
    case 2: return ObjCBridgeCastKind::BRIDGE_RETAINED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCBridgeCastKind e) {
  switch (e) {
    case ObjCBridgeCastKind::BRIDGE: return "BRIDGE";
    case ObjCBridgeCastKind::BRIDGE_TRANSFER: return "BRIDGE_TRANSFER";
    case ObjCBridgeCastKind::BRIDGE_RETAINED: return "BRIDGE_RETAINED";
    default: return "<invalid>";
  }
}

ObjCDispatchMethodKind FromPasta(pasta::ObjCDispatchMethodKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCDispatchMethodKind::LEGACY;
    case 1: return ObjCDispatchMethodKind::NON_LEGACY;
    case 2: return ObjCDispatchMethodKind::MIXED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCDispatchMethodKind e) {
  switch (e) {
    case ObjCDispatchMethodKind::LEGACY: return "LEGACY";
    case ObjCDispatchMethodKind::NON_LEGACY: return "NON_LEGACY";
    case ObjCDispatchMethodKind::MIXED: return "MIXED";
    default: return "<invalid>";
  }
}

ObjCInstanceTypeFamily FromPasta(pasta::ObjCInstanceTypeFamily e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCInstanceTypeFamily::NONE;
    case 1: return ObjCInstanceTypeFamily::ARRAY;
    case 2: return ObjCInstanceTypeFamily::DICTIONARY;
    case 3: return ObjCInstanceTypeFamily::SINGLETON;
    case 4: return ObjCInstanceTypeFamily::INITIALIZER;
    case 5: return ObjCInstanceTypeFamily::RETURNS_SELF;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCInstanceTypeFamily e) {
  switch (e) {
    case ObjCInstanceTypeFamily::NONE: return "NONE";
    case ObjCInstanceTypeFamily::ARRAY: return "ARRAY";
    case ObjCInstanceTypeFamily::DICTIONARY: return "DICTIONARY";
    case ObjCInstanceTypeFamily::SINGLETON: return "SINGLETON";
    case ObjCInstanceTypeFamily::INITIALIZER: return "INITIALIZER";
    case ObjCInstanceTypeFamily::RETURNS_SELF: return "RETURNS_SELF";
    default: return "<invalid>";
  }
}

ObjCKeywordKind FromPasta(pasta::ObjCKeywordKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCKeywordKind::NOT_KEYWORD;
    case 1: return ObjCKeywordKind::CLASS;
    case 2: return ObjCKeywordKind::COMPATIBILITY_ALIAS;
    case 3: return ObjCKeywordKind::DEFINITIONS;
    case 4: return ObjCKeywordKind::ENCODE;
    case 5: return ObjCKeywordKind::OBJC_END;
    case 6: return ObjCKeywordKind::IMPLEMENTATION;
    case 7: return ObjCKeywordKind::INTERFACE;
    case 8: return ObjCKeywordKind::PRIVATE;
    case 9: return ObjCKeywordKind::PROTECTED;
    case 10: return ObjCKeywordKind::PROTOCOL;
    case 11: return ObjCKeywordKind::PUBLIC;
    case 12: return ObjCKeywordKind::SELECTOR;
    case 13: return ObjCKeywordKind::THROW;
    case 14: return ObjCKeywordKind::TRY;
    case 15: return ObjCKeywordKind::CATCH;
    case 16: return ObjCKeywordKind::FINALLY;
    case 17: return ObjCKeywordKind::SYNCHRONIZED;
    case 18: return ObjCKeywordKind::AUTORELEASEPOOL;
    case 19: return ObjCKeywordKind::PROPERTY;
    case 20: return ObjCKeywordKind::PACKAGE;
    case 21: return ObjCKeywordKind::REQUIRED;
    case 22: return ObjCKeywordKind::OPTIONAL;
    case 23: return ObjCKeywordKind::SYNTHESIZE;
    case 24: return ObjCKeywordKind::DYNAMIC;
    case 25: return ObjCKeywordKind::IMPORT;
    case 26: return ObjCKeywordKind::AVAILABLE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCKeywordKind e) {
  switch (e) {
    case ObjCKeywordKind::NOT_KEYWORD: return "NOT_KEYWORD";
    case ObjCKeywordKind::CLASS: return "CLASS";
    case ObjCKeywordKind::COMPATIBILITY_ALIAS: return "COMPATIBILITY_ALIAS";
    case ObjCKeywordKind::DEFINITIONS: return "DEFINITIONS";
    case ObjCKeywordKind::ENCODE: return "ENCODE";
    case ObjCKeywordKind::OBJC_END: return "OBJC_END";
    case ObjCKeywordKind::IMPLEMENTATION: return "IMPLEMENTATION";
    case ObjCKeywordKind::INTERFACE: return "INTERFACE";
    case ObjCKeywordKind::PRIVATE: return "PRIVATE";
    case ObjCKeywordKind::PROTECTED: return "PROTECTED";
    case ObjCKeywordKind::PROTOCOL: return "PROTOCOL";
    case ObjCKeywordKind::PUBLIC: return "PUBLIC";
    case ObjCKeywordKind::SELECTOR: return "SELECTOR";
    case ObjCKeywordKind::THROW: return "THROW";
    case ObjCKeywordKind::TRY: return "TRY";
    case ObjCKeywordKind::CATCH: return "CATCH";
    case ObjCKeywordKind::FINALLY: return "FINALLY";
    case ObjCKeywordKind::SYNCHRONIZED: return "SYNCHRONIZED";
    case ObjCKeywordKind::AUTORELEASEPOOL: return "AUTORELEASEPOOL";
    case ObjCKeywordKind::PROPERTY: return "PROPERTY";
    case ObjCKeywordKind::PACKAGE: return "PACKAGE";
    case ObjCKeywordKind::REQUIRED: return "REQUIRED";
    case ObjCKeywordKind::OPTIONAL: return "OPTIONAL";
    case ObjCKeywordKind::SYNTHESIZE: return "SYNTHESIZE";
    case ObjCKeywordKind::DYNAMIC: return "DYNAMIC";
    case ObjCKeywordKind::IMPORT: return "IMPORT";
    case ObjCKeywordKind::AVAILABLE: return "AVAILABLE";
    default: return "<invalid>";
  }
}

ObjCLifetime FromPasta(pasta::ObjCLifetime e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCLifetime::NONE;
    case 1: return ObjCLifetime::EXPLICIT_NONE;
    case 2: return ObjCLifetime::STRONG;
    case 3: return ObjCLifetime::WEAK;
    case 4: return ObjCLifetime::AUTORELEASING;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCLifetime e) {
  switch (e) {
    case ObjCLifetime::NONE: return "NONE";
    case ObjCLifetime::EXPLICIT_NONE: return "EXPLICIT_NONE";
    case ObjCLifetime::STRONG: return "STRONG";
    case ObjCLifetime::WEAK: return "WEAK";
    case ObjCLifetime::AUTORELEASING: return "AUTORELEASING";
    default: return "<invalid>";
  }
}

ObjCMethodFamily FromPasta(pasta::ObjCMethodFamily e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMethodFamily::NONE;
    case 1: return ObjCMethodFamily::ALLOC;
    case 2: return ObjCMethodFamily::COPY;
    case 3: return ObjCMethodFamily::INITIALIZER;
    case 4: return ObjCMethodFamily::MUTABLE_COPY;
    case 5: return ObjCMethodFamily::NEW;
    case 6: return ObjCMethodFamily::AUTORELEASE;
    case 7: return ObjCMethodFamily::DEALLOC;
    case 8: return ObjCMethodFamily::FINALIZE;
    case 9: return ObjCMethodFamily::RELEASE;
    case 10: return ObjCMethodFamily::RETAIN;
    case 11: return ObjCMethodFamily::RETAIN_COUNT;
    case 12: return ObjCMethodFamily::SELF;
    case 13: return ObjCMethodFamily::INITIALIZE;
    case 14: return ObjCMethodFamily::PERFORM_SELECTOR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCMethodFamily e) {
  switch (e) {
    case ObjCMethodFamily::NONE: return "NONE";
    case ObjCMethodFamily::ALLOC: return "ALLOC";
    case ObjCMethodFamily::COPY: return "COPY";
    case ObjCMethodFamily::INITIALIZER: return "INITIALIZER";
    case ObjCMethodFamily::MUTABLE_COPY: return "MUTABLE_COPY";
    case ObjCMethodFamily::NEW: return "NEW";
    case ObjCMethodFamily::AUTORELEASE: return "AUTORELEASE";
    case ObjCMethodFamily::DEALLOC: return "DEALLOC";
    case ObjCMethodFamily::FINALIZE: return "FINALIZE";
    case ObjCMethodFamily::RELEASE: return "RELEASE";
    case ObjCMethodFamily::RETAIN: return "RETAIN";
    case ObjCMethodFamily::RETAIN_COUNT: return "RETAIN_COUNT";
    case ObjCMethodFamily::SELF: return "SELF";
    case ObjCMethodFamily::INITIALIZE: return "INITIALIZE";
    case ObjCMethodFamily::PERFORM_SELECTOR: return "PERFORM_SELECTOR";
    default: return "<invalid>";
  }
}

ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ObjCPropertyQueryKind::QUERY_UNKNOWN;
    case 1: return ObjCPropertyQueryKind::QUERY_INSTANCE;
    case 2: return ObjCPropertyQueryKind::QUERY_CLASS;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCPropertyQueryKind e) {
  switch (e) {
    case ObjCPropertyQueryKind::QUERY_UNKNOWN: return "QUERY_UNKNOWN";
    case ObjCPropertyQueryKind::QUERY_INSTANCE: return "QUERY_INSTANCE";
    case ObjCPropertyQueryKind::QUERY_CLASS: return "QUERY_CLASS";
    default: return "<invalid>";
  }
}

ObjCStringFormatFamily FromPasta(pasta::ObjCStringFormatFamily e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCStringFormatFamily::NONE;
    case 1: return ObjCStringFormatFamily::NS_STRING;
    case 2: return ObjCStringFormatFamily::CF_STRING;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCStringFormatFamily e) {
  switch (e) {
    case ObjCStringFormatFamily::NONE: return "NONE";
    case ObjCStringFormatFamily::NS_STRING: return "NS_STRING";
    case ObjCStringFormatFamily::CF_STRING: return "CF_STRING";
    default: return "<invalid>";
  }
}

ObjCSubstitutionContext FromPasta(pasta::ObjCSubstitutionContext e) {
  switch (static_cast<int>(e)) {
    case 0: return ObjCSubstitutionContext::ORDINARY;
    case 1: return ObjCSubstitutionContext::RESULT;
    case 2: return ObjCSubstitutionContext::PARAMETER;
    case 3: return ObjCSubstitutionContext::PROPERTY;
    case 4: return ObjCSubstitutionContext::SUPERCLASS;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCSubstitutionContext e) {
  switch (e) {
    case ObjCSubstitutionContext::ORDINARY: return "ORDINARY";
    case ObjCSubstitutionContext::RESULT: return "RESULT";
    case ObjCSubstitutionContext::PARAMETER: return "PARAMETER";
    case ObjCSubstitutionContext::PROPERTY: return "PROPERTY";
    case ObjCSubstitutionContext::SUPERCLASS: return "SUPERCLASS";
    default: return "<invalid>";
  }
}

ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ObjCTypeParamVariance::INVARIANT;
    case 1: return ObjCTypeParamVariance::COVARIANT;
    case 2: return ObjCTypeParamVariance::CONTRAVARIANT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ObjCTypeParamVariance e) {
  switch (e) {
    case ObjCTypeParamVariance::INVARIANT: return "INVARIANT";
    case ObjCTypeParamVariance::COVARIANT: return "COVARIANT";
    case ObjCTypeParamVariance::CONTRAVARIANT: return "CONTRAVARIANT";
    default: return "<invalid>";
  }
}

OnOffSwitch FromPasta(pasta::OnOffSwitch e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OnOffSwitch::ON;
    case 1: return OnOffSwitch::OFF;
    case 2: return OnOffSwitch::DEFAULT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OnOffSwitch e) {
  switch (e) {
    case OnOffSwitch::ON: return "ON";
    case OnOffSwitch::OFF: return "OFF";
    case OnOffSwitch::DEFAULT: return "DEFAULT";
    default: return "<invalid>";
  }
}

OnStackType FromPasta(pasta::OnStackType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OnStackType::ON_STACK;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OnStackType e) {
  switch (e) {
    case OnStackType::ON_STACK: return "ON_STACK";
    default: return "<invalid>";
  }
}

OpenMPAtomicDefaultMemOrderClauseKind FromPasta(pasta::OpenMPAtomicDefaultMemOrderClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPAtomicDefaultMemOrderClauseKind::SEQ_CST;
    case 1: return OpenMPAtomicDefaultMemOrderClauseKind::ACQ_REL;
    case 2: return OpenMPAtomicDefaultMemOrderClauseKind::RELAXED;
    case 3: return OpenMPAtomicDefaultMemOrderClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPAtomicDefaultMemOrderClauseKind e) {
  switch (e) {
    case OpenMPAtomicDefaultMemOrderClauseKind::SEQ_CST: return "SEQ_CST";
    case OpenMPAtomicDefaultMemOrderClauseKind::ACQ_REL: return "ACQ_REL";
    case OpenMPAtomicDefaultMemOrderClauseKind::RELAXED: return "RELAXED";
    case OpenMPAtomicDefaultMemOrderClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPDefaultmapClauseKind FromPasta(pasta::OpenMPDefaultmapClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDefaultmapClauseKind::SCALAR;
    case 1: return OpenMPDefaultmapClauseKind::AGGREGATE;
    case 2: return OpenMPDefaultmapClauseKind::POINTER;
    case 3: return OpenMPDefaultmapClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPDefaultmapClauseKind e) {
  switch (e) {
    case OpenMPDefaultmapClauseKind::SCALAR: return "SCALAR";
    case OpenMPDefaultmapClauseKind::AGGREGATE: return "AGGREGATE";
    case OpenMPDefaultmapClauseKind::POINTER: return "POINTER";
    case OpenMPDefaultmapClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPDefaultmapClauseModifier FromPasta(pasta::OpenMPDefaultmapClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 3: return OpenMPDefaultmapClauseModifier::UNKNOWN;
    case 4: return OpenMPDefaultmapClauseModifier::ALLOC;
    case 5: return OpenMPDefaultmapClauseModifier::TO;
    case 6: return OpenMPDefaultmapClauseModifier::FROM;
    case 7: return OpenMPDefaultmapClauseModifier::TOFROM;
    case 9: return OpenMPDefaultmapClauseModifier::NONE;
    case 10: return OpenMPDefaultmapClauseModifier::DEFAULT;
    case 11: return OpenMPDefaultmapClauseModifier::PRESENT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPDefaultmapClauseModifier e) {
  switch (e) {
    case OpenMPDefaultmapClauseModifier::UNKNOWN: return "UNKNOWN";
    case OpenMPDefaultmapClauseModifier::ALLOC: return "ALLOC";
    case OpenMPDefaultmapClauseModifier::TO: return "TO";
    case OpenMPDefaultmapClauseModifier::FROM: return "FROM";
    case OpenMPDefaultmapClauseModifier::TOFROM: return "TOFROM";
    case OpenMPDefaultmapClauseModifier::NONE: return "NONE";
    case OpenMPDefaultmapClauseModifier::DEFAULT: return "DEFAULT";
    case OpenMPDefaultmapClauseModifier::PRESENT: return "PRESENT";
    default: return "<invalid>";
  }
}

OpenMPDependClauseKind FromPasta(pasta::OpenMPDependClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDependClauseKind::IN;
    case 1: return OpenMPDependClauseKind::OUT;
    case 2: return OpenMPDependClauseKind::INOUT;
    case 3: return OpenMPDependClauseKind::MUTEXINOUTSET;
    case 4: return OpenMPDependClauseKind::DEPOBJ;
    case 5: return OpenMPDependClauseKind::SOURCE;
    case 6: return OpenMPDependClauseKind::SINK;
    case 7: return OpenMPDependClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPDependClauseKind e) {
  switch (e) {
    case OpenMPDependClauseKind::IN: return "IN";
    case OpenMPDependClauseKind::OUT: return "OUT";
    case OpenMPDependClauseKind::INOUT: return "INOUT";
    case OpenMPDependClauseKind::MUTEXINOUTSET: return "MUTEXINOUTSET";
    case OpenMPDependClauseKind::DEPOBJ: return "DEPOBJ";
    case OpenMPDependClauseKind::SOURCE: return "SOURCE";
    case OpenMPDependClauseKind::SINK: return "SINK";
    case OpenMPDependClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPDeviceClauseModifier FromPasta(pasta::OpenMPDeviceClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDeviceClauseModifier::ANCESTOR;
    case 1: return OpenMPDeviceClauseModifier::DEVICE_NUM;
    case 2: return OpenMPDeviceClauseModifier::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPDeviceClauseModifier e) {
  switch (e) {
    case OpenMPDeviceClauseModifier::ANCESTOR: return "ANCESTOR";
    case OpenMPDeviceClauseModifier::DEVICE_NUM: return "DEVICE_NUM";
    case OpenMPDeviceClauseModifier::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPDeviceType FromPasta(pasta::OpenMPDeviceType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDeviceType::HOST;
    case 1: return OpenMPDeviceType::NOHOST;
    case 2: return OpenMPDeviceType::ANY;
    case 3: return OpenMPDeviceType::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPDeviceType e) {
  switch (e) {
    case OpenMPDeviceType::HOST: return "HOST";
    case OpenMPDeviceType::NOHOST: return "NOHOST";
    case OpenMPDeviceType::ANY: return "ANY";
    case OpenMPDeviceType::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPDistScheduleClauseKind FromPasta(pasta::OpenMPDistScheduleClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDistScheduleClauseKind::STATIC;
    case 1: return OpenMPDistScheduleClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPDistScheduleClauseKind e) {
  switch (e) {
    case OpenMPDistScheduleClauseKind::STATIC: return "STATIC";
    case OpenMPDistScheduleClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPLastprivateModifier FromPasta(pasta::OpenMPLastprivateModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPLastprivateModifier::CONDITIONAL;
    case 1: return OpenMPLastprivateModifier::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPLastprivateModifier e) {
  switch (e) {
    case OpenMPLastprivateModifier::CONDITIONAL: return "CONDITIONAL";
    case OpenMPLastprivateModifier::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPLinearClauseKind FromPasta(pasta::OpenMPLinearClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPLinearClauseKind::VALUE;
    case 1: return OpenMPLinearClauseKind::REFERENCE;
    case 2: return OpenMPLinearClauseKind::UVAL;
    case 3: return OpenMPLinearClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPLinearClauseKind e) {
  switch (e) {
    case OpenMPLinearClauseKind::VALUE: return "VALUE";
    case OpenMPLinearClauseKind::REFERENCE: return "REFERENCE";
    case OpenMPLinearClauseKind::UVAL: return "UVAL";
    case OpenMPLinearClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPMapClauseKind FromPasta(pasta::OpenMPMapClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPMapClauseKind::ALLOC;
    case 1: return OpenMPMapClauseKind::TO;
    case 2: return OpenMPMapClauseKind::FROM;
    case 3: return OpenMPMapClauseKind::TOFROM;
    case 4: return OpenMPMapClauseKind::DELETE;
    case 5: return OpenMPMapClauseKind::RELEASE;
    case 6: return OpenMPMapClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPMapClauseKind e) {
  switch (e) {
    case OpenMPMapClauseKind::ALLOC: return "ALLOC";
    case OpenMPMapClauseKind::TO: return "TO";
    case OpenMPMapClauseKind::FROM: return "FROM";
    case OpenMPMapClauseKind::TOFROM: return "TOFROM";
    case OpenMPMapClauseKind::DELETE: return "DELETE";
    case OpenMPMapClauseKind::RELEASE: return "RELEASE";
    case OpenMPMapClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPMapModifierKind FromPasta(pasta::OpenMPMapModifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 6: return OpenMPMapModifierKind::UNKNOWN;
    case 7: return OpenMPMapModifierKind::ALWAYS;
    case 8: return OpenMPMapModifierKind::CLOSE;
    case 9: return OpenMPMapModifierKind::MAPPER;
    case 10: return OpenMPMapModifierKind::PRESENT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPMapModifierKind e) {
  switch (e) {
    case OpenMPMapModifierKind::UNKNOWN: return "UNKNOWN";
    case OpenMPMapModifierKind::ALWAYS: return "ALWAYS";
    case OpenMPMapModifierKind::CLOSE: return "CLOSE";
    case OpenMPMapModifierKind::MAPPER: return "MAPPER";
    case OpenMPMapModifierKind::PRESENT: return "PRESENT";
    default: return "<invalid>";
  }
}

OpenMPMotionModifierKind FromPasta(pasta::OpenMPMotionModifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPMotionModifierKind::MOTIONMODIFIER_MAPPER;
    case 1: return OpenMPMotionModifierKind::MOTIONMODIFIER_PRESENT;
    case 2: return OpenMPMotionModifierKind::MOTIONMODIFIER_UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPMotionModifierKind e) {
  switch (e) {
    case OpenMPMotionModifierKind::MOTIONMODIFIER_MAPPER: return "MOTIONMODIFIER_MAPPER";
    case OpenMPMotionModifierKind::MOTIONMODIFIER_PRESENT: return "MOTIONMODIFIER_PRESENT";
    case OpenMPMotionModifierKind::MOTIONMODIFIER_UNKNOWN: return "MOTIONMODIFIER_UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPOrderClauseKind FromPasta(pasta::OpenMPOrderClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPOrderClauseKind::CONCURRENT;
    case 1: return OpenMPOrderClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPOrderClauseKind e) {
  switch (e) {
    case OpenMPOrderClauseKind::CONCURRENT: return "CONCURRENT";
    case OpenMPOrderClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPReductionClauseModifier FromPasta(pasta::OpenMPReductionClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPReductionClauseModifier::DEFAULT;
    case 1: return OpenMPReductionClauseModifier::INSCAN;
    case 2: return OpenMPReductionClauseModifier::TASK;
    case 3: return OpenMPReductionClauseModifier::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPReductionClauseModifier e) {
  switch (e) {
    case OpenMPReductionClauseModifier::DEFAULT: return "DEFAULT";
    case OpenMPReductionClauseModifier::INSCAN: return "INSCAN";
    case OpenMPReductionClauseModifier::TASK: return "TASK";
    case OpenMPReductionClauseModifier::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPScheduleClauseKind FromPasta(pasta::OpenMPScheduleClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPScheduleClauseKind::STATIC;
    case 1: return OpenMPScheduleClauseKind::DYNAMIC;
    case 2: return OpenMPScheduleClauseKind::GUIDED;
    case 3: return OpenMPScheduleClauseKind::AUTO;
    case 4: return OpenMPScheduleClauseKind::RUNTIME;
    case 5: return OpenMPScheduleClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPScheduleClauseKind e) {
  switch (e) {
    case OpenMPScheduleClauseKind::STATIC: return "STATIC";
    case OpenMPScheduleClauseKind::DYNAMIC: return "DYNAMIC";
    case OpenMPScheduleClauseKind::GUIDED: return "GUIDED";
    case OpenMPScheduleClauseKind::AUTO: return "AUTO";
    case OpenMPScheduleClauseKind::RUNTIME: return "RUNTIME";
    case OpenMPScheduleClauseKind::UNKNOWN: return "UNKNOWN";
    default: return "<invalid>";
  }
}

OpenMPScheduleClauseModifier FromPasta(pasta::OpenMPScheduleClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 5: return OpenMPScheduleClauseModifier::UNKNOWN;
    case 6: return OpenMPScheduleClauseModifier::MONOTONIC;
    case 7: return OpenMPScheduleClauseModifier::NONMONOTONIC;
    case 8: return OpenMPScheduleClauseModifier::SIMD;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OpenMPScheduleClauseModifier e) {
  switch (e) {
    case OpenMPScheduleClauseModifier::UNKNOWN: return "UNKNOWN";
    case OpenMPScheduleClauseModifier::MONOTONIC: return "MONOTONIC";
    case OpenMPScheduleClauseModifier::NONMONOTONIC: return "NONMONOTONIC";
    case OpenMPScheduleClauseModifier::SIMD: return "SIMD";
    default: return "<invalid>";
  }
}

OptionType FromPasta(pasta::OptionType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OptionType::VECTORIZE;
    case 1: return OptionType::VECTORIZE_WIDTH;
    case 2: return OptionType::INTERLEAVE;
    case 3: return OptionType::INTERLEAVE_COUNT;
    case 4: return OptionType::UNROLL;
    case 5: return OptionType::UNROLL_COUNT;
    case 6: return OptionType::UNROLL_AND_JAM;
    case 7: return OptionType::UNROLL_AND_JAM_COUNT;
    case 8: return OptionType::PIPELINE_DISABLED;
    case 9: return OptionType::PIPELINE_INITIATION_INTERVAL;
    case 10: return OptionType::DISTRIBUTE;
    case 11: return OptionType::VECTORIZE_PREDICATE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OptionType e) {
  switch (e) {
    case OptionType::VECTORIZE: return "VECTORIZE";
    case OptionType::VECTORIZE_WIDTH: return "VECTORIZE_WIDTH";
    case OptionType::INTERLEAVE: return "INTERLEAVE";
    case OptionType::INTERLEAVE_COUNT: return "INTERLEAVE_COUNT";
    case OptionType::UNROLL: return "UNROLL";
    case OptionType::UNROLL_COUNT: return "UNROLL_COUNT";
    case OptionType::UNROLL_AND_JAM: return "UNROLL_AND_JAM";
    case OptionType::UNROLL_AND_JAM_COUNT: return "UNROLL_AND_JAM_COUNT";
    case OptionType::PIPELINE_DISABLED: return "PIPELINE_DISABLED";
    case OptionType::PIPELINE_INITIATION_INTERVAL: return "PIPELINE_INITIATION_INTERVAL";
    case OptionType::DISTRIBUTE: return "DISTRIBUTE";
    case OptionType::VECTORIZE_PREDICATE: return "VECTORIZE_PREDICATE";
    default: return "<invalid>";
  }
}

OverloadedOperatorKind FromPasta(pasta::OverloadedOperatorKind e) {
  switch (static_cast<int>(e)) {
    case 0: return OverloadedOperatorKind::NONE;
    case 1: return OverloadedOperatorKind::NEW;
    case 2: return OverloadedOperatorKind::DELETE;
    case 3: return OverloadedOperatorKind::ARRAY_NEW;
    case 4: return OverloadedOperatorKind::ARRAY_DELETE;
    case 5: return OverloadedOperatorKind::PLUS;
    case 6: return OverloadedOperatorKind::MINUS;
    case 7: return OverloadedOperatorKind::STAR;
    case 8: return OverloadedOperatorKind::SLASH;
    case 9: return OverloadedOperatorKind::PERCENT;
    case 10: return OverloadedOperatorKind::CARET;
    case 11: return OverloadedOperatorKind::AMP;
    case 12: return OverloadedOperatorKind::PIPE;
    case 13: return OverloadedOperatorKind::TILDE;
    case 14: return OverloadedOperatorKind::EXCLAIM;
    case 15: return OverloadedOperatorKind::EQUAL;
    case 16: return OverloadedOperatorKind::LESS;
    case 17: return OverloadedOperatorKind::GREATER;
    case 18: return OverloadedOperatorKind::PLUS_EQUAL;
    case 19: return OverloadedOperatorKind::MINUS_EQUAL;
    case 20: return OverloadedOperatorKind::STAR_EQUAL;
    case 21: return OverloadedOperatorKind::SLASH_EQUAL;
    case 22: return OverloadedOperatorKind::PERCENT_EQUAL;
    case 23: return OverloadedOperatorKind::CARET_EQUAL;
    case 24: return OverloadedOperatorKind::AMP_EQUAL;
    case 25: return OverloadedOperatorKind::PIPE_EQUAL;
    case 26: return OverloadedOperatorKind::LESS_LESS;
    case 27: return OverloadedOperatorKind::GREATER_GREATER;
    case 28: return OverloadedOperatorKind::LESS_LESS_EQUAL;
    case 29: return OverloadedOperatorKind::GREATER_GREATER_EQUAL;
    case 30: return OverloadedOperatorKind::EQUAL_EQUAL;
    case 31: return OverloadedOperatorKind::EXCLAIM_EQUAL;
    case 32: return OverloadedOperatorKind::LESS_EQUAL;
    case 33: return OverloadedOperatorKind::GREATER_EQUAL;
    case 34: return OverloadedOperatorKind::SPACESHIP;
    case 35: return OverloadedOperatorKind::AMP_AMP;
    case 36: return OverloadedOperatorKind::PIPE_PIPE;
    case 37: return OverloadedOperatorKind::PLUS_PLUS;
    case 38: return OverloadedOperatorKind::MINUS_MINUS;
    case 39: return OverloadedOperatorKind::COMMA;
    case 40: return OverloadedOperatorKind::ARROW_STAR;
    case 41: return OverloadedOperatorKind::ARROW;
    case 42: return OverloadedOperatorKind::CALL;
    case 43: return OverloadedOperatorKind::SUBSCRIPT;
    case 44: return OverloadedOperatorKind::CONDITIONAL;
    case 45: return OverloadedOperatorKind::COAWAIT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OverloadedOperatorKind e) {
  switch (e) {
    case OverloadedOperatorKind::NONE: return "NONE";
    case OverloadedOperatorKind::NEW: return "NEW";
    case OverloadedOperatorKind::DELETE: return "DELETE";
    case OverloadedOperatorKind::ARRAY_NEW: return "ARRAY_NEW";
    case OverloadedOperatorKind::ARRAY_DELETE: return "ARRAY_DELETE";
    case OverloadedOperatorKind::PLUS: return "PLUS";
    case OverloadedOperatorKind::MINUS: return "MINUS";
    case OverloadedOperatorKind::STAR: return "STAR";
    case OverloadedOperatorKind::SLASH: return "SLASH";
    case OverloadedOperatorKind::PERCENT: return "PERCENT";
    case OverloadedOperatorKind::CARET: return "CARET";
    case OverloadedOperatorKind::AMP: return "AMP";
    case OverloadedOperatorKind::PIPE: return "PIPE";
    case OverloadedOperatorKind::TILDE: return "TILDE";
    case OverloadedOperatorKind::EXCLAIM: return "EXCLAIM";
    case OverloadedOperatorKind::EQUAL: return "EQUAL";
    case OverloadedOperatorKind::LESS: return "LESS";
    case OverloadedOperatorKind::GREATER: return "GREATER";
    case OverloadedOperatorKind::PLUS_EQUAL: return "PLUS_EQUAL";
    case OverloadedOperatorKind::MINUS_EQUAL: return "MINUS_EQUAL";
    case OverloadedOperatorKind::STAR_EQUAL: return "STAR_EQUAL";
    case OverloadedOperatorKind::SLASH_EQUAL: return "SLASH_EQUAL";
    case OverloadedOperatorKind::PERCENT_EQUAL: return "PERCENT_EQUAL";
    case OverloadedOperatorKind::CARET_EQUAL: return "CARET_EQUAL";
    case OverloadedOperatorKind::AMP_EQUAL: return "AMP_EQUAL";
    case OverloadedOperatorKind::PIPE_EQUAL: return "PIPE_EQUAL";
    case OverloadedOperatorKind::LESS_LESS: return "LESS_LESS";
    case OverloadedOperatorKind::GREATER_GREATER: return "GREATER_GREATER";
    case OverloadedOperatorKind::LESS_LESS_EQUAL: return "LESS_LESS_EQUAL";
    case OverloadedOperatorKind::GREATER_GREATER_EQUAL: return "GREATER_GREATER_EQUAL";
    case OverloadedOperatorKind::EQUAL_EQUAL: return "EQUAL_EQUAL";
    case OverloadedOperatorKind::EXCLAIM_EQUAL: return "EXCLAIM_EQUAL";
    case OverloadedOperatorKind::LESS_EQUAL: return "LESS_EQUAL";
    case OverloadedOperatorKind::GREATER_EQUAL: return "GREATER_EQUAL";
    case OverloadedOperatorKind::SPACESHIP: return "SPACESHIP";
    case OverloadedOperatorKind::AMP_AMP: return "AMP_AMP";
    case OverloadedOperatorKind::PIPE_PIPE: return "PIPE_PIPE";
    case OverloadedOperatorKind::PLUS_PLUS: return "PLUS_PLUS";
    case OverloadedOperatorKind::MINUS_MINUS: return "MINUS_MINUS";
    case OverloadedOperatorKind::COMMA: return "COMMA";
    case OverloadedOperatorKind::ARROW_STAR: return "ARROW_STAR";
    case OverloadedOperatorKind::ARROW: return "ARROW";
    case OverloadedOperatorKind::CALL: return "CALL";
    case OverloadedOperatorKind::SUBSCRIPT: return "SUBSCRIPT";
    case OverloadedOperatorKind::CONDITIONAL: return "CONDITIONAL";
    case OverloadedOperatorKind::COAWAIT: return "COAWAIT";
    default: return "<invalid>";
  }
}

OverloadsShown FromPasta(pasta::OverloadsShown e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OverloadsShown::ALL;
    case 1: return OverloadsShown::BEST;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OverloadsShown e) {
  switch (e) {
    case OverloadsShown::ALL: return "ALL";
    case OverloadsShown::BEST: return "BEST";
    default: return "<invalid>";
  }
}

OwnershipKind FromPasta(pasta::OwnershipKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OwnershipKind::HOLDS;
    case 1: return OwnershipKind::RETURNS;
    case 2: return OwnershipKind::TAKES;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(OwnershipKind e) {
  switch (e) {
    case OwnershipKind::HOLDS: return "HOLDS";
    case OwnershipKind::RETURNS: return "RETURNS";
    case OwnershipKind::TAKES: return "TAKES";
    default: return "<invalid>";
  }
}

PCSType FromPasta(pasta::PCSType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PCSType::AAPCS;
    case 1: return PCSType::VFP;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PCSType e) {
  switch (e) {
    case PCSType::AAPCS: return "AAPCS";
    case PCSType::VFP: return "VFP";
    default: return "<invalid>";
  }
}

PPKeywordKind FromPasta(pasta::PPKeywordKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PPKeywordKind::NOT_KEYWORD;
    case 1: return PPKeywordKind::IF;
    case 2: return PPKeywordKind::IFDEF;
    case 3: return PPKeywordKind::IFNDEF;
    case 4: return PPKeywordKind::ELIF;
    case 5: return PPKeywordKind::ELIFDEF;
    case 6: return PPKeywordKind::ELIFNDEF;
    case 7: return PPKeywordKind::ELSE;
    case 8: return PPKeywordKind::ENDIF;
    case 9: return PPKeywordKind::DEFINED;
    case 10: return PPKeywordKind::INCLUDE;
    case 11: return PPKeywordKind::__INCLUDE_MACROS;
    case 12: return PPKeywordKind::DEFINE;
    case 13: return PPKeywordKind::UNDEF;
    case 14: return PPKeywordKind::LINE;
    case 15: return PPKeywordKind::ERROR;
    case 16: return PPKeywordKind::PRAGMA;
    case 17: return PPKeywordKind::IMPORT;
    case 18: return PPKeywordKind::INCLUDE_NEXT;
    case 19: return PPKeywordKind::WARNING;
    case 20: return PPKeywordKind::IDENTIFIER;
    case 21: return PPKeywordKind::SCCS;
    case 22: return PPKeywordKind::ASSERT;
    case 23: return PPKeywordKind::UNASSERT;
    case 24: return PPKeywordKind::__PUBLIC_MACRO;
    case 25: return PPKeywordKind::__PRIVATE_MACRO;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PPKeywordKind e) {
  switch (e) {
    case PPKeywordKind::NOT_KEYWORD: return "NOT_KEYWORD";
    case PPKeywordKind::IF: return "IF";
    case PPKeywordKind::IFDEF: return "IFDEF";
    case PPKeywordKind::IFNDEF: return "IFNDEF";
    case PPKeywordKind::ELIF: return "ELIF";
    case PPKeywordKind::ELIFDEF: return "ELIFDEF";
    case PPKeywordKind::ELIFNDEF: return "ELIFNDEF";
    case PPKeywordKind::ELSE: return "ELSE";
    case PPKeywordKind::ENDIF: return "ENDIF";
    case PPKeywordKind::DEFINED: return "DEFINED";
    case PPKeywordKind::INCLUDE: return "INCLUDE";
    case PPKeywordKind::__INCLUDE_MACROS: return "__INCLUDE_MACROS";
    case PPKeywordKind::DEFINE: return "DEFINE";
    case PPKeywordKind::UNDEF: return "UNDEF";
    case PPKeywordKind::LINE: return "LINE";
    case PPKeywordKind::ERROR: return "ERROR";
    case PPKeywordKind::PRAGMA: return "PRAGMA";
    case PPKeywordKind::IMPORT: return "IMPORT";
    case PPKeywordKind::INCLUDE_NEXT: return "INCLUDE_NEXT";
    case PPKeywordKind::WARNING: return "WARNING";
    case PPKeywordKind::IDENTIFIER: return "IDENTIFIER";
    case PPKeywordKind::SCCS: return "SCCS";
    case PPKeywordKind::ASSERT: return "ASSERT";
    case PPKeywordKind::UNASSERT: return "UNASSERT";
    case PPKeywordKind::__PUBLIC_MACRO: return "__PUBLIC_MACRO";
    case PPKeywordKind::__PRIVATE_MACRO: return "__PRIVATE_MACRO";
    default: return "<invalid>";
  }
}

ParameterABI FromPasta(pasta::ParameterABI e) {
  switch (static_cast<int>(e)) {
    case 0: return ParameterABI::ORDINARY;
    case 1: return ParameterABI::SWIFT_INDIRECT_RESULT;
    case 2: return ParameterABI::SWIFT_ERROR_RESULT;
    case 3: return ParameterABI::SWIFT_CONTEXT;
    case 4: return ParameterABI::SWIFT_ASYNC_CONTEXT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ParameterABI e) {
  switch (e) {
    case ParameterABI::ORDINARY: return "ORDINARY";
    case ParameterABI::SWIFT_INDIRECT_RESULT: return "SWIFT_INDIRECT_RESULT";
    case ParameterABI::SWIFT_ERROR_RESULT: return "SWIFT_ERROR_RESULT";
    case ParameterABI::SWIFT_CONTEXT: return "SWIFT_CONTEXT";
    case ParameterABI::SWIFT_ASYNC_CONTEXT: return "SWIFT_ASYNC_CONTEXT";
    default: return "<invalid>";
  }
}

ParenLocsOffsets FromPasta(pasta::ParenLocsOffsets e) {
  switch (static_cast<int>(e)) {
    case 0: return ParenLocsOffsets::L_PAREN;
    case 1: return ParenLocsOffsets::R_PAREN;
    case 2: return ParenLocsOffsets::TOTAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ParenLocsOffsets e) {
  switch (e) {
    case ParenLocsOffsets::L_PAREN: return "L_PAREN";
    case ParenLocsOffsets::R_PAREN: return "R_PAREN";
    case ParenLocsOffsets::TOTAL: return "TOTAL";
    default: return "<invalid>";
  }
}

PragmaFloatControlKind FromPasta(pasta::PragmaFloatControlKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaFloatControlKind::UNKNOWN;
    case 1: return PragmaFloatControlKind::PRECISE;
    case 2: return PragmaFloatControlKind::NO_PRECISE;
    case 3: return PragmaFloatControlKind::EXCEPT;
    case 4: return PragmaFloatControlKind::NO_EXCEPT;
    case 5: return PragmaFloatControlKind::PUSH;
    case 6: return PragmaFloatControlKind::POP;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PragmaFloatControlKind e) {
  switch (e) {
    case PragmaFloatControlKind::UNKNOWN: return "UNKNOWN";
    case PragmaFloatControlKind::PRECISE: return "PRECISE";
    case PragmaFloatControlKind::NO_PRECISE: return "NO_PRECISE";
    case PragmaFloatControlKind::EXCEPT: return "EXCEPT";
    case PragmaFloatControlKind::NO_EXCEPT: return "NO_EXCEPT";
    case PragmaFloatControlKind::PUSH: return "PUSH";
    case PragmaFloatControlKind::POP: return "POP";
    default: return "<invalid>";
  }
}

PragmaMSCommentKind FromPasta(pasta::PragmaMSCommentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSCommentKind::UNKNOWN;
    case 1: return PragmaMSCommentKind::LINKER;
    case 2: return PragmaMSCommentKind::LIB;
    case 3: return PragmaMSCommentKind::COMPILER;
    case 4: return PragmaMSCommentKind::EXE_STRING;
    case 5: return PragmaMSCommentKind::USER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PragmaMSCommentKind e) {
  switch (e) {
    case PragmaMSCommentKind::UNKNOWN: return "UNKNOWN";
    case PragmaMSCommentKind::LINKER: return "LINKER";
    case PragmaMSCommentKind::LIB: return "LIB";
    case PragmaMSCommentKind::COMPILER: return "COMPILER";
    case PragmaMSCommentKind::EXE_STRING: return "EXE_STRING";
    case PragmaMSCommentKind::USER: return "USER";
    default: return "<invalid>";
  }
}

PragmaMSPointersToMembersKind FromPasta(pasta::PragmaMSPointersToMembersKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSPointersToMembersKind::BEST_CASE;
    case 1: return PragmaMSPointersToMembersKind::FULL_GENERALITY_SINGLE_INHERITANCE;
    case 2: return PragmaMSPointersToMembersKind::FULL_GENERALITY_MULTIPLE_INHERITANCE;
    case 3: return PragmaMSPointersToMembersKind::FULL_GENERALITY_VIRTUAL_INHERITANCE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PragmaMSPointersToMembersKind e) {
  switch (e) {
    case PragmaMSPointersToMembersKind::BEST_CASE: return "BEST_CASE";
    case PragmaMSPointersToMembersKind::FULL_GENERALITY_SINGLE_INHERITANCE: return "FULL_GENERALITY_SINGLE_INHERITANCE";
    case PragmaMSPointersToMembersKind::FULL_GENERALITY_MULTIPLE_INHERITANCE: return "FULL_GENERALITY_MULTIPLE_INHERITANCE";
    case PragmaMSPointersToMembersKind::FULL_GENERALITY_VIRTUAL_INHERITANCE: return "FULL_GENERALITY_VIRTUAL_INHERITANCE";
    default: return "<invalid>";
  }
}

PragmaMSStructKind FromPasta(pasta::PragmaMSStructKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSStructKind::OFF;
    case 1: return PragmaMSStructKind::ON;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PragmaMSStructKind e) {
  switch (e) {
    case PragmaMSStructKind::OFF: return "OFF";
    case PragmaMSStructKind::ON: return "ON";
    default: return "<invalid>";
  }
}

PragmaSectionFlag FromPasta(pasta::PragmaSectionFlag e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaSectionFlag::NONE;
    case 1: return PragmaSectionFlag::READ;
    case 2: return PragmaSectionFlag::WRITE;
    case 4: return PragmaSectionFlag::EXECUTE;
    case 8: return PragmaSectionFlag::IMPLICIT;
    case 16: return PragmaSectionFlag::ZERO_INITIALIZER;
    case 2147483648: return PragmaSectionFlag::INVALID;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PragmaSectionFlag e) {
  switch (e) {
    case PragmaSectionFlag::NONE: return "NONE";
    case PragmaSectionFlag::READ: return "READ";
    case PragmaSectionFlag::WRITE: return "WRITE";
    case PragmaSectionFlag::EXECUTE: return "EXECUTE";
    case PragmaSectionFlag::IMPLICIT: return "IMPLICIT";
    case PragmaSectionFlag::ZERO_INITIALIZER: return "ZERO_INITIALIZER";
    case PragmaSectionFlag::INVALID: return "INVALID";
    default: return "<invalid>";
  }
}

ProfileInstrKind FromPasta(pasta::ProfileInstrKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ProfileInstrKind::PROFILE_NONE;
    case 1: return ProfileInstrKind::PROFILE_CLANG_INSTR;
    case 2: return ProfileInstrKind::PROFILE_IR_INSTR;
    case 3: return ProfileInstrKind::PROFILE_CSIR_INSTR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ProfileInstrKind e) {
  switch (e) {
    case ProfileInstrKind::PROFILE_NONE: return "PROFILE_NONE";
    case ProfileInstrKind::PROFILE_CLANG_INSTR: return "PROFILE_CLANG_INSTR";
    case ProfileInstrKind::PROFILE_IR_INSTR: return "PROFILE_IR_INSTR";
    case ProfileInstrKind::PROFILE_CSIR_INSTR: return "PROFILE_CSIR_INSTR";
    default: return "<invalid>";
  }
}

RangeExprOffset FromPasta(pasta::RangeExprOffset e) {
  switch (static_cast<int>(e)) {
    case 0: return RangeExprOffset::BEGIN;
    case 1: return RangeExprOffset::END;
    case 2: return RangeExprOffset::STEP;
    case 3: return RangeExprOffset::TOTAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(RangeExprOffset e) {
  switch (e) {
    case RangeExprOffset::BEGIN: return "BEGIN";
    case RangeExprOffset::END: return "END";
    case RangeExprOffset::STEP: return "STEP";
    case RangeExprOffset::TOTAL: return "TOTAL";
    default: return "<invalid>";
  }
}

RangeLocOffset FromPasta(pasta::RangeLocOffset e) {
  switch (static_cast<int>(e)) {
    case 0: return RangeLocOffset::ASSIGN_TOKEN;
    case 2: return RangeLocOffset::SECOND_COLON_TOKEN;
    case 3: return RangeLocOffset::TOTAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(RangeLocOffset e) {
  switch (e) {
    case RangeLocOffset::ASSIGN_TOKEN: return "ASSIGN_TOKEN";
    case RangeLocOffset::SECOND_COLON_TOKEN: return "SECOND_COLON_TOKEN";
    case RangeLocOffset::TOTAL: return "TOTAL";
    default: return "<invalid>";
  }
}

RefQualifierKind FromPasta(pasta::RefQualifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RefQualifierKind::NONE;
    case 1: return RefQualifierKind::L_VALUE;
    case 2: return RefQualifierKind::R_VALUE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(RefQualifierKind e) {
  switch (e) {
    case RefQualifierKind::NONE: return "NONE";
    case RefQualifierKind::L_VALUE: return "L_VALUE";
    case RefQualifierKind::R_VALUE: return "R_VALUE";
    default: return "<invalid>";
  }
}

RemarkKind FromPasta(pasta::RemarkKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return RemarkKind::MISSING;
    case 1: return RemarkKind::ENABLED;
    case 2: return RemarkKind::ENABLED_EVERYTHING;
    case 3: return RemarkKind::DISABLED;
    case 4: return RemarkKind::DISABLED_EVERYTHING;
    case 5: return RemarkKind::WITH_PATTERN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(RemarkKind e) {
  switch (e) {
    case RemarkKind::MISSING: return "MISSING";
    case RemarkKind::ENABLED: return "ENABLED";
    case RemarkKind::ENABLED_EVERYTHING: return "ENABLED_EVERYTHING";
    case RemarkKind::DISABLED: return "DISABLED";
    case RemarkKind::DISABLED_EVERYTHING: return "DISABLED_EVERYTHING";
    case RemarkKind::WITH_PATTERN: return "WITH_PATTERN";
    default: return "<invalid>";
  }
}

ReservedIdentifierStatus FromPasta(pasta::ReservedIdentifierStatus e) {
  switch (static_cast<int>(e)) {
    case 0: return ReservedIdentifierStatus::NOT_RESERVED;
    case 1: return ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE;
    case 2: return ReservedIdentifierStatus::STARTS_WITH_DOUBLE_UNDERSCORE;
    case 3: return ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER;
    case 4: return ReservedIdentifierStatus::CONTAINS_DOUBLE_UNDERSCORE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ReservedIdentifierStatus e) {
  switch (e) {
    case ReservedIdentifierStatus::NOT_RESERVED: return "NOT_RESERVED";
    case ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE: return "STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE";
    case ReservedIdentifierStatus::STARTS_WITH_DOUBLE_UNDERSCORE: return "STARTS_WITH_DOUBLE_UNDERSCORE";
    case ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER: return "STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER";
    case ReservedIdentifierStatus::CONTAINS_DOUBLE_UNDERSCORE: return "CONTAINS_DOUBLE_UNDERSCORE";
    default: return "<invalid>";
  }
}

SFINAEResponse FromPasta(pasta::SFINAEResponse e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SFINAEResponse::SUBSTITUTION_FAILURE;
    case 1: return SFINAEResponse::SUPPRESS;
    case 2: return SFINAEResponse::REPORT;
    case 3: return SFINAEResponse::ACCESS_CONTROL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SFINAEResponse e) {
  switch (e) {
    case SFINAEResponse::SUBSTITUTION_FAILURE: return "SUBSTITUTION_FAILURE";
    case SFINAEResponse::SUPPRESS: return "SUPPRESS";
    case SFINAEResponse::REPORT: return "REPORT";
    case SFINAEResponse::ACCESS_CONTROL: return "ACCESS_CONTROL";
    default: return "<invalid>";
  }
}

SYCLMajorVersion FromPasta(pasta::SYCLMajorVersion e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SYCLMajorVersion::VERSION_NONE;
    case 1: return SYCLMajorVersion::VERSION2017;
    case 2: return SYCLMajorVersion::VERSION2020;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SYCLMajorVersion e) {
  switch (e) {
    case SYCLMajorVersion::VERSION_NONE: return "VERSION_NONE";
    case SYCLMajorVersion::VERSION2017: return "VERSION2017";
    case SYCLMajorVersion::VERSION2020: return "VERSION2020";
    default: return "<invalid>";
  }
}

SanitizerOrdinal FromPasta(pasta::SanitizerOrdinal e) {
  switch (static_cast<unsigned long long>(e)) {
    case 0: return SanitizerOrdinal::ADDRESS;
    case 1: return SanitizerOrdinal::POINTER_COMPARE;
    case 2: return SanitizerOrdinal::POINTER_SUBTRACT;
    case 3: return SanitizerOrdinal::KERNEL_ADDRESS;
    case 4: return SanitizerOrdinal::HW_ADDRESS;
    case 5: return SanitizerOrdinal::KERNEL_HW_ADDRESS;
    case 6: return SanitizerOrdinal::MEMORY_TAG;
    case 7: return SanitizerOrdinal::MEMORY;
    case 8: return SanitizerOrdinal::KERNEL_MEMORY;
    case 9: return SanitizerOrdinal::FUZZER;
    case 10: return SanitizerOrdinal::FUZZER_NO_LINK;
    case 11: return SanitizerOrdinal::THREAD;
    case 12: return SanitizerOrdinal::LEAK;
    case 13: return SanitizerOrdinal::ALIGNMENT;
    case 14: return SanitizerOrdinal::ARRAY_BOUNDS;
    case 15: return SanitizerOrdinal::BOOLEAN;
    case 16: return SanitizerOrdinal::BUILTIN;
    case 17: return SanitizerOrdinal::ENUM;
    case 18: return SanitizerOrdinal::FLOAT_CAST_OVERFLOW;
    case 19: return SanitizerOrdinal::FLOAT_DIVIDE_BY_ZERO;
    case 20: return SanitizerOrdinal::FUNCTION;
    case 21: return SanitizerOrdinal::INTEGER_DIVIDE_BY_ZERO;
    case 22: return SanitizerOrdinal::NONNULL_ATTRIBUTE;
    case 23: return SanitizerOrdinal::NULL__;
    case 24: return SanitizerOrdinal::NULLABILITY_ARGUMENT;
    case 25: return SanitizerOrdinal::NULLABILITY_ASSIGN;
    case 26: return SanitizerOrdinal::NULLABILITY_RETURN;
    case 27: return SanitizerOrdinal::NULLABILITY_GROUP;
    case 28: return SanitizerOrdinal::OBJECT_SIZE;
    case 29: return SanitizerOrdinal::POINTER_OVERFLOW;
    case 30: return SanitizerOrdinal::RETURN;
    case 31: return SanitizerOrdinal::RETURNS_NONNULL_ATTRIBUTE;
    case 32: return SanitizerOrdinal::SHIFT_BASE;
    case 33: return SanitizerOrdinal::SHIFT_EXPONENT;
    case 34: return SanitizerOrdinal::SHIFT_GROUP;
    case 35: return SanitizerOrdinal::SIGNED_INTEGER_OVERFLOW;
    case 36: return SanitizerOrdinal::UNREACHABLE;
    case 37: return SanitizerOrdinal::VLA_BOUND;
    case 38: return SanitizerOrdinal::VPTR;
    case 39: return SanitizerOrdinal::UNSIGNED_INTEGER_OVERFLOW;
    case 40: return SanitizerOrdinal::UNSIGNED_SHIFT_BASE;
    case 41: return SanitizerOrdinal::DATA_FLOW;
    case 42: return SanitizerOrdinal::CFI_CAST_STRICT;
    case 43: return SanitizerOrdinal::CFI_DERIVED_CAST;
    case 44: return SanitizerOrdinal::CFII_CALL;
    case 45: return SanitizerOrdinal::CFIMF_CALL;
    case 46: return SanitizerOrdinal::CFI_UNRELATED_CAST;
    case 47: return SanitizerOrdinal::CFINV_CALL;
    case 48: return SanitizerOrdinal::CFIV_CALL;
    case 49: return SanitizerOrdinal::CFI_GROUP;
    case 50: return SanitizerOrdinal::SAFE_STACK;
    case 51: return SanitizerOrdinal::SHADOW_CALL_STACK;
    case 52: return SanitizerOrdinal::UNDEFINED_GROUP;
    case 53: return SanitizerOrdinal::UNDEFINED_TRAP_GROUP;
    case 54: return SanitizerOrdinal::IMPLICIT_UNSIGNED_INTEGER_TRUNCATION;
    case 55: return SanitizerOrdinal::IMPLICIT_SIGNED_INTEGER_TRUNCATION;
    case 56: return SanitizerOrdinal::IMPLICIT_INTEGER_TRUNCATION_GROUP;
    case 57: return SanitizerOrdinal::IMPLICIT_INTEGER_SIGN_CHANGE;
    case 58: return SanitizerOrdinal::IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP;
    case 59: return SanitizerOrdinal::OBJ_C_CAST;
    case 60: return SanitizerOrdinal::IMPLICIT_CONVERSION_GROUP;
    case 61: return SanitizerOrdinal::INTEGER_GROUP;
    case 62: return SanitizerOrdinal::LOCAL_BOUNDS;
    case 63: return SanitizerOrdinal::BOUNDS_GROUP;
    case 64: return SanitizerOrdinal::SCUDO;
    case 65: return SanitizerOrdinal::ALL_GROUP;
    case 66: return SanitizerOrdinal::COUNT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SanitizerOrdinal e) {
  switch (e) {
    case SanitizerOrdinal::ADDRESS: return "ADDRESS";
    case SanitizerOrdinal::POINTER_COMPARE: return "POINTER_COMPARE";
    case SanitizerOrdinal::POINTER_SUBTRACT: return "POINTER_SUBTRACT";
    case SanitizerOrdinal::KERNEL_ADDRESS: return "KERNEL_ADDRESS";
    case SanitizerOrdinal::HW_ADDRESS: return "HW_ADDRESS";
    case SanitizerOrdinal::KERNEL_HW_ADDRESS: return "KERNEL_HW_ADDRESS";
    case SanitizerOrdinal::MEMORY_TAG: return "MEMORY_TAG";
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
    case SanitizerOrdinal::NULL__: return "NULL__";
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

SelectorLocationsKind FromPasta(pasta::SelectorLocationsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SelectorLocationsKind::NON_STANDARD;
    case 1: return SelectorLocationsKind::STANDARD_NO_SPACE;
    case 2: return SelectorLocationsKind::STANDARD_WITH_SPACE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SelectorLocationsKind e) {
  switch (e) {
    case SelectorLocationsKind::NON_STANDARD: return "NON_STANDARD";
    case SelectorLocationsKind::STANDARD_NO_SPACE: return "STANDARD_NO_SPACE";
    case SelectorLocationsKind::STANDARD_WITH_SPACE: return "STANDARD_WITH_SPACE";
    default: return "<invalid>";
  }
}

SignReturnAddressKeyKind FromPasta(pasta::SignReturnAddressKeyKind e) {
  switch (static_cast<int>(e)) {
    case 0: return SignReturnAddressKeyKind::A_KEY;
    case 1: return SignReturnAddressKeyKind::B_KEY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SignReturnAddressKeyKind e) {
  switch (e) {
    case SignReturnAddressKeyKind::A_KEY: return "A_KEY";
    case SignReturnAddressKeyKind::B_KEY: return "B_KEY";
    default: return "<invalid>";
  }
}

SignReturnAddressScopeKind FromPasta(pasta::SignReturnAddressScopeKind e) {
  switch (static_cast<int>(e)) {
    case 0: return SignReturnAddressScopeKind::NONE;
    case 1: return SignReturnAddressScopeKind::NON_LEAF;
    case 2: return SignReturnAddressScopeKind::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SignReturnAddressScopeKind e) {
  switch (e) {
    case SignReturnAddressScopeKind::NONE: return "NONE";
    case SignReturnAddressScopeKind::NON_LEAF: return "NON_LEAF";
    case SignReturnAddressScopeKind::ALL: return "ALL";
    default: return "<invalid>";
  }
}

SignedOverflowBehaviorTy FromPasta(pasta::SignedOverflowBehaviorTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SignedOverflowBehaviorTy::UNDEFINED;
    case 1: return SignedOverflowBehaviorTy::DEFINED;
    case 2: return SignedOverflowBehaviorTy::TRAPPING;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SignedOverflowBehaviorTy e) {
  switch (e) {
    case SignedOverflowBehaviorTy::UNDEFINED: return "UNDEFINED";
    case SignedOverflowBehaviorTy::DEFINED: return "DEFINED";
    case SignedOverflowBehaviorTy::TRAPPING: return "TRAPPING";
    default: return "<invalid>";
  }
}

SpecialMemberFlags FromPasta(pasta::SpecialMemberFlags e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return SpecialMemberFlags::DEFAULT_CONSTRUCTOR;
    case 2: return SpecialMemberFlags::COPY_CONSTRUCTOR;
    case 4: return SpecialMemberFlags::MOVE_CONSTRUCTOR;
    case 8: return SpecialMemberFlags::COPY_ASSIGNMENT;
    case 16: return SpecialMemberFlags::MOVE_ASSIGNMENT;
    case 32: return SpecialMemberFlags::DESTRUCTOR;
    case 63: return SpecialMemberFlags::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SpecialMemberFlags e) {
  switch (e) {
    case SpecialMemberFlags::DEFAULT_CONSTRUCTOR: return "DEFAULT_CONSTRUCTOR";
    case SpecialMemberFlags::COPY_CONSTRUCTOR: return "COPY_CONSTRUCTOR";
    case SpecialMemberFlags::MOVE_CONSTRUCTOR: return "MOVE_CONSTRUCTOR";
    case SpecialMemberFlags::COPY_ASSIGNMENT: return "COPY_ASSIGNMENT";
    case SpecialMemberFlags::MOVE_ASSIGNMENT: return "MOVE_ASSIGNMENT";
    case SpecialMemberFlags::DESTRUCTOR: return "DESTRUCTOR";
    case SpecialMemberFlags::ALL: return "ALL";
    default: return "<invalid>";
  }
}

SpecifierKind FromPasta(pasta::SpecifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SpecifierKind::IDENTIFIER;
    case 1: return SpecifierKind::NAMESPACE;
    case 2: return SpecifierKind::NAMESPACE_ALIAS;
    case 3: return SpecifierKind::TYPE_SPEC;
    case 4: return SpecifierKind::TYPE_SPEC_WITH_TEMPLATE;
    case 5: return SpecifierKind::GLOBAL;
    case 6: return SpecifierKind::SUPER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SpecifierKind e) {
  switch (e) {
    case SpecifierKind::IDENTIFIER: return "IDENTIFIER";
    case SpecifierKind::NAMESPACE: return "NAMESPACE";
    case SpecifierKind::NAMESPACE_ALIAS: return "NAMESPACE_ALIAS";
    case SpecifierKind::TYPE_SPEC: return "TYPE_SPEC";
    case SpecifierKind::TYPE_SPEC_WITH_TEMPLATE: return "TYPE_SPEC_WITH_TEMPLATE";
    case SpecifierKind::GLOBAL: return "GLOBAL";
    case SpecifierKind::SUPER: return "SUPER";
    default: return "<invalid>";
  }
}

Spelling FromPasta(pasta::Spelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Spelling::GNU_AARCH64_VECTOR_PCS;
    case 1: return Spelling::CXX11_CLANG_AARCH64_VECTOR_PCS;
    case 2: return Spelling::C2_XCLANG_AARCH64_VECTOR_PCS;
    case 15: return Spelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Spelling e) {
  switch (e) {
    case Spelling::GNU_AARCH64_VECTOR_PCS: return "GNU_AARCH64_VECTOR_PCS";
    case Spelling::CXX11_CLANG_AARCH64_VECTOR_PCS: return "CXX11_CLANG_AARCH64_VECTOR_PCS";
    case Spelling::C2_XCLANG_AARCH64_VECTOR_PCS: return "C2_XCLANG_AARCH64_VECTOR_PCS";
    case Spelling::SPELLING_NOT_CALCULATED: return "SPELLING_NOT_CALCULATED";
    default: return "<invalid>";
  }
}

StackProtectorMode FromPasta(pasta::StackProtectorMode e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StackProtectorMode::OFF;
    case 1: return StackProtectorMode::ON;
    case 2: return StackProtectorMode::STRONG;
    case 3: return StackProtectorMode::REQ;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StackProtectorMode e) {
  switch (e) {
    case StackProtectorMode::OFF: return "OFF";
    case StackProtectorMode::ON: return "ON";
    case StackProtectorMode::STRONG: return "STRONG";
    case StackProtectorMode::REQ: return "REQ";
    default: return "<invalid>";
  }
}

StorageClass FromPasta(pasta::StorageClass e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StorageClass::NONE;
    case 1: return StorageClass::EXTERN;
    case 2: return StorageClass::STATIC;
    case 3: return StorageClass::PRIVATE_EXTERN;
    case 4: return StorageClass::AUTO;
    case 5: return StorageClass::REGISTER;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StorageClass e) {
  switch (e) {
    case StorageClass::NONE: return "NONE";
    case StorageClass::EXTERN: return "EXTERN";
    case StorageClass::STATIC: return "STATIC";
    case StorageClass::PRIVATE_EXTERN: return "PRIVATE_EXTERN";
    case StorageClass::AUTO: return "AUTO";
    case StorageClass::REGISTER: return "REGISTER";
    default: return "<invalid>";
  }
}

StorageDuration FromPasta(pasta::StorageDuration e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StorageDuration::FULL_EXPRESSION;
    case 1: return StorageDuration::AUTOMATIC;
    case 2: return StorageDuration::THREAD;
    case 3: return StorageDuration::STATIC;
    case 4: return StorageDuration::DYNAMIC;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StorageDuration e) {
  switch (e) {
    case StorageDuration::FULL_EXPRESSION: return "FULL_EXPRESSION";
    case StorageDuration::AUTOMATIC: return "AUTOMATIC";
    case StorageDuration::THREAD: return "THREAD";
    case StorageDuration::STATIC: return "STATIC";
    case StorageDuration::DYNAMIC: return "DYNAMIC";
    default: return "<invalid>";
  }
}

StoredNameKind FromPasta(pasta::StoredNameKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StoredNameKind::STORED_IDENTIFIER;
    case 1: return StoredNameKind::STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR;
    case 2: return StoredNameKind::STORED_OBJ_C_ONE_ARGUMENT_SELECTOR;
    case 3: return StoredNameKind::STORED_CXX_CONSTRUCTOR_NAME;
    case 4: return StoredNameKind::STORED_CXX_DESTRUCTOR_NAME;
    case 5: return StoredNameKind::STORED_CXX_CONVERSION_FUNCTION_NAME;
    case 6: return StoredNameKind::STORED_CXX_OPERATOR_NAME;
    case 7: return StoredNameKind::STORED_DECLARATION_NAME_EXTRA;
    case 8: return StoredNameKind::UNCOMMON_NAME_KIND_OFFSET;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StoredNameKind e) {
  switch (e) {
    case StoredNameKind::STORED_IDENTIFIER: return "STORED_IDENTIFIER";
    case StoredNameKind::STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR: return "STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR";
    case StoredNameKind::STORED_OBJ_C_ONE_ARGUMENT_SELECTOR: return "STORED_OBJ_C_ONE_ARGUMENT_SELECTOR";
    case StoredNameKind::STORED_CXX_CONSTRUCTOR_NAME: return "STORED_CXX_CONSTRUCTOR_NAME";
    case StoredNameKind::STORED_CXX_DESTRUCTOR_NAME: return "STORED_CXX_DESTRUCTOR_NAME";
    case StoredNameKind::STORED_CXX_CONVERSION_FUNCTION_NAME: return "STORED_CXX_CONVERSION_FUNCTION_NAME";
    case StoredNameKind::STORED_CXX_OPERATOR_NAME: return "STORED_CXX_OPERATOR_NAME";
    case StoredNameKind::STORED_DECLARATION_NAME_EXTRA: return "STORED_DECLARATION_NAME_EXTRA";
    case StoredNameKind::UNCOMMON_NAME_KIND_OFFSET: return "UNCOMMON_NAME_KIND_OFFSET";
    default: return "<invalid>";
  }
}

StoredSpecifierKind FromPasta(pasta::StoredSpecifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StoredSpecifierKind::STORED_IDENTIFIER;
    case 1: return StoredSpecifierKind::STORED_DECLARATION;
    case 2: return StoredSpecifierKind::STORED_TYPE_SPEC;
    case 3: return StoredSpecifierKind::STORED_TYPE_SPEC_WITH_TEMPLATE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StoredSpecifierKind e) {
  switch (e) {
    case StoredSpecifierKind::STORED_IDENTIFIER: return "STORED_IDENTIFIER";
    case StoredSpecifierKind::STORED_DECLARATION: return "STORED_DECLARATION";
    case StoredSpecifierKind::STORED_TYPE_SPEC: return "STORED_TYPE_SPEC";
    case StoredSpecifierKind::STORED_TYPE_SPEC_WITH_TEMPLATE: return "STORED_TYPE_SPEC_WITH_TEMPLATE";
    default: return "<invalid>";
  }
}

StructReturnConventionKind FromPasta(pasta::StructReturnConventionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StructReturnConventionKind::DEFAULT;
    case 1: return StructReturnConventionKind::ON_STACK;
    case 2: return StructReturnConventionKind::IN_REGS;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(StructReturnConventionKind e) {
  switch (e) {
    case StructReturnConventionKind::DEFAULT: return "DEFAULT";
    case StructReturnConventionKind::ON_STACK: return "ON_STACK";
    case StructReturnConventionKind::IN_REGS: return "IN_REGS";
    default: return "<invalid>";
  }
}

SubExpr FromPasta(pasta::SubExpr e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SubExpr::CALLEE;
    case 1: return SubExpr::LHS;
    case 2: return SubExpr::RHS;
    case 3: return SubExpr::COUNT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SubExpr e) {
  switch (e) {
    case SubExpr::CALLEE: return "CALLEE";
    case SubExpr::LHS: return "LHS";
    case SubExpr::RHS: return "RHS";
    case SubExpr::COUNT: return "COUNT";
    default: return "<invalid>";
  }
}

SubStmt FromPasta(pasta::SubStmt e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SubStmt::BODY;
    case 1: return SubStmt::PROMISE;
    case 2: return SubStmt::INITIALIZER_SUSPEND;
    case 3: return SubStmt::FINAL_SUSPEND;
    case 4: return SubStmt::ON_EXCEPTION;
    case 5: return SubStmt::ON_FALLTHROUGH;
    case 6: return SubStmt::ALLOCATE;
    case 7: return SubStmt::DEALLOCATE;
    case 8: return SubStmt::RETURN_VALUE;
    case 9: return SubStmt::RESULT_DECLARATION;
    case 10: return SubStmt::RETURN_STATEMENT;
    case 11: return SubStmt::RETURN_STATEMENT_ON_ALLOC_FAILURE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SubStmt e) {
  switch (e) {
    case SubStmt::BODY: return "BODY";
    case SubStmt::PROMISE: return "PROMISE";
    case SubStmt::INITIALIZER_SUSPEND: return "INITIALIZER_SUSPEND";
    case SubStmt::FINAL_SUSPEND: return "FINAL_SUSPEND";
    case SubStmt::ON_EXCEPTION: return "ON_EXCEPTION";
    case SubStmt::ON_FALLTHROUGH: return "ON_FALLTHROUGH";
    case SubStmt::ALLOCATE: return "ALLOCATE";
    case SubStmt::DEALLOCATE: return "DEALLOCATE";
    case SubStmt::RETURN_VALUE: return "RETURN_VALUE";
    case SubStmt::RESULT_DECLARATION: return "RESULT_DECLARATION";
    case SubStmt::RETURN_STATEMENT: return "RETURN_STATEMENT";
    case SubStmt::RETURN_STATEMENT_ON_ALLOC_FAILURE: return "RETURN_STATEMENT_ON_ALLOC_FAILURE";
    default: return "<invalid>";
  }
}

SyncScope FromPasta(pasta::SyncScope e) {
  switch (static_cast<int>(e)) {
    case 0: return SyncScope::OPEN_CL_WORK_GROUP;
    case 1: return SyncScope::OPEN_CL_DEVICE;
    case 2: return SyncScope::OPEN_CL_ALL_SVM_DEVICES;
    case 3: return SyncScope::OPEN_CL_SUB_GROUP;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(SyncScope e) {
  switch (e) {
    case SyncScope::OPEN_CL_WORK_GROUP: return "OPEN_CL_WORK_GROUP";
    case SyncScope::OPEN_CL_DEVICE: return "OPEN_CL_DEVICE";
    case SyncScope::OPEN_CL_ALL_SVM_DEVICES: return "OPEN_CL_ALL_SVM_DEVICES";
    case SyncScope::OPEN_CL_SUB_GROUP: return "OPEN_CL_SUB_GROUP";
    default: return "<invalid>";
  }
}

Syntax FromPasta(pasta::Syntax e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Syntax::GNU;
    case 1: return Syntax::CXX11;
    case 2: return Syntax::C2_X;
    case 3: return Syntax::DECLSPEC;
    case 4: return Syntax::MICROSOFT;
    case 5: return Syntax::KEYWORD;
    case 6: return Syntax::PRAGMA;
    case 7: return Syntax::CONTEXT_SENSITIVE_KEYWORD;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Syntax e) {
  switch (e) {
    case Syntax::GNU: return "GNU";
    case Syntax::CXX11: return "CXX11";
    case Syntax::C2_X: return "C2_X";
    case Syntax::DECLSPEC: return "DECLSPEC";
    case Syntax::MICROSOFT: return "MICROSOFT";
    case Syntax::KEYWORD: return "KEYWORD";
    case Syntax::PRAGMA: return "PRAGMA";
    case Syntax::CONTEXT_SENSITIVE_KEYWORD: return "CONTEXT_SENSITIVE_KEYWORD";
    default: return "<invalid>";
  }
}

TLSModel FromPasta(pasta::TLSModel e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TLSModel::GENERAL_DYNAMIC_TLS_MODEL;
    case 1: return TLSModel::LOCAL_DYNAMIC_TLS_MODEL;
    case 2: return TLSModel::INITIAL_EXEC_TLS_MODEL;
    case 3: return TLSModel::LOCAL_EXEC_TLS_MODEL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TLSModel e) {
  switch (e) {
    case TLSModel::GENERAL_DYNAMIC_TLS_MODEL: return "GENERAL_DYNAMIC_TLS_MODEL";
    case TLSModel::LOCAL_DYNAMIC_TLS_MODEL: return "LOCAL_DYNAMIC_TLS_MODEL";
    case TLSModel::INITIAL_EXEC_TLS_MODEL: return "INITIAL_EXEC_TLS_MODEL";
    case TLSModel::LOCAL_EXEC_TLS_MODEL: return "LOCAL_EXEC_TLS_MODEL";
    default: return "<invalid>";
  }
}

TQ FromPasta(pasta::TQ e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return TQ::CONST;
    case 2: return TQ::RESTRICT;
    case 4: return TQ::VOLATILE;
    case 7: return TQ::CVR_MASK;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TQ e) {
  switch (e) {
    case TQ::CONST: return "CONST";
    case TQ::RESTRICT: return "RESTRICT";
    case TQ::VOLATILE: return "VOLATILE";
    case TQ::CVR_MASK: return "CVR_MASK";
    default: return "<invalid>";
  }
}

TagTypeKind FromPasta(pasta::TagTypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TagTypeKind::STRUCT;
    case 1: return TagTypeKind::INTERFACE;
    case 2: return TagTypeKind::UNION;
    case 3: return TagTypeKind::CLASS;
    case 4: return TagTypeKind::ENUM;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TagTypeKind e) {
  switch (e) {
    case TagTypeKind::STRUCT: return "STRUCT";
    case TagTypeKind::INTERFACE: return "INTERFACE";
    case TagTypeKind::UNION: return "UNION";
    case TagTypeKind::CLASS: return "CLASS";
    case TagTypeKind::ENUM: return "ENUM";
    default: return "<invalid>";
  }
}

TailPaddingUseRules FromPasta(pasta::TailPaddingUseRules e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TailPaddingUseRules::ALWAYS_USE_TAIL_PADDING;
    case 1: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD03;
    case 2: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD11;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TailPaddingUseRules e) {
  switch (e) {
    case TailPaddingUseRules::ALWAYS_USE_TAIL_PADDING: return "ALWAYS_USE_TAIL_PADDING";
    case TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD03: return "USE_TAIL_PADDING_UNLESS_POD03";
    case TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD11: return "USE_TAIL_PADDING_UNLESS_POD11";
    default: return "<invalid>";
  }
}

TemplateArgumentDependence FromPasta(pasta::TemplateArgumentDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return TemplateArgumentDependence::UNEXPANDED_PACK;
    case 2: return TemplateArgumentDependence::INSTANTIATION;
    case 4: return TemplateArgumentDependence::DEPENDENT;
    case 8: return TemplateArgumentDependence::ERROR;
    case 0: return TemplateArgumentDependence::NONE;
    case 6: return TemplateArgumentDependence::DEPENDENT_INSTANTIATION;
    case 15: return TemplateArgumentDependence::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TemplateArgumentDependence e) {
  switch (e) {
    case TemplateArgumentDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case TemplateArgumentDependence::INSTANTIATION: return "INSTANTIATION";
    case TemplateArgumentDependence::DEPENDENT: return "DEPENDENT";
    case TemplateArgumentDependence::ERROR: return "ERROR";
    case TemplateArgumentDependence::NONE: return "NONE";
    case TemplateArgumentDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    case TemplateArgumentDependence::ALL: return "ALL";
    default: return "<invalid>";
  }
}

TemplateNameDependence FromPasta(pasta::TemplateNameDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return TemplateNameDependence::UNEXPANDED_PACK;
    case 2: return TemplateNameDependence::INSTANTIATION;
    case 4: return TemplateNameDependence::DEPENDENT;
    case 8: return TemplateNameDependence::ERROR;
    case 0: return TemplateNameDependence::NONE;
    case 6: return TemplateNameDependence::DEPENDENT_INSTANTIATION;
    case 15: return TemplateNameDependence::ALL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TemplateNameDependence e) {
  switch (e) {
    case TemplateNameDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case TemplateNameDependence::INSTANTIATION: return "INSTANTIATION";
    case TemplateNameDependence::DEPENDENT: return "DEPENDENT";
    case TemplateNameDependence::ERROR: return "ERROR";
    case TemplateNameDependence::NONE: return "NONE";
    case TemplateNameDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    case TemplateNameDependence::ALL: return "ALL";
    default: return "<invalid>";
  }
}

TemplateSpecializationKind FromPasta(pasta::TemplateSpecializationKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TemplateSpecializationKind::UNDECLARED;
    case 1: return TemplateSpecializationKind::IMPLICIT_INSTANTIATION;
    case 2: return TemplateSpecializationKind::EXPLICIT_SPECIALIZATION;
    case 3: return TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DECLARATION;
    case 4: return TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DEFINITION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TemplateSpecializationKind e) {
  switch (e) {
    case TemplateSpecializationKind::UNDECLARED: return "UNDECLARED";
    case TemplateSpecializationKind::IMPLICIT_INSTANTIATION: return "IMPLICIT_INSTANTIATION";
    case TemplateSpecializationKind::EXPLICIT_SPECIALIZATION: return "EXPLICIT_SPECIALIZATION";
    case TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DECLARATION: return "EXPLICIT_INSTANTIATION_DECLARATION";
    case TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DEFINITION: return "EXPLICIT_INSTANTIATION_DEFINITION";
    default: return "<invalid>";
  }
}

TextDiagnosticFormat FromPasta(pasta::TextDiagnosticFormat e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TextDiagnosticFormat::CLANG;
    case 1: return TextDiagnosticFormat::MSVC;
    case 2: return TextDiagnosticFormat::VI;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TextDiagnosticFormat e) {
  switch (e) {
    case TextDiagnosticFormat::CLANG: return "CLANG";
    case TextDiagnosticFormat::MSVC: return "MSVC";
    case TextDiagnosticFormat::VI: return "VI";
    default: return "<invalid>";
  }
}

ThreadModelKind FromPasta(pasta::ThreadModelKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ThreadModelKind::POSIX;
    case 1: return ThreadModelKind::SINGLE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ThreadModelKind e) {
  switch (e) {
    case ThreadModelKind::POSIX: return "POSIX";
    case ThreadModelKind::SINGLE: return "SINGLE";
    default: return "<invalid>";
  }
}

ThreadStorageClassSpecifier FromPasta(pasta::ThreadStorageClassSpecifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ThreadStorageClassSpecifier::UNSPECIFIED;
    case 1: return ThreadStorageClassSpecifier::__THREAD;
    case 2: return ThreadStorageClassSpecifier::THREAD_LOCAL;
    case 3: return ThreadStorageClassSpecifier::_THREAD_LOCAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(ThreadStorageClassSpecifier e) {
  switch (e) {
    case ThreadStorageClassSpecifier::UNSPECIFIED: return "UNSPECIFIED";
    case ThreadStorageClassSpecifier::__THREAD: return "__THREAD";
    case ThreadStorageClassSpecifier::THREAD_LOCAL: return "THREAD_LOCAL";
    case ThreadStorageClassSpecifier::_THREAD_LOCAL: return "_THREAD_LOCAL";
    default: return "<invalid>";
  }
}

TokenKind FromPasta(pasta::TokenKind e) {
  switch (static_cast<unsigned short>(e)) {
    case 0: return TokenKind::UNKNOWN;
    case 1: return TokenKind::END_OF_FILE;
    case 2: return TokenKind::END_OF_DIRECTIVE;
    case 3: return TokenKind::CODE_COMPLETION;
    case 4: return TokenKind::COMMENT;
    case 5: return TokenKind::IDENTIFIER;
    case 6: return TokenKind::IDENTIFIER;
    case 7: return TokenKind::NUMERIC_CONSTANT;
    case 8: return TokenKind::CHARACTER_CONSTANT;
    case 9: return TokenKind::WIDE_CHARACTER_CONSTANT;
    case 10: return TokenKind::UTF8_CHARACTER_CONSTANT;
    case 11: return TokenKind::UTF16_CHARACTER_CONSTANT;
    case 12: return TokenKind::UTF32_CHARACTER_CONSTANT;
    case 13: return TokenKind::STRING_LITERAL;
    case 14: return TokenKind::WIDE_STRING_LITERAL;
    case 15: return TokenKind::HEADER_NAME;
    case 16: return TokenKind::UTF8_STRING_LITERAL;
    case 17: return TokenKind::UTF16_STRING_LITERAL;
    case 18: return TokenKind::UTF32_STRING_LITERAL;
    case 19: return TokenKind::L_SQUARE;
    case 20: return TokenKind::R_SQUARE;
    case 21: return TokenKind::L_PARENTHESIS;
    case 22: return TokenKind::R_PARENTHESIS;
    case 23: return TokenKind::L_BRACE;
    case 24: return TokenKind::R_BRACE;
    case 25: return TokenKind::PERIOD;
    case 26: return TokenKind::ELLIPSIS;
    case 27: return TokenKind::AMP;
    case 28: return TokenKind::AMP_AMP;
    case 29: return TokenKind::AMP_EQUAL;
    case 30: return TokenKind::STAR;
    case 31: return TokenKind::STAR_EQUAL;
    case 32: return TokenKind::PLUS;
    case 33: return TokenKind::PLUS_PLUS;
    case 34: return TokenKind::PLUS_EQUAL;
    case 35: return TokenKind::MINUS;
    case 36: return TokenKind::ARROW;
    case 37: return TokenKind::MINUS_MINUS;
    case 38: return TokenKind::MINUS_EQUAL;
    case 39: return TokenKind::TILDE;
    case 40: return TokenKind::EXCLAIM;
    case 41: return TokenKind::EXCLAIM_EQUAL;
    case 42: return TokenKind::SLASH;
    case 43: return TokenKind::SLASH_EQUAL;
    case 44: return TokenKind::PERCENT;
    case 45: return TokenKind::PERCENT_EQUAL;
    case 46: return TokenKind::LESS;
    case 47: return TokenKind::LESS_LESS;
    case 48: return TokenKind::LESS_EQUAL;
    case 49: return TokenKind::LESS_LESS_EQUAL;
    case 50: return TokenKind::SPACESHIP;
    case 51: return TokenKind::GREATER;
    case 52: return TokenKind::GREATER_GREATER;
    case 53: return TokenKind::GREATER_EQUAL;
    case 54: return TokenKind::GREATER_GREATER_EQUAL;
    case 55: return TokenKind::CARET;
    case 56: return TokenKind::CARET_EQUAL;
    case 57: return TokenKind::PIPE;
    case 58: return TokenKind::PIPE_PIPE;
    case 59: return TokenKind::PIPE_EQUAL;
    case 60: return TokenKind::QUESTION;
    case 61: return TokenKind::COLON;
    case 62: return TokenKind::SEMI;
    case 63: return TokenKind::EQUAL;
    case 64: return TokenKind::EQUAL_EQUAL;
    case 65: return TokenKind::COMMA;
    case 66: return TokenKind::HASH;
    case 67: return TokenKind::HASH_HASH;
    case 68: return TokenKind::HASHAT;
    case 69: return TokenKind::PERIOD_STAR;
    case 70: return TokenKind::ARROW_STAR;
    case 71: return TokenKind::COLON_COLON;
    case 72: return TokenKind::AT;
    case 73: return TokenKind::LESS_LESS_LESS;
    case 74: return TokenKind::GREATER_GREATER_GREATER;
    case 75: return TokenKind::CARETCARET;
    case 76: return TokenKind::KEYWORD_AUTO;
    case 77: return TokenKind::KEYWORD_BREAK;
    case 78: return TokenKind::KEYWORD_CASE;
    case 79: return TokenKind::KEYWORD_CHARACTER;
    case 80: return TokenKind::KEYWORD_CONST;
    case 81: return TokenKind::KEYWORD_CONTINUE;
    case 82: return TokenKind::KEYWORD_DEFAULT;
    case 83: return TokenKind::KEYWORD_DO;
    case 84: return TokenKind::KEYWORD_DOUBLE;
    case 85: return TokenKind::KEYWORD_ELSE;
    case 86: return TokenKind::KEYWORD_ENUM;
    case 87: return TokenKind::KEYWORD_EXTERN;
    case 88: return TokenKind::KEYWORD_FLOAT;
    case 89: return TokenKind::KEYWORD_FOR;
    case 90: return TokenKind::KEYWORD_GOTO;
    case 91: return TokenKind::KEYWORD_IF;
    case 92: return TokenKind::KEYWORD_INLINE;
    case 93: return TokenKind::KEYWORD_INT;
    case 94: return TokenKind::KEYWORD__EXT_INT;
    case 95: return TokenKind::KEYWORD_LONG;
    case 96: return TokenKind::KEYWORD_REGISTER;
    case 97: return TokenKind::KEYWORD_RESTRICT;
    case 98: return TokenKind::KEYWORD_RETURN;
    case 99: return TokenKind::KEYWORD_SHORT;
    case 100: return TokenKind::KEYWORD_SIGNED;
    case 101: return TokenKind::KEYWORD_SIZEOF;
    case 102: return TokenKind::KEYWORD_STATIC;
    case 103: return TokenKind::KEYWORD_STRUCT;
    case 104: return TokenKind::KEYWORD_SWITCH;
    case 105: return TokenKind::KEYWORD_TYPEDEF;
    case 106: return TokenKind::KEYWORD_UNION;
    case 107: return TokenKind::KEYWORD_UNSIGNED;
    case 108: return TokenKind::KEYWORD_VOID;
    case 109: return TokenKind::KEYWORD_VOLATILE;
    case 110: return TokenKind::KEYWORD_WHILE;
    case 111: return TokenKind::KEYWORD__ALIGNAS;
    case 112: return TokenKind::KEYWORD__ALIGNOF;
    case 113: return TokenKind::KEYWORD__ATOMIC;
    case 114: return TokenKind::KEYWORD__BOOLEAN;
    case 115: return TokenKind::KEYWORD__COMPLEX;
    case 116: return TokenKind::KEYWORD__GENERIC;
    case 117: return TokenKind::KEYWORD__IMAGINARY;
    case 118: return TokenKind::KEYWORD__NORETURN;
    case 119: return TokenKind::KEYWORD__STATIC_ASSERT;
    case 120: return TokenKind::KEYWORD__THREAD_LOCAL;
    case 121: return TokenKind::KEYWORD___FUNC__;
    case 122: return TokenKind::KEYWORD___OBJC_YES;
    case 123: return TokenKind::KEYWORD___OBJC_NO;
    case 124: return TokenKind::KEYWORD_ASSEMBLY;
    case 125: return TokenKind::KEYWORD_BOOLEAN;
    case 126: return TokenKind::KEYWORD_CATCH;
    case 127: return TokenKind::KEYWORD_CLASS;
    case 128: return TokenKind::KEYWORD_CONST_CAST;
    case 129: return TokenKind::KEYWORD_DELETE;
    case 130: return TokenKind::KEYWORD_DYNAMIC_CAST;
    case 131: return TokenKind::KEYWORD_EXPLICIT;
    case 132: return TokenKind::KEYWORD_EXPORT;
    case 133: return TokenKind::KEYWORD_FALSE;
    case 134: return TokenKind::KEYWORD_FRIEND;
    case 135: return TokenKind::KEYWORD_MUTABLE;
    case 136: return TokenKind::KEYWORD_NAMESPACE;
    case 137: return TokenKind::KEYWORD_NEW;
    case 138: return TokenKind::KEYWORD_OPERATOR;
    case 139: return TokenKind::KEYWORD_PRIVATE;
    case 140: return TokenKind::KEYWORD_PROTECTED;
    case 141: return TokenKind::KEYWORD_PUBLIC;
    case 142: return TokenKind::KEYWORD_REINTERPRET_CAST;
    case 143: return TokenKind::KEYWORD_STATIC_CAST;
    case 144: return TokenKind::KEYWORD_TEMPLATE;
    case 145: return TokenKind::KEYWORD_THIS;
    case 146: return TokenKind::KEYWORD_THROW;
    case 147: return TokenKind::KEYWORD_TRUE;
    case 148: return TokenKind::KEYWORD_TRY;
    case 149: return TokenKind::KEYWORD_TYPENAME;
    case 150: return TokenKind::KEYWORD_TYPEID;
    case 151: return TokenKind::KEYWORD_USING;
    case 152: return TokenKind::KEYWORD_VIRTUAL;
    case 153: return TokenKind::KEYWORD_WCHAR_T;
    case 154: return TokenKind::KEYWORD_ALIGNAS;
    case 155: return TokenKind::KEYWORD_ALIGNOF;
    case 156: return TokenKind::KEYWORD_CHAR16_T;
    case 157: return TokenKind::KEYWORD_CHAR32_T;
    case 158: return TokenKind::KEYWORD_CONSTEXPR;
    case 159: return TokenKind::KEYWORD_DECLTYPE;
    case 160: return TokenKind::KEYWORD_NOEXCEPT;
    case 161: return TokenKind::KEYWORD_NULLPTR;
    case 162: return TokenKind::KEYWORD_STATIC_ASSERT;
    case 163: return TokenKind::KEYWORD_THREAD_LOCAL;
    case 164: return TokenKind::KEYWORD_CONCEPT;
    case 165: return TokenKind::KEYWORD_REQUIRES;
    case 166: return TokenKind::KEYWORD_CO_AWAIT;
    case 167: return TokenKind::KEYWORD_CO_RETURN;
    case 168: return TokenKind::KEYWORD_CO_YIELD;
    case 169: return TokenKind::KEYWORD_MODULE;
    case 170: return TokenKind::KEYWORD_IMPORT;
    case 171: return TokenKind::KEYWORD_CONSTEVAL;
    case 172: return TokenKind::KEYWORD_CONSTINIT;
    case 173: return TokenKind::KEYWORD_CHAR8_T;
    case 174: return TokenKind::KEYWORD__FLOAT16;
    case 175: return TokenKind::KEYWORD__ACCUM;
    case 176: return TokenKind::KEYWORD__FRACT;
    case 177: return TokenKind::KEYWORD__SAT;
    case 178: return TokenKind::KEYWORD__DECIMAL32;
    case 179: return TokenKind::KEYWORD__DECIMAL64;
    case 180: return TokenKind::KEYWORD__DECIMAL128;
    case 181: return TokenKind::KEYWORD___NULL;
    case 182: return TokenKind::KEYWORD___ALIGNOF;
    case 183: return TokenKind::KEYWORD___ATTRIBUTE;
    case 184: return TokenKind::KEYWORD___BUILTIN_CHOOSE_EXPRESSION;
    case 185: return TokenKind::KEYWORD___BUILTIN_OFFSETOF;
    case 186: return TokenKind::KEYWORD___BUILTIN_FILE;
    case 187: return TokenKind::KEYWORD___BUILTIN_FUNCTION;
    case 188: return TokenKind::KEYWORD___BUILTIN_LINE;
    case 189: return TokenKind::KEYWORD___BUILTIN_COLUMN;
    case 190: return TokenKind::KEYWORD___BUILTIN_TYPES_COMPATIBLE_P;
    case 191: return TokenKind::KEYWORD___BUILTIN_VA_ARGUMENT;
    case 192: return TokenKind::KEYWORD___EXTENSION__;
    case 193: return TokenKind::KEYWORD___FLOAT128;
    case 194: return TokenKind::KEYWORD___IMAG;
    case 195: return TokenKind::KEYWORD___INT128;
    case 196: return TokenKind::KEYWORD___LABEL__;
    case 197: return TokenKind::KEYWORD___REAL;
    case 198: return TokenKind::KEYWORD___THREAD;
    case 199: return TokenKind::KEYWORD___FUNCTION__;
    case 200: return TokenKind::KEYWORD___PRETTYFUNCTION__;
    case 201: return TokenKind::KEYWORD___AUTO_TYPE;
    case 202: return TokenKind::KEYWORD_TYPEOF;
    case 203: return TokenKind::KEYWORD___FUNCDNAME__;
    case 204: return TokenKind::KEYWORD___FUNCSIG__;
    case 205: return TokenKind::KEYWORD_LFUNCTION__;
    case 206: return TokenKind::KEYWORD_LFUNCSIG__;
    case 207: return TokenKind::KEYWORD___IS_INTERFACE_CLASS;
    case 208: return TokenKind::KEYWORD___IS_SEALED;
    case 209: return TokenKind::KEYWORD___IS_DESTRUCTIBLE;
    case 210: return TokenKind::KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE;
    case 211: return TokenKind::KEYWORD___IS_NOTHROW_DESTRUCTIBLE;
    case 212: return TokenKind::KEYWORD___IS_NOTHROW_ASSIGNABLE;
    case 213: return TokenKind::KEYWORD___IS_CONSTRUCTIBLE;
    case 214: return TokenKind::KEYWORD___IS_NOTHROW_CONSTRUCTIBLE;
    case 215: return TokenKind::KEYWORD___IS_ASSIGNABLE;
    case 216: return TokenKind::KEYWORD___HAS_NOTHROW_MOVE_ASSIGN;
    case 217: return TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN;
    case 218: return TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR;
    case 219: return TokenKind::KEYWORD___HAS_NOTHROW_ASSIGN;
    case 220: return TokenKind::KEYWORD___HAS_NOTHROW_COPY;
    case 221: return TokenKind::KEYWORD___HAS_NOTHROW_CONSTRUCTOR;
    case 222: return TokenKind::KEYWORD___HAS_TRIVIAL_ASSIGN;
    case 223: return TokenKind::KEYWORD___HAS_TRIVIAL_COPY;
    case 224: return TokenKind::KEYWORD___HAS_TRIVIAL_CONSTRUCTOR;
    case 225: return TokenKind::KEYWORD___HAS_TRIVIAL_DESTRUCTOR;
    case 226: return TokenKind::KEYWORD___HAS_VIRTUAL_DESTRUCTOR;
    case 227: return TokenKind::KEYWORD___IS_ABSTRACT;
    case 228: return TokenKind::KEYWORD___IS_AGGREGATE;
    case 229: return TokenKind::KEYWORD___IS_BASE_OF;
    case 230: return TokenKind::KEYWORD___IS_CLASS;
    case 231: return TokenKind::KEYWORD___IS_CONVERTIBLE_TO;
    case 232: return TokenKind::KEYWORD___IS_EMPTY;
    case 233: return TokenKind::KEYWORD___IS_ENUM;
    case 234: return TokenKind::KEYWORD___IS_FINAL;
    case 235: return TokenKind::KEYWORD___IS_LITERAL;
    case 236: return TokenKind::KEYWORD___IS_POD;
    case 237: return TokenKind::KEYWORD___IS_POLYMORPHIC;
    case 238: return TokenKind::KEYWORD___IS_STANDARD_LAYOUT;
    case 239: return TokenKind::KEYWORD___IS_TRIVIAL;
    case 240: return TokenKind::KEYWORD___IS_TRIVIALLY_ASSIGNABLE;
    case 241: return TokenKind::KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE;
    case 242: return TokenKind::KEYWORD___IS_TRIVIALLY_COPYABLE;
    case 243: return TokenKind::KEYWORD___IS_UNION;
    case 244: return TokenKind::KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS;
    case 245: return TokenKind::KEYWORD___UNDERLYING_TYPE;
    case 246: return TokenKind::KEYWORD___REFERENCE_BINDS_TO_TEMPORARY;
    case 247: return TokenKind::KEYWORD___IS_LVALUE_EXPRESSION;
    case 248: return TokenKind::KEYWORD___IS_RVALUE_EXPRESSION;
    case 249: return TokenKind::KEYWORD___IS_ARITHMETIC;
    case 250: return TokenKind::KEYWORD___IS_FLOATING_POINT;
    case 251: return TokenKind::KEYWORD___IS_INTEGRAL;
    case 252: return TokenKind::KEYWORD___IS_COMPLETE_TYPE;
    case 253: return TokenKind::KEYWORD___IS_VOID;
    case 254: return TokenKind::KEYWORD___IS_ARRAY;
    case 255: return TokenKind::KEYWORD___IS_FUNCTION;
    case 256: return TokenKind::KEYWORD___IS_REFERENCE;
    case 257: return TokenKind::KEYWORD___IS_LVALUE_REFERENCE;
    case 258: return TokenKind::KEYWORD___IS_RVALUE_REFERENCE;
    case 259: return TokenKind::KEYWORD___IS_FUNDAMENTAL;
    case 260: return TokenKind::KEYWORD___IS_OBJECT;
    case 261: return TokenKind::KEYWORD___IS_SCALAR;
    case 262: return TokenKind::KEYWORD___IS_COMPOUND;
    case 263: return TokenKind::KEYWORD___IS_POINTER;
    case 264: return TokenKind::KEYWORD___IS_MEMBER_OBJECT_POINTER;
    case 265: return TokenKind::KEYWORD___IS_MEMBER_FUNCTION_POINTER;
    case 266: return TokenKind::KEYWORD___IS_MEMBER_POINTER;
    case 267: return TokenKind::KEYWORD___IS_CONST;
    case 268: return TokenKind::KEYWORD___IS_VOLATILE;
    case 269: return TokenKind::KEYWORD___IS_SIGNED;
    case 270: return TokenKind::KEYWORD___IS_UNSIGNED;
    case 271: return TokenKind::KEYWORD___IS_SAME;
    case 272: return TokenKind::KEYWORD___IS_CONVERTIBLE;
    case 273: return TokenKind::KEYWORD___ARRAY_RANK;
    case 274: return TokenKind::KEYWORD___ARRAY_EXTENT;
    case 275: return TokenKind::KEYWORD___PRIVATE_EXTERN__;
    case 276: return TokenKind::KEYWORD___MODULE_PRIVATE__;
    case 277: return TokenKind::KEYWORD___DECLSPEC;
    case 278: return TokenKind::KEYWORD___CDECL;
    case 279: return TokenKind::KEYWORD___STDCALL;
    case 280: return TokenKind::KEYWORD___FASTCALL;
    case 281: return TokenKind::KEYWORD___THISCALL;
    case 282: return TokenKind::KEYWORD___REGCALL;
    case 283: return TokenKind::KEYWORD___VECTORCALL;
    case 284: return TokenKind::KEYWORD___FORCEINLINE;
    case 285: return TokenKind::KEYWORD___UNALIGNED;
    case 286: return TokenKind::KEYWORD___SUPER;
    case 287: return TokenKind::KEYWORD___GLOBAL;
    case 288: return TokenKind::KEYWORD___LOCAL;
    case 289: return TokenKind::KEYWORD___CONSTANT;
    case 290: return TokenKind::KEYWORD___PRIVATE;
    case 291: return TokenKind::KEYWORD___GENERIC;
    case 292: return TokenKind::KEYWORD___KERNEL;
    case 293: return TokenKind::KEYWORD___READ_ONLY;
    case 294: return TokenKind::KEYWORD___WRITE_ONLY;
    case 295: return TokenKind::KEYWORD___READ_WRITE;
    case 296: return TokenKind::KEYWORD___BUILTIN_ASTYPE;
    case 297: return TokenKind::KEYWORD_VEC_STEP;
    case 298: return TokenKind::KEYWORD_IMAGE1_DT;
    case 299: return TokenKind::KEYWORD_IMAGE1_DARRAY_T;
    case 300: return TokenKind::KEYWORD_IMAGE1_DBUFFER_T;
    case 301: return TokenKind::KEYWORD_IMAGE2_DT;
    case 302: return TokenKind::KEYWORD_IMAGE2_DARRAY_T;
    case 303: return TokenKind::KEYWORD_IMAGE2_DDEPTH_T;
    case 304: return TokenKind::KEYWORD_IMAGE2_DARRAY_DEPTH_T;
    case 305: return TokenKind::KEYWORD_IMAGE2_DMSAA_T;
    case 306: return TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_T;
    case 307: return TokenKind::KEYWORD_IMAGE2_DMSAA_DEPTH_T;
    case 308: return TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_DEPTH_T;
    case 309: return TokenKind::KEYWORD_IMAGE3_DT;
    case 310: return TokenKind::KEYWORD_PIPE;
    case 311: return TokenKind::KEYWORD_ADDRSPACE_CAST;
    case 312: return TokenKind::KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN;
    case 313: return TokenKind::KEYWORD___PASCAL;
    case 314: return TokenKind::KEYWORD___VECTOR;
    case 315: return TokenKind::KEYWORD___PIXEL;
    case 316: return TokenKind::KEYWORD___BOOLEAN;
    case 317: return TokenKind::KEYWORD___BF16;
    case 318: return TokenKind::KEYWORD_HALF;
    case 319: return TokenKind::KEYWORD___BRIDGE;
    case 320: return TokenKind::KEYWORD___BRIDGE_TRANSFER;
    case 321: return TokenKind::KEYWORD___BRIDGE_RETAINED;
    case 322: return TokenKind::KEYWORD___BRIDGE_RETAIN;
    case 323: return TokenKind::KEYWORD___COVARIANT;
    case 324: return TokenKind::KEYWORD___CONTRAVARIANT;
    case 325: return TokenKind::KEYWORD___KINDOF;
    case 326: return TokenKind::KEYWORD__NONNULL;
    case 327: return TokenKind::KEYWORD__NULLABLE;
    case 328: return TokenKind::KEYWORD__NULLABLE_RESULT;
    case 329: return TokenKind::KEYWORD__NULL_UNSPECIFIED;
    case 330: return TokenKind::KEYWORD___PTR64;
    case 331: return TokenKind::KEYWORD___PTR32;
    case 332: return TokenKind::KEYWORD___SPTR;
    case 333: return TokenKind::KEYWORD___UPTR;
    case 334: return TokenKind::KEYWORD___W64;
    case 335: return TokenKind::KEYWORD___UUIDOF;
    case 336: return TokenKind::KEYWORD___TRY;
    case 337: return TokenKind::KEYWORD___FINALLY;
    case 338: return TokenKind::KEYWORD___LEAVE;
    case 339: return TokenKind::KEYWORD___INT64;
    case 340: return TokenKind::KEYWORD___IF_EXISTS;
    case 341: return TokenKind::KEYWORD___IF_NOT_EXISTS;
    case 342: return TokenKind::KEYWORD___SINGLE_INHERITANCE;
    case 343: return TokenKind::KEYWORD___MULTIPLE_INHERITANCE;
    case 344: return TokenKind::KEYWORD___VIRTUAL_INHERITANCE;
    case 345: return TokenKind::KEYWORD___INTERFACE;
    case 346: return TokenKind::KEYWORD___BUILTIN_CONVERTVECTOR;
    case 347: return TokenKind::KEYWORD___BUILTIN_BIT_CAST;
    case 348: return TokenKind::KEYWORD___BUILTIN_AVAILABLE;
    case 349: return TokenKind::KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME;
    case 350: return TokenKind::KEYWORD___UNKNOWN_ANYTYPE;
    case 351: return TokenKind::ANNOT_CXXSCOPE;
    case 352: return TokenKind::ANNOT_TYPENAME;
    case 353: return TokenKind::ANNOT_TEMPLATE_ID;
    case 354: return TokenKind::ANNOT_NON_TYPE;
    case 355: return TokenKind::ANNOT_NON_TYPE_UNDECLARED;
    case 356: return TokenKind::ANNOT_NON_TYPE_DEPENDENT;
    case 357: return TokenKind::ANNOT_OVERLOAD;
    case 358: return TokenKind::ANNOT_PRIMARY_EXPRESSION;
    case 359: return TokenKind::ANNOT_DECLTYPE;
    case 360: return TokenKind::ANNOT_PRAGMA_UNUSED;
    case 361: return TokenKind::ANNOT_PRAGMA_VIS;
    case 362: return TokenKind::ANNOT_PRAGMA_PACK;
    case 363: return TokenKind::ANNOT_PRAGMA_PARSER_CRASH;
    case 364: return TokenKind::ANNOT_PRAGMA_CAPTURED;
    case 365: return TokenKind::ANNOT_PRAGMA_DUMP;
    case 366: return TokenKind::ANNOT_PRAGMA_MSSTRUCT;
    case 367: return TokenKind::ANNOT_PRAGMA_ALIGN;
    case 368: return TokenKind::ANNOT_PRAGMA_WEAK;
    case 369: return TokenKind::ANNOT_PRAGMA_WEAKALIAS;
    case 370: return TokenKind::ANNOT_PRAGMA_REDEFINE_EXTNAME;
    case 371: return TokenKind::ANNOT_PRAGMA_FP_CONTRACT;
    case 372: return TokenKind::ANNOT_PRAGMA_FENV_ACCESS;
    case 373: return TokenKind::ANNOT_PRAGMA_FENV_ROUND;
    case 374: return TokenKind::ANNOT_PRAGMA_FLOAT_CONTROL;
    case 375: return TokenKind::ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS;
    case 376: return TokenKind::ANNOT_PRAGMA_MS_VTORDISP;
    case 377: return TokenKind::ANNOT_PRAGMA_MS_PRAGMA;
    case 378: return TokenKind::ANNOT_PRAGMA_OPENCL_EXTENSION;
    case 379: return TokenKind::ANNOT_ATTRIBUTE_OPENMP;
    case 380: return TokenKind::ANNOT_PRAGMA_OPENMP;
    case 381: return TokenKind::ANNOT_PRAGMA_OPENMP_END;
    case 382: return TokenKind::ANNOT_PRAGMA_LOOP_HINT;
    case 383: return TokenKind::ANNOT_PRAGMA_FP;
    case 384: return TokenKind::ANNOT_PRAGMA_ATTRIBUTE;
    case 385: return TokenKind::ANNOT_MODULE_INCLUDE;
    case 386: return TokenKind::ANNOT_MODULE_BEGIN;
    case 387: return TokenKind::ANNOT_MODULE_END;
    case 388: return TokenKind::ANNOT_HEADER_UNIT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TokenKind e) {
  switch (e) {
    case TokenKind::UNKNOWN: return "UNKNOWN";
    case TokenKind::END_OF_FILE: return "END_OF_FILE";
    case TokenKind::END_OF_DIRECTIVE: return "END_OF_DIRECTIVE";
    case TokenKind::CODE_COMPLETION: return "CODE_COMPLETION";
    case TokenKind::COMMENT: return "COMMENT";
    case TokenKind::IDENTIFIER: return "IDENTIFIER";
    case TokenKind::WHITESPACE: return "WHITESPACE";
    case TokenKind::NUMERIC_CONSTANT: return "NUMERIC_CONSTANT";
    case TokenKind::CHARACTER_CONSTANT: return "CHARACTER_CONSTANT";
    case TokenKind::WIDE_CHARACTER_CONSTANT: return "WIDE_CHARACTER_CONSTANT";
    case TokenKind::UTF8_CHARACTER_CONSTANT: return "UTF8_CHARACTER_CONSTANT";
    case TokenKind::UTF16_CHARACTER_CONSTANT: return "UTF16_CHARACTER_CONSTANT";
    case TokenKind::UTF32_CHARACTER_CONSTANT: return "UTF32_CHARACTER_CONSTANT";
    case TokenKind::STRING_LITERAL: return "STRING_LITERAL";
    case TokenKind::WIDE_STRING_LITERAL: return "WIDE_STRING_LITERAL";
    case TokenKind::HEADER_NAME: return "HEADER_NAME";
    case TokenKind::UTF8_STRING_LITERAL: return "UTF8_STRING_LITERAL";
    case TokenKind::UTF16_STRING_LITERAL: return "UTF16_STRING_LITERAL";
    case TokenKind::UTF32_STRING_LITERAL: return "UTF32_STRING_LITERAL";
    case TokenKind::L_SQUARE: return "L_SQUARE";
    case TokenKind::R_SQUARE: return "R_SQUARE";
    case TokenKind::L_PARENTHESIS: return "L_PARENTHESIS";
    case TokenKind::R_PARENTHESIS: return "R_PARENTHESIS";
    case TokenKind::L_BRACE: return "L_BRACE";
    case TokenKind::R_BRACE: return "R_BRACE";
    case TokenKind::PERIOD: return "PERIOD";
    case TokenKind::ELLIPSIS: return "ELLIPSIS";
    case TokenKind::AMP: return "AMP";
    case TokenKind::AMP_AMP: return "AMP_AMP";
    case TokenKind::AMP_EQUAL: return "AMP_EQUAL";
    case TokenKind::STAR: return "STAR";
    case TokenKind::STAR_EQUAL: return "STAR_EQUAL";
    case TokenKind::PLUS: return "PLUS";
    case TokenKind::PLUS_PLUS: return "PLUS_PLUS";
    case TokenKind::PLUS_EQUAL: return "PLUS_EQUAL";
    case TokenKind::MINUS: return "MINUS";
    case TokenKind::ARROW: return "ARROW";
    case TokenKind::MINUS_MINUS: return "MINUS_MINUS";
    case TokenKind::MINUS_EQUAL: return "MINUS_EQUAL";
    case TokenKind::TILDE: return "TILDE";
    case TokenKind::EXCLAIM: return "EXCLAIM";
    case TokenKind::EXCLAIM_EQUAL: return "EXCLAIM_EQUAL";
    case TokenKind::SLASH: return "SLASH";
    case TokenKind::SLASH_EQUAL: return "SLASH_EQUAL";
    case TokenKind::PERCENT: return "PERCENT";
    case TokenKind::PERCENT_EQUAL: return "PERCENT_EQUAL";
    case TokenKind::LESS: return "LESS";
    case TokenKind::LESS_LESS: return "LESS_LESS";
    case TokenKind::LESS_EQUAL: return "LESS_EQUAL";
    case TokenKind::LESS_LESS_EQUAL: return "LESS_LESS_EQUAL";
    case TokenKind::SPACESHIP: return "SPACESHIP";
    case TokenKind::GREATER: return "GREATER";
    case TokenKind::GREATER_GREATER: return "GREATER_GREATER";
    case TokenKind::GREATER_EQUAL: return "GREATER_EQUAL";
    case TokenKind::GREATER_GREATER_EQUAL: return "GREATER_GREATER_EQUAL";
    case TokenKind::CARET: return "CARET";
    case TokenKind::CARET_EQUAL: return "CARET_EQUAL";
    case TokenKind::PIPE: return "PIPE";
    case TokenKind::PIPE_PIPE: return "PIPE_PIPE";
    case TokenKind::PIPE_EQUAL: return "PIPE_EQUAL";
    case TokenKind::QUESTION: return "QUESTION";
    case TokenKind::COLON: return "COLON";
    case TokenKind::SEMI: return "SEMI";
    case TokenKind::EQUAL: return "EQUAL";
    case TokenKind::EQUAL_EQUAL: return "EQUAL_EQUAL";
    case TokenKind::COMMA: return "COMMA";
    case TokenKind::HASH: return "HASH";
    case TokenKind::HASH_HASH: return "HASH_HASH";
    case TokenKind::HASHAT: return "HASHAT";
    case TokenKind::PERIOD_STAR: return "PERIOD_STAR";
    case TokenKind::ARROW_STAR: return "ARROW_STAR";
    case TokenKind::COLON_COLON: return "COLON_COLON";
    case TokenKind::AT: return "AT";
    case TokenKind::LESS_LESS_LESS: return "LESS_LESS_LESS";
    case TokenKind::GREATER_GREATER_GREATER: return "GREATER_GREATER_GREATER";
    case TokenKind::CARETCARET: return "CARETCARET";
    case TokenKind::KEYWORD_AUTO: return "KEYWORD_AUTO";
    case TokenKind::KEYWORD_BREAK: return "KEYWORD_BREAK";
    case TokenKind::KEYWORD_CASE: return "KEYWORD_CASE";
    case TokenKind::KEYWORD_CHARACTER: return "KEYWORD_CHARACTER";
    case TokenKind::KEYWORD_CONST: return "KEYWORD_CONST";
    case TokenKind::KEYWORD_CONTINUE: return "KEYWORD_CONTINUE";
    case TokenKind::KEYWORD_DEFAULT: return "KEYWORD_DEFAULT";
    case TokenKind::KEYWORD_DO: return "KEYWORD_DO";
    case TokenKind::KEYWORD_DOUBLE: return "KEYWORD_DOUBLE";
    case TokenKind::KEYWORD_ELSE: return "KEYWORD_ELSE";
    case TokenKind::KEYWORD_ENUM: return "KEYWORD_ENUM";
    case TokenKind::KEYWORD_EXTERN: return "KEYWORD_EXTERN";
    case TokenKind::KEYWORD_FLOAT: return "KEYWORD_FLOAT";
    case TokenKind::KEYWORD_FOR: return "KEYWORD_FOR";
    case TokenKind::KEYWORD_GOTO: return "KEYWORD_GOTO";
    case TokenKind::KEYWORD_IF: return "KEYWORD_IF";
    case TokenKind::KEYWORD_INLINE: return "KEYWORD_INLINE";
    case TokenKind::KEYWORD_INT: return "KEYWORD_INT";
    case TokenKind::KEYWORD__EXT_INT: return "KEYWORD__EXT_INT";
    case TokenKind::KEYWORD_LONG: return "KEYWORD_LONG";
    case TokenKind::KEYWORD_REGISTER: return "KEYWORD_REGISTER";
    case TokenKind::KEYWORD_RESTRICT: return "KEYWORD_RESTRICT";
    case TokenKind::KEYWORD_RETURN: return "KEYWORD_RETURN";
    case TokenKind::KEYWORD_SHORT: return "KEYWORD_SHORT";
    case TokenKind::KEYWORD_SIGNED: return "KEYWORD_SIGNED";
    case TokenKind::KEYWORD_SIZEOF: return "KEYWORD_SIZEOF";
    case TokenKind::KEYWORD_STATIC: return "KEYWORD_STATIC";
    case TokenKind::KEYWORD_STRUCT: return "KEYWORD_STRUCT";
    case TokenKind::KEYWORD_SWITCH: return "KEYWORD_SWITCH";
    case TokenKind::KEYWORD_TYPEDEF: return "KEYWORD_TYPEDEF";
    case TokenKind::KEYWORD_UNION: return "KEYWORD_UNION";
    case TokenKind::KEYWORD_UNSIGNED: return "KEYWORD_UNSIGNED";
    case TokenKind::KEYWORD_VOID: return "KEYWORD_VOID";
    case TokenKind::KEYWORD_VOLATILE: return "KEYWORD_VOLATILE";
    case TokenKind::KEYWORD_WHILE: return "KEYWORD_WHILE";
    case TokenKind::KEYWORD__ALIGNAS: return "KEYWORD__ALIGNAS";
    case TokenKind::KEYWORD__ALIGNOF: return "KEYWORD__ALIGNOF";
    case TokenKind::KEYWORD__ATOMIC: return "KEYWORD__ATOMIC";
    case TokenKind::KEYWORD__BOOLEAN: return "KEYWORD__BOOLEAN";
    case TokenKind::KEYWORD__COMPLEX: return "KEYWORD__COMPLEX";
    case TokenKind::KEYWORD__GENERIC: return "KEYWORD__GENERIC";
    case TokenKind::KEYWORD__IMAGINARY: return "KEYWORD__IMAGINARY";
    case TokenKind::KEYWORD__NORETURN: return "KEYWORD__NORETURN";
    case TokenKind::KEYWORD__STATIC_ASSERT: return "KEYWORD__STATIC_ASSERT";
    case TokenKind::KEYWORD__THREAD_LOCAL: return "KEYWORD__THREAD_LOCAL";
    case TokenKind::KEYWORD___FUNC__: return "KEYWORD___FUNC__";
    case TokenKind::KEYWORD___OBJC_YES: return "KEYWORD___OBJC_YES";
    case TokenKind::KEYWORD___OBJC_NO: return "KEYWORD___OBJC_NO";
    case TokenKind::KEYWORD_ASSEMBLY: return "KEYWORD_ASSEMBLY";
    case TokenKind::KEYWORD_BOOLEAN: return "KEYWORD_BOOLEAN";
    case TokenKind::KEYWORD_CATCH: return "KEYWORD_CATCH";
    case TokenKind::KEYWORD_CLASS: return "KEYWORD_CLASS";
    case TokenKind::KEYWORD_CONST_CAST: return "KEYWORD_CONST_CAST";
    case TokenKind::KEYWORD_DELETE: return "KEYWORD_DELETE";
    case TokenKind::KEYWORD_DYNAMIC_CAST: return "KEYWORD_DYNAMIC_CAST";
    case TokenKind::KEYWORD_EXPLICIT: return "KEYWORD_EXPLICIT";
    case TokenKind::KEYWORD_EXPORT: return "KEYWORD_EXPORT";
    case TokenKind::KEYWORD_FALSE: return "KEYWORD_FALSE";
    case TokenKind::KEYWORD_FRIEND: return "KEYWORD_FRIEND";
    case TokenKind::KEYWORD_MUTABLE: return "KEYWORD_MUTABLE";
    case TokenKind::KEYWORD_NAMESPACE: return "KEYWORD_NAMESPACE";
    case TokenKind::KEYWORD_NEW: return "KEYWORD_NEW";
    case TokenKind::KEYWORD_OPERATOR: return "KEYWORD_OPERATOR";
    case TokenKind::KEYWORD_PRIVATE: return "KEYWORD_PRIVATE";
    case TokenKind::KEYWORD_PROTECTED: return "KEYWORD_PROTECTED";
    case TokenKind::KEYWORD_PUBLIC: return "KEYWORD_PUBLIC";
    case TokenKind::KEYWORD_REINTERPRET_CAST: return "KEYWORD_REINTERPRET_CAST";
    case TokenKind::KEYWORD_STATIC_CAST: return "KEYWORD_STATIC_CAST";
    case TokenKind::KEYWORD_TEMPLATE: return "KEYWORD_TEMPLATE";
    case TokenKind::KEYWORD_THIS: return "KEYWORD_THIS";
    case TokenKind::KEYWORD_THROW: return "KEYWORD_THROW";
    case TokenKind::KEYWORD_TRUE: return "KEYWORD_TRUE";
    case TokenKind::KEYWORD_TRY: return "KEYWORD_TRY";
    case TokenKind::KEYWORD_TYPENAME: return "KEYWORD_TYPENAME";
    case TokenKind::KEYWORD_TYPEID: return "KEYWORD_TYPEID";
    case TokenKind::KEYWORD_USING: return "KEYWORD_USING";
    case TokenKind::KEYWORD_VIRTUAL: return "KEYWORD_VIRTUAL";
    case TokenKind::KEYWORD_WCHAR_T: return "KEYWORD_WCHAR_T";
    case TokenKind::KEYWORD_ALIGNAS: return "KEYWORD_ALIGNAS";
    case TokenKind::KEYWORD_ALIGNOF: return "KEYWORD_ALIGNOF";
    case TokenKind::KEYWORD_CHAR16_T: return "KEYWORD_CHAR16_T";
    case TokenKind::KEYWORD_CHAR32_T: return "KEYWORD_CHAR32_T";
    case TokenKind::KEYWORD_CONSTEXPR: return "KEYWORD_CONSTEXPR";
    case TokenKind::KEYWORD_DECLTYPE: return "KEYWORD_DECLTYPE";
    case TokenKind::KEYWORD_NOEXCEPT: return "KEYWORD_NOEXCEPT";
    case TokenKind::KEYWORD_NULLPTR: return "KEYWORD_NULLPTR";
    case TokenKind::KEYWORD_STATIC_ASSERT: return "KEYWORD_STATIC_ASSERT";
    case TokenKind::KEYWORD_THREAD_LOCAL: return "KEYWORD_THREAD_LOCAL";
    case TokenKind::KEYWORD_CONCEPT: return "KEYWORD_CONCEPT";
    case TokenKind::KEYWORD_REQUIRES: return "KEYWORD_REQUIRES";
    case TokenKind::KEYWORD_CO_AWAIT: return "KEYWORD_CO_AWAIT";
    case TokenKind::KEYWORD_CO_RETURN: return "KEYWORD_CO_RETURN";
    case TokenKind::KEYWORD_CO_YIELD: return "KEYWORD_CO_YIELD";
    case TokenKind::KEYWORD_MODULE: return "KEYWORD_MODULE";
    case TokenKind::KEYWORD_IMPORT: return "KEYWORD_IMPORT";
    case TokenKind::KEYWORD_CONSTEVAL: return "KEYWORD_CONSTEVAL";
    case TokenKind::KEYWORD_CONSTINIT: return "KEYWORD_CONSTINIT";
    case TokenKind::KEYWORD_CHAR8_T: return "KEYWORD_CHAR8_T";
    case TokenKind::KEYWORD__FLOAT16: return "KEYWORD__FLOAT16";
    case TokenKind::KEYWORD__ACCUM: return "KEYWORD__ACCUM";
    case TokenKind::KEYWORD__FRACT: return "KEYWORD__FRACT";
    case TokenKind::KEYWORD__SAT: return "KEYWORD__SAT";
    case TokenKind::KEYWORD__DECIMAL32: return "KEYWORD__DECIMAL32";
    case TokenKind::KEYWORD__DECIMAL64: return "KEYWORD__DECIMAL64";
    case TokenKind::KEYWORD__DECIMAL128: return "KEYWORD__DECIMAL128";
    case TokenKind::KEYWORD___NULL: return "KEYWORD___NULL";
    case TokenKind::KEYWORD___ALIGNOF: return "KEYWORD___ALIGNOF";
    case TokenKind::KEYWORD___ATTRIBUTE: return "KEYWORD___ATTRIBUTE";
    case TokenKind::KEYWORD___BUILTIN_CHOOSE_EXPRESSION: return "KEYWORD___BUILTIN_CHOOSE_EXPRESSION";
    case TokenKind::KEYWORD___BUILTIN_OFFSETOF: return "KEYWORD___BUILTIN_OFFSETOF";
    case TokenKind::KEYWORD___BUILTIN_FILE: return "KEYWORD___BUILTIN_FILE";
    case TokenKind::KEYWORD___BUILTIN_FUNCTION: return "KEYWORD___BUILTIN_FUNCTION";
    case TokenKind::KEYWORD___BUILTIN_LINE: return "KEYWORD___BUILTIN_LINE";
    case TokenKind::KEYWORD___BUILTIN_COLUMN: return "KEYWORD___BUILTIN_COLUMN";
    case TokenKind::KEYWORD___BUILTIN_TYPES_COMPATIBLE_P: return "KEYWORD___BUILTIN_TYPES_COMPATIBLE_P";
    case TokenKind::KEYWORD___BUILTIN_VA_ARGUMENT: return "KEYWORD___BUILTIN_VA_ARGUMENT";
    case TokenKind::KEYWORD___EXTENSION__: return "KEYWORD___EXTENSION__";
    case TokenKind::KEYWORD___FLOAT128: return "KEYWORD___FLOAT128";
    case TokenKind::KEYWORD___IMAG: return "KEYWORD___IMAG";
    case TokenKind::KEYWORD___INT128: return "KEYWORD___INT128";
    case TokenKind::KEYWORD___LABEL__: return "KEYWORD___LABEL__";
    case TokenKind::KEYWORD___REAL: return "KEYWORD___REAL";
    case TokenKind::KEYWORD___THREAD: return "KEYWORD___THREAD";
    case TokenKind::KEYWORD___FUNCTION__: return "KEYWORD___FUNCTION__";
    case TokenKind::KEYWORD___PRETTYFUNCTION__: return "KEYWORD___PRETTYFUNCTION__";
    case TokenKind::KEYWORD___AUTO_TYPE: return "KEYWORD___AUTO_TYPE";
    case TokenKind::KEYWORD_TYPEOF: return "KEYWORD_TYPEOF";
    case TokenKind::KEYWORD___FUNCDNAME__: return "KEYWORD___FUNCDNAME__";
    case TokenKind::KEYWORD___FUNCSIG__: return "KEYWORD___FUNCSIG__";
    case TokenKind::KEYWORD_LFUNCTION__: return "KEYWORD_LFUNCTION__";
    case TokenKind::KEYWORD_LFUNCSIG__: return "KEYWORD_LFUNCSIG__";
    case TokenKind::KEYWORD___IS_INTERFACE_CLASS: return "KEYWORD___IS_INTERFACE_CLASS";
    case TokenKind::KEYWORD___IS_SEALED: return "KEYWORD___IS_SEALED";
    case TokenKind::KEYWORD___IS_DESTRUCTIBLE: return "KEYWORD___IS_DESTRUCTIBLE";
    case TokenKind::KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE: return "KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE";
    case TokenKind::KEYWORD___IS_NOTHROW_DESTRUCTIBLE: return "KEYWORD___IS_NOTHROW_DESTRUCTIBLE";
    case TokenKind::KEYWORD___IS_NOTHROW_ASSIGNABLE: return "KEYWORD___IS_NOTHROW_ASSIGNABLE";
    case TokenKind::KEYWORD___IS_CONSTRUCTIBLE: return "KEYWORD___IS_CONSTRUCTIBLE";
    case TokenKind::KEYWORD___IS_NOTHROW_CONSTRUCTIBLE: return "KEYWORD___IS_NOTHROW_CONSTRUCTIBLE";
    case TokenKind::KEYWORD___IS_ASSIGNABLE: return "KEYWORD___IS_ASSIGNABLE";
    case TokenKind::KEYWORD___HAS_NOTHROW_MOVE_ASSIGN: return "KEYWORD___HAS_NOTHROW_MOVE_ASSIGN";
    case TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN: return "KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN";
    case TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR: return "KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR";
    case TokenKind::KEYWORD___HAS_NOTHROW_ASSIGN: return "KEYWORD___HAS_NOTHROW_ASSIGN";
    case TokenKind::KEYWORD___HAS_NOTHROW_COPY: return "KEYWORD___HAS_NOTHROW_COPY";
    case TokenKind::KEYWORD___HAS_NOTHROW_CONSTRUCTOR: return "KEYWORD___HAS_NOTHROW_CONSTRUCTOR";
    case TokenKind::KEYWORD___HAS_TRIVIAL_ASSIGN: return "KEYWORD___HAS_TRIVIAL_ASSIGN";
    case TokenKind::KEYWORD___HAS_TRIVIAL_COPY: return "KEYWORD___HAS_TRIVIAL_COPY";
    case TokenKind::KEYWORD___HAS_TRIVIAL_CONSTRUCTOR: return "KEYWORD___HAS_TRIVIAL_CONSTRUCTOR";
    case TokenKind::KEYWORD___HAS_TRIVIAL_DESTRUCTOR: return "KEYWORD___HAS_TRIVIAL_DESTRUCTOR";
    case TokenKind::KEYWORD___HAS_VIRTUAL_DESTRUCTOR: return "KEYWORD___HAS_VIRTUAL_DESTRUCTOR";
    case TokenKind::KEYWORD___IS_ABSTRACT: return "KEYWORD___IS_ABSTRACT";
    case TokenKind::KEYWORD___IS_AGGREGATE: return "KEYWORD___IS_AGGREGATE";
    case TokenKind::KEYWORD___IS_BASE_OF: return "KEYWORD___IS_BASE_OF";
    case TokenKind::KEYWORD___IS_CLASS: return "KEYWORD___IS_CLASS";
    case TokenKind::KEYWORD___IS_CONVERTIBLE_TO: return "KEYWORD___IS_CONVERTIBLE_TO";
    case TokenKind::KEYWORD___IS_EMPTY: return "KEYWORD___IS_EMPTY";
    case TokenKind::KEYWORD___IS_ENUM: return "KEYWORD___IS_ENUM";
    case TokenKind::KEYWORD___IS_FINAL: return "KEYWORD___IS_FINAL";
    case TokenKind::KEYWORD___IS_LITERAL: return "KEYWORD___IS_LITERAL";
    case TokenKind::KEYWORD___IS_POD: return "KEYWORD___IS_POD";
    case TokenKind::KEYWORD___IS_POLYMORPHIC: return "KEYWORD___IS_POLYMORPHIC";
    case TokenKind::KEYWORD___IS_STANDARD_LAYOUT: return "KEYWORD___IS_STANDARD_LAYOUT";
    case TokenKind::KEYWORD___IS_TRIVIAL: return "KEYWORD___IS_TRIVIAL";
    case TokenKind::KEYWORD___IS_TRIVIALLY_ASSIGNABLE: return "KEYWORD___IS_TRIVIALLY_ASSIGNABLE";
    case TokenKind::KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE: return "KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE";
    case TokenKind::KEYWORD___IS_TRIVIALLY_COPYABLE: return "KEYWORD___IS_TRIVIALLY_COPYABLE";
    case TokenKind::KEYWORD___IS_UNION: return "KEYWORD___IS_UNION";
    case TokenKind::KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS: return "KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS";
    case TokenKind::KEYWORD___UNDERLYING_TYPE: return "KEYWORD___UNDERLYING_TYPE";
    case TokenKind::KEYWORD___REFERENCE_BINDS_TO_TEMPORARY: return "KEYWORD___REFERENCE_BINDS_TO_TEMPORARY";
    case TokenKind::KEYWORD___IS_LVALUE_EXPRESSION: return "KEYWORD___IS_LVALUE_EXPRESSION";
    case TokenKind::KEYWORD___IS_RVALUE_EXPRESSION: return "KEYWORD___IS_RVALUE_EXPRESSION";
    case TokenKind::KEYWORD___IS_ARITHMETIC: return "KEYWORD___IS_ARITHMETIC";
    case TokenKind::KEYWORD___IS_FLOATING_POINT: return "KEYWORD___IS_FLOATING_POINT";
    case TokenKind::KEYWORD___IS_INTEGRAL: return "KEYWORD___IS_INTEGRAL";
    case TokenKind::KEYWORD___IS_COMPLETE_TYPE: return "KEYWORD___IS_COMPLETE_TYPE";
    case TokenKind::KEYWORD___IS_VOID: return "KEYWORD___IS_VOID";
    case TokenKind::KEYWORD___IS_ARRAY: return "KEYWORD___IS_ARRAY";
    case TokenKind::KEYWORD___IS_FUNCTION: return "KEYWORD___IS_FUNCTION";
    case TokenKind::KEYWORD___IS_REFERENCE: return "KEYWORD___IS_REFERENCE";
    case TokenKind::KEYWORD___IS_LVALUE_REFERENCE: return "KEYWORD___IS_LVALUE_REFERENCE";
    case TokenKind::KEYWORD___IS_RVALUE_REFERENCE: return "KEYWORD___IS_RVALUE_REFERENCE";
    case TokenKind::KEYWORD___IS_FUNDAMENTAL: return "KEYWORD___IS_FUNDAMENTAL";
    case TokenKind::KEYWORD___IS_OBJECT: return "KEYWORD___IS_OBJECT";
    case TokenKind::KEYWORD___IS_SCALAR: return "KEYWORD___IS_SCALAR";
    case TokenKind::KEYWORD___IS_COMPOUND: return "KEYWORD___IS_COMPOUND";
    case TokenKind::KEYWORD___IS_POINTER: return "KEYWORD___IS_POINTER";
    case TokenKind::KEYWORD___IS_MEMBER_OBJECT_POINTER: return "KEYWORD___IS_MEMBER_OBJECT_POINTER";
    case TokenKind::KEYWORD___IS_MEMBER_FUNCTION_POINTER: return "KEYWORD___IS_MEMBER_FUNCTION_POINTER";
    case TokenKind::KEYWORD___IS_MEMBER_POINTER: return "KEYWORD___IS_MEMBER_POINTER";
    case TokenKind::KEYWORD___IS_CONST: return "KEYWORD___IS_CONST";
    case TokenKind::KEYWORD___IS_VOLATILE: return "KEYWORD___IS_VOLATILE";
    case TokenKind::KEYWORD___IS_SIGNED: return "KEYWORD___IS_SIGNED";
    case TokenKind::KEYWORD___IS_UNSIGNED: return "KEYWORD___IS_UNSIGNED";
    case TokenKind::KEYWORD___IS_SAME: return "KEYWORD___IS_SAME";
    case TokenKind::KEYWORD___IS_CONVERTIBLE: return "KEYWORD___IS_CONVERTIBLE";
    case TokenKind::KEYWORD___ARRAY_RANK: return "KEYWORD___ARRAY_RANK";
    case TokenKind::KEYWORD___ARRAY_EXTENT: return "KEYWORD___ARRAY_EXTENT";
    case TokenKind::KEYWORD___PRIVATE_EXTERN__: return "KEYWORD___PRIVATE_EXTERN__";
    case TokenKind::KEYWORD___MODULE_PRIVATE__: return "KEYWORD___MODULE_PRIVATE__";
    case TokenKind::KEYWORD___DECLSPEC: return "KEYWORD___DECLSPEC";
    case TokenKind::KEYWORD___CDECL: return "KEYWORD___CDECL";
    case TokenKind::KEYWORD___STDCALL: return "KEYWORD___STDCALL";
    case TokenKind::KEYWORD___FASTCALL: return "KEYWORD___FASTCALL";
    case TokenKind::KEYWORD___THISCALL: return "KEYWORD___THISCALL";
    case TokenKind::KEYWORD___REGCALL: return "KEYWORD___REGCALL";
    case TokenKind::KEYWORD___VECTORCALL: return "KEYWORD___VECTORCALL";
    case TokenKind::KEYWORD___FORCEINLINE: return "KEYWORD___FORCEINLINE";
    case TokenKind::KEYWORD___UNALIGNED: return "KEYWORD___UNALIGNED";
    case TokenKind::KEYWORD___SUPER: return "KEYWORD___SUPER";
    case TokenKind::KEYWORD___GLOBAL: return "KEYWORD___GLOBAL";
    case TokenKind::KEYWORD___LOCAL: return "KEYWORD___LOCAL";
    case TokenKind::KEYWORD___CONSTANT: return "KEYWORD___CONSTANT";
    case TokenKind::KEYWORD___PRIVATE: return "KEYWORD___PRIVATE";
    case TokenKind::KEYWORD___GENERIC: return "KEYWORD___GENERIC";
    case TokenKind::KEYWORD___KERNEL: return "KEYWORD___KERNEL";
    case TokenKind::KEYWORD___READ_ONLY: return "KEYWORD___READ_ONLY";
    case TokenKind::KEYWORD___WRITE_ONLY: return "KEYWORD___WRITE_ONLY";
    case TokenKind::KEYWORD___READ_WRITE: return "KEYWORD___READ_WRITE";
    case TokenKind::KEYWORD___BUILTIN_ASTYPE: return "KEYWORD___BUILTIN_ASTYPE";
    case TokenKind::KEYWORD_VEC_STEP: return "KEYWORD_VEC_STEP";
    case TokenKind::KEYWORD_IMAGE1_DT: return "KEYWORD_IMAGE1_DT";
    case TokenKind::KEYWORD_IMAGE1_DARRAY_T: return "KEYWORD_IMAGE1_DARRAY_T";
    case TokenKind::KEYWORD_IMAGE1_DBUFFER_T: return "KEYWORD_IMAGE1_DBUFFER_T";
    case TokenKind::KEYWORD_IMAGE2_DT: return "KEYWORD_IMAGE2_DT";
    case TokenKind::KEYWORD_IMAGE2_DARRAY_T: return "KEYWORD_IMAGE2_DARRAY_T";
    case TokenKind::KEYWORD_IMAGE2_DDEPTH_T: return "KEYWORD_IMAGE2_DDEPTH_T";
    case TokenKind::KEYWORD_IMAGE2_DARRAY_DEPTH_T: return "KEYWORD_IMAGE2_DARRAY_DEPTH_T";
    case TokenKind::KEYWORD_IMAGE2_DMSAA_T: return "KEYWORD_IMAGE2_DMSAA_T";
    case TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_T: return "KEYWORD_IMAGE2_DARRAY_MSAA_T";
    case TokenKind::KEYWORD_IMAGE2_DMSAA_DEPTH_T: return "KEYWORD_IMAGE2_DMSAA_DEPTH_T";
    case TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_DEPTH_T: return "KEYWORD_IMAGE2_DARRAY_MSAA_DEPTH_T";
    case TokenKind::KEYWORD_IMAGE3_DT: return "KEYWORD_IMAGE3_DT";
    case TokenKind::KEYWORD_PIPE: return "KEYWORD_PIPE";
    case TokenKind::KEYWORD_ADDRSPACE_CAST: return "KEYWORD_ADDRSPACE_CAST";
    case TokenKind::KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN: return "KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN";
    case TokenKind::KEYWORD___PASCAL: return "KEYWORD___PASCAL";
    case TokenKind::KEYWORD___VECTOR: return "KEYWORD___VECTOR";
    case TokenKind::KEYWORD___PIXEL: return "KEYWORD___PIXEL";
    case TokenKind::KEYWORD___BOOLEAN: return "KEYWORD___BOOLEAN";
    case TokenKind::KEYWORD___BF16: return "KEYWORD___BF16";
    case TokenKind::KEYWORD_HALF: return "KEYWORD_HALF";
    case TokenKind::KEYWORD___BRIDGE: return "KEYWORD___BRIDGE";
    case TokenKind::KEYWORD___BRIDGE_TRANSFER: return "KEYWORD___BRIDGE_TRANSFER";
    case TokenKind::KEYWORD___BRIDGE_RETAINED: return "KEYWORD___BRIDGE_RETAINED";
    case TokenKind::KEYWORD___BRIDGE_RETAIN: return "KEYWORD___BRIDGE_RETAIN";
    case TokenKind::KEYWORD___COVARIANT: return "KEYWORD___COVARIANT";
    case TokenKind::KEYWORD___CONTRAVARIANT: return "KEYWORD___CONTRAVARIANT";
    case TokenKind::KEYWORD___KINDOF: return "KEYWORD___KINDOF";
    case TokenKind::KEYWORD__NONNULL: return "KEYWORD__NONNULL";
    case TokenKind::KEYWORD__NULLABLE: return "KEYWORD__NULLABLE";
    case TokenKind::KEYWORD__NULLABLE_RESULT: return "KEYWORD__NULLABLE_RESULT";
    case TokenKind::KEYWORD__NULL_UNSPECIFIED: return "KEYWORD__NULL_UNSPECIFIED";
    case TokenKind::KEYWORD___PTR64: return "KEYWORD___PTR64";
    case TokenKind::KEYWORD___PTR32: return "KEYWORD___PTR32";
    case TokenKind::KEYWORD___SPTR: return "KEYWORD___SPTR";
    case TokenKind::KEYWORD___UPTR: return "KEYWORD___UPTR";
    case TokenKind::KEYWORD___W64: return "KEYWORD___W64";
    case TokenKind::KEYWORD___UUIDOF: return "KEYWORD___UUIDOF";
    case TokenKind::KEYWORD___TRY: return "KEYWORD___TRY";
    case TokenKind::KEYWORD___FINALLY: return "KEYWORD___FINALLY";
    case TokenKind::KEYWORD___LEAVE: return "KEYWORD___LEAVE";
    case TokenKind::KEYWORD___INT64: return "KEYWORD___INT64";
    case TokenKind::KEYWORD___IF_EXISTS: return "KEYWORD___IF_EXISTS";
    case TokenKind::KEYWORD___IF_NOT_EXISTS: return "KEYWORD___IF_NOT_EXISTS";
    case TokenKind::KEYWORD___SINGLE_INHERITANCE: return "KEYWORD___SINGLE_INHERITANCE";
    case TokenKind::KEYWORD___MULTIPLE_INHERITANCE: return "KEYWORD___MULTIPLE_INHERITANCE";
    case TokenKind::KEYWORD___VIRTUAL_INHERITANCE: return "KEYWORD___VIRTUAL_INHERITANCE";
    case TokenKind::KEYWORD___INTERFACE: return "KEYWORD___INTERFACE";
    case TokenKind::KEYWORD___BUILTIN_CONVERTVECTOR: return "KEYWORD___BUILTIN_CONVERTVECTOR";
    case TokenKind::KEYWORD___BUILTIN_BIT_CAST: return "KEYWORD___BUILTIN_BIT_CAST";
    case TokenKind::KEYWORD___BUILTIN_AVAILABLE: return "KEYWORD___BUILTIN_AVAILABLE";
    case TokenKind::KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME: return "KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME";
    case TokenKind::KEYWORD___UNKNOWN_ANYTYPE: return "KEYWORD___UNKNOWN_ANYTYPE";
    case TokenKind::ANNOT_CXXSCOPE: return "ANNOT_CXXSCOPE";
    case TokenKind::ANNOT_TYPENAME: return "ANNOT_TYPENAME";
    case TokenKind::ANNOT_TEMPLATE_ID: return "ANNOT_TEMPLATE_ID";
    case TokenKind::ANNOT_NON_TYPE: return "ANNOT_NON_TYPE";
    case TokenKind::ANNOT_NON_TYPE_UNDECLARED: return "ANNOT_NON_TYPE_UNDECLARED";
    case TokenKind::ANNOT_NON_TYPE_DEPENDENT: return "ANNOT_NON_TYPE_DEPENDENT";
    case TokenKind::ANNOT_OVERLOAD: return "ANNOT_OVERLOAD";
    case TokenKind::ANNOT_PRIMARY_EXPRESSION: return "ANNOT_PRIMARY_EXPRESSION";
    case TokenKind::ANNOT_DECLTYPE: return "ANNOT_DECLTYPE";
    case TokenKind::ANNOT_PRAGMA_UNUSED: return "ANNOT_PRAGMA_UNUSED";
    case TokenKind::ANNOT_PRAGMA_VIS: return "ANNOT_PRAGMA_VIS";
    case TokenKind::ANNOT_PRAGMA_PACK: return "ANNOT_PRAGMA_PACK";
    case TokenKind::ANNOT_PRAGMA_PARSER_CRASH: return "ANNOT_PRAGMA_PARSER_CRASH";
    case TokenKind::ANNOT_PRAGMA_CAPTURED: return "ANNOT_PRAGMA_CAPTURED";
    case TokenKind::ANNOT_PRAGMA_DUMP: return "ANNOT_PRAGMA_DUMP";
    case TokenKind::ANNOT_PRAGMA_MSSTRUCT: return "ANNOT_PRAGMA_MSSTRUCT";
    case TokenKind::ANNOT_PRAGMA_ALIGN: return "ANNOT_PRAGMA_ALIGN";
    case TokenKind::ANNOT_PRAGMA_WEAK: return "ANNOT_PRAGMA_WEAK";
    case TokenKind::ANNOT_PRAGMA_WEAKALIAS: return "ANNOT_PRAGMA_WEAKALIAS";
    case TokenKind::ANNOT_PRAGMA_REDEFINE_EXTNAME: return "ANNOT_PRAGMA_REDEFINE_EXTNAME";
    case TokenKind::ANNOT_PRAGMA_FP_CONTRACT: return "ANNOT_PRAGMA_FP_CONTRACT";
    case TokenKind::ANNOT_PRAGMA_FENV_ACCESS: return "ANNOT_PRAGMA_FENV_ACCESS";
    case TokenKind::ANNOT_PRAGMA_FENV_ROUND: return "ANNOT_PRAGMA_FENV_ROUND";
    case TokenKind::ANNOT_PRAGMA_FLOAT_CONTROL: return "ANNOT_PRAGMA_FLOAT_CONTROL";
    case TokenKind::ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS: return "ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS";
    case TokenKind::ANNOT_PRAGMA_MS_VTORDISP: return "ANNOT_PRAGMA_MS_VTORDISP";
    case TokenKind::ANNOT_PRAGMA_MS_PRAGMA: return "ANNOT_PRAGMA_MS_PRAGMA";
    case TokenKind::ANNOT_PRAGMA_OPENCL_EXTENSION: return "ANNOT_PRAGMA_OPENCL_EXTENSION";
    case TokenKind::ANNOT_ATTRIBUTE_OPENMP: return "ANNOT_ATTRIBUTE_OPENMP";
    case TokenKind::ANNOT_PRAGMA_OPENMP: return "ANNOT_PRAGMA_OPENMP";
    case TokenKind::ANNOT_PRAGMA_OPENMP_END: return "ANNOT_PRAGMA_OPENMP_END";
    case TokenKind::ANNOT_PRAGMA_LOOP_HINT: return "ANNOT_PRAGMA_LOOP_HINT";
    case TokenKind::ANNOT_PRAGMA_FP: return "ANNOT_PRAGMA_FP";
    case TokenKind::ANNOT_PRAGMA_ATTRIBUTE: return "ANNOT_PRAGMA_ATTRIBUTE";
    case TokenKind::ANNOT_MODULE_INCLUDE: return "ANNOT_MODULE_INCLUDE";
    case TokenKind::ANNOT_MODULE_BEGIN: return "ANNOT_MODULE_BEGIN";
    case TokenKind::ANNOT_MODULE_END: return "ANNOT_MODULE_END";
    case TokenKind::ANNOT_HEADER_UNIT: return "ANNOT_HEADER_UNIT";
    case TokenKind::PP_IF: return "PP_IF";
    case TokenKind::PP_IFDEF: return "PP_IFDEF";
    case TokenKind::PP_IFNDEF: return "PP_IFNDEF";
    case TokenKind::PP_ELIF: return "PP_ELIF";
    case TokenKind::PP_ELIFDEF: return "PP_ELIFDEF";
    case TokenKind::PP_ELIFNDEF: return "PP_ELIFNDEF";
    case TokenKind::PP_ELSE: return "PP_ELSE";
    case TokenKind::PP_ENDIF: return "PP_ENDIF";
    case TokenKind::PP_DEFINED: return "PP_DEFINED";
    case TokenKind::PP_INCLUDE: return "PP_INCLUDE";
    case TokenKind::PP___INCLUDE_MACROS: return "PP___INCLUDE_MACROS";
    case TokenKind::PP_DEFINE: return "PP_DEFINE";
    case TokenKind::PP_UNDEF: return "PP_UNDEF";
    case TokenKind::PP_LINE: return "PP_LINE";
    case TokenKind::PP_ERROR: return "PP_ERROR";
    case TokenKind::PP_PRAGMA: return "PP_PRAGMA";
    case TokenKind::PP_IMPORT: return "PP_IMPORT";
    case TokenKind::PP_INCLUDE_NEXT: return "PP_INCLUDE_NEXT";
    case TokenKind::PP_WARNING: return "PP_WARNING";
    case TokenKind::PP_IDENTIFIER: return "PP_IDENTIFIER";
    case TokenKind::PP_SCCS: return "PP_SCCS";
    case TokenKind::PP_ASSERT: return "PP_ASSERT";
    case TokenKind::PP_UNASSERT: return "PP_UNASSERT";
    case TokenKind::PP___PUBLIC_MACRO: return "PP___PUBLIC_MACRO";
    case TokenKind::PP___PRIVATE_MACRO: return "PP___PRIVATE_MACRO";
    case TokenKind::OBJC_AT_CLASS: return "OBJC_AT_CLASS";
    case TokenKind::OBJC_AT_COMPATIBILITY_ALIAS: return "OBJC_AT_COMPATIBILITY_ALIAS";
    case TokenKind::OBJC_AT_DEFINITIONS: return "OBJC_AT_DEFINITIONS";
    case TokenKind::OBJC_AT_ENCODE: return "OBJC_AT_ENCODE";
    case TokenKind::OBJC_AT_OBJC_END: return "OBJC_AT_OBJC_END";
    case TokenKind::OBJC_AT_IMPLEMENTATION: return "OBJC_AT_IMPLEMENTATION";
    case TokenKind::OBJC_AT_INTERFACE: return "OBJC_AT_INTERFACE";
    case TokenKind::OBJC_AT_PRIVATE: return "OBJC_AT_PRIVATE";
    case TokenKind::OBJC_AT_PROTECTED: return "OBJC_AT_PROTECTED";
    case TokenKind::OBJC_AT_PROTOCOL: return "OBJC_AT_PROTOCOL";
    case TokenKind::OBJC_AT_PUBLIC: return "OBJC_AT_PUBLIC";
    case TokenKind::OBJC_AT_SELECTOR: return "OBJC_AT_SELECTOR";
    case TokenKind::OBJC_AT_THROW: return "OBJC_AT_THROW";
    case TokenKind::OBJC_AT_TRY: return "OBJC_AT_TRY";
    case TokenKind::OBJC_AT_CATCH: return "OBJC_AT_CATCH";
    case TokenKind::OBJC_AT_FINALLY: return "OBJC_AT_FINALLY";
    case TokenKind::OBJC_AT_SYNCHRONIZED: return "OBJC_AT_SYNCHRONIZED";
    case TokenKind::OBJC_AT_AUTORELEASEPOOL: return "OBJC_AT_AUTORELEASEPOOL";
    case TokenKind::OBJC_AT_PROPERTY: return "OBJC_AT_PROPERTY";
    case TokenKind::OBJC_AT_PACKAGE: return "OBJC_AT_PACKAGE";
    case TokenKind::OBJC_AT_REQUIRED: return "OBJC_AT_REQUIRED";
    case TokenKind::OBJC_AT_OPTIONAL: return "OBJC_AT_OPTIONAL";
    case TokenKind::OBJC_AT_SYNTHESIZE: return "OBJC_AT_SYNTHESIZE";
    case TokenKind::OBJC_AT_DYNAMIC: return "OBJC_AT_DYNAMIC";
    case TokenKind::OBJC_AT_IMPORT: return "OBJC_AT_IMPORT";
    case TokenKind::OBJC_AT_AVAILABLE: return "OBJC_AT_AVAILABLE";
    default: return "<invalid>";
  }
}

TrailingAllocKind FromPasta(pasta::TrailingAllocKind e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return TrailingAllocKind::TAK_INHERITS_CONSTRUCTOR;
    case 2: return TrailingAllocKind::TAK_HAS_TAIL_EXPLICIT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TrailingAllocKind e) {
  switch (e) {
    case TrailingAllocKind::TAK_INHERITS_CONSTRUCTOR: return "TAK_INHERITS_CONSTRUCTOR";
    case TrailingAllocKind::TAK_HAS_TAIL_EXPLICIT: return "TAK_HAS_TAIL_EXPLICIT";
    default: return "<invalid>";
  }
}

TranslationUnitKind FromPasta(pasta::TranslationUnitKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TranslationUnitKind::COMPLETE;
    case 1: return TranslationUnitKind::PREFIX;
    case 2: return TranslationUnitKind::MODULE;
    case 3: return TranslationUnitKind::INCREMENTAL;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TranslationUnitKind e) {
  switch (e) {
    case TranslationUnitKind::COMPLETE: return "COMPLETE";
    case TranslationUnitKind::PREFIX: return "PREFIX";
    case TranslationUnitKind::MODULE: return "MODULE";
    case TranslationUnitKind::INCREMENTAL: return "INCREMENTAL";
    default: return "<invalid>";
  }
}

TrivialAutoVarInitKind FromPasta(pasta::TrivialAutoVarInitKind e) {
  switch (static_cast<int>(e)) {
    case 0: return TrivialAutoVarInitKind::UNINITIALIZED;
    case 1: return TrivialAutoVarInitKind::ZERO;
    case 2: return TrivialAutoVarInitKind::PATTERN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TrivialAutoVarInitKind e) {
  switch (e) {
    case TrivialAutoVarInitKind::UNINITIALIZED: return "UNINITIALIZED";
    case TrivialAutoVarInitKind::ZERO: return "ZERO";
    case TrivialAutoVarInitKind::PATTERN: return "PATTERN";
    default: return "<invalid>";
  }
}

TypeDependence FromPasta(pasta::TypeDependence e) {
  switch (static_cast<unsigned char>(e)) {
    case 1: return TypeDependence::UNEXPANDED_PACK;
    case 2: return TypeDependence::INSTANTIATION;
    case 4: return TypeDependence::DEPENDENT;
    case 8: return TypeDependence::VARIABLY_MODIFIED;
    case 16: return TypeDependence::ERROR;
    case 0: return TypeDependence::NONE;
    case 31: return TypeDependence::ALL;
    case 6: return TypeDependence::DEPENDENT_INSTANTIATION;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeDependence e) {
  switch (e) {
    case TypeDependence::UNEXPANDED_PACK: return "UNEXPANDED_PACK";
    case TypeDependence::INSTANTIATION: return "INSTANTIATION";
    case TypeDependence::DEPENDENT: return "DEPENDENT";
    case TypeDependence::VARIABLY_MODIFIED: return "VARIABLY_MODIFIED";
    case TypeDependence::ERROR: return "ERROR";
    case TypeDependence::NONE: return "NONE";
    case TypeDependence::ALL: return "ALL";
    case TypeDependence::DEPENDENT_INSTANTIATION: return "DEPENDENT_INSTANTIATION";
    default: return "<invalid>";
  }
}

TypeLocClass FromPasta(pasta::TypeLocClass e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeLocClass::ADJUSTED;
    case 1: return TypeLocClass::DECAYED;
    case 2: return TypeLocClass::CONSTANT_ARRAY;
    case 3: return TypeLocClass::DEPENDENT_SIZED_ARRAY;
    case 4: return TypeLocClass::INCOMPLETE_ARRAY;
    case 5: return TypeLocClass::VARIABLE_ARRAY;
    case 6: return TypeLocClass::ATOMIC;
    case 7: return TypeLocClass::ATTRIBUTED;
    case 8: return TypeLocClass::BLOCK_POINTER;
    case 9: return TypeLocClass::BUILTIN;
    case 10: return TypeLocClass::COMPLEX;
    case 11: return TypeLocClass::DECLTYPE;
    case 12: return TypeLocClass::AUTO;
    case 13: return TypeLocClass::DEDUCED_TEMPLATE_SPECIALIZATION;
    case 14: return TypeLocClass::DEPENDENT_ADDRESS_SPACE;
    case 15: return TypeLocClass::DEPENDENT_EXT_INT;
    case 16: return TypeLocClass::DEPENDENT_NAME;
    case 17: return TypeLocClass::DEPENDENT_SIZED_EXT_VECTOR;
    case 18: return TypeLocClass::DEPENDENT_TEMPLATE_SPECIALIZATION;
    case 19: return TypeLocClass::DEPENDENT_VECTOR;
    case 20: return TypeLocClass::ELABORATED;
    case 21: return TypeLocClass::EXT_INT;
    case 22: return TypeLocClass::FUNCTION_NO_PROTO;
    case 23: return TypeLocClass::FUNCTION_PROTO;
    case 24: return TypeLocClass::INJECTED_CLASS_NAME;
    case 25: return TypeLocClass::MACRO_QUALIFIED;
    case 26: return TypeLocClass::CONSTANT_MATRIX;
    case 27: return TypeLocClass::DEPENDENT_SIZED_MATRIX;
    case 28: return TypeLocClass::MEMBER_POINTER;
    case 29: return TypeLocClass::OBJ_C_OBJECT_POINTER;
    case 30: return TypeLocClass::OBJ_C_OBJECT;
    case 31: return TypeLocClass::OBJ_C_INTERFACE;
    case 32: return TypeLocClass::OBJ_C_TYPE_PARAMETER;
    case 33: return TypeLocClass::PACK_EXPANSION;
    case 34: return TypeLocClass::PARENTHESIS;
    case 35: return TypeLocClass::PIPE;
    case 36: return TypeLocClass::POINTER;
    case 37: return TypeLocClass::L_VALUE_REFERENCE;
    case 38: return TypeLocClass::R_VALUE_REFERENCE;
    case 39: return TypeLocClass::SUBST_TEMPLATE_TYPE_PARM_PACK;
    case 40: return TypeLocClass::SUBST_TEMPLATE_TYPE_PARM;
    case 41: return TypeLocClass::ENUM;
    case 42: return TypeLocClass::RECORD;
    case 43: return TypeLocClass::TEMPLATE_SPECIALIZATION;
    case 44: return TypeLocClass::TEMPLATE_TYPE_PARM;
    case 45: return TypeLocClass::TYPE_OF_EXPRESSION;
    case 46: return TypeLocClass::TYPE_OF;
    case 47: return TypeLocClass::TYPEDEF;
    case 48: return TypeLocClass::UNARY_TRANSFORM;
    case 49: return TypeLocClass::UNRESOLVED_USING;
    case 50: return TypeLocClass::VECTOR;
    case 51: return TypeLocClass::EXT_VECTOR;
    case 52: return TypeLocClass::QUALIFIED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeLocClass e) {
  switch (e) {
    case TypeLocClass::ADJUSTED: return "ADJUSTED";
    case TypeLocClass::DECAYED: return "DECAYED";
    case TypeLocClass::CONSTANT_ARRAY: return "CONSTANT_ARRAY";
    case TypeLocClass::DEPENDENT_SIZED_ARRAY: return "DEPENDENT_SIZED_ARRAY";
    case TypeLocClass::INCOMPLETE_ARRAY: return "INCOMPLETE_ARRAY";
    case TypeLocClass::VARIABLE_ARRAY: return "VARIABLE_ARRAY";
    case TypeLocClass::ATOMIC: return "ATOMIC";
    case TypeLocClass::ATTRIBUTED: return "ATTRIBUTED";
    case TypeLocClass::BLOCK_POINTER: return "BLOCK_POINTER";
    case TypeLocClass::BUILTIN: return "BUILTIN";
    case TypeLocClass::COMPLEX: return "COMPLEX";
    case TypeLocClass::DECLTYPE: return "DECLTYPE";
    case TypeLocClass::AUTO: return "AUTO";
    case TypeLocClass::DEDUCED_TEMPLATE_SPECIALIZATION: return "DEDUCED_TEMPLATE_SPECIALIZATION";
    case TypeLocClass::DEPENDENT_ADDRESS_SPACE: return "DEPENDENT_ADDRESS_SPACE";
    case TypeLocClass::DEPENDENT_EXT_INT: return "DEPENDENT_EXT_INT";
    case TypeLocClass::DEPENDENT_NAME: return "DEPENDENT_NAME";
    case TypeLocClass::DEPENDENT_SIZED_EXT_VECTOR: return "DEPENDENT_SIZED_EXT_VECTOR";
    case TypeLocClass::DEPENDENT_TEMPLATE_SPECIALIZATION: return "DEPENDENT_TEMPLATE_SPECIALIZATION";
    case TypeLocClass::DEPENDENT_VECTOR: return "DEPENDENT_VECTOR";
    case TypeLocClass::ELABORATED: return "ELABORATED";
    case TypeLocClass::EXT_INT: return "EXT_INT";
    case TypeLocClass::FUNCTION_NO_PROTO: return "FUNCTION_NO_PROTO";
    case TypeLocClass::FUNCTION_PROTO: return "FUNCTION_PROTO";
    case TypeLocClass::INJECTED_CLASS_NAME: return "INJECTED_CLASS_NAME";
    case TypeLocClass::MACRO_QUALIFIED: return "MACRO_QUALIFIED";
    case TypeLocClass::CONSTANT_MATRIX: return "CONSTANT_MATRIX";
    case TypeLocClass::DEPENDENT_SIZED_MATRIX: return "DEPENDENT_SIZED_MATRIX";
    case TypeLocClass::MEMBER_POINTER: return "MEMBER_POINTER";
    case TypeLocClass::OBJ_C_OBJECT_POINTER: return "OBJ_C_OBJECT_POINTER";
    case TypeLocClass::OBJ_C_OBJECT: return "OBJ_C_OBJECT";
    case TypeLocClass::OBJ_C_INTERFACE: return "OBJ_C_INTERFACE";
    case TypeLocClass::OBJ_C_TYPE_PARAMETER: return "OBJ_C_TYPE_PARAMETER";
    case TypeLocClass::PACK_EXPANSION: return "PACK_EXPANSION";
    case TypeLocClass::PARENTHESIS: return "PARENTHESIS";
    case TypeLocClass::PIPE: return "PIPE";
    case TypeLocClass::POINTER: return "POINTER";
    case TypeLocClass::L_VALUE_REFERENCE: return "L_VALUE_REFERENCE";
    case TypeLocClass::R_VALUE_REFERENCE: return "R_VALUE_REFERENCE";
    case TypeLocClass::SUBST_TEMPLATE_TYPE_PARM_PACK: return "SUBST_TEMPLATE_TYPE_PARM_PACK";
    case TypeLocClass::SUBST_TEMPLATE_TYPE_PARM: return "SUBST_TEMPLATE_TYPE_PARM";
    case TypeLocClass::ENUM: return "ENUM";
    case TypeLocClass::RECORD: return "RECORD";
    case TypeLocClass::TEMPLATE_SPECIALIZATION: return "TEMPLATE_SPECIALIZATION";
    case TypeLocClass::TEMPLATE_TYPE_PARM: return "TEMPLATE_TYPE_PARM";
    case TypeLocClass::TYPE_OF_EXPRESSION: return "TYPE_OF_EXPRESSION";
    case TypeLocClass::TYPE_OF: return "TYPE_OF";
    case TypeLocClass::TYPEDEF: return "TYPEDEF";
    case TypeLocClass::UNARY_TRANSFORM: return "UNARY_TRANSFORM";
    case TypeLocClass::UNRESOLVED_USING: return "UNRESOLVED_USING";
    case TypeLocClass::VECTOR: return "VECTOR";
    case TypeLocClass::EXT_VECTOR: return "EXT_VECTOR";
    case TypeLocClass::QUALIFIED: return "QUALIFIED";
    default: return "<invalid>";
  }
}

TypeSpecifierSign FromPasta(pasta::TypeSpecifierSign e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifierSign::UNSPECIFIED;
    case 1: return TypeSpecifierSign::SIGNED;
    case 2: return TypeSpecifierSign::UNSIGNED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeSpecifierSign e) {
  switch (e) {
    case TypeSpecifierSign::UNSPECIFIED: return "UNSPECIFIED";
    case TypeSpecifierSign::SIGNED: return "SIGNED";
    case TypeSpecifierSign::UNSIGNED: return "UNSIGNED";
    default: return "<invalid>";
  }
}

TypeSpecifierType FromPasta(pasta::TypeSpecifierType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeSpecifierType::UNSPECIFIED;
    case 1: return TypeSpecifierType::VOID;
    case 2: return TypeSpecifierType::CHARACTER;
    case 3: return TypeSpecifierType::WCHAR;
    case 4: return TypeSpecifierType::CHAR8;
    case 5: return TypeSpecifierType::CHAR16;
    case 6: return TypeSpecifierType::CHAR32;
    case 7: return TypeSpecifierType::INT;
    case 8: return TypeSpecifierType::INT128;
    case 9: return TypeSpecifierType::EXTINT;
    case 10: return TypeSpecifierType::HALF;
    case 11: return TypeSpecifierType::FLOAT16;
    case 12: return TypeSpecifierType::ACCUM;
    case 13: return TypeSpecifierType::FRACT;
    case 14: return TypeSpecifierType::B_FLOAT16;
    case 15: return TypeSpecifierType::FLOAT;
    case 16: return TypeSpecifierType::DOUBLE;
    case 17: return TypeSpecifierType::FLOAT128;
    case 18: return TypeSpecifierType::BOOLEAN;
    case 19: return TypeSpecifierType::DECIMAL32;
    case 20: return TypeSpecifierType::DECIMAL64;
    case 21: return TypeSpecifierType::DECIMAL128;
    case 22: return TypeSpecifierType::ENUM;
    case 23: return TypeSpecifierType::UNION;
    case 24: return TypeSpecifierType::STRUCT;
    case 25: return TypeSpecifierType::CLASS;
    case 26: return TypeSpecifierType::INTERFACE;
    case 27: return TypeSpecifierType::TYPENAME;
    case 28: return TypeSpecifierType::TYPEOF_TYPE;
    case 29: return TypeSpecifierType::TYPEOF_EXPRESSION;
    case 30: return TypeSpecifierType::DECLTYPE;
    case 31: return TypeSpecifierType::UNDERLYING_TYPE;
    case 32: return TypeSpecifierType::AUTO;
    case 33: return TypeSpecifierType::DECLTYPE_AUTO;
    case 34: return TypeSpecifierType::AUTO_TYPE;
    case 35: return TypeSpecifierType::UNKNOWN_ANYTYPE;
    case 36: return TypeSpecifierType::ATOMIC;
    case 37: return TypeSpecifierType::IMAGE1_DT;
    case 38: return TypeSpecifierType::IMAGE1_DARRAY_T;
    case 39: return TypeSpecifierType::IMAGE1_DBUFFER_T;
    case 40: return TypeSpecifierType::IMAGE2_DT;
    case 41: return TypeSpecifierType::IMAGE2_DARRAY_T;
    case 42: return TypeSpecifierType::IMAGE2_DDEPTH_T;
    case 43: return TypeSpecifierType::IMAGE2_DARRAY_DEPTH_T;
    case 44: return TypeSpecifierType::IMAGE2_DMSAA_T;
    case 45: return TypeSpecifierType::IMAGE2_DARRAY_MSAA_T;
    case 46: return TypeSpecifierType::IMAGE2_DMSAA_DEPTH_T;
    case 47: return TypeSpecifierType::IMAGE2_DARRAY_MSAA_DEPTH_T;
    case 48: return TypeSpecifierType::IMAGE3_DT;
    case 49: return TypeSpecifierType::ERROR;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeSpecifierType e) {
  switch (e) {
    case TypeSpecifierType::UNSPECIFIED: return "UNSPECIFIED";
    case TypeSpecifierType::VOID: return "VOID";
    case TypeSpecifierType::CHARACTER: return "CHARACTER";
    case TypeSpecifierType::WCHAR: return "WCHAR";
    case TypeSpecifierType::CHAR8: return "CHAR8";
    case TypeSpecifierType::CHAR16: return "CHAR16";
    case TypeSpecifierType::CHAR32: return "CHAR32";
    case TypeSpecifierType::INT: return "INT";
    case TypeSpecifierType::INT128: return "INT128";
    case TypeSpecifierType::EXTINT: return "EXTINT";
    case TypeSpecifierType::HALF: return "HALF";
    case TypeSpecifierType::FLOAT16: return "FLOAT16";
    case TypeSpecifierType::ACCUM: return "ACCUM";
    case TypeSpecifierType::FRACT: return "FRACT";
    case TypeSpecifierType::B_FLOAT16: return "B_FLOAT16";
    case TypeSpecifierType::FLOAT: return "FLOAT";
    case TypeSpecifierType::DOUBLE: return "DOUBLE";
    case TypeSpecifierType::FLOAT128: return "FLOAT128";
    case TypeSpecifierType::BOOLEAN: return "BOOLEAN";
    case TypeSpecifierType::DECIMAL32: return "DECIMAL32";
    case TypeSpecifierType::DECIMAL64: return "DECIMAL64";
    case TypeSpecifierType::DECIMAL128: return "DECIMAL128";
    case TypeSpecifierType::ENUM: return "ENUM";
    case TypeSpecifierType::UNION: return "UNION";
    case TypeSpecifierType::STRUCT: return "STRUCT";
    case TypeSpecifierType::CLASS: return "CLASS";
    case TypeSpecifierType::INTERFACE: return "INTERFACE";
    case TypeSpecifierType::TYPENAME: return "TYPENAME";
    case TypeSpecifierType::TYPEOF_TYPE: return "TYPEOF_TYPE";
    case TypeSpecifierType::TYPEOF_EXPRESSION: return "TYPEOF_EXPRESSION";
    case TypeSpecifierType::DECLTYPE: return "DECLTYPE";
    case TypeSpecifierType::UNDERLYING_TYPE: return "UNDERLYING_TYPE";
    case TypeSpecifierType::AUTO: return "AUTO";
    case TypeSpecifierType::DECLTYPE_AUTO: return "DECLTYPE_AUTO";
    case TypeSpecifierType::AUTO_TYPE: return "AUTO_TYPE";
    case TypeSpecifierType::UNKNOWN_ANYTYPE: return "UNKNOWN_ANYTYPE";
    case TypeSpecifierType::ATOMIC: return "ATOMIC";
    case TypeSpecifierType::IMAGE1_DT: return "IMAGE1_DT";
    case TypeSpecifierType::IMAGE1_DARRAY_T: return "IMAGE1_DARRAY_T";
    case TypeSpecifierType::IMAGE1_DBUFFER_T: return "IMAGE1_DBUFFER_T";
    case TypeSpecifierType::IMAGE2_DT: return "IMAGE2_DT";
    case TypeSpecifierType::IMAGE2_DARRAY_T: return "IMAGE2_DARRAY_T";
    case TypeSpecifierType::IMAGE2_DDEPTH_T: return "IMAGE2_DDEPTH_T";
    case TypeSpecifierType::IMAGE2_DARRAY_DEPTH_T: return "IMAGE2_DARRAY_DEPTH_T";
    case TypeSpecifierType::IMAGE2_DMSAA_T: return "IMAGE2_DMSAA_T";
    case TypeSpecifierType::IMAGE2_DARRAY_MSAA_T: return "IMAGE2_DARRAY_MSAA_T";
    case TypeSpecifierType::IMAGE2_DMSAA_DEPTH_T: return "IMAGE2_DMSAA_DEPTH_T";
    case TypeSpecifierType::IMAGE2_DARRAY_MSAA_DEPTH_T: return "IMAGE2_DARRAY_MSAA_DEPTH_T";
    case TypeSpecifierType::IMAGE3_DT: return "IMAGE3_DT";
    case TypeSpecifierType::ERROR: return "ERROR";
    default: return "<invalid>";
  }
}

TypeSpecifierWidth FromPasta(pasta::TypeSpecifierWidth e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifierWidth::UNSPECIFIED;
    case 1: return TypeSpecifierWidth::SHORT;
    case 2: return TypeSpecifierWidth::LONG;
    case 3: return TypeSpecifierWidth::LONG_LONG;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeSpecifierWidth e) {
  switch (e) {
    case TypeSpecifierWidth::UNSPECIFIED: return "UNSPECIFIED";
    case TypeSpecifierWidth::SHORT: return "SHORT";
    case TypeSpecifierWidth::LONG: return "LONG";
    case TypeSpecifierWidth::LONG_LONG: return "LONG_LONG";
    default: return "<invalid>";
  }
}

TypeSpecifiersPipe FromPasta(pasta::TypeSpecifiersPipe e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifiersPipe::UNSPECIFIED;
    case 1: return TypeSpecifiersPipe::PIPE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeSpecifiersPipe e) {
  switch (e) {
    case TypeSpecifiersPipe::UNSPECIFIED: return "UNSPECIFIED";
    case TypeSpecifiersPipe::PIPE: return "PIPE";
    default: return "<invalid>";
  }
}

TypeTrait FromPasta(pasta::TypeTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TypeTrait::IS_INTERFACE_CLASS;
    case 1: return TypeTrait::IS_SEALED;
    case 2: return TypeTrait::IS_DESTRUCTIBLE;
    case 3: return TypeTrait::IS_TRIVIALLY_DESTRUCTIBLE;
    case 4: return TypeTrait::IS_NOTHROW_DESTRUCTIBLE;
    case 5: return TypeTrait::HAS_NOTHROW_MOVE_ASSIGN;
    case 6: return TypeTrait::HAS_TRIVIAL_MOVE_ASSIGN;
    case 7: return TypeTrait::HAS_TRIVIAL_MOVE_CONSTRUCTOR;
    case 8: return TypeTrait::HAS_NOTHROW_ASSIGN;
    case 9: return TypeTrait::HAS_NOTHROW_COPY;
    case 10: return TypeTrait::HAS_NOTHROW_CONSTRUCTOR;
    case 11: return TypeTrait::HAS_TRIVIAL_ASSIGN;
    case 12: return TypeTrait::HAS_TRIVIAL_COPY;
    case 13: return TypeTrait::HAS_TRIVIAL_DEFAULT_CONSTRUCTOR;
    case 14: return TypeTrait::HAS_TRIVIAL_DESTRUCTOR;
    case 15: return TypeTrait::HAS_VIRTUAL_DESTRUCTOR;
    case 16: return TypeTrait::IS_ABSTRACT;
    case 17: return TypeTrait::IS_AGGREGATE;
    case 18: return TypeTrait::IS_CLASS;
    case 19: return TypeTrait::IS_EMPTY;
    case 20: return TypeTrait::IS_ENUM;
    case 21: return TypeTrait::IS_FINAL;
    case 22: return TypeTrait::IS_LITERAL;
    case 23: return TypeTrait::IS_POD;
    case 24: return TypeTrait::IS_POLYMORPHIC;
    case 25: return TypeTrait::IS_STANDARD_LAYOUT;
    case 26: return TypeTrait::IS_TRIVIAL;
    case 27: return TypeTrait::IS_TRIVIALLY_COPYABLE;
    case 28: return TypeTrait::IS_UNION;
    case 29: return TypeTrait::HAS_UNIQUE_OBJECT_REPRESENTATIONS;
    case 30: return TypeTrait::IS_ARITHMETIC;
    case 31: return TypeTrait::IS_FLOATING_POINT;
    case 32: return TypeTrait::IS_INTEGRAL;
    case 33: return TypeTrait::IS_COMPLETE_TYPE;
    case 34: return TypeTrait::IS_VOID;
    case 35: return TypeTrait::IS_ARRAY;
    case 36: return TypeTrait::IS_FUNCTION;
    case 37: return TypeTrait::IS_REFERENCE;
    case 38: return TypeTrait::IS_LVALUE_REFERENCE;
    case 39: return TypeTrait::IS_RVALUE_REFERENCE;
    case 40: return TypeTrait::IS_FUNDAMENTAL;
    case 41: return TypeTrait::IS_OBJECT;
    case 42: return TypeTrait::IS_SCALAR;
    case 43: return TypeTrait::IS_COMPOUND;
    case 44: return TypeTrait::IS_POINTER;
    case 45: return TypeTrait::IS_MEMBER_OBJECT_POINTER;
    case 46: return TypeTrait::IS_MEMBER_FUNCTION_POINTER;
    case 47: return TypeTrait::IS_MEMBER_POINTER;
    case 48: return TypeTrait::IS_CONST;
    case 49: return TypeTrait::IS_VOLATILE;
    case 50: return TypeTrait::IS_SIGNED;
    case 51: return TypeTrait::IS_UNSIGNED;
    case 52: return TypeTrait::TYPE_COMPATIBLE;
    case 53: return TypeTrait::IS_NOTHROW_ASSIGNABLE;
    case 54: return TypeTrait::IS_ASSIGNABLE;
    case 55: return TypeTrait::IS_BASE_OF;
    case 56: return TypeTrait::IS_CONVERTIBLE_TO;
    case 57: return TypeTrait::IS_TRIVIALLY_ASSIGNABLE;
    case 58: return TypeTrait::REFERENCE_BINDS_TO_TEMPORARY;
    case 59: return TypeTrait::IS_SAME;
    case 60: return TypeTrait::IS_CONVERTIBLE;
    case 61: return TypeTrait::IS_CONSTRUCTIBLE;
    case 62: return TypeTrait::IS_NOTHROW_CONSTRUCTIBLE;
    case 63: return TypeTrait::IS_TRIVIALLY_CONSTRUCTIBLE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TypeTrait e) {
  switch (e) {
    case TypeTrait::IS_INTERFACE_CLASS: return "IS_INTERFACE_CLASS";
    case TypeTrait::IS_SEALED: return "IS_SEALED";
    case TypeTrait::IS_DESTRUCTIBLE: return "IS_DESTRUCTIBLE";
    case TypeTrait::IS_TRIVIALLY_DESTRUCTIBLE: return "IS_TRIVIALLY_DESTRUCTIBLE";
    case TypeTrait::IS_NOTHROW_DESTRUCTIBLE: return "IS_NOTHROW_DESTRUCTIBLE";
    case TypeTrait::HAS_NOTHROW_MOVE_ASSIGN: return "HAS_NOTHROW_MOVE_ASSIGN";
    case TypeTrait::HAS_TRIVIAL_MOVE_ASSIGN: return "HAS_TRIVIAL_MOVE_ASSIGN";
    case TypeTrait::HAS_TRIVIAL_MOVE_CONSTRUCTOR: return "HAS_TRIVIAL_MOVE_CONSTRUCTOR";
    case TypeTrait::HAS_NOTHROW_ASSIGN: return "HAS_NOTHROW_ASSIGN";
    case TypeTrait::HAS_NOTHROW_COPY: return "HAS_NOTHROW_COPY";
    case TypeTrait::HAS_NOTHROW_CONSTRUCTOR: return "HAS_NOTHROW_CONSTRUCTOR";
    case TypeTrait::HAS_TRIVIAL_ASSIGN: return "HAS_TRIVIAL_ASSIGN";
    case TypeTrait::HAS_TRIVIAL_COPY: return "HAS_TRIVIAL_COPY";
    case TypeTrait::HAS_TRIVIAL_DEFAULT_CONSTRUCTOR: return "HAS_TRIVIAL_DEFAULT_CONSTRUCTOR";
    case TypeTrait::HAS_TRIVIAL_DESTRUCTOR: return "HAS_TRIVIAL_DESTRUCTOR";
    case TypeTrait::HAS_VIRTUAL_DESTRUCTOR: return "HAS_VIRTUAL_DESTRUCTOR";
    case TypeTrait::IS_ABSTRACT: return "IS_ABSTRACT";
    case TypeTrait::IS_AGGREGATE: return "IS_AGGREGATE";
    case TypeTrait::IS_CLASS: return "IS_CLASS";
    case TypeTrait::IS_EMPTY: return "IS_EMPTY";
    case TypeTrait::IS_ENUM: return "IS_ENUM";
    case TypeTrait::IS_FINAL: return "IS_FINAL";
    case TypeTrait::IS_LITERAL: return "IS_LITERAL";
    case TypeTrait::IS_POD: return "IS_POD";
    case TypeTrait::IS_POLYMORPHIC: return "IS_POLYMORPHIC";
    case TypeTrait::IS_STANDARD_LAYOUT: return "IS_STANDARD_LAYOUT";
    case TypeTrait::IS_TRIVIAL: return "IS_TRIVIAL";
    case TypeTrait::IS_TRIVIALLY_COPYABLE: return "IS_TRIVIALLY_COPYABLE";
    case TypeTrait::IS_UNION: return "IS_UNION";
    case TypeTrait::HAS_UNIQUE_OBJECT_REPRESENTATIONS: return "HAS_UNIQUE_OBJECT_REPRESENTATIONS";
    case TypeTrait::IS_ARITHMETIC: return "IS_ARITHMETIC";
    case TypeTrait::IS_FLOATING_POINT: return "IS_FLOATING_POINT";
    case TypeTrait::IS_INTEGRAL: return "IS_INTEGRAL";
    case TypeTrait::IS_COMPLETE_TYPE: return "IS_COMPLETE_TYPE";
    case TypeTrait::IS_VOID: return "IS_VOID";
    case TypeTrait::IS_ARRAY: return "IS_ARRAY";
    case TypeTrait::IS_FUNCTION: return "IS_FUNCTION";
    case TypeTrait::IS_REFERENCE: return "IS_REFERENCE";
    case TypeTrait::IS_LVALUE_REFERENCE: return "IS_LVALUE_REFERENCE";
    case TypeTrait::IS_RVALUE_REFERENCE: return "IS_RVALUE_REFERENCE";
    case TypeTrait::IS_FUNDAMENTAL: return "IS_FUNDAMENTAL";
    case TypeTrait::IS_OBJECT: return "IS_OBJECT";
    case TypeTrait::IS_SCALAR: return "IS_SCALAR";
    case TypeTrait::IS_COMPOUND: return "IS_COMPOUND";
    case TypeTrait::IS_POINTER: return "IS_POINTER";
    case TypeTrait::IS_MEMBER_OBJECT_POINTER: return "IS_MEMBER_OBJECT_POINTER";
    case TypeTrait::IS_MEMBER_FUNCTION_POINTER: return "IS_MEMBER_FUNCTION_POINTER";
    case TypeTrait::IS_MEMBER_POINTER: return "IS_MEMBER_POINTER";
    case TypeTrait::IS_CONST: return "IS_CONST";
    case TypeTrait::IS_VOLATILE: return "IS_VOLATILE";
    case TypeTrait::IS_SIGNED: return "IS_SIGNED";
    case TypeTrait::IS_UNSIGNED: return "IS_UNSIGNED";
    case TypeTrait::TYPE_COMPATIBLE: return "TYPE_COMPATIBLE";
    case TypeTrait::IS_NOTHROW_ASSIGNABLE: return "IS_NOTHROW_ASSIGNABLE";
    case TypeTrait::IS_ASSIGNABLE: return "IS_ASSIGNABLE";
    case TypeTrait::IS_BASE_OF: return "IS_BASE_OF";
    case TypeTrait::IS_CONVERTIBLE_TO: return "IS_CONVERTIBLE_TO";
    case TypeTrait::IS_TRIVIALLY_ASSIGNABLE: return "IS_TRIVIALLY_ASSIGNABLE";
    case TypeTrait::REFERENCE_BINDS_TO_TEMPORARY: return "REFERENCE_BINDS_TO_TEMPORARY";
    case TypeTrait::IS_SAME: return "IS_SAME";
    case TypeTrait::IS_CONVERTIBLE: return "IS_CONVERTIBLE";
    case TypeTrait::IS_CONSTRUCTIBLE: return "IS_CONSTRUCTIBLE";
    case TypeTrait::IS_NOTHROW_CONSTRUCTIBLE: return "IS_NOTHROW_CONSTRUCTIBLE";
    case TypeTrait::IS_TRIVIALLY_CONSTRUCTIBLE: return "IS_TRIVIALLY_CONSTRUCTIBLE";
    default: return "<invalid>";
  }
}

UnaryExprOrTypeTrait FromPasta(pasta::UnaryExprOrTypeTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnaryExprOrTypeTrait::SIZE_OF;
    case 1: return UnaryExprOrTypeTrait::ALIGN_OF;
    case 2: return UnaryExprOrTypeTrait::PREFERRED_ALIGN_OF;
    case 3: return UnaryExprOrTypeTrait::VEC_STEP;
    case 4: return UnaryExprOrTypeTrait::OPEN_MP_REQUIRED_SIMD_ALIGN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(UnaryExprOrTypeTrait e) {
  switch (e) {
    case UnaryExprOrTypeTrait::SIZE_OF: return "SIZE_OF";
    case UnaryExprOrTypeTrait::ALIGN_OF: return "ALIGN_OF";
    case UnaryExprOrTypeTrait::PREFERRED_ALIGN_OF: return "PREFERRED_ALIGN_OF";
    case UnaryExprOrTypeTrait::VEC_STEP: return "VEC_STEP";
    case UnaryExprOrTypeTrait::OPEN_MP_REQUIRED_SIMD_ALIGN: return "OPEN_MP_REQUIRED_SIMD_ALIGN";
    default: return "<invalid>";
  }
}

UnaryOperatorKind FromPasta(pasta::UnaryOperatorKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnaryOperatorKind::POST_INCREMENT;
    case 1: return UnaryOperatorKind::POST_DEC;
    case 2: return UnaryOperatorKind::PRE_INCREMENT;
    case 3: return UnaryOperatorKind::PRE_DEC;
    case 4: return UnaryOperatorKind::ADDR_OF;
    case 5: return UnaryOperatorKind::DEREF;
    case 6: return UnaryOperatorKind::PLUS;
    case 7: return UnaryOperatorKind::MINUS;
    case 8: return UnaryOperatorKind::NOT;
    case 9: return UnaryOperatorKind::L_NOT;
    case 10: return UnaryOperatorKind::REAL;
    case 11: return UnaryOperatorKind::IMAG;
    case 12: return UnaryOperatorKind::EXTENSION;
    case 13: return UnaryOperatorKind::COAWAIT;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(UnaryOperatorKind e) {
  switch (e) {
    case UnaryOperatorKind::POST_INCREMENT: return "POST_INCREMENT";
    case UnaryOperatorKind::POST_DEC: return "POST_DEC";
    case UnaryOperatorKind::PRE_INCREMENT: return "PRE_INCREMENT";
    case UnaryOperatorKind::PRE_DEC: return "PRE_DEC";
    case UnaryOperatorKind::ADDR_OF: return "ADDR_OF";
    case UnaryOperatorKind::DEREF: return "DEREF";
    case UnaryOperatorKind::PLUS: return "PLUS";
    case UnaryOperatorKind::MINUS: return "MINUS";
    case UnaryOperatorKind::NOT: return "NOT";
    case UnaryOperatorKind::L_NOT: return "L_NOT";
    case UnaryOperatorKind::REAL: return "REAL";
    case UnaryOperatorKind::IMAG: return "IMAG";
    case UnaryOperatorKind::EXTENSION: return "EXTENSION";
    case UnaryOperatorKind::COAWAIT: return "COAWAIT";
    default: return "<invalid>";
  }
}

APValueKind FromPasta(pasta::APValueKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return APValueKind::NONE;
    case 1: return APValueKind::INDETERMINATE;
    case 2: return APValueKind::INT;
    case 3: return APValueKind::FLOAT;
    case 4: return APValueKind::FIXED_POINT;
    case 5: return APValueKind::COMPLEX_INT;
    case 6: return APValueKind::COMPLEX_FLOAT;
    case 7: return APValueKind::L_VALUE;
    case 8: return APValueKind::VECTOR;
    case 9: return APValueKind::ARRAY;
    case 10: return APValueKind::STRUCT;
    case 11: return APValueKind::UNION;
    case 12: return APValueKind::MEMBER_POINTER;
    case 13: return APValueKind::ADDR_LABEL_DIFF;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(APValueKind e) {
  switch (e) {
    case APValueKind::NONE: return "NONE";
    case APValueKind::INDETERMINATE: return "INDETERMINATE";
    case APValueKind::INT: return "INT";
    case APValueKind::FLOAT: return "FLOAT";
    case APValueKind::FIXED_POINT: return "FIXED_POINT";
    case APValueKind::COMPLEX_INT: return "COMPLEX_INT";
    case APValueKind::COMPLEX_FLOAT: return "COMPLEX_FLOAT";
    case APValueKind::L_VALUE: return "L_VALUE";
    case APValueKind::VECTOR: return "VECTOR";
    case APValueKind::ARRAY: return "ARRAY";
    case APValueKind::STRUCT: return "STRUCT";
    case APValueKind::UNION: return "UNION";
    case APValueKind::MEMBER_POINTER: return "MEMBER_POINTER";
    case APValueKind::ADDR_LABEL_DIFF: return "ADDR_LABEL_DIFF";
    default: return "<invalid>";
  }
}

VectorLibrary FromPasta(pasta::VectorLibrary e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VectorLibrary::NO_LIBRARY;
    case 1: return VectorLibrary::ACCELERATE;
    case 2: return VectorLibrary::LIBMVEC;
    case 3: return VectorLibrary::MASSV;
    case 4: return VectorLibrary::SVML;
    case 5: return VectorLibrary::DARWIN_LIBSYSTEM_M;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(VectorLibrary e) {
  switch (e) {
    case VectorLibrary::NO_LIBRARY: return "NO_LIBRARY";
    case VectorLibrary::ACCELERATE: return "ACCELERATE";
    case VectorLibrary::LIBMVEC: return "LIBMVEC";
    case VectorLibrary::MASSV: return "MASSV";
    case VectorLibrary::SVML: return "SVML";
    case VectorLibrary::DARWIN_LIBSYSTEM_M: return "DARWIN_LIBSYSTEM_M";
    default: return "<invalid>";
  }
}

Visibility FromPasta(pasta::Visibility e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Visibility::HIDDEN_VISIBILITY;
    case 1: return Visibility::PROTECTED_VISIBILITY;
    case 2: return Visibility::DEFAULT_VISIBILITY;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(Visibility e) {
  switch (e) {
    case Visibility::HIDDEN_VISIBILITY: return "HIDDEN_VISIBILITY";
    case Visibility::PROTECTED_VISIBILITY: return "PROTECTED_VISIBILITY";
    case Visibility::DEFAULT_VISIBILITY: return "DEFAULT_VISIBILITY";
    default: return "<invalid>";
  }
}

VisibilityType FromPasta(pasta::VisibilityType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VisibilityType::DEFAULT;
    case 1: return VisibilityType::HIDDEN;
    case 2: return VisibilityType::PROTECTED;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(VisibilityType e) {
  switch (e) {
    case VisibilityType::DEFAULT: return "DEFAULT";
    case VisibilityType::HIDDEN: return "HIDDEN";
    case VisibilityType::PROTECTED: return "PROTECTED";
    default: return "<invalid>";
  }
}

PathKind FromPasta(pasta::PathKind e) {
  switch (static_cast<signed char>(e)) {
    case 47: return PathKind::UNIX;
    case 92: return PathKind::WINDOWS;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(PathKind e) {
  switch (e) {
    case PathKind::UNIX: return "UNIX";
    case PathKind::WINDOWS: return "WINDOWS";
    default: return "<invalid>";
  }
}

FileType FromPasta(pasta::FileType e) {
  switch (static_cast<signed char>(e)) {
    case 0: return FileType::NONE;
    case -1: return FileType::NOT_FOUND;
    case 1: return FileType::REGULAR;
    case 2: return FileType::DIRECTORY;
    case 3: return FileType::SYMBOLIC_LINK;
    case 4: return FileType::BLOCK;
    case 5: return FileType::CHARACTER;
    case 6: return FileType::FIRST_IN_FIRST_OUT;
    case 7: return FileType::SOCKET;
    case 8: return FileType::KNKNOWN;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(FileType e) {
  switch (e) {
    case FileType::NONE: return "NONE";
    case FileType::NOT_FOUND: return "NOT_FOUND";
    case FileType::REGULAR: return "REGULAR";
    case FileType::DIRECTORY: return "DIRECTORY";
    case FileType::SYMBOLIC_LINK: return "SYMBOLIC_LINK";
    case FileType::BLOCK: return "BLOCK";
    case FileType::CHARACTER: return "CHARACTER";
    case FileType::FIRST_IN_FIRST_OUT: return "FIRST_IN_FIRST_OUT";
    case FileType::SOCKET: return "SOCKET";
    case FileType::KNKNOWN: return "KNKNOWN";
    default: return "<invalid>";
  }
}

CompilerName FromPasta(pasta::CompilerName e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CompilerName::UNKNOWN;
    case 1: return CompilerName::CLANG;
    case 2: return CompilerName::APPLE_CLANG;
    case 3: return CompilerName::CLANG_CL;
    case 4: return CompilerName::CL;
    case 5: return CompilerName::GNU;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(CompilerName e) {
  switch (e) {
    case CompilerName::UNKNOWN: return "UNKNOWN";
    case CompilerName::CLANG: return "CLANG";
    case CompilerName::APPLE_CLANG: return "APPLE_CLANG";
    case CompilerName::CLANG_CL: return "CLANG_CL";
    case CompilerName::CL: return "CL";
    case CompilerName::GNU: return "GNU";
    default: return "<invalid>";
  }
}

IncludePathLocation FromPasta(pasta::IncludePathLocation e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IncludePathLocation::ABSOLUTE;
    case 1: return IncludePathLocation::SYSROOT_RELATIVE;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(IncludePathLocation e) {
  switch (e) {
    case IncludePathLocation::ABSOLUTE: return "ABSOLUTE";
    case IncludePathLocation::SYSROOT_RELATIVE: return "SYSROOT_RELATIVE";
    default: return "<invalid>";
  }
}

TargetLanguage FromPasta(pasta::TargetLanguage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TargetLanguage::C;
    case 1: return TargetLanguage::CXX;
    default: __builtin_unreachable();
  }
}

const char *EnumeratorName(TargetLanguage e) {
  switch (e) {
    case TargetLanguage::C: return "C";
    case TargetLanguage::CXX: return "CXX";
    default: return "<invalid>";
  }
}

#ifndef MX_DISABLE_API
unsigned TemplateParameterList::num_parameters(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal0();
}

unsigned TemplateParameterList::num_required_parameters(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal1();
}

unsigned TemplateParameterList::depth(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal2();
}

bool TemplateParameterList::has_unexpanded_parameter_pack(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal3();
}

bool TemplateParameterList::has_parameter_pack(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal4();
}

std::optional<Expr> TemplateParameterList::requires_clause(void) const {
  auto self = fragment->NthPseudo(offset);
  if (!self.getVal6()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal5());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

Token TemplateParameterList::template_keyword_token(void) const {
  auto self = fragment->NthPseudo(offset);
  return fragment->TokenFor(fragment, self.getVal7());
}

Token TemplateParameterList::left_angle_token(void) const {
  auto self = fragment->NthPseudo(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

Token TemplateParameterList::right_angle_token(void) const {
  auto self = fragment->NthPseudo(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

TokenRange TemplateParameterList::token_range(void) const {
  auto self = fragment->NthPseudo(offset);
  return fragment->TokenRangeFor(fragment, self.getVal10(), self.getVal11());
}

std::vector<NamedDecl> TemplateParameterList::parameters(void) const {
  auto self = fragment->NthPseudo(offset);
  auto list = self.getVal12();
  std::vector<NamedDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = NamedDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

TemplateArgumentKind TemplateArgument::kind(void) const {
  auto self = fragment->NthPseudo(offset);
  return static_cast<TemplateArgumentKind>(self.getVal13());
}

bool TemplateArgument::is_null(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal3();
}

bool TemplateArgument::is_dependent(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal4();
}

bool TemplateArgument::is_instantiation_dependent(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal6();
}

bool TemplateArgument::contains_unexpanded_parameter_pack(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal14();
}

bool TemplateArgument::is_pack_expansion(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal15();
}

std::optional<ValueDecl> TemplateArgument::as_declaration(void) const {
  auto self = fragment->NthPseudo(offset);
  if (!self.getVal16()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal5());
    return ValueDecl::from(fragment->DeclFor(fragment, id));
  }
}

TokenRange CXXBaseSpecifier::token_range(void) const {
  auto self = fragment->NthPseudo(offset);
  return fragment->TokenRangeFor(fragment, self.getVal5(), self.getVal7());
}

Token CXXBaseSpecifier::base_type_token(void) const {
  auto self = fragment->NthPseudo(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

bool CXXBaseSpecifier::is_virtual(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal3();
}

TagTypeKind CXXBaseSpecifier::base_kind(void) const {
  auto self = fragment->NthPseudo(offset);
  return static_cast<TagTypeKind>(self.getVal13());
}

bool CXXBaseSpecifier::is_pack_expansion(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal4();
}

bool CXXBaseSpecifier::constructors_are_inherited(void) const {
  auto self = fragment->NthPseudo(offset);
  return self.getVal6();
}

std::optional<Token> CXXBaseSpecifier::ellipsis(void) const {
  auto self = fragment->NthPseudo(offset);
  if (!self.getVal14()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return fragment->TokenFor(fragment, id);
  }
}

AccessSpecifier CXXBaseSpecifier::semantic_access_specifier(void) const {
  auto self = fragment->NthPseudo(offset);
  return static_cast<AccessSpecifier>(self.getVal17());
}

AccessSpecifier CXXBaseSpecifier::lexical_access_specifier(void) const {
  auto self = fragment->NthPseudo(offset);
  return static_cast<AccessSpecifier>(self.getVal18());
}

Stmt Stmt::ignore_containers(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal0());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::vector<Stmt> Stmt::children(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal1();
  std::vector<Stmt> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->StmtFor(fragment, id));
  }
  return vec;
}

Token Stmt::begin_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal2());
}

Token Stmt::end_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal3());
}

TokenRange Stmt::token_range(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal4(), self.getVal5());
}

StmtKind Stmt::kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<StmtKind>(self.getVal6());
}

Stmt Stmt::strip_label_like_statements(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal7());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<SEHTryStmt> SEHTryStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SEHTryStmt> SEHTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_TRY_STMT:
      return reinterpret_cast<const SEHTryStmt &>(parent);
    default: return std::nullopt;
  }
}

SEHExceptStmt SEHTryStmt::except_handler(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return SEHExceptStmt::from(fragment->StmtFor(fragment, id)).value();
}

SEHFinallyStmt SEHTryStmt::finally_handler(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return SEHFinallyStmt::from(fragment->StmtFor(fragment, id)).value();
}

Stmt SEHTryStmt::handler(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Stmt(fragment->StmtFor(fragment, id));
}

bool SEHTryStmt::is_cxx_try(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

CompoundStmt SEHTryStmt::try_block(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

Token SEHTryStmt::try_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

std::optional<SEHLeaveStmt> SEHLeaveStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SEHLeaveStmt> SEHLeaveStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_LEAVE_STMT:
      return reinterpret_cast<const SEHLeaveStmt &>(parent);
    default: return std::nullopt;
  }
}

Token SEHLeaveStmt::leave_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

std::optional<SEHFinallyStmt> SEHFinallyStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SEHFinallyStmt> SEHFinallyStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_FINALLY_STMT:
      return reinterpret_cast<const SEHFinallyStmt &>(parent);
    default: return std::nullopt;
  }
}

CompoundStmt SEHFinallyStmt::block(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

Token SEHFinallyStmt::finally_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<SEHExceptStmt> SEHExceptStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SEHExceptStmt> SEHExceptStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_EXCEPT_STMT:
      return reinterpret_cast<const SEHExceptStmt &>(parent);
    default: return std::nullopt;
  }
}

CompoundStmt SEHExceptStmt::block(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

Token SEHExceptStmt::except_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

Expr SEHExceptStmt::filter_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ReturnStmt> ReturnStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ReturnStmt> ReturnStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::RETURN_STMT:
      return reinterpret_cast<const ReturnStmt &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarDecl> ReturnStmt::nrvo_candidate(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal8());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<Expr> ReturnStmt::return_value(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal14()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

Token ReturnStmt::return_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal10());
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_FOR_COLLECTION_STMT:
      return reinterpret_cast<const ObjCForCollectionStmt &>(parent);
    default: return std::nullopt;
  }
}

Stmt ObjCForCollectionStmt::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr ObjCForCollectionStmt::collection(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Stmt ObjCForCollectionStmt::element(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Stmt(fragment->StmtFor(fragment, id));
}

Token ObjCForCollectionStmt::for_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal12());
}

Token ObjCForCollectionStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AUTORELEASE_POOL_STMT:
      return reinterpret_cast<const ObjCAutoreleasePoolStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAutoreleasePoolStmt::at_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

Stmt ObjCAutoreleasePoolStmt::sub_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_TRY_STMT:
      return reinterpret_cast<const ObjCAtTryStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtTryStmt::at_try_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

ObjCAtFinallyStmt ObjCAtTryStmt::finally_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return ObjCAtFinallyStmt::from(fragment->StmtFor(fragment, id)).value();
}

Stmt ObjCAtTryStmt::try_body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::vector<ObjCAtCatchStmt> ObjCAtTryStmt::catch_statements(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<ObjCAtCatchStmt> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCAtCatchStmt::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<ObjCAtThrowStmt> ObjCAtThrowStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAtThrowStmt> ObjCAtThrowStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_THROW_STMT:
      return reinterpret_cast<const ObjCAtThrowStmt &>(parent);
    default: return std::nullopt;
  }
}

Expr ObjCAtThrowStmt::throw_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token ObjCAtThrowStmt::throw_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<ObjCAtSynchronizedStmt> ObjCAtSynchronizedStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAtSynchronizedStmt> ObjCAtSynchronizedStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT:
      return reinterpret_cast<const ObjCAtSynchronizedStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtSynchronizedStmt::at_synchronized_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

CompoundStmt ObjCAtSynchronizedStmt::synch_body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

Expr ObjCAtSynchronizedStmt::synch_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ObjCAtFinallyStmt> ObjCAtFinallyStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAtFinallyStmt> ObjCAtFinallyStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_FINALLY_STMT:
      return reinterpret_cast<const ObjCAtFinallyStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtFinallyStmt::at_finally_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

Stmt ObjCAtFinallyStmt::finally_body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<ObjCAtCatchStmt> ObjCAtCatchStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAtCatchStmt> ObjCAtCatchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_CATCH_STMT:
      return reinterpret_cast<const ObjCAtCatchStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtCatchStmt::at_catch_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

Stmt ObjCAtCatchStmt::catch_body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Stmt(fragment->StmtFor(fragment, id));
}

VarDecl ObjCAtCatchStmt::catch_parameter_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return VarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCAtCatchStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal12());
}

bool ObjCAtCatchStmt::has_ellipsis(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

std::optional<OMPExecutableDirective> OMPExecutableDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPExecutableDirective> OMPExecutableDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_DISPATCH_DIRECTIVE:
    case mx::StmtKind::OMP_DEPOBJ_DIRECTIVE:
    case mx::StmtKind::OMP_CRITICAL_DIRECTIVE:
    case mx::StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE:
    case mx::StmtKind::OMP_CANCEL_DIRECTIVE:
    case mx::StmtKind::OMP_BARRIER_DIRECTIVE:
    case mx::StmtKind::OMP_ATOMIC_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DIRECTIVE:
    case mx::StmtKind::OMP_TASKYIELD_DIRECTIVE:
    case mx::StmtKind::OMP_TASKWAIT_DIRECTIVE:
    case mx::StmtKind::OMP_TASKGROUP_DIRECTIVE:
    case mx::StmtKind::OMP_TASK_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_UPDATE_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_PARALLEL_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_EXIT_DATA_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_DATA_DIRECTIVE:
    case mx::StmtKind::OMP_SINGLE_DIRECTIVE:
    case mx::StmtKind::OMP_SECTIONS_DIRECTIVE:
    case mx::StmtKind::OMP_SECTION_DIRECTIVE:
    case mx::StmtKind::OMP_SCAN_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_MASTER_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_DIRECTIVE:
    case mx::StmtKind::OMP_ORDERED_DIRECTIVE:
    case mx::StmtKind::OMP_MASTER_DIRECTIVE:
    case mx::StmtKind::OMP_MASKED_DIRECTIVE:
    case mx::StmtKind::OMP_UNROLL_DIRECTIVE:
    case mx::StmtKind::OMP_TILE_DIRECTIVE:
    case mx::StmtKind::OMP_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TASK_LOOP_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE:
    case mx::StmtKind::OMP_INTEROP_DIRECTIVE:
    case mx::StmtKind::OMP_FLUSH_DIRECTIVE:
      return reinterpret_cast<const OMPExecutableDirective &>(parent);
    default: return std::nullopt;
  }
}

Stmt OMPExecutableDirective::associated_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Stmt(fragment->StmtFor(fragment, id));
}

CapturedStmt OMPExecutableDirective::innermost_captured_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return CapturedStmt::from(fragment->StmtFor(fragment, id)).value();
}

Stmt OMPExecutableDirective::raw_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt OMPExecutableDirective::structured_block(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return Stmt(fragment->StmtFor(fragment, id));
}

bool OMPExecutableDirective::has_associated_statement(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

bool OMPExecutableDirective::is_standalone_directive(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal14();
}

std::optional<OMPDispatchDirective> OMPDispatchDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDispatchDirective> OMPDispatchDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDispatchDirective> OMPDispatchDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_DISPATCH_DIRECTIVE:
      return reinterpret_cast<const OMPDispatchDirective &>(parent);
    default: return std::nullopt;
  }
}

Token OMPDispatchDirective::target_call_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

std::optional<OMPDepobjDirective> OMPDepobjDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDepobjDirective> OMPDepobjDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDepobjDirective> OMPDepobjDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_DEPOBJ_DIRECTIVE:
      return reinterpret_cast<const OMPDepobjDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPCriticalDirective> OMPCriticalDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPCriticalDirective> OMPCriticalDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPCriticalDirective> OMPCriticalDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_CRITICAL_DIRECTIVE:
      return reinterpret_cast<const OMPCriticalDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPCancellationPointDirective> OMPCancellationPointDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPCancellationPointDirective> OMPCancellationPointDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPCancellationPointDirective> OMPCancellationPointDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE:
      return reinterpret_cast<const OMPCancellationPointDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPCancelDirective> OMPCancelDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPCancelDirective> OMPCancelDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPCancelDirective> OMPCancelDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_CANCEL_DIRECTIVE:
      return reinterpret_cast<const OMPCancelDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPBarrierDirective> OMPBarrierDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPBarrierDirective> OMPBarrierDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPBarrierDirective> OMPBarrierDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_BARRIER_DIRECTIVE:
      return reinterpret_cast<const OMPBarrierDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPAtomicDirective> OMPAtomicDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_ATOMIC_DIRECTIVE:
      return reinterpret_cast<const OMPAtomicDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPAtomicDirective::expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPAtomicDirective::update_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal16());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPAtomicDirective::v(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal17());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPAtomicDirective::x(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal18());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPAtomicDirective::is_postfix_update(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

bool OMPAtomicDirective::is_xlhs_in_rhs_part(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal20();
}

std::optional<OMPTeamsDirective> OMPTeamsDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTeamsDirective> OMPTeamsDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDirective> OMPTeamsDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TEAMS_DIRECTIVE:
      return reinterpret_cast<const OMPTeamsDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTaskyieldDirective> OMPTaskyieldDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTaskyieldDirective> OMPTaskyieldDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskyieldDirective> OMPTaskyieldDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TASKYIELD_DIRECTIVE:
      return reinterpret_cast<const OMPTaskyieldDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTaskwaitDirective> OMPTaskwaitDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTaskwaitDirective> OMPTaskwaitDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskwaitDirective> OMPTaskwaitDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TASKWAIT_DIRECTIVE:
      return reinterpret_cast<const OMPTaskwaitDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTaskgroupDirective> OMPTaskgroupDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTaskgroupDirective> OMPTaskgroupDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskgroupDirective> OMPTaskgroupDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TASKGROUP_DIRECTIVE:
      return reinterpret_cast<const OMPTaskgroupDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPTaskgroupDirective::reduction_reference(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<OMPTaskDirective> OMPTaskDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTaskDirective> OMPTaskDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskDirective> OMPTaskDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TASK_DIRECTIVE:
      return reinterpret_cast<const OMPTaskDirective &>(parent);
    default: return std::nullopt;
  }
}

bool OMPTaskDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPTargetUpdateDirective> OMPTargetUpdateDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetUpdateDirective> OMPTargetUpdateDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetUpdateDirective> OMPTargetUpdateDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_UPDATE_DIRECTIVE:
      return reinterpret_cast<const OMPTargetUpdateDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDirective> OMPTargetTeamsDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDirective> OMPTargetTeamsDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDirective> OMPTargetTeamsDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_TEAMS_DIRECTIVE:
      return reinterpret_cast<const OMPTargetTeamsDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetParallelDirective> OMPTargetParallelDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetParallelDirective> OMPTargetParallelDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetParallelDirective> OMPTargetParallelDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_PARALLEL_DIRECTIVE:
      return reinterpret_cast<const OMPTargetParallelDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPTargetParallelDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPTargetParallelDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPTargetExitDataDirective> OMPTargetExitDataDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetExitDataDirective> OMPTargetExitDataDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetExitDataDirective> OMPTargetExitDataDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_EXIT_DATA_DIRECTIVE:
      return reinterpret_cast<const OMPTargetExitDataDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetEnterDataDirective> OMPTargetEnterDataDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetEnterDataDirective> OMPTargetEnterDataDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetEnterDataDirective> OMPTargetEnterDataDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE:
      return reinterpret_cast<const OMPTargetEnterDataDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetDirective> OMPTargetDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetDirective> OMPTargetDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetDirective> OMPTargetDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_DIRECTIVE:
      return reinterpret_cast<const OMPTargetDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetDataDirective> OMPTargetDataDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetDataDirective> OMPTargetDataDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetDataDirective> OMPTargetDataDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_DATA_DIRECTIVE:
      return reinterpret_cast<const OMPTargetDataDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPSingleDirective> OMPSingleDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPSingleDirective> OMPSingleDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPSingleDirective> OMPSingleDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_SINGLE_DIRECTIVE:
      return reinterpret_cast<const OMPSingleDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPSectionsDirective> OMPSectionsDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPSectionsDirective> OMPSectionsDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPSectionsDirective> OMPSectionsDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_SECTIONS_DIRECTIVE:
      return reinterpret_cast<const OMPSectionsDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPSectionsDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPSectionsDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPSectionDirective> OMPSectionDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPSectionDirective> OMPSectionDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPSectionDirective> OMPSectionDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_SECTION_DIRECTIVE:
      return reinterpret_cast<const OMPSectionDirective &>(parent);
    default: return std::nullopt;
  }
}

bool OMPSectionDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPScanDirective> OMPScanDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPScanDirective> OMPScanDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPScanDirective> OMPScanDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_SCAN_DIRECTIVE:
      return reinterpret_cast<const OMPScanDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPParallelSectionsDirective> OMPParallelSectionsDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPParallelSectionsDirective> OMPParallelSectionsDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelSectionsDirective> OMPParallelSectionsDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE:
      return reinterpret_cast<const OMPParallelSectionsDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPParallelSectionsDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPParallelSectionsDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPParallelMasterDirective> OMPParallelMasterDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPParallelMasterDirective> OMPParallelMasterDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelMasterDirective> OMPParallelMasterDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_PARALLEL_MASTER_DIRECTIVE:
      return reinterpret_cast<const OMPParallelMasterDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPParallelMasterDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<OMPParallelDirective> OMPParallelDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPParallelDirective> OMPParallelDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelDirective> OMPParallelDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_PARALLEL_DIRECTIVE:
      return reinterpret_cast<const OMPParallelDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPParallelDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPParallelDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPOrderedDirective> OMPOrderedDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPOrderedDirective> OMPOrderedDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPOrderedDirective> OMPOrderedDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_ORDERED_DIRECTIVE:
      return reinterpret_cast<const OMPOrderedDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPMasterDirective> OMPMasterDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPMasterDirective> OMPMasterDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMasterDirective> OMPMasterDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_MASTER_DIRECTIVE:
      return reinterpret_cast<const OMPMasterDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPMaskedDirective> OMPMaskedDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPMaskedDirective> OMPMaskedDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMaskedDirective> OMPMaskedDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_MASKED_DIRECTIVE:
      return reinterpret_cast<const OMPMaskedDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPLoopBasedDirective> OMPLoopBasedDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_UNROLL_DIRECTIVE:
    case mx::StmtKind::OMP_TILE_DIRECTIVE:
    case mx::StmtKind::OMP_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TASK_LOOP_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE:
      return reinterpret_cast<const OMPLoopBasedDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPUnrollDirective> OMPUnrollDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPUnrollDirective> OMPUnrollDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPUnrollDirective> OMPUnrollDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPUnrollDirective> OMPUnrollDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_UNROLL_DIRECTIVE:
      return reinterpret_cast<const OMPUnrollDirective &>(parent);
    default: return std::nullopt;
  }
}

Stmt OMPUnrollDirective::pre_initializers(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt OMPUnrollDirective::transformed_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal16());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<OMPTileDirective> OMPTileDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTileDirective> OMPTileDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTileDirective> OMPTileDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTileDirective> OMPTileDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TILE_DIRECTIVE:
      return reinterpret_cast<const OMPTileDirective &>(parent);
    default: return std::nullopt;
  }
}

Stmt OMPTileDirective::pre_initializers(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt OMPTileDirective::transformed_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal16());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPLoopDirective> OMPLoopDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TASK_LOOP_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_PARALLEL_FOR_DIRECTIVE:
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE:
      return reinterpret_cast<const OMPLoopDirective &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> OMPLoopDirective::counters(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Expr> OMPLoopDirective::dependent_counters(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal21();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Expr> OMPLoopDirective::dependent_initializers(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal22();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Expr> OMPLoopDirective::finals(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal23();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Expr> OMPLoopDirective::finals_conditions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal24();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

Stmt OMPLoopDirective::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr OMPLoopDirective::calculate_last_iteration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal16());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal17());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_distance_condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal18());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_ensure_upper_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal25());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal26());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_lower_bound_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal27());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_next_lower_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal28());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_next_upper_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal29());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_parallel_for_in_distance_condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal30());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::combined_upper_bound_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal31());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal32());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::distance_increment(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal33());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::ensure_upper_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal34());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::increment(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::is_last_iteration_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::iteration_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::last_iteration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::lower_bound_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::next_lower_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::next_upper_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal42());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::num_iterations(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal43());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::pre_condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal44());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Stmt OMPLoopDirective::pre_initializers(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal45());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr OMPLoopDirective::prev_ensure_upper_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal46());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::prev_lower_bound_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal47());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::prev_upper_bound_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal48());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::stride_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal49());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPLoopDirective::upper_bound_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal50());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::vector<Expr> OMPLoopDirective::initializers(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal51();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Expr> OMPLoopDirective::private_counters(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal52();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Expr> OMPLoopDirective::updates(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal53();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<OMPForSimdDirective> OMPForSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPForSimdDirective> OMPForSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPForSimdDirective> OMPForSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPForSimdDirective> OMPForSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPForSimdDirective> OMPForSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_FOR_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPForSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPForDirective> OMPForDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPForDirective> OMPForDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPForDirective> OMPForDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPForDirective> OMPForDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPForDirective> OMPForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_FOR_DIRECTIVE:
      return reinterpret_cast<const OMPForDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPForDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal54());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPForDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeSimdDirective> OMPDistributeSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPDistributeSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPDistributeParallelForSimdDirective> OMPDistributeParallelForSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDistributeParallelForSimdDirective> OMPDistributeParallelForSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeParallelForSimdDirective> OMPDistributeParallelForSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeParallelForSimdDirective> OMPDistributeParallelForSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeParallelForSimdDirective> OMPDistributeParallelForSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPDistributeParallelForSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPDistributeParallelForDirective> OMPDistributeParallelForDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDistributeParallelForDirective> OMPDistributeParallelForDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeParallelForDirective> OMPDistributeParallelForDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeParallelForDirective> OMPDistributeParallelForDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeParallelForDirective> OMPDistributeParallelForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
      return reinterpret_cast<const OMPDistributeParallelForDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPDistributeParallelForDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal54());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPDistributeParallelForDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPDistributeDirective> OMPDistributeDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDistributeDirective> OMPDistributeDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeDirective> OMPDistributeDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeDirective> OMPDistributeDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPDistributeDirective> OMPDistributeDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_DISTRIBUTE_DIRECTIVE:
      return reinterpret_cast<const OMPDistributeDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeSimdDirective> OMPTeamsDistributeSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPTeamsDistributeSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeParallelForSimdDirective> OMPTeamsDistributeParallelForSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPTeamsDistributeParallelForSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeParallelForDirective> OMPTeamsDistributeParallelForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
      return reinterpret_cast<const OMPTeamsDistributeParallelForDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPTeamsDistributeParallelForDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal54());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPTeamsDistributeParallelForDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPTeamsDistributeDirective> OMPTeamsDistributeDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTeamsDistributeDirective> OMPTeamsDistributeDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeDirective> OMPTeamsDistributeDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeDirective> OMPTeamsDistributeDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTeamsDistributeDirective> OMPTeamsDistributeDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE:
      return reinterpret_cast<const OMPTeamsDistributeDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTaskLoopSimdDirective> OMPTaskLoopSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTaskLoopSimdDirective> OMPTaskLoopSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskLoopSimdDirective> OMPTaskLoopSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskLoopSimdDirective> OMPTaskLoopSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskLoopSimdDirective> OMPTaskLoopSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPTaskLoopSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTaskLoopDirective> OMPTaskLoopDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TASK_LOOP_DIRECTIVE:
      return reinterpret_cast<const OMPTaskLoopDirective &>(parent);
    default: return std::nullopt;
  }
}

bool OMPTaskLoopDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPTargetTeamsDistributeSimdDirective> OMPTargetTeamsDistributeSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDistributeSimdDirective> OMPTargetTeamsDistributeSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeSimdDirective> OMPTargetTeamsDistributeSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeSimdDirective> OMPTargetTeamsDistributeSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeSimdDirective> OMPTargetTeamsDistributeSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPTargetTeamsDistributeSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> OMPTargetTeamsDistributeParallelForSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> OMPTargetTeamsDistributeParallelForSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> OMPTargetTeamsDistributeParallelForSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> OMPTargetTeamsDistributeParallelForSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> OMPTargetTeamsDistributeParallelForSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPTargetTeamsDistributeParallelForSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDistributeParallelForDirective> OMPTargetTeamsDistributeParallelForDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDistributeParallelForDirective> OMPTargetTeamsDistributeParallelForDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeParallelForDirective> OMPTargetTeamsDistributeParallelForDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeParallelForDirective> OMPTargetTeamsDistributeParallelForDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeParallelForDirective> OMPTargetTeamsDistributeParallelForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE:
      return reinterpret_cast<const OMPTargetTeamsDistributeParallelForDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPTargetTeamsDistributeParallelForDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal54());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPTargetTeamsDistributeParallelForDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPTargetTeamsDistributeDirective> OMPTargetTeamsDistributeDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetTeamsDistributeDirective> OMPTargetTeamsDistributeDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeDirective> OMPTargetTeamsDistributeDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeDirective> OMPTargetTeamsDistributeDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetTeamsDistributeDirective> OMPTargetTeamsDistributeDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE:
      return reinterpret_cast<const OMPTargetTeamsDistributeDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetSimdDirective> OMPTargetSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetSimdDirective> OMPTargetSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetSimdDirective> OMPTargetSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetSimdDirective> OMPTargetSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetSimdDirective> OMPTargetSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPTargetSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetParallelForSimdDirective> OMPTargetParallelForSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPTargetParallelForSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPTargetParallelForDirective> OMPTargetParallelForDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPTargetParallelForDirective> OMPTargetParallelForDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetParallelForDirective> OMPTargetParallelForDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetParallelForDirective> OMPTargetParallelForDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPTargetParallelForDirective> OMPTargetParallelForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE:
      return reinterpret_cast<const OMPTargetParallelForDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPTargetParallelForDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal54());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPTargetParallelForDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPSimdDirective> OMPSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPSimdDirective> OMPSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPSimdDirective> OMPSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPSimdDirective> OMPSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPSimdDirective> OMPSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPParallelMasterTaskLoopSimdDirective> OMPParallelMasterTaskLoopSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPParallelMasterTaskLoopSimdDirective> OMPParallelMasterTaskLoopSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelMasterTaskLoopSimdDirective> OMPParallelMasterTaskLoopSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelMasterTaskLoopSimdDirective> OMPParallelMasterTaskLoopSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelMasterTaskLoopSimdDirective> OMPParallelMasterTaskLoopSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPParallelMasterTaskLoopSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPParallelMasterTaskLoopDirective> OMPParallelMasterTaskLoopDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPParallelMasterTaskLoopDirective> OMPParallelMasterTaskLoopDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelMasterTaskLoopDirective> OMPParallelMasterTaskLoopDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelMasterTaskLoopDirective> OMPParallelMasterTaskLoopDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelMasterTaskLoopDirective> OMPParallelMasterTaskLoopDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE:
      return reinterpret_cast<const OMPParallelMasterTaskLoopDirective &>(parent);
    default: return std::nullopt;
  }
}

bool OMPParallelMasterTaskLoopDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPParallelForSimdDirective> OMPParallelForSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPParallelForSimdDirective> OMPParallelForSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelForSimdDirective> OMPParallelForSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelForSimdDirective> OMPParallelForSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelForSimdDirective> OMPParallelForSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPParallelForSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPParallelForDirective> OMPParallelForDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPParallelForDirective> OMPParallelForDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelForDirective> OMPParallelForDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelForDirective> OMPParallelForDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPParallelForDirective> OMPParallelForDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_PARALLEL_FOR_DIRECTIVE:
      return reinterpret_cast<const OMPParallelForDirective &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPParallelForDirective::task_reduction_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal54());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OMPParallelForDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPMasterTaskLoopSimdDirective> OMPMasterTaskLoopSimdDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPMasterTaskLoopSimdDirective> OMPMasterTaskLoopSimdDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMasterTaskLoopSimdDirective> OMPMasterTaskLoopSimdDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMasterTaskLoopSimdDirective> OMPMasterTaskLoopSimdDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMasterTaskLoopSimdDirective> OMPMasterTaskLoopSimdDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE:
      return reinterpret_cast<const OMPMasterTaskLoopSimdDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPMasterTaskLoopDirective> OMPMasterTaskLoopDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPMasterTaskLoopDirective> OMPMasterTaskLoopDirective::from(const OMPLoopDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMasterTaskLoopDirective> OMPMasterTaskLoopDirective::from(const OMPLoopBasedDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMasterTaskLoopDirective> OMPMasterTaskLoopDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPMasterTaskLoopDirective> OMPMasterTaskLoopDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE:
      return reinterpret_cast<const OMPMasterTaskLoopDirective &>(parent);
    default: return std::nullopt;
  }
}

bool OMPMasterTaskLoopDirective::has_cancel(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<OMPInteropDirective> OMPInteropDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPInteropDirective> OMPInteropDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPInteropDirective> OMPInteropDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_INTEROP_DIRECTIVE:
      return reinterpret_cast<const OMPInteropDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPFlushDirective> OMPFlushDirective::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPFlushDirective> OMPFlushDirective::from(const OMPExecutableDirective &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPFlushDirective> OMPFlushDirective::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_FLUSH_DIRECTIVE:
      return reinterpret_cast<const OMPFlushDirective &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPCanonicalLoop> OMPCanonicalLoop::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPCanonicalLoop> OMPCanonicalLoop::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_CANONICAL_LOOP:
      return reinterpret_cast<const OMPCanonicalLoop &>(parent);
    default: return std::nullopt;
  }
}

CapturedStmt OMPCanonicalLoop::distance_func(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return CapturedStmt::from(fragment->StmtFor(fragment, id)).value();
}

Stmt OMPCanonicalLoop::loop_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Stmt(fragment->StmtFor(fragment, id));
}

CapturedStmt OMPCanonicalLoop::loop_variable_func(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return CapturedStmt::from(fragment->StmtFor(fragment, id)).value();
}

DeclRefExpr OMPCanonicalLoop::loop_variable_reference(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return DeclRefExpr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<NullStmt> NullStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<NullStmt> NullStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::NULL_STMT:
      return reinterpret_cast<const NullStmt &>(parent);
    default: return std::nullopt;
  }
}

Token NullStmt::semi_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

bool NullStmt::has_leading_empty_macro(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

std::optional<MSDependentExistsStmt> MSDependentExistsStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MSDependentExistsStmt> MSDependentExistsStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MS_DEPENDENT_EXISTS_STMT:
      return reinterpret_cast<const MSDependentExistsStmt &>(parent);
    default: return std::nullopt;
  }
}

Token MSDependentExistsStmt::keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

CompoundStmt MSDependentExistsStmt::sub_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

bool MSDependentExistsStmt::is_if_exists(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

bool MSDependentExistsStmt::is_if_not_exists(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal14();
}

std::optional<IndirectGotoStmt> IndirectGotoStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<IndirectGotoStmt> IndirectGotoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::INDIRECT_GOTO_STMT:
      return reinterpret_cast<const IndirectGotoStmt &>(parent);
    default: return std::nullopt;
  }
}

LabelDecl IndirectGotoStmt::constant_target(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return LabelDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token IndirectGotoStmt::goto_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

Token IndirectGotoStmt::star_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal10());
}

Expr IndirectGotoStmt::target(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<IfStmt> IfStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<IfStmt> IfStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::IF_STMT:
      return reinterpret_cast<const IfStmt &>(parent);
    default: return std::nullopt;
  }
}

Expr IfStmt::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<VarDecl> IfStmt::condition_variable(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> IfStmt::condition_variable_declaration_statement(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal14()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal10());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<Stmt> IfStmt::else_(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal19()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal12());
    return fragment->StmtFor(fragment, id);
  }
}

Token IfStmt::else_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

Token IfStmt::if_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal16());
}

std::optional<Stmt> IfStmt::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal20()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal17());
    return fragment->StmtFor(fragment, id);
  }
}

Token IfStmt::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal18());
}

Token IfStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal25());
}

Stmt IfStmt::then(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal26());
  return Stmt(fragment->StmtFor(fragment, id));
}

bool IfStmt::has_else_storage(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal55();
}

bool IfStmt::has_initializer_storage(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal56();
}

bool IfStmt::has_variable_storage(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal57();
}

bool IfStmt::is_constexpr(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal58();
}

bool IfStmt::is_obj_c_availability_check(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal59();
}

std::optional<GotoStmt> GotoStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<GotoStmt> GotoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::GOTO_STMT:
      return reinterpret_cast<const GotoStmt &>(parent);
    default: return std::nullopt;
  }
}

Token GotoStmt::goto_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

LabelDecl GotoStmt::label(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return LabelDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token GotoStmt::label_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal10());
}

std::optional<ForStmt> ForStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ForStmt> ForStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::FOR_STMT:
      return reinterpret_cast<const ForStmt &>(parent);
    default: return std::nullopt;
  }
}

Stmt ForStmt::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<Expr> ForStmt::condition(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<VarDecl> ForStmt::condition_variable(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal14()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal10());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> ForStmt::condition_variable_declaration_statement(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal19()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal12());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

Token ForStmt::for_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

std::optional<Expr> ForStmt::increment(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal20()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal16());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<Stmt> ForStmt::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal55()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal17());
    return fragment->StmtFor(fragment, id);
  }
}

Token ForStmt::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal18());
}

Token ForStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal25());
}

std::optional<DoStmt> DoStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DoStmt> DoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DO_STMT:
      return reinterpret_cast<const DoStmt &>(parent);
    default: return std::nullopt;
  }
}

Stmt DoStmt::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr DoStmt::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token DoStmt::do_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal10());
}

Token DoStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal12());
}

Token DoStmt::while_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

std::optional<DeclStmt> DeclStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DeclStmt> DeclStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DECL_STMT:
      return reinterpret_cast<const DeclStmt &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Decl> DeclStmt::declarations(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<Decl> DeclStmt::single_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal8());
    return fragment->DeclFor(fragment, id);
  }
}

bool DeclStmt::is_single_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal14();
}

std::optional<CoroutineBodyStmt> CoroutineBodyStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CoroutineBodyStmt> CoroutineBodyStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COROUTINE_BODY_STMT:
      return reinterpret_cast<const CoroutineBodyStmt &>(parent);
    default: return std::nullopt;
  }
}

Expr CoroutineBodyStmt::allocate(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Stmt CoroutineBodyStmt::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr CoroutineBodyStmt::deallocate(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Stmt CoroutineBodyStmt::exception_handler(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt CoroutineBodyStmt::fallthrough_handler(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt CoroutineBodyStmt::final_suspend_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal16());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt CoroutineBodyStmt::initializer_suspend_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal17());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::vector<Stmt> CoroutineBodyStmt::parameter_moves(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Stmt> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->StmtFor(fragment, id));
  }
  return vec;
}

VarDecl CoroutineBodyStmt::promise_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal18());
  return VarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Stmt CoroutineBodyStmt::promise_declaration_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal25());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt CoroutineBodyStmt::result_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal26());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt CoroutineBodyStmt::return_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal27());
  return Stmt(fragment->StmtFor(fragment, id));
}

Stmt CoroutineBodyStmt::return_statement_on_alloc_failure(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal28());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr CoroutineBodyStmt::return_value_initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal29());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool CoroutineBodyStmt::has_dependent_promise_type(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

std::optional<CoreturnStmt> CoreturnStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CoreturnStmt> CoreturnStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CORETURN_STMT:
      return reinterpret_cast<const CoreturnStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CoreturnStmt::keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

Expr CoreturnStmt::operand(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CoreturnStmt::promise_call(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool CoreturnStmt::is_implicit(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

std::optional<ContinueStmt> ContinueStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ContinueStmt> ContinueStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CONTINUE_STMT:
      return reinterpret_cast<const ContinueStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ContinueStmt::continue_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

std::optional<CompoundStmt> CompoundStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CompoundStmt> CompoundStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COMPOUND_STMT:
      return reinterpret_cast<const CompoundStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CompoundStmt::left_brace_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

Token CompoundStmt::right_brace_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<Stmt> CompoundStmt::statement_expression_result(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal10());
    return fragment->StmtFor(fragment, id);
  }
}

std::optional<CapturedStmt> CapturedStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CapturedStmt> CapturedStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CAPTURED_STMT:
      return reinterpret_cast<const CapturedStmt &>(parent);
    default: return std::nullopt;
  }
}

CapturedDecl CapturedStmt::captured_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return CapturedDecl::from(fragment->DeclFor(fragment, id)).value();
}

RecordDecl CapturedStmt::captured_record_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return RecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

CapturedRegionKind CapturedStmt::captured_region_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<CapturedRegionKind>(self.getVal60());
}

Stmt CapturedStmt::captured_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<CXXTryStmt> CXXTryStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXTryStmt> CXXTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_TRY_STMT:
      return reinterpret_cast<const CXXTryStmt &>(parent);
    default: return std::nullopt;
  }
}

CompoundStmt CXXTryStmt::try_block(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

Token CXXTryStmt::try_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

std::vector<CXXCatchStmt> CXXTryStmt::handlers(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<CXXCatchStmt> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = CXXCatchStmt::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_FOR_RANGE_STMT:
      return reinterpret_cast<const CXXForRangeStmt &>(parent);
    default: return std::nullopt;
  }
}

DeclStmt CXXForRangeStmt::begin_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return DeclStmt::from(fragment->StmtFor(fragment, id)).value();
}

Stmt CXXForRangeStmt::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Stmt(fragment->StmtFor(fragment, id));
}

Token CXXForRangeStmt::coawait_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal10());
}

Token CXXForRangeStmt::colon_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal12());
}

Expr CXXForRangeStmt::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

DeclStmt CXXForRangeStmt::end_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal16());
  return DeclStmt::from(fragment->StmtFor(fragment, id)).value();
}

Token CXXForRangeStmt::for_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal17());
}

Expr CXXForRangeStmt::increment(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal18());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Stmt CXXForRangeStmt::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal25());
  return Stmt(fragment->StmtFor(fragment, id));
}

DeclStmt CXXForRangeStmt::loop_variable_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal26());
  return DeclStmt::from(fragment->StmtFor(fragment, id)).value();
}

VarDecl CXXForRangeStmt::loop_variable(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal27());
  return VarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token CXXForRangeStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal28());
}

Expr CXXForRangeStmt::range_initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal29());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

DeclStmt CXXForRangeStmt::range_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal30());
  return DeclStmt::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_CATCH_STMT:
      return reinterpret_cast<const CXXCatchStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CXXCatchStmt::catch_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

VarDecl CXXCatchStmt::exception_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return VarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Stmt CXXCatchStmt::handler_block(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<BreakStmt> BreakStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BreakStmt> BreakStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::BREAK_STMT:
      return reinterpret_cast<const BreakStmt &>(parent);
    default: return std::nullopt;
  }
}

Token BreakStmt::break_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

std::optional<AsmStmt> AsmStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<AsmStmt> AsmStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MS_ASM_STMT:
    case mx::StmtKind::GCC_ASM_STMT:
      return reinterpret_cast<const AsmStmt &>(parent);
    default: return std::nullopt;
  }
}

std::string_view AsmStmt::generate_assembly_string(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Token AsmStmt::assembly_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

std::vector<Expr> AsmStmt::inputs(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

bool AsmStmt::is_simple(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal11();
}

bool AsmStmt::is_volatile(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal14();
}

std::vector<Expr> AsmStmt::outputs(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal21();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<std::string_view> AsmStmt::output_constraints(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal62();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<Expr> AsmStmt::output_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal22();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<std::string_view> AsmStmt::input_constraints(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal63();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<Expr> AsmStmt::input_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal23();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<std::string_view> AsmStmt::clobbers(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal64();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::optional<MSAsmStmt> MSAsmStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MSAsmStmt> MSAsmStmt::from(const AsmStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MSAsmStmt> MSAsmStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MS_ASM_STMT:
      return reinterpret_cast<const MSAsmStmt &>(parent);
    default: return std::nullopt;
  }
}

std::vector<std::string_view> MSAsmStmt::all_constraints(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal65();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<Expr> MSAsmStmt::all_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal24();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::string_view MSAsmStmt::assembly_string(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal66();
  return std::string_view(data.cStr(), data.size());
}

Token MSAsmStmt::l_brace_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

bool MSAsmStmt::has_braces(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<GCCAsmStmt> GCCAsmStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<GCCAsmStmt> GCCAsmStmt::from(const AsmStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<GCCAsmStmt> GCCAsmStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::GCC_ASM_STMT:
      return reinterpret_cast<const GCCAsmStmt &>(parent);
    default: return std::nullopt;
  }
}

StringLiteral GCCAsmStmt::assembly_string(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return StringLiteral::from(fragment->StmtFor(fragment, id)).value();
}

Token GCCAsmStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal10());
}

bool GCCAsmStmt::is_assembly_goto(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::vector<AddrLabelExpr> GCCAsmStmt::labels(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal24();
  std::vector<AddrLabelExpr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = AddrLabelExpr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<StringLiteral> GCCAsmStmt::output_constraint_literals(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal51();
  std::vector<StringLiteral> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = StringLiteral::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<std::string_view> GCCAsmStmt::output_names(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal65();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<StringLiteral> GCCAsmStmt::input_constraint_literals(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal52();
  std::vector<StringLiteral> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = StringLiteral::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<std::string_view> GCCAsmStmt::input_names(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal67();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<StringLiteral> GCCAsmStmt::clobber_string_literals(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal53();
  std::vector<StringLiteral> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = StringLiteral::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<AddrLabelExpr> GCCAsmStmt::label_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal68();
  std::vector<AddrLabelExpr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = AddrLabelExpr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<std::string_view> GCCAsmStmt::label_names(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal69();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::optional<WhileStmt> WhileStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<WhileStmt> WhileStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::WHILE_STMT:
      return reinterpret_cast<const WhileStmt &>(parent);
    default: return std::nullopt;
  }
}

Stmt WhileStmt::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr WhileStmt::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<VarDecl> WhileStmt::condition_variable(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal10());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> WhileStmt::condition_variable_declaration_statement(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal14()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal12());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

Token WhileStmt::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

Token WhileStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal16());
}

Token WhileStmt::while_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal17());
}

bool WhileStmt::has_variable_storage(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

std::optional<ValueStmt> ValueStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ValueStmt> ValueStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::LABEL_STMT:
    case mx::StmtKind::DESIGNATED_INIT_UPDATE_EXPR:
    case mx::StmtKind::DESIGNATED_INIT_EXPR:
    case mx::StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR:
    case mx::StmtKind::DEPENDENT_COAWAIT_EXPR:
    case mx::StmtKind::DECL_REF_EXPR:
    case mx::StmtKind::COAWAIT_EXPR:
    case mx::StmtKind::COYIELD_EXPR:
    case mx::StmtKind::CONVERT_VECTOR_EXPR:
    case mx::StmtKind::CONCEPT_SPECIALIZATION_EXPR:
    case mx::StmtKind::COMPOUND_LITERAL_EXPR:
    case mx::StmtKind::CHOOSE_EXPR:
    case mx::StmtKind::CHARACTER_LITERAL:
    case mx::StmtKind::IMPLICIT_CAST_EXPR:
    case mx::StmtKind::CXX_DYNAMIC_CAST_EXPR:
    case mx::StmtKind::CXX_CONST_CAST_EXPR:
    case mx::StmtKind::CXX_ADDRSPACE_CAST_EXPR:
    case mx::StmtKind::CXX_STATIC_CAST_EXPR:
    case mx::StmtKind::CXX_REINTERPRET_CAST_EXPR:
    case mx::StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
    case mx::StmtKind::C_STYLE_CAST_EXPR:
    case mx::StmtKind::BUILTIN_BIT_CAST_EXPR:
    case mx::StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
    case mx::StmtKind::CALL_EXPR:
    case mx::StmtKind::CXX_OPERATOR_CALL_EXPR:
    case mx::StmtKind::CXX_MEMBER_CALL_EXPR:
    case mx::StmtKind::CUDA_KERNEL_CALL_EXPR:
    case mx::StmtKind::USER_DEFINED_LITERAL:
    case mx::StmtKind::CXX_UUIDOF_EXPR:
    case mx::StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR:
    case mx::StmtKind::CXX_TYPEID_EXPR:
    case mx::StmtKind::CXX_THROW_EXPR:
    case mx::StmtKind::CXX_THIS_EXPR:
    case mx::StmtKind::CXX_STD_INITIALIZER_LIST_EXPR:
    case mx::StmtKind::CXX_SCALAR_VALUE_INIT_EXPR:
    case mx::StmtKind::CXX_REWRITTEN_BINARY_OPERATOR:
    case mx::StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR:
    case mx::StmtKind::CXX_NULL_PTR_LITERAL_EXPR:
    case mx::StmtKind::CXX_NOEXCEPT_EXPR:
    case mx::StmtKind::CXX_NEW_EXPR:
    case mx::StmtKind::CXX_INHERITED_CTOR_INIT_EXPR:
    case mx::StmtKind::CXX_FOLD_EXPR:
    case mx::StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR:
    case mx::StmtKind::CXX_DELETE_EXPR:
    case mx::StmtKind::CXX_DEFAULT_INIT_EXPR:
    case mx::StmtKind::CXX_DEFAULT_ARG_EXPR:
    case mx::StmtKind::CXX_CONSTRUCT_EXPR:
    case mx::StmtKind::CXX_TEMPORARY_OBJECT_EXPR:
    case mx::StmtKind::CXX_BOOL_LITERAL_EXPR:
    case mx::StmtKind::CXX_BIND_TEMPORARY_EXPR:
    case mx::StmtKind::BLOCK_EXPR:
    case mx::StmtKind::BINARY_OPERATOR:
    case mx::StmtKind::COMPOUND_ASSIGN_OPERATOR:
    case mx::StmtKind::ATOMIC_EXPR:
    case mx::StmtKind::AS_TYPE_EXPR:
    case mx::StmtKind::ARRAY_TYPE_TRAIT_EXPR:
    case mx::StmtKind::ARRAY_SUBSCRIPT_EXPR:
    case mx::StmtKind::ARRAY_INIT_LOOP_EXPR:
    case mx::StmtKind::ARRAY_INIT_INDEX_EXPR:
    case mx::StmtKind::ADDR_LABEL_EXPR:
    case mx::StmtKind::CONDITIONAL_OPERATOR:
    case mx::StmtKind::BINARY_CONDITIONAL_OPERATOR:
    case mx::StmtKind::VA_ARG_EXPR:
    case mx::StmtKind::UNARY_OPERATOR:
    case mx::StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR:
    case mx::StmtKind::TYPO_EXPR:
    case mx::StmtKind::TYPE_TRAIT_EXPR:
    case mx::StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR:
    case mx::StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR:
    case mx::StmtKind::STRING_LITERAL:
    case mx::StmtKind::STMT_EXPR:
    case mx::StmtKind::SOURCE_LOC_EXPR:
    case mx::StmtKind::SIZE_OF_PACK_EXPR:
    case mx::StmtKind::SHUFFLE_VECTOR_EXPR:
    case mx::StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR:
    case mx::StmtKind::REQUIRES_EXPR:
    case mx::StmtKind::RECOVERY_EXPR:
    case mx::StmtKind::PSEUDO_OBJECT_EXPR:
    case mx::StmtKind::PREDEFINED_EXPR:
    case mx::StmtKind::PAREN_LIST_EXPR:
    case mx::StmtKind::PAREN_EXPR:
    case mx::StmtKind::PACK_EXPANSION_EXPR:
    case mx::StmtKind::UNRESOLVED_MEMBER_EXPR:
    case mx::StmtKind::UNRESOLVED_LOOKUP_EXPR:
    case mx::StmtKind::OPAQUE_VALUE_EXPR:
    case mx::StmtKind::OFFSET_OF_EXPR:
    case mx::StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR:
    case mx::StmtKind::OBJ_C_STRING_LITERAL:
    case mx::StmtKind::OBJ_C_SELECTOR_EXPR:
    case mx::StmtKind::OBJ_C_PROTOCOL_EXPR:
    case mx::StmtKind::OBJ_C_PROPERTY_REF_EXPR:
    case mx::StmtKind::OBJ_C_MESSAGE_EXPR:
    case mx::StmtKind::OBJ_C_IVAR_REF_EXPR:
    case mx::StmtKind::OBJ_C_ISA_EXPR:
    case mx::StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR:
    case mx::StmtKind::OBJ_C_ENCODE_EXPR:
    case mx::StmtKind::OBJ_C_DICTIONARY_LITERAL:
    case mx::StmtKind::OBJ_C_BOXED_EXPR:
    case mx::StmtKind::OBJ_C_BOOL_LITERAL_EXPR:
    case mx::StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR:
    case mx::StmtKind::OBJ_C_ARRAY_LITERAL:
    case mx::StmtKind::OMP_ITERATOR_EXPR:
    case mx::StmtKind::OMP_ARRAY_SHAPING_EXPR:
    case mx::StmtKind::OMP_ARRAY_SECTION_EXPR:
    case mx::StmtKind::NO_INIT_EXPR:
    case mx::StmtKind::MEMBER_EXPR:
    case mx::StmtKind::MATRIX_SUBSCRIPT_EXPR:
    case mx::StmtKind::MATERIALIZE_TEMPORARY_EXPR:
    case mx::StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR:
    case mx::StmtKind::MS_PROPERTY_REF_EXPR:
    case mx::StmtKind::LAMBDA_EXPR:
    case mx::StmtKind::INTEGER_LITERAL:
    case mx::StmtKind::INIT_LIST_EXPR:
    case mx::StmtKind::IMPLICIT_VALUE_INIT_EXPR:
    case mx::StmtKind::IMAGINARY_LITERAL:
    case mx::StmtKind::GENERIC_SELECTION_EXPR:
    case mx::StmtKind::GNU_NULL_EXPR:
    case mx::StmtKind::FUNCTION_PARM_PACK_EXPR:
    case mx::StmtKind::EXPR_WITH_CLEANUPS:
    case mx::StmtKind::CONSTANT_EXPR:
    case mx::StmtKind::FLOATING_LITERAL:
    case mx::StmtKind::FIXED_POINT_LITERAL:
    case mx::StmtKind::EXT_VECTOR_ELEMENT_EXPR:
    case mx::StmtKind::EXPRESSION_TRAIT_EXPR:
    case mx::StmtKind::ATTRIBUTED_STMT:
      return reinterpret_cast<const ValueStmt &>(parent);
    default: return std::nullopt;
  }
}

std::optional<Expr> ValueStmt::expression_statement(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal8());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<LabelStmt> LabelStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<LabelStmt> LabelStmt::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<LabelStmt> LabelStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::LABEL_STMT:
      return reinterpret_cast<const LabelStmt &>(parent);
    default: return std::nullopt;
  }
}

LabelDecl LabelStmt::declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return LabelDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token LabelStmt::identifier_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal10());
}

std::string_view LabelStmt::name(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Stmt LabelStmt::sub_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return Stmt(fragment->StmtFor(fragment, id));
}

bool LabelStmt::is_side_entry(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal14();
}

std::optional<Expr> Expr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<Expr> Expr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<Expr> Expr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DESIGNATED_INIT_UPDATE_EXPR:
    case mx::StmtKind::DESIGNATED_INIT_EXPR:
    case mx::StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR:
    case mx::StmtKind::DEPENDENT_COAWAIT_EXPR:
    case mx::StmtKind::DECL_REF_EXPR:
    case mx::StmtKind::COAWAIT_EXPR:
    case mx::StmtKind::COYIELD_EXPR:
    case mx::StmtKind::CONVERT_VECTOR_EXPR:
    case mx::StmtKind::CONCEPT_SPECIALIZATION_EXPR:
    case mx::StmtKind::COMPOUND_LITERAL_EXPR:
    case mx::StmtKind::CHOOSE_EXPR:
    case mx::StmtKind::CHARACTER_LITERAL:
    case mx::StmtKind::IMPLICIT_CAST_EXPR:
    case mx::StmtKind::CXX_DYNAMIC_CAST_EXPR:
    case mx::StmtKind::CXX_CONST_CAST_EXPR:
    case mx::StmtKind::CXX_ADDRSPACE_CAST_EXPR:
    case mx::StmtKind::CXX_STATIC_CAST_EXPR:
    case mx::StmtKind::CXX_REINTERPRET_CAST_EXPR:
    case mx::StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
    case mx::StmtKind::C_STYLE_CAST_EXPR:
    case mx::StmtKind::BUILTIN_BIT_CAST_EXPR:
    case mx::StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
    case mx::StmtKind::CALL_EXPR:
    case mx::StmtKind::CXX_OPERATOR_CALL_EXPR:
    case mx::StmtKind::CXX_MEMBER_CALL_EXPR:
    case mx::StmtKind::CUDA_KERNEL_CALL_EXPR:
    case mx::StmtKind::USER_DEFINED_LITERAL:
    case mx::StmtKind::CXX_UUIDOF_EXPR:
    case mx::StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR:
    case mx::StmtKind::CXX_TYPEID_EXPR:
    case mx::StmtKind::CXX_THROW_EXPR:
    case mx::StmtKind::CXX_THIS_EXPR:
    case mx::StmtKind::CXX_STD_INITIALIZER_LIST_EXPR:
    case mx::StmtKind::CXX_SCALAR_VALUE_INIT_EXPR:
    case mx::StmtKind::CXX_REWRITTEN_BINARY_OPERATOR:
    case mx::StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR:
    case mx::StmtKind::CXX_NULL_PTR_LITERAL_EXPR:
    case mx::StmtKind::CXX_NOEXCEPT_EXPR:
    case mx::StmtKind::CXX_NEW_EXPR:
    case mx::StmtKind::CXX_INHERITED_CTOR_INIT_EXPR:
    case mx::StmtKind::CXX_FOLD_EXPR:
    case mx::StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR:
    case mx::StmtKind::CXX_DELETE_EXPR:
    case mx::StmtKind::CXX_DEFAULT_INIT_EXPR:
    case mx::StmtKind::CXX_DEFAULT_ARG_EXPR:
    case mx::StmtKind::CXX_CONSTRUCT_EXPR:
    case mx::StmtKind::CXX_TEMPORARY_OBJECT_EXPR:
    case mx::StmtKind::CXX_BOOL_LITERAL_EXPR:
    case mx::StmtKind::CXX_BIND_TEMPORARY_EXPR:
    case mx::StmtKind::BLOCK_EXPR:
    case mx::StmtKind::BINARY_OPERATOR:
    case mx::StmtKind::COMPOUND_ASSIGN_OPERATOR:
    case mx::StmtKind::ATOMIC_EXPR:
    case mx::StmtKind::AS_TYPE_EXPR:
    case mx::StmtKind::ARRAY_TYPE_TRAIT_EXPR:
    case mx::StmtKind::ARRAY_SUBSCRIPT_EXPR:
    case mx::StmtKind::ARRAY_INIT_LOOP_EXPR:
    case mx::StmtKind::ARRAY_INIT_INDEX_EXPR:
    case mx::StmtKind::ADDR_LABEL_EXPR:
    case mx::StmtKind::CONDITIONAL_OPERATOR:
    case mx::StmtKind::BINARY_CONDITIONAL_OPERATOR:
    case mx::StmtKind::VA_ARG_EXPR:
    case mx::StmtKind::UNARY_OPERATOR:
    case mx::StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR:
    case mx::StmtKind::TYPO_EXPR:
    case mx::StmtKind::TYPE_TRAIT_EXPR:
    case mx::StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR:
    case mx::StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR:
    case mx::StmtKind::STRING_LITERAL:
    case mx::StmtKind::STMT_EXPR:
    case mx::StmtKind::SOURCE_LOC_EXPR:
    case mx::StmtKind::SIZE_OF_PACK_EXPR:
    case mx::StmtKind::SHUFFLE_VECTOR_EXPR:
    case mx::StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR:
    case mx::StmtKind::REQUIRES_EXPR:
    case mx::StmtKind::RECOVERY_EXPR:
    case mx::StmtKind::PSEUDO_OBJECT_EXPR:
    case mx::StmtKind::PREDEFINED_EXPR:
    case mx::StmtKind::PAREN_LIST_EXPR:
    case mx::StmtKind::PAREN_EXPR:
    case mx::StmtKind::PACK_EXPANSION_EXPR:
    case mx::StmtKind::UNRESOLVED_MEMBER_EXPR:
    case mx::StmtKind::UNRESOLVED_LOOKUP_EXPR:
    case mx::StmtKind::OPAQUE_VALUE_EXPR:
    case mx::StmtKind::OFFSET_OF_EXPR:
    case mx::StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR:
    case mx::StmtKind::OBJ_C_STRING_LITERAL:
    case mx::StmtKind::OBJ_C_SELECTOR_EXPR:
    case mx::StmtKind::OBJ_C_PROTOCOL_EXPR:
    case mx::StmtKind::OBJ_C_PROPERTY_REF_EXPR:
    case mx::StmtKind::OBJ_C_MESSAGE_EXPR:
    case mx::StmtKind::OBJ_C_IVAR_REF_EXPR:
    case mx::StmtKind::OBJ_C_ISA_EXPR:
    case mx::StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR:
    case mx::StmtKind::OBJ_C_ENCODE_EXPR:
    case mx::StmtKind::OBJ_C_DICTIONARY_LITERAL:
    case mx::StmtKind::OBJ_C_BOXED_EXPR:
    case mx::StmtKind::OBJ_C_BOOL_LITERAL_EXPR:
    case mx::StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR:
    case mx::StmtKind::OBJ_C_ARRAY_LITERAL:
    case mx::StmtKind::OMP_ITERATOR_EXPR:
    case mx::StmtKind::OMP_ARRAY_SHAPING_EXPR:
    case mx::StmtKind::OMP_ARRAY_SECTION_EXPR:
    case mx::StmtKind::NO_INIT_EXPR:
    case mx::StmtKind::MEMBER_EXPR:
    case mx::StmtKind::MATRIX_SUBSCRIPT_EXPR:
    case mx::StmtKind::MATERIALIZE_TEMPORARY_EXPR:
    case mx::StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR:
    case mx::StmtKind::MS_PROPERTY_REF_EXPR:
    case mx::StmtKind::LAMBDA_EXPR:
    case mx::StmtKind::INTEGER_LITERAL:
    case mx::StmtKind::INIT_LIST_EXPR:
    case mx::StmtKind::IMPLICIT_VALUE_INIT_EXPR:
    case mx::StmtKind::IMAGINARY_LITERAL:
    case mx::StmtKind::GENERIC_SELECTION_EXPR:
    case mx::StmtKind::GNU_NULL_EXPR:
    case mx::StmtKind::FUNCTION_PARM_PACK_EXPR:
    case mx::StmtKind::EXPR_WITH_CLEANUPS:
    case mx::StmtKind::CONSTANT_EXPR:
    case mx::StmtKind::FLOATING_LITERAL:
    case mx::StmtKind::FIXED_POINT_LITERAL:
    case mx::StmtKind::EXT_VECTOR_ELEMENT_EXPR:
    case mx::StmtKind::EXPRESSION_TRAIT_EXPR:
      return reinterpret_cast<const Expr &>(parent);
    default: return std::nullopt;
  }
}

bool Expr::has_side_effects(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal14();
}

Expr Expr::ignore_casts(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_conversion_operator_single_step(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_imp_casts(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_implicit(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal13());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_implicit_as_written(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal16());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_parenthesis_base_casts(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal17());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_parenthesis_casts(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal18());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_parenthesis_imp_casts(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal25());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_parenthesis_l_value_casts(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal26());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_parenthesis_noop_casts(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal27());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_parentheses(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal28());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr Expr::ignore_unless_spelled_in_source(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal29());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool Expr::contains_errors(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal19();
}

bool Expr::contains_unexpanded_parameter_pack(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal20();
}

Expr Expr::best_dynamic_class_type_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal30());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token Expr::expression_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal31());
}

std::optional<ObjCPropertyRefExpr> Expr::obj_c_property(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal55()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal32());
    return ObjCPropertyRefExpr::from(fragment->StmtFor(fragment, id));
  }
}

ExprObjectKind Expr::object_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ExprObjectKind>(self.getVal60());
}

std::optional<Decl> Expr::referenced_declaration_of_callee(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal56()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal33());
    return fragment->DeclFor(fragment, id);
  }
}

std::optional<FieldDecl> Expr::source_bit_field(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal57()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal34());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

ExprValueKind Expr::value_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ExprValueKind>(self.getVal70());
}

bool Expr::has_non_trivial_call(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal58();
}

bool Expr::is_default_argument(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal59();
}

bool Expr::is_gl_value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal71();
}

bool Expr::is_implicit_cxx_this(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal72();
}

bool Expr::is_instantiation_dependent(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal73();
}

bool Expr::is_known_to_have_boolean_value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal74();
}

bool Expr::is_l_value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal75();
}

bool Expr::is_objcgc_candidate(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal76();
}

bool Expr::is_obj_c_self_expression(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal77();
}

bool Expr::is_ordinary_or_bit_field_object(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal78();
}

bool Expr::is_pr_value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal79();
}

bool Expr::is_read_if_discarded_in_c_plus_plus11(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal80();
}

bool Expr::is_type_dependent(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal81();
}

bool Expr::is_value_dependent(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal82();
}

bool Expr::is_x_value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal83();
}

bool Expr::refers_to_bit_field(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal84();
}

bool Expr::refers_to_global_register_variable(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal85();
}

bool Expr::refers_to_matrix_element(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal86();
}

bool Expr::refers_to_vector_element(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal87();
}

std::optional<DesignatedInitUpdateExpr> DesignatedInitUpdateExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DesignatedInitUpdateExpr> DesignatedInitUpdateExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DesignatedInitUpdateExpr> DesignatedInitUpdateExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DesignatedInitUpdateExpr> DesignatedInitUpdateExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DESIGNATED_INIT_UPDATE_EXPR:
      return reinterpret_cast<const DesignatedInitUpdateExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr DesignatedInitUpdateExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

InitListExpr DesignatedInitUpdateExpr::updater(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return InitListExpr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DesignatedInitExpr> DesignatedInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DESIGNATED_INIT_EXPR:
      return reinterpret_cast<const DesignatedInitExpr &>(parent);
    default: return std::nullopt;
  }
}

TokenRange DesignatedInitExpr::designators_source_range(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal35(), self.getVal36());
}

Token DesignatedInitExpr::equal_or_colon_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Expr DesignatedInitExpr::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool DesignatedInitExpr::is_direct_initializer(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool DesignatedInitExpr::uses_gnu_syntax(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::vector<Expr> DesignatedInitExpr::sub_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DependentScopeDeclRefExpr> DependentScopeDeclRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR:
      return reinterpret_cast<const DependentScopeDeclRefExpr &>(parent);
    default: return std::nullopt;
  }
}

Token DependentScopeDeclRefExpr::l_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token DependentScopeDeclRefExpr::r_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token DependentScopeDeclRefExpr::template_keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

bool DependentScopeDeclRefExpr::has_explicit_template_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool DependentScopeDeclRefExpr::has_template_keyword(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DependentCoawaitExpr> DependentCoawaitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DEPENDENT_COAWAIT_EXPR:
      return reinterpret_cast<const DependentCoawaitExpr &>(parent);
    default: return std::nullopt;
  }
}

Token DependentCoawaitExpr::keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Expr DependentCoawaitExpr::operand(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

UnresolvedLookupExpr DependentCoawaitExpr::operator_coawait_lookup(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return UnresolvedLookupExpr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<DeclRefExpr> DeclRefExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DeclRefExpr> DeclRefExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DeclRefExpr> DeclRefExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DeclRefExpr> DeclRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DECL_REF_EXPR:
      return reinterpret_cast<const DeclRefExpr &>(parent);
    default: return std::nullopt;
  }
}

ValueDecl DeclRefExpr::declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return ValueDecl::from(fragment->DeclFor(fragment, id)).value();
}

NamedDecl DeclRefExpr::found_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token DeclRefExpr::l_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token DeclRefExpr::r_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Token DeclRefExpr::template_keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

bool DeclRefExpr::had_multiple_candidates(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool DeclRefExpr::has_explicit_template_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool DeclRefExpr::has_qualifier(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool DeclRefExpr::has_template_kw_and_arguments_info(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool DeclRefExpr::has_template_keyword(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

NonOdrUseReason DeclRefExpr::is_non_odr_use(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<NonOdrUseReason>(self.getVal93());
}

bool DeclRefExpr::refers_to_enclosing_variable_or_capture(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoroutineSuspendExpr> CoroutineSuspendExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COAWAIT_EXPR:
    case mx::StmtKind::COYIELD_EXPR:
      return reinterpret_cast<const CoroutineSuspendExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CoroutineSuspendExpr::common_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token CoroutineSuspendExpr::keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

OpaqueValueExpr CoroutineSuspendExpr::opaque_value(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return OpaqueValueExpr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CoroutineSuspendExpr::ready_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CoroutineSuspendExpr::resume_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CoroutineSuspendExpr::suspend_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<CoawaitExpr> CoawaitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CoawaitExpr> CoawaitExpr::from(const CoroutineSuspendExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoawaitExpr> CoawaitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoawaitExpr> CoawaitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoawaitExpr> CoawaitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COAWAIT_EXPR:
      return reinterpret_cast<const CoawaitExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CoawaitExpr::operand(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool CoawaitExpr::is_implicit(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CoyieldExpr> CoyieldExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CoyieldExpr> CoyieldExpr::from(const CoroutineSuspendExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoyieldExpr> CoyieldExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoyieldExpr> CoyieldExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CoyieldExpr> CoyieldExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COYIELD_EXPR:
      return reinterpret_cast<const CoyieldExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CoyieldExpr::operand(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ConvertVectorExpr> ConvertVectorExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ConvertVectorExpr> ConvertVectorExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConvertVectorExpr> ConvertVectorExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConvertVectorExpr> ConvertVectorExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CONVERT_VECTOR_EXPR:
      return reinterpret_cast<const ConvertVectorExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ConvertVectorExpr::builtin_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token ConvertVectorExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Expr ConvertVectorExpr::src_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ConceptSpecializationExpr> ConceptSpecializationExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ConceptSpecializationExpr> ConceptSpecializationExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConceptSpecializationExpr> ConceptSpecializationExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConceptSpecializationExpr> ConceptSpecializationExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CONCEPT_SPECIALIZATION_EXPR:
      return reinterpret_cast<const ConceptSpecializationExpr &>(parent);
    default: return std::nullopt;
  }
}

std::vector<TemplateArgument> ConceptSpecializationExpr::template_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal95();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

bool ConceptSpecializationExpr::is_satisfied(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CompoundLiteralExpr> CompoundLiteralExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COMPOUND_LITERAL_EXPR:
      return reinterpret_cast<const CompoundLiteralExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CompoundLiteralExpr::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token CompoundLiteralExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

bool CompoundLiteralExpr::is_file_scope(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ChooseExpr> ChooseExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ChooseExpr> ChooseExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ChooseExpr> ChooseExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ChooseExpr> ChooseExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CHOOSE_EXPR:
      return reinterpret_cast<const ChooseExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ChooseExpr::builtin_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Expr ChooseExpr::chosen_sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ChooseExpr::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ChooseExpr::lhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ChooseExpr::rhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token ChooseExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

bool ChooseExpr::is_condition_dependent(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool ChooseExpr::is_condition_true(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<CharacterLiteral> CharacterLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CharacterLiteral> CharacterLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CharacterLiteral> CharacterLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CharacterLiteral> CharacterLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CHARACTER_LITERAL:
      return reinterpret_cast<const CharacterLiteral &>(parent);
    default: return std::nullopt;
  }
}

Token CharacterLiteral::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

std::optional<CastExpr> CastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CastExpr> CastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CastExpr> CastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CastExpr> CastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::IMPLICIT_CAST_EXPR:
    case mx::StmtKind::CXX_DYNAMIC_CAST_EXPR:
    case mx::StmtKind::CXX_CONST_CAST_EXPR:
    case mx::StmtKind::CXX_ADDRSPACE_CAST_EXPR:
    case mx::StmtKind::CXX_STATIC_CAST_EXPR:
    case mx::StmtKind::CXX_REINTERPRET_CAST_EXPR:
    case mx::StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
    case mx::StmtKind::C_STYLE_CAST_EXPR:
    case mx::StmtKind::BUILTIN_BIT_CAST_EXPR:
    case mx::StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
      return reinterpret_cast<const CastExpr &>(parent);
    default: return std::nullopt;
  }
}

CastKind CastExpr::cast_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<CastKind>(self.getVal93());
}

std::string_view CastExpr::cast_kind_name(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

std::optional<NamedDecl> CastExpr::conversion_function(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal88()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal35());
    return NamedDecl::from(fragment->DeclFor(fragment, id));
  }
}

Expr CastExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CastExpr::sub_expression_as_written(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<FieldDecl> CastExpr::target_union_field(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal89()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal38());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool CastExpr::has_stored_fp_features(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

std::optional<ImplicitCastExpr> ImplicitCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ImplicitCastExpr> ImplicitCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ImplicitCastExpr> ImplicitCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ImplicitCastExpr> ImplicitCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ImplicitCastExpr> ImplicitCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::IMPLICIT_CAST_EXPR:
      return reinterpret_cast<const ImplicitCastExpr &>(parent);
    default: return std::nullopt;
  }
}

bool ImplicitCastExpr::is_part_of_explicit_cast(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExplicitCastExpr> ExplicitCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_DYNAMIC_CAST_EXPR:
    case mx::StmtKind::CXX_CONST_CAST_EXPR:
    case mx::StmtKind::CXX_ADDRSPACE_CAST_EXPR:
    case mx::StmtKind::CXX_STATIC_CAST_EXPR:
    case mx::StmtKind::CXX_REINTERPRET_CAST_EXPR:
    case mx::StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
    case mx::StmtKind::C_STYLE_CAST_EXPR:
    case mx::StmtKind::BUILTIN_BIT_CAST_EXPR:
    case mx::StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
      return reinterpret_cast<const ExplicitCastExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNamedCastExpr> CXXNamedCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_DYNAMIC_CAST_EXPR:
    case mx::StmtKind::CXX_CONST_CAST_EXPR:
    case mx::StmtKind::CXX_ADDRSPACE_CAST_EXPR:
    case mx::StmtKind::CXX_STATIC_CAST_EXPR:
    case mx::StmtKind::CXX_REINTERPRET_CAST_EXPR:
      return reinterpret_cast<const CXXNamedCastExpr &>(parent);
    default: return std::nullopt;
  }
}

TokenRange CXXNamedCastExpr::angle_brackets(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal39(), self.getVal40());
}

std::string_view CXXNamedCastExpr::cast_name(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal66();
  return std::string_view(data.cStr(), data.size());
}

Token CXXNamedCastExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal41());
}

Token CXXNamedCastExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal42());
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const CXXNamedCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDynamicCastExpr> CXXDynamicCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_DYNAMIC_CAST_EXPR:
      return reinterpret_cast<const CXXDynamicCastExpr &>(parent);
    default: return std::nullopt;
  }
}

bool CXXDynamicCastExpr::is_always_null(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

std::optional<CXXConstCastExpr> CXXConstCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXConstCastExpr> CXXConstCastExpr::from(const CXXNamedCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXConstCastExpr> CXXConstCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXConstCastExpr> CXXConstCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXConstCastExpr> CXXConstCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXConstCastExpr> CXXConstCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXConstCastExpr> CXXConstCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_CONST_CAST_EXPR:
      return reinterpret_cast<const CXXConstCastExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const CXXNamedCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXAddrspaceCastExpr> CXXAddrspaceCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_ADDRSPACE_CAST_EXPR:
      return reinterpret_cast<const CXXAddrspaceCastExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<CXXStaticCastExpr> CXXStaticCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXStaticCastExpr> CXXStaticCastExpr::from(const CXXNamedCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXStaticCastExpr> CXXStaticCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXStaticCastExpr> CXXStaticCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXStaticCastExpr> CXXStaticCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXStaticCastExpr> CXXStaticCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXStaticCastExpr> CXXStaticCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_STATIC_CAST_EXPR:
      return reinterpret_cast<const CXXStaticCastExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const CXXNamedCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXReinterpretCastExpr> CXXReinterpretCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_REINTERPRET_CAST_EXPR:
      return reinterpret_cast<const CXXReinterpretCastExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<CXXFunctionalCastExpr> CXXFunctionalCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXFunctionalCastExpr> CXXFunctionalCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXFunctionalCastExpr> CXXFunctionalCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXFunctionalCastExpr> CXXFunctionalCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXFunctionalCastExpr> CXXFunctionalCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXFunctionalCastExpr> CXXFunctionalCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_FUNCTIONAL_CAST_EXPR:
      return reinterpret_cast<const CXXFunctionalCastExpr &>(parent);
    default: return std::nullopt;
  }
}

Token CXXFunctionalCastExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

Token CXXFunctionalCastExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

bool CXXFunctionalCastExpr::is_list_initialization(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

std::optional<CStyleCastExpr> CStyleCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CStyleCastExpr> CStyleCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CStyleCastExpr> CStyleCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CStyleCastExpr> CStyleCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CStyleCastExpr> CStyleCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CStyleCastExpr> CStyleCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::C_STYLE_CAST_EXPR:
      return reinterpret_cast<const CStyleCastExpr &>(parent);
    default: return std::nullopt;
  }
}

Token CStyleCastExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

Token CStyleCastExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

std::optional<BuiltinBitCastExpr> BuiltinBitCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BuiltinBitCastExpr> BuiltinBitCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BuiltinBitCastExpr> BuiltinBitCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BuiltinBitCastExpr> BuiltinBitCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BuiltinBitCastExpr> BuiltinBitCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BuiltinBitCastExpr> BuiltinBitCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::BUILTIN_BIT_CAST_EXPR:
      return reinterpret_cast<const BuiltinBitCastExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const ExplicitCastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const CastExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBridgedCastExpr> ObjCBridgedCastExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_BRIDGED_CAST_EXPR:
      return reinterpret_cast<const ObjCBridgedCastExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCBridgedCastExpr::bridge_keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

ObjCBridgeCastKind ObjCBridgedCastExpr::bridge_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ObjCBridgeCastKind>(self.getVal96());
}

std::string_view ObjCBridgedCastExpr::bridge_kind_name(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal66();
  return std::string_view(data.cStr(), data.size());
}

Token ObjCBridgedCastExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

std::optional<CallExpr> CallExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CallExpr> CallExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CallExpr> CallExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CallExpr> CallExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CALL_EXPR:
    case mx::StmtKind::CXX_OPERATOR_CALL_EXPR:
    case mx::StmtKind::CXX_MEMBER_CALL_EXPR:
    case mx::StmtKind::CUDA_KERNEL_CALL_EXPR:
    case mx::StmtKind::USER_DEFINED_LITERAL:
      return reinterpret_cast<const CallExpr &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> CallExpr::arguments(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

CallExprADLCallKind CallExpr::adl_call_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<CallExprADLCallKind>(self.getVal93());
}

Expr CallExpr::callee(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<Decl> CallExpr::callee_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal88()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal36());
    return fragment->DeclFor(fragment, id);
  }
}

std::optional<FunctionDecl> CallExpr::direct_callee(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal89()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal37());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token CallExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

bool CallExpr::has_stored_fp_features(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool CallExpr::has_unused_result_attribute(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool CallExpr::is_builtin_assume_false(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool CallExpr::is_call_to_std_move(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

bool CallExpr::is_unevaluated_builtin_call(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

bool CallExpr::uses_adl(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal98();
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const CallExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXOperatorCallExpr> CXXOperatorCallExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_OPERATOR_CALL_EXPR:
      return reinterpret_cast<const CXXOperatorCallExpr &>(parent);
    default: return std::nullopt;
  }
}

OverloadedOperatorKind CXXOperatorCallExpr::operator_(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<OverloadedOperatorKind>(self.getVal96());
}

Token CXXOperatorCallExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

bool CXXOperatorCallExpr::is_assignment_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal99();
}

bool CXXOperatorCallExpr::is_comparison_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal100();
}

bool CXXOperatorCallExpr::is_infix_binary_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal101();
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const CallExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXMemberCallExpr> CXXMemberCallExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_MEMBER_CALL_EXPR:
      return reinterpret_cast<const CXXMemberCallExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXMemberCallExpr::implicit_object_argument(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

CXXMethodDecl CXXMemberCallExpr::method_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return CXXMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

CXXRecordDecl CXXMemberCallExpr::record_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const CallExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CUDAKernelCallExpr> CUDAKernelCallExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CUDA_KERNEL_CALL_EXPR:
      return reinterpret_cast<const CUDAKernelCallExpr &>(parent);
    default: return std::nullopt;
  }
}

CallExpr CUDAKernelCallExpr::config(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return CallExpr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const CallExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UserDefinedLiteral> UserDefinedLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::USER_DEFINED_LITERAL:
      return reinterpret_cast<const UserDefinedLiteral &>(parent);
    default: return std::nullopt;
  }
}

Expr UserDefinedLiteral::cooked_literal(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

UserDefinedLiteralLiteralOperatorKind UserDefinedLiteral::literal_operator_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<UserDefinedLiteralLiteralOperatorKind>(self.getVal96());
}

Token UserDefinedLiteral::ud_suffix_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXUuidofExpr> CXXUuidofExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_UUIDOF_EXPR:
      return reinterpret_cast<const CXXUuidofExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXUuidofExpr::expression_operand(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

MSGuidDecl CXXUuidofExpr::guid_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return MSGuidDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool CXXUuidofExpr::is_type_operand(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXUnresolvedConstructExpr> CXXUnresolvedConstructExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR:
      return reinterpret_cast<const CXXUnresolvedConstructExpr &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> CXXUnresolvedConstructExpr::arguments(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

Token CXXUnresolvedConstructExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token CXXUnresolvedConstructExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

bool CXXUnresolvedConstructExpr::is_list_initialization(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CXXTypeidExpr> CXXTypeidExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXTypeidExpr> CXXTypeidExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXTypeidExpr> CXXTypeidExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXTypeidExpr> CXXTypeidExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_TYPEID_EXPR:
      return reinterpret_cast<const CXXTypeidExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXTypeidExpr::expression_operand(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool CXXTypeidExpr::is_most_derived(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool CXXTypeidExpr::is_potentially_evaluated(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool CXXTypeidExpr::is_type_operand(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

std::optional<CXXThrowExpr> CXXThrowExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXThrowExpr> CXXThrowExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXThrowExpr> CXXThrowExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXThrowExpr> CXXThrowExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_THROW_EXPR:
      return reinterpret_cast<const CXXThrowExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXThrowExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token CXXThrowExpr::throw_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

bool CXXThrowExpr::is_thrown_variable_in_scope(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CXXThisExpr> CXXThisExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXThisExpr> CXXThisExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXThisExpr> CXXThisExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXThisExpr> CXXThisExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_THIS_EXPR:
      return reinterpret_cast<const CXXThisExpr &>(parent);
    default: return std::nullopt;
  }
}

Token CXXThisExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

bool CXXThisExpr::is_implicit(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXStdInitializerListExpr> CXXStdInitializerListExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_STD_INITIALIZER_LIST_EXPR:
      return reinterpret_cast<const CXXStdInitializerListExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXStdInitializerListExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXScalarValueInitExpr> CXXScalarValueInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_SCALAR_VALUE_INIT_EXPR:
      return reinterpret_cast<const CXXScalarValueInitExpr &>(parent);
    default: return std::nullopt;
  }
}

Token CXXScalarValueInitExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

std::optional<CXXRewrittenBinaryOperator> CXXRewrittenBinaryOperator::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXRewrittenBinaryOperator> CXXRewrittenBinaryOperator::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXRewrittenBinaryOperator> CXXRewrittenBinaryOperator::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXRewrittenBinaryOperator> CXXRewrittenBinaryOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_REWRITTEN_BINARY_OPERATOR:
      return reinterpret_cast<const CXXRewrittenBinaryOperator &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXRewrittenBinaryOperator::lhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

BinaryOperatorKind CXXRewrittenBinaryOperator::opcode(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<BinaryOperatorKind>(self.getVal93());
}

std::string_view CXXRewrittenBinaryOperator::opcode_string(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

BinaryOperatorKind CXXRewrittenBinaryOperator::operator_(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<BinaryOperatorKind>(self.getVal96());
}

Token CXXRewrittenBinaryOperator::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Expr CXXRewrittenBinaryOperator::rhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CXXRewrittenBinaryOperator::semantic_form(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool CXXRewrittenBinaryOperator::is_assignment_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool CXXRewrittenBinaryOperator::is_comparison_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool CXXRewrittenBinaryOperator::is_reversed(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXPseudoDestructorExpr> CXXPseudoDestructorExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR:
      return reinterpret_cast<const CXXPseudoDestructorExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXPseudoDestructorExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token CXXPseudoDestructorExpr::colon_colon_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token CXXPseudoDestructorExpr::destroyed_type_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token CXXPseudoDestructorExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Token CXXPseudoDestructorExpr::tilde_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

bool CXXPseudoDestructorExpr::has_qualifier(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool CXXPseudoDestructorExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNullPtrLiteralExpr> CXXNullPtrLiteralExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_NULL_PTR_LITERAL_EXPR:
      return reinterpret_cast<const CXXNullPtrLiteralExpr &>(parent);
    default: return std::nullopt;
  }
}

Token CXXNullPtrLiteralExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

std::optional<CXXNoexceptExpr> CXXNoexceptExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXNoexceptExpr> CXXNoexceptExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNoexceptExpr> CXXNoexceptExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNoexceptExpr> CXXNoexceptExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_NOEXCEPT_EXPR:
      return reinterpret_cast<const CXXNoexceptExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXNoexceptExpr::operand(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool CXXNoexceptExpr::value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CXXNewExpr> CXXNewExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXNewExpr> CXXNewExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNewExpr> CXXNewExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXNewExpr> CXXNewExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_NEW_EXPR:
      return reinterpret_cast<const CXXNewExpr &>(parent);
    default: return std::nullopt;
  }
}

bool CXXNewExpr::does_usual_array_delete_want_size(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<Expr> CXXNewExpr::array_size(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal89()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal35());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

CXXConstructExpr CXXNewExpr::construct_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return CXXConstructExpr::from(fragment->StmtFor(fragment, id)).value();
}

TokenRange CXXNewExpr::direct_initializer_range(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal37(), self.getVal38());
}

CXXNewExprInitializationStyle CXXNewExpr::initialization_style(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<CXXNewExprInitializationStyle>(self.getVal93());
}

Expr CXXNewExpr::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

FunctionDecl CXXNewExpr::operator_delete(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return FunctionDecl::from(fragment->DeclFor(fragment, id)).value();
}

FunctionDecl CXXNewExpr::operator_new(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return FunctionDecl::from(fragment->DeclFor(fragment, id)).value();
}

TokenRange CXXNewExpr::type_id_parentheses(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal42(), self.getVal43());
}

bool CXXNewExpr::has_initializer(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool CXXNewExpr::is_array(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool CXXNewExpr::is_global_new(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool CXXNewExpr::is_parenthesis_type_id(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

bool CXXNewExpr::pass_alignment(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

std::vector<Expr> CXXNewExpr::placement_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

bool CXXNewExpr::should_null_check_allocation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal98();
}

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXInheritedCtorInitExpr> CXXInheritedCtorInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_INHERITED_CTOR_INIT_EXPR:
      return reinterpret_cast<const CXXInheritedCtorInitExpr &>(parent);
    default: return std::nullopt;
  }
}

bool CXXInheritedCtorInitExpr::constructs_virtual_base(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

CXXConstructExprConstructionKind CXXInheritedCtorInitExpr::construction_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<CXXConstructExprConstructionKind>(self.getVal93());
}

CXXConstructorDecl CXXInheritedCtorInitExpr::constructor(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return CXXConstructorDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token CXXInheritedCtorInitExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

bool CXXInheritedCtorInitExpr::inherited_from_virtual_base(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<CXXFoldExpr> CXXFoldExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXFoldExpr> CXXFoldExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXFoldExpr> CXXFoldExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXFoldExpr> CXXFoldExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_FOLD_EXPR:
      return reinterpret_cast<const CXXFoldExpr &>(parent);
    default: return std::nullopt;
  }
}

UnresolvedLookupExpr CXXFoldExpr::callee(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return UnresolvedLookupExpr::from(fragment->StmtFor(fragment, id)).value();
}

Token CXXFoldExpr::ellipsis_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Expr CXXFoldExpr::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CXXFoldExpr::lhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token CXXFoldExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

BinaryOperatorKind CXXFoldExpr::operator_(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<BinaryOperatorKind>(self.getVal93());
}

Expr CXXFoldExpr::pattern(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr CXXFoldExpr::rhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token CXXFoldExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal42());
}

bool CXXFoldExpr::is_left_fold(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool CXXFoldExpr::is_right_fold(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDependentScopeMemberExpr> CXXDependentScopeMemberExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR:
      return reinterpret_cast<const CXXDependentScopeMemberExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXDependentScopeMemberExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

NamedDecl CXXDependentScopeMemberExpr::first_qualifier_found_in_scope(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token CXXDependentScopeMemberExpr::l_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token CXXDependentScopeMemberExpr::member_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Token CXXDependentScopeMemberExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

Token CXXDependentScopeMemberExpr::r_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

Token CXXDependentScopeMemberExpr::template_keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal41());
}

bool CXXDependentScopeMemberExpr::has_explicit_template_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool CXXDependentScopeMemberExpr::has_template_keyword(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool CXXDependentScopeMemberExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool CXXDependentScopeMemberExpr::is_implicit_access(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

std::optional<CXXDeleteExpr> CXXDeleteExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXDeleteExpr> CXXDeleteExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDeleteExpr> CXXDeleteExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDeleteExpr> CXXDeleteExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_DELETE_EXPR:
      return reinterpret_cast<const CXXDeleteExpr &>(parent);
    default: return std::nullopt;
  }
}

bool CXXDeleteExpr::does_usual_array_delete_want_size(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

Expr CXXDeleteExpr::argument(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

FunctionDecl CXXDeleteExpr::operator_delete(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return FunctionDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool CXXDeleteExpr::is_array_form(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool CXXDeleteExpr::is_array_form_as_written(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool CXXDeleteExpr::is_global_delete(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

std::optional<CXXDefaultInitExpr> CXXDefaultInitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXDefaultInitExpr> CXXDefaultInitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDefaultInitExpr> CXXDefaultInitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDefaultInitExpr> CXXDefaultInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_DEFAULT_INIT_EXPR:
      return reinterpret_cast<const CXXDefaultInitExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXDefaultInitExpr::expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

FieldDecl CXXDefaultInitExpr::field(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return FieldDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token CXXDefaultInitExpr::used_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXDefaultArgExpr> CXXDefaultArgExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_DEFAULT_ARG_EXPR:
      return reinterpret_cast<const CXXDefaultArgExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXDefaultArgExpr::expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ParmVarDecl CXXDefaultArgExpr::parameter(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return ParmVarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token CXXDefaultArgExpr::used_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXConstructExpr> CXXConstructExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_CONSTRUCT_EXPR:
    case mx::StmtKind::CXX_TEMPORARY_OBJECT_EXPR:
      return reinterpret_cast<const CXXConstructExpr &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> CXXConstructExpr::arguments(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

CXXConstructExprConstructionKind CXXConstructExpr::construction_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<CXXConstructExprConstructionKind>(self.getVal93());
}

CXXConstructorDecl CXXConstructExpr::constructor(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return CXXConstructorDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token CXXConstructExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

TokenRange CXXConstructExpr::parenthesis_or_brace_range(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal37(), self.getVal38());
}

bool CXXConstructExpr::had_multiple_candidates(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool CXXConstructExpr::is_elidable(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool CXXConstructExpr::is_list_initialization(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool CXXConstructExpr::is_std_initializer_list_initialization(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool CXXConstructExpr::requires_zero_initialization(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

std::optional<CXXTemporaryObjectExpr> CXXTemporaryObjectExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXTemporaryObjectExpr> CXXTemporaryObjectExpr::from(const CXXConstructExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXTemporaryObjectExpr> CXXTemporaryObjectExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXTemporaryObjectExpr> CXXTemporaryObjectExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXTemporaryObjectExpr> CXXTemporaryObjectExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_TEMPORARY_OBJECT_EXPR:
      return reinterpret_cast<const CXXTemporaryObjectExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<CXXBoolLiteralExpr> CXXBoolLiteralExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXBoolLiteralExpr> CXXBoolLiteralExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXBoolLiteralExpr> CXXBoolLiteralExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXBoolLiteralExpr> CXXBoolLiteralExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_BOOL_LITERAL_EXPR:
      return reinterpret_cast<const CXXBoolLiteralExpr &>(parent);
    default: return std::nullopt;
  }
}

Token CXXBoolLiteralExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

bool CXXBoolLiteralExpr::value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<CXXBindTemporaryExpr> CXXBindTemporaryExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXBindTemporaryExpr> CXXBindTemporaryExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXBindTemporaryExpr> CXXBindTemporaryExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CXXBindTemporaryExpr> CXXBindTemporaryExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_BIND_TEMPORARY_EXPR:
      return reinterpret_cast<const CXXBindTemporaryExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr CXXBindTemporaryExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<BlockExpr> BlockExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BlockExpr> BlockExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BlockExpr> BlockExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BlockExpr> BlockExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::BLOCK_EXPR:
      return reinterpret_cast<const BlockExpr &>(parent);
    default: return std::nullopt;
  }
}

BlockDecl BlockExpr::block_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return BlockDecl::from(fragment->DeclFor(fragment, id)).value();
}

Stmt BlockExpr::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Stmt(fragment->StmtFor(fragment, id));
}

Token BlockExpr::caret_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<BinaryOperator> BinaryOperator::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BinaryOperator> BinaryOperator::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BinaryOperator> BinaryOperator::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BinaryOperator> BinaryOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::BINARY_OPERATOR:
    case mx::StmtKind::COMPOUND_ASSIGN_OPERATOR:
      return reinterpret_cast<const BinaryOperator &>(parent);
    default: return std::nullopt;
  }
}

Expr BinaryOperator::lhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

BinaryOperatorKind BinaryOperator::opcode(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<BinaryOperatorKind>(self.getVal93());
}

std::string_view BinaryOperator::opcode_string(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Token BinaryOperator::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Expr BinaryOperator::rhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool BinaryOperator::has_stored_fp_features(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool BinaryOperator::is_additive_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool BinaryOperator::is_assignment_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool BinaryOperator::is_bitwise_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool BinaryOperator::is_comma_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool BinaryOperator::is_comparison_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

bool BinaryOperator::is_compound_assignment_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

bool BinaryOperator::is_equality_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal98();
}

bool BinaryOperator::is_logical_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal99();
}

bool BinaryOperator::is_multiplicative_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal100();
}

bool BinaryOperator::is_pointer_memory_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal101();
}

bool BinaryOperator::is_relational_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal102();
}

bool BinaryOperator::is_shift_assign_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal103();
}

bool BinaryOperator::is_shift_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal104();
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const BinaryOperator &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CompoundAssignOperator> CompoundAssignOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COMPOUND_ASSIGN_OPERATOR:
      return reinterpret_cast<const CompoundAssignOperator &>(parent);
    default: return std::nullopt;
  }
}

std::optional<AtomicExpr> AtomicExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<AtomicExpr> AtomicExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AtomicExpr> AtomicExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AtomicExpr> AtomicExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::ATOMIC_EXPR:
      return reinterpret_cast<const AtomicExpr &>(parent);
    default: return std::nullopt;
  }
}

Token AtomicExpr::builtin_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

AtomicExprAtomicOp AtomicExpr::operation(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<AtomicExprAtomicOp>(self.getVal93());
}

Expr AtomicExpr::order(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<Expr> AtomicExpr::order_fail(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal88()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal37());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

Expr AtomicExpr::pointer(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token AtomicExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

std::optional<Expr> AtomicExpr::scope(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal89()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal40());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<Expr> AtomicExpr::value1(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal90()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal41());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<Expr> AtomicExpr::value2(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal91()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal42());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<Expr> AtomicExpr::weak(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal92()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal43());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

bool AtomicExpr::is_cmp_x_chg(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

bool AtomicExpr::is_open_cl(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

bool AtomicExpr::is_volatile(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal98();
}

std::vector<Expr> AtomicExpr::sub_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<AsTypeExpr> AsTypeExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<AsTypeExpr> AsTypeExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AsTypeExpr> AsTypeExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AsTypeExpr> AsTypeExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::AS_TYPE_EXPR:
      return reinterpret_cast<const AsTypeExpr &>(parent);
    default: return std::nullopt;
  }
}

Token AsTypeExpr::builtin_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token AsTypeExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Expr AsTypeExpr::src_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArrayTypeTraitExpr> ArrayTypeTraitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::ARRAY_TYPE_TRAIT_EXPR:
      return reinterpret_cast<const ArrayTypeTraitExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr ArrayTypeTraitExpr::dimension_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ArrayTypeTrait ArrayTypeTraitExpr::trait(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ArrayTypeTrait>(self.getVal93());
}

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArraySubscriptExpr> ArraySubscriptExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::ARRAY_SUBSCRIPT_EXPR:
      return reinterpret_cast<const ArraySubscriptExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr ArraySubscriptExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ArraySubscriptExpr::index(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ArraySubscriptExpr::lhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token ArraySubscriptExpr::r_bracket_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Expr ArraySubscriptExpr::rhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArrayInitLoopExpr> ArrayInitLoopExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::ARRAY_INIT_LOOP_EXPR:
      return reinterpret_cast<const ArrayInitLoopExpr &>(parent);
    default: return std::nullopt;
  }
}

OpaqueValueExpr ArrayInitLoopExpr::common_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return OpaqueValueExpr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ArrayInitLoopExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ArrayInitIndexExpr> ArrayInitIndexExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ArrayInitIndexExpr> ArrayInitIndexExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArrayInitIndexExpr> ArrayInitIndexExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ArrayInitIndexExpr> ArrayInitIndexExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::ARRAY_INIT_INDEX_EXPR:
      return reinterpret_cast<const ArrayInitIndexExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<AddrLabelExpr> AddrLabelExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<AddrLabelExpr> AddrLabelExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AddrLabelExpr> AddrLabelExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AddrLabelExpr> AddrLabelExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::ADDR_LABEL_EXPR:
      return reinterpret_cast<const AddrLabelExpr &>(parent);
    default: return std::nullopt;
  }
}

Token AddrLabelExpr::amp_amp_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

LabelDecl AddrLabelExpr::label(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return LabelDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token AddrLabelExpr::label_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AbstractConditionalOperator> AbstractConditionalOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CONDITIONAL_OPERATOR:
    case mx::StmtKind::BINARY_CONDITIONAL_OPERATOR:
      return reinterpret_cast<const AbstractConditionalOperator &>(parent);
    default: return std::nullopt;
  }
}

Token AbstractConditionalOperator::colon_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Expr AbstractConditionalOperator::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr AbstractConditionalOperator::false_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token AbstractConditionalOperator::question_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Expr AbstractConditionalOperator::true_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ConditionalOperator> ConditionalOperator::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ConditionalOperator> ConditionalOperator::from(const AbstractConditionalOperator &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConditionalOperator> ConditionalOperator::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConditionalOperator> ConditionalOperator::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConditionalOperator> ConditionalOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CONDITIONAL_OPERATOR:
      return reinterpret_cast<const ConditionalOperator &>(parent);
    default: return std::nullopt;
  }
}

Expr ConditionalOperator::lhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ConditionalOperator::rhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<BinaryConditionalOperator> BinaryConditionalOperator::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BinaryConditionalOperator> BinaryConditionalOperator::from(const AbstractConditionalOperator &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BinaryConditionalOperator> BinaryConditionalOperator::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BinaryConditionalOperator> BinaryConditionalOperator::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<BinaryConditionalOperator> BinaryConditionalOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::BINARY_CONDITIONAL_OPERATOR:
      return reinterpret_cast<const BinaryConditionalOperator &>(parent);
    default: return std::nullopt;
  }
}

Expr BinaryConditionalOperator::common(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

OpaqueValueExpr BinaryConditionalOperator::opaque_value(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return OpaqueValueExpr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<VAArgExpr> VAArgExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<VAArgExpr> VAArgExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<VAArgExpr> VAArgExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<VAArgExpr> VAArgExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::VA_ARG_EXPR:
      return reinterpret_cast<const VAArgExpr &>(parent);
    default: return std::nullopt;
  }
}

Token VAArgExpr::builtin_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token VAArgExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Expr VAArgExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool VAArgExpr::is_microsoft_abi(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<UnaryOperator> UnaryOperator::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UnaryOperator> UnaryOperator::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnaryOperator> UnaryOperator::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnaryOperator> UnaryOperator::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::UNARY_OPERATOR:
      return reinterpret_cast<const UnaryOperator &>(parent);
    default: return std::nullopt;
  }
}

bool UnaryOperator::can_overflow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

UnaryOperatorKind UnaryOperator::opcode(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<UnaryOperatorKind>(self.getVal93());
}

Token UnaryOperator::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Expr UnaryOperator::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool UnaryOperator::has_stored_fp_features(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool UnaryOperator::is_arithmetic_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool UnaryOperator::is_decrement_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool UnaryOperator::is_increment_decrement_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool UnaryOperator::is_increment_operation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

bool UnaryOperator::is_postfix(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

bool UnaryOperator::is_prefix(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal98();
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnaryExprOrTypeTraitExpr> UnaryExprOrTypeTraitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR:
      return reinterpret_cast<const UnaryExprOrTypeTraitExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<Expr> UnaryExprOrTypeTraitExpr::argument_expression(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal88()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal35());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

Token UnaryExprOrTypeTraitExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token UnaryExprOrTypeTraitExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

bool UnaryExprOrTypeTraitExpr::is_argument_type(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<TypoExpr> TypoExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TypoExpr> TypoExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<TypoExpr> TypoExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<TypoExpr> TypoExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::TYPO_EXPR:
      return reinterpret_cast<const TypoExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TypeTraitExpr> TypeTraitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TypeTraitExpr> TypeTraitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<TypeTraitExpr> TypeTraitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<TypeTraitExpr> TypeTraitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::TYPE_TRAIT_EXPR:
      return reinterpret_cast<const TypeTraitExpr &>(parent);
    default: return std::nullopt;
  }
}

TypeTrait TypeTraitExpr::trait(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<TypeTrait>(self.getVal93());
}

bool TypeTraitExpr::value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<SubstNonTypeTemplateParmPackExpr> SubstNonTypeTemplateParmPackExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SubstNonTypeTemplateParmPackExpr> SubstNonTypeTemplateParmPackExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SubstNonTypeTemplateParmPackExpr> SubstNonTypeTemplateParmPackExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SubstNonTypeTemplateParmPackExpr> SubstNonTypeTemplateParmPackExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR:
      return reinterpret_cast<const SubstNonTypeTemplateParmPackExpr &>(parent);
    default: return std::nullopt;
  }
}

NonTypeTemplateParmDecl SubstNonTypeTemplateParmPackExpr::parameter_pack(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return NonTypeTemplateParmDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token SubstNonTypeTemplateParmPackExpr::parameter_pack_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SubstNonTypeTemplateParmExpr> SubstNonTypeTemplateParmExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR:
      return reinterpret_cast<const SubstNonTypeTemplateParmExpr &>(parent);
    default: return std::nullopt;
  }
}

Token SubstNonTypeTemplateParmExpr::name_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

NonTypeTemplateParmDecl SubstNonTypeTemplateParmExpr::parameter(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return NonTypeTemplateParmDecl::from(fragment->DeclFor(fragment, id)).value();
}

Expr SubstNonTypeTemplateParmExpr::replacement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool SubstNonTypeTemplateParmExpr::is_reference_parameter(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<StringLiteral> StringLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<StringLiteral> StringLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<StringLiteral> StringLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<StringLiteral> StringLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::STRING_LITERAL:
      return reinterpret_cast<const StringLiteral &>(parent);
    default: return std::nullopt;
  }
}

bool StringLiteral::contains_non_ascii(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool StringLiteral::contains_non_ascii_or_null(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::string_view StringLiteral::bytes(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

std::string_view StringLiteral::string(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal66();
  return std::string_view(data.cStr(), data.size());
}

bool StringLiteral::is_ascii(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool StringLiteral::is_pascal(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool StringLiteral::is_utf16(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool StringLiteral::is_utf32(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

bool StringLiteral::is_utf8(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

bool StringLiteral::is_wide(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal98();
}

std::optional<StmtExpr> StmtExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<StmtExpr> StmtExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<StmtExpr> StmtExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<StmtExpr> StmtExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::STMT_EXPR:
      return reinterpret_cast<const StmtExpr &>(parent);
    default: return std::nullopt;
  }
}

Token StmtExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token StmtExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

CompoundStmt StmtExpr::sub_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<SourceLocExpr> SourceLocExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SourceLocExpr> SourceLocExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SourceLocExpr> SourceLocExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SourceLocExpr> SourceLocExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SOURCE_LOC_EXPR:
      return reinterpret_cast<const SourceLocExpr &>(parent);
    default: return std::nullopt;
  }
}

std::string_view SourceLocExpr::builtin_string(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

SourceLocExprIdentKind SourceLocExpr::identifier_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<SourceLocExprIdentKind>(self.getVal93());
}

Token SourceLocExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

bool SourceLocExpr::is_int_type(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool SourceLocExpr::is_string_type(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SizeOfPackExpr> SizeOfPackExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SIZE_OF_PACK_EXPR:
      return reinterpret_cast<const SizeOfPackExpr &>(parent);
    default: return std::nullopt;
  }
}

Token SizeOfPackExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

NamedDecl SizeOfPackExpr::pack(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token SizeOfPackExpr::pack_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::vector<TemplateArgument> SizeOfPackExpr::partial_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal95();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

Token SizeOfPackExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

bool SizeOfPackExpr::is_partially_substituted(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ShuffleVectorExpr> ShuffleVectorExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ShuffleVectorExpr> ShuffleVectorExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ShuffleVectorExpr> ShuffleVectorExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ShuffleVectorExpr> ShuffleVectorExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SHUFFLE_VECTOR_EXPR:
      return reinterpret_cast<const ShuffleVectorExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ShuffleVectorExpr::builtin_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token ShuffleVectorExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::optional<SYCLUniqueStableNameExpr> SYCLUniqueStableNameExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SYCLUniqueStableNameExpr> SYCLUniqueStableNameExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SYCLUniqueStableNameExpr> SYCLUniqueStableNameExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<SYCLUniqueStableNameExpr> SYCLUniqueStableNameExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR:
      return reinterpret_cast<const SYCLUniqueStableNameExpr &>(parent);
    default: return std::nullopt;
  }
}

std::string_view SYCLUniqueStableNameExpr::compute_name(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Token SYCLUniqueStableNameExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token SYCLUniqueStableNameExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token SYCLUniqueStableNameExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<RequiresExpr> RequiresExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<RequiresExpr> RequiresExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<RequiresExpr> RequiresExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<RequiresExpr> RequiresExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::REQUIRES_EXPR:
      return reinterpret_cast<const RequiresExpr &>(parent);
    default: return std::nullopt;
  }
}

RequiresExprBodyDecl RequiresExpr::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return RequiresExprBodyDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::vector<ParmVarDecl> RequiresExpr::local_parameters(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<ParmVarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ParmVarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

Token RequiresExpr::r_brace_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token RequiresExpr::requires_kw_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

bool RequiresExpr::is_satisfied(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<RecoveryExpr> RecoveryExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<RecoveryExpr> RecoveryExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<RecoveryExpr> RecoveryExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<RecoveryExpr> RecoveryExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::RECOVERY_EXPR:
      return reinterpret_cast<const RecoveryExpr &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> RecoveryExpr::sub_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<PseudoObjectExpr> PseudoObjectExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::PSEUDO_OBJECT_EXPR:
      return reinterpret_cast<const PseudoObjectExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr PseudoObjectExpr::result_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr PseudoObjectExpr::syntactic_form(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::vector<Expr> PseudoObjectExpr::semantics(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Expr> PseudoObjectExpr::semantic_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal21();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<PredefinedExpr> PredefinedExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<PredefinedExpr> PredefinedExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<PredefinedExpr> PredefinedExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<PredefinedExpr> PredefinedExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::PREDEFINED_EXPR:
      return reinterpret_cast<const PredefinedExpr &>(parent);
    default: return std::nullopt;
  }
}

StringLiteral PredefinedExpr::function_name(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return StringLiteral::from(fragment->StmtFor(fragment, id)).value();
}

PredefinedExprIdentKind PredefinedExpr::identifier_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<PredefinedExprIdentKind>(self.getVal93());
}

std::string_view PredefinedExpr::identifier_kind_name(void) const {
  auto self = fragment->NthStmt(offset);
  capnp::Text::Reader data = self.getVal61();
  return std::string_view(data.cStr(), data.size());
}

Token PredefinedExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::optional<ParenListExpr> ParenListExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ParenListExpr> ParenListExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ParenListExpr> ParenListExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ParenListExpr> ParenListExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::PAREN_LIST_EXPR:
      return reinterpret_cast<const ParenListExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ParenListExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token ParenListExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::vector<Expr> ParenListExpr::expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<ParenExpr> ParenExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ParenExpr> ParenExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ParenExpr> ParenExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ParenExpr> ParenExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::PAREN_EXPR:
      return reinterpret_cast<const ParenExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ParenExpr::l_paren(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token ParenExpr::r_paren(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Expr ParenExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<PackExpansionExpr> PackExpansionExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<PackExpansionExpr> PackExpansionExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<PackExpansionExpr> PackExpansionExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<PackExpansionExpr> PackExpansionExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::PACK_EXPANSION_EXPR:
      return reinterpret_cast<const PackExpansionExpr &>(parent);
    default: return std::nullopt;
  }
}

Token PackExpansionExpr::ellipsis_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Expr PackExpansionExpr::pattern(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<OverloadExpr> OverloadExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OverloadExpr> OverloadExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OverloadExpr> OverloadExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OverloadExpr> OverloadExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::UNRESOLVED_MEMBER_EXPR:
    case mx::StmtKind::UNRESOLVED_LOOKUP_EXPR:
      return reinterpret_cast<const OverloadExpr &>(parent);
    default: return std::nullopt;
  }
}

Token OverloadExpr::l_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token OverloadExpr::name_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

CXXRecordDecl OverloadExpr::naming_class(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token OverloadExpr::r_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Token OverloadExpr::template_keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

bool OverloadExpr::has_explicit_template_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool OverloadExpr::has_template_keyword(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const OverloadExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnresolvedMemberExpr> UnresolvedMemberExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::UNRESOLVED_MEMBER_EXPR:
      return reinterpret_cast<const UnresolvedMemberExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr UnresolvedMemberExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal40());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token UnresolvedMemberExpr::member_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal41());
}

Token UnresolvedMemberExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal42());
}

bool UnresolvedMemberExpr::has_unresolved_using(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool UnresolvedMemberExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool UnresolvedMemberExpr::is_implicit_access(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

std::optional<UnresolvedLookupExpr> UnresolvedLookupExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UnresolvedLookupExpr> UnresolvedLookupExpr::from(const OverloadExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnresolvedLookupExpr> UnresolvedLookupExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnresolvedLookupExpr> UnresolvedLookupExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<UnresolvedLookupExpr> UnresolvedLookupExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::UNRESOLVED_LOOKUP_EXPR:
      return reinterpret_cast<const UnresolvedLookupExpr &>(parent);
    default: return std::nullopt;
  }
}

bool UnresolvedLookupExpr::is_overloaded(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool UnresolvedLookupExpr::requires_adl(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

std::optional<OpaqueValueExpr> OpaqueValueExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OpaqueValueExpr> OpaqueValueExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OpaqueValueExpr> OpaqueValueExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OpaqueValueExpr> OpaqueValueExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OPAQUE_VALUE_EXPR:
      return reinterpret_cast<const OpaqueValueExpr &>(parent);
    default: return std::nullopt;
  }
}

Token OpaqueValueExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Expr OpaqueValueExpr::source_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool OpaqueValueExpr::is_unique(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<OffsetOfExpr> OffsetOfExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OffsetOfExpr> OffsetOfExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OffsetOfExpr> OffsetOfExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OffsetOfExpr> OffsetOfExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OFFSET_OF_EXPR:
      return reinterpret_cast<const OffsetOfExpr &>(parent);
    default: return std::nullopt;
  }
}

Token OffsetOfExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token OffsetOfExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCSubscriptRefExpr> ObjCSubscriptRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR:
      return reinterpret_cast<const ObjCSubscriptRefExpr &>(parent);
    default: return std::nullopt;
  }
}

ObjCMethodDecl ObjCSubscriptRefExpr::at_index_method_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

Expr ObjCSubscriptRefExpr::base_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr ObjCSubscriptRefExpr::key_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token ObjCSubscriptRefExpr::r_bracket(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

bool ObjCSubscriptRefExpr::is_array_subscript_reference_expression(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ObjCStringLiteral> ObjCStringLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCStringLiteral> ObjCStringLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCStringLiteral> ObjCStringLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCStringLiteral> ObjCStringLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_STRING_LITERAL:
      return reinterpret_cast<const ObjCStringLiteral &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCStringLiteral::at_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

StringLiteral ObjCStringLiteral::string(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return StringLiteral::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ObjCSelectorExpr> ObjCSelectorExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCSelectorExpr> ObjCSelectorExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCSelectorExpr> ObjCSelectorExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCSelectorExpr> ObjCSelectorExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_SELECTOR_EXPR:
      return reinterpret_cast<const ObjCSelectorExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCSelectorExpr::at_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token ObjCSelectorExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCProtocolExpr> ObjCProtocolExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_PROTOCOL_EXPR:
      return reinterpret_cast<const ObjCProtocolExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCProtocolExpr::at_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

ObjCProtocolDecl ObjCProtocolExpr::protocol(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return ObjCProtocolDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCProtocolExpr::protocol_id_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token ObjCProtocolExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCPropertyRefExpr> ObjCPropertyRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_PROPERTY_REF_EXPR:
      return reinterpret_cast<const ObjCPropertyRefExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr ObjCPropertyRefExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ObjCInterfaceDecl ObjCPropertyRefExpr::class_receiver(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCPropertyDecl ObjCPropertyRefExpr::explicit_property(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return ObjCPropertyDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCMethodDecl ObjCPropertyRefExpr::implicit_property_getter(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCMethodDecl ObjCPropertyRefExpr::implicit_property_setter(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCPropertyRefExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

Token ObjCPropertyRefExpr::receiver_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal41());
}

bool ObjCPropertyRefExpr::is_class_receiver(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool ObjCPropertyRefExpr::is_explicit_property(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool ObjCPropertyRefExpr::is_implicit_property(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool ObjCPropertyRefExpr::is_messaging_getter(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool ObjCPropertyRefExpr::is_messaging_setter(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool ObjCPropertyRefExpr::is_object_receiver(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

bool ObjCPropertyRefExpr::is_super_receiver(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

std::optional<ObjCMessageExpr> ObjCMessageExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCMessageExpr> ObjCMessageExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCMessageExpr> ObjCMessageExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCMessageExpr> ObjCMessageExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_MESSAGE_EXPR:
      return reinterpret_cast<const ObjCMessageExpr &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> ObjCMessageExpr::arguments(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

Expr ObjCMessageExpr::instance_receiver(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token ObjCMessageExpr::left_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

ObjCMethodDecl ObjCMessageExpr::method_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCMethodFamily ObjCMessageExpr::method_family(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ObjCMethodFamily>(self.getVal93());
}

ObjCInterfaceDecl ObjCMessageExpr::receiver_interface(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCMessageExprReceiverKind ObjCMessageExpr::receiver_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ObjCMessageExprReceiverKind>(self.getVal96());
}

TokenRange ObjCMessageExpr::receiver_range(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal39(), self.getVal40());
}

Token ObjCMessageExpr::right_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal41());
}

Token ObjCMessageExpr::selector_start_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal42());
}

Token ObjCMessageExpr::super_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal43());
}

bool ObjCMessageExpr::is_class_message(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool ObjCMessageExpr::is_delegate_initializer_call(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool ObjCMessageExpr::is_implicit(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool ObjCMessageExpr::is_instance_message(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

std::vector<Token> ObjCMessageExpr::selector_tokens(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal21();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCIvarRefExpr> ObjCIvarRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_IVAR_REF_EXPR:
      return reinterpret_cast<const ObjCIvarRefExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr ObjCIvarRefExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ObjCIvarDecl ObjCIvarRefExpr::declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return ObjCIvarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCIvarRefExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token ObjCIvarRefExpr::operation_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

bool ObjCIvarRefExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool ObjCIvarRefExpr::is_free_instance_variable(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<ObjCIsaExpr> ObjCIsaExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCIsaExpr> ObjCIsaExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCIsaExpr> ObjCIsaExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCIsaExpr> ObjCIsaExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_ISA_EXPR:
      return reinterpret_cast<const ObjCIsaExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr ObjCIsaExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token ObjCIsaExpr::base_token_end(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token ObjCIsaExpr::isa_member_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token ObjCIsaExpr::operation_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

bool ObjCIsaExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ObjCIndirectCopyRestoreExpr> ObjCIndirectCopyRestoreExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCIndirectCopyRestoreExpr> ObjCIndirectCopyRestoreExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCIndirectCopyRestoreExpr> ObjCIndirectCopyRestoreExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCIndirectCopyRestoreExpr> ObjCIndirectCopyRestoreExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR:
      return reinterpret_cast<const ObjCIndirectCopyRestoreExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr ObjCIndirectCopyRestoreExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool ObjCIndirectCopyRestoreExpr::should_copy(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ObjCEncodeExpr> ObjCEncodeExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCEncodeExpr> ObjCEncodeExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCEncodeExpr> ObjCEncodeExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCEncodeExpr> ObjCEncodeExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_ENCODE_EXPR:
      return reinterpret_cast<const ObjCEncodeExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCEncodeExpr::at_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token ObjCEncodeExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCDictionaryLiteral> ObjCDictionaryLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_DICTIONARY_LITERAL:
      return reinterpret_cast<const ObjCDictionaryLiteral &>(parent);
    default: return std::nullopt;
  }
}

ObjCMethodDecl ObjCDictionaryLiteral::dictionary_with_objects_method(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<ObjCBoxedExpr> ObjCBoxedExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCBoxedExpr> ObjCBoxedExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBoxedExpr> ObjCBoxedExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBoxedExpr> ObjCBoxedExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_BOXED_EXPR:
      return reinterpret_cast<const ObjCBoxedExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCBoxedExpr::at_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

ObjCMethodDecl ObjCBoxedExpr::boxing_method(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

Expr ObjCBoxedExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool ObjCBoxedExpr::is_expressible_as_constant_initializer(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCBoolLiteralExpr> ObjCBoolLiteralExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_BOOL_LITERAL_EXPR:
      return reinterpret_cast<const ObjCBoolLiteralExpr &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCBoolLiteralExpr::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

bool ObjCBoolLiteralExpr::value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCAvailabilityCheckExpr> ObjCAvailabilityCheckExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR:
      return reinterpret_cast<const ObjCAvailabilityCheckExpr &>(parent);
    default: return std::nullopt;
  }
}

bool ObjCAvailabilityCheckExpr::has_version(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ObjCArrayLiteral> ObjCArrayLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_ARRAY_LITERAL:
      return reinterpret_cast<const ObjCArrayLiteral &>(parent);
    default: return std::nullopt;
  }
}

ObjCMethodDecl ObjCArrayLiteral::array_with_objects_method(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::vector<Expr> ObjCArrayLiteral::elements(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<OMPIteratorExpr> OMPIteratorExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPIteratorExpr> OMPIteratorExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPIteratorExpr> OMPIteratorExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPIteratorExpr> OMPIteratorExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_ITERATOR_EXPR:
      return reinterpret_cast<const OMPIteratorExpr &>(parent);
    default: return std::nullopt;
  }
}

Token OMPIteratorExpr::iterator_kw_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Token OMPIteratorExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token OMPIteratorExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<OMPArrayShapingExpr> OMPArrayShapingExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPArrayShapingExpr> OMPArrayShapingExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPArrayShapingExpr> OMPArrayShapingExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPArrayShapingExpr> OMPArrayShapingExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_ARRAY_SHAPING_EXPR:
      return reinterpret_cast<const OMPArrayShapingExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPArrayShapingExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::vector<Expr> OMPArrayShapingExpr::dimensions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

Token OMPArrayShapingExpr::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token OMPArrayShapingExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<OMPArraySectionExpr> OMPArraySectionExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_ARRAY_SECTION_EXPR:
      return reinterpret_cast<const OMPArraySectionExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPArraySectionExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token OMPArraySectionExpr::colon_token_first(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token OMPArraySectionExpr::colon_token_second(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Expr OMPArraySectionExpr::length(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPArraySectionExpr::lower_bound(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token OMPArraySectionExpr::r_bracket_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

Expr OMPArraySectionExpr::stride(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<NoInitExpr> NoInitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<NoInitExpr> NoInitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<NoInitExpr> NoInitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<NoInitExpr> NoInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::NO_INIT_EXPR:
      return reinterpret_cast<const NoInitExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<MemberExpr> MemberExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MemberExpr> MemberExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MemberExpr> MemberExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MemberExpr> MemberExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MEMBER_EXPR:
      return reinterpret_cast<const MemberExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr MemberExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token MemberExpr::l_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

ValueDecl MemberExpr::member_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return ValueDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token MemberExpr::member_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Token MemberExpr::operator_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal39());
}

Token MemberExpr::r_angle_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal40());
}

Token MemberExpr::template_keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal41());
}

bool MemberExpr::had_multiple_candidates(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool MemberExpr::has_explicit_template_arguments(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

bool MemberExpr::has_qualifier(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool MemberExpr::has_template_keyword(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool MemberExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool MemberExpr::is_implicit_access(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

NonOdrUseReason MemberExpr::is_non_odr_use(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<NonOdrUseReason>(self.getVal93());
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MatrixSubscriptExpr> MatrixSubscriptExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MATRIX_SUBSCRIPT_EXPR:
      return reinterpret_cast<const MatrixSubscriptExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr MatrixSubscriptExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr MatrixSubscriptExpr::column_index(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token MatrixSubscriptExpr::r_bracket_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Expr MatrixSubscriptExpr::row_index(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool MatrixSubscriptExpr::is_incomplete(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MaterializeTemporaryExpr> MaterializeTemporaryExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MATERIALIZE_TEMPORARY_EXPR:
      return reinterpret_cast<const MaterializeTemporaryExpr &>(parent);
    default: return std::nullopt;
  }
}

ValueDecl MaterializeTemporaryExpr::extending_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return ValueDecl::from(fragment->DeclFor(fragment, id)).value();
}

LifetimeExtendedTemporaryDecl MaterializeTemporaryExpr::lifetime_extended_temporary_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return LifetimeExtendedTemporaryDecl::from(fragment->DeclFor(fragment, id)).value();
}

StorageDuration MaterializeTemporaryExpr::storage_duration(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<StorageDuration>(self.getVal93());
}

Expr MaterializeTemporaryExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool MaterializeTemporaryExpr::is_bound_to_lvalue_reference(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool MaterializeTemporaryExpr::is_usable_in_constant_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MSPropertySubscriptExpr> MSPropertySubscriptExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR:
      return reinterpret_cast<const MSPropertySubscriptExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr MSPropertySubscriptExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr MSPropertySubscriptExpr::index(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token MSPropertySubscriptExpr::r_bracket_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

std::optional<MSPropertyRefExpr> MSPropertyRefExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MSPropertyRefExpr> MSPropertyRefExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MSPropertyRefExpr> MSPropertyRefExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<MSPropertyRefExpr> MSPropertyRefExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MS_PROPERTY_REF_EXPR:
      return reinterpret_cast<const MSPropertyRefExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr MSPropertyRefExpr::base_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token MSPropertyRefExpr::member_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

MSPropertyDecl MSPropertyRefExpr::property_declaration(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal37());
  return MSPropertyDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool MSPropertyRefExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool MSPropertyRefExpr::is_implicit_access(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<LambdaExpr> LambdaExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<LambdaExpr> LambdaExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<LambdaExpr> LambdaExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<LambdaExpr> LambdaExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::LAMBDA_EXPR:
      return reinterpret_cast<const LambdaExpr &>(parent);
    default: return std::nullopt;
  }
}

Stmt LambdaExpr::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Stmt(fragment->StmtFor(fragment, id));
}

CXXMethodDecl LambdaExpr::call_operator(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return CXXMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

LambdaCaptureDefault LambdaExpr::capture_default(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<LambdaCaptureDefault>(self.getVal93());
}

Token LambdaExpr::capture_default_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

CompoundStmt LambdaExpr::compound_statement_body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal38());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

std::vector<NamedDecl> LambdaExpr::explicit_template_parameters(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<NamedDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = NamedDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

TokenRange LambdaExpr::introducer_range(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenRangeFor(fragment, self.getVal39(), self.getVal40());
}

CXXRecordDecl LambdaExpr::lambda_class(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal41());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<TemplateParameterList> LambdaExpr::template_parameter_list(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal88()) {
    return std::nullopt;
  } else {
    return TemplateParameterList(fragment, self.getVal105());
  }
}

std::optional<Expr> LambdaExpr::trailing_requires_clause(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal89()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal42());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

bool LambdaExpr::has_explicit_parameters(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal90();
}

bool LambdaExpr::has_explicit_result_type(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal91();
}

bool LambdaExpr::is_generic_lambda(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool LambdaExpr::is_mutable(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

std::optional<IntegerLiteral> IntegerLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<IntegerLiteral> IntegerLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<IntegerLiteral> IntegerLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<IntegerLiteral> IntegerLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::INTEGER_LITERAL:
      return reinterpret_cast<const IntegerLiteral &>(parent);
    default: return std::nullopt;
  }
}

Token IntegerLiteral::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

std::optional<InitListExpr> InitListExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<InitListExpr> InitListExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<InitListExpr> InitListExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<InitListExpr> InitListExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::INIT_LIST_EXPR:
      return reinterpret_cast<const InitListExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<Expr> InitListExpr::array_filler(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal88()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal35());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<FieldDecl> InitListExpr::initialized_field_in_union(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal89()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal36());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token InitListExpr::l_brace_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token InitListExpr::r_brace_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

std::optional<InitListExpr> InitListExpr::semantic_form(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal90()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal39());
    return InitListExpr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<InitListExpr> InitListExpr::syntactic_form(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal91()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal40());
    return InitListExpr::from(fragment->StmtFor(fragment, id));
  }
}

bool InitListExpr::had_array_range_designator(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal92();
}

bool InitListExpr::has_array_filler(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal94();
}

std::vector<Expr> InitListExpr::initializers(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

bool InitListExpr::is_explicit(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal97();
}

bool InitListExpr::is_semantic_form(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal98();
}

bool InitListExpr::is_string_literal_initializer(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal99();
}

bool InitListExpr::is_syntactic_form(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal100();
}

bool InitListExpr::is_transparent(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal101();
}

std::optional<ImplicitValueInitExpr> ImplicitValueInitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ImplicitValueInitExpr> ImplicitValueInitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ImplicitValueInitExpr> ImplicitValueInitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ImplicitValueInitExpr> ImplicitValueInitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::IMPLICIT_VALUE_INIT_EXPR:
      return reinterpret_cast<const ImplicitValueInitExpr &>(parent);
    default: return std::nullopt;
  }
}

std::optional<ImaginaryLiteral> ImaginaryLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ImaginaryLiteral> ImaginaryLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ImaginaryLiteral> ImaginaryLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ImaginaryLiteral> ImaginaryLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::IMAGINARY_LITERAL:
      return reinterpret_cast<const ImaginaryLiteral &>(parent);
    default: return std::nullopt;
  }
}

Expr ImaginaryLiteral::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<GenericSelectionExpr> GenericSelectionExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::GENERIC_SELECTION_EXPR:
      return reinterpret_cast<const GenericSelectionExpr &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> GenericSelectionExpr::association_expressions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

Expr GenericSelectionExpr::controlling_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token GenericSelectionExpr::default_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

Token GenericSelectionExpr::generic_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal37());
}

Token GenericSelectionExpr::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal38());
}

Expr GenericSelectionExpr::result_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal39());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool GenericSelectionExpr::is_result_dependent(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<GNUNullExpr> GNUNullExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<GNUNullExpr> GNUNullExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<GNUNullExpr> GNUNullExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<GNUNullExpr> GNUNullExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::GNU_NULL_EXPR:
      return reinterpret_cast<const GNUNullExpr &>(parent);
    default: return std::nullopt;
  }
}

Token GNUNullExpr::token_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FunctionParmPackExpr> FunctionParmPackExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::FUNCTION_PARM_PACK_EXPR:
      return reinterpret_cast<const FunctionParmPackExpr &>(parent);
    default: return std::nullopt;
  }
}

VarDecl FunctionParmPackExpr::parameter_pack(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return VarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token FunctionParmPackExpr::parameter_pack_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal36());
}

std::vector<VarDecl> FunctionParmPackExpr::expansions(void) const {
  auto self = fragment->NthStmt(offset);
  auto list = self.getVal15();
  std::vector<VarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = VarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<FullExpr> FullExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FullExpr> FullExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FullExpr> FullExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FullExpr> FullExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::EXPR_WITH_CLEANUPS:
    case mx::StmtKind::CONSTANT_EXPR:
      return reinterpret_cast<const FullExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr FullExpr::sub_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ExprWithCleanups> ExprWithCleanups::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ExprWithCleanups> ExprWithCleanups::from(const FullExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExprWithCleanups> ExprWithCleanups::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExprWithCleanups> ExprWithCleanups::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExprWithCleanups> ExprWithCleanups::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::EXPR_WITH_CLEANUPS:
      return reinterpret_cast<const ExprWithCleanups &>(parent);
    default: return std::nullopt;
  }
}

bool ExprWithCleanups::cleanups_have_side_effects(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<ConstantExpr> ConstantExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ConstantExpr> ConstantExpr::from(const FullExpr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConstantExpr> ConstantExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConstantExpr> ConstantExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ConstantExpr> ConstantExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CONSTANT_EXPR:
      return reinterpret_cast<const ConstantExpr &>(parent);
    default: return std::nullopt;
  }
}

ConstantExprResultStorageKind ConstantExpr::result_storage_kind(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ConstantExprResultStorageKind>(self.getVal93());
}

bool ConstantExpr::has_ap_value_result(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

bool ConstantExpr::is_immediate_invocation(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<FloatingLiteral> FloatingLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FloatingLiteral> FloatingLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FloatingLiteral> FloatingLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FloatingLiteral> FloatingLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::FLOATING_LITERAL:
      return reinterpret_cast<const FloatingLiteral &>(parent);
    default: return std::nullopt;
  }
}

Token FloatingLiteral::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

bool FloatingLiteral::is_exact(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<FixedPointLiteral> FixedPointLiteral::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FixedPointLiteral> FixedPointLiteral::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FixedPointLiteral> FixedPointLiteral::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<FixedPointLiteral> FixedPointLiteral::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::FIXED_POINT_LITERAL:
      return reinterpret_cast<const FixedPointLiteral &>(parent);
    default: return std::nullopt;
  }
}

Token FixedPointLiteral::token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

std::optional<ExtVectorElementExpr> ExtVectorElementExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ExtVectorElementExpr> ExtVectorElementExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExtVectorElementExpr> ExtVectorElementExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExtVectorElementExpr> ExtVectorElementExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::EXT_VECTOR_ELEMENT_EXPR:
      return reinterpret_cast<const ExtVectorElementExpr &>(parent);
    default: return std::nullopt;
  }
}

bool ExtVectorElementExpr::contains_duplicate_elements(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

Token ExtVectorElementExpr::accessor_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal35());
}

Expr ExtVectorElementExpr::base(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal36());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool ExtVectorElementExpr::is_arrow(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal89();
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const Expr &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<ExpressionTraitExpr> ExpressionTraitExpr::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::EXPRESSION_TRAIT_EXPR:
      return reinterpret_cast<const ExpressionTraitExpr &>(parent);
    default: return std::nullopt;
  }
}

Expr ExpressionTraitExpr::queried_expression(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal35());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ExpressionTrait ExpressionTraitExpr::trait(void) const {
  auto self = fragment->NthStmt(offset);
  return static_cast<ExpressionTrait>(self.getVal93());
}

bool ExpressionTraitExpr::value(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal88();
}

std::optional<AttributedStmt> AttributedStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<AttributedStmt> AttributedStmt::from(const ValueStmt &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<AttributedStmt> AttributedStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::ATTRIBUTED_STMT:
      return reinterpret_cast<const AttributedStmt &>(parent);
    default: return std::nullopt;
  }
}

Token AttributedStmt::attribute_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

Stmt AttributedStmt::sub_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal10());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<SwitchStmt> SwitchStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SwitchStmt> SwitchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SWITCH_STMT:
      return reinterpret_cast<const SwitchStmt &>(parent);
    default: return std::nullopt;
  }
}

Stmt SwitchStmt::body(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal8());
  return Stmt(fragment->StmtFor(fragment, id));
}

Expr SwitchStmt::condition(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal9());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<VarDecl> SwitchStmt::condition_variable(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal10());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> SwitchStmt::condition_variable_declaration_statement(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal14()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal12());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<Stmt> SwitchStmt::initializer(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal19()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal13());
    return fragment->StmtFor(fragment, id);
  }
}

Token SwitchStmt::l_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal16());
}

Token SwitchStmt::r_paren_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal17());
}

std::optional<SwitchCase> SwitchStmt::first_switch_case(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal20()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal18());
    return SwitchCase::from(fragment->StmtFor(fragment, id));
  }
}

Token SwitchStmt::switch_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal25());
}

bool SwitchStmt::has_initializer_storage(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal55();
}

bool SwitchStmt::has_variable_storage(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal56();
}

bool SwitchStmt::is_all_enum_cases_covered(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal57();
}

std::optional<SwitchCase> SwitchCase::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<SwitchCase> SwitchCase::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DEFAULT_STMT:
    case mx::StmtKind::CASE_STMT:
      return reinterpret_cast<const SwitchCase &>(parent);
    default: return std::nullopt;
  }
}

Token SwitchCase::colon_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

Token SwitchCase::keyword_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<SwitchCase> SwitchCase::next_switch_case(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal11()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal10());
    return SwitchCase::from(fragment->StmtFor(fragment, id));
  }
}

Stmt SwitchCase::sub_statement(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal12());
  return Stmt(fragment->StmtFor(fragment, id));
}

std::optional<DefaultStmt> DefaultStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DefaultStmt> DefaultStmt::from(const SwitchCase &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<DefaultStmt> DefaultStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DEFAULT_STMT:
      return reinterpret_cast<const DefaultStmt &>(parent);
    default: return std::nullopt;
  }
}

Token DefaultStmt::default_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

std::optional<CaseStmt> CaseStmt::from(const TokenContext &c) {
  if (auto d = c.as_stmt()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CaseStmt> CaseStmt::from(const SwitchCase &parent) {
  return from(reinterpret_cast<const Stmt &>(parent));
}

std::optional<CaseStmt> CaseStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CASE_STMT:
      return reinterpret_cast<const CaseStmt &>(parent);
    default: return std::nullopt;
  }
}

bool CaseStmt::case_statement_is_gnu_range(void) const {
  auto self = fragment->NthStmt(offset);
  return self.getVal14();
}

Token CaseStmt::case_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal13());
}

Token CaseStmt::ellipsis_token(void) const {
  auto self = fragment->NthStmt(offset);
  return fragment->TokenFor(fragment, self.getVal16());
}

Expr CaseStmt::lhs(void) const {
  auto self = fragment->NthStmt(offset);
  EntityId id(self.getVal17());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<Expr> CaseStmt::rhs(void) const {
  auto self = fragment->NthStmt(offset);
  if (!self.getVal19()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal18());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

AccessSpecifier Decl::access(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<AccessSpecifier>(self.getVal0());
}

AccessSpecifier Decl::access_unsafe(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<AccessSpecifier>(self.getVal1());
}

AvailabilityResult Decl::availability(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<AvailabilityResult>(self.getVal2());
}

Token Decl::begin_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal3());
}

Token Decl::body_r_brace(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal4());
}

Decl Decl::canonical_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal5());
  return Decl(fragment->DeclFor(fragment, id));
}

std::optional<TemplateParameterList> Decl::described_template_parameters(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal7()) {
    return std::nullopt;
  } else {
    return TemplateParameterList(fragment, self.getVal6());
  }
}

Token Decl::end_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal8());
}

DeclFriendObjectKind Decl::friend_object_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<DeclFriendObjectKind>(self.getVal9());
}

DeclModuleOwnershipKind Decl::module_ownership_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<DeclModuleOwnershipKind>(self.getVal10());
}

Decl Decl::most_recent_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal11());
  return Decl(fragment->DeclFor(fragment, id));
}

std::optional<Decl> Decl::next_declaration_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal13()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal12());
    return fragment->DeclFor(fragment, id);
  }
}

std::optional<Decl> Decl::non_closure_context(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal15()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal14());
    return fragment->DeclFor(fragment, id);
  }
}

std::optional<Decl> Decl::previous_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal17()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal16());
    return fragment->DeclFor(fragment, id);
  }
}

bool Decl::has_attributes(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal18();
}

bool Decl::has_defining_attribute(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal19();
}

bool Decl::has_owning_module(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal20();
}

bool Decl::has_tag_identifier_namespace(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal21();
}

bool Decl::is_canonical_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal22();
}

bool Decl::is_defined_outside_function_or_method(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal23();
}

bool Decl::is_deprecated(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal24();
}

bool Decl::is_first_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal25();
}

bool Decl::is_function_or_function_template(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal26();
}

bool Decl::is_implicit(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal27();
}

bool Decl::is_in_anonymous_namespace(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal28();
}

bool Decl::is_in_local_scope_for_instantiation(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal29();
}

bool Decl::is_in_std_namespace(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal30();
}

bool Decl::is_invalid_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal31();
}

bool Decl::is_module_private(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal32();
}

bool Decl::is_out_of_line(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal33();
}

bool Decl::is_parameter_pack(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal34();
}

bool Decl::is_referenced(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal35();
}

bool Decl::is_template_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal36();
}

bool Decl::is_template_parameter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal37();
}

bool Decl::is_template_parameter_pack(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal38();
}

bool Decl::is_templated(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal39();
}

bool Decl::is_this_declaration_referenced(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal40();
}

bool Decl::is_top_level_declaration_in_obj_c_container(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal41();
}

bool Decl::is_unavailable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal42();
}

bool Decl::is_unconditionally_visible(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal43();
}

bool Decl::is_used(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal44();
}

bool Decl::is_weak_imported(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal45();
}

std::vector<Decl> Decl::redeclarations(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal46();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

DeclKind Decl::kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<DeclKind>(self.getVal47());
}

Token Decl::token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal48());
}

TokenRange Decl::token_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal49(), self.getVal50());
}

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION:
      return reinterpret_cast<const ClassScopeFunctionSpecializationDecl &>(parent);
    default: return std::nullopt;
  }
}

CXXMethodDecl ClassScopeFunctionSpecializationDecl::specialization(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return CXXMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool ClassScopeFunctionSpecializationDecl::has_explicit_template_arguments(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

std::optional<CapturedDecl> CapturedDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CapturedDecl> CapturedDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CAPTURED:
      return reinterpret_cast<const CapturedDecl &>(parent);
    default: return std::nullopt;
  }
}

ImplicitParamDecl CapturedDecl::context_parameter(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return ImplicitParamDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool CapturedDecl::is_nothrow(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

std::vector<ImplicitParamDecl> CapturedDecl::parameters(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<ImplicitParamDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ImplicitParamDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Decl> CapturedDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal54();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<BlockDecl> BlockDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BlockDecl> BlockDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::BLOCK:
      return reinterpret_cast<const BlockDecl &>(parent);
    default: return std::nullopt;
  }
}

bool BlockDecl::block_missing_return_type(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

bool BlockDecl::can_avoid_copy_to_heap(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal55();
}

bool BlockDecl::captures_cxx_this(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal56();
}

bool BlockDecl::does_not_escape(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal57();
}

Decl BlockDecl::block_mangling_context_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return Decl(fragment->DeclFor(fragment, id));
}

Token BlockDecl::caret_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

CompoundStmt BlockDecl::compound_body(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return CompoundStmt::from(fragment->StmtFor(fragment, id)).value();
}

bool BlockDecl::has_captures(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal60();
}

bool BlockDecl::is_conversion_from_lambda(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal61();
}

bool BlockDecl::is_variadic(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal62();
}

std::vector<ParmVarDecl> BlockDecl::parameters(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<ParmVarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ParmVarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ParmVarDecl> BlockDecl::parameter_declarations(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal54();
  std::vector<ParmVarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ParmVarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Decl> BlockDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal63();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<AccessSpecDecl> AccessSpecDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<AccessSpecDecl> AccessSpecDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::ACCESS_SPEC:
      return reinterpret_cast<const AccessSpecDecl &>(parent);
    default: return std::nullopt;
  }
}

Token AccessSpecDecl::access_specifier_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal51());
}

Token AccessSpecDecl::colon_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDeclarativeDirectiveDecl> OMPDeclarativeDirectiveDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_THREAD_PRIVATE:
    case mx::DeclKind::OMP_REQUIRES:
    case mx::DeclKind::OMP_ALLOCATE:
      return reinterpret_cast<const OMPDeclarativeDirectiveDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const OMPDeclarativeDirectiveDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPThreadPrivateDecl> OMPThreadPrivateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_THREAD_PRIVATE:
      return reinterpret_cast<const OMPThreadPrivateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> OMPThreadPrivateDecl::varlists(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const OMPDeclarativeDirectiveDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPRequiresDecl> OMPRequiresDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_REQUIRES:
      return reinterpret_cast<const OMPRequiresDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPAllocateDecl> OMPAllocateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPAllocateDecl> OMPAllocateDecl::from(const OMPDeclarativeDirectiveDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPAllocateDecl> OMPAllocateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_ALLOCATE:
      return reinterpret_cast<const OMPAllocateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Expr> OMPAllocateDecl::varlists(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Expr> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = Expr::from(fragment->StmtFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<TranslationUnitDecl> TranslationUnitDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TranslationUnitDecl> TranslationUnitDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TRANSLATION_UNIT:
      return reinterpret_cast<const TranslationUnitDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Decl> TranslationUnitDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<StaticAssertDecl> StaticAssertDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<StaticAssertDecl> StaticAssertDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::STATIC_ASSERT:
      return reinterpret_cast<const StaticAssertDecl &>(parent);
    default: return std::nullopt;
  }
}

Expr StaticAssertDecl::assert_expression(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

StringLiteral StaticAssertDecl::message(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return StringLiteral::from(fragment->StmtFor(fragment, id)).value();
}

Token StaticAssertDecl::r_paren_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

bool StaticAssertDecl::is_failed(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

std::optional<RequiresExprBodyDecl> RequiresExprBodyDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<RequiresExprBodyDecl> RequiresExprBodyDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::REQUIRES_EXPR_BODY:
      return reinterpret_cast<const RequiresExprBodyDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Decl> RequiresExprBodyDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<PragmaDetectMismatchDecl> PragmaDetectMismatchDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<PragmaDetectMismatchDecl> PragmaDetectMismatchDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::PRAGMA_DETECT_MISMATCH:
      return reinterpret_cast<const PragmaDetectMismatchDecl &>(parent);
    default: return std::nullopt;
  }
}

std::string_view PragmaDetectMismatchDecl::name(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal64();
  return std::string_view(data.cStr(), data.size());
}

std::string_view PragmaDetectMismatchDecl::value(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal65();
  return std::string_view(data.cStr(), data.size());
}

std::optional<PragmaCommentDecl> PragmaCommentDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<PragmaCommentDecl> PragmaCommentDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::PRAGMA_COMMENT:
      return reinterpret_cast<const PragmaCommentDecl &>(parent);
    default: return std::nullopt;
  }
}

std::string_view PragmaCommentDecl::argument(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal64();
  return std::string_view(data.cStr(), data.size());
}

PragmaMSCommentKind PragmaCommentDecl::comment_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<PragmaMSCommentKind>(self.getVal66());
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_PROPERTY_IMPL:
      return reinterpret_cast<const ObjCPropertyImplDecl &>(parent);
    default: return std::nullopt;
  }
}

Expr ObjCPropertyImplDecl::getter_cxx_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ObjCMethodDecl ObjCPropertyImplDecl::getter_method_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCPropertyDecl ObjCPropertyImplDecl::property_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return ObjCPropertyDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCPropertyImplDeclKind ObjCPropertyImplDecl::property_implementation(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCPropertyImplDeclKind>(self.getVal66());
}

ObjCIvarDecl ObjCPropertyImplDecl::property_instance_variable_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal67());
  return ObjCIvarDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCPropertyImplDecl::property_instance_variable_declaration_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal68());
}

Expr ObjCPropertyImplDecl::setter_cxx_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal69());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ObjCMethodDecl ObjCPropertyImplDecl::setter_method_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal70());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool ObjCPropertyImplDecl::is_instance_variable_name_specified(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

std::optional<NamedDecl> NamedDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<NamedDecl> NamedDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::NAMED:
    case mx::DeclKind::LABEL:
    case mx::DeclKind::BASE_USING:
    case mx::DeclKind::USING_ENUM:
    case mx::DeclKind::USING:
    case mx::DeclKind::VALUE:
    case mx::DeclKind::UNRESOLVED_USING_VALUE:
    case mx::DeclKind::TEMPLATE_PARAM_OBJECT:
    case mx::DeclKind::OMP_DECLARE_REDUCTION:
    case mx::DeclKind::MS_GUID:
    case mx::DeclKind::INDIRECT_FIELD:
    case mx::DeclKind::ENUM_CONSTANT:
    case mx::DeclKind::DECLARATOR:
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::NON_TYPE_TEMPLATE_PARM:
    case mx::DeclKind::MS_PROPERTY:
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
    case mx::DeclKind::FIELD:
    case mx::DeclKind::OBJ_C_IVAR:
    case mx::DeclKind::OBJ_C_AT_DEFS_FIELD:
    case mx::DeclKind::BINDING:
    case mx::DeclKind::OMP_DECLARE_MAPPER:
    case mx::DeclKind::USING_SHADOW:
    case mx::DeclKind::CONSTRUCTOR_USING_SHADOW:
    case mx::DeclKind::USING_PACK:
    case mx::DeclKind::USING_DIRECTIVE:
    case mx::DeclKind::UNRESOLVED_USING_IF_EXISTS:
    case mx::DeclKind::TYPE:
    case mx::DeclKind::TEMPLATE_TYPE_PARM:
    case mx::DeclKind::TAG:
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::ENUM:
    case mx::DeclKind::UNRESOLVED_USING_TYPENAME:
    case mx::DeclKind::TYPEDEF_NAME:
    case mx::DeclKind::TYPEDEF:
    case mx::DeclKind::TYPE_ALIAS:
    case mx::DeclKind::OBJ_C_TYPE_PARAM:
    case mx::DeclKind::TEMPLATE:
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
    case mx::DeclKind::CONCEPT:
    case mx::DeclKind::BUILTIN_TEMPLATE:
    case mx::DeclKind::TEMPLATE_TEMPLATE_PARM:
    case mx::DeclKind::OBJ_C_PROPERTY:
    case mx::DeclKind::OBJ_C_METHOD:
    case mx::DeclKind::OBJ_C_CONTAINER:
    case mx::DeclKind::OBJ_C_CATEGORY:
    case mx::DeclKind::OBJ_C_PROTOCOL:
    case mx::DeclKind::OBJ_C_INTERFACE:
    case mx::DeclKind::OBJ_C_IMPL:
    case mx::DeclKind::OBJ_C_CATEGORY_IMPL:
    case mx::DeclKind::OBJ_C_IMPLEMENTATION:
    case mx::DeclKind::OBJ_C_COMPATIBLE_ALIAS:
    case mx::DeclKind::NAMESPACE:
    case mx::DeclKind::NAMESPACE_ALIAS:
      return reinterpret_cast<const NamedDecl &>(parent);
    default: return std::nullopt;
  }
}

Linkage NamedDecl::formal_linkage(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<Linkage>(self.getVal66());
}

Linkage NamedDecl::linkage_internal(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<Linkage>(self.getVal71());
}

std::string_view NamedDecl::name(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal64();
  return std::string_view(data.cStr(), data.size());
}

ObjCStringFormatFamily NamedDecl::obj_cf_string_formatting_family(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCStringFormatFamily>(self.getVal72());
}

std::string_view NamedDecl::qualified_name_as_string(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal65();
  return std::string_view(data.cStr(), data.size());
}

NamedDecl NamedDecl::underlying_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

Visibility NamedDecl::visibility(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<Visibility>(self.getVal73());
}

bool NamedDecl::has_external_formal_linkage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

bool NamedDecl::has_linkage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal55();
}

bool NamedDecl::has_linkage_been_computed(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal56();
}

bool NamedDecl::is_cxx_class_member(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal57();
}

bool NamedDecl::is_cxx_instance_member(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal60();
}

bool NamedDecl::is_externally_declarable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal61();
}

bool NamedDecl::is_externally_visible(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal62();
}

bool NamedDecl::is_linkage_valid(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal74();
}

std::optional<LabelDecl> LabelDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<LabelDecl> LabelDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<LabelDecl> LabelDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::LABEL:
      return reinterpret_cast<const LabelDecl &>(parent);
    default: return std::nullopt;
  }
}

std::string_view LabelDecl::ms_assembly_label(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal75();
  return std::string_view(data.cStr(), data.size());
}

LabelStmt LabelDecl::statement(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return LabelStmt::from(fragment->StmtFor(fragment, id)).value();
}

bool LabelDecl::is_gnu_local(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

bool LabelDecl::is_ms_assembly_label(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool LabelDecl::is_resolved_ms_assembly_label(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

std::optional<BaseUsingDecl> BaseUsingDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BaseUsingDecl> BaseUsingDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<BaseUsingDecl> BaseUsingDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::BASE_USING:
    case mx::DeclKind::USING_ENUM:
    case mx::DeclKind::USING:
      return reinterpret_cast<const BaseUsingDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<UsingShadowDecl> BaseUsingDecl::shadows(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<UsingShadowDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = UsingShadowDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const BaseUsingDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UsingEnumDecl> UsingEnumDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::USING_ENUM:
      return reinterpret_cast<const UsingEnumDecl &>(parent);
    default: return std::nullopt;
  }
}

EnumDecl UsingEnumDecl::enum_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return EnumDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token UsingEnumDecl::enum_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

Token UsingEnumDecl::using_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal67());
}

std::optional<UsingDecl> UsingDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UsingDecl> UsingDecl::from(const BaseUsingDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UsingDecl> UsingDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UsingDecl> UsingDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::USING:
      return reinterpret_cast<const UsingDecl &>(parent);
    default: return std::nullopt;
  }
}

Token UsingDecl::using_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

bool UsingDecl::has_typename(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

bool UsingDecl::is_access_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

std::optional<ValueDecl> ValueDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ValueDecl> ValueDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ValueDecl> ValueDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::VALUE:
    case mx::DeclKind::UNRESOLVED_USING_VALUE:
    case mx::DeclKind::TEMPLATE_PARAM_OBJECT:
    case mx::DeclKind::OMP_DECLARE_REDUCTION:
    case mx::DeclKind::MS_GUID:
    case mx::DeclKind::INDIRECT_FIELD:
    case mx::DeclKind::ENUM_CONSTANT:
    case mx::DeclKind::DECLARATOR:
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::NON_TYPE_TEMPLATE_PARM:
    case mx::DeclKind::MS_PROPERTY:
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
    case mx::DeclKind::FIELD:
    case mx::DeclKind::OBJ_C_IVAR:
    case mx::DeclKind::OBJ_C_AT_DEFS_FIELD:
    case mx::DeclKind::BINDING:
    case mx::DeclKind::OMP_DECLARE_MAPPER:
      return reinterpret_cast<const ValueDecl &>(parent);
    default: return std::nullopt;
  }
}

bool ValueDecl::is_weak(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UnresolvedUsingValueDecl> UnresolvedUsingValueDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::UNRESOLVED_USING_VALUE:
      return reinterpret_cast<const UnresolvedUsingValueDecl &>(parent);
    default: return std::nullopt;
  }
}

Token UnresolvedUsingValueDecl::ellipsis_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

Token UnresolvedUsingValueDecl::using_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

bool UnresolvedUsingValueDecl::is_access_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool UnresolvedUsingValueDecl::is_pack_expansion(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

std::optional<TemplateParamObjectDecl> TemplateParamObjectDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateParamObjectDecl> TemplateParamObjectDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TemplateParamObjectDecl> TemplateParamObjectDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TemplateParamObjectDecl> TemplateParamObjectDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TEMPLATE_PARAM_OBJECT:
      return reinterpret_cast<const TemplateParamObjectDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPDeclareReductionDecl> OMPDeclareReductionDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_DECLARE_REDUCTION:
      return reinterpret_cast<const OMPDeclareReductionDecl &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPDeclareReductionDecl::combiner(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPDeclareReductionDecl::combiner_in(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPDeclareReductionDecl::combiner_out(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal67());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPDeclareReductionDecl::initializer_original(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal68());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPDeclareReductionDecl::initializer_private(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal69());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Expr OMPDeclareReductionDecl::initializer(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal70());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

OMPDeclareReductionDeclInitKind OMPDeclareReductionDecl::initializer_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<OMPDeclareReductionDeclInitKind>(self.getVal79());
}

OMPDeclareReductionDecl OMPDeclareReductionDecl::prev_declaration_in_scope(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal80());
  return OMPDeclareReductionDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::vector<Decl> OMPDeclareReductionDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<MSGuidDecl> MSGuidDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MSGuidDecl> MSGuidDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<MSGuidDecl> MSGuidDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<MSGuidDecl> MSGuidDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::MS_GUID:
      return reinterpret_cast<const MSGuidDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<IndirectFieldDecl> IndirectFieldDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<IndirectFieldDecl> IndirectFieldDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<IndirectFieldDecl> IndirectFieldDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<IndirectFieldDecl> IndirectFieldDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::INDIRECT_FIELD:
      return reinterpret_cast<const IndirectFieldDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<NamedDecl> IndirectFieldDecl::chain(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<NamedDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = NamedDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<FieldDecl> IndirectFieldDecl::anonymous_field(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal77()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal58());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<VarDecl> IndirectFieldDecl::variable_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal78()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal59());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<EnumConstantDecl> EnumConstantDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<EnumConstantDecl> EnumConstantDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<EnumConstantDecl> EnumConstantDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<EnumConstantDecl> EnumConstantDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::ENUM_CONSTANT:
      return reinterpret_cast<const EnumConstantDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<Expr> EnumConstantDecl::initializer_expression(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal77()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal58());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<DeclaratorDecl> DeclaratorDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DeclaratorDecl> DeclaratorDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<DeclaratorDecl> DeclaratorDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<DeclaratorDecl> DeclaratorDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::DECLARATOR:
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::NON_TYPE_TEMPLATE_PARM:
    case mx::DeclKind::MS_PROPERTY:
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
    case mx::DeclKind::FIELD:
    case mx::DeclKind::OBJ_C_IVAR:
    case mx::DeclKind::OBJ_C_AT_DEFS_FIELD:
      return reinterpret_cast<const DeclaratorDecl &>(parent);
    default: return std::nullopt;
  }
}

Token DeclaratorDecl::inner_token_start(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

Token DeclaratorDecl::outer_token_start(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

std::optional<Expr> DeclaratorDecl::trailing_requires_clause(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal77()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal67());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

Token DeclaratorDecl::type_spec_end_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal68());
}

Token DeclaratorDecl::type_spec_start_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal69());
}

std::vector<TemplateParameterList> DeclaratorDecl::template_parameter_lists(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal81();
  std::vector<TemplateParameterList> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::optional<VarDecl> VarDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<VarDecl> VarDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarDecl> VarDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarDecl> VarDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarDecl> VarDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::VAR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      return reinterpret_cast<const VarDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarDecl> VarDecl::acting_definition(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal78()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal70());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<Expr> VarDecl::initializer(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal80());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

VarDeclInitializationStyle VarDecl::initializer_style(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<VarDeclInitializationStyle>(self.getVal79());
}

std::optional<VarDecl> VarDecl::initializing_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal84()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal83());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<VarDecl> VarDecl::instantiated_from_static_data_member(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal86()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal85());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

LanguageLinkage VarDecl::language_linkage(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<LanguageLinkage>(self.getVal87());
}

Token VarDecl::point_of_instantiation(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal88());
}

StorageClass VarDecl::storage_class(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<StorageClass>(self.getVal89());
}

StorageDuration VarDecl::storage_duration(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<StorageDuration>(self.getVal90());
}

VarDeclTLSKind VarDecl::tls_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<VarDeclTLSKind>(self.getVal91());
}

ThreadStorageClassSpecifier VarDecl::tsc_spec(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ThreadStorageClassSpecifier>(self.getVal92());
}

std::optional<VarDecl> VarDecl::template_instantiation_pattern(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal94()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal93());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind VarDecl::template_specialization_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal95());
}

TemplateSpecializationKind VarDecl::template_specialization_kind_for_instantiation(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal96());
}

bool VarDecl::has_constant_initialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal97();
}

bool VarDecl::has_dependent_alignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal98();
}

bool VarDecl::has_external_storage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal99();
}

bool VarDecl::has_global_storage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal100();
}

bool VarDecl::has_initializer(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal101();
}

bool VarDecl::has_local_storage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal102();
}

bool VarDecl::is_arc_pseudo_strong(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal103();
}

bool VarDecl::is_cxx_for_range_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal104();
}

bool VarDecl::is_constexpr(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal105();
}

bool VarDecl::is_direct_initializer(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal106();
}

bool VarDecl::is_escaping_byref(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal107();
}

bool VarDecl::is_exception_variable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal108();
}

bool VarDecl::is_extern_c(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal109();
}

bool VarDecl::is_file_variable_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal110();
}

bool VarDecl::is_function_or_method_variable_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal111();
}

bool VarDecl::is_in_extern_c_context(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal112();
}

bool VarDecl::is_in_extern_cxx_context(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal113();
}

bool VarDecl::is_initializer_capture(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal114();
}

bool VarDecl::is_inline(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal115();
}

bool VarDecl::is_inline_specified(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal116();
}

bool VarDecl::is_known_to_be_defined(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal117();
}

bool VarDecl::is_local_variable_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal118();
}

bool VarDecl::is_local_variable_declaration_or_parm(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal119();
}

bool VarDecl::is_nrvo_variable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal120();
}

bool VarDecl::is_no_destroy(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal121();
}

bool VarDecl::is_non_escaping_byref(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal122();
}

bool VarDecl::is_obj_c_for_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal123();
}

bool VarDecl::is_previous_declaration_in_same_block_scope(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal124();
}

bool VarDecl::is_static_data_member(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal125();
}

bool VarDecl::is_static_local(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal126();
}

bool VarDecl::is_this_declaration_a_demoted_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal127();
}

bool VarDecl::is_usable_in_constant_expressions(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal128();
}

bool VarDecl::might_be_usable_in_constant_expressions(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal129();
}

QualTypeDestructionKind VarDecl::needs_destruction(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<QualTypeDestructionKind>(self.getVal130());
}

std::optional<ParmVarDecl> ParmVarDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ParmVarDecl> ParmVarDecl::from(const VarDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ParmVarDecl> ParmVarDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ParmVarDecl> ParmVarDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ParmVarDecl> ParmVarDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ParmVarDecl> ParmVarDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::PARM_VAR:
      return reinterpret_cast<const ParmVarDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<Expr> ParmVarDecl::default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal132()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal131());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

TokenRange ParmVarDecl::default_argument_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal133(), self.getVal134());
}

DeclObjCDeclQualifier ParmVarDecl::obj_c_decl_qualifier(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<DeclObjCDeclQualifier>(self.getVal135());
}

std::optional<Expr> ParmVarDecl::uninstantiated_default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal137()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal136());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

bool ParmVarDecl::has_default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal138();
}

bool ParmVarDecl::has_inherited_default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal139();
}

bool ParmVarDecl::has_uninstantiated_default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal140();
}

bool ParmVarDecl::has_unparsed_default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal141();
}

bool ParmVarDecl::is_destroyed_in_callee(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal142();
}

bool ParmVarDecl::is_knr_promoted(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal143();
}

bool ParmVarDecl::is_obj_c_method_parameter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal144();
}

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::from(const VarDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPCapturedExprDecl> OMPCapturedExprDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_CAPTURED_EXPR:
      return reinterpret_cast<const OMPCapturedExprDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const VarDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ImplicitParamDecl> ImplicitParamDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::IMPLICIT_PARAM:
      return reinterpret_cast<const ImplicitParamDecl &>(parent);
    default: return std::nullopt;
  }
}

ImplicitParamDeclImplicitParamKind ImplicitParamDecl::parameter_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ImplicitParamDeclImplicitParamKind>(self.getVal135());
}

std::optional<DecompositionDecl> DecompositionDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<DecompositionDecl> DecompositionDecl::from(const VarDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<DecompositionDecl> DecompositionDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<DecompositionDecl> DecompositionDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<DecompositionDecl> DecompositionDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<DecompositionDecl> DecompositionDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::DECOMPOSITION:
      return reinterpret_cast<const DecompositionDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<BindingDecl> DecompositionDecl::bindings(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<BindingDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = BindingDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const VarDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplateSpecializationDecl> VarTemplateSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      return reinterpret_cast<const VarTemplateSpecializationDecl &>(parent);
    default: return std::nullopt;
  }
}

Token VarTemplateSpecializationDecl::extern_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal131());
}

TemplateSpecializationKind VarTemplateSpecializationDecl::specialization_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal135());
}

std::vector<TemplateArgument> VarTemplateSpecializationDecl::template_arguments(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal145();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::vector<TemplateArgument> VarTemplateSpecializationDecl::template_instantiation_arguments(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal146();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

Token VarTemplateSpecializationDecl::template_keyword_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal133());
}

bool VarTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal132();
}

bool VarTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal137();
}

bool VarTemplateSpecializationDecl::is_explicit_specialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal138();
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const VarTemplateSpecializationDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const VarDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplatePartialSpecializationDecl> VarTemplatePartialSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      return reinterpret_cast<const VarTemplatePartialSpecializationDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<NonTypeTemplateParmDecl> NonTypeTemplateParmDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::NON_TYPE_TEMPLATE_PARM:
      return reinterpret_cast<const NonTypeTemplateParmDecl &>(parent);
    default: return std::nullopt;
  }
}

bool NonTypeTemplateParmDecl::default_argument_was_inherited(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

Expr NonTypeTemplateParmDecl::default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal70());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

Token NonTypeTemplateParmDecl::default_argument_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal80());
}

Expr NonTypeTemplateParmDecl::placeholder_type_constraint(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal83());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool NonTypeTemplateParmDecl::has_default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

bool NonTypeTemplateParmDecl::has_placeholder_type_constraint(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal84();
}

bool NonTypeTemplateParmDecl::is_expanded_parameter_pack(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal86();
}

bool NonTypeTemplateParmDecl::is_pack_expansion(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal94();
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<MSPropertyDecl> MSPropertyDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::MS_PROPERTY:
      return reinterpret_cast<const MSPropertyDecl &>(parent);
    default: return std::nullopt;
  }
}

bool MSPropertyDecl::has_getter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

bool MSPropertyDecl::has_setter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

std::optional<FunctionDecl> FunctionDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FunctionDecl> FunctionDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FunctionDecl> FunctionDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FunctionDecl> FunctionDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FunctionDecl> FunctionDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      return reinterpret_cast<const FunctionDecl &>(parent);
    default: return std::nullopt;
  }
}

bool FunctionDecl::does_this_declaration_have_a_body(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

ConstexprSpecKind FunctionDecl::constexpr_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ConstexprSpecKind>(self.getVal79());
}

std::optional<FunctionDecl> FunctionDecl::definition(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal70());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token FunctionDecl::ellipsis_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal80());
}

TokenRange FunctionDecl::exception_spec_source_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal83(), self.getVal85());
}

ExceptionSpecificationType FunctionDecl::exception_spec_type(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ExceptionSpecificationType>(self.getVal87());
}

std::optional<FunctionDecl> FunctionDecl::instantiated_from_member_function(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal84()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal88());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

LanguageLinkage FunctionDecl::language_linkage(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<LanguageLinkage>(self.getVal89());
}

MultiVersionKind FunctionDecl::multi_version_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<MultiVersionKind>(self.getVal90());
}

OverloadedOperatorKind FunctionDecl::overloaded_operator(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<OverloadedOperatorKind>(self.getVal91());
}

TokenRange FunctionDecl::parameters_source_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal93(), self.getVal131());
}

Token FunctionDecl::point_of_instantiation(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal133());
}

TokenRange FunctionDecl::return_type_source_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal134(), self.getVal136());
}

StorageClass FunctionDecl::storage_class(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<StorageClass>(self.getVal92());
}

std::optional<FunctionDecl> FunctionDecl::template_instantiation_pattern(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal86()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal147());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind FunctionDecl::template_specialization_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal95());
}

TemplateSpecializationKind FunctionDecl::template_specialization_kind_for_instantiation(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal96());
}

FunctionDeclTemplatedKind FunctionDecl::templated_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<FunctionDeclTemplatedKind>(self.getVal130());
}

bool FunctionDecl::has_implicit_return_zero(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal94();
}

bool FunctionDecl::has_inherited_prototype(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal97();
}

bool FunctionDecl::has_one_parameter_or_default_arguments(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal98();
}

bool FunctionDecl::has_prototype(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal99();
}

bool FunctionDecl::has_skipped_body(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal100();
}

bool FunctionDecl::has_trivial_body(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal101();
}

bool FunctionDecl::has_written_prototype(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal102();
}

bool FunctionDecl::instantiation_is_pending(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal103();
}

bool FunctionDecl::is_cpu_dispatch_multi_version(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal104();
}

bool FunctionDecl::is_cpu_specific_multi_version(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal105();
}

bool FunctionDecl::is_consteval(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal106();
}

bool FunctionDecl::is_constexpr(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal107();
}

bool FunctionDecl::is_constexpr_specified(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal108();
}

bool FunctionDecl::is_defaulted(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal109();
}

bool FunctionDecl::is_deleted(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal110();
}

bool FunctionDecl::is_deleted_as_written(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal111();
}

bool FunctionDecl::is_destroying_operator_delete(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal112();
}

bool FunctionDecl::is_explicitly_defaulted(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal113();
}

bool FunctionDecl::is_extern_c(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal114();
}

bool FunctionDecl::is_function_template_specialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal115();
}

bool FunctionDecl::is_global(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal116();
}

bool FunctionDecl::is_implicitly_instantiable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal117();
}

bool FunctionDecl::is_in_extern_c_context(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal118();
}

bool FunctionDecl::is_in_extern_cxx_context(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal119();
}

bool FunctionDecl::is_inline_builtin_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal120();
}

bool FunctionDecl::is_inline_specified(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal121();
}

bool FunctionDecl::is_inlined(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal122();
}

bool FunctionDecl::is_late_template_parsed(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal123();
}

bool FunctionDecl::is_msvcrt_entry_point(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal124();
}

bool FunctionDecl::is_main(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal125();
}

bool FunctionDecl::is_multi_version(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal126();
}

bool FunctionDecl::is_no_return(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal127();
}

bool FunctionDecl::is_overloaded_operator(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal128();
}

bool FunctionDecl::is_pure(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal129();
}

bool FunctionDecl::is_replaceable_global_allocation_function(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal132();
}

bool FunctionDecl::is_static(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal137();
}

bool FunctionDecl::is_target_multi_version(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal138();
}

bool FunctionDecl::is_template_instantiation(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal139();
}

bool FunctionDecl::is_this_declaration_a_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal140();
}

bool FunctionDecl::is_this_declaration_instantiated_from_a_friend_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal141();
}

bool FunctionDecl::is_trivial(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal142();
}

bool FunctionDecl::is_trivial_for_call(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal143();
}

bool FunctionDecl::is_user_provided(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal144();
}

bool FunctionDecl::is_variadic(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal148();
}

bool FunctionDecl::is_virtual_as_written(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal149();
}

std::vector<ParmVarDecl> FunctionDecl::parameters(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<ParmVarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ParmVarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

bool FunctionDecl::uses_seh_try(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal150();
}

bool FunctionDecl::will_have_body(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal151();
}

std::optional<Stmt> FunctionDecl::body(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal153()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal152());
    return fragment->StmtFor(fragment, id);
  }
}

std::vector<Decl> FunctionDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal54();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const FunctionDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXMethodDecl> CXXMethodDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
      return reinterpret_cast<const CXXMethodDecl &>(parent);
    default: return std::nullopt;
  }
}

CXXRecordDecl CXXMethodDecl::parent(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal154());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

RefQualifierKind CXXMethodDecl::reference_qualifier(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<RefQualifierKind>(self.getVal135());
}

bool CXXMethodDecl::has_inline_body(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal155();
}

bool CXXMethodDecl::is_const(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal156();
}

bool CXXMethodDecl::is_copy_assignment_operator(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal157();
}

bool CXXMethodDecl::is_instance(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal158();
}

bool CXXMethodDecl::is_lambda_static_invoker(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal159();
}

bool CXXMethodDecl::is_move_assignment_operator(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal160();
}

bool CXXMethodDecl::is_virtual(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal161();
}

bool CXXMethodDecl::is_volatile(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal162();
}

std::vector<CXXMethodDecl> CXXMethodDecl::overridden_methods(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal63();
  std::vector<CXXMethodDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = CXXMethodDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const CXXMethodDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const FunctionDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDestructorDecl> CXXDestructorDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CXX_DESTRUCTOR:
      return reinterpret_cast<const CXXDestructorDecl &>(parent);
    default: return std::nullopt;
  }
}

FunctionDecl CXXDestructorDecl::operator_delete(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal163());
  return FunctionDecl::from(fragment->DeclFor(fragment, id)).value();
}

Expr CXXDestructorDecl::operator_delete_this_argument(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal164());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const CXXMethodDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const FunctionDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConversionDecl> CXXConversionDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CXX_CONVERSION:
      return reinterpret_cast<const CXXConversionDecl &>(parent);
    default: return std::nullopt;
  }
}

bool CXXConversionDecl::is_explicit(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal165();
}

bool CXXConversionDecl::is_lambda_to_block_pointer_conversion(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal166();
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const CXXMethodDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const FunctionDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXConstructorDecl> CXXConstructorDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CXX_CONSTRUCTOR:
      return reinterpret_cast<const CXXConstructorDecl &>(parent);
    default: return std::nullopt;
  }
}

CXXConstructorDecl CXXConstructorDecl::target_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal163());
  return CXXConstructorDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool CXXConstructorDecl::is_default_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal165();
}

bool CXXConstructorDecl::is_delegating_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal166();
}

bool CXXConstructorDecl::is_explicit(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal167();
}

bool CXXConstructorDecl::is_inheriting_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal168();
}

bool CXXConstructorDecl::is_specialization_copying_object(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal169();
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const FunctionDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXDeductionGuideDecl> CXXDeductionGuideDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:
      return reinterpret_cast<const CXXDeductionGuideDecl &>(parent);
    default: return std::nullopt;
  }
}

CXXConstructorDecl CXXDeductionGuideDecl::corresponding_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal154());
  return CXXConstructorDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool CXXDeductionGuideDecl::is_copy_deduction_candidate(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal155();
}

bool CXXDeductionGuideDecl::is_explicit(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal156();
}

std::optional<FieldDecl> FieldDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FieldDecl> FieldDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FieldDecl> FieldDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FieldDecl> FieldDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FieldDecl> FieldDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FIELD:
    case mx::DeclKind::OBJ_C_IVAR:
    case mx::DeclKind::OBJ_C_AT_DEFS_FIELD:
      return reinterpret_cast<const FieldDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<Expr> FieldDecl::bit_width(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal78()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal70());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

InClassInitStyle FieldDecl::in_class_initializer_style(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<InClassInitStyle>(self.getVal79());
}

std::optional<Expr> FieldDecl::in_class_initializer(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal80());
    return Expr::from(fragment->StmtFor(fragment, id));
  }
}

RecordDecl FieldDecl::parent(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal83());
  return RecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool FieldDecl::has_captured_vla_type(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal84();
}

bool FieldDecl::has_in_class_initializer(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal86();
}

bool FieldDecl::is_anonymous_struct_or_union(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal94();
}

bool FieldDecl::is_bit_field(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal97();
}

bool FieldDecl::is_mutable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal98();
}

bool FieldDecl::is_unnamed_bitfield(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal99();
}

bool FieldDecl::is_zero_length_bit_field(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal100();
}

bool FieldDecl::is_zero_size(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal101();
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const FieldDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCIvarDecl> ObjCIvarDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_IVAR:
      return reinterpret_cast<const ObjCIvarDecl &>(parent);
    default: return std::nullopt;
  }
}

ObjCIvarDeclAccessControl ObjCIvarDecl::access_control(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCIvarDeclAccessControl>(self.getVal87());
}

ObjCIvarDeclAccessControl ObjCIvarDecl::canonical_access_control(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCIvarDeclAccessControl>(self.getVal89());
}

ObjCInterfaceDecl ObjCIvarDecl::containing_interface(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal85());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCIvarDecl ObjCIvarDecl::next_instance_variable(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal88());
  return ObjCIvarDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool ObjCIvarDecl::synthesize(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal102();
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const FieldDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const DeclaratorDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCAtDefsFieldDecl> ObjCAtDefsFieldDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_AT_DEFS_FIELD:
      return reinterpret_cast<const ObjCAtDefsFieldDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<BindingDecl> BindingDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BindingDecl> BindingDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<BindingDecl> BindingDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<BindingDecl> BindingDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::BINDING:
      return reinterpret_cast<const BindingDecl &>(parent);
    default: return std::nullopt;
  }
}

Expr BindingDecl::binding(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

ValueDecl BindingDecl::decomposed_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return ValueDecl::from(fragment->DeclFor(fragment, id)).value();
}

VarDecl BindingDecl::holding_variable(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal67());
  return VarDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPDeclarativeDirectiveValueDecl> OMPDeclarativeDirectiveValueDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_DECLARE_MAPPER:
      return reinterpret_cast<const OMPDeclarativeDirectiveValueDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const OMPDeclarativeDirectiveValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const ValueDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<OMPDeclareMapperDecl> OMPDeclareMapperDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OMP_DECLARE_MAPPER:
      return reinterpret_cast<const OMPDeclareMapperDecl &>(parent);
    default: return std::nullopt;
  }
}

Expr OMPDeclareMapperDecl::mapper_variable_reference(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

OMPDeclareMapperDecl OMPDeclareMapperDecl::prev_declaration_in_scope(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return OMPDeclareMapperDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::vector<Decl> OMPDeclareMapperDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<UsingShadowDecl> UsingShadowDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UsingShadowDecl> UsingShadowDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UsingShadowDecl> UsingShadowDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::USING_SHADOW:
    case mx::DeclKind::CONSTRUCTOR_USING_SHADOW:
      return reinterpret_cast<const UsingShadowDecl &>(parent);
    default: return std::nullopt;
  }
}

BaseUsingDecl UsingShadowDecl::introducer(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return BaseUsingDecl::from(fragment->DeclFor(fragment, id)).value();
}

UsingShadowDecl UsingShadowDecl::next_using_shadow_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return UsingShadowDecl::from(fragment->DeclFor(fragment, id)).value();
}

NamedDecl UsingShadowDecl::target_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal67());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::from(const UsingShadowDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CONSTRUCTOR_USING_SHADOW:
      return reinterpret_cast<const ConstructorUsingShadowDecl &>(parent);
    default: return std::nullopt;
  }
}

bool ConstructorUsingShadowDecl::constructs_virtual_base(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

CXXRecordDecl ConstructorUsingShadowDecl::constructed_base_class(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal68());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::constructed_base_class_shadow_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal77()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal69());
    return ConstructorUsingShadowDecl::from(fragment->DeclFor(fragment, id));
  }
}

CXXRecordDecl ConstructorUsingShadowDecl::nominated_base_class(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal70());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::nominated_base_class_shadow_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal78()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal80());
    return ConstructorUsingShadowDecl::from(fragment->DeclFor(fragment, id));
  }
}

CXXRecordDecl ConstructorUsingShadowDecl::parent(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal83());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<UsingPackDecl> UsingPackDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UsingPackDecl> UsingPackDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UsingPackDecl> UsingPackDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::USING_PACK:
      return reinterpret_cast<const UsingPackDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<NamedDecl> UsingPackDecl::expansions(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<NamedDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = NamedDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

NamedDecl UsingPackDecl::instantiated_from_using_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<UsingDirectiveDecl> UsingDirectiveDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UsingDirectiveDecl> UsingDirectiveDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UsingDirectiveDecl> UsingDirectiveDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::USING_DIRECTIVE:
      return reinterpret_cast<const UsingDirectiveDecl &>(parent);
    default: return std::nullopt;
  }
}

Token UsingDirectiveDecl::identifier_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

Token UsingDirectiveDecl::namespace_key_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

NamedDecl UsingDirectiveDecl::nominated_namespace_as_written(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal67());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token UsingDirectiveDecl::using_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal68());
}

std::optional<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UnresolvedUsingIfExistsDecl> UnresolvedUsingIfExistsDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::UNRESOLVED_USING_IF_EXISTS:
      return reinterpret_cast<const UnresolvedUsingIfExistsDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TypeDecl> TypeDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TypeDecl> TypeDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypeDecl> TypeDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TYPE:
    case mx::DeclKind::TEMPLATE_TYPE_PARM:
    case mx::DeclKind::TAG:
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::ENUM:
    case mx::DeclKind::UNRESOLVED_USING_TYPENAME:
    case mx::DeclKind::TYPEDEF_NAME:
    case mx::DeclKind::TYPEDEF:
    case mx::DeclKind::TYPE_ALIAS:
    case mx::DeclKind::OBJ_C_TYPE_PARAM:
      return reinterpret_cast<const TypeDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TemplateTypeParmDecl> TemplateTypeParmDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TEMPLATE_TYPE_PARM:
      return reinterpret_cast<const TemplateTypeParmDecl &>(parent);
    default: return std::nullopt;
  }
}

bool TemplateTypeParmDecl::default_argument_was_inherited(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

Token TemplateTypeParmDecl::default_argument_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

bool TemplateTypeParmDecl::has_default_argument(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool TemplateTypeParmDecl::has_type_constraint(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

bool TemplateTypeParmDecl::is_expanded_parameter_pack(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

bool TemplateTypeParmDecl::is_pack_expansion(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal84();
}

bool TemplateTypeParmDecl::was_declared_with_typename(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal86();
}

std::optional<TagDecl> TagDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TagDecl> TagDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TagDecl> TagDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TagDecl> TagDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TAG:
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
    case mx::DeclKind::ENUM:
      return reinterpret_cast<const TagDecl &>(parent);
    default: return std::nullopt;
  }
}

TokenRange TagDecl::brace_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal58(), self.getVal59());
}

std::optional<TagDecl> TagDecl::definition(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal76()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal67());
    return TagDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token TagDecl::inner_token_start(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal68());
}

Token TagDecl::outer_token_start(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal69());
}

TagTypeKind TagDecl::tag_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TagTypeKind>(self.getVal79());
}

std::optional<TypedefNameDecl> TagDecl::typedef_name_for_anonymous_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal77()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal70());
    return TypedefNameDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool TagDecl::has_name_for_linkage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

bool TagDecl::is_being_defined(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

bool TagDecl::is_class(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal84();
}

bool TagDecl::is_complete_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal86();
}

bool TagDecl::is_complete_definition_required(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal94();
}

bool TagDecl::is_dependent_type(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal97();
}

bool TagDecl::is_embedded_in_declarator(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal98();
}

bool TagDecl::is_enum(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal99();
}

bool TagDecl::is_free_standing(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal100();
}

bool TagDecl::is_interface(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal101();
}

bool TagDecl::is_struct(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal102();
}

bool TagDecl::is_this_declaration_a_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal103();
}

bool TagDecl::is_union(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal104();
}

bool TagDecl::may_have_out_of_date_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal105();
}

std::vector<TemplateParameterList> TagDecl::template_parameter_lists(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal81();
  std::vector<TemplateParameterList> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::vector<Decl> TagDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<RecordDecl> RecordDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<RecordDecl> RecordDecl::from(const TagDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<RecordDecl> RecordDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<RecordDecl> RecordDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<RecordDecl> RecordDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::RECORD:
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
      return reinterpret_cast<const RecordDecl &>(parent);
    default: return std::nullopt;
  }
}

bool RecordDecl::can_pass_in_registers(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal106();
}

std::vector<FieldDecl> RecordDecl::fields(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal54();
  std::vector<FieldDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = FieldDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<FieldDecl> RecordDecl::find_first_named_data_member(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal107()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal80());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

RecordDeclArgPassingKind RecordDecl::argument_passing_restrictions(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<RecordDeclArgPassingKind>(self.getVal87());
}

bool RecordDecl::has_flexible_array_member(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal108();
}

bool RecordDecl::has_loaded_fields_from_external_storage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal109();
}

bool RecordDecl::has_non_trivial_to_primitive_copy_c_union(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal110();
}

bool RecordDecl::has_non_trivial_to_primitive_default_initialize_c_union(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal111();
}

bool RecordDecl::has_non_trivial_to_primitive_destruct_c_union(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal112();
}

bool RecordDecl::has_object_member(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal113();
}

bool RecordDecl::has_volatile_member(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal114();
}

bool RecordDecl::is_anonymous_struct_or_union(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal115();
}

bool RecordDecl::is_captured_record(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal116();
}

bool RecordDecl::is_injected_class_name(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal117();
}

bool RecordDecl::is_lambda(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal118();
}

bool RecordDecl::is_ms_struct(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal119();
}

bool RecordDecl::is_non_trivial_to_primitive_copy(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal120();
}

bool RecordDecl::is_non_trivial_to_primitive_default_initialize(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal121();
}

bool RecordDecl::is_non_trivial_to_primitive_destroy(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal122();
}

bool RecordDecl::is_or_contains_union(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal123();
}

bool RecordDecl::is_parameter_destroyed_in_callee(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal124();
}

bool RecordDecl::may_insert_extra_padding(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal125();
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const RecordDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const TagDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<CXXRecordDecl> CXXRecordDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CXX_RECORD:
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
      return reinterpret_cast<const CXXRecordDecl &>(parent);
    default: return std::nullopt;
  }
}

bool CXXRecordDecl::allow_const_default_initializer(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal126();
}

std::vector<CXXBaseSpecifier> CXXRecordDecl::bases(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal145();
  std::vector<CXXBaseSpecifier> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

MSInheritanceModel CXXRecordDecl::calculate_inheritance_model(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<MSInheritanceModel>(self.getVal89());
}

std::vector<CXXConstructorDecl> CXXRecordDecl::constructors(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal63();
  std::vector<CXXConstructorDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = CXXConstructorDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

bool CXXRecordDecl::defaulted_copy_constructor_is_deleted(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal127();
}

bool CXXRecordDecl::defaulted_default_constructor_is_constexpr(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal128();
}

bool CXXRecordDecl::defaulted_destructor_is_constexpr(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal129();
}

bool CXXRecordDecl::defaulted_destructor_is_deleted(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal132();
}

bool CXXRecordDecl::defaulted_move_constructor_is_deleted(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal137();
}

std::vector<FriendDecl> CXXRecordDecl::friends(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal170();
  std::vector<FriendDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = FriendDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<CXXDestructorDecl> CXXRecordDecl::destructor(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal138()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal83());
    return CXXDestructorDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<TemplateParameterList> CXXRecordDecl::generic_lambda_template_parameter_list(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal139()) {
    return std::nullopt;
  } else {
    return TemplateParameterList(fragment, self.getVal171());
  }
}

std::optional<CXXRecordDecl> CXXRecordDecl::instantiated_from_member_class(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal140()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal85());
    return CXXRecordDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<CXXMethodDecl> CXXRecordDecl::lambda_call_operator(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal141()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal88());
    return CXXMethodDecl::from(fragment->DeclFor(fragment, id));
  }
}

LambdaCaptureDefault CXXRecordDecl::lambda_capture_default(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<LambdaCaptureDefault>(self.getVal90());
}

Decl CXXRecordDecl::lambda_context_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal93());
  return Decl(fragment->DeclFor(fragment, id));
}

std::vector<NamedDecl> CXXRecordDecl::lambda_explicit_template_parameters(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal172();
  std::vector<NamedDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = NamedDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

MSInheritanceModel CXXRecordDecl::ms_inheritance_model(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<MSInheritanceModel>(self.getVal91());
}

MSVtorDispMode CXXRecordDecl::ms_vtor_disp_mode(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<MSVtorDispMode>(self.getVal92());
}

CXXRecordDecl CXXRecordDecl::most_recent_non_injected_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal131());
  return CXXRecordDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<CXXRecordDecl> CXXRecordDecl::template_instantiation_pattern(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal142()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal133());
    return CXXRecordDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind CXXRecordDecl::template_specialization_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal95());
}

bool CXXRecordDecl::has_any_dependent_bases(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal143();
}

bool CXXRecordDecl::has_constexpr_default_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal144();
}

bool CXXRecordDecl::has_constexpr_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal148();
}

bool CXXRecordDecl::has_constexpr_non_copy_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal149();
}

bool CXXRecordDecl::has_copy_assignment_with_const_parameter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal150();
}

bool CXXRecordDecl::has_copy_constructor_with_const_parameter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal151();
}

bool CXXRecordDecl::has_default_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal153();
}

bool CXXRecordDecl::has_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal155();
}

bool CXXRecordDecl::has_direct_fields(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal156();
}

bool CXXRecordDecl::has_friends(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal157();
}

bool CXXRecordDecl::has_in_class_initializer(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal158();
}

bool CXXRecordDecl::has_inherited_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal159();
}

bool CXXRecordDecl::has_inherited_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal160();
}

bool CXXRecordDecl::has_irrelevant_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal161();
}

bool CXXRecordDecl::has_known_lambda_internal_linkage(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal162();
}

bool CXXRecordDecl::has_move_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal165();
}

bool CXXRecordDecl::has_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal166();
}

bool CXXRecordDecl::has_mutable_fields(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal167();
}

bool CXXRecordDecl::has_non_literal_type_fields_or_bases(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal168();
}

bool CXXRecordDecl::has_non_trivial_copy_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal169();
}

bool CXXRecordDecl::has_non_trivial_copy_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal173();
}

bool CXXRecordDecl::has_non_trivial_copy_constructor_for_call(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal174();
}

bool CXXRecordDecl::has_non_trivial_default_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal175();
}

bool CXXRecordDecl::has_non_trivial_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal176();
}

bool CXXRecordDecl::has_non_trivial_destructor_for_call(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal177();
}

bool CXXRecordDecl::has_non_trivial_move_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal178();
}

bool CXXRecordDecl::has_non_trivial_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal179();
}

bool CXXRecordDecl::has_non_trivial_move_constructor_for_call(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal180();
}

bool CXXRecordDecl::has_private_fields(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal181();
}

bool CXXRecordDecl::has_protected_fields(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal182();
}

bool CXXRecordDecl::has_simple_copy_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal183();
}

bool CXXRecordDecl::has_simple_copy_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal184();
}

bool CXXRecordDecl::has_simple_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal185();
}

bool CXXRecordDecl::has_simple_move_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal186();
}

bool CXXRecordDecl::has_simple_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal187();
}

bool CXXRecordDecl::has_trivial_copy_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal188();
}

bool CXXRecordDecl::has_trivial_copy_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal189();
}

bool CXXRecordDecl::has_trivial_copy_constructor_for_call(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal190();
}

bool CXXRecordDecl::has_trivial_default_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal191();
}

bool CXXRecordDecl::has_trivial_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal192();
}

bool CXXRecordDecl::has_trivial_destructor_for_call(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal193();
}

bool CXXRecordDecl::has_trivial_move_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal194();
}

bool CXXRecordDecl::has_trivial_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal195();
}

bool CXXRecordDecl::has_trivial_move_constructor_for_call(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal196();
}

bool CXXRecordDecl::has_uninitialized_reference_member(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal197();
}

bool CXXRecordDecl::has_user_declared_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal198();
}

bool CXXRecordDecl::has_user_declared_copy_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal199();
}

bool CXXRecordDecl::has_user_declared_copy_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal200();
}

bool CXXRecordDecl::has_user_declared_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal201();
}

bool CXXRecordDecl::has_user_declared_move_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal202();
}

bool CXXRecordDecl::has_user_declared_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal203();
}

bool CXXRecordDecl::has_user_declared_move_operation(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal204();
}

bool CXXRecordDecl::has_user_provided_default_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal205();
}

bool CXXRecordDecl::has_variant_members(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal206();
}

bool CXXRecordDecl::implicit_copy_assignment_has_const_parameter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal207();
}

bool CXXRecordDecl::implicit_copy_constructor_has_const_parameter(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal208();
}

bool CXXRecordDecl::is_abstract(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal209();
}

bool CXXRecordDecl::is_aggregate(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal210();
}

bool CXXRecordDecl::is_any_destructor_no_return(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal211();
}

bool CXXRecordDecl::is_c_like(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal212();
}

bool CXXRecordDecl::is_cxx11_standard_layout(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal213();
}

bool CXXRecordDecl::is_dependent_lambda(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal214();
}

bool CXXRecordDecl::is_dynamic_class(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal215();
}

bool CXXRecordDecl::is_effectively_final(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal216();
}

bool CXXRecordDecl::is_empty(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal217();
}

bool CXXRecordDecl::is_generic_lambda(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal218();
}

bool CXXRecordDecl::is_interface_like(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal219();
}

bool CXXRecordDecl::is_literal(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal220();
}

std::optional<FunctionDecl> CXXRecordDecl::is_local_class(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal221()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal134());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool CXXRecordDecl::is_pod(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal222();
}

bool CXXRecordDecl::is_parsing_base_specifiers(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal223();
}

bool CXXRecordDecl::is_polymorphic(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal224();
}

bool CXXRecordDecl::is_standard_layout(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal225();
}

bool CXXRecordDecl::is_structural(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal226();
}

bool CXXRecordDecl::is_trivial(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal227();
}

bool CXXRecordDecl::is_trivially_copyable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal228();
}

bool CXXRecordDecl::lambda_is_default_constructible_and_assignable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal229();
}

bool CXXRecordDecl::may_be_abstract(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal230();
}

bool CXXRecordDecl::may_be_dynamic_class(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal231();
}

bool CXXRecordDecl::may_be_non_dynamic_class(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal232();
}

std::vector<CXXMethodDecl> CXXRecordDecl::methods(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal233();
  std::vector<CXXMethodDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = CXXMethodDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

bool CXXRecordDecl::needs_implicit_copy_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal234();
}

bool CXXRecordDecl::needs_implicit_copy_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal235();
}

bool CXXRecordDecl::needs_implicit_default_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal236();
}

bool CXXRecordDecl::needs_implicit_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal237();
}

bool CXXRecordDecl::needs_implicit_move_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal238();
}

bool CXXRecordDecl::needs_implicit_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal239();
}

bool CXXRecordDecl::needs_overload_resolution_for_copy_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal240();
}

bool CXXRecordDecl::needs_overload_resolution_for_copy_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal241();
}

bool CXXRecordDecl::needs_overload_resolution_for_destructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal242();
}

bool CXXRecordDecl::needs_overload_resolution_for_move_assignment(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal243();
}

bool CXXRecordDecl::needs_overload_resolution_for_move_constructor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal244();
}

bool CXXRecordDecl::null_field_offset_is_zero(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal245();
}

std::vector<CXXBaseSpecifier> CXXRecordDecl::virtual_bases(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal146();
  std::vector<CXXBaseSpecifier> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const CXXRecordDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const RecordDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const TagDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateSpecializationDecl> ClassTemplateSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CLASS_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
      return reinterpret_cast<const ClassTemplateSpecializationDecl &>(parent);
    default: return std::nullopt;
  }
}

Token ClassTemplateSpecializationDecl::extern_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal136());
}

Token ClassTemplateSpecializationDecl::point_of_instantiation(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal147());
}

TemplateSpecializationKind ClassTemplateSpecializationDecl::specialization_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal96());
}

std::vector<TemplateArgument> ClassTemplateSpecializationDecl::template_arguments(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal246();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::vector<TemplateArgument> ClassTemplateSpecializationDecl::template_instantiation_arguments(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal247();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

Token ClassTemplateSpecializationDecl::template_keyword_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal152());
}

bool ClassTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal248();
}

bool ClassTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal249();
}

bool ClassTemplateSpecializationDecl::is_explicit_specialization(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal250();
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const ClassTemplateSpecializationDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const CXXRecordDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const RecordDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const TagDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplatePartialSpecializationDecl> ClassTemplatePartialSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
      return reinterpret_cast<const ClassTemplatePartialSpecializationDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<EnumDecl> EnumDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<EnumDecl> EnumDecl::from(const TagDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<EnumDecl> EnumDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<EnumDecl> EnumDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<EnumDecl> EnumDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::ENUM:
      return reinterpret_cast<const EnumDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<EnumConstantDecl> EnumDecl::enumerators(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal54();
  std::vector<EnumConstantDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = EnumConstantDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<EnumDecl> EnumDecl::instantiated_from_member_enum(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal106()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal80());
    return EnumDecl::from(fragment->DeclFor(fragment, id));
  }
}

TokenRange EnumDecl::integer_type_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal83(), self.getVal85());
}

std::optional<EnumDecl> EnumDecl::template_instantiation_pattern(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal107()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal88());
    return EnumDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind EnumDecl::template_specialization_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<TemplateSpecializationKind>(self.getVal87());
}

bool EnumDecl::is_closed(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal108();
}

bool EnumDecl::is_closed_flag(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal109();
}

bool EnumDecl::is_closed_non_flag(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal110();
}

bool EnumDecl::is_complete(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal111();
}

bool EnumDecl::is_fixed(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal112();
}

bool EnumDecl::is_scoped(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal113();
}

bool EnumDecl::is_scoped_using_class_tag(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal114();
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<UnresolvedUsingTypenameDecl> UnresolvedUsingTypenameDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::UNRESOLVED_USING_TYPENAME:
      return reinterpret_cast<const UnresolvedUsingTypenameDecl &>(parent);
    default: return std::nullopt;
  }
}

Token UnresolvedUsingTypenameDecl::ellipsis_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

Token UnresolvedUsingTypenameDecl::typename_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

Token UnresolvedUsingTypenameDecl::using_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal67());
}

bool UnresolvedUsingTypenameDecl::is_pack_expansion(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypedefNameDecl> TypedefNameDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TYPEDEF_NAME:
    case mx::DeclKind::TYPEDEF:
    case mx::DeclKind::TYPE_ALIAS:
    case mx::DeclKind::OBJ_C_TYPE_PARAM:
      return reinterpret_cast<const TypedefNameDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TagDecl> TypedefNameDecl::anonymous_declaration_with_typedef_name(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal76()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal58());
    return TagDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool TypedefNameDecl::is_moded(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool TypedefNameDecl::is_transparent_tag(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

std::optional<TypedefDecl> TypedefDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TypedefDecl> TypedefDecl::from(const TypedefNameDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypedefDecl> TypedefDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypedefDecl> TypedefDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypedefDecl> TypedefDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TYPEDEF:
      return reinterpret_cast<const TypedefDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const TypedefNameDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypeAliasDecl> TypeAliasDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TYPE_ALIAS:
      return reinterpret_cast<const TypeAliasDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TypeAliasTemplateDecl> TypeAliasDecl::described_alias_template(void) const {
  auto self = fragment->NthDecl(offset);
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal59());
    return TypeAliasTemplateDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const TypedefNameDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const TypeDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCTypeParamDecl> ObjCTypeParamDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_TYPE_PARAM:
      return reinterpret_cast<const ObjCTypeParamDecl &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCTypeParamDecl::colon_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

ObjCTypeParamVariance ObjCTypeParamDecl::variance(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCTypeParamVariance>(self.getVal79());
}

Token ObjCTypeParamDecl::variance_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal67());
}

bool ObjCTypeParamDecl::has_explicit_bound(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

std::optional<TemplateDecl> TemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateDecl> TemplateDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TemplateDecl> TemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TEMPLATE:
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
    case mx::DeclKind::CONCEPT:
    case mx::DeclKind::BUILTIN_TEMPLATE:
    case mx::DeclKind::TEMPLATE_TEMPLATE_PARM:
      return reinterpret_cast<const TemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<RedeclarableTemplateDecl> RedeclarableTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::REDECLARABLE_TEMPLATE:
    case mx::DeclKind::FUNCTION_TEMPLATE:
    case mx::DeclKind::CLASS_TEMPLATE:
    case mx::DeclKind::VAR_TEMPLATE:
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
      return reinterpret_cast<const RedeclarableTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const RedeclarableTemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<FunctionTemplateDecl> FunctionTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FUNCTION_TEMPLATE:
      return reinterpret_cast<const FunctionTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const RedeclarableTemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ClassTemplateDecl> ClassTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CLASS_TEMPLATE:
      return reinterpret_cast<const ClassTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarTemplateDecl> VarTemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<VarTemplateDecl> VarTemplateDecl::from(const RedeclarableTemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplateDecl> VarTemplateDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplateDecl> VarTemplateDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<VarTemplateDecl> VarTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::VAR_TEMPLATE:
      return reinterpret_cast<const VarTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const RedeclarableTemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TypeAliasTemplateDecl> TypeAliasTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TYPE_ALIAS_TEMPLATE:
      return reinterpret_cast<const TypeAliasTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<ConceptDecl> ConceptDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ConceptDecl> ConceptDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ConceptDecl> ConceptDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ConceptDecl> ConceptDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CONCEPT:
      return reinterpret_cast<const ConceptDecl &>(parent);
    default: return std::nullopt;
  }
}

Expr ConceptDecl::constraint_expression(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

bool ConceptDecl::is_type_concept(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<BuiltinTemplateDecl> BuiltinTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::BUILTIN_TEMPLATE:
      return reinterpret_cast<const BuiltinTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<TemplateTemplateParmDecl> TemplateTemplateParmDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<TemplateTemplateParmDecl> TemplateTemplateParmDecl::from(const TemplateDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TemplateTemplateParmDecl> TemplateTemplateParmDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<TemplateTemplateParmDecl> TemplateTemplateParmDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TEMPLATE_TEMPLATE_PARM:
      return reinterpret_cast<const TemplateTemplateParmDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCPropertyDecl> ObjCPropertyDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_PROPERTY:
      return reinterpret_cast<const ObjCPropertyDecl &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCPropertyDecl::at_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

ObjCMethodDecl ObjCPropertyDecl::getter_method_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCPropertyDecl::getter_name_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal67());
}

Token ObjCPropertyDecl::l_paren_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal68());
}

ObjCPropertyDeclPropertyControl ObjCPropertyDecl::property_implementation(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCPropertyDeclPropertyControl>(self.getVal79());
}

ObjCIvarDecl ObjCPropertyDecl::property_instance_variable_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal69());
  return ObjCIvarDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCPropertyQueryKind ObjCPropertyDecl::query_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCPropertyQueryKind>(self.getVal87());
}

ObjCPropertyDeclSetterKind ObjCPropertyDecl::setter_kind(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCPropertyDeclSetterKind>(self.getVal89());
}

ObjCMethodDecl ObjCPropertyDecl::setter_method_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal70());
  return ObjCMethodDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCPropertyDecl::setter_name_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal80());
}

bool ObjCPropertyDecl::is_atomic(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

bool ObjCPropertyDecl::is_class_property(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool ObjCPropertyDecl::is_direct_property(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

bool ObjCPropertyDecl::is_instance_property(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

bool ObjCPropertyDecl::is_optional(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal84();
}

bool ObjCPropertyDecl::is_read_only(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal86();
}

bool ObjCPropertyDecl::is_retaining(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal94();
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCMethodDecl> ObjCMethodDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_METHOD:
      return reinterpret_cast<const ObjCMethodDecl &>(parent);
    default: return std::nullopt;
  }
}

bool ObjCMethodDecl::defined_in_ns_object(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

ObjCPropertyDecl ObjCMethodDecl::find_property_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return ObjCPropertyDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCCategoryDecl ObjCMethodDecl::category(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return ObjCCategoryDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCInterfaceDecl ObjCMethodDecl::class_interface(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal67());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

ImplicitParamDecl ObjCMethodDecl::cmd_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal68());
  return ImplicitParamDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCMethodDecl::declarator_end_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal69());
}

ObjCMethodDeclImplementationControl ObjCMethodDecl::implementation_control(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCMethodDeclImplementationControl>(self.getVal79());
}

ObjCMethodFamily ObjCMethodDecl::method_family(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<ObjCMethodFamily>(self.getVal87());
}

DeclObjCDeclQualifier ObjCMethodDecl::obj_c_decl_qualifier(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<DeclObjCDeclQualifier>(self.getVal89());
}

TokenRange ObjCMethodDecl::return_type_source_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal70(), self.getVal80());
}

Token ObjCMethodDecl::selector_start_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal83());
}

ImplicitParamDecl ObjCMethodDecl::self_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal85());
  return ImplicitParamDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool ObjCMethodDecl::has_redeclaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool ObjCMethodDecl::has_related_result_type(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

bool ObjCMethodDecl::has_skipped_body(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

bool ObjCMethodDecl::is_class_method(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal84();
}

bool ObjCMethodDecl::is_defined(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal86();
}

bool ObjCMethodDecl::is_designated_initializer_for_the_interface(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal94();
}

bool ObjCMethodDecl::is_direct_method(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal97();
}

bool ObjCMethodDecl::is_instance_method(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal98();
}

bool ObjCMethodDecl::is_optional(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal99();
}

bool ObjCMethodDecl::is_overriding(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal100();
}

bool ObjCMethodDecl::is_property_accessor(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal101();
}

bool ObjCMethodDecl::is_redeclaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal102();
}

bool ObjCMethodDecl::is_synthesized_accessor_stub(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal103();
}

bool ObjCMethodDecl::is_this_declaration_a_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal104();
}

bool ObjCMethodDecl::is_this_declaration_a_designated_initializer(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal105();
}

bool ObjCMethodDecl::is_variadic(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal106();
}

std::vector<ParmVarDecl> ObjCMethodDecl::parameters(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<ParmVarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ParmVarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Token> ObjCMethodDecl::selector_tokens(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal54();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::vector<Decl> ObjCMethodDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal63();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCContainerDecl> ObjCContainerDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_CONTAINER:
    case mx::DeclKind::OBJ_C_CATEGORY:
    case mx::DeclKind::OBJ_C_PROTOCOL:
    case mx::DeclKind::OBJ_C_INTERFACE:
    case mx::DeclKind::OBJ_C_IMPL:
    case mx::DeclKind::OBJ_C_CATEGORY_IMPL:
    case mx::DeclKind::OBJ_C_IMPLEMENTATION:
      return reinterpret_cast<const ObjCContainerDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<ObjCMethodDecl> ObjCContainerDecl::class_methods(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<ObjCMethodDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCMethodDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCPropertyDecl> ObjCContainerDecl::class_properties(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal54();
  std::vector<ObjCPropertyDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCPropertyDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

TokenRange ObjCContainerDecl::at_end_range(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenRangeFor(fragment, self.getVal58(), self.getVal59());
}

Token ObjCContainerDecl::at_start_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal67());
}

std::vector<ObjCMethodDecl> ObjCContainerDecl::instance_methods(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal63();
  std::vector<ObjCMethodDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCMethodDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCPropertyDecl> ObjCContainerDecl::instance_properties(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal170();
  std::vector<ObjCPropertyDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCPropertyDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCMethodDecl> ObjCContainerDecl::methods(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal172();
  std::vector<ObjCMethodDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCMethodDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCPropertyDecl> ObjCContainerDecl::properties(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal233();
  std::vector<ObjCPropertyDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCPropertyDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Decl> ObjCContainerDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal251();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const ObjCContainerDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCCategoryDecl> ObjCCategoryDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_CATEGORY:
      return reinterpret_cast<const ObjCCategoryDecl &>(parent);
    default: return std::nullopt;
  }
}

bool ObjCCategoryDecl::is_class_extension(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

Token ObjCCategoryDecl::category_name_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal68());
}

ObjCInterfaceDecl ObjCCategoryDecl::class_interface(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal69());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCCategoryImplDecl ObjCCategoryDecl::implementation(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal70());
  return ObjCCategoryImplDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCCategoryDecl::instance_variable_l_brace_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal80());
}

Token ObjCCategoryDecl::instance_variable_r_brace_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal83());
}

ObjCCategoryDecl ObjCCategoryDecl::next_class_category(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal85());
  return ObjCCategoryDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCCategoryDecl ObjCCategoryDecl::next_class_category_raw(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal88());
  return ObjCCategoryDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::vector<ObjCIvarDecl> ObjCCategoryDecl::instance_variables(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal252();
  std::vector<ObjCIvarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCIvarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Token> ObjCCategoryDecl::protocol_tokens(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal253();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::vector<ObjCProtocolDecl> ObjCCategoryDecl::protocols(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal254();
  std::vector<ObjCProtocolDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCProtocolDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const ObjCContainerDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCProtocolDecl> ObjCProtocolDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_PROTOCOL:
      return reinterpret_cast<const ObjCProtocolDecl &>(parent);
    default: return std::nullopt;
  }
}

ObjCProtocolDecl ObjCProtocolDecl::definition(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal68());
  return ObjCProtocolDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::string_view ObjCProtocolDecl::obj_c_runtime_name_as_string(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal75();
  return std::string_view(data.cStr(), data.size());
}

bool ObjCProtocolDecl::has_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

bool ObjCProtocolDecl::is_non_runtime_protocol(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool ObjCProtocolDecl::is_this_declaration_a_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

std::vector<Token> ObjCProtocolDecl::protocol_tokens(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal252();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::vector<ObjCProtocolDecl> ObjCProtocolDecl::protocols(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal253();
  std::vector<ObjCProtocolDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCProtocolDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const ObjCContainerDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCInterfaceDecl> ObjCInterfaceDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_INTERFACE:
      return reinterpret_cast<const ObjCInterfaceDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<ObjCProtocolDecl> ObjCInterfaceDecl::all_referenced_protocols(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal252();
  std::vector<ObjCProtocolDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCProtocolDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

bool ObjCInterfaceDecl::declares_or_inherits_designated_initializers(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

ObjCCategoryDecl ObjCInterfaceDecl::category_list_raw(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal68());
  return ObjCCategoryDecl::from(fragment->DeclFor(fragment, id)).value();
}

ObjCInterfaceDecl ObjCInterfaceDecl::definition(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal69());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCInterfaceDecl::end_of_definition_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal70());
}

ObjCImplementationDecl ObjCInterfaceDecl::implementation(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal80());
  return ObjCImplementationDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::string_view ObjCInterfaceDecl::obj_c_runtime_name_as_string(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal75();
  return std::string_view(data.cStr(), data.size());
}

ObjCInterfaceDecl ObjCInterfaceDecl::super_class(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal83());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCInterfaceDecl::super_class_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal85());
}

bool ObjCInterfaceDecl::has_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

bool ObjCInterfaceDecl::has_designated_initializers(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal78();
}

bool ObjCInterfaceDecl::is_arc_weakref_unavailable(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal82();
}

bool ObjCInterfaceDecl::is_implicit_interface_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal84();
}

ObjCInterfaceDecl ObjCInterfaceDecl::is_obj_c_requires_property_definitions(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal88());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

bool ObjCInterfaceDecl::is_this_declaration_a_definition(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal86();
}

std::vector<ObjCIvarDecl> ObjCInterfaceDecl::instance_variables(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal253();
  std::vector<ObjCIvarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCIvarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::known_categories(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal254();
  std::vector<ObjCCategoryDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCCategoryDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::known_extensions(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal255();
  std::vector<ObjCCategoryDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCCategoryDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<Token> ObjCInterfaceDecl::protocol_tokens(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal256();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::vector<ObjCProtocolDecl> ObjCInterfaceDecl::protocols(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal257();
  std::vector<ObjCProtocolDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCProtocolDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::visible_categories(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal258();
  std::vector<ObjCCategoryDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCCategoryDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::visible_extensions(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal259();
  std::vector<ObjCCategoryDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCCategoryDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const ObjCContainerDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCImplDecl> ObjCImplDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_IMPL:
    case mx::DeclKind::OBJ_C_CATEGORY_IMPL:
    case mx::DeclKind::OBJ_C_IMPLEMENTATION:
      return reinterpret_cast<const ObjCImplDecl &>(parent);
    default: return std::nullopt;
  }
}

ObjCInterfaceDecl ObjCImplDecl::class_interface(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal68());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::vector<ObjCPropertyImplDecl> ObjCImplDecl::property_implementations(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal252();
  std::vector<ObjCPropertyImplDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCPropertyImplDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const ObjCImplDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const ObjCContainerDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCCategoryImplDecl> ObjCCategoryImplDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_CATEGORY_IMPL:
      return reinterpret_cast<const ObjCCategoryImplDecl &>(parent);
    default: return std::nullopt;
  }
}

ObjCCategoryDecl ObjCCategoryImplDecl::category_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal69());
  return ObjCCategoryDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCCategoryImplDecl::category_name_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal70());
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const ObjCImplDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const ObjCContainerDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCImplementationDecl> ObjCImplementationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_IMPLEMENTATION:
      return reinterpret_cast<const ObjCImplementationDecl &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCImplementationDecl::instance_variable_l_brace_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal69());
}

Token ObjCImplementationDecl::instance_variable_r_brace_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal70());
}

std::string_view ObjCImplementationDecl::obj_c_runtime_name_as_string(void) const {
  auto self = fragment->NthDecl(offset);
  capnp::Text::Reader data = self.getVal75();
  return std::string_view(data.cStr(), data.size());
}

ObjCInterfaceDecl ObjCImplementationDecl::super_class(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal80());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token ObjCImplementationDecl::super_class_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal83());
}

bool ObjCImplementationDecl::has_destructors(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal76();
}

bool ObjCImplementationDecl::has_non_zero_constructors(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal77();
}

std::vector<ObjCIvarDecl> ObjCImplementationDecl::instance_variables(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal253();
  std::vector<ObjCIvarDecl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    if (auto e = ObjCIvarDecl::from(fragment->DeclFor(fragment, id))) {
      vec.emplace_back(std::move(*e));
    }
  }
  return vec;
}

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<ObjCCompatibleAliasDecl> ObjCCompatibleAliasDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_COMPATIBLE_ALIAS:
      return reinterpret_cast<const ObjCCompatibleAliasDecl &>(parent);
    default: return std::nullopt;
  }
}

ObjCInterfaceDecl ObjCCompatibleAliasDecl::class_interface(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return ObjCInterfaceDecl::from(fragment->DeclFor(fragment, id)).value();
}

std::optional<NamespaceDecl> NamespaceDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<NamespaceDecl> NamespaceDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<NamespaceDecl> NamespaceDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::NAMESPACE:
      return reinterpret_cast<const NamespaceDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Decl> NamespaceDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::from(const NamedDecl &parent) {
  return from(reinterpret_cast<const Decl &>(parent));
}

std::optional<NamespaceAliasDecl> NamespaceAliasDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::NAMESPACE_ALIAS:
      return reinterpret_cast<const NamespaceAliasDecl &>(parent);
    default: return std::nullopt;
  }
}

Token NamespaceAliasDecl::alias_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

NamedDecl NamespaceAliasDecl::aliased_namespace(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal59());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token NamespaceAliasDecl::namespace_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal67());
}

Token NamespaceAliasDecl::target_name_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal68());
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::LINKAGE_SPEC:
      return reinterpret_cast<const LinkageSpecDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Decl> LinkageSpecDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::LIFETIME_EXTENDED_TEMPORARY:
      return reinterpret_cast<const LifetimeExtendedTemporaryDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Stmt> LifetimeExtendedTemporaryDecl::children_expression(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Stmt> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->StmtFor(fragment, id));
  }
  return vec;
}

ValueDecl LifetimeExtendedTemporaryDecl::extending_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return ValueDecl::from(fragment->DeclFor(fragment, id)).value();
}

StorageDuration LifetimeExtendedTemporaryDecl::storage_duration(void) const {
  auto self = fragment->NthDecl(offset);
  return static_cast<StorageDuration>(self.getVal66());
}

Expr LifetimeExtendedTemporaryDecl::temporary_expression(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return Expr::from(fragment->StmtFor(fragment, id)).value();
}

std::optional<ImportDecl> ImportDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ImportDecl> ImportDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::IMPORT:
      return reinterpret_cast<const ImportDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Token> ImportDecl::identifier_tokens(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FRIEND_TEMPLATE:
      return reinterpret_cast<const FriendTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<FriendDecl> FriendDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FriendDecl> FriendDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FRIEND:
      return reinterpret_cast<const FriendDecl &>(parent);
    default: return std::nullopt;
  }
}

NamedDecl FriendDecl::friend_declaration(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal51());
  return NamedDecl::from(fragment->DeclFor(fragment, id)).value();
}

Token FriendDecl::friend_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

bool FriendDecl::is_unsupported_friend(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

std::vector<TemplateParameterList> FriendDecl::friend_type_template_parameter_lists(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal81();
  std::vector<TemplateParameterList> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FILE_SCOPE_ASM:
      return reinterpret_cast<const FileScopeAsmDecl &>(parent);
    default: return std::nullopt;
  }
}

Token FileScopeAsmDecl::assembly_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal51());
}

StringLiteral FileScopeAsmDecl::assembly_string(void) const {
  auto self = fragment->NthDecl(offset);
  EntityId id(self.getVal58());
  return StringLiteral::from(fragment->StmtFor(fragment, id)).value();
}

Token FileScopeAsmDecl::r_paren_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal59());
}

std::optional<ExternCContextDecl> ExternCContextDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ExternCContextDecl> ExternCContextDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::EXTERN_C_CONTEXT:
      return reinterpret_cast<const ExternCContextDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Decl> ExternCContextDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<ExportDecl> ExportDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<ExportDecl> ExportDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::EXPORT:
      return reinterpret_cast<const ExportDecl &>(parent);
    default: return std::nullopt;
  }
}

Token ExportDecl::export_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal51());
}

Token ExportDecl::r_brace_token(void) const {
  auto self = fragment->NthDecl(offset);
  return fragment->TokenFor(fragment, self.getVal58());
}

bool ExportDecl::has_braces(void) const {
  auto self = fragment->NthDecl(offset);
  return self.getVal52();
}

std::vector<Decl> ExportDecl::declarations_in_context(void) const {
  auto self = fragment->NthDecl(offset);
  auto list = self.getVal53();
  std::vector<Decl> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->DeclFor(fragment, id));
  }
  return vec;
}

std::optional<EmptyDecl> EmptyDecl::from(const TokenContext &c) {
  if (auto d = c.as_decl()) {
    return from(*d);
  } else {
    return std::nullopt;
  }
}

std::optional<EmptyDecl> EmptyDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::EMPTY:
      return reinterpret_cast<const EmptyDecl &>(parent);
    default: return std::nullopt;
  }
}

#endif  // MX_DISABLE_API
}  // namespace mx
