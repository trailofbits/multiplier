// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/TypeKind.h>

namespace mx {

const char *EnumeratorName(ir::TypeKind kind) {
  switch (kind) {
    default: return "UNKNOWN";
    case ir::TypeKind::BUILTIN_SHAPED: return "BUILTIN_SHAPED";
    case ir::TypeKind::BUILTIN_FLOAT: return "BUILTIN_FLOAT";
    case ir::TypeKind::BUILTIN_COMPLEX: return "BUILTIN_COMPLEX";
    case ir::TypeKind::BUILTIN_FLOAT8_E5_M2: return "BUILTIN_FLOAT8_E5_M2";
    case ir::TypeKind::BUILTIN_FLOAT8_E4_M3_FN: return "BUILTIN_FLOAT8_E4_M3_FN";
    case ir::TypeKind::BUILTIN_FLOAT8_E5_M2_FNUZ: return "BUILTIN_FLOAT8_E5_M2_FNUZ";
    case ir::TypeKind::BUILTIN_FLOAT8_E4_M3_FNUZ: return "BUILTIN_FLOAT8_E4_M3_FNUZ";
    case ir::TypeKind::BUILTIN_FLOAT8_E4_M3_B11_FNUZ: return "BUILTIN_FLOAT8_E4_M3_B11_FNUZ";
    case ir::TypeKind::BUILTIN_B_FLOAT16: return "BUILTIN_B_FLOAT16";
    case ir::TypeKind::BUILTIN_FLOAT16: return "BUILTIN_FLOAT16";
    case ir::TypeKind::BUILTIN_FLOAT_TF32: return "BUILTIN_FLOAT_TF32";
    case ir::TypeKind::BUILTIN_FLOAT32: return "BUILTIN_FLOAT32";
    case ir::TypeKind::BUILTIN_FLOAT64: return "BUILTIN_FLOAT64";
    case ir::TypeKind::BUILTIN_FLOAT80: return "BUILTIN_FLOAT80";
    case ir::TypeKind::BUILTIN_FLOAT128: return "BUILTIN_FLOAT128";
    case ir::TypeKind::BUILTIN_FUNCTION: return "BUILTIN_FUNCTION";
    case ir::TypeKind::BUILTIN_INDEX: return "BUILTIN_INDEX";
    case ir::TypeKind::BUILTIN_INTEGER: return "BUILTIN_INTEGER";
    case ir::TypeKind::BUILTIN_MEM_REF: return "BUILTIN_MEM_REF";
    case ir::TypeKind::BUILTIN_NONE: return "BUILTIN_NONE";
    case ir::TypeKind::BUILTIN_OPAQUE: return "BUILTIN_OPAQUE";
    case ir::TypeKind::BUILTIN_RANKED_TENSOR: return "BUILTIN_RANKED_TENSOR";
    case ir::TypeKind::BUILTIN_TUPLE: return "BUILTIN_TUPLE";
    case ir::TypeKind::BUILTIN_UNRANKED_MEM_REF: return "BUILTIN_UNRANKED_MEM_REF";
    case ir::TypeKind::BUILTIN_UNRANKED_TENSOR: return "BUILTIN_UNRANKED_TENSOR";
    case ir::TypeKind::BUILTIN_VECTOR: return "BUILTIN_VECTOR";
    case ir::TypeKind::LLVM_ARRAY: return "LLVM_ARRAY";
    case ir::TypeKind::LLVM_FUNCTION: return "LLVM_FUNCTION";
    case ir::TypeKind::LLVM_POINTER: return "LLVM_POINTER";
    case ir::TypeKind::LLVM_FIXED_VECTOR: return "LLVM_FIXED_VECTOR";
    case ir::TypeKind::LLVM_SCALABLE_VECTOR: return "LLVM_SCALABLE_VECTOR";
    case ir::TypeKind::LLVM_TARGET_EXT: return "LLVM_TARGET_EXT";
    case ir::TypeKind::HL_RECORD: return "HL_RECORD";
    case ir::TypeKind::HL_ENUM: return "HL_ENUM";
    case ir::TypeKind::HL_TYPEDEF: return "HL_TYPEDEF";
    case ir::TypeKind::HL_ELABORATED: return "HL_ELABORATED";
    case ir::TypeKind::HL_LABEL: return "HL_LABEL";
    case ir::TypeKind::HL_PAREN: return "HL_PAREN";
    case ir::TypeKind::HL_L_VALUE: return "HL_L_VALUE";
    case ir::TypeKind::HL_R_VALUE: return "HL_R_VALUE";
    case ir::TypeKind::HL_VOID: return "HL_VOID";
    case ir::TypeKind::HL_BOOL: return "HL_BOOL";
    case ir::TypeKind::HL_CHAR: return "HL_CHAR";
    case ir::TypeKind::HL_SHORT: return "HL_SHORT";
    case ir::TypeKind::HL_INT: return "HL_INT";
    case ir::TypeKind::HL_LONG: return "HL_LONG";
    case ir::TypeKind::HL_LONG_LONG: return "HL_LONG_LONG";
    case ir::TypeKind::HL_INT128: return "HL_INT128";
    case ir::TypeKind::HL_HALF: return "HL_HALF";
    case ir::TypeKind::HL_B_FLOAT16: return "HL_B_FLOAT16";
    case ir::TypeKind::HL_FLOAT: return "HL_FLOAT";
    case ir::TypeKind::HL_DOUBLE: return "HL_DOUBLE";
    case ir::TypeKind::HL_LONG_DOUBLE: return "HL_LONG_DOUBLE";
    case ir::TypeKind::HL_FLOAT128: return "HL_FLOAT128";
    case ir::TypeKind::HL_COMPLEX: return "HL_COMPLEX";
    case ir::TypeKind::HL_POINTER: return "HL_POINTER";
    case ir::TypeKind::HL_ARRAY: return "HL_ARRAY";
    case ir::TypeKind::HL_VECTOR: return "HL_VECTOR";
    case ir::TypeKind::HL_DECAYED: return "HL_DECAYED";
    case ir::TypeKind::HL_ATTRIBUTED: return "HL_ATTRIBUTED";
    case ir::TypeKind::HL_ADJUSTED: return "HL_ADJUSTED";
    case ir::TypeKind::HL_REFERENCE: return "HL_REFERENCE";
    case ir::TypeKind::HL_TYPE_OF_EXPR: return "HL_TYPE_OF_EXPR";
    case ir::TypeKind::HL_TYPE_OF_TYPE: return "HL_TYPE_OF_TYPE";
    case ir::TypeKind::CORE_FUNCTION: return "CORE_FUNCTION";
    case ir::TypeKind::UNSUP_UNSUPPORTED: return "UNSUP_UNSUPPORTED";
  }
}

bool IsBuiltinTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::TypeKind::BUILTIN_SHAPED:
    case mx::ir::TypeKind::BUILTIN_FLOAT:
    case mx::ir::TypeKind::BUILTIN_COMPLEX:
    case mx::ir::TypeKind::BUILTIN_FLOAT8_E5_M2:
    case mx::ir::TypeKind::BUILTIN_FLOAT8_E4_M3_FN:
    case mx::ir::TypeKind::BUILTIN_FLOAT8_E5_M2_FNUZ:
    case mx::ir::TypeKind::BUILTIN_FLOAT8_E4_M3_FNUZ:
    case mx::ir::TypeKind::BUILTIN_FLOAT8_E4_M3_B11_FNUZ:
    case mx::ir::TypeKind::BUILTIN_B_FLOAT16:
    case mx::ir::TypeKind::BUILTIN_FLOAT16:
    case mx::ir::TypeKind::BUILTIN_FLOAT_TF32:
    case mx::ir::TypeKind::BUILTIN_FLOAT32:
    case mx::ir::TypeKind::BUILTIN_FLOAT64:
    case mx::ir::TypeKind::BUILTIN_FLOAT80:
    case mx::ir::TypeKind::BUILTIN_FLOAT128:
    case mx::ir::TypeKind::BUILTIN_FUNCTION:
    case mx::ir::TypeKind::BUILTIN_INDEX:
    case mx::ir::TypeKind::BUILTIN_INTEGER:
    case mx::ir::TypeKind::BUILTIN_MEM_REF:
    case mx::ir::TypeKind::BUILTIN_NONE:
    case mx::ir::TypeKind::BUILTIN_OPAQUE:
    case mx::ir::TypeKind::BUILTIN_RANKED_TENSOR:
    case mx::ir::TypeKind::BUILTIN_TUPLE:
    case mx::ir::TypeKind::BUILTIN_UNRANKED_MEM_REF:
    case mx::ir::TypeKind::BUILTIN_UNRANKED_TENSOR:
    case mx::ir::TypeKind::BUILTIN_VECTOR:
      return true;
  }
}

bool IsLLVMIRTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::TypeKind::LLVM_ARRAY:
    case mx::ir::TypeKind::LLVM_FUNCTION:
    case mx::ir::TypeKind::LLVM_POINTER:
    case mx::ir::TypeKind::LLVM_FIXED_VECTOR:
    case mx::ir::TypeKind::LLVM_SCALABLE_VECTOR:
    case mx::ir::TypeKind::LLVM_TARGET_EXT:
      return true;
  }
}

bool IsMemRefTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsABITypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsLowLevelTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsHighLevelTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::TypeKind::HL_RECORD:
    case mx::ir::TypeKind::HL_ENUM:
    case mx::ir::TypeKind::HL_TYPEDEF:
    case mx::ir::TypeKind::HL_ELABORATED:
    case mx::ir::TypeKind::HL_LABEL:
    case mx::ir::TypeKind::HL_PAREN:
    case mx::ir::TypeKind::HL_L_VALUE:
    case mx::ir::TypeKind::HL_R_VALUE:
    case mx::ir::TypeKind::HL_VOID:
    case mx::ir::TypeKind::HL_BOOL:
    case mx::ir::TypeKind::HL_CHAR:
    case mx::ir::TypeKind::HL_SHORT:
    case mx::ir::TypeKind::HL_INT:
    case mx::ir::TypeKind::HL_LONG:
    case mx::ir::TypeKind::HL_LONG_LONG:
    case mx::ir::TypeKind::HL_INT128:
    case mx::ir::TypeKind::HL_HALF:
    case mx::ir::TypeKind::HL_B_FLOAT16:
    case mx::ir::TypeKind::HL_FLOAT:
    case mx::ir::TypeKind::HL_DOUBLE:
    case mx::ir::TypeKind::HL_LONG_DOUBLE:
    case mx::ir::TypeKind::HL_FLOAT128:
    case mx::ir::TypeKind::HL_COMPLEX:
    case mx::ir::TypeKind::HL_POINTER:
    case mx::ir::TypeKind::HL_ARRAY:
    case mx::ir::TypeKind::HL_VECTOR:
    case mx::ir::TypeKind::HL_DECAYED:
    case mx::ir::TypeKind::HL_ATTRIBUTED:
    case mx::ir::TypeKind::HL_ADJUSTED:
    case mx::ir::TypeKind::HL_REFERENCE:
    case mx::ir::TypeKind::HL_TYPE_OF_EXPR:
    case mx::ir::TypeKind::HL_TYPE_OF_TYPE:
      return true;
  }
}

bool IsCoreTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::TypeKind::CORE_FUNCTION:
      return true;
  }
}

bool IsMetaTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
  }
}

bool IsUnsupportedTypeKind(ir::TypeKind kind) {
  switch (kind) {
    default:
      return false;
    case mx::ir::TypeKind::UNSUP_UNSUPPORTED:
      return true;
  }
}

}  // namespace mx
