// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Core/Attribute.h>

#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::core {
std::optional<Attribute> Attribute::from(const ::mx::ir::Attribute &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::AttributeKind::CORE_BOOLEAN:
    case mx::ir::AttributeKind::CORE_FLOAT:
    case mx::ir::AttributeKind::CORE_INTEGER:
    case mx::ir::AttributeKind::CORE_SOURCE_LANGUAGE:
    case mx::ir::AttributeKind::CORE_STRING_LITERAL:
    case mx::ir::AttributeKind::CORE_VOID:
      return reinterpret_cast<const Attribute &>(that);
  }
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

bool BooleanAttr::value(void) const {
  auto val = underlying_repr().getValue();
  return val;
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

std::optional<IntegerAttr> IntegerAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_INTEGER) {
    return reinterpret_cast<const IntegerAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::IntegerAttr IntegerAttr::underlying_repr(void) const noexcept {
  return ::vast::core::IntegerAttr(this->::mx::ir::Attribute::attr_);
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

std::optional<StringLiteralAttr> StringLiteralAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::CORE_STRING_LITERAL) {
    return reinterpret_cast<const StringLiteralAttr &>(that);
  }
  return std::nullopt;
}

::vast::core::StringLiteralAttr StringLiteralAttr::underlying_repr(void) const noexcept {
  return ::vast::core::StringLiteralAttr(this->::mx::ir::Attribute::attr_);
}

std::string_view StringLiteralAttr::value(void) const {
  auto val = underlying_repr().getValue();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
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

}  // namespace mx::ir::core
