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

namespace mx {
class Expr;
class NamedDecl;
class Reference;
class SourceIR;
class TemplateParameterList;
class TemplateParameterListImpl;
class TokenRange;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateParameterList {
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
  friend class TemplateParameterListImpl;
  std::shared_ptr<const TemplateParameterListImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  TemplateParameterList(TemplateParameterList &&) noexcept = default;
  TemplateParameterList(const TemplateParameterList &) = default;
  TemplateParameterList &operator=(TemplateParameterList &&) noexcept = default;
  TemplateParameterList &operator=(const TemplateParameterList &) = default;

  friend inline std::strong_ordering operator<=>(const TemplateParameterList &lhs, const TemplateParameterList &rhs) noexcept {
    return lhs.id().Pack() <=> rhs.id().Pack();
  }

  bool operator==(const TemplateParameterList &) const noexcept = default;
  bool operator!=(const TemplateParameterList &) const noexcept = default;

  /* implicit */ inline TemplateParameterList(std::shared_ptr<const TemplateParameterListImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::TEMPLATE_PARAMETER_LIST;
  }

  PackedTemplateParameterListId id(void) const;
  gap::generator<Reference> references(void) const &;

  inline static std::optional<TemplateParameterList> from(const TemplateParameterList &self) {
    return self;
  }

  inline static std::optional<TemplateParameterList> from(const std::optional<TemplateParameterList> &self) {
    return self;
  }

  inline static std::optional<TemplateParameterList> from(const Reference &r) {
    return r.as_template_parameter_list();
  }

  inline static std::optional<TemplateParameterList> from(const TokenContext &t) {
    return t.as_template_parameter_list();
  }

  unsigned num_parameters(void) const;
  unsigned num_required_parameters(void) const;
  unsigned depth(void) const;
  bool has_unexpanded_parameter_pack(void) const;
  bool has_parameter_pack(void) const;
  std::optional<Expr> requires_clause(void) const;
  Token template_keyword_token(void) const;
  Token left_angle_token(void) const;
  Token right_angle_token(void) const;
  TokenRange tokens(void) const;
  std::optional<NamedDecl> nth_parameter(unsigned n) const;
  gap::generator<NamedDecl> parameters(void) const &;
};

#endif
} // namespace mx
