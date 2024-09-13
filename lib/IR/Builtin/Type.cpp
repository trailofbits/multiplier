// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Builtin/Type.h>

#include <multiplier/IR/Attribute.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::builtin {
std::optional<Type> Type::from(const ::mx::ir::Type &that) {
  if (IsBuiltinTypeKind(that.kind())) {
    return reinterpret_cast<const Type &>(that);
  }
  return std::nullopt;
}

std::optional<ShapedType> ShapedType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_SHAPED) {
    return reinterpret_cast<const ShapedType &>(that);
  }
  return std::nullopt;
}

::mlir::ShapedType ShapedType::underlying_repr(void) const noexcept {
  return ::mlir::ShapedType(this->::mx::ir::Type::type_);
}

::mx::ir::Type ShapedType::element_type(void) const {
  auto mlir_type = underlying_repr().getElementType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool ShapedType::has_rank(void) const {
  auto val = underlying_repr().hasRank();
  return val;
}

unsigned int ShapedType::element_type_bit_width(void) const {
  auto val = underlying_repr().getElementTypeBitWidth();
  return val;
}

int64_t ShapedType::rank(void) const {
  auto val = underlying_repr().getRank();
  return val;
}

int64_t ShapedType::num_elements(void) const {
  auto val = underlying_repr().getNumElements();
  return val;
}

bool ShapedType::has_static_shape(void) const {
  auto val = underlying_repr().hasStaticShape();
  return val;
}

int64_t ShapedType::num_dynamic_dims(void) const {
  auto val = underlying_repr().getNumDynamicDims();
  return val;
}

std::optional<FloatType> FloatType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT) {
    return reinterpret_cast<const FloatType &>(that);
  }
  return std::nullopt;
}

::mlir::FloatType FloatType::underlying_repr(void) const noexcept {
  return ::mlir::FloatType(this->::mx::ir::Type::type_);
}

unsigned int FloatType::width(void) const {
  auto val = underlying_repr().getWidth();
  return val;
}

unsigned int FloatType::fp_mantissa_width(void) const {
  auto val = underlying_repr().getFPMantissaWidth();
  return val;
}

std::optional<ComplexType> ComplexType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_COMPLEX) {
    return reinterpret_cast<const ComplexType &>(that);
  }
  return std::nullopt;
}

::mlir::ComplexType ComplexType::underlying_repr(void) const noexcept {
  return ::mlir::ComplexType(this->::mx::ir::Type::type_);
}

std::optional<Float8E5M2Type> Float8E5M2Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT8_E5_M2) {
    return reinterpret_cast<const Float8E5M2Type &>(that);
  }
  return std::nullopt;
}

::mlir::Float8E5M2Type Float8E5M2Type::underlying_repr(void) const noexcept {
  return ::mlir::Float8E5M2Type(this->::mx::ir::Type::type_);
}

std::optional<Float8E4M3FNType> Float8E4M3FNType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT8_E4_M3_FN) {
    return reinterpret_cast<const Float8E4M3FNType &>(that);
  }
  return std::nullopt;
}

::mlir::Float8E4M3FNType Float8E4M3FNType::underlying_repr(void) const noexcept {
  return ::mlir::Float8E4M3FNType(this->::mx::ir::Type::type_);
}

std::optional<Float8E5M2FNUZType> Float8E5M2FNUZType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT8_E5_M2_FNUZ) {
    return reinterpret_cast<const Float8E5M2FNUZType &>(that);
  }
  return std::nullopt;
}

::mlir::Float8E5M2FNUZType Float8E5M2FNUZType::underlying_repr(void) const noexcept {
  return ::mlir::Float8E5M2FNUZType(this->::mx::ir::Type::type_);
}

std::optional<Float8E4M3FNUZType> Float8E4M3FNUZType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT8_E4_M3_FNUZ) {
    return reinterpret_cast<const Float8E4M3FNUZType &>(that);
  }
  return std::nullopt;
}

::mlir::Float8E4M3FNUZType Float8E4M3FNUZType::underlying_repr(void) const noexcept {
  return ::mlir::Float8E4M3FNUZType(this->::mx::ir::Type::type_);
}

std::optional<Float8E4M3B11FNUZType> Float8E4M3B11FNUZType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT8_E4_M3_B11_FNUZ) {
    return reinterpret_cast<const Float8E4M3B11FNUZType &>(that);
  }
  return std::nullopt;
}

::mlir::Float8E4M3B11FNUZType Float8E4M3B11FNUZType::underlying_repr(void) const noexcept {
  return ::mlir::Float8E4M3B11FNUZType(this->::mx::ir::Type::type_);
}

std::optional<BFloat16Type> BFloat16Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_B_FLOAT16) {
    return reinterpret_cast<const BFloat16Type &>(that);
  }
  return std::nullopt;
}

::mlir::BFloat16Type BFloat16Type::underlying_repr(void) const noexcept {
  return ::mlir::BFloat16Type(this->::mx::ir::Type::type_);
}

std::optional<Float16Type> Float16Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT16) {
    return reinterpret_cast<const Float16Type &>(that);
  }
  return std::nullopt;
}

::mlir::Float16Type Float16Type::underlying_repr(void) const noexcept {
  return ::mlir::Float16Type(this->::mx::ir::Type::type_);
}

std::optional<FloatTF32Type> FloatTF32Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT_TF32) {
    return reinterpret_cast<const FloatTF32Type &>(that);
  }
  return std::nullopt;
}

::mlir::FloatTF32Type FloatTF32Type::underlying_repr(void) const noexcept {
  return ::mlir::FloatTF32Type(this->::mx::ir::Type::type_);
}

std::optional<Float32Type> Float32Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT32) {
    return reinterpret_cast<const Float32Type &>(that);
  }
  return std::nullopt;
}

::mlir::Float32Type Float32Type::underlying_repr(void) const noexcept {
  return ::mlir::Float32Type(this->::mx::ir::Type::type_);
}

std::optional<Float64Type> Float64Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT64) {
    return reinterpret_cast<const Float64Type &>(that);
  }
  return std::nullopt;
}

::mlir::Float64Type Float64Type::underlying_repr(void) const noexcept {
  return ::mlir::Float64Type(this->::mx::ir::Type::type_);
}

std::optional<Float80Type> Float80Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT80) {
    return reinterpret_cast<const Float80Type &>(that);
  }
  return std::nullopt;
}

::mlir::Float80Type Float80Type::underlying_repr(void) const noexcept {
  return ::mlir::Float80Type(this->::mx::ir::Type::type_);
}

std::optional<Float128Type> Float128Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FLOAT128) {
    return reinterpret_cast<const Float128Type &>(that);
  }
  return std::nullopt;
}

::mlir::Float128Type Float128Type::underlying_repr(void) const noexcept {
  return ::mlir::Float128Type(this->::mx::ir::Type::type_);
}

std::optional<FunctionType> FunctionType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_FUNCTION) {
    return reinterpret_cast<const FunctionType &>(that);
  }
  return std::nullopt;
}

::mlir::FunctionType FunctionType::underlying_repr(void) const noexcept {
  return ::mlir::FunctionType(this->::mx::ir::Type::type_);
}

unsigned int FunctionType::num_inputs(void) const {
  auto val = underlying_repr().getNumInputs();
  return val;
}

unsigned int FunctionType::num_results(void) const {
  auto val = underlying_repr().getNumResults();
  return val;
}

std::optional<IndexType> IndexType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_INDEX) {
    return reinterpret_cast<const IndexType &>(that);
  }
  return std::nullopt;
}

::mlir::IndexType IndexType::underlying_repr(void) const noexcept {
  return ::mlir::IndexType(this->::mx::ir::Type::type_);
}

std::optional<IntegerType> IntegerType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_INTEGER) {
    return reinterpret_cast<const IntegerType &>(that);
  }
  return std::nullopt;
}

::mlir::IntegerType IntegerType::underlying_repr(void) const noexcept {
  return ::mlir::IntegerType(this->::mx::ir::Type::type_);
}

bool IntegerType::is_signless(void) const {
  auto val = underlying_repr().isSignless();
  return val;
}

bool IntegerType::is_signed(void) const {
  auto val = underlying_repr().isSigned();
  return val;
}

bool IntegerType::is_unsigned(void) const {
  auto val = underlying_repr().isUnsigned();
  return val;
}

unsigned int IntegerType::width(void) const {
  auto val = underlying_repr().getWidth();
  return val;
}

std::optional<MemRefType> MemRefType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_MEM_REF) {
    return reinterpret_cast<const MemRefType &>(that);
  }
  return std::nullopt;
}

::mlir::MemRefType MemRefType::underlying_repr(void) const noexcept {
  return ::mlir::MemRefType(this->::mx::ir::Type::type_);
}

unsigned int MemRefType::memory_space_as_int(void) const {
  auto val = underlying_repr().getMemorySpaceAsInt();
  return val;
}

std::optional<NoneType> NoneType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_NONE) {
    return reinterpret_cast<const NoneType &>(that);
  }
  return std::nullopt;
}

::mlir::NoneType NoneType::underlying_repr(void) const noexcept {
  return ::mlir::NoneType(this->::mx::ir::Type::type_);
}

std::optional<OpaqueType> OpaqueType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_OPAQUE) {
    return reinterpret_cast<const OpaqueType &>(that);
  }
  return std::nullopt;
}

::mlir::OpaqueType OpaqueType::underlying_repr(void) const noexcept {
  return ::mlir::OpaqueType(this->::mx::ir::Type::type_);
}

std::string_view OpaqueType::type_data(void) const {
  auto val = underlying_repr().getTypeData();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<RankedTensorType> RankedTensorType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_RANKED_TENSOR) {
    return reinterpret_cast<const RankedTensorType &>(that);
  }
  return std::nullopt;
}

::mlir::RankedTensorType RankedTensorType::underlying_repr(void) const noexcept {
  return ::mlir::RankedTensorType(this->::mx::ir::Type::type_);
}

std::optional<TupleType> TupleType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_TUPLE) {
    return reinterpret_cast<const TupleType &>(that);
  }
  return std::nullopt;
}

::mlir::TupleType TupleType::underlying_repr(void) const noexcept {
  return ::mlir::TupleType(this->::mx::ir::Type::type_);
}

size_t TupleType::size(void) const {
  auto val = underlying_repr().size();
  return val;
}

std::optional<UnrankedMemRefType> UnrankedMemRefType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_UNRANKED_MEM_REF) {
    return reinterpret_cast<const UnrankedMemRefType &>(that);
  }
  return std::nullopt;
}

::mlir::UnrankedMemRefType UnrankedMemRefType::underlying_repr(void) const noexcept {
  return ::mlir::UnrankedMemRefType(this->::mx::ir::Type::type_);
}

unsigned int UnrankedMemRefType::memory_space_as_int(void) const {
  auto val = underlying_repr().getMemorySpaceAsInt();
  return val;
}

std::optional<UnrankedTensorType> UnrankedTensorType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_UNRANKED_TENSOR) {
    return reinterpret_cast<const UnrankedTensorType &>(that);
  }
  return std::nullopt;
}

::mlir::UnrankedTensorType UnrankedTensorType::underlying_repr(void) const noexcept {
  return ::mlir::UnrankedTensorType(this->::mx::ir::Type::type_);
}

std::optional<VectorType> VectorType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::BUILTIN_VECTOR) {
    return reinterpret_cast<const VectorType &>(that);
  }
  return std::nullopt;
}

::mlir::VectorType VectorType::underlying_repr(void) const noexcept {
  return ::mlir::VectorType(this->::mx::ir::Type::type_);
}

bool VectorType::is_scalable(void) const {
  auto val = underlying_repr().isScalable();
  return val;
}

bool VectorType::all_dims_scalable(void) const {
  auto val = underlying_repr().allDimsScalable();
  return val;
}

bool VectorType::has_rank(void) const {
  auto val = underlying_repr().hasRank();
  return val;
}

}  // namespace mx::ir::builtin
