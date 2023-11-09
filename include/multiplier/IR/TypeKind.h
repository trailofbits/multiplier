// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

namespace mx {
namespace ir {

enum class TypeKind : unsigned {
  UNKNOWN,
  LLVMARRAYTYPE,
  LLVMFIXEDVECTORTYPE,
  LLVMFUNCTIONTYPE,
  LLVMPOINTERTYPE,
  LLVMSCALABLEVECTORTYPE,
  LLVMTARGETEXTTYPE,
  LLVMVOIDTYPE,
  LLVMPPCFP128TYPE,
  LLVMX86MMXTYPE,
  LLVMTOKENTYPE,
  LLVMLABELTYPE,
  LLVMMETADATATYPE,
  LLVMSTRUCTTYPE,
  ADJUSTEDTYPE,
  ARRAYTYPE,
  ATTRIBUTEDTYPE,
  BFLOAT16TYPE,
  BOOLTYPE,
  CHARTYPE,
  DECAYEDTYPE,
  DOUBLETYPE,
  ELABORATEDTYPE,
  ENUMTYPE,
  FLOAT128TYPE,
  FLOATTYPE,
  HALFTYPE,
  INT128TYPE,
  INTTYPE,
  LVALUETYPE,
  LABELTYPE,
  LONGDOUBLETYPE,
  LONGLONGTYPE,
  LONGTYPE,
  PARENTYPE,
  POINTERTYPE,
  RVALUETYPE,
  RECORDTYPE,
  REFERENCETYPE,
  SHORTTYPE,
  TYPEOFEXPRTYPE,
  TYPEOFTYPETYPE,
  TYPEDEFTYPE,
  VOIDTYPE,
  FUNCTIONTYPE,
  UNSUPPORTEDTYPE,
};

}  // namespace ir

inline static const char *EnumerationName(ir::TypeKind) {
  return "TypeKind";
}

inline static constexpr unsigned NumEnumerators(ir::TypeKind) {
  return 45;
}

const char *EnumeratorName(ir::TypeKind);

}  // namespace mx
