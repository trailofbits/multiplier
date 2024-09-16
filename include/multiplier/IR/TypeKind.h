// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Compiler.h"

namespace mx {
namespace ir {

enum class TypeKind : unsigned {
  UNKNOWN,
  BUILTIN_SHAPED,
  BUILTIN_FLOAT,
  BUILTIN_COMPLEX,
  BUILTIN_FLOAT8_E5_M2,
  BUILTIN_FLOAT8_E4_M3_FN,
  BUILTIN_FLOAT8_E5_M2_FNUZ,
  BUILTIN_FLOAT8_E4_M3_FNUZ,
  BUILTIN_FLOAT8_E4_M3_B11_FNUZ,
  BUILTIN_B_FLOAT16,
  BUILTIN_FLOAT16,
  BUILTIN_FLOAT_TF32,
  BUILTIN_FLOAT32,
  BUILTIN_FLOAT64,
  BUILTIN_FLOAT80,
  BUILTIN_FLOAT128,
  BUILTIN_FUNCTION,
  BUILTIN_INDEX,
  BUILTIN_INTEGER,
  BUILTIN_MEM_REF,
  BUILTIN_NONE,
  BUILTIN_OPAQUE,
  BUILTIN_RANKED_TENSOR,
  BUILTIN_TUPLE,
  BUILTIN_UNRANKED_MEM_REF,
  BUILTIN_UNRANKED_TENSOR,
  BUILTIN_VECTOR,
  LLVM_ARRAY,
  LLVM_FUNCTION,
  LLVM_POINTER,
  LLVM_FIXED_VECTOR,
  LLVM_SCALABLE_VECTOR,
  LLVM_TARGET_EXT,
  HL_RECORD,
  HL_ENUM,
  HL_TYPEDEF,
  HL_ELABORATED,
  HL_LABEL,
  HL_PAREN,
  HL_L_VALUE,
  HL_R_VALUE,
  HL_VOID,
  HL_BOOL,
  HL_CHAR,
  HL_SHORT,
  HL_INT,
  HL_LONG,
  HL_LONG_LONG,
  HL_INT128,
  HL_HALF,
  HL_B_FLOAT16,
  HL_FLOAT,
  HL_DOUBLE,
  HL_LONG_DOUBLE,
  HL_FLOAT128,
  HL_COMPLEX,
  HL_POINTER,
  HL_ARRAY,
  HL_VECTOR,
  HL_DECAYED,
  HL_ATTRIBUTED,
  HL_ADJUSTED,
  HL_REFERENCE,
  HL_TYPE_OF_EXPR,
  HL_TYPE_OF_TYPE,
  HL_AUTO,
  HL_ATOMIC,
  CORE_FUNCTION,
  UNSUP_UNSUPPORTED,
};

}  // namespace ir

inline static const char *EnumerationName(ir::TypeKind) {
  return "TypeKind";
}

inline static constexpr unsigned NumEnumerators(ir::TypeKind) {
  return 68;
}

MX_EXPORT const char *EnumeratorName(ir::TypeKind);

MX_EXPORT bool IsBuiltinTypeKind(ir::TypeKind);

MX_EXPORT bool IsLLVMIRTypeKind(ir::TypeKind);

MX_EXPORT bool IsMemRefTypeKind(ir::TypeKind);

MX_EXPORT bool IsABITypeKind(ir::TypeKind);

MX_EXPORT bool IsLowLevelTypeKind(ir::TypeKind);

MX_EXPORT bool IsHighLevelTypeKind(ir::TypeKind);

MX_EXPORT bool IsCoreTypeKind(ir::TypeKind);

MX_EXPORT bool IsMetaTypeKind(ir::TypeKind);

MX_EXPORT bool IsUnsupportedTypeKind(ir::TypeKind);

}  // namespace mx
