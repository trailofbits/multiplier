// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#define MX_IR_FOR_EACH_MLIR_TYPE(_builtin, _llvm, _scf, _memref, _ll, _hl, _core, _meta, _unsup) \
   _llvm(LLVMArrayType, TypeKind::LLVMARRAYTYPE, mlir::LLVM::LLVMArrayType) \
   _llvm(LLVMFixedVectorType, TypeKind::LLVMFIXEDVECTORTYPE, mlir::LLVM::LLVMFixedVectorType) \
   _llvm(LLVMFunctionType, TypeKind::LLVMFUNCTIONTYPE, mlir::LLVM::LLVMFunctionType) \
   _llvm(LLVMPointerType, TypeKind::LLVMPOINTERTYPE, mlir::LLVM::LLVMPointerType) \
   _llvm(LLVMScalableVectorType, TypeKind::LLVMSCALABLEVECTORTYPE, mlir::LLVM::LLVMScalableVectorType) \
   _llvm(LLVMVoidType, TypeKind::LLVMVOIDTYPE, mlir::LLVM::LLVMVoidType) \
   _llvm(LLVMPPCFP128Type, TypeKind::LLVMPPCFP128TYPE, mlir::LLVM::LLVMPPCFP128Type) \
   _llvm(LLVMX86MMXType, TypeKind::LLVMX86MMXTYPE, mlir::LLVM::LLVMX86MMXType) \
   _llvm(LLVMTokenType, TypeKind::LLVMTOKENTYPE, mlir::LLVM::LLVMTokenType) \
   _llvm(LLVMLabelType, TypeKind::LLVMLABELTYPE, mlir::LLVM::LLVMLabelType) \
   _llvm(LLVMMetadataType, TypeKind::LLVMMETADATATYPE, mlir::LLVM::LLVMMetadataType) \
   _llvm(LLVMStructType, TypeKind::LLVMSTRUCTTYPE, mlir::LLVM::LLVMStructType) \
   _hl(AdjustedType, TypeKind::ADJUSTEDTYPE, vast::hl::AdjustedType) \
   _hl(ArrayType, TypeKind::ARRAYTYPE, vast::hl::ArrayType) \
   _hl(AttributedType, TypeKind::ATTRIBUTEDTYPE, vast::hl::AttributedType) \
   _hl(BFloat16Type, TypeKind::BFLOAT16TYPE, vast::hl::BFloat16Type) \
   _hl(BoolType, TypeKind::BOOLTYPE, vast::hl::BoolType) \
   _hl(CharType, TypeKind::CHARTYPE, vast::hl::CharType) \
   _hl(DecayedType, TypeKind::DECAYEDTYPE, vast::hl::DecayedType) \
   _hl(DoubleType, TypeKind::DOUBLETYPE, vast::hl::DoubleType) \
   _hl(ElaboratedType, TypeKind::ELABORATEDTYPE, vast::hl::ElaboratedType) \
   _hl(EnumType, TypeKind::ENUMTYPE, vast::hl::EnumType) \
   _hl(Float128Type, TypeKind::FLOAT128TYPE, vast::hl::Float128Type) \
   _hl(FloatType, TypeKind::FLOATTYPE, vast::hl::FloatType) \
   _hl(HalfType, TypeKind::HALFTYPE, vast::hl::HalfType) \
   _hl(Int128Type, TypeKind::INT128TYPE, vast::hl::Int128Type) \
   _hl(IntType, TypeKind::INTTYPE, vast::hl::IntType) \
   _hl(LValueType, TypeKind::LVALUETYPE, vast::hl::LValueType) \
   _hl(LabelType, TypeKind::LABELTYPE, vast::hl::LabelType) \
   _hl(LongDoubleType, TypeKind::LONGDOUBLETYPE, vast::hl::LongDoubleType) \
   _hl(LongLongType, TypeKind::LONGLONGTYPE, vast::hl::LongLongType) \
   _hl(LongType, TypeKind::LONGTYPE, vast::hl::LongType) \
   _hl(ParenType, TypeKind::PARENTYPE, vast::hl::ParenType) \
   _hl(PointerType, TypeKind::POINTERTYPE, vast::hl::PointerType) \
   _hl(RValueType, TypeKind::RVALUETYPE, vast::hl::RValueType) \
   _hl(RecordType, TypeKind::RECORDTYPE, vast::hl::RecordType) \
   _hl(ReferenceType, TypeKind::REFERENCETYPE, vast::hl::ReferenceType) \
   _hl(ShortType, TypeKind::SHORTTYPE, vast::hl::ShortType) \
   _hl(TypeOfExprType, TypeKind::TYPEOFEXPRTYPE, vast::hl::TypeOfExprType) \
   _hl(TypeOfTypeType, TypeKind::TYPEOFTYPETYPE, vast::hl::TypeOfTypeType) \
   _hl(TypedefType, TypeKind::TYPEDEFTYPE, vast::hl::TypedefType) \
   _hl(VoidType, TypeKind::VOIDTYPE, vast::hl::VoidType) \
   _unsup(UnsupportedType, TypeKind::UNSUPPORTEDTYPE, vast::unsup::UnsupportedType)

#define MX_IR_NUM_MLIR_TYPES 43

