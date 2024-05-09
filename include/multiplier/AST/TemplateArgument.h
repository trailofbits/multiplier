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
#include <gap/coro/generator.hpp>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include "../Compiler.h"
#include "../Entity.h"
#include "../Iterator.h"
#include "../Frontend/TokenContext.h"

#include <multiplier/AST/PseudoKind.h>
#include <multiplier/AST/TemplateArgumentKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class Expr;
class File;
class TemplateArgument;
class TemplateArgumentImpl;
class Token;
class Type;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TemplateArgument {
 public:
  std::optional<Decl> parent_declaration(void) const;
  std::optional<Stmt> parent_statement(void) const;
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
  friend class TemplateArgumentImpl;
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const TemplateArgumentImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  TemplateArgument(TemplateArgument &&) noexcept = default;
  TemplateArgument(const TemplateArgument &) = default;
  TemplateArgument &operator=(TemplateArgument &&) noexcept = default;
  TemplateArgument &operator=(const TemplateArgument &) = default;

  inline bool operator==(const TemplateArgument &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline TemplateArgument(std::shared_ptr<const TemplateArgumentImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::TEMPLATE_ARGUMENT;
  }

  PackedTemplateArgumentId id(void) const;

  inline static std::optional<TemplateArgument> from(const TemplateArgument &self) {
    return self;
  }

  inline static std::optional<TemplateArgument> from(const std::optional<TemplateArgument> &self) {
    return self;
  }

  static std::optional<TemplateArgument> from(const Reference &r);
  static std::optional<TemplateArgument> from(const VariantEntity &e);
  static std::optional<TemplateArgument> from(const TokenContext &t);

  TemplateArgumentKind kind(void) const;
  bool is_empty(void) const;
  bool is_dependent(void) const;
  bool is_instantiation_dependent(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  std::optional<ValueDecl> declaration(void) const;
  std::optional<Type> type(void) const;
  std::optional<Type> parameter_type_for_declaration(void) const;
  std::optional<Type> null_pointer_type(void) const;
  std::optional<Expr> expression(void) const;
  std::optional<TemplateArgument> nth_pack_argument(unsigned n) const;
  unsigned num_pack_arguments(void) const;
  gap::generator<TemplateArgument> pack_arguments(void) const &;
};

#endif
} // namespace mx
