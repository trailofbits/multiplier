// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/HighLevel/Type.h>

#include <multiplier/IR/Attribute.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<Type> Type::from(const ::mx::ir::Type &that) {
  if (IsHighLevelTypeKind(that.kind())) {
    return reinterpret_cast<const Type &>(that);
  }
  return std::nullopt;
}

std::optional<RecordType> RecordType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_RECORD) {
    return reinterpret_cast<const RecordType &>(that);
  }
  return std::nullopt;
}

::vast::hl::RecordType RecordType::underlying_repr(void) const noexcept {
  return ::vast::hl::RecordType(this->::mx::ir::Type::type_);
}

std::string_view RecordType::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<EnumType> EnumType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_ENUM) {
    return reinterpret_cast<const EnumType &>(that);
  }
  return std::nullopt;
}

::vast::hl::EnumType EnumType::underlying_repr(void) const noexcept {
  return ::vast::hl::EnumType(this->::mx::ir::Type::type_);
}

std::string_view EnumType::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<TypedefType> TypedefType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_TYPEDEF) {
    return reinterpret_cast<const TypedefType &>(that);
  }
  return std::nullopt;
}

::vast::hl::TypedefType TypedefType::underlying_repr(void) const noexcept {
  return ::vast::hl::TypedefType(this->::mx::ir::Type::type_);
}

std::string_view TypedefType::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<ElaboratedType> ElaboratedType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_ELABORATED) {
    return reinterpret_cast<const ElaboratedType &>(that);
  }
  return std::nullopt;
}

::vast::hl::ElaboratedType ElaboratedType::underlying_repr(void) const noexcept {
  return ::vast::hl::ElaboratedType(this->::mx::ir::Type::type_);
}

std::optional<LabelType> LabelType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_LABEL) {
    return reinterpret_cast<const LabelType &>(that);
  }
  return std::nullopt;
}

::vast::hl::LabelType LabelType::underlying_repr(void) const noexcept {
  return ::vast::hl::LabelType(this->::mx::ir::Type::type_);
}

std::optional<ParenType> ParenType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_PAREN) {
    return reinterpret_cast<const ParenType &>(that);
  }
  return std::nullopt;
}

::vast::hl::ParenType ParenType::underlying_repr(void) const noexcept {
  return ::vast::hl::ParenType(this->::mx::ir::Type::type_);
}

std::optional<LValueType> LValueType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_L_VALUE) {
    return reinterpret_cast<const LValueType &>(that);
  }
  return std::nullopt;
}

::vast::hl::LValueType LValueType::underlying_repr(void) const noexcept {
  return ::vast::hl::LValueType(this->::mx::ir::Type::type_);
}

std::optional<RValueType> RValueType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_R_VALUE) {
    return reinterpret_cast<const RValueType &>(that);
  }
  return std::nullopt;
}

::vast::hl::RValueType RValueType::underlying_repr(void) const noexcept {
  return ::vast::hl::RValueType(this->::mx::ir::Type::type_);
}

std::optional<VoidType> VoidType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_VOID) {
    return reinterpret_cast<const VoidType &>(that);
  }
  return std::nullopt;
}

::vast::hl::VoidType VoidType::underlying_repr(void) const noexcept {
  return ::vast::hl::VoidType(this->::mx::ir::Type::type_);
}

std::optional<BoolType> BoolType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_BOOL) {
    return reinterpret_cast<const BoolType &>(that);
  }
  return std::nullopt;
}

::vast::hl::BoolType BoolType::underlying_repr(void) const noexcept {
  return ::vast::hl::BoolType(this->::mx::ir::Type::type_);
}

std::optional<CharType> CharType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_CHAR) {
    return reinterpret_cast<const CharType &>(that);
  }
  return std::nullopt;
}

::vast::hl::CharType CharType::underlying_repr(void) const noexcept {
  return ::vast::hl::CharType(this->::mx::ir::Type::type_);
}

std::optional<ShortType> ShortType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_SHORT) {
    return reinterpret_cast<const ShortType &>(that);
  }
  return std::nullopt;
}

::vast::hl::ShortType ShortType::underlying_repr(void) const noexcept {
  return ::vast::hl::ShortType(this->::mx::ir::Type::type_);
}

std::optional<IntType> IntType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_INT) {
    return reinterpret_cast<const IntType &>(that);
  }
  return std::nullopt;
}

::vast::hl::IntType IntType::underlying_repr(void) const noexcept {
  return ::vast::hl::IntType(this->::mx::ir::Type::type_);
}

std::optional<LongType> LongType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_LONG) {
    return reinterpret_cast<const LongType &>(that);
  }
  return std::nullopt;
}

::vast::hl::LongType LongType::underlying_repr(void) const noexcept {
  return ::vast::hl::LongType(this->::mx::ir::Type::type_);
}

std::optional<LongLongType> LongLongType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_LONG_LONG) {
    return reinterpret_cast<const LongLongType &>(that);
  }
  return std::nullopt;
}

::vast::hl::LongLongType LongLongType::underlying_repr(void) const noexcept {
  return ::vast::hl::LongLongType(this->::mx::ir::Type::type_);
}

std::optional<Int128Type> Int128Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_INT128) {
    return reinterpret_cast<const Int128Type &>(that);
  }
  return std::nullopt;
}

::vast::hl::Int128Type Int128Type::underlying_repr(void) const noexcept {
  return ::vast::hl::Int128Type(this->::mx::ir::Type::type_);
}

std::optional<HalfType> HalfType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_HALF) {
    return reinterpret_cast<const HalfType &>(that);
  }
  return std::nullopt;
}

::vast::hl::HalfType HalfType::underlying_repr(void) const noexcept {
  return ::vast::hl::HalfType(this->::mx::ir::Type::type_);
}

std::optional<BFloat16Type> BFloat16Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_B_FLOAT16) {
    return reinterpret_cast<const BFloat16Type &>(that);
  }
  return std::nullopt;
}

::vast::hl::BFloat16Type BFloat16Type::underlying_repr(void) const noexcept {
  return ::vast::hl::BFloat16Type(this->::mx::ir::Type::type_);
}

std::optional<FloatType> FloatType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_FLOAT) {
    return reinterpret_cast<const FloatType &>(that);
  }
  return std::nullopt;
}

::vast::hl::FloatType FloatType::underlying_repr(void) const noexcept {
  return ::vast::hl::FloatType(this->::mx::ir::Type::type_);
}

std::optional<DoubleType> DoubleType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_DOUBLE) {
    return reinterpret_cast<const DoubleType &>(that);
  }
  return std::nullopt;
}

::vast::hl::DoubleType DoubleType::underlying_repr(void) const noexcept {
  return ::vast::hl::DoubleType(this->::mx::ir::Type::type_);
}

std::optional<LongDoubleType> LongDoubleType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_LONG_DOUBLE) {
    return reinterpret_cast<const LongDoubleType &>(that);
  }
  return std::nullopt;
}

::vast::hl::LongDoubleType LongDoubleType::underlying_repr(void) const noexcept {
  return ::vast::hl::LongDoubleType(this->::mx::ir::Type::type_);
}

std::optional<Float128Type> Float128Type::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_FLOAT128) {
    return reinterpret_cast<const Float128Type &>(that);
  }
  return std::nullopt;
}

::vast::hl::Float128Type Float128Type::underlying_repr(void) const noexcept {
  return ::vast::hl::Float128Type(this->::mx::ir::Type::type_);
}

std::optional<ComplexType> ComplexType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_COMPLEX) {
    return reinterpret_cast<const ComplexType &>(that);
  }
  return std::nullopt;
}

::vast::hl::ComplexType ComplexType::underlying_repr(void) const noexcept {
  return ::vast::hl::ComplexType(this->::mx::ir::Type::type_);
}

std::optional<PointerType> PointerType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_POINTER) {
    return reinterpret_cast<const PointerType &>(that);
  }
  return std::nullopt;
}

::vast::hl::PointerType PointerType::underlying_repr(void) const noexcept {
  return ::vast::hl::PointerType(this->::mx::ir::Type::type_);
}

std::optional<ArrayType> ArrayType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_ARRAY) {
    return reinterpret_cast<const ArrayType &>(that);
  }
  return std::nullopt;
}

::vast::hl::ArrayType ArrayType::underlying_repr(void) const noexcept {
  return ::vast::hl::ArrayType(this->::mx::ir::Type::type_);
}

std::optional<VectorType> VectorType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_VECTOR) {
    return reinterpret_cast<const VectorType &>(that);
  }
  return std::nullopt;
}

::vast::hl::VectorType VectorType::underlying_repr(void) const noexcept {
  return ::vast::hl::VectorType(this->::mx::ir::Type::type_);
}

std::optional<DecayedType> DecayedType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_DECAYED) {
    return reinterpret_cast<const DecayedType &>(that);
  }
  return std::nullopt;
}

::vast::hl::DecayedType DecayedType::underlying_repr(void) const noexcept {
  return ::vast::hl::DecayedType(this->::mx::ir::Type::type_);
}

std::optional<AttributedType> AttributedType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_ATTRIBUTED) {
    return reinterpret_cast<const AttributedType &>(that);
  }
  return std::nullopt;
}

::vast::hl::AttributedType AttributedType::underlying_repr(void) const noexcept {
  return ::vast::hl::AttributedType(this->::mx::ir::Type::type_);
}

std::optional<AdjustedType> AdjustedType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_ADJUSTED) {
    return reinterpret_cast<const AdjustedType &>(that);
  }
  return std::nullopt;
}

::vast::hl::AdjustedType AdjustedType::underlying_repr(void) const noexcept {
  return ::vast::hl::AdjustedType(this->::mx::ir::Type::type_);
}

std::optional<ReferenceType> ReferenceType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_REFERENCE) {
    return reinterpret_cast<const ReferenceType &>(that);
  }
  return std::nullopt;
}

::vast::hl::ReferenceType ReferenceType::underlying_repr(void) const noexcept {
  return ::vast::hl::ReferenceType(this->::mx::ir::Type::type_);
}

std::optional<TypeOfExprType> TypeOfExprType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_TYPE_OF_EXPR) {
    return reinterpret_cast<const TypeOfExprType &>(that);
  }
  return std::nullopt;
}

::vast::hl::TypeOfExprType TypeOfExprType::underlying_repr(void) const noexcept {
  return ::vast::hl::TypeOfExprType(this->::mx::ir::Type::type_);
}

std::string_view TypeOfExprType::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<TypeOfTypeType> TypeOfTypeType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_TYPE_OF_TYPE) {
    return reinterpret_cast<const TypeOfTypeType &>(that);
  }
  return std::nullopt;
}

::vast::hl::TypeOfTypeType TypeOfTypeType::underlying_repr(void) const noexcept {
  return ::vast::hl::TypeOfTypeType(this->::mx::ir::Type::type_);
}

std::optional<AutoType> AutoType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_AUTO) {
    return reinterpret_cast<const AutoType &>(that);
  }
  return std::nullopt;
}

::vast::hl::AutoType AutoType::underlying_repr(void) const noexcept {
  return ::vast::hl::AutoType(this->::mx::ir::Type::type_);
}

std::optional<AtomicType> AtomicType::from(const ::mx::ir::Type &that) {
  if (that.kind() == TypeKind::HL_ATOMIC) {
    return reinterpret_cast<const AtomicType &>(that);
  }
  return std::nullopt;
}

::vast::hl::AtomicType AtomicType::underlying_repr(void) const noexcept {
  return ::vast::hl::AtomicType(this->::mx::ir::Type::type_);
}

}  // namespace mx::ir::hl
