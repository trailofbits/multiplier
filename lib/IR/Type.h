// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#define MX_IR_FOR_EACH_MLIR_TYPE(_builtin, _llvm, _memref, _abi, _ll, _hl, _core, _meta, _unsup) \
   _builtin(ShapedType, TypeKind::BUILTIN_SHAPED, mlir::ShapedType) \
   _builtin(FloatType, TypeKind::BUILTIN_FLOAT, mlir::FloatType) \
   _builtin(ComplexType, TypeKind::BUILTIN_COMPLEX, mlir::ComplexType) \
   _builtin(Float8E5M2Type, TypeKind::BUILTIN_FLOAT8_E5_M2, mlir::Float8E5M2Type) \
   _builtin(Float8E4M3FNType, TypeKind::BUILTIN_FLOAT8_E4_M3_FN, mlir::Float8E4M3FNType) \
   _builtin(Float8E5M2FNUZType, TypeKind::BUILTIN_FLOAT8_E5_M2_FNUZ, mlir::Float8E5M2FNUZType) \
   _builtin(Float8E4M3FNUZType, TypeKind::BUILTIN_FLOAT8_E4_M3_FNUZ, mlir::Float8E4M3FNUZType) \
   _builtin(Float8E4M3B11FNUZType, TypeKind::BUILTIN_FLOAT8_E4_M3_B11_FNUZ, mlir::Float8E4M3B11FNUZType) \
   _builtin(BFloat16Type, TypeKind::BUILTIN_B_FLOAT16, mlir::BFloat16Type) \
   _builtin(Float16Type, TypeKind::BUILTIN_FLOAT16, mlir::Float16Type) \
   _builtin(FloatTF32Type, TypeKind::BUILTIN_FLOAT_TF32, mlir::FloatTF32Type) \
   _builtin(Float32Type, TypeKind::BUILTIN_FLOAT32, mlir::Float32Type) \
   _builtin(Float64Type, TypeKind::BUILTIN_FLOAT64, mlir::Float64Type) \
   _builtin(Float80Type, TypeKind::BUILTIN_FLOAT80, mlir::Float80Type) \
   _builtin(Float128Type, TypeKind::BUILTIN_FLOAT128, mlir::Float128Type) \
   _builtin(FunctionType, TypeKind::BUILTIN_FUNCTION, mlir::FunctionType) \
   _builtin(IndexType, TypeKind::BUILTIN_INDEX, mlir::IndexType) \
   _builtin(IntegerType, TypeKind::BUILTIN_INTEGER, mlir::IntegerType) \
   _builtin(MemRefType, TypeKind::BUILTIN_MEM_REF, mlir::MemRefType) \
   _builtin(NoneType, TypeKind::BUILTIN_NONE, mlir::NoneType) \
   _builtin(OpaqueType, TypeKind::BUILTIN_OPAQUE, mlir::OpaqueType) \
   _builtin(RankedTensorType, TypeKind::BUILTIN_RANKED_TENSOR, mlir::RankedTensorType) \
   _builtin(TupleType, TypeKind::BUILTIN_TUPLE, mlir::TupleType) \
   _builtin(UnrankedMemRefType, TypeKind::BUILTIN_UNRANKED_MEM_REF, mlir::UnrankedMemRefType) \
   _builtin(UnrankedTensorType, TypeKind::BUILTIN_UNRANKED_TENSOR, mlir::UnrankedTensorType) \
   _builtin(VectorType, TypeKind::BUILTIN_VECTOR, mlir::VectorType) \
   _llvm(LLVMArrayType, TypeKind::LLVM_ARRAY, mlir::LLVM::LLVMArrayType) \
   _llvm(LLVMFunctionType, TypeKind::LLVM_FUNCTION, mlir::LLVM::LLVMFunctionType) \
   _llvm(LLVMPointerType, TypeKind::LLVM_POINTER, mlir::LLVM::LLVMPointerType) \
   _llvm(LLVMFixedVectorType, TypeKind::LLVM_FIXED_VECTOR, mlir::LLVM::LLVMFixedVectorType) \
   _llvm(LLVMScalableVectorType, TypeKind::LLVM_SCALABLE_VECTOR, mlir::LLVM::LLVMScalableVectorType) \
   _llvm(LLVMTargetExtType, TypeKind::LLVM_TARGET_EXT, mlir::LLVM::LLVMTargetExtType) \
   _hl(RecordType, TypeKind::HL_RECORD, vast::hl::RecordType) \
   _hl(EnumType, TypeKind::HL_ENUM, vast::hl::EnumType) \
   _hl(TypedefType, TypeKind::HL_TYPEDEF, vast::hl::TypedefType) \
   _hl(ElaboratedType, TypeKind::HL_ELABORATED, vast::hl::ElaboratedType) \
   _hl(LabelType, TypeKind::HL_LABEL, vast::hl::LabelType) \
   _hl(ParenType, TypeKind::HL_PAREN, vast::hl::ParenType) \
   _hl(LValueType, TypeKind::HL_L_VALUE, vast::hl::LValueType) \
   _hl(RValueType, TypeKind::HL_R_VALUE, vast::hl::RValueType) \
   _hl(VoidType, TypeKind::HL_VOID, vast::hl::VoidType) \
   _hl(BoolType, TypeKind::HL_BOOL, vast::hl::BoolType) \
   _hl(CharType, TypeKind::HL_CHAR, vast::hl::CharType) \
   _hl(ShortType, TypeKind::HL_SHORT, vast::hl::ShortType) \
   _hl(IntType, TypeKind::HL_INT, vast::hl::IntType) \
   _hl(LongType, TypeKind::HL_LONG, vast::hl::LongType) \
   _hl(LongLongType, TypeKind::HL_LONG_LONG, vast::hl::LongLongType) \
   _hl(Int128Type, TypeKind::HL_INT128, vast::hl::Int128Type) \
   _hl(HalfType, TypeKind::HL_HALF, vast::hl::HalfType) \
   _hl(BFloat16Type, TypeKind::HL_B_FLOAT16, vast::hl::BFloat16Type) \
   _hl(FloatType, TypeKind::HL_FLOAT, vast::hl::FloatType) \
   _hl(DoubleType, TypeKind::HL_DOUBLE, vast::hl::DoubleType) \
   _hl(LongDoubleType, TypeKind::HL_LONG_DOUBLE, vast::hl::LongDoubleType) \
   _hl(Float128Type, TypeKind::HL_FLOAT128, vast::hl::Float128Type) \
   _hl(ComplexType, TypeKind::HL_COMPLEX, vast::hl::ComplexType) \
   _hl(PointerType, TypeKind::HL_POINTER, vast::hl::PointerType) \
   _hl(ArrayType, TypeKind::HL_ARRAY, vast::hl::ArrayType) \
   _hl(VectorType, TypeKind::HL_VECTOR, vast::hl::VectorType) \
   _hl(DecayedType, TypeKind::HL_DECAYED, vast::hl::DecayedType) \
   _hl(AttributedType, TypeKind::HL_ATTRIBUTED, vast::hl::AttributedType) \
   _hl(AdjustedType, TypeKind::HL_ADJUSTED, vast::hl::AdjustedType) \
   _hl(ReferenceType, TypeKind::HL_REFERENCE, vast::hl::ReferenceType) \
   _hl(TypeOfExprType, TypeKind::HL_TYPE_OF_EXPR, vast::hl::TypeOfExprType) \
   _hl(TypeOfTypeType, TypeKind::HL_TYPE_OF_TYPE, vast::hl::TypeOfTypeType) \
   _core(FunctionType, TypeKind::CORE_FUNCTION, vast::core::FunctionType) \
   _unsup(UnsupportedType, TypeKind::UNSUP_UNSUPPORTED, vast::unsup::UnsupportedType)

#define MX_IR_NUM_MLIR_TYPES 66

