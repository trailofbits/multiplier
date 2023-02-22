// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include <compare>

#include "PseudoKind.h"
#include "TemplateArgumentKind.h"

namespace mx {
class Reference;
class SourceIR;
class TemplateArgument;
class TemplateArgumentImpl;
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateArgument {
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class SourceIR;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class TemplateArgumentImpl;
  std::shared_ptr<const TemplateArgumentImpl> impl;
  inline static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  inline static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  inline static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  TemplateArgument(TemplateArgument &&) noexcept = default;
  TemplateArgument(const TemplateArgument &) = default;
  TemplateArgument &operator=(TemplateArgument &&) noexcept = default;
  TemplateArgument &operator=(const TemplateArgument &) = default;

  friend inline std::strong_ordering operator<=>(const TemplateArgument &lhs, const TemplateArgument &rhs) noexcept {
    return lhs.id().Pack() <=> rhs.id().Pack();
  }

  bool operator==(const TemplateArgument &) const noexcept = default;
  bool operator!=(const TemplateArgument &) const noexcept = default;

  /* implicit */ inline TemplateArgument(std::shared_ptr<const TemplateArgumentImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::TEMPLATE_ARGUMENT;
  }

  PackedTemplateArgumentId id(void) const;
  gap::generator<Reference> references(void) const &;

  inline static std::optional<TemplateArgument> from(const TemplateArgument &self) {
    return self;
  }

  inline static std::optional<TemplateArgument> from(const std::optional<TemplateArgument> &self) {
    return self;
  }

  inline static std::optional<TemplateArgument> from(const Reference &r) {
    return r.as_template_argument();
  }

  inline static std::optional<TemplateArgument> from(const TokenContext &t) {
    return t.as_template_argument();
  }

  TemplateArgumentKind kind(void) const;
  bool is_null(void) const;
  bool is_dependent(void) const;
  bool is_instantiation_dependent(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  std::optional<ValueDecl> as_declaration(void) const;
  std::optional<Type> as_type(void) const;
  std::optional<Type> parameter_type_for_declaration(void) const;
  std::optional<Type> null_pointer_type(void) const;
};

#endif
} // namespace mx
