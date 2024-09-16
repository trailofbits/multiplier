// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Attribute.h"

namespace mlir {
class TypedAttr;
class ElementsAttr;
class AffineMapAttr;
class ArrayAttr;
class DenseArrayAttr;
class DenseIntOrFPElementsAttr;
class DenseStringElementsAttr;
class DenseResourceElementsAttr;
class DictionaryAttr;
class FloatAttr;
class IntegerAttr;
class IntegerSetAttr;
class OpaqueAttr;
class SparseElementsAttr;
class StridedLayoutAttr;
class StringAttr;
class SymbolRefAttr;
class TypeAttr;
class UnitAttr;
class BoolAttr;
class FlatSymbolRefAttr;
class DenseIntElementsAttr;
class DataLayoutSpecAttr;
}  // namespace mlir
namespace mx::ir::builtin {

class MX_EXPORT Attribute : public ::mx::ir::Attribute {
 public:
  static std::optional<Attribute> from(const ::mx::ir::Attribute &);
};
static_assert(sizeof(Attribute) == sizeof(::mx::ir::Attribute));

class MX_EXPORT TypedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_TYPED;
  }

  static std::optional<TypedAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::TypedAttr underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Type type(void) const;
};
static_assert(sizeof(TypedAttr) == sizeof(Attribute));

class MX_EXPORT ElementsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_ELEMENTS;
  }

  static std::optional<ElementsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::ElementsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_splat(void) const;
  //::mlir::ShapedType shaped_type(void) const;
  //Type element_type(void) const;
  int64_t num_elements(void) const;
  int64_t size(void) const;
  bool empty(void) const;
  ::mx::ir::Type type(void) const;
};
static_assert(sizeof(ElementsAttr) == sizeof(Attribute));

class MX_EXPORT AffineMapAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_AFFINE_MAP;
  }

  static std::optional<AffineMapAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::AffineMapAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //AffineMap affine_map(void) const;
  //AffineMap value(void) const;
};
static_assert(sizeof(AffineMapAttr) == sizeof(Attribute));

class MX_EXPORT ArrayAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_ARRAY;
  }

  static std::optional<ArrayAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::ArrayAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //iterator begin(void) const;
  //iterator end(void) const;
  size_t size(void) const;
  bool empty(void) const;
  //::llvm::ArrayRef<Attribute> value(void) const;
};
static_assert(sizeof(ArrayAttr) == sizeof(Attribute));

class MX_EXPORT DenseArrayAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_DENSE_ARRAY;
  }

  static std::optional<DenseArrayAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::DenseArrayAttr underlying_repr(void) const noexcept;

  // Imported methods:
  int64_t size(void) const;
  bool empty(void) const;
  //Type element_type(void) const;
  //::llvm::ArrayRef<char> raw_data(void) const;
};
static_assert(sizeof(DenseArrayAttr) == sizeof(Attribute));

class MX_EXPORT DenseIntOrFPElementsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_DENSE_INT_OR_FP_ELEMENTS;
  }

  static std::optional<DenseIntOrFPElementsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::DenseIntOrFPElementsAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(DenseIntOrFPElementsAttr) == sizeof(Attribute));

class MX_EXPORT DenseStringElementsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_DENSE_STRING_ELEMENTS;
  }

  static std::optional<DenseStringElementsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::DenseStringElementsAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(DenseStringElementsAttr) == sizeof(Attribute));

class MX_EXPORT DenseResourceElementsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_DENSE_RESOURCE_ELEMENTS;
  }

  static std::optional<DenseResourceElementsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::DenseResourceElementsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //ShapedType type(void) const;
  //DenseResourceElementsHandle raw_handle(void) const;
};
static_assert(sizeof(DenseResourceElementsAttr) == sizeof(Attribute));

class MX_EXPORT DictionaryAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_DICTIONARY;
  }

  static std::optional<DictionaryAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::DictionaryAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //iterator begin(void) const;
  //iterator end(void) const;
  bool empty(void) const;
  size_t size(void) const;
  //::llvm::ArrayRef<NamedAttribute> value(void) const;
};
static_assert(sizeof(DictionaryAttr) == sizeof(Attribute));

class MX_EXPORT FloatAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_FLOAT;
  }

  static std::optional<FloatAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::FloatAttr underlying_repr(void) const noexcept;

  // Imported methods:
  double value_as_double(void) const;
  ::mx::ir::Type type(void) const;
  //::llvm::APFloat value(void) const;
};
static_assert(sizeof(FloatAttr) == sizeof(Attribute));

class MX_EXPORT IntegerAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_INTEGER;
  }

  static std::optional<IntegerAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::IntegerAttr underlying_repr(void) const noexcept;

  // Imported methods:
  int64_t integer_value(void) const;
  int64_t signed_integer_value(void) const;
  uint64_t unsigned_integer_value(void) const;
  //APSInt aps_int(void) const;
  ::mx::ir::Type type(void) const;
  //APInt value(void) const;
};
static_assert(sizeof(IntegerAttr) == sizeof(Attribute));

class MX_EXPORT IntegerSetAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_INTEGER_SET;
  }

  static std::optional<IntegerSetAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::IntegerSetAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //IntegerSet value(void) const;
};
static_assert(sizeof(IntegerSetAttr) == sizeof(Attribute));

class MX_EXPORT OpaqueAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_OPAQUE;
  }

  static std::optional<OpaqueAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::OpaqueAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr dialect_namespace(void) const;
  std::string_view attr_data(void) const;
  ::mx::ir::Type type(void) const;
};
static_assert(sizeof(OpaqueAttr) == sizeof(Attribute));

class MX_EXPORT SparseElementsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_SPARSE_ELEMENTS;
  }

  static std::optional<SparseElementsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::SparseElementsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //APFloat zero_ap_float(void) const;
  //APInt zero_ap_int(void) const;
  //Attribute zero_attr(void) const;
  //std::vector<long, allocator<long>> flattened_sparse_indices(void) const;
  //ShapedType type(void) const;
  //DenseIntElementsAttr indices(void) const;
  //DenseElementsAttr values(void) const;
};
static_assert(sizeof(SparseElementsAttr) == sizeof(Attribute));

class MX_EXPORT StridedLayoutAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_STRIDED_LAYOUT;
  }

  static std::optional<StridedLayoutAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::StridedLayoutAttr underlying_repr(void) const noexcept;

  // Imported methods:
  int64_t offset(void) const;
  //::llvm::ArrayRef<long long> strides(void) const;
  //::mlir::AffineMap affine_map(void) const;
};
static_assert(sizeof(StridedLayoutAttr) == sizeof(Attribute));

class MX_EXPORT StringAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_STRING;
  }

  static std::optional<StringAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::StringAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //Dialect * referenced_dialect(void) const;
  //StringRef strref(void) const;
  std::string str(void) const;
  //const char * data(void) const;
  size_t size(void) const;
  bool empty(void) const;
  //StringRef::iterator begin(void) const;
  //StringRef::iterator end(void) const;
  std::string_view value(void) const;
  ::mx::ir::Type type(void) const;
};
static_assert(sizeof(StringAttr) == sizeof(Attribute));

class MX_EXPORT SymbolRefAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_SYMBOL_REF;
  }

  static std::optional<SymbolRefAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::SymbolRefAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr leaf_reference(void) const;
  //StringAttr root_reference(void) const;
  //::llvm::ArrayRef<FlatSymbolRefAttr> nested_references(void) const;
};
static_assert(sizeof(SymbolRefAttr) == sizeof(Attribute));

class MX_EXPORT TypeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_TYPE;
  }

  static std::optional<TypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::TypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //Type value(void) const;
};
static_assert(sizeof(TypeAttr) == sizeof(Attribute));

class MX_EXPORT UnitAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_UNIT;
  }

  static std::optional<UnitAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::UnitAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(UnitAttr) == sizeof(Attribute));

class MX_EXPORT BoolAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_BOOL;
  }

  static std::optional<BoolAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::BoolAttr underlying_repr(void) const noexcept;

  // Imported methods:
  bool value(void) const;
};
static_assert(sizeof(BoolAttr) == sizeof(Attribute));

class MX_EXPORT FlatSymbolRefAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_FLAT_SYMBOL_REF;
  }

  static std::optional<FlatSymbolRefAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::FlatSymbolRefAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr attr(void) const;
  //StringRef value(void) const;
};
static_assert(sizeof(FlatSymbolRefAttr) == sizeof(Attribute));

class MX_EXPORT DenseIntElementsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_DENSE_INT_ELEMENTS;
  }

  static std::optional<DenseIntElementsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::DenseIntElementsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //iterator begin(void) const;
  //iterator end(void) const;
};
static_assert(sizeof(DenseIntElementsAttr) == sizeof(Attribute));

class MX_EXPORT DataLayoutSpecAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::BUILTIN_DATA_LAYOUT_SPEC;
  }

  static std::optional<DataLayoutSpecAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::DataLayoutSpecAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DataLayoutEntryListRef entries(void) const;
};
static_assert(sizeof(DataLayoutSpecAttr) == sizeof(Attribute));

}  // namespace mx::ir::builtin
