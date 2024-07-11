// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>
#include <multiplier/AST/StorageDuration.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class File;
class LifetimeExtendedTemporaryDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT LifetimeExtendedTemporaryDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<LifetimeExtendedTemporaryDecl> in(const Index &index);
  static gap::generator<LifetimeExtendedTemporaryDecl> in(const Fragment &frag);
  static gap::generator<LifetimeExtendedTemporaryDecl> in(const File &file);
  static gap::generator<LifetimeExtendedTemporaryDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<LifetimeExtendedTemporaryDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<LifetimeExtendedTemporaryDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::LIFETIME_EXTENDED_TEMPORARY;
  }

  static gap::generator<LifetimeExtendedTemporaryDecl> containing(const Decl &decl);
  static gap::generator<LifetimeExtendedTemporaryDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<LifetimeExtendedTemporaryDecl> containing(const Stmt &stmt);
  static gap::generator<LifetimeExtendedTemporaryDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  LifetimeExtendedTemporaryDecl canonical_declaration(void) const;
  std::optional<LifetimeExtendedTemporaryDecl> definition(void) const;
  gap::generator<LifetimeExtendedTemporaryDecl> redeclarations(void) const &;
  static std::optional<LifetimeExtendedTemporaryDecl> by_id(const Index &, EntityId);

  static std::optional<LifetimeExtendedTemporaryDecl> from_base(const Decl &parent);
  inline static std::optional<LifetimeExtendedTemporaryDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<LifetimeExtendedTemporaryDecl> from(const std::optional<Decl> &parent);
  static std::optional<LifetimeExtendedTemporaryDecl> from(const Reference &r);
  static std::optional<LifetimeExtendedTemporaryDecl> from(const VariantEntity &e);
  static std::optional<LifetimeExtendedTemporaryDecl> from(const TokenContext &t);

  gap::generator<Stmt> children(void) const &;
  ValueDecl extending_declaration(void) const;
  uint32_t mangling_number(void) const;
  StorageDuration storage_duration(void) const;
  Expr temporary_expression(void) const;
};

static_assert(sizeof(LifetimeExtendedTemporaryDecl) == sizeof(Decl));

#endif
} // namespace mx
