// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Builtin/Attribute.h>

#include <multiplier/IR/Type.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::builtin {
std::optional<Attribute> Attribute::from(const ::mx::ir::Attribute &that) {
  if (IsBuiltinAttributeKind(that.kind())) {
    return reinterpret_cast<const Attribute &>(that);
  }
  return std::nullopt;
}

std::optional<TypedAttr> TypedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_TYPED) {
    return reinterpret_cast<const TypedAttr &>(that);
  }
  return std::nullopt;
}

::mlir::TypedAttr TypedAttr::underlying_repr(void) const noexcept {
  return ::mlir::TypedAttr(this->::mx::ir::Attribute::attr_);
}

::mx::ir::Type TypedAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<ElementsAttr> ElementsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_ELEMENTS) {
    return reinterpret_cast<const ElementsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::ElementsAttr ElementsAttr::underlying_repr(void) const noexcept {
  return ::mlir::ElementsAttr(this->::mx::ir::Attribute::attr_);
}

bool ElementsAttr::is_splat(void) const {
  auto val = underlying_repr().isSplat();
  return val;
}

int64_t ElementsAttr::num_elements(void) const {
  auto val = underlying_repr().getNumElements();
  return val;
}

int64_t ElementsAttr::size(void) const {
  auto val = underlying_repr().size();
  return val;
}

bool ElementsAttr::empty(void) const {
  auto val = underlying_repr().empty();
  return val;
}

::mx::ir::Type ElementsAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<AffineMapAttr> AffineMapAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_AFFINE_MAP) {
    return reinterpret_cast<const AffineMapAttr &>(that);
  }
  return std::nullopt;
}

::mlir::AffineMapAttr AffineMapAttr::underlying_repr(void) const noexcept {
  return ::mlir::AffineMapAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<ArrayAttr> ArrayAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_ARRAY) {
    return reinterpret_cast<const ArrayAttr &>(that);
  }
  return std::nullopt;
}

::mlir::ArrayAttr ArrayAttr::underlying_repr(void) const noexcept {
  return ::mlir::ArrayAttr(this->::mx::ir::Attribute::attr_);
}

bool ArrayAttr::empty(void) const {
  auto val = underlying_repr().empty();
  return val;
}

std::optional<DenseArrayAttr> DenseArrayAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_DENSE_ARRAY) {
    return reinterpret_cast<const DenseArrayAttr &>(that);
  }
  return std::nullopt;
}

::mlir::DenseArrayAttr DenseArrayAttr::underlying_repr(void) const noexcept {
  return ::mlir::DenseArrayAttr(this->::mx::ir::Attribute::attr_);
}

int64_t DenseArrayAttr::size(void) const {
  auto val = underlying_repr().size();
  return val;
}

bool DenseArrayAttr::empty(void) const {
  auto val = underlying_repr().empty();
  return val;
}

std::optional<DenseIntOrFPElementsAttr> DenseIntOrFPElementsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_DENSE_INT_OR_FP_ELEMENTS) {
    return reinterpret_cast<const DenseIntOrFPElementsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::DenseIntOrFPElementsAttr DenseIntOrFPElementsAttr::underlying_repr(void) const noexcept {
  return ::mlir::DenseIntOrFPElementsAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DenseStringElementsAttr> DenseStringElementsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_DENSE_STRING_ELEMENTS) {
    return reinterpret_cast<const DenseStringElementsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::DenseStringElementsAttr DenseStringElementsAttr::underlying_repr(void) const noexcept {
  return ::mlir::DenseStringElementsAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DenseResourceElementsAttr> DenseResourceElementsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_DENSE_RESOURCE_ELEMENTS) {
    return reinterpret_cast<const DenseResourceElementsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::DenseResourceElementsAttr DenseResourceElementsAttr::underlying_repr(void) const noexcept {
  return ::mlir::DenseResourceElementsAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DictionaryAttr> DictionaryAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_DICTIONARY) {
    return reinterpret_cast<const DictionaryAttr &>(that);
  }
  return std::nullopt;
}

::mlir::DictionaryAttr DictionaryAttr::underlying_repr(void) const noexcept {
  return ::mlir::DictionaryAttr(this->::mx::ir::Attribute::attr_);
}

bool DictionaryAttr::empty(void) const {
  auto val = underlying_repr().empty();
  return val;
}

std::optional<FloatAttr> FloatAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_FLOAT) {
    return reinterpret_cast<const FloatAttr &>(that);
  }
  return std::nullopt;
}

::mlir::FloatAttr FloatAttr::underlying_repr(void) const noexcept {
  return ::mlir::FloatAttr(this->::mx::ir::Attribute::attr_);
}

double FloatAttr::value_as_double(void) const {
  auto val = underlying_repr().getValueAsDouble();
  return val;
}

::mx::ir::Type FloatAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<IntegerAttr> IntegerAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_INTEGER) {
    return reinterpret_cast<const IntegerAttr &>(that);
  }
  return std::nullopt;
}

::mlir::IntegerAttr IntegerAttr::underlying_repr(void) const noexcept {
  return ::mlir::IntegerAttr(this->::mx::ir::Attribute::attr_);
}

int64_t IntegerAttr::int_(void) const {
  auto val = underlying_repr().getInt();
  return val;
}

int64_t IntegerAttr::s_int(void) const {
  auto val = underlying_repr().getSInt();
  return val;
}

uint64_t IntegerAttr::u_int(void) const {
  auto val = underlying_repr().getUInt();
  return val;
}

::mx::ir::Type IntegerAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<IntegerSetAttr> IntegerSetAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_INTEGER_SET) {
    return reinterpret_cast<const IntegerSetAttr &>(that);
  }
  return std::nullopt;
}

::mlir::IntegerSetAttr IntegerSetAttr::underlying_repr(void) const noexcept {
  return ::mlir::IntegerSetAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<OpaqueAttr> OpaqueAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_OPAQUE) {
    return reinterpret_cast<const OpaqueAttr &>(that);
  }
  return std::nullopt;
}

::mlir::OpaqueAttr OpaqueAttr::underlying_repr(void) const noexcept {
  return ::mlir::OpaqueAttr(this->::mx::ir::Attribute::attr_);
}

std::string_view OpaqueAttr::attr_data(void) const {
  auto val = underlying_repr().getAttrData();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type OpaqueAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<SparseElementsAttr> SparseElementsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_SPARSE_ELEMENTS) {
    return reinterpret_cast<const SparseElementsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::SparseElementsAttr SparseElementsAttr::underlying_repr(void) const noexcept {
  return ::mlir::SparseElementsAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<StridedLayoutAttr> StridedLayoutAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_STRIDED_LAYOUT) {
    return reinterpret_cast<const StridedLayoutAttr &>(that);
  }
  return std::nullopt;
}

::mlir::StridedLayoutAttr StridedLayoutAttr::underlying_repr(void) const noexcept {
  return ::mlir::StridedLayoutAttr(this->::mx::ir::Attribute::attr_);
}

int64_t StridedLayoutAttr::offset(void) const {
  auto val = underlying_repr().getOffset();
  return val;
}

std::optional<StringAttr> StringAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_STRING) {
    return reinterpret_cast<const StringAttr &>(that);
  }
  return std::nullopt;
}

::mlir::StringAttr StringAttr::underlying_repr(void) const noexcept {
  return ::mlir::StringAttr(this->::mx::ir::Attribute::attr_);
}

std::string StringAttr::str(void) const {
  auto val = underlying_repr().str();
  return val;
}

bool StringAttr::empty(void) const {
  auto val = underlying_repr().empty();
  return val;
}

std::string_view StringAttr::value(void) const {
  auto val = underlying_repr().getValue();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type StringAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<SymbolRefAttr> SymbolRefAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_SYMBOL_REF) {
    return reinterpret_cast<const SymbolRefAttr &>(that);
  }
  return std::nullopt;
}

::mlir::SymbolRefAttr SymbolRefAttr::underlying_repr(void) const noexcept {
  return ::mlir::SymbolRefAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<TypeAttr> TypeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_TYPE) {
    return reinterpret_cast<const TypeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::TypeAttr TypeAttr::underlying_repr(void) const noexcept {
  return ::mlir::TypeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<UnitAttr> UnitAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_UNIT) {
    return reinterpret_cast<const UnitAttr &>(that);
  }
  return std::nullopt;
}

::mlir::UnitAttr UnitAttr::underlying_repr(void) const noexcept {
  return ::mlir::UnitAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<BoolAttr> BoolAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_BOOL) {
    return reinterpret_cast<const BoolAttr &>(that);
  }
  return std::nullopt;
}

::mlir::BoolAttr BoolAttr::underlying_repr(void) const noexcept {
  return ::mlir::BoolAttr(this->::mx::ir::Attribute::attr_);
}

bool BoolAttr::value(void) const {
  auto val = underlying_repr().getValue();
  return val;
}

std::optional<FlatSymbolRefAttr> FlatSymbolRefAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_FLAT_SYMBOL_REF) {
    return reinterpret_cast<const FlatSymbolRefAttr &>(that);
  }
  return std::nullopt;
}

::mlir::FlatSymbolRefAttr FlatSymbolRefAttr::underlying_repr(void) const noexcept {
  return ::mlir::FlatSymbolRefAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DenseIntElementsAttr> DenseIntElementsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::BUILTIN_DENSE_INT_ELEMENTS) {
    return reinterpret_cast<const DenseIntElementsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::DenseIntElementsAttr DenseIntElementsAttr::underlying_repr(void) const noexcept {
  return ::mlir::DenseIntElementsAttr(this->::mx::ir::Attribute::attr_);
}

}  // namespace mx::ir::builtin
