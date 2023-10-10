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
    case ir::TypeKind::LLVMARRAYTYPE: return "LLVMARRAYTYPE";
    case ir::TypeKind::LLVMFIXEDVECTORTYPE: return "LLVMFIXEDVECTORTYPE";
    case ir::TypeKind::LLVMFUNCTIONTYPE: return "LLVMFUNCTIONTYPE";
    case ir::TypeKind::LLVMPOINTERTYPE: return "LLVMPOINTERTYPE";
    case ir::TypeKind::LLVMSCALABLEVECTORTYPE: return "LLVMSCALABLEVECTORTYPE";
    case ir::TypeKind::LLVMVOIDTYPE: return "LLVMVOIDTYPE";
    case ir::TypeKind::LLVMPPCFP128TYPE: return "LLVMPPCFP128TYPE";
    case ir::TypeKind::LLVMX86MMXTYPE: return "LLVMX86MMXTYPE";
    case ir::TypeKind::LLVMTOKENTYPE: return "LLVMTOKENTYPE";
    case ir::TypeKind::LLVMLABELTYPE: return "LLVMLABELTYPE";
    case ir::TypeKind::LLVMMETADATATYPE: return "LLVMMETADATATYPE";
    case ir::TypeKind::LLVMSTRUCTTYPE: return "LLVMSTRUCTTYPE";
    case ir::TypeKind::ADJUSTEDTYPE: return "ADJUSTEDTYPE";
    case ir::TypeKind::ARRAYTYPE: return "ARRAYTYPE";
    case ir::TypeKind::ATTRIBUTEDTYPE: return "ATTRIBUTEDTYPE";
    case ir::TypeKind::BFLOAT16TYPE: return "BFLOAT16TYPE";
    case ir::TypeKind::BOOLTYPE: return "BOOLTYPE";
    case ir::TypeKind::CHARTYPE: return "CHARTYPE";
    case ir::TypeKind::DECAYEDTYPE: return "DECAYEDTYPE";
    case ir::TypeKind::DOUBLETYPE: return "DOUBLETYPE";
    case ir::TypeKind::ELABORATEDTYPE: return "ELABORATEDTYPE";
    case ir::TypeKind::ENUMTYPE: return "ENUMTYPE";
    case ir::TypeKind::FLOAT128TYPE: return "FLOAT128TYPE";
    case ir::TypeKind::FLOATTYPE: return "FLOATTYPE";
    case ir::TypeKind::HALFTYPE: return "HALFTYPE";
    case ir::TypeKind::INT128TYPE: return "INT128TYPE";
    case ir::TypeKind::INTTYPE: return "INTTYPE";
    case ir::TypeKind::LVALUETYPE: return "LVALUETYPE";
    case ir::TypeKind::LABELTYPE: return "LABELTYPE";
    case ir::TypeKind::LONGDOUBLETYPE: return "LONGDOUBLETYPE";
    case ir::TypeKind::LONGLONGTYPE: return "LONGLONGTYPE";
    case ir::TypeKind::LONGTYPE: return "LONGTYPE";
    case ir::TypeKind::PARENTYPE: return "PARENTYPE";
    case ir::TypeKind::POINTERTYPE: return "POINTERTYPE";
    case ir::TypeKind::RVALUETYPE: return "RVALUETYPE";
    case ir::TypeKind::RECORDTYPE: return "RECORDTYPE";
    case ir::TypeKind::REFERENCETYPE: return "REFERENCETYPE";
    case ir::TypeKind::SHORTTYPE: return "SHORTTYPE";
    case ir::TypeKind::TYPEOFEXPRTYPE: return "TYPEOFEXPRTYPE";
    case ir::TypeKind::TYPEOFTYPETYPE: return "TYPEOFTYPETYPE";
    case ir::TypeKind::TYPEDEFTYPE: return "TYPEDEFTYPE";
    case ir::TypeKind::VOIDTYPE: return "VOIDTYPE";
    case ir::TypeKind::UNSUPPORTEDTYPE: return "UNSUPPORTEDTYPE";
  }
}

}  // namespace mx
