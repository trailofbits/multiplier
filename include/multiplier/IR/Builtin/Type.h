// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Type.h"

namespace mlir {
class ShapedType;
class FloatType;
class ComplexType;
class Float8E5M2Type;
class Float8E4M3FNType;
class Float8E5M2FNUZType;
class Float8E4M3FNUZType;
class Float8E4M3B11FNUZType;
class BFloat16Type;
class Float16Type;
class FloatTF32Type;
class Float32Type;
class Float64Type;
class Float80Type;
class Float128Type;
class FunctionType;
class IndexType;
class IntegerType;
class MemRefType;
class NoneType;
class OpaqueType;
class RankedTensorType;
class TupleType;
class UnrankedMemRefType;
class UnrankedTensorType;
class VectorType;
}  // namespace mlir
namespace mx::ir::builtin {

class MX_EXPORT Type : public ::mx::ir::Type {
 public:
  static std::optional<Type> from(const ::mx::ir::Type &);
};
static_assert(sizeof(Type) == sizeof(::mx::ir::Type));

class MX_EXPORT ShapedType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_SHAPED;
  }

  static std::optional<ShapedType> from(const ::mx::ir::Type &that);
  ::mlir::ShapedType underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Type element_type(void) const;
  bool has_rank(void) const;
  //::llvm::ArrayRef<long long> shape(void) const;
  unsigned int element_type_bit_width(void) const;
  int64_t rank(void) const;
  int64_t num_elements(void) const;
  bool has_static_shape(void) const;
  int64_t num_dynamic_dims(void) const;
};
static_assert(sizeof(ShapedType) == sizeof(Type));

class MX_EXPORT FloatType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT;
  }

  static std::optional<FloatType> from(const ::mx::ir::Type &that);
  ::mlir::FloatType underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int width(void) const;
  unsigned int fp_mantissa_width(void) const;
  //const llvm::fltSemantics & float_semantics(void) const;
};
static_assert(sizeof(FloatType) == sizeof(Type));

class MX_EXPORT ComplexType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_COMPLEX;
  }

  static std::optional<ComplexType> from(const ::mx::ir::Type &that);
  ::mlir::ComplexType underlying_repr(void) const noexcept;

  // Imported methods:
  //Type element_type(void) const;
};
static_assert(sizeof(ComplexType) == sizeof(Type));

class MX_EXPORT Float8E5M2Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT8_E5_M2;
  }

  static std::optional<Float8E5M2Type> from(const ::mx::ir::Type &that);
  ::mlir::Float8E5M2Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float8E5M2Type) == sizeof(Type));

class MX_EXPORT Float8E4M3FNType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT8_E4_M3_FN;
  }

  static std::optional<Float8E4M3FNType> from(const ::mx::ir::Type &that);
  ::mlir::Float8E4M3FNType underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float8E4M3FNType) == sizeof(Type));

class MX_EXPORT Float8E5M2FNUZType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT8_E5_M2_FNUZ;
  }

  static std::optional<Float8E5M2FNUZType> from(const ::mx::ir::Type &that);
  ::mlir::Float8E5M2FNUZType underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float8E5M2FNUZType) == sizeof(Type));

class MX_EXPORT Float8E4M3FNUZType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT8_E4_M3_FNUZ;
  }

  static std::optional<Float8E4M3FNUZType> from(const ::mx::ir::Type &that);
  ::mlir::Float8E4M3FNUZType underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float8E4M3FNUZType) == sizeof(Type));

class MX_EXPORT Float8E4M3B11FNUZType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT8_E4_M3_B11_FNUZ;
  }

  static std::optional<Float8E4M3B11FNUZType> from(const ::mx::ir::Type &that);
  ::mlir::Float8E4M3B11FNUZType underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float8E4M3B11FNUZType) == sizeof(Type));

class MX_EXPORT BFloat16Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_B_FLOAT16;
  }

  static std::optional<BFloat16Type> from(const ::mx::ir::Type &that);
  ::mlir::BFloat16Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(BFloat16Type) == sizeof(Type));

class MX_EXPORT Float16Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT16;
  }

  static std::optional<Float16Type> from(const ::mx::ir::Type &that);
  ::mlir::Float16Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float16Type) == sizeof(Type));

class MX_EXPORT FloatTF32Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT_TF32;
  }

  static std::optional<FloatTF32Type> from(const ::mx::ir::Type &that);
  ::mlir::FloatTF32Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(FloatTF32Type) == sizeof(Type));

class MX_EXPORT Float32Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT32;
  }

  static std::optional<Float32Type> from(const ::mx::ir::Type &that);
  ::mlir::Float32Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float32Type) == sizeof(Type));

class MX_EXPORT Float64Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT64;
  }

  static std::optional<Float64Type> from(const ::mx::ir::Type &that);
  ::mlir::Float64Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float64Type) == sizeof(Type));

class MX_EXPORT Float80Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT80;
  }

  static std::optional<Float80Type> from(const ::mx::ir::Type &that);
  ::mlir::Float80Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float80Type) == sizeof(Type));

class MX_EXPORT Float128Type final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FLOAT128;
  }

  static std::optional<Float128Type> from(const ::mx::ir::Type &that);
  ::mlir::Float128Type underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(Float128Type) == sizeof(Type));

class MX_EXPORT FunctionType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_FUNCTION;
  }

  static std::optional<FunctionType> from(const ::mx::ir::Type &that);
  ::mlir::FunctionType underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int num_inputs(void) const;
  unsigned int num_results(void) const;
  //ArrayRef<Type> inputs(void) const;
  //ArrayRef<Type> results(void) const;
};
static_assert(sizeof(FunctionType) == sizeof(Type));

class MX_EXPORT IndexType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_INDEX;
  }

  static std::optional<IndexType> from(const ::mx::ir::Type &that);
  ::mlir::IndexType underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(IndexType) == sizeof(Type));

class MX_EXPORT IntegerType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_INTEGER;
  }

  static std::optional<IntegerType> from(const ::mx::ir::Type &that);
  ::mlir::IntegerType underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_signless(void) const;
  bool is_signed(void) const;
  bool is_unsigned(void) const;
  unsigned int width(void) const;
  //SignednessSemantics signedness(void) const;
};
static_assert(sizeof(IntegerType) == sizeof(Type));

class MX_EXPORT MemRefType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_MEM_REF;
  }

  static std::optional<MemRefType> from(const ::mx::ir::Type &that);
  ::mlir::MemRefType underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int memory_space_as_int(void) const;
  //::llvm::ArrayRef<long long> shape(void) const;
  //Type element_type(void) const;
  //MemRefLayoutAttrInterface layout(void) const;
  //Attribute memory_space(void) const;
};
static_assert(sizeof(MemRefType) == sizeof(Type));

class MX_EXPORT NoneType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_NONE;
  }

  static std::optional<NoneType> from(const ::mx::ir::Type &that);
  ::mlir::NoneType underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(NoneType) == sizeof(Type));

class MX_EXPORT OpaqueType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_OPAQUE;
  }

  static std::optional<OpaqueType> from(const ::mx::ir::Type &that);
  ::mlir::OpaqueType underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr dialect_namespace(void) const;
  std::string_view type_data(void) const;
};
static_assert(sizeof(OpaqueType) == sizeof(Type));

class MX_EXPORT RankedTensorType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_RANKED_TENSOR;
  }

  static std::optional<RankedTensorType> from(const ::mx::ir::Type &that);
  ::mlir::RankedTensorType underlying_repr(void) const noexcept;

  // Imported methods:
  //::llvm::ArrayRef<long long> shape(void) const;
  //Type element_type(void) const;
  //Attribute encoding(void) const;
};
static_assert(sizeof(RankedTensorType) == sizeof(Type));

class MX_EXPORT TupleType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_TUPLE;
  }

  static std::optional<TupleType> from(const ::mx::ir::Type &that);
  ::mlir::TupleType underlying_repr(void) const noexcept;

  // Imported methods:
  //size_t size(void) const;
  //iterator begin(void) const;
  //iterator end(void) const;
  //ArrayRef<Type> types(void) const;
};
static_assert(sizeof(TupleType) == sizeof(Type));

class MX_EXPORT UnrankedMemRefType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_UNRANKED_MEM_REF;
  }

  static std::optional<UnrankedMemRefType> from(const ::mx::ir::Type &that);
  ::mlir::UnrankedMemRefType underlying_repr(void) const noexcept;

  // Imported methods:
  //ArrayRef<long long> shape(void) const;
  unsigned int memory_space_as_int(void) const;
  //Type element_type(void) const;
  //Attribute memory_space(void) const;
};
static_assert(sizeof(UnrankedMemRefType) == sizeof(Type));

class MX_EXPORT UnrankedTensorType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_UNRANKED_TENSOR;
  }

  static std::optional<UnrankedTensorType> from(const ::mx::ir::Type &that);
  ::mlir::UnrankedTensorType underlying_repr(void) const noexcept;

  // Imported methods:
  //ArrayRef<long long> shape(void) const;
  //Type element_type(void) const;
};
static_assert(sizeof(UnrankedTensorType) == sizeof(Type));

class MX_EXPORT VectorType final : public Type {
 public:
  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN_VECTOR;
  }

  static std::optional<VectorType> from(const ::mx::ir::Type &that);
  ::mlir::VectorType underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_scalable(void) const;
  bool all_dims_scalable(void) const;
  bool has_rank(void) const;
  //::llvm::ArrayRef<long long> shape(void) const;
  //Type element_type(void) const;
  //::llvm::ArrayRef<bool> scalable_dims(void) const;
};
static_assert(sizeof(VectorType) == sizeof(Type));

}  // namespace mx::ir::builtin
