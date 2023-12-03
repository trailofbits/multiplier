// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeclaratorDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class MSPropertyDecl;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MSPropertyDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<MSPropertyDecl> in(const Index &index);
  static gap::generator<MSPropertyDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSPropertyDecl> by_id(const Index &, EntityId);
  static gap::generator<MSPropertyDecl> in(const Fragment &frag);
  static gap::generator<MSPropertyDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::MS_PROPERTY;
  }

  static gap::generator<MSPropertyDecl> containing(const Decl &decl);
  static gap::generator<MSPropertyDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<MSPropertyDecl> containing(const Stmt &stmt);
  static gap::generator<MSPropertyDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  MSPropertyDecl canonical_declaration(void) const;
  std::optional<MSPropertyDecl> definition(void) const;
  gap::generator<MSPropertyDecl> redeclarations(void) const &;
  static std::optional<MSPropertyDecl> from_base(const Decl &parent);
  inline static std::optional<MSPropertyDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<MSPropertyDecl> from(const std::optional<Decl> &parent);
  static std::optional<MSPropertyDecl> from(const Reference &r);
  static std::optional<MSPropertyDecl> from(const VariantEntity &e);
  static std::optional<MSPropertyDecl> from(const TokenContext &t);

  bool has_getter(void) const;
  bool has_setter(void) const;
};

static_assert(sizeof(MSPropertyDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
