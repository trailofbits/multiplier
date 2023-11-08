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

#include "../Iterator.h"
#include "../Types.h"

#include "StmtKind.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class File;
class Fragment;
class Index;
class Reference;
class Stmt;
class StmtImpl;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Stmt {
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
  friend class TokenContext;
  friend class Type;
  friend class StmtImpl;
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const StmtImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  Stmt(Stmt &&) noexcept = default;
  Stmt(const Stmt &) = default;
  Stmt &operator=(Stmt &&) noexcept = default;
  Stmt &operator=(const Stmt &) = default;

  inline bool operator==(const Stmt &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline Stmt(std::shared_ptr<const StmtImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::STATEMENT;
  }

  PackedStmtId id(void) const;
  gap::generator<Reference> references(void) const &;

  std::optional<PackedDeclId> referenced_declaration_id(void) const;
  std::optional<Decl> referenced_declaration(void) const;
 public:
  static gap::generator<Stmt> in(const Index &index, std::span<StmtKind> kinds);
  static gap::generator<Stmt> in(const Fragment &frag, std::span<StmtKind> kinds);
  static gap::generator<Stmt> in(const File &file, std::span<StmtKind> kinds);
  static gap::generator<Stmt> in(const Index &index);
  static gap::generator<Stmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Stmt> by_id(const Index &, EntityId);
  static gap::generator<Stmt> in(const Fragment &frag);
  static gap::generator<Stmt> in(const File &file);

  static gap::generator<Stmt> containing(const Decl &decl);
  static gap::generator<Stmt> containing(const std::optional<Decl> &decl);

  static gap::generator<Stmt> containing(const Stmt &stmt);
  static gap::generator<Stmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<Stmt> from(const Stmt &self) {
    return self;
  }

  inline static std::optional<Stmt> from(const std::optional<Stmt> &self) {
    return self;
  }

  static std::optional<Stmt> from(const Reference &r);

  static std::optional<Stmt> from(const TokenContext &t);

  Stmt ignore_containers(void) const;
  gap::generator<Stmt> children(void) const &;
  TokenRange tokens(void) const;
  StmtKind kind(void) const;
  Stmt strip_label_like_statements(void) const;
};

#endif
} // namespace mx
