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

ArrayTypeArraySizeModifier FromPasta(pasta::ArrayTypeArraySizeModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArrayTypeArraySizeModifier::NORMAL;
    case 1: return ArrayTypeArraySizeModifier::STATIC;
    case 2: return ArrayTypeArraySizeModifier::STAR;
    default: __builtin_unreachable();
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

CXXConstructExprConstructionKind FromPasta(pasta::CXXConstructExprConstructionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CXXConstructExprConstructionKind::COMPLETE;
    case 1: return CXXConstructExprConstructionKind::NON_VIRTUAL_BASE;
    case 2: return CXXConstructExprConstructionKind::VIRTUAL_BASE;
    case 3: return CXXConstructExprConstructionKind::DELEGATING;
    default: __builtin_unreachable();
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

CallExprADLCallKind FromPasta(pasta::CallExprADLCallKind e) {
  switch (static_cast<int>(e)) {
    case 0: return CallExprADLCallKind::NOT_ADL;
    case 1: return CallExprADLCallKind::USES_ADL;
    default: __builtin_unreachable();
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

ConstantExprResultStorageKind FromPasta(pasta::ConstantExprResultStorageKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConstantExprResultStorageKind::NONE;
    case 1: return ConstantExprResultStorageKind::INT64;
    case 2: return ConstantExprResultStorageKind::AP_VALUE;
    default: __builtin_unreachable();
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

DeclModuleOwnershipKind FromPasta(pasta::DeclModuleOwnershipKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DeclModuleOwnershipKind::UNOWNED;
    case 1: return DeclModuleOwnershipKind::VISIBLE;
    case 2: return DeclModuleOwnershipKind::VISIBLE_WHEN_IMPORTED;
    case 3: return DeclModuleOwnershipKind::MODULE_PRIVATE;
    default: __builtin_unreachable();
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

ExprConstantExprKind FromPasta(pasta::ExprConstantExprKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExprConstantExprKind::NORMAL;
    case 1: return ExprConstantExprKind::NON_CLASS_TEMPLATE_ARGUMENT;
    case 2: return ExprConstantExprKind::CLASS_TEMPLATE_ARGUMENT;
    case 3: return ExprConstantExprKind::IMMEDIATE_INVOCATION;
    default: __builtin_unreachable();
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

ExprNullPointerConstantValueDependence FromPasta(pasta::ExprNullPointerConstantValueDependence e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExprNullPointerConstantValueDependence::NEVER_VALUE_DEPENDENT;
    case 1: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NULL;
    case 2: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NOT_NULL;
    default: __builtin_unreachable();
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

ImplicitCastExprOnStack FromPasta(pasta::ImplicitCastExprOnStack e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ImplicitCastExprOnStack::ON_STACK;
    default: __builtin_unreachable();
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

LinkageSpecDeclLanguageIDs FromPasta(pasta::LinkageSpecDeclLanguageIDs e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return LinkageSpecDeclLanguageIDs::C;
    case 2: return LinkageSpecDeclLanguageIDs::CXX;
    default: __builtin_unreachable();
  }
}

NamedDeclExplicitVisibilityKind FromPasta(pasta::NamedDeclExplicitVisibilityKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_TYPE;
    case 1: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_VALUE;
    default: __builtin_unreachable();
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

ObjCMessageExprReceiverKind FromPasta(pasta::ObjCMessageExprReceiverKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCMessageExprReceiverKind::CLASS;
    case 1: return ObjCMessageExprReceiverKind::INSTANCE;
    case 2: return ObjCMessageExprReceiverKind::SUPER_CLASS;
    case 3: return ObjCMessageExprReceiverKind::SUPER_INSTANCE;
    default: __builtin_unreachable();
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

ObjCPropertyDeclPropertyControl FromPasta(pasta::ObjCPropertyDeclPropertyControl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyDeclPropertyControl::NONE;
    case 1: return ObjCPropertyDeclPropertyControl::REQUIRED;
    case 2: return ObjCPropertyDeclPropertyControl::OPTIONAL;
    default: __builtin_unreachable();
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

ObjCPropertyImplDeclKind FromPasta(pasta::ObjCPropertyImplDeclKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCPropertyImplDeclKind::SYNTHESIZE;
    case 1: return ObjCPropertyImplDeclKind::DYNAMIC;
    default: __builtin_unreachable();
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

QualTypePrimitiveDefaultInitializeKind FromPasta(pasta::QualTypePrimitiveDefaultInitializeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return QualTypePrimitiveDefaultInitializeKind::TRIVIAL;
    case 1: return QualTypePrimitiveDefaultInitializeKind::ARC_STRONG;
    case 2: return QualTypePrimitiveDefaultInitializeKind::ARC_WEAK;
    case 3: return QualTypePrimitiveDefaultInitializeKind::STRUCT;
    default: __builtin_unreachable();
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

SourceLocExprIdentKind FromPasta(pasta::SourceLocExprIdentKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SourceLocExprIdentKind::FUNCTION;
    case 1: return SourceLocExprIdentKind::FILE;
    case 2: return SourceLocExprIdentKind::LINE;
    case 3: return SourceLocExprIdentKind::COLUMN;
    default: __builtin_unreachable();
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

UnaryTransformTypeUTTKind FromPasta(pasta::UnaryTransformTypeUTTKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return UnaryTransformTypeUTTKind::ENUM_UNDERLYING_TYPE;
    default: __builtin_unreachable();
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

VarDeclDefinitionKind FromPasta(pasta::VarDeclDefinitionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclDefinitionKind::DECLARATION_ONLY;
    case 1: return VarDeclDefinitionKind::TENTATIVE_DEFINITION;
    case 2: return VarDeclDefinitionKind::DEFINITION;
    default: __builtin_unreachable();
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

VarDeclTLSKind FromPasta(pasta::VarDeclTLSKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return VarDeclTLSKind::NONE;
    case 1: return VarDeclTLSKind::STATIC;
    case 2: return VarDeclTLSKind::DYNAMIC;
    default: __builtin_unreachable();
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

ASTDumpOutputFormat FromPasta(pasta::ASTDumpOutputFormat e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ASTDumpOutputFormat::DEFAULT;
    case 1: return ASTDumpOutputFormat::JSON;
    default: __builtin_unreachable();
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

AddrSpaceMapMangling FromPasta(pasta::AddrSpaceMapMangling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return AddrSpaceMapMangling::TARGET;
    case 1: return AddrSpaceMapMangling::ON;
    case 2: return AddrSpaceMapMangling::OFF;
    default: __builtin_unreachable();
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

AltivecSrcCompatKind FromPasta(pasta::AltivecSrcCompatKind e) {
  switch (static_cast<int>(e)) {
    case 0: return AltivecSrcCompatKind::MIXED;
    case 1: return AltivecSrcCompatKind::GCC;
    case 2: return AltivecSrcCompatKind::XL;
    default: __builtin_unreachable();
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

ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ArrayTypeTrait::ARRAY_RANK;
    case 1: return ArrayTypeTrait::ARRAY_EXTENT;
    default: __builtin_unreachable();
  }
}

AtomicScopeModelKind FromPasta(pasta::AtomicScopeModelKind e) {
  switch (static_cast<int>(e)) {
    case 0: return AtomicScopeModelKind::NONE;
    case 1: return AtomicScopeModelKind::OPEN_CL;
    default: __builtin_unreachable();
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

AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword e) {
  switch (static_cast<int>(e)) {
    case 0: return AutoTypeKeyword::AUTO;
    case 1: return AutoTypeKeyword::DECLTYPE_AUTO;
    case 2: return AutoTypeKeyword::GNU_AUTO_TYPE;
    default: __builtin_unreachable();
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

BlockType FromPasta(pasta::BlockType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return BlockType::BY_REFERENCE;
    default: __builtin_unreachable();
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

CanThrowResult FromPasta(pasta::CanThrowResult e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return CanThrowResult::CANNOT;
    case 1: return CanThrowResult::DEPENDENT;
    case 2: return CanThrowResult::CAN;
    default: __builtin_unreachable();
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

ComparisonCategoryType FromPasta(pasta::ComparisonCategoryType e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ComparisonCategoryType::PARTIAL_ORDERING;
    case 1: return ComparisonCategoryType::WEAK_ORDERING;
    case 2: return ComparisonCategoryType::STRONG_ORDERING;
    default: __builtin_unreachable();
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

ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ConstexprSpecKind::UNSPECIFIED;
    case 1: return ConstexprSpecKind::CONSTEXPR;
    case 2: return ConstexprSpecKind::CONSTEVAL;
    case 3: return ConstexprSpecKind::CONSTINIT;
    default: __builtin_unreachable();
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

ConventionKind FromPasta(pasta::ConventionKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ConventionKind::NONE;
    case 1: return ConventionKind::NON_NULL_ERROR;
    case 2: return ConventionKind::ZERO_ARGUMENT;
    case 3: return ConventionKind::NON_ZERO_ARGUMENT;
    default: __builtin_unreachable();
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

DefaultArgKind FromPasta(pasta::DefaultArgKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DefaultArgKind::NONE;
    case 1: return DefaultArgKind::UNPARSED;
    case 2: return DefaultArgKind::UNINSTANTIATED;
    case 3: return DefaultArgKind::NORMAL;
    default: __builtin_unreachable();
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

DevTypeTy FromPasta(pasta::DevTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DevTypeTy::HOST;
    case 1: return DevTypeTy::NO_HOST;
    case 2: return DevTypeTy::ANY;
    default: __builtin_unreachable();
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

DiagnosticType FromPasta(pasta::DiagnosticType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return DiagnosticType::ERROR;
    case 1: return DiagnosticType::WARNING;
    default: __builtin_unreachable();
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

EmbedBitcodeKind FromPasta(pasta::EmbedBitcodeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return EmbedBitcodeKind::EMBED_OFF;
    case 1: return EmbedBitcodeKind::EMBED_ALL;
    case 2: return EmbedBitcodeKind::EMBED_BITCODE;
    case 3: return EmbedBitcodeKind::EMBED_MARKER;
    default: __builtin_unreachable();
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

ExplicitSpecKind FromPasta(pasta::ExplicitSpecKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExplicitSpecKind::RESOLVED_FALSE;
    case 1: return ExplicitSpecKind::RESOLVED_TRUE;
    case 2: return ExplicitSpecKind::UNRESOLVED;
    default: __builtin_unreachable();
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

ExprOffsets FromPasta(pasta::ExprOffsets e) {
  switch (static_cast<int>(e)) {
    case 0: return ExprOffsets::ALLOCATOR;
    case 1: return ExprOffsets::ALLOCATOR_TRAITS;
    case 2: return ExprOffsets::TOTAL;
    default: __builtin_unreachable();
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

ExpressionTrait FromPasta(pasta::ExpressionTrait e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ExpressionTrait::IS_L_VALUE_EXPRESSION;
    case 1: return ExpressionTrait::IS_R_VALUE_EXPRESSION;
    default: __builtin_unreachable();
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

ExtendArgsKind FromPasta(pasta::ExtendArgsKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ExtendArgsKind::EXTEND_TO32;
    case 1: return ExtendArgsKind::EXTEND_TO64;
    default: __builtin_unreachable();
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

FPModeKind FromPasta(pasta::FPModeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FPModeKind::OFF;
    case 1: return FPModeKind::ON;
    case 2: return FPModeKind::FAST;
    case 3: return FPModeKind::FAST_HONOR_PRAGMAS;
    default: __builtin_unreachable();
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

FiniteLoopsKind FromPasta(pasta::FiniteLoopsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return FiniteLoopsKind::LANGUAGE;
    case 1: return FiniteLoopsKind::ALWAYS;
    case 2: return FiniteLoopsKind::NEVER;
    default: __builtin_unreachable();
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

GC FromPasta(pasta::GC e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GC::GC_NONE;
    case 1: return GC::WEAK;
    case 2: return GC::STRONG;
    default: __builtin_unreachable();
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

GuardArg FromPasta(pasta::GuardArg e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return GuardArg::NOCF;
    default: __builtin_unreachable();
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

IdentifierInfoFlag FromPasta(pasta::IdentifierInfoFlag e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return IdentifierInfoFlag::ZERO_ARGUMENT;
    case 2: return IdentifierInfoFlag::ONE_ARGUMENT;
    case 7: return IdentifierInfoFlag::MULTI_ARGUMENT;
    default: __builtin_unreachable();
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

InClassInitStyle FromPasta(pasta::InClassInitStyle e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InClassInitStyle::NO_INITIALIZER;
    case 1: return InClassInitStyle::COPY_INITIALIZER;
    case 2: return InClassInitStyle::LIST_INITIALIZER;
    default: __builtin_unreachable();
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

InitStorageKind FromPasta(pasta::InitStorageKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InitStorageKind::NO_INITIALIZER;
    case 1: return InitStorageKind::IN_CLASS_COPY_INITIALIZER;
    case 2: return InitStorageKind::IN_CLASS_LIST_INITIALIZER;
    case 3: return InitStorageKind::CAPTURED_VLA_TYPE;
    default: __builtin_unreachable();
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

InliningMethod FromPasta(pasta::InliningMethod e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return InliningMethod::NORMAL_INLINING;
    case 1: return InliningMethod::ONLY_HINT_INLINING;
    case 2: return InliningMethod::ONLY_ALWAYS_INLINING;
    default: __builtin_unreachable();
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

LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LambdaCaptureDefault::NONE;
    case 1: return LambdaCaptureDefault::BY_COPY;
    case 2: return LambdaCaptureDefault::BY_REFERENCE;
    default: __builtin_unreachable();
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

LanguageLinkage FromPasta(pasta::LanguageLinkage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return LanguageLinkage::C_LANGUAGE_LINKAGE;
    case 1: return LanguageLinkage::CXX_LANGUAGE_LINKAGE;
    case 2: return LanguageLinkage::NO_LANGUAGE_LINKAGE;
    default: __builtin_unreachable();
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

MSInheritanceModel FromPasta(pasta::MSInheritanceModel e) {
  switch (static_cast<int>(e)) {
    case 0: return MSInheritanceModel::SINGLE;
    case 1: return MSInheritanceModel::MULTIPLE;
    case 2: return MSInheritanceModel::VIRTUAL;
    case 3: return MSInheritanceModel::UNSPECIFIED;
    default: __builtin_unreachable();
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

MSVtorDispMode FromPasta(pasta::MSVtorDispMode e) {
  switch (static_cast<int>(e)) {
    case 0: return MSVtorDispMode::NEVER;
    case 1: return MSVtorDispMode::FOR_VIRTUAL_BASE_OVERRIDE;
    case 2: return MSVtorDispMode::FOR_VF_TABLE;
    default: __builtin_unreachable();
  }
}

MapTypeTy FromPasta(pasta::MapTypeTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return MapTypeTy::TO;
    case 1: return MapTypeTy::LINK;
    default: __builtin_unreachable();
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

MultiVersionKind FromPasta(pasta::MultiVersionKind e) {
  switch (static_cast<int>(e)) {
    case 0: return MultiVersionKind::NONE;
    case 1: return MultiVersionKind::TARGET;
    case 2: return MultiVersionKind::CPU_SPECIFIC;
    case 3: return MultiVersionKind::CPU_DISPATCH;
    default: __builtin_unreachable();
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

NeedExtraManglingDecl FromPasta(pasta::NeedExtraManglingDecl e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NeedExtraManglingDecl::NEED_EXTRA_MANGLING_DECLARATION;
    default: __builtin_unreachable();
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

NewtypeKind FromPasta(pasta::NewtypeKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NewtypeKind::STRUCT;
    case 1: return NewtypeKind::ENUM;
    default: __builtin_unreachable();
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

NonceObjCInterface FromPasta(pasta::NonceObjCInterface e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return NonceObjCInterface::OBJ_C_INTERFACE;
    default: __builtin_unreachable();
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

ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ObjCBridgeCastKind::BRIDGE;
    case 1: return ObjCBridgeCastKind::BRIDGE_TRANSFER;
    case 2: return ObjCBridgeCastKind::BRIDGE_RETAINED;
    default: __builtin_unreachable();
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

ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ObjCPropertyQueryKind::QUERY_UNKNOWN;
    case 1: return ObjCPropertyQueryKind::QUERY_INSTANCE;
    case 2: return ObjCPropertyQueryKind::QUERY_CLASS;
    default: __builtin_unreachable();
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

ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance e) {
  switch (static_cast<unsigned char>(e)) {
    case 0: return ObjCTypeParamVariance::INVARIANT;
    case 1: return ObjCTypeParamVariance::COVARIANT;
    case 2: return ObjCTypeParamVariance::CONTRAVARIANT;
    default: __builtin_unreachable();
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

OnStackType FromPasta(pasta::OnStackType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OnStackType::ON_STACK;
    default: __builtin_unreachable();
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

OpenMPDefaultmapClauseKind FromPasta(pasta::OpenMPDefaultmapClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDefaultmapClauseKind::SCALAR;
    case 1: return OpenMPDefaultmapClauseKind::AGGREGATE;
    case 2: return OpenMPDefaultmapClauseKind::POINTER;
    case 3: return OpenMPDefaultmapClauseKind::UNKNOWN;
    default: __builtin_unreachable();
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

OpenMPDeviceClauseModifier FromPasta(pasta::OpenMPDeviceClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDeviceClauseModifier::ANCESTOR;
    case 1: return OpenMPDeviceClauseModifier::DEVICE_NUM;
    case 2: return OpenMPDeviceClauseModifier::UNKNOWN;
    default: __builtin_unreachable();
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

OpenMPDistScheduleClauseKind FromPasta(pasta::OpenMPDistScheduleClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPDistScheduleClauseKind::STATIC;
    case 1: return OpenMPDistScheduleClauseKind::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPLastprivateModifier FromPasta(pasta::OpenMPLastprivateModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPLastprivateModifier::CONDITIONAL;
    case 1: return OpenMPLastprivateModifier::UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPLinearClauseKind FromPasta(pasta::OpenMPLinearClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPLinearClauseKind::VAL;
    case 1: return OpenMPLinearClauseKind::REFERENCE;
    case 2: return OpenMPLinearClauseKind::UVAL;
    case 3: return OpenMPLinearClauseKind::UNKNOWN;
    default: __builtin_unreachable();
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

OpenMPMotionModifierKind FromPasta(pasta::OpenMPMotionModifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPMotionModifierKind::MOTIONMODIFIER_MAPPER;
    case 1: return OpenMPMotionModifierKind::MOTIONMODIFIER_PRESENT;
    case 2: return OpenMPMotionModifierKind::MOTIONMODIFIER_UNKNOWN;
    default: __builtin_unreachable();
  }
}

OpenMPOrderClauseKind FromPasta(pasta::OpenMPOrderClauseKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OpenMPOrderClauseKind::CONCURRENT;
    case 1: return OpenMPOrderClauseKind::UNKNOWN;
    default: __builtin_unreachable();
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

OpenMPScheduleClauseModifier FromPasta(pasta::OpenMPScheduleClauseModifier e) {
  switch (static_cast<unsigned>(e)) {
    case 5: return OpenMPScheduleClauseModifier::UNKNOWN;
    case 6: return OpenMPScheduleClauseModifier::MONOTONIC;
    case 7: return OpenMPScheduleClauseModifier::NONMONOTONIC;
    case 8: return OpenMPScheduleClauseModifier::SIMD;
    default: __builtin_unreachable();
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

OverloadsShown FromPasta(pasta::OverloadsShown e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return OverloadsShown::ALL;
    case 1: return OverloadsShown::BEST;
    default: __builtin_unreachable();
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

PCSType FromPasta(pasta::PCSType e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PCSType::AAPCS;
    case 1: return PCSType::VFP;
    default: __builtin_unreachable();
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

ParenLocsOffsets FromPasta(pasta::ParenLocsOffsets e) {
  switch (static_cast<int>(e)) {
    case 0: return ParenLocsOffsets::L_PAREN;
    case 1: return ParenLocsOffsets::R_PAREN;
    case 2: return ParenLocsOffsets::TOTAL;
    default: __builtin_unreachable();
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

PragmaMSPointersToMembersKind FromPasta(pasta::PragmaMSPointersToMembersKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSPointersToMembersKind::BEST_CASE;
    case 1: return PragmaMSPointersToMembersKind::FULL_GENERALITY_SINGLE_INHERITANCE;
    case 2: return PragmaMSPointersToMembersKind::FULL_GENERALITY_MULTIPLE_INHERITANCE;
    case 3: return PragmaMSPointersToMembersKind::FULL_GENERALITY_VIRTUAL_INHERITANCE;
    default: __builtin_unreachable();
  }
}

PragmaMSStructKind FromPasta(pasta::PragmaMSStructKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return PragmaMSStructKind::OFF;
    case 1: return PragmaMSStructKind::ON;
    default: __builtin_unreachable();
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

ProfileInstrKind FromPasta(pasta::ProfileInstrKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return ProfileInstrKind::PROFILE_NONE;
    case 1: return ProfileInstrKind::PROFILE_CLANG_INSTR;
    case 2: return ProfileInstrKind::PROFILE_IR_INSTR;
    case 3: return ProfileInstrKind::PROFILE_CSIR_INSTR;
    default: __builtin_unreachable();
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

RangeLocOffset FromPasta(pasta::RangeLocOffset e) {
  switch (static_cast<int>(e)) {
    case 0: return RangeLocOffset::ASSIGN_TOKEN;
    case 2: return RangeLocOffset::SECOND_COLON_TOKEN;
    case 3: return RangeLocOffset::TOTAL;
    default: __builtin_unreachable();
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

SFINAEResponse FromPasta(pasta::SFINAEResponse e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SFINAEResponse::SUBSTITUTION_FAILURE;
    case 1: return SFINAEResponse::SUPPRESS;
    case 2: return SFINAEResponse::REPORT;
    case 3: return SFINAEResponse::ACCESS_CONTROL;
    default: __builtin_unreachable();
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

SelectorLocationsKind FromPasta(pasta::SelectorLocationsKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SelectorLocationsKind::NON_STANDARD;
    case 1: return SelectorLocationsKind::STANDARD_NO_SPACE;
    case 2: return SelectorLocationsKind::STANDARD_WITH_SPACE;
    default: __builtin_unreachable();
  }
}

SignReturnAddressKeyKind FromPasta(pasta::SignReturnAddressKeyKind e) {
  switch (static_cast<int>(e)) {
    case 0: return SignReturnAddressKeyKind::A_KEY;
    case 1: return SignReturnAddressKeyKind::B_KEY;
    default: __builtin_unreachable();
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

SignedOverflowBehaviorTy FromPasta(pasta::SignedOverflowBehaviorTy e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SignedOverflowBehaviorTy::UNDEFINED;
    case 1: return SignedOverflowBehaviorTy::DEFINED;
    case 2: return SignedOverflowBehaviorTy::TRAPPING;
    default: __builtin_unreachable();
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

Spelling FromPasta(pasta::Spelling e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Spelling::GNU_AARCH64_VECTOR_PCS;
    case 1: return Spelling::CXX11_CLANG_AARCH64_VECTOR_PCS;
    case 2: return Spelling::C2_XCLANG_AARCH64_VECTOR_PCS;
    case 15: return Spelling::SPELLING_NOT_CALCULATED;
    default: __builtin_unreachable();
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

StoredSpecifierKind FromPasta(pasta::StoredSpecifierKind e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return StoredSpecifierKind::STORED_IDENTIFIER;
    case 1: return StoredSpecifierKind::STORED_DECLARATION;
    case 2: return StoredSpecifierKind::STORED_TYPE_SPEC;
    case 3: return StoredSpecifierKind::STORED_TYPE_SPEC_WITH_TEMPLATE;
    default: __builtin_unreachable();
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

SubExpr FromPasta(pasta::SubExpr e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return SubExpr::CALLEE;
    case 1: return SubExpr::LHS;
    case 2: return SubExpr::RHS;
    case 3: return SubExpr::COUNT;
    default: __builtin_unreachable();
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

SyncScope FromPasta(pasta::SyncScope e) {
  switch (static_cast<int>(e)) {
    case 0: return SyncScope::OPEN_CL_WORK_GROUP;
    case 1: return SyncScope::OPEN_CL_DEVICE;
    case 2: return SyncScope::OPEN_CL_ALL_SVM_DEVICES;
    case 3: return SyncScope::OPEN_CL_SUB_GROUP;
    default: __builtin_unreachable();
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

TLSModel FromPasta(pasta::TLSModel e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TLSModel::GENERAL_DYNAMIC_TLS_MODEL;
    case 1: return TLSModel::LOCAL_DYNAMIC_TLS_MODEL;
    case 2: return TLSModel::INITIAL_EXEC_TLS_MODEL;
    case 3: return TLSModel::LOCAL_EXEC_TLS_MODEL;
    default: __builtin_unreachable();
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

TailPaddingUseRules FromPasta(pasta::TailPaddingUseRules e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TailPaddingUseRules::ALWAYS_USE_TAIL_PADDING;
    case 1: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD03;
    case 2: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_POD11;
    default: __builtin_unreachable();
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

TextDiagnosticFormat FromPasta(pasta::TextDiagnosticFormat e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TextDiagnosticFormat::CLANG;
    case 1: return TextDiagnosticFormat::MSVC;
    case 2: return TextDiagnosticFormat::VI;
    default: __builtin_unreachable();
  }
}

ThreadModelKind FromPasta(pasta::ThreadModelKind e) {
  switch (static_cast<int>(e)) {
    case 0: return ThreadModelKind::POSIX;
    case 1: return ThreadModelKind::SINGLE;
    default: __builtin_unreachable();
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

TrailingAllocKind FromPasta(pasta::TrailingAllocKind e) {
  switch (static_cast<unsigned>(e)) {
    case 1: return TrailingAllocKind::TAK_INHERITS_CONSTRUCTOR;
    case 2: return TrailingAllocKind::TAK_HAS_TAIL_EXPLICIT;
    default: __builtin_unreachable();
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

TrivialAutoVarInitKind FromPasta(pasta::TrivialAutoVarInitKind e) {
  switch (static_cast<int>(e)) {
    case 0: return TrivialAutoVarInitKind::UNINITIALIZED;
    case 1: return TrivialAutoVarInitKind::ZERO;
    case 2: return TrivialAutoVarInitKind::PATTERN;
    default: __builtin_unreachable();
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

TypeSpecifierSign FromPasta(pasta::TypeSpecifierSign e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifierSign::UNSPECIFIED;
    case 1: return TypeSpecifierSign::SIGNED;
    case 2: return TypeSpecifierSign::UNSIGNED;
    default: __builtin_unreachable();
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

TypeSpecifierWidth FromPasta(pasta::TypeSpecifierWidth e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifierWidth::UNSPECIFIED;
    case 1: return TypeSpecifierWidth::SHORT;
    case 2: return TypeSpecifierWidth::LONG;
    case 3: return TypeSpecifierWidth::LONG_LONG;
    default: __builtin_unreachable();
  }
}

TypeSpecifiersPipe FromPasta(pasta::TypeSpecifiersPipe e) {
  switch (static_cast<int>(e)) {
    case 0: return TypeSpecifiersPipe::UNSPECIFIED;
    case 1: return TypeSpecifiersPipe::PIPE;
    default: __builtin_unreachable();
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

Visibility FromPasta(pasta::Visibility e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return Visibility::HIDDEN_VISIBILITY;
    case 1: return Visibility::PROTECTED_VISIBILITY;
    case 2: return Visibility::DEFAULT_VISIBILITY;
    default: __builtin_unreachable();
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

PathKind FromPasta(pasta::PathKind e) {
  switch (static_cast<signed char>(e)) {
    case 47: return PathKind::UNIX;
    case 92: return PathKind::WINDOWS;
    default: __builtin_unreachable();
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

IncludePathLocation FromPasta(pasta::IncludePathLocation e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return IncludePathLocation::ABSOLUTE;
    case 1: return IncludePathLocation::SYSROOT_RELATIVE;
    default: __builtin_unreachable();
  }
}

TargetLanguage FromPasta(pasta::TargetLanguage e) {
  switch (static_cast<unsigned>(e)) {
    case 0: return TargetLanguage::C;
    case 1: return TargetLanguage::CXX;
    default: __builtin_unreachable();
  }
}

#ifndef MX_DISABLE_API
unsigned TemplateParameterList::num_parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal0();
}

unsigned TemplateParameterList::num_required_parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal1();
}

unsigned TemplateParameterList::depth(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal2();
}

bool TemplateParameterList::has_unexpanded_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

bool TemplateParameterList::has_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
}

Token TemplateParameterList::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal5());
}

Token TemplateParameterList::left_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal6());
}

Token TemplateParameterList::right_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal7());
}

TokenRange TemplateParameterList::token_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal8(), self.getVal9());
}

std::vector<NamedDecl> TemplateParameterList::parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

TemplateArgumentKind TemplateArgument::kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateArgumentKind>(self.getVal11());
}

bool TemplateArgument::is_null(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

bool TemplateArgument::is_dependent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
}

bool TemplateArgument::is_instantiation_dependent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

bool TemplateArgument::contains_unexpanded_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal13();
}

bool TemplateArgument::is_pack_expansion(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal14();
}

std::optional<ValueDecl> TemplateArgument::as_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal15()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal5());
    return ValueDecl::from(fragment->DeclFor(fragment, id));
  }
}

TokenRange CXXBaseSpecifier::token_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal5(), self.getVal6());
}

Token CXXBaseSpecifier::base_type_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal7());
}

bool CXXBaseSpecifier::is_virtual(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

TagTypeKind CXXBaseSpecifier::base_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TagTypeKind>(self.getVal11());
}

bool CXXBaseSpecifier::is_pack_expansion(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
}

bool CXXBaseSpecifier::constructors_are_inherited(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

std::optional<Token> CXXBaseSpecifier::ellipsis(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal13()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal8());
    return fragment->TokenFor(fragment, id);
  }
}

AccessSpecifier CXXBaseSpecifier::semantic_access_specifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<AccessSpecifier>(self.getVal16());
}

AccessSpecifier CXXBaseSpecifier::lexical_access_specifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<AccessSpecifier>(self.getVal17());
}

Token Stmt::begin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal5());
}

Token Stmt::end_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal6());
}

TokenRange Stmt::token_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal7(), self.getVal8());
}

StmtKind Stmt::kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<StmtKind>(self.getVal11());
}

std::optional<SEHTryStmt> SEHTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_TRY_STMT:
      return reinterpret_cast<const SEHTryStmt &>(parent);
    default: return std::nullopt;
  }
}

bool SEHTryStmt::is_cxx_try(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

Token SEHTryStmt::try_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

std::optional<SEHLeaveStmt> SEHLeaveStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_LEAVE_STMT:
      return reinterpret_cast<const SEHLeaveStmt &>(parent);
    default: return std::nullopt;
  }
}

Token SEHLeaveStmt::leave_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<SEHFinallyStmt> SEHFinallyStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_FINALLY_STMT:
      return reinterpret_cast<const SEHFinallyStmt &>(parent);
    default: return std::nullopt;
  }
}

Token SEHFinallyStmt::finally_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

std::optional<SEHExceptStmt> SEHExceptStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SEH_EXCEPT_STMT:
      return reinterpret_cast<const SEHExceptStmt &>(parent);
    default: return std::nullopt;
  }
}

Token SEHExceptStmt::except_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

std::optional<ReturnStmt> ReturnStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::RETURN_STMT:
      return reinterpret_cast<const ReturnStmt &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarDecl> ReturnStmt::nrvo_candidate(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal3()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token ReturnStmt::return_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

std::optional<ObjCForCollectionStmt> ObjCForCollectionStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_FOR_COLLECTION_STMT:
      return reinterpret_cast<const ObjCForCollectionStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCForCollectionStmt::for_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

Token ObjCForCollectionStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

std::optional<ObjCAutoreleasePoolStmt> ObjCAutoreleasePoolStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AUTORELEASE_POOL_STMT:
      return reinterpret_cast<const ObjCAutoreleasePoolStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAutoreleasePoolStmt::at_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<ObjCAtTryStmt> ObjCAtTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_TRY_STMT:
      return reinterpret_cast<const ObjCAtTryStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtTryStmt::at_try_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::vector<ObjCAtCatchStmt> ObjCAtTryStmt::catch_statements(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::optional<ObjCAtThrowStmt> ObjCAtThrowStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_THROW_STMT:
      return reinterpret_cast<const ObjCAtThrowStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtThrowStmt::throw_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<ObjCAtSynchronizedStmt> ObjCAtSynchronizedStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT:
      return reinterpret_cast<const ObjCAtSynchronizedStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtSynchronizedStmt::at_synchronized_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<ObjCAtFinallyStmt> ObjCAtFinallyStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_FINALLY_STMT:
      return reinterpret_cast<const ObjCAtFinallyStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtFinallyStmt::at_finally_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<ObjCAtCatchStmt> ObjCAtCatchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OBJ_C_AT_CATCH_STMT:
      return reinterpret_cast<const ObjCAtCatchStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ObjCAtCatchStmt::at_catch_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

Token ObjCAtCatchStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

bool ObjCAtCatchStmt::has_ellipsis(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
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

bool OMPExecutableDirective::has_associated_statement(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

bool OMPExecutableDirective::is_standalone_directive(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
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

Token OMPDispatchDirective::target_call_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
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

bool OMPAtomicDirective::is_postfix_update(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

bool OMPAtomicDirective::is_xlhs_in_rhs_part(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal13();
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

bool OMPTaskDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPTargetParallelDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPSectionsDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPSectionDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPParallelSectionsDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPParallelDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPForDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPDistributeParallelForDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPTeamsDistributeParallelForDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPTaskLoopDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPTargetTeamsDistributeParallelForDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPTargetParallelForDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPParallelMasterTaskLoopDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPParallelForDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

bool OMPMasterTaskLoopDirective::has_cancel(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

std::optional<OMPCanonicalLoop> OMPCanonicalLoop::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::OMP_CANONICAL_LOOP:
      return reinterpret_cast<const OMPCanonicalLoop &>(parent);
    default: return std::nullopt;
  }
}

std::optional<NullStmt> NullStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::NULL_STMT:
      return reinterpret_cast<const NullStmt &>(parent);
    default: return std::nullopt;
  }
}

Token NullStmt::semi_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

bool NullStmt::has_leading_empty_macro(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

std::optional<MSDependentExistsStmt> MSDependentExistsStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MS_DEPENDENT_EXISTS_STMT:
      return reinterpret_cast<const MSDependentExistsStmt &>(parent);
    default: return std::nullopt;
  }
}

Token MSDependentExistsStmt::keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

bool MSDependentExistsStmt::is_if_exists(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

bool MSDependentExistsStmt::is_if_not_exists(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
}

std::optional<IndirectGotoStmt> IndirectGotoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::INDIRECT_GOTO_STMT:
      return reinterpret_cast<const IndirectGotoStmt &>(parent);
    default: return std::nullopt;
  }
}

Token IndirectGotoStmt::goto_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

Token IndirectGotoStmt::star_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

std::optional<IfStmt> IfStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::IF_STMT:
      return reinterpret_cast<const IfStmt &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarDecl> IfStmt::condition_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal3()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> IfStmt::condition_variable_declaration_statement(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal4()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal18());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

Token IfStmt::else_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token IfStmt::if_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token IfStmt::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token IfStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool IfStmt::has_else_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

bool IfStmt::has_initializer_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal13();
}

bool IfStmt::has_variable_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal14();
}

bool IfStmt::is_constexpr(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal15();
}

bool IfStmt::is_obj_c_availability_check(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal23();
}

std::optional<GotoStmt> GotoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::GOTO_STMT:
      return reinterpret_cast<const GotoStmt &>(parent);
    default: return std::nullopt;
  }
}

Token GotoStmt::goto_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

Token GotoStmt::label_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

std::optional<ForStmt> ForStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::FOR_STMT:
      return reinterpret_cast<const ForStmt &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarDecl> ForStmt::condition_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal3()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> ForStmt::condition_variable_declaration_statement(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal4()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal18());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

Token ForStmt::for_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token ForStmt::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ForStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

std::optional<DoStmt> DoStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DO_STMT:
      return reinterpret_cast<const DoStmt &>(parent);
    default: return std::nullopt;
  }
}

Token DoStmt::do_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

Token DoStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

Token DoStmt::while_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

std::optional<DeclStmt> DeclStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DECL_STMT:
      return reinterpret_cast<const DeclStmt &>(parent);
    default: return std::nullopt;
  }
}

bool DeclStmt::is_single_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

std::optional<CoroutineBodyStmt> CoroutineBodyStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COROUTINE_BODY_STMT:
      return reinterpret_cast<const CoroutineBodyStmt &>(parent);
    default: return std::nullopt;
  }
}

bool CoroutineBodyStmt::has_dependent_promise_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

std::optional<CoreturnStmt> CoreturnStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CORETURN_STMT:
      return reinterpret_cast<const CoreturnStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CoreturnStmt::keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

bool CoreturnStmt::is_implicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

std::optional<ContinueStmt> ContinueStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CONTINUE_STMT:
      return reinterpret_cast<const ContinueStmt &>(parent);
    default: return std::nullopt;
  }
}

Token ContinueStmt::continue_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<CompoundStmt> CompoundStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::COMPOUND_STMT:
      return reinterpret_cast<const CompoundStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CompoundStmt::l_brac_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

Token CompoundStmt::r_brac_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

std::optional<CapturedStmt> CapturedStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CAPTURED_STMT:
      return reinterpret_cast<const CapturedStmt &>(parent);
    default: return std::nullopt;
  }
}

CapturedRegionKind CapturedStmt::captured_region_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<CapturedRegionKind>(self.getVal16());
}

std::optional<CXXTryStmt> CXXTryStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_TRY_STMT:
      return reinterpret_cast<const CXXTryStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CXXTryStmt::try_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

std::vector<CXXCatchStmt> CXXTryStmt::handlers(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::optional<CXXForRangeStmt> CXXForRangeStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_FOR_RANGE_STMT:
      return reinterpret_cast<const CXXForRangeStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CXXForRangeStmt::coawait_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

Token CXXForRangeStmt::colon_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token CXXForRangeStmt::for_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token CXXForRangeStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

std::optional<CXXCatchStmt> CXXCatchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::CXX_CATCH_STMT:
      return reinterpret_cast<const CXXCatchStmt &>(parent);
    default: return std::nullopt;
  }
}

Token CXXCatchStmt::catch_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<BreakStmt> BreakStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::BREAK_STMT:
      return reinterpret_cast<const BreakStmt &>(parent);
    default: return std::nullopt;
  }
}

Token BreakStmt::break_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<AsmStmt> AsmStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::MS_ASM_STMT:
    case mx::StmtKind::GCC_ASM_STMT:
      return reinterpret_cast<const AsmStmt &>(parent);
    default: return std::nullopt;
  }
}

std::string_view AsmStmt::generate_assembly_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

Token AsmStmt::assembly_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

bool AsmStmt::is_simple(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

bool AsmStmt::is_volatile(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
}

std::vector<std::string_view> AsmStmt::output_constraints(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal28();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<std::string_view> AsmStmt::input_constraints(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal29();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<std::string_view> AsmStmt::clobbers(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal30();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
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

std::vector<std::string_view> MSAsmStmt::all_constraints(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal31();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::string_view MSAsmStmt::assembly_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal32();
  return std::string_view(data.cStr(), data.size());
}

Token MSAsmStmt::l_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

bool MSAsmStmt::has_braces(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

Token GCCAsmStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

bool GCCAsmStmt::is_assembly_goto(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

std::vector<AddrLabelExpr> GCCAsmStmt::labels(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::vector<StringLiteral> GCCAsmStmt::output_constraint_literals(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal33();
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

std::vector<std::string_view> GCCAsmStmt::output_names(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal31();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<StringLiteral> GCCAsmStmt::input_constraint_literals(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal34();
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

std::vector<std::string_view> GCCAsmStmt::input_names(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal35();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::vector<StringLiteral> GCCAsmStmt::clobber_string_literals(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal36();
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

std::vector<AddrLabelExpr> GCCAsmStmt::label_expressions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal37();
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

std::vector<std::string_view> GCCAsmStmt::label_names(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal38();
  std::vector<std::string_view> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(v.cStr(), v.size());
  }
  return vec;
}

std::optional<WhileStmt> WhileStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::WHILE_STMT:
      return reinterpret_cast<const WhileStmt &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarDecl> WhileStmt::condition_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal3()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> WhileStmt::condition_variable_declaration_statement(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal4()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal18());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

Token WhileStmt::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token WhileStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token WhileStmt::while_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool WhileStmt::has_variable_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
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

Token LabelStmt::identifier_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
}

std::string_view LabelStmt::name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

bool LabelStmt::is_side_entry(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
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

bool Expr::has_side_effects(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

bool Expr::contains_errors(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
}

bool Expr::contains_unexpanded_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

Token Expr::expression_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<ObjCPropertyRefExpr> Expr::obj_c_property(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal13()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal18());
    return ObjCPropertyRefExpr::from(fragment->StmtFor(fragment, id));
  }
}

ExprObjectKind Expr::object_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ExprObjectKind>(self.getVal16());
}

std::optional<FieldDecl> Expr::source_bit_field(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal14()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal19());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

ExprValueKind Expr::value_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ExprValueKind>(self.getVal17());
}

bool Expr::has_non_trivial_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal15();
}

bool Expr::is_default_argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal23();
}

bool Expr::is_gl_value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal39();
}

bool Expr::is_implicit_cxx_this(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal40();
}

bool Expr::is_instantiation_dependent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal41();
}

bool Expr::is_known_to_have_boolean_value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal42();
}

bool Expr::is_l_value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal43();
}

bool Expr::is_objcgc_candidate(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal44();
}

bool Expr::is_obj_c_self_expression(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal45();
}

bool Expr::is_ordinary_or_bit_field_object(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal46();
}

bool Expr::is_pr_value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal47();
}

bool Expr::is_read_if_discarded_in_c_plus_plus11(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal48();
}

bool Expr::is_type_dependent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal49();
}

bool Expr::is_value_dependent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal50();
}

bool Expr::is_x_value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal51();
}

bool Expr::refers_to_bit_field(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal52();
}

bool Expr::refers_to_global_register_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal53();
}

bool Expr::refers_to_matrix_element(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal54();
}

bool Expr::refers_to_vector_element(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal55();
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

TokenRange DesignatedInitExpr::designators_source_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal20(), self.getVal21());
}

Token DesignatedInitExpr::equal_or_colon_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool DesignatedInitExpr::is_direct_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool DesignatedInitExpr::uses_gnu_syntax(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token DependentScopeDeclRefExpr::l_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token DependentScopeDeclRefExpr::r_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token DependentScopeDeclRefExpr::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool DependentScopeDeclRefExpr::has_explicit_template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool DependentScopeDeclRefExpr::has_template_keyword(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token DependentCoawaitExpr::keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

Token DeclRefExpr::l_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token DeclRefExpr::r_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

Token DeclRefExpr::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

bool DeclRefExpr::had_multiple_candidates(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool DeclRefExpr::has_explicit_template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool DeclRefExpr::has_qualifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool DeclRefExpr::has_template_kw_and_arguments_info(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool DeclRefExpr::has_template_keyword(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

NonOdrUseReason DeclRefExpr::is_non_odr_use(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<NonOdrUseReason>(self.getVal61());
}

bool DeclRefExpr::refers_to_enclosing_variable_or_capture(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
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

Token CoroutineSuspendExpr::keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

bool CoawaitExpr::is_implicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token ConvertVectorExpr::builtin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ConvertVectorExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

std::vector<TemplateArgument> ConceptSpecializationExpr::template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal63();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

bool ConceptSpecializationExpr::is_satisfied(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token CompoundLiteralExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool CompoundLiteralExpr::is_file_scope(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token ChooseExpr::builtin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ChooseExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool ChooseExpr::is_condition_dependent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool ChooseExpr::is_condition_true(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token CharacterLiteral::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

CastKind CastExpr::cast_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<CastKind>(self.getVal61());
}

std::string_view CastExpr::cast_kind_name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

std::optional<NamedDecl> CastExpr::conversion_function(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal56()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal20());
    return NamedDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<FieldDecl> CastExpr::target_union_field(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal57()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal21());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool CastExpr::has_stored_fp_features(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
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

bool ImplicitCastExpr::is_part_of_explicit_cast(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
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

TokenRange CXXNamedCastExpr::angle_brackets(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal22(), self.getVal24());
}

std::string_view CXXNamedCastExpr::cast_name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal32();
  return std::string_view(data.cStr(), data.size());
}

Token CXXNamedCastExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

Token CXXNamedCastExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
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

bool CXXDynamicCastExpr::is_always_null(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
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

Token CXXFunctionalCastExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token CXXFunctionalCastExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

bool CXXFunctionalCastExpr::is_list_initialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
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

Token CStyleCastExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token CStyleCastExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
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

Token ObjCBridgedCastExpr::bridge_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

ObjCBridgeCastKind ObjCBridgedCastExpr::bridge_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCBridgeCastKind>(self.getVal64());
}

std::string_view ObjCBridgedCastExpr::bridge_kind_name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal32();
  return std::string_view(data.cStr(), data.size());
}

Token ObjCBridgedCastExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
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

CallExprADLCallKind CallExpr::adl_call_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<CallExprADLCallKind>(self.getVal61());
}

std::optional<FunctionDecl> CallExpr::direct_callee(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal56()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal20());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token CallExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool CallExpr::has_stored_fp_features(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool CallExpr::has_unused_result_attribute(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool CallExpr::is_builtin_assume_false(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool CallExpr::is_call_to_std_move(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool CallExpr::is_unevaluated_builtin_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool CallExpr::uses_adl(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
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

OverloadedOperatorKind CXXOperatorCallExpr::operator_(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<OverloadedOperatorKind>(self.getVal64());
}

Token CXXOperatorCallExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool CXXOperatorCallExpr::is_assignment_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal66();
}

bool CXXOperatorCallExpr::is_comparison_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal67();
}

bool CXXOperatorCallExpr::is_infix_binary_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal68();
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

UserDefinedLiteralLiteralOperatorKind UserDefinedLiteral::literal_operator_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<UserDefinedLiteralLiteralOperatorKind>(self.getVal64());
}

Token UserDefinedLiteral::ud_suffix_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
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

bool CXXUuidofExpr::is_type_operand(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token CXXUnresolvedConstructExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token CXXUnresolvedConstructExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool CXXUnresolvedConstructExpr::is_list_initialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

bool CXXTypeidExpr::is_most_derived(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool CXXTypeidExpr::is_potentially_evaluated(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool CXXTypeidExpr::is_type_operand(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
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

Token CXXThrowExpr::throw_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool CXXThrowExpr::is_thrown_variable_in_scope(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token CXXThisExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool CXXThisExpr::is_implicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token CXXScalarValueInitExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

BinaryOperatorKind CXXRewrittenBinaryOperator::opcode(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<BinaryOperatorKind>(self.getVal61());
}

std::string_view CXXRewrittenBinaryOperator::opcode_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

BinaryOperatorKind CXXRewrittenBinaryOperator::operator_(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<BinaryOperatorKind>(self.getVal64());
}

Token CXXRewrittenBinaryOperator::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool CXXRewrittenBinaryOperator::is_assignment_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool CXXRewrittenBinaryOperator::is_comparison_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool CXXRewrittenBinaryOperator::is_reversed(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
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

Token CXXPseudoDestructorExpr::colon_colon_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token CXXPseudoDestructorExpr::destroyed_type_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token CXXPseudoDestructorExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token CXXPseudoDestructorExpr::tilde_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

bool CXXPseudoDestructorExpr::has_qualifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool CXXPseudoDestructorExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token CXXNullPtrLiteralExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

bool CXXNoexceptExpr::value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

bool CXXNewExpr::does_usual_array_delete_want_size(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

TokenRange CXXNewExpr::direct_initializer_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal21(), self.getVal22());
}

CXXNewExprInitializationStyle CXXNewExpr::initialization_style(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<CXXNewExprInitializationStyle>(self.getVal61());
}

TokenRange CXXNewExpr::type_id_parentheses(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal26(), self.getVal69());
}

bool CXXNewExpr::has_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool CXXNewExpr::is_array(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool CXXNewExpr::is_global_new(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool CXXNewExpr::is_parenthesis_type_id(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool CXXNewExpr::pass_alignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool CXXNewExpr::should_null_check_allocation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
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

bool CXXInheritedCtorInitExpr::constructs_virtual_base(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

CXXConstructExprConstructionKind CXXInheritedCtorInitExpr::construction_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<CXXConstructExprConstructionKind>(self.getVal61());
}

Token CXXInheritedCtorInitExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool CXXInheritedCtorInitExpr::inherited_from_virtual_base(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token CXXFoldExpr::ellipsis_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token CXXFoldExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

BinaryOperatorKind CXXFoldExpr::operator_(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<BinaryOperatorKind>(self.getVal61());
}

Token CXXFoldExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

bool CXXFoldExpr::is_left_fold(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool CXXFoldExpr::is_right_fold(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token CXXDependentScopeMemberExpr::l_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token CXXDependentScopeMemberExpr::member_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token CXXDependentScopeMemberExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

Token CXXDependentScopeMemberExpr::r_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

Token CXXDependentScopeMemberExpr::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

bool CXXDependentScopeMemberExpr::has_explicit_template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool CXXDependentScopeMemberExpr::has_template_keyword(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool CXXDependentScopeMemberExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool CXXDependentScopeMemberExpr::is_implicit_access(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
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

bool CXXDeleteExpr::does_usual_array_delete_want_size(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool CXXDeleteExpr::is_array_form(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool CXXDeleteExpr::is_array_form_as_written(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool CXXDeleteExpr::is_global_delete(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
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

Token CXXDefaultInitExpr::used_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token CXXDefaultArgExpr::used_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

CXXConstructExprConstructionKind CXXConstructExpr::construction_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<CXXConstructExprConstructionKind>(self.getVal61());
}

Token CXXConstructExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

TokenRange CXXConstructExpr::parenthesis_or_brace_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal22(), self.getVal24());
}

bool CXXConstructExpr::had_multiple_candidates(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool CXXConstructExpr::is_elidable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool CXXConstructExpr::is_list_initialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool CXXConstructExpr::is_std_initializer_list_initialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool CXXConstructExpr::requires_zero_initialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
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

Token CXXBoolLiteralExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool CXXBoolLiteralExpr::value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token BlockExpr::caret_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

BinaryOperatorKind BinaryOperator::opcode(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<BinaryOperatorKind>(self.getVal61());
}

std::string_view BinaryOperator::opcode_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

Token BinaryOperator::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool BinaryOperator::has_stored_fp_features(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool BinaryOperator::is_additive_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool BinaryOperator::is_assignment_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool BinaryOperator::is_bitwise_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool BinaryOperator::is_comma_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool BinaryOperator::is_comparison_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool BinaryOperator::is_compound_assignment_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
}

bool BinaryOperator::is_equality_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal66();
}

bool BinaryOperator::is_logical_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal67();
}

bool BinaryOperator::is_multiplicative_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal68();
}

bool BinaryOperator::is_pointer_memory_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal70();
}

bool BinaryOperator::is_relational_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal71();
}

bool BinaryOperator::is_shift_assign_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal72();
}

bool BinaryOperator::is_shift_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
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

Token AtomicExpr::builtin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

AtomicExprAtomicOp AtomicExpr::operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<AtomicExprAtomicOp>(self.getVal61());
}

Token AtomicExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool AtomicExpr::is_cmp_x_chg(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool AtomicExpr::is_open_cl(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool AtomicExpr::is_volatile(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
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

Token AsTypeExpr::builtin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token AsTypeExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

ArrayTypeTrait ArrayTypeTraitExpr::trait(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ArrayTypeTrait>(self.getVal61());
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

Token ArraySubscriptExpr::r_bracket_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

Token AddrLabelExpr::amp_amp_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token AddrLabelExpr::label_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
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

Token AbstractConditionalOperator::colon_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token AbstractConditionalOperator::question_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token VAArgExpr::builtin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token VAArgExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool VAArgExpr::is_microsoft_abi(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

bool UnaryOperator::can_overflow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

UnaryOperatorKind UnaryOperator::opcode(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<UnaryOperatorKind>(self.getVal61());
}

Token UnaryOperator::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool UnaryOperator::has_stored_fp_features(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool UnaryOperator::is_arithmetic_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool UnaryOperator::is_decrement_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool UnaryOperator::is_increment_decrement_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool UnaryOperator::is_increment_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool UnaryOperator::is_postfix(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
}

bool UnaryOperator::is_prefix(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal66();
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

Token UnaryExprOrTypeTraitExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token UnaryExprOrTypeTraitExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool UnaryExprOrTypeTraitExpr::is_argument_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

TypeTrait TypeTraitExpr::trait(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TypeTrait>(self.getVal61());
}

bool TypeTraitExpr::value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token SubstNonTypeTemplateParmPackExpr::parameter_pack_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token SubstNonTypeTemplateParmExpr::name_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool SubstNonTypeTemplateParmExpr::is_reference_parameter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

bool StringLiteral::contains_non_ascii(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool StringLiteral::contains_non_ascii_or_null(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

std::string_view StringLiteral::bytes(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

std::string_view StringLiteral::string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal32();
  return std::string_view(data.cStr(), data.size());
}

bool StringLiteral::is_ascii(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool StringLiteral::is_pascal(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool StringLiteral::is_utf16(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool StringLiteral::is_utf32(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool StringLiteral::is_utf8(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
}

bool StringLiteral::is_wide(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal66();
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

Token StmtExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token StmtExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

std::string_view SourceLocExpr::builtin_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

SourceLocExprIdentKind SourceLocExpr::identifier_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<SourceLocExprIdentKind>(self.getVal61());
}

Token SourceLocExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool SourceLocExpr::is_int_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool SourceLocExpr::is_string_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token SizeOfPackExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token SizeOfPackExpr::pack_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

std::vector<TemplateArgument> SizeOfPackExpr::partial_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal63();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

Token SizeOfPackExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

bool SizeOfPackExpr::is_partially_substituted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token ShuffleVectorExpr::builtin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ShuffleVectorExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

std::string_view SYCLUniqueStableNameExpr::compute_name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

Token SYCLUniqueStableNameExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token SYCLUniqueStableNameExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token SYCLUniqueStableNameExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
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

std::vector<ParmVarDecl> RequiresExpr::local_parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

Token RequiresExpr::r_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token RequiresExpr::requires_kw_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool RequiresExpr::is_satisfied(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

PredefinedExprIdentKind PredefinedExpr::identifier_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<PredefinedExprIdentKind>(self.getVal61());
}

std::string_view PredefinedExpr::identifier_kind_name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

Token PredefinedExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token ParenListExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ParenListExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token ParenExpr::l_paren(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ParenExpr::r_paren(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token PackExpansionExpr::ellipsis_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

Token OverloadExpr::l_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token OverloadExpr::name_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token OverloadExpr::r_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

Token OverloadExpr::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

bool OverloadExpr::has_explicit_template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool OverloadExpr::has_template_keyword(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token UnresolvedMemberExpr::member_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

Token UnresolvedMemberExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal69());
}

bool UnresolvedMemberExpr::has_unresolved_using(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool UnresolvedMemberExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool UnresolvedMemberExpr::is_implicit_access(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
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

bool UnresolvedLookupExpr::is_overloaded(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool UnresolvedLookupExpr::requires_adl(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
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

Token OpaqueValueExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool OpaqueValueExpr::is_unique(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token OffsetOfExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token OffsetOfExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token ObjCSubscriptRefExpr::r_bracket(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool ObjCSubscriptRefExpr::is_array_subscript_reference_expression(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token ObjCStringLiteral::at_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

Token ObjCSelectorExpr::at_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ObjCSelectorExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token ObjCProtocolExpr::at_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ObjCProtocolExpr::protocol_id_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token ObjCProtocolExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
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

Token ObjCPropertyRefExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

Token ObjCPropertyRefExpr::receiver_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

bool ObjCPropertyRefExpr::is_class_receiver(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool ObjCPropertyRefExpr::is_explicit_property(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool ObjCPropertyRefExpr::is_implicit_property(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool ObjCPropertyRefExpr::is_messaging_getter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool ObjCPropertyRefExpr::is_messaging_setter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool ObjCPropertyRefExpr::is_object_receiver(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool ObjCPropertyRefExpr::is_super_receiver(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
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

Token ObjCMessageExpr::left_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

ObjCMethodFamily ObjCMessageExpr::method_family(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCMethodFamily>(self.getVal61());
}

ObjCMessageExprReceiverKind ObjCMessageExpr::receiver_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCMessageExprReceiverKind>(self.getVal64());
}

TokenRange ObjCMessageExpr::receiver_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal24(), self.getVal25());
}

Token ObjCMessageExpr::right_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

Token ObjCMessageExpr::selector_start_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal69());
}

Token ObjCMessageExpr::super_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal74());
}

bool ObjCMessageExpr::is_class_message(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool ObjCMessageExpr::is_delegate_initializer_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool ObjCMessageExpr::is_implicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool ObjCMessageExpr::is_instance_message(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

std::vector<Token> ObjCMessageExpr::selector_tokens(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
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

Token ObjCIvarRefExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token ObjCIvarRefExpr::operation_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool ObjCIvarRefExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool ObjCIvarRefExpr::is_free_instance_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token ObjCIsaExpr::base_token_end(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ObjCIsaExpr::isa_member_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token ObjCIsaExpr::operation_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool ObjCIsaExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

bool ObjCIndirectCopyRestoreExpr::should_copy(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token ObjCEncodeExpr::at_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ObjCEncodeExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token ObjCBoxedExpr::at_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool ObjCBoxedExpr::is_expressible_as_constant_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token ObjCBoolLiteralExpr::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool ObjCBoolLiteralExpr::value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

bool ObjCAvailabilityCheckExpr::has_version(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token OMPIteratorExpr::iterator_kw_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token OMPIteratorExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token OMPIteratorExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
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

Token OMPArrayShapingExpr::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token OMPArrayShapingExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
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

Token OMPArraySectionExpr::colon_token_first(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token OMPArraySectionExpr::colon_token_second(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token OMPArraySectionExpr::r_bracket_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
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

Token MemberExpr::l_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token MemberExpr::member_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token MemberExpr::operator_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

Token MemberExpr::r_angle_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

Token MemberExpr::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

bool MemberExpr::had_multiple_candidates(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool MemberExpr::has_explicit_template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool MemberExpr::has_qualifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool MemberExpr::has_template_keyword(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool MemberExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool MemberExpr::is_implicit_access(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

NonOdrUseReason MemberExpr::is_non_odr_use(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<NonOdrUseReason>(self.getVal61());
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

Token MatrixSubscriptExpr::r_bracket_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool MatrixSubscriptExpr::is_incomplete(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

StorageDuration MaterializeTemporaryExpr::storage_duration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<StorageDuration>(self.getVal61());
}

bool MaterializeTemporaryExpr::is_bound_to_lvalue_reference(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool MaterializeTemporaryExpr::is_usable_in_constant_expressions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token MSPropertySubscriptExpr::r_bracket_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

Token MSPropertyRefExpr::member_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool MSPropertyRefExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool MSPropertyRefExpr::is_implicit_access(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

LambdaCaptureDefault LambdaExpr::capture_default(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<LambdaCaptureDefault>(self.getVal61());
}

Token LambdaExpr::capture_default_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

std::vector<NamedDecl> LambdaExpr::explicit_template_parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

TokenRange LambdaExpr::introducer_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal24(), self.getVal25());
}

std::optional<TemplateParameterList> LambdaExpr::template_parameter_list(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal56()) {
    return std::nullopt;
  } else {
    return TemplateParameterList(fragment, self.getVal0());
  }
}

bool LambdaExpr::has_explicit_parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool LambdaExpr::has_explicit_result_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool LambdaExpr::is_generic_lambda(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool LambdaExpr::is_mutable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
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

Token IntegerLiteral::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

std::optional<FieldDecl> InitListExpr::initialized_field_in_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal56()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal20());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token InitListExpr::l_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token InitListExpr::r_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

std::optional<InitListExpr> InitListExpr::semantic_form(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal57()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal24());
    return InitListExpr::from(fragment->StmtFor(fragment, id));
  }
}

std::optional<InitListExpr> InitListExpr::syntactic_form(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal58()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal25());
    return InitListExpr::from(fragment->StmtFor(fragment, id));
  }
}

bool InitListExpr::had_array_range_designator(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool InitListExpr::has_array_filler(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

bool InitListExpr::is_explicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool InitListExpr::is_semantic_form(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
}

bool InitListExpr::is_string_literal_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal66();
}

bool InitListExpr::is_syntactic_form(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal67();
}

bool InitListExpr::is_transparent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal68();
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

Token GenericSelectionExpr::default_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token GenericSelectionExpr::generic_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token GenericSelectionExpr::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool GenericSelectionExpr::is_result_dependent(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token GNUNullExpr::token_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

Token FunctionParmPackExpr::parameter_pack_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

std::vector<VarDecl> FunctionParmPackExpr::expansions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

bool ExprWithCleanups::cleanups_have_side_effects(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

ConstantExprResultStorageKind ConstantExpr::result_storage_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ConstantExprResultStorageKind>(self.getVal61());
}

bool ConstantExpr::has_ap_value_result(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool ConstantExpr::is_immediate_invocation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

Token FloatingLiteral::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool FloatingLiteral::is_exact(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token FixedPointLiteral::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

bool ExtVectorElementExpr::contains_duplicate_elements(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

Token ExtVectorElementExpr::accessor_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool ExtVectorElementExpr::is_arrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
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

ExpressionTrait ExpressionTraitExpr::trait(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ExpressionTrait>(self.getVal61());
}

bool ExpressionTraitExpr::value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
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

Token AttributedStmt::attribute_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

std::optional<SwitchStmt> SwitchStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::SWITCH_STMT:
      return reinterpret_cast<const SwitchStmt &>(parent);
    default: return std::nullopt;
  }
}

std::optional<VarDecl> SwitchStmt::condition_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal3()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal9());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<DeclStmt> SwitchStmt::condition_variable_declaration_statement(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal4()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal18());
    return DeclStmt::from(fragment->StmtFor(fragment, id));
  }
}

Token SwitchStmt::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token SwitchStmt::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token SwitchStmt::switch_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool SwitchStmt::has_initializer_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

bool SwitchStmt::has_variable_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal13();
}

bool SwitchStmt::is_all_enum_cases_covered(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal14();
}

std::optional<SwitchCase> SwitchCase::from(const Stmt &parent) {
  switch (parent.kind()) {
    case mx::StmtKind::DEFAULT_STMT:
    case mx::StmtKind::CASE_STMT:
      return reinterpret_cast<const SwitchCase &>(parent);
    default: return std::nullopt;
  }
}

Token SwitchCase::colon_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal9());
}

Token SwitchCase::keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal18());
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

Token DefaultStmt::default_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
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

bool CaseStmt::case_statement_is_gnu_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal3();
}

Token CaseStmt::case_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token CaseStmt::ellipsis_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

AccessSpecifier Decl::access(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<AccessSpecifier>(self.getVal11());
}

AccessSpecifier Decl::access_unsafe(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<AccessSpecifier>(self.getVal16());
}

AvailabilityResult Decl::availability(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<AvailabilityResult>(self.getVal17());
}

Token Decl::begin_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal5());
}

Token Decl::body_r_brace(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal6());
}

std::optional<TemplateParameterList> Decl::described_template_parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal3()) {
    return std::nullopt;
  } else {
    return TemplateParameterList(fragment, self.getVal0());
  }
}

Token Decl::end_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal7());
}

DeclFriendObjectKind Decl::friend_object_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<DeclFriendObjectKind>(self.getVal61());
}

DeclModuleOwnershipKind Decl::module_ownership_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<DeclModuleOwnershipKind>(self.getVal64());
}

bool Decl::has_attributes(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal4();
}

bool Decl::has_defining_attribute(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal12();
}

bool Decl::has_owning_module(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal13();
}

bool Decl::has_tag_identifier_namespace(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal14();
}

bool Decl::is_canonical_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal15();
}

bool Decl::is_defined_outside_function_or_method(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal23();
}

bool Decl::is_deprecated(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal39();
}

bool Decl::is_first_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal40();
}

bool Decl::is_function_or_function_template(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal41();
}

bool Decl::is_implicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal42();
}

bool Decl::is_in_anonymous_namespace(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal43();
}

bool Decl::is_in_local_scope_for_instantiation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal44();
}

bool Decl::is_in_std_namespace(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal45();
}

bool Decl::is_invalid_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal46();
}

bool Decl::is_module_private(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal47();
}

bool Decl::is_out_of_line(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal48();
}

bool Decl::is_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal49();
}

bool Decl::is_referenced(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal50();
}

bool Decl::is_template_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal51();
}

bool Decl::is_template_parameter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal52();
}

bool Decl::is_template_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal53();
}

bool Decl::is_templated(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal54();
}

bool Decl::is_this_declaration_referenced(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal55();
}

bool Decl::is_top_level_declaration_in_obj_c_container(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal56();
}

bool Decl::is_unavailable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal57();
}

bool Decl::is_unconditionally_visible(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal58();
}

bool Decl::is_used(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal59();
}

bool Decl::is_weak_imported(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal60();
}

DeclKind Decl::kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<DeclKind>(self.getVal75());
}

Token Decl::token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal8());
}

TokenRange Decl::token_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal9(), self.getVal18());
}

std::optional<ClassScopeFunctionSpecializationDecl> ClassScopeFunctionSpecializationDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION:
      return reinterpret_cast<const ClassScopeFunctionSpecializationDecl &>(parent);
    default: return std::nullopt;
  }
}

bool ClassScopeFunctionSpecializationDecl::has_explicit_template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

std::optional<CapturedDecl> CapturedDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::CAPTURED:
      return reinterpret_cast<const CapturedDecl &>(parent);
    default: return std::nullopt;
  }
}

bool CapturedDecl::is_nothrow(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

std::vector<ImplicitParamDecl> CapturedDecl::parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::optional<BlockDecl> BlockDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::BLOCK:
      return reinterpret_cast<const BlockDecl &>(parent);
    default: return std::nullopt;
  }
}

bool BlockDecl::block_missing_return_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool BlockDecl::can_avoid_copy_to_heap(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
}

bool BlockDecl::captures_cxx_this(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal66();
}

bool BlockDecl::does_not_escape(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal67();
}

Token BlockDecl::caret_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

bool BlockDecl::has_captures(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal68();
}

bool BlockDecl::is_conversion_from_lambda(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal70();
}

bool BlockDecl::is_variadic(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal71();
}

std::vector<ParmVarDecl> BlockDecl::parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::vector<ParmVarDecl> BlockDecl::parameter_declarations(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal33();
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

std::optional<AccessSpecDecl> AccessSpecDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::ACCESS_SPEC:
      return reinterpret_cast<const AccessSpecDecl &>(parent);
    default: return std::nullopt;
  }
}

Token AccessSpecDecl::access_specifier_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token AccessSpecDecl::colon_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
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

std::optional<TranslationUnitDecl> TranslationUnitDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::TRANSLATION_UNIT:
      return reinterpret_cast<const TranslationUnitDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<StaticAssertDecl> StaticAssertDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::STATIC_ASSERT:
      return reinterpret_cast<const StaticAssertDecl &>(parent);
    default: return std::nullopt;
  }
}

Token StaticAssertDecl::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool StaticAssertDecl::is_failed(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

std::optional<RequiresExprBodyDecl> RequiresExprBodyDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::REQUIRES_EXPR_BODY:
      return reinterpret_cast<const RequiresExprBodyDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<PragmaDetectMismatchDecl> PragmaDetectMismatchDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::PRAGMA_DETECT_MISMATCH:
      return reinterpret_cast<const PragmaDetectMismatchDecl &>(parent);
    default: return std::nullopt;
  }
}

std::string_view PragmaDetectMismatchDecl::name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

std::string_view PragmaDetectMismatchDecl::value(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal32();
  return std::string_view(data.cStr(), data.size());
}

std::optional<PragmaCommentDecl> PragmaCommentDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::PRAGMA_COMMENT:
      return reinterpret_cast<const PragmaCommentDecl &>(parent);
    default: return std::nullopt;
  }
}

std::string_view PragmaCommentDecl::argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

PragmaMSCommentKind PragmaCommentDecl::comment_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<PragmaMSCommentKind>(self.getVal76());
}

std::optional<ObjCPropertyImplDecl> ObjCPropertyImplDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::OBJ_C_PROPERTY_IMPL:
      return reinterpret_cast<const ObjCPropertyImplDecl &>(parent);
    default: return std::nullopt;
  }
}

ObjCPropertyImplDeclKind ObjCPropertyImplDecl::property_implementation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCPropertyImplDeclKind>(self.getVal76());
}

Token ObjCPropertyImplDecl::property_instance_variable_declaration_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool ObjCPropertyImplDecl::is_instance_variable_name_specified(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
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

Linkage NamedDecl::formal_linkage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<Linkage>(self.getVal76());
}

Linkage NamedDecl::linkage_internal(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<Linkage>(self.getVal77());
}

std::string_view NamedDecl::name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal27();
  return std::string_view(data.cStr(), data.size());
}

ObjCStringFormatFamily NamedDecl::obj_cf_string_formatting_family(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCStringFormatFamily>(self.getVal78());
}

std::string_view NamedDecl::qualified_name_as_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal32();
  return std::string_view(data.cStr(), data.size());
}

Visibility NamedDecl::visibility(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<Visibility>(self.getVal79());
}

bool NamedDecl::has_external_formal_linkage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

bool NamedDecl::has_linkage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal65();
}

bool NamedDecl::has_linkage_been_computed(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal66();
}

bool NamedDecl::is_cxx_class_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal67();
}

bool NamedDecl::is_cxx_instance_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal68();
}

bool NamedDecl::is_externally_declarable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal70();
}

bool NamedDecl::is_externally_visible(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal71();
}

bool NamedDecl::is_linkage_valid(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal72();
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

std::string_view LabelDecl::ms_assembly_label(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal80();
  return std::string_view(data.cStr(), data.size());
}

bool LabelDecl::is_gnu_local(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

bool LabelDecl::is_ms_assembly_label(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool LabelDecl::is_resolved_ms_assembly_label(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
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

std::vector<UsingShadowDecl> BaseUsingDecl::shadows(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

Token UsingEnumDecl::enum_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token UsingEnumDecl::using_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
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

Token UsingDecl::using_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool UsingDecl::has_typename(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

bool UsingDecl::is_access_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
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

bool ValueDecl::is_weak(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
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

Token UnresolvedUsingValueDecl::ellipsis_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token UnresolvedUsingValueDecl::using_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

bool UnresolvedUsingValueDecl::is_access_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool UnresolvedUsingValueDecl::is_pack_expansion(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
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

OMPDeclareReductionDeclInitKind OMPDeclareReductionDecl::initializer_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<OMPDeclareReductionDeclInitKind>(self.getVal83());
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

std::vector<NamedDecl> IndirectFieldDecl::chain(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::optional<FieldDecl> IndirectFieldDecl::anonymous_field(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal81()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal20());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<VarDecl> IndirectFieldDecl::variable_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal21());
    return VarDecl::from(fragment->DeclFor(fragment, id));
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

Token DeclaratorDecl::inner_token_start(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token DeclaratorDecl::outer_token_start(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token DeclaratorDecl::type_spec_end_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token DeclaratorDecl::type_spec_start_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

std::vector<TemplateParameterList> DeclaratorDecl::template_parameter_lists(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal63();
  std::vector<TemplateParameterList> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
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

std::optional<VarDecl> VarDecl::acting_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal81()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal25());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

VarDeclInitializationStyle VarDecl::initializer_style(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<VarDeclInitializationStyle>(self.getVal83());
}

std::optional<VarDecl> VarDecl::initializing_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal26());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<VarDecl> VarDecl::instantiated_from_static_data_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal84()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal69());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

LanguageLinkage VarDecl::language_linkage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<LanguageLinkage>(self.getVal85());
}

Token VarDecl::point_of_instantiation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal74());
}

StorageClass VarDecl::storage_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<StorageClass>(self.getVal86());
}

StorageDuration VarDecl::storage_duration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<StorageDuration>(self.getVal87());
}

VarDeclTLSKind VarDecl::tls_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<VarDeclTLSKind>(self.getVal88());
}

ThreadStorageClassSpecifier VarDecl::tsc_spec(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ThreadStorageClassSpecifier>(self.getVal89());
}

std::optional<VarDecl> VarDecl::template_instantiation_pattern(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal91()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal90());
    return VarDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind VarDecl::template_specialization_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal92());
}

TemplateSpecializationKind VarDecl::template_specialization_kind_for_instantiation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal93());
}

bool VarDecl::has_constant_initialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
}

bool VarDecl::has_dependent_alignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal95();
}

bool VarDecl::has_external_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal96();
}

bool VarDecl::has_global_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal97();
}

bool VarDecl::has_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal98();
}

bool VarDecl::has_local_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal99();
}

bool VarDecl::is_arc_pseudo_strong(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal100();
}

bool VarDecl::is_cxx_for_range_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal101();
}

bool VarDecl::is_constexpr(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal102();
}

bool VarDecl::is_direct_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal103();
}

bool VarDecl::is_escaping_byref(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal104();
}

bool VarDecl::is_exception_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal105();
}

bool VarDecl::is_extern_c(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal106();
}

bool VarDecl::is_file_variable_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal107();
}

bool VarDecl::is_function_or_method_variable_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal108();
}

bool VarDecl::is_in_extern_c_context(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal109();
}

bool VarDecl::is_in_extern_cxx_context(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal110();
}

bool VarDecl::is_initializer_capture(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal111();
}

bool VarDecl::is_inline(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal112();
}

bool VarDecl::is_inline_specified(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal113();
}

bool VarDecl::is_known_to_be_defined(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal114();
}

bool VarDecl::is_local_variable_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal115();
}

bool VarDecl::is_local_variable_declaration_or_parm(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal116();
}

bool VarDecl::is_nrvo_variable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal117();
}

bool VarDecl::is_no_destroy(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal118();
}

bool VarDecl::is_non_escaping_byref(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal119();
}

bool VarDecl::is_obj_c_for_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal120();
}

bool VarDecl::is_previous_declaration_in_same_block_scope(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal121();
}

bool VarDecl::is_static_data_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal122();
}

bool VarDecl::is_static_local(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal123();
}

bool VarDecl::is_this_declaration_a_demoted_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal124();
}

bool VarDecl::is_usable_in_constant_expressions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal125();
}

bool VarDecl::might_be_usable_in_constant_expressions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal126();
}

QualTypeDestructionKind VarDecl::needs_destruction(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<QualTypeDestructionKind>(self.getVal127());
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

TokenRange ParmVarDecl::default_argument_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal128(), self.getVal129());
}

DeclObjCDeclQualifier ParmVarDecl::obj_c_decl_qualifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<DeclObjCDeclQualifier>(self.getVal130());
}

bool ParmVarDecl::has_default_argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal131();
}

bool ParmVarDecl::has_inherited_default_argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal132();
}

bool ParmVarDecl::has_uninstantiated_default_argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal133();
}

bool ParmVarDecl::has_unparsed_default_argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal134();
}

bool ParmVarDecl::is_destroyed_in_callee(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal135();
}

bool ParmVarDecl::is_knr_promoted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal136();
}

bool ParmVarDecl::is_obj_c_method_parameter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal137();
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

ImplicitParamDeclImplicitParamKind ImplicitParamDecl::parameter_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ImplicitParamDeclImplicitParamKind>(self.getVal130());
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

std::vector<BindingDecl> DecompositionDecl::bindings(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

Token VarTemplateSpecializationDecl::extern_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal128());
}

TemplateSpecializationKind VarTemplateSpecializationDecl::specialization_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal130());
}

std::vector<TemplateArgument> VarTemplateSpecializationDecl::template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal138();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::vector<TemplateArgument> VarTemplateSpecializationDecl::template_instantiation_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal139();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

Token VarTemplateSpecializationDecl::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal129());
}

bool VarTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal131();
}

bool VarTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal132();
}

bool VarTemplateSpecializationDecl::is_explicit_specialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal133();
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

bool NonTypeTemplateParmDecl::default_argument_was_inherited(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

Token NonTypeTemplateParmDecl::default_argument_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

bool NonTypeTemplateParmDecl::has_default_argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

bool NonTypeTemplateParmDecl::has_placeholder_type_constraint(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
}

bool NonTypeTemplateParmDecl::is_expanded_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal91();
}

bool NonTypeTemplateParmDecl::is_pack_expansion(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
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

bool MSPropertyDecl::has_getter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool MSPropertyDecl::has_setter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
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

bool FunctionDecl::does_this_declaration_have_a_body(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

ConstexprSpecKind FunctionDecl::constexpr_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ConstexprSpecKind>(self.getVal83());
}

std::optional<FunctionDecl> FunctionDecl::definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal25());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token FunctionDecl::ellipsis_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

TokenRange FunctionDecl::exception_spec_source_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal69(), self.getVal74());
}

ExceptionSpecificationType FunctionDecl::exception_spec_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ExceptionSpecificationType>(self.getVal85());
}

std::optional<FunctionDecl> FunctionDecl::instantiated_from_member_function(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal84()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal90());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

LanguageLinkage FunctionDecl::language_linkage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<LanguageLinkage>(self.getVal86());
}

MultiVersionKind FunctionDecl::multi_version_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<MultiVersionKind>(self.getVal87());
}

OverloadedOperatorKind FunctionDecl::overloaded_operator(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<OverloadedOperatorKind>(self.getVal88());
}

TokenRange FunctionDecl::parameters_source_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal128(), self.getVal129());
}

Token FunctionDecl::point_of_instantiation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal140());
}

TokenRange FunctionDecl::return_type_source_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal141(), self.getVal142());
}

StorageClass FunctionDecl::storage_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<StorageClass>(self.getVal89());
}

std::optional<FunctionDecl> FunctionDecl::template_instantiation_pattern(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal91()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal143());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind FunctionDecl::template_specialization_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal92());
}

TemplateSpecializationKind FunctionDecl::template_specialization_kind_for_instantiation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal93());
}

FunctionDeclTemplatedKind FunctionDecl::templated_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<FunctionDeclTemplatedKind>(self.getVal127());
}

bool FunctionDecl::has_implicit_return_zero(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
}

bool FunctionDecl::has_inherited_prototype(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal95();
}

bool FunctionDecl::has_one_parameter_or_default_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal96();
}

bool FunctionDecl::has_prototype(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal97();
}

bool FunctionDecl::has_skipped_body(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal98();
}

bool FunctionDecl::has_trivial_body(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal99();
}

bool FunctionDecl::has_written_prototype(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal100();
}

bool FunctionDecl::instantiation_is_pending(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal101();
}

bool FunctionDecl::is_cpu_dispatch_multi_version(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal102();
}

bool FunctionDecl::is_cpu_specific_multi_version(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal103();
}

bool FunctionDecl::is_consteval(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal104();
}

bool FunctionDecl::is_constexpr(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal105();
}

bool FunctionDecl::is_constexpr_specified(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal106();
}

bool FunctionDecl::is_defaulted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal107();
}

bool FunctionDecl::is_deleted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal108();
}

bool FunctionDecl::is_deleted_as_written(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal109();
}

bool FunctionDecl::is_destroying_operator_delete(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal110();
}

bool FunctionDecl::is_explicitly_defaulted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal111();
}

bool FunctionDecl::is_extern_c(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal112();
}

bool FunctionDecl::is_function_template_specialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal113();
}

bool FunctionDecl::is_global(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal114();
}

bool FunctionDecl::is_implicitly_instantiable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal115();
}

bool FunctionDecl::is_in_extern_c_context(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal116();
}

bool FunctionDecl::is_in_extern_cxx_context(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal117();
}

bool FunctionDecl::is_inline_builtin_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal118();
}

bool FunctionDecl::is_inline_specified(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal119();
}

bool FunctionDecl::is_inlined(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal120();
}

bool FunctionDecl::is_late_template_parsed(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal121();
}

bool FunctionDecl::is_msvcrt_entry_point(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal122();
}

bool FunctionDecl::is_main(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal123();
}

bool FunctionDecl::is_multi_version(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal124();
}

bool FunctionDecl::is_no_return(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal125();
}

bool FunctionDecl::is_overloaded_operator(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal126();
}

bool FunctionDecl::is_pure(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal131();
}

bool FunctionDecl::is_replaceable_global_allocation_function(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal132();
}

bool FunctionDecl::is_static(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal133();
}

bool FunctionDecl::is_target_multi_version(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal134();
}

bool FunctionDecl::is_template_instantiation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal135();
}

bool FunctionDecl::is_this_declaration_a_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal136();
}

bool FunctionDecl::is_this_declaration_instantiated_from_a_friend_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal137();
}

bool FunctionDecl::is_trivial(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal144();
}

bool FunctionDecl::is_trivial_for_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal145();
}

bool FunctionDecl::is_user_provided(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal146();
}

bool FunctionDecl::is_variadic(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal147();
}

bool FunctionDecl::is_virtual_as_written(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal148();
}

std::vector<ParmVarDecl> FunctionDecl::parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

bool FunctionDecl::uses_seh_try(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal149();
}

bool FunctionDecl::will_have_body(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal150();
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

RefQualifierKind CXXMethodDecl::reference_qualifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<RefQualifierKind>(self.getVal130());
}

bool CXXMethodDecl::has_inline_body(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal152();
}

bool CXXMethodDecl::is_const(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal153();
}

bool CXXMethodDecl::is_copy_assignment_operator(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal154();
}

bool CXXMethodDecl::is_instance(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal155();
}

bool CXXMethodDecl::is_lambda_static_invoker(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal156();
}

bool CXXMethodDecl::is_move_assignment_operator(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal157();
}

bool CXXMethodDecl::is_virtual(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal158();
}

bool CXXMethodDecl::is_volatile(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal159();
}

std::vector<CXXMethodDecl> CXXMethodDecl::overridden_methods(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal34();
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

bool CXXConversionDecl::is_explicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal161();
}

bool CXXConversionDecl::is_lambda_to_block_pointer_conversion(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal162();
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

bool CXXConstructorDecl::is_default_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal161();
}

bool CXXConstructorDecl::is_delegating_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal162();
}

bool CXXConstructorDecl::is_explicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal163();
}

bool CXXConstructorDecl::is_inheriting_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal164();
}

bool CXXConstructorDecl::is_specialization_copying_object(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal165();
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

bool CXXDeductionGuideDecl::is_copy_deduction_candidate(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal152();
}

bool CXXDeductionGuideDecl::is_explicit(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal153();
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

InClassInitStyle FieldDecl::in_class_initializer_style(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<InClassInitStyle>(self.getVal83());
}

bool FieldDecl::has_captured_vla_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool FieldDecl::has_in_class_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

bool FieldDecl::is_anonymous_struct_or_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
}

bool FieldDecl::is_bit_field(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal91();
}

bool FieldDecl::is_mutable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
}

bool FieldDecl::is_unnamed_bitfield(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal95();
}

bool FieldDecl::is_zero_length_bit_field(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal96();
}

bool FieldDecl::is_zero_size(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal97();
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

ObjCIvarDeclAccessControl ObjCIvarDecl::access_control(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCIvarDeclAccessControl>(self.getVal85());
}

ObjCIvarDeclAccessControl ObjCIvarDecl::canonical_access_control(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCIvarDeclAccessControl>(self.getVal86());
}

bool ObjCIvarDecl::synthesize(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal98();
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

bool ConstructorUsingShadowDecl::constructs_virtual_base(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::constructed_base_class_shadow_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal81()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal25());
    return ConstructorUsingShadowDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<ConstructorUsingShadowDecl> ConstructorUsingShadowDecl::nominated_base_class_shadow_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal82()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal69());
    return ConstructorUsingShadowDecl::from(fragment->DeclFor(fragment, id));
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

std::vector<NamedDecl> UsingPackDecl::expansions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

Token UsingDirectiveDecl::identifier_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token UsingDirectiveDecl::namespace_key_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token UsingDirectiveDecl::using_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
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

bool TemplateTypeParmDecl::default_argument_was_inherited(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

Token TemplateTypeParmDecl::default_argument_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool TemplateTypeParmDecl::has_default_argument(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool TemplateTypeParmDecl::has_type_constraint(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

bool TemplateTypeParmDecl::is_expanded_parameter_pack(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
}

bool TemplateTypeParmDecl::is_pack_expansion(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal91();
}

bool TemplateTypeParmDecl::was_declared_with_typename(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
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

TokenRange TagDecl::brace_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal20(), self.getVal21());
}

std::optional<TagDecl> TagDecl::definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal73()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal22());
    return TagDecl::from(fragment->DeclFor(fragment, id));
  }
}

Token TagDecl::inner_token_start(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

Token TagDecl::outer_token_start(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

TagTypeKind TagDecl::tag_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TagTypeKind>(self.getVal83());
}

std::optional<TypedefNameDecl> TagDecl::typedef_name_for_anonymous_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal81()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal26());
    return TypedefNameDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool TagDecl::has_name_for_linkage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

bool TagDecl::is_being_defined(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
}

bool TagDecl::is_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal91();
}

bool TagDecl::is_complete_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
}

bool TagDecl::is_complete_definition_required(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal95();
}

bool TagDecl::is_dependent_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal96();
}

bool TagDecl::is_embedded_in_declarator(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal97();
}

bool TagDecl::is_enum(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal98();
}

bool TagDecl::is_free_standing(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal99();
}

bool TagDecl::is_interface(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal100();
}

bool TagDecl::is_struct(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal101();
}

bool TagDecl::is_this_declaration_a_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal102();
}

bool TagDecl::is_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal103();
}

bool TagDecl::may_have_out_of_date_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal104();
}

std::vector<TemplateParameterList> TagDecl::template_parameter_lists(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal63();
  std::vector<TemplateParameterList> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
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

bool RecordDecl::can_pass_in_registers(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal105();
}

std::vector<FieldDecl> RecordDecl::fields(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal33();
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

std::optional<FieldDecl> RecordDecl::find_first_named_data_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal106()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal69());
    return FieldDecl::from(fragment->DeclFor(fragment, id));
  }
}

RecordDeclArgPassingKind RecordDecl::argument_passing_restrictions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<RecordDeclArgPassingKind>(self.getVal85());
}

bool RecordDecl::has_flexible_array_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal107();
}

bool RecordDecl::has_loaded_fields_from_external_storage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal108();
}

bool RecordDecl::has_non_trivial_to_primitive_copy_c_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal109();
}

bool RecordDecl::has_non_trivial_to_primitive_default_initialize_c_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal110();
}

bool RecordDecl::has_non_trivial_to_primitive_destruct_c_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal111();
}

bool RecordDecl::has_object_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal112();
}

bool RecordDecl::has_volatile_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal113();
}

bool RecordDecl::is_anonymous_struct_or_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal114();
}

bool RecordDecl::is_captured_record(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal115();
}

bool RecordDecl::is_injected_class_name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal116();
}

bool RecordDecl::is_lambda(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal117();
}

bool RecordDecl::is_ms_struct(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal118();
}

bool RecordDecl::is_non_trivial_to_primitive_copy(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal119();
}

bool RecordDecl::is_non_trivial_to_primitive_default_initialize(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal120();
}

bool RecordDecl::is_non_trivial_to_primitive_destroy(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal121();
}

bool RecordDecl::is_or_contains_union(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal122();
}

bool RecordDecl::is_parameter_destroyed_in_callee(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal123();
}

bool RecordDecl::may_insert_extra_padding(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal124();
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

bool CXXRecordDecl::allow_const_default_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal125();
}

std::vector<CXXBaseSpecifier> CXXRecordDecl::bases(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal138();
  std::vector<CXXBaseSpecifier> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

MSInheritanceModel CXXRecordDecl::calculate_inheritance_model(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<MSInheritanceModel>(self.getVal86());
}

std::vector<CXXConstructorDecl> CXXRecordDecl::constructors(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal34();
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

bool CXXRecordDecl::defaulted_copy_constructor_is_deleted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal126();
}

bool CXXRecordDecl::defaulted_default_constructor_is_constexpr(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal131();
}

bool CXXRecordDecl::defaulted_destructor_is_constexpr(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal132();
}

bool CXXRecordDecl::defaulted_destructor_is_deleted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal133();
}

bool CXXRecordDecl::defaulted_move_constructor_is_deleted(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal134();
}

std::vector<FriendDecl> CXXRecordDecl::friends(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal36();
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

std::optional<CXXDestructorDecl> CXXRecordDecl::destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal135()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal74());
    return CXXDestructorDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<TemplateParameterList> CXXRecordDecl::generic_lambda_template_parameter_list(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal136()) {
    return std::nullopt;
  } else {
    return TemplateParameterList(fragment, self.getVal1());
  }
}

std::optional<CXXRecordDecl> CXXRecordDecl::instantiated_from_member_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal137()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal90());
    return CXXRecordDecl::from(fragment->DeclFor(fragment, id));
  }
}

std::optional<CXXMethodDecl> CXXRecordDecl::lambda_call_operator(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal144()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal128());
    return CXXMethodDecl::from(fragment->DeclFor(fragment, id));
  }
}

LambdaCaptureDefault CXXRecordDecl::lambda_capture_default(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<LambdaCaptureDefault>(self.getVal87());
}

std::vector<NamedDecl> CXXRecordDecl::lambda_explicit_template_parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal37();
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

MSInheritanceModel CXXRecordDecl::ms_inheritance_model(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<MSInheritanceModel>(self.getVal88());
}

MSVtorDispMode CXXRecordDecl::ms_vtor_disp_mode(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<MSVtorDispMode>(self.getVal89());
}

std::optional<CXXRecordDecl> CXXRecordDecl::template_instantiation_pattern(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal145()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal140());
    return CXXRecordDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind CXXRecordDecl::template_specialization_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal92());
}

bool CXXRecordDecl::has_any_dependent_bases(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal146();
}

bool CXXRecordDecl::has_constexpr_default_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal147();
}

bool CXXRecordDecl::has_constexpr_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal148();
}

bool CXXRecordDecl::has_constexpr_non_copy_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal149();
}

bool CXXRecordDecl::has_copy_assignment_with_const_parameter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal150();
}

bool CXXRecordDecl::has_copy_constructor_with_const_parameter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal152();
}

bool CXXRecordDecl::has_default_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal153();
}

bool CXXRecordDecl::has_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal154();
}

bool CXXRecordDecl::has_direct_fields(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal155();
}

bool CXXRecordDecl::has_friends(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal156();
}

bool CXXRecordDecl::has_in_class_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal157();
}

bool CXXRecordDecl::has_inherited_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal158();
}

bool CXXRecordDecl::has_inherited_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal159();
}

bool CXXRecordDecl::has_irrelevant_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal161();
}

bool CXXRecordDecl::has_known_lambda_internal_linkage(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal162();
}

bool CXXRecordDecl::has_move_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal163();
}

bool CXXRecordDecl::has_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal164();
}

bool CXXRecordDecl::has_mutable_fields(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal165();
}

bool CXXRecordDecl::has_non_literal_type_fields_or_bases(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal166();
}

bool CXXRecordDecl::has_non_trivial_copy_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal167();
}

bool CXXRecordDecl::has_non_trivial_copy_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal168();
}

bool CXXRecordDecl::has_non_trivial_copy_constructor_for_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal169();
}

bool CXXRecordDecl::has_non_trivial_default_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal170();
}

bool CXXRecordDecl::has_non_trivial_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal171();
}

bool CXXRecordDecl::has_non_trivial_destructor_for_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal172();
}

bool CXXRecordDecl::has_non_trivial_move_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal173();
}

bool CXXRecordDecl::has_non_trivial_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal174();
}

bool CXXRecordDecl::has_non_trivial_move_constructor_for_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal175();
}

bool CXXRecordDecl::has_private_fields(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal176();
}

bool CXXRecordDecl::has_protected_fields(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal177();
}

bool CXXRecordDecl::has_simple_copy_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal178();
}

bool CXXRecordDecl::has_simple_copy_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal179();
}

bool CXXRecordDecl::has_simple_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal180();
}

bool CXXRecordDecl::has_simple_move_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal181();
}

bool CXXRecordDecl::has_simple_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal182();
}

bool CXXRecordDecl::has_trivial_copy_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal183();
}

bool CXXRecordDecl::has_trivial_copy_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal184();
}

bool CXXRecordDecl::has_trivial_copy_constructor_for_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal185();
}

bool CXXRecordDecl::has_trivial_default_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal186();
}

bool CXXRecordDecl::has_trivial_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal187();
}

bool CXXRecordDecl::has_trivial_destructor_for_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal188();
}

bool CXXRecordDecl::has_trivial_move_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal189();
}

bool CXXRecordDecl::has_trivial_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal190();
}

bool CXXRecordDecl::has_trivial_move_constructor_for_call(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal191();
}

bool CXXRecordDecl::has_uninitialized_reference_member(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal192();
}

bool CXXRecordDecl::has_user_declared_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal193();
}

bool CXXRecordDecl::has_user_declared_copy_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal194();
}

bool CXXRecordDecl::has_user_declared_copy_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal195();
}

bool CXXRecordDecl::has_user_declared_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal196();
}

bool CXXRecordDecl::has_user_declared_move_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal197();
}

bool CXXRecordDecl::has_user_declared_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal198();
}

bool CXXRecordDecl::has_user_declared_move_operation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal199();
}

bool CXXRecordDecl::has_user_provided_default_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal200();
}

bool CXXRecordDecl::has_variant_members(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal201();
}

bool CXXRecordDecl::implicit_copy_assignment_has_const_parameter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal202();
}

bool CXXRecordDecl::implicit_copy_constructor_has_const_parameter(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal203();
}

bool CXXRecordDecl::is_abstract(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal204();
}

bool CXXRecordDecl::is_aggregate(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal205();
}

bool CXXRecordDecl::is_any_destructor_no_return(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal206();
}

bool CXXRecordDecl::is_c_like(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal207();
}

bool CXXRecordDecl::is_cxx11_standard_layout(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal208();
}

bool CXXRecordDecl::is_dependent_lambda(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal209();
}

bool CXXRecordDecl::is_dynamic_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal210();
}

bool CXXRecordDecl::is_effectively_final(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal211();
}

bool CXXRecordDecl::is_empty(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal212();
}

bool CXXRecordDecl::is_generic_lambda(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal213();
}

bool CXXRecordDecl::is_interface_like(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal214();
}

bool CXXRecordDecl::is_literal(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal215();
}

std::optional<FunctionDecl> CXXRecordDecl::is_local_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal216()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal141());
    return FunctionDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool CXXRecordDecl::is_pod(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal217();
}

bool CXXRecordDecl::is_parsing_base_specifiers(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal218();
}

bool CXXRecordDecl::is_polymorphic(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal219();
}

bool CXXRecordDecl::is_standard_layout(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal220();
}

bool CXXRecordDecl::is_structural(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal221();
}

bool CXXRecordDecl::is_trivial(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal222();
}

bool CXXRecordDecl::is_trivially_copyable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal223();
}

bool CXXRecordDecl::lambda_is_default_constructible_and_assignable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal224();
}

bool CXXRecordDecl::may_be_abstract(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal225();
}

bool CXXRecordDecl::may_be_dynamic_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal226();
}

bool CXXRecordDecl::may_be_non_dynamic_class(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal227();
}

std::vector<CXXMethodDecl> CXXRecordDecl::methods(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal228();
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

bool CXXRecordDecl::needs_implicit_copy_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal229();
}

bool CXXRecordDecl::needs_implicit_copy_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal230();
}

bool CXXRecordDecl::needs_implicit_default_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal231();
}

bool CXXRecordDecl::needs_implicit_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal232();
}

bool CXXRecordDecl::needs_implicit_move_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal233();
}

bool CXXRecordDecl::needs_implicit_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal234();
}

bool CXXRecordDecl::needs_overload_resolution_for_copy_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal235();
}

bool CXXRecordDecl::needs_overload_resolution_for_copy_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal236();
}

bool CXXRecordDecl::needs_overload_resolution_for_destructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal237();
}

bool CXXRecordDecl::needs_overload_resolution_for_move_assignment(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal238();
}

bool CXXRecordDecl::needs_overload_resolution_for_move_constructor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal239();
}

bool CXXRecordDecl::null_field_offset_is_zero(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal240();
}

std::vector<CXXBaseSpecifier> CXXRecordDecl::virtual_bases(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal139();
  std::vector<CXXBaseSpecifier> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
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

Token ClassTemplateSpecializationDecl::extern_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal142());
}

Token ClassTemplateSpecializationDecl::point_of_instantiation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal143());
}

TemplateSpecializationKind ClassTemplateSpecializationDecl::specialization_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal93());
}

std::vector<TemplateArgument> ClassTemplateSpecializationDecl::template_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal241();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::vector<TemplateArgument> ClassTemplateSpecializationDecl::template_instantiation_arguments(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal242();
  std::vector<TemplateArgument> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

Token ClassTemplateSpecializationDecl::template_keyword_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal151());
}

bool ClassTemplateSpecializationDecl::is_class_scope_explicit_specialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal243();
}

bool ClassTemplateSpecializationDecl::is_explicit_instantiation_or_specialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal244();
}

bool ClassTemplateSpecializationDecl::is_explicit_specialization(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal245();
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

std::vector<EnumConstantDecl> EnumDecl::enumerators(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal33();
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

std::optional<EnumDecl> EnumDecl::instantiated_from_member_enum(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal105()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal69());
    return EnumDecl::from(fragment->DeclFor(fragment, id));
  }
}

TokenRange EnumDecl::integer_type_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal74(), self.getVal90());
}

std::optional<EnumDecl> EnumDecl::template_instantiation_pattern(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal106()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal128());
    return EnumDecl::from(fragment->DeclFor(fragment, id));
  }
}

TemplateSpecializationKind EnumDecl::template_specialization_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<TemplateSpecializationKind>(self.getVal85());
}

bool EnumDecl::is_closed(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal107();
}

bool EnumDecl::is_closed_flag(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal108();
}

bool EnumDecl::is_closed_non_flag(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal109();
}

bool EnumDecl::is_complete(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal110();
}

bool EnumDecl::is_fixed(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal111();
}

bool EnumDecl::is_scoped(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal112();
}

bool EnumDecl::is_scoped_using_class_tag(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal113();
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

Token UnresolvedUsingTypenameDecl::ellipsis_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token UnresolvedUsingTypenameDecl::typename_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

Token UnresolvedUsingTypenameDecl::using_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool UnresolvedUsingTypenameDecl::is_pack_expansion(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
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

std::optional<TagDecl> TypedefNameDecl::anonymous_declaration_with_typedef_name(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal73()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal20());
    return TagDecl::from(fragment->DeclFor(fragment, id));
  }
}

bool TypedefNameDecl::is_moded(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool TypedefNameDecl::is_transparent_tag(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
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

std::optional<TypeAliasTemplateDecl> TypeAliasDecl::described_alias_template(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  if (!self.getVal84()) {
    return std::nullopt;
  } else {
    EntityId id(self.getVal21());
    return TypeAliasTemplateDecl::from(fragment->DeclFor(fragment, id));
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

Token ObjCTypeParamDecl::colon_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

ObjCTypeParamVariance ObjCTypeParamDecl::variance(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCTypeParamVariance>(self.getVal83());
}

Token ObjCTypeParamDecl::variance_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

bool ObjCTypeParamDecl::has_explicit_bound(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
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

bool ConceptDecl::is_type_concept(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
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

Token ObjCPropertyDecl::at_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token ObjCPropertyDecl::getter_name_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token ObjCPropertyDecl::l_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

ObjCPropertyDeclPropertyControl ObjCPropertyDecl::property_implementation(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCPropertyDeclPropertyControl>(self.getVal83());
}

ObjCPropertyQueryKind ObjCPropertyDecl::query_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCPropertyQueryKind>(self.getVal85());
}

ObjCPropertyDeclSetterKind ObjCPropertyDecl::setter_kind(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCPropertyDeclSetterKind>(self.getVal86());
}

Token ObjCPropertyDecl::setter_name_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal69());
}

bool ObjCPropertyDecl::is_atomic(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

bool ObjCPropertyDecl::is_class_property(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool ObjCPropertyDecl::is_direct_property(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

bool ObjCPropertyDecl::is_instance_property(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
}

bool ObjCPropertyDecl::is_optional(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal91();
}

bool ObjCPropertyDecl::is_read_only(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
}

bool ObjCPropertyDecl::is_retaining(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal95();
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

bool ObjCMethodDecl::defined_in_ns_object(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

Token ObjCMethodDecl::declarator_end_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

ObjCMethodDeclImplementationControl ObjCMethodDecl::implementation_control(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCMethodDeclImplementationControl>(self.getVal83());
}

ObjCMethodFamily ObjCMethodDecl::method_family(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<ObjCMethodFamily>(self.getVal85());
}

DeclObjCDeclQualifier ObjCMethodDecl::obj_c_decl_qualifier(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<DeclObjCDeclQualifier>(self.getVal86());
}

TokenRange ObjCMethodDecl::return_type_source_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal26(), self.getVal69());
}

Token ObjCMethodDecl::selector_start_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal74());
}

bool ObjCMethodDecl::has_redeclaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool ObjCMethodDecl::has_related_result_type(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

bool ObjCMethodDecl::has_skipped_body(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
}

bool ObjCMethodDecl::is_class_method(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal91();
}

bool ObjCMethodDecl::is_defined(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
}

bool ObjCMethodDecl::is_designated_initializer_for_the_interface(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal95();
}

bool ObjCMethodDecl::is_direct_method(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal96();
}

bool ObjCMethodDecl::is_instance_method(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal97();
}

bool ObjCMethodDecl::is_optional(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal98();
}

bool ObjCMethodDecl::is_overriding(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal99();
}

bool ObjCMethodDecl::is_property_accessor(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal100();
}

bool ObjCMethodDecl::is_redeclaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal101();
}

bool ObjCMethodDecl::is_synthesized_accessor_stub(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal102();
}

bool ObjCMethodDecl::is_this_declaration_a_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal103();
}

bool ObjCMethodDecl::is_this_declaration_a_designated_initializer(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal104();
}

bool ObjCMethodDecl::is_variadic(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal105();
}

std::vector<ParmVarDecl> ObjCMethodDecl::parameters(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::vector<Token> ObjCMethodDecl::selector_tokens(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal33();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
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

std::vector<ObjCMethodDecl> ObjCContainerDecl::class_methods(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
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

std::vector<ObjCPropertyDecl> ObjCContainerDecl::class_properties(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal33();
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

TokenRange ObjCContainerDecl::at_end_range(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenRangeFor(fragment, self.getVal20(), self.getVal21());
}

Token ObjCContainerDecl::at_start_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

std::vector<ObjCMethodDecl> ObjCContainerDecl::instance_methods(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal34();
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

std::vector<ObjCPropertyDecl> ObjCContainerDecl::instance_properties(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal36();
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

std::vector<ObjCMethodDecl> ObjCContainerDecl::methods(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal37();
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

std::vector<ObjCPropertyDecl> ObjCContainerDecl::properties(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal228();
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

bool ObjCCategoryDecl::is_class_extension(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

Token ObjCCategoryDecl::category_name_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

Token ObjCCategoryDecl::instance_variable_l_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal69());
}

Token ObjCCategoryDecl::instance_variable_r_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal74());
}

std::vector<ObjCIvarDecl> ObjCCategoryDecl::instance_variables(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal247();
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

std::vector<Token> ObjCCategoryDecl::protocol_tokens(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal248();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::vector<ObjCProtocolDecl> ObjCCategoryDecl::protocols(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal249();
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

std::string_view ObjCProtocolDecl::obj_c_runtime_name_as_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal80();
  return std::string_view(data.cStr(), data.size());
}

bool ObjCProtocolDecl::has_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

bool ObjCProtocolDecl::is_non_runtime_protocol(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool ObjCProtocolDecl::is_this_declaration_a_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

std::vector<Token> ObjCProtocolDecl::protocol_tokens(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal247();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::vector<ObjCProtocolDecl> ObjCProtocolDecl::protocols(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal248();
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

std::vector<ObjCProtocolDecl> ObjCInterfaceDecl::all_referenced_protocols(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal247();
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

bool ObjCInterfaceDecl::declares_or_inherits_designated_initializers(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

Token ObjCInterfaceDecl::end_of_definition_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

std::string_view ObjCInterfaceDecl::obj_c_runtime_name_as_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal80();
  return std::string_view(data.cStr(), data.size());
}

Token ObjCInterfaceDecl::super_class_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal90());
}

bool ObjCInterfaceDecl::has_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

bool ObjCInterfaceDecl::has_designated_initializers(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal82();
}

bool ObjCInterfaceDecl::is_arc_weakref_unavailable(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal84();
}

bool ObjCInterfaceDecl::is_implicit_interface_declaration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal91();
}

bool ObjCInterfaceDecl::is_this_declaration_a_definition(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal94();
}

std::vector<ObjCIvarDecl> ObjCInterfaceDecl::instance_variables(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal248();
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

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::known_categories(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal249();
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

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::known_extensions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal250();
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

std::vector<Token> ObjCInterfaceDecl::protocol_tokens(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal251();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::vector<ObjCProtocolDecl> ObjCInterfaceDecl::protocols(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
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

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::visible_categories(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal253();
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

std::vector<ObjCCategoryDecl> ObjCInterfaceDecl::visible_extensions(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
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

std::vector<ObjCPropertyImplDecl> ObjCImplDecl::property_implementations(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal247();
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

Token ObjCCategoryImplDecl::category_name_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
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

Token ObjCImplementationDecl::instance_variable_l_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal25());
}

Token ObjCImplementationDecl::instance_variable_r_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal26());
}

std::string_view ObjCImplementationDecl::obj_c_runtime_name_as_string(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  capnp::Text::Reader data = self.getVal80();
  return std::string_view(data.cStr(), data.size());
}

Token ObjCImplementationDecl::super_class_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal74());
}

bool ObjCImplementationDecl::has_destructors(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal73();
}

bool ObjCImplementationDecl::has_non_zero_constructors(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal81();
}

std::vector<ObjCIvarDecl> ObjCImplementationDecl::instance_variables(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal248();
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

Token NamespaceAliasDecl::alias_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

Token NamespaceAliasDecl::namespace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal22());
}

Token NamespaceAliasDecl::target_name_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal24());
}

std::optional<LinkageSpecDecl> LinkageSpecDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::LINKAGE_SPEC:
      return reinterpret_cast<const LinkageSpecDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<LifetimeExtendedTemporaryDecl> LifetimeExtendedTemporaryDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::LIFETIME_EXTENDED_TEMPORARY:
      return reinterpret_cast<const LifetimeExtendedTemporaryDecl &>(parent);
    default: return std::nullopt;
  }
}

StorageDuration LifetimeExtendedTemporaryDecl::storage_duration(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return static_cast<StorageDuration>(self.getVal76());
}

std::optional<ImportDecl> ImportDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::IMPORT:
      return reinterpret_cast<const ImportDecl &>(parent);
    default: return std::nullopt;
  }
}

std::vector<Token> ImportDecl::identifier_tokens(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal10();
  std::vector<Token> vec;
  vec.reserve(list.size());
  for (auto v : list) {
    EntityId id(v);
    vec.emplace_back(fragment->TokenFor(fragment, id));
  }
  return vec;
}

std::optional<FriendTemplateDecl> FriendTemplateDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FRIEND_TEMPLATE:
      return reinterpret_cast<const FriendTemplateDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<FriendDecl> FriendDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FRIEND:
      return reinterpret_cast<const FriendDecl &>(parent);
    default: return std::nullopt;
  }
}

Token FriendDecl::friend_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool FriendDecl::is_unsupported_friend(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
}

std::vector<TemplateParameterList> FriendDecl::friend_type_template_parameter_lists(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  auto list = self.getVal63();
  std::vector<TemplateParameterList> vec;
  vec.reserve(list.size());
  for (auto v : list) {
vec.emplace_back(fragment, v);
  }
  return vec;
}

std::optional<FileScopeAsmDecl> FileScopeAsmDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::FILE_SCOPE_ASM:
      return reinterpret_cast<const FileScopeAsmDecl &>(parent);
    default: return std::nullopt;
  }
}

Token FileScopeAsmDecl::assembly_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token FileScopeAsmDecl::r_paren_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal21());
}

std::optional<ExternCContextDecl> ExternCContextDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::EXTERN_C_CONTEXT:
      return reinterpret_cast<const ExternCContextDecl &>(parent);
    default: return std::nullopt;
  }
}

std::optional<ExportDecl> ExportDecl::from(const Decl &parent) {
  switch (parent.kind()) {
    case mx::DeclKind::EXPORT:
      return reinterpret_cast<const ExportDecl &>(parent);
    default: return std::nullopt;
  }
}

Token ExportDecl::export_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal19());
}

Token ExportDecl::r_brace_token(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return fragment->TokenFor(fragment, self.getVal20());
}

bool ExportDecl::has_braces(void) const noexcept {
  EntityListReader entities = fragment->Entities();
  mx::ast::Entity::Reader self = entities[offset];
  return self.getVal62();
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
