// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/Type.h>

#include <multiplier/IR/Attribute.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<Type> Type::from(const ::mx::ir::Type &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::TypeKind::LLVM_ARRAY:
    case mx::ir::TypeKind::LLVM_FIXED_VECTOR:
    case mx::ir::TypeKind::LLVM_FUNCTION:
    case mx::ir::TypeKind::LLVM_POINTER:
    case mx::ir::TypeKind::LLVM_SCALABLE_VECTOR:
    case mx::ir::TypeKind::LLVM_TARGET_EXT:
      return reinterpret_cast<const Type &>(that);
  }
}

std::optional<ArrayType> ArrayType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::LLVM_ARRAY) {
    return reinterpret_cast<const ArrayType &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LLVMArrayType ArrayType::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LLVMArrayType(this->::mx::ir::Type::type_);
}

std::optional<FixedVectorType> FixedVectorType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::LLVM_FIXED_VECTOR) {
    return reinterpret_cast<const FixedVectorType &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LLVMFixedVectorType FixedVectorType::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LLVMFixedVectorType(this->::mx::ir::Type::type_);
}

std::optional<FunctionType> FunctionType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::LLVM_FUNCTION) {
    return reinterpret_cast<const FunctionType &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LLVMFunctionType FunctionType::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LLVMFunctionType(this->::mx::ir::Type::type_);
}

bool FunctionType::is_var_arg(void) const {
  auto val = underlying_repr().isVarArg();
  return val;
}

bool FunctionType::var_arg(void) const {
  auto val = underlying_repr().getVarArg();
  return val;
}

std::optional<PointerType> PointerType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::LLVM_POINTER) {
    return reinterpret_cast<const PointerType &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LLVMPointerType PointerType::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LLVMPointerType(this->::mx::ir::Type::type_);
}

bool PointerType::is_opaque(void) const {
  auto val = underlying_repr().isOpaque();
  return val;
}

std::optional<ScalableVectorType> ScalableVectorType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::LLVM_SCALABLE_VECTOR) {
    return reinterpret_cast<const ScalableVectorType &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LLVMScalableVectorType ScalableVectorType::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LLVMScalableVectorType(this->::mx::ir::Type::type_);
}

std::optional<TargetExtType> TargetExtType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::LLVM_TARGET_EXT) {
    return reinterpret_cast<const TargetExtType &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LLVMTargetExtType TargetExtType::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LLVMTargetExtType(this->::mx::ir::Type::type_);
}

bool TargetExtType::supports_mem_ops(void) const {
  auto val = underlying_repr().supportsMemOps();
  return val;
}

std::string_view TargetExtType::ext_type_name(void) const {
  auto val = underlying_repr().getExtTypeName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::llvm
