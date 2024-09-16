// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Core/Attribute.h>

#include <multiplier/IR/Type.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <vast/Dialect/Dialects.hpp>

namespace mx::ir::core {
std::optional<Attribute> Attribute::from(const ::mx::ir::Attribute &that) {
  if (IsCoreAttributeKind(that.kind())) {
    return reinterpret_cast<const Attribute &>(that);
  }
  return std::nullopt;
}

std::optional<BooleanAttr> BooleanAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_BOOLEAN) {
    return reinterpret_cast<const BooleanAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::BooleanAttr BooleanAttr::underlying_repr(void) const noexcept {
  return ::vast::core::BooleanAttr(this->::mx::ir::Attribute::attr_);
}

::mx::ir::Type BooleanAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool BooleanAttr::value(void) const {
  auto val = underlying_repr().getValue();
  return val;
}

std::optional<IntegerAttr> IntegerAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_INTEGER) {
    return reinterpret_cast<const IntegerAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::IntegerAttr IntegerAttr::underlying_repr(void) const noexcept {
  return ::vast::core::IntegerAttr(this->::mx::ir::Attribute::attr_);
}

::mx::ir::Type IntegerAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<FloatAttr> FloatAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_FLOAT) {
    return reinterpret_cast<const FloatAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::FloatAttr FloatAttr::underlying_repr(void) const noexcept {
  return ::vast::core::FloatAttr(this->::mx::ir::Attribute::attr_);
}

::mx::ir::Type FloatAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<VoidAttr> VoidAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_VOID) {
    return reinterpret_cast<const VoidAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::VoidAttr VoidAttr::underlying_repr(void) const noexcept {
  return ::vast::core::VoidAttr(this->::mx::ir::Attribute::attr_);
}

::mx::ir::Type VoidAttr::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<SourceLanguageAttr> SourceLanguageAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_SOURCE_LANGUAGE) {
    return reinterpret_cast<const SourceLanguageAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::SourceLanguageAttr SourceLanguageAttr::underlying_repr(void) const noexcept {
  return ::vast::core::SourceLanguageAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<GlobalLinkageKindAttr> GlobalLinkageKindAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_GLOBAL_LINKAGE_KIND) {
    return reinterpret_cast<const GlobalLinkageKindAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::GlobalLinkageKindAttr GlobalLinkageKindAttr::underlying_repr(void) const noexcept {
  return ::vast::core::GlobalLinkageKindAttr(this->::mx::ir::Attribute::attr_);
}

}  // namespace mx::ir::core
