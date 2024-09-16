// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Attribute.h"

namespace vast::core {
class BooleanAttr;
class IntegerAttr;
class FloatAttr;
class VoidAttr;
class SourceLanguageAttr;
class GlobalLinkageKindAttr;
}  // namespace vast::core
namespace mx::ir::core {

class MX_EXPORT Attribute : public ::mx::ir::Attribute {
 public:
  static std::optional<Attribute> from(const ::mx::ir::Attribute &);
};
static_assert(sizeof(Attribute) == sizeof(::mx::ir::Attribute));

class MX_EXPORT BooleanAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::CORE_BOOLEAN;
  }

  static std::optional<BooleanAttr> from(const ::mx::ir::Attribute &that);

  ::vast::core::BooleanAttr underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Type type(void) const;
  bool value(void) const;
};
static_assert(sizeof(BooleanAttr) == sizeof(Attribute));

class MX_EXPORT IntegerAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::CORE_INTEGER;
  }

  static std::optional<IntegerAttr> from(const ::mx::ir::Attribute &that);

  ::vast::core::IntegerAttr underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Type type(void) const;
  //::llvm::APSInt value(void) const;
};
static_assert(sizeof(IntegerAttr) == sizeof(Attribute));

class MX_EXPORT FloatAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::CORE_FLOAT;
  }

  static std::optional<FloatAttr> from(const ::mx::ir::Attribute &that);

  ::vast::core::FloatAttr underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Type type(void) const;
  //::llvm::APFloat value(void) const;
};
static_assert(sizeof(FloatAttr) == sizeof(Attribute));

class MX_EXPORT VoidAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::CORE_VOID;
  }

  static std::optional<VoidAttr> from(const ::mx::ir::Attribute &that);

  ::vast::core::VoidAttr underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Type type(void) const;
};
static_assert(sizeof(VoidAttr) == sizeof(Attribute));

class MX_EXPORT SourceLanguageAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::CORE_SOURCE_LANGUAGE;
  }

  static std::optional<SourceLanguageAttr> from(const ::mx::ir::Attribute &that);

  ::vast::core::SourceLanguageAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::vast::core::SourceLanguage value(void) const;
};
static_assert(sizeof(SourceLanguageAttr) == sizeof(Attribute));

class MX_EXPORT GlobalLinkageKindAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::CORE_GLOBAL_LINKAGE_KIND;
  }

  static std::optional<GlobalLinkageKindAttr> from(const ::mx::ir::Attribute &that);

  ::vast::core::GlobalLinkageKindAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::vast::core::GlobalLinkageKind value(void) const;
};
static_assert(sizeof(GlobalLinkageKindAttr) == sizeof(Attribute));

}  // namespace mx::ir::core
