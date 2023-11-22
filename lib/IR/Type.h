// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#define MX_IR_FOR_EACH_MLIR_TYPE(_builtin, _llvm, _memref, _abi, _ll, _hl, _core, _meta, _unsup) \
   _llvm(LLVMArrayType, TypeKind::LLVM_ARRAY, mlir::LLVM::LLVMArrayType) \
   _llvm(LLVMFixedVectorType, TypeKind::LLVM_FIXED_VECTOR, mlir::LLVM::LLVMFixedVectorType) \
   _llvm(LLVMFunctionType, TypeKind::LLVM_FUNCTION, mlir::LLVM::LLVMFunctionType) \
   _llvm(LLVMPointerType, TypeKind::LLVM_POINTER, mlir::LLVM::LLVMPointerType) \
   _llvm(LLVMScalableVectorType, TypeKind::LLVM_SCALABLE_VECTOR, mlir::LLVM::LLVMScalableVectorType) \
   _llvm(LLVMTargetExtType, TypeKind::LLVM_TARGET_EXT, mlir::LLVM::LLVMTargetExtType) \
   _hl(AdjustedType, TypeKind::ADJUSTED, vast::hl::AdjustedType) \
   _hl(ArrayType, TypeKind::ARRAY, vast::hl::ArrayType) \
   _hl(AttributedType, TypeKind::ATTRIBUTED, vast::hl::AttributedType) \
   _hl(BFloat16Type, TypeKind::B_FLOAT16, vast::hl::BFloat16Type) \
   _hl(BoolType, TypeKind::BOOL, vast::hl::BoolType) \
   _hl(CharType, TypeKind::CHAR, vast::hl::CharType) \
   _hl(DecayedType, TypeKind::DECAYED, vast::hl::DecayedType) \
   _hl(DoubleType, TypeKind::DOUBLE, vast::hl::DoubleType) \
   _hl(ElaboratedType, TypeKind::ELABORATED, vast::hl::ElaboratedType) \
   _hl(EnumType, TypeKind::ENUM, vast::hl::EnumType) \
   _hl(Float128Type, TypeKind::FLOAT128, vast::hl::Float128Type) \
   _hl(FloatType, TypeKind::FLOAT, vast::hl::FloatType) \
   _hl(HalfType, TypeKind::HALF, vast::hl::HalfType) \
   _hl(Int128Type, TypeKind::INT128, vast::hl::Int128Type) \
   _hl(IntType, TypeKind::INT, vast::hl::IntType) \
   _hl(LValueType, TypeKind::L_VALUE, vast::hl::LValueType) \
   _hl(LabelType, TypeKind::LABEL, vast::hl::LabelType) \
   _hl(LongDoubleType, TypeKind::LONG_DOUBLE, vast::hl::LongDoubleType) \
   _hl(LongLongType, TypeKind::LONG_LONG, vast::hl::LongLongType) \
   _hl(LongType, TypeKind::LONG, vast::hl::LongType) \
   _hl(ParenType, TypeKind::PAREN, vast::hl::ParenType) \
   _hl(PointerType, TypeKind::POINTER, vast::hl::PointerType) \
   _hl(RValueType, TypeKind::R_VALUE, vast::hl::RValueType) \
   _hl(RecordType, TypeKind::RECORD, vast::hl::RecordType) \
   _hl(ReferenceType, TypeKind::REFERENCE, vast::hl::ReferenceType) \
   _hl(ShortType, TypeKind::SHORT, vast::hl::ShortType) \
   _hl(TypeOfExprType, TypeKind::TYPE_OF_EXPR, vast::hl::TypeOfExprType) \
   _hl(TypeOfTypeType, TypeKind::TYPE_OF_TYPE, vast::hl::TypeOfTypeType) \
   _hl(TypedefType, TypeKind::TYPEDEF, vast::hl::TypedefType) \
   _hl(VoidType, TypeKind::VOID, vast::hl::VoidType) \
   _core(FunctionType, TypeKind::FUNCTION, vast::core::FunctionType) \
   _unsup(UnsupportedType, TypeKind::UNSUPPORTED, vast::unsup::UnsupportedType)

#define MX_IR_NUM_MLIR_TYPES 38

