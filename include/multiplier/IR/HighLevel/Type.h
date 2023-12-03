// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Type.h"

namespace vast::hl {
class AdjustedType;
class ArrayType;
class AttributedType;
class BFloat16Type;
class BoolType;
class CharType;
class DecayedType;
class DoubleType;
class ElaboratedType;
class EnumType;
class Float128Type;
class FloatType;
class HalfType;
class Int128Type;
class IntType;
class LValueType;
class LabelType;
class LongDoubleType;
class LongLongType;
class LongType;
class ParenType;
class PointerType;
class RValueType;
class RecordType;
class ReferenceType;
class ShortType;
class TypeOfExprType;
class TypeOfTypeType;
class TypedefType;
class VoidType;
}  // namespace vast::hl
namespace mx::ir::hl {

class MX_EXPORT Type : public ::mx::ir::Type {
 public:
  static std::optional<Type> from(const ::mx::ir::Type &);
};
static_assert(sizeof(Type) == sizeof(::mx::ir::Type));

class MX_EXPORT AdjustedType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_ADJUSTED;
  }

  static std::optional<AdjustedType> from(const ::mx::ir::Type &that);
  ::vast::hl::AdjustedType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type original(void) const;
  //Type adjusted(void) const;
};
static_assert(sizeof(AdjustedType) == sizeof(Type));

class MX_EXPORT ArrayType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_ARRAY;
  }

  static std::optional<ArrayType> from(const ::mx::ir::Type &that);
  ::vast::hl::ArrayType underlying_repr(void) const noexcept;

  // Imported methods:
  //std::tuple<dimensions_t,mlir::Type> dim__and__type(void) const;
  //dimensions_t dimensions(void) const;
  //SizeParam size(void) const;
  //Type element_type(void) const;
  //CVRQualifiersAttr quals(void) const;
};
static_assert(sizeof(ArrayType) == sizeof(Type));

class MX_EXPORT AttributedType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_ATTRIBUTED;
  }

  static std::optional<AttributedType> from(const ::mx::ir::Type &that);
  ::vast::hl::AttributedType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
};
static_assert(sizeof(AttributedType) == sizeof(Type));

class MX_EXPORT BFloat16Type final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_B_FLOAT16;
  }

  static std::optional<BFloat16Type> from(const ::mx::ir::Type &that);
  ::vast::hl::BFloat16Type underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(BFloat16Type) == sizeof(Type));

class MX_EXPORT BoolType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_BOOL;
  }

  static std::optional<BoolType> from(const ::mx::ir::Type &that);
  ::vast::hl::BoolType underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(BoolType) == sizeof(Type));

class MX_EXPORT CharType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_CHAR;
  }

  static std::optional<CharType> from(const ::mx::ir::Type &that);
  ::vast::hl::CharType underlying_repr(void) const noexcept;

  // Imported methods:
  //UCVQualifiersAttr quals(void) const;
};
static_assert(sizeof(CharType) == sizeof(Type));

class MX_EXPORT DecayedType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_DECAYED;
  }

  static std::optional<DecayedType> from(const ::mx::ir::Type &that);
  ::vast::hl::DecayedType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
};
static_assert(sizeof(DecayedType) == sizeof(Type));

class MX_EXPORT DoubleType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_DOUBLE;
  }

  static std::optional<DoubleType> from(const ::mx::ir::Type &that);
  ::vast::hl::DoubleType underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(DoubleType) == sizeof(Type));

class MX_EXPORT ElaboratedType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_ELABORATED;
  }

  static std::optional<ElaboratedType> from(const ::mx::ir::Type &that);
  ::vast::hl::ElaboratedType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
  //CVRQualifiersAttr quals(void) const;
};
static_assert(sizeof(ElaboratedType) == sizeof(Type));

class MX_EXPORT EnumType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_ENUM;
  }

  static std::optional<EnumType> from(const ::mx::ir::Type &that);
  ::vast::hl::EnumType underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(EnumType) == sizeof(Type));

class MX_EXPORT Float128Type final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_FLOAT128;
  }

  static std::optional<Float128Type> from(const ::mx::ir::Type &that);
  ::vast::hl::Float128Type underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(Float128Type) == sizeof(Type));

class MX_EXPORT FloatType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_FLOAT;
  }

  static std::optional<FloatType> from(const ::mx::ir::Type &that);
  ::vast::hl::FloatType underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(FloatType) == sizeof(Type));

class MX_EXPORT HalfType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_HALF;
  }

  static std::optional<HalfType> from(const ::mx::ir::Type &that);
  ::vast::hl::HalfType underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(HalfType) == sizeof(Type));

class MX_EXPORT Int128Type final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_INT128;
  }

  static std::optional<Int128Type> from(const ::mx::ir::Type &that);
  ::vast::hl::Int128Type underlying_repr(void) const noexcept;

  // Imported methods:
  //UCVQualifiersAttr quals(void) const;
};
static_assert(sizeof(Int128Type) == sizeof(Type));

class MX_EXPORT IntType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_INT;
  }

  static std::optional<IntType> from(const ::mx::ir::Type &that);
  ::vast::hl::IntType underlying_repr(void) const noexcept;

  // Imported methods:
  //UCVQualifiersAttr quals(void) const;
};
static_assert(sizeof(IntType) == sizeof(Type));

class MX_EXPORT LValueType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_L_VALUE;
  }

  static std::optional<LValueType> from(const ::mx::ir::Type &that);
  ::vast::hl::LValueType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
};
static_assert(sizeof(LValueType) == sizeof(Type));

class MX_EXPORT LabelType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_LABEL;
  }

  static std::optional<LabelType> from(const ::mx::ir::Type &that);
  ::vast::hl::LabelType underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(LabelType) == sizeof(Type));

class MX_EXPORT LongDoubleType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_LONG_DOUBLE;
  }

  static std::optional<LongDoubleType> from(const ::mx::ir::Type &that);
  ::vast::hl::LongDoubleType underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(LongDoubleType) == sizeof(Type));

class MX_EXPORT LongLongType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_LONG_LONG;
  }

  static std::optional<LongLongType> from(const ::mx::ir::Type &that);
  ::vast::hl::LongLongType underlying_repr(void) const noexcept;

  // Imported methods:
  //UCVQualifiersAttr quals(void) const;
};
static_assert(sizeof(LongLongType) == sizeof(Type));

class MX_EXPORT LongType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_LONG;
  }

  static std::optional<LongType> from(const ::mx::ir::Type &that);
  ::vast::hl::LongType underlying_repr(void) const noexcept;

  // Imported methods:
  //UCVQualifiersAttr quals(void) const;
};
static_assert(sizeof(LongType) == sizeof(Type));

class MX_EXPORT ParenType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_PAREN;
  }

  static std::optional<ParenType> from(const ::mx::ir::Type &that);
  ::vast::hl::ParenType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
};
static_assert(sizeof(ParenType) == sizeof(Type));

class MX_EXPORT PointerType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_POINTER;
  }

  static std::optional<PointerType> from(const ::mx::ir::Type &that);
  ::vast::hl::PointerType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
  //CVRQualifiersAttr quals(void) const;
};
static_assert(sizeof(PointerType) == sizeof(Type));

class MX_EXPORT RValueType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_R_VALUE;
  }

  static std::optional<RValueType> from(const ::mx::ir::Type &that);
  ::vast::hl::RValueType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
};
static_assert(sizeof(RValueType) == sizeof(Type));

class MX_EXPORT RecordType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_RECORD;
  }

  static std::optional<RecordType> from(const ::mx::ir::Type &that);
  ::vast::hl::RecordType underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(RecordType) == sizeof(Type));

class MX_EXPORT ReferenceType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_REFERENCE;
  }

  static std::optional<ReferenceType> from(const ::mx::ir::Type &that);
  ::vast::hl::ReferenceType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
};
static_assert(sizeof(ReferenceType) == sizeof(Type));

class MX_EXPORT ShortType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_SHORT;
  }

  static std::optional<ShortType> from(const ::mx::ir::Type &that);
  ::vast::hl::ShortType underlying_repr(void) const noexcept;

  // Imported methods:
  //UCVQualifiersAttr quals(void) const;
};
static_assert(sizeof(ShortType) == sizeof(Type));

class MX_EXPORT TypeOfExprType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_TYPE_OF_EXPR;
  }

  static std::optional<TypeOfExprType> from(const ::mx::ir::Type &that);
  ::vast::hl::TypeOfExprType underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
  //CVRQualifiersAttr quals(void) const;
};
static_assert(sizeof(TypeOfExprType) == sizeof(Type));

class MX_EXPORT TypeOfTypeType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_TYPE_OF_TYPE;
  }

  static std::optional<TypeOfTypeType> from(const ::mx::ir::Type &that);
  ::vast::hl::TypeOfTypeType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type unmodified_type(void) const;
  //CVRQualifiersAttr quals(void) const;
};
static_assert(sizeof(TypeOfTypeType) == sizeof(Type));

class MX_EXPORT TypedefType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_TYPEDEF;
  }

  static std::optional<TypedefType> from(const ::mx::ir::Type &that);
  ::vast::hl::TypedefType underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
  //CVRQualifiersAttr quals(void) const;
};
static_assert(sizeof(TypedefType) == sizeof(Type));

class MX_EXPORT VoidType final : public Type {
 public:
  inline static TypeKind static_kind(void) {
    return TypeKind::HL_VOID;
  }

  static std::optional<VoidType> from(const ::mx::ir::Type &that);
  ::vast::hl::VoidType underlying_repr(void) const noexcept;

  // Imported methods:
  //CVQualifiersAttr quals(void) const;
};
static_assert(sizeof(VoidType) == sizeof(Type));

}  // namespace mx::ir::hl
