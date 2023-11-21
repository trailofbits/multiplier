// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <compare>
#include <cstdint>
#include <filesystem>
#include <gap/core/generator.hpp>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include "../Entity.h"
#include "../Iterator.h"

#include "PseudoKind.h"

namespace mx {
class EntityProvider;
class Index;
class Expr;
class File;
class Fragment;
class NamedDecl;
class Reference;
class TemplateParameterList;
class TemplateParameterListImpl;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateParameterList {
 public:
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class TemplateParameterListImpl;
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const TemplateParameterListImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  TemplateParameterList(TemplateParameterList &&) noexcept = default;
  TemplateParameterList(const TemplateParameterList &) = default;
  TemplateParameterList &operator=(TemplateParameterList &&) noexcept = default;
  TemplateParameterList &operator=(const TemplateParameterList &) = default;

  inline bool operator==(const TemplateParameterList &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline TemplateParameterList(std::shared_ptr<const TemplateParameterListImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::TEMPLATE_PARAMETER_LIST;
  }

  PackedTemplateParameterListId id(void) const;

  inline static std::optional<TemplateParameterList> from(const TemplateParameterList &self) {
    return self;
  }

  inline static std::optional<TemplateParameterList> from(const std::optional<TemplateParameterList> &self) {
    return self;
  }

  static std::optional<TemplateParameterList> from(const Reference &r);
  static std::optional<TemplateParameterList> from(const VariantEntity &e);
  static std::optional<TemplateParameterList> from(const TokenContext &t);

  uint32_t depth(void) const;
  bool has_unexpanded_parameter_pack(void) const;
  bool has_parameter_pack(void) const;
  std::optional<Expr> requires_clause(void) const;
  Token template_keyword_token(void) const;
  Token left_angle_token(void) const;
  Token right_angle_token(void) const;
  TokenRange tokens(void) const;
  std::optional<NamedDecl> nth_parameter(unsigned n) const;
  unsigned num_parameters(void) const;
  gap::generator<NamedDecl> parameters(void) const &;
};

#endif
} // namespace mx
