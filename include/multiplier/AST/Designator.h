// Copyright (c) 2022-present, Trail of Bits, Inc.
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

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class Designator;
class DesignatorImpl;
class FieldDecl;
class File;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT Designator {
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
  friend class DesignatorImpl;
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const DesignatorImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  Designator(Designator &&) noexcept = default;
  Designator(const Designator &) = default;
  Designator &operator=(Designator &&) noexcept = default;
  Designator &operator=(const Designator &) = default;

  inline bool operator==(const Designator &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline Designator(std::shared_ptr<const DesignatorImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::DESIGNATOR;
  }

  PackedDesignatorId id(void) const;

  static gap::generator<Designator> in(const Index &index);
  static gap::generator<Designator> in(const Fragment &frag);
  static gap::generator<Designator> in(const File &file);
  static gap::generator<Designator> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<Designator> by_id(const Index &, EntityId);

  inline static std::optional<Designator> from(const Designator &self) {
    return self;
  }

  inline static std::optional<Designator> from(const std::optional<Designator> &self) {
    return self;
  }

  static std::optional<Designator> from(const Reference &r);
  static std::optional<Designator> from(const VariantEntity &e);
  static std::optional<Designator> from(const TokenContext &t);

  bool is_field_designator(void) const;
  bool is_array_designator(void) const;
  bool is_array_range_designator(void) const;
  std::optional<FieldDecl> field(void) const;
  TokenRange tokens(void) const;
  Token dot_token(void) const;
  Token field_token(void) const;
  Token left_bracket_token(void) const;
  Token right_bracket_token(void) const;
  Token ellipsis_token(void) const;
};

#endif
} // namespace mx
