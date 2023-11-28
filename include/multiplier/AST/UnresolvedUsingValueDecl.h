// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ValueDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class Token;
class UnresolvedUsingValueDecl;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedUsingValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UnresolvedUsingValueDecl> in(const Index &index);
  static gap::generator<UnresolvedUsingValueDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedUsingValueDecl> by_id(const Index &, EntityId);
  static gap::generator<UnresolvedUsingValueDecl> in(const Fragment &frag);
  static gap::generator<UnresolvedUsingValueDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_VALUE;
  }

  static gap::generator<UnresolvedUsingValueDecl> containing(const Decl &decl);
  static gap::generator<UnresolvedUsingValueDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedUsingValueDecl> containing(const Stmt &stmt);
  static gap::generator<UnresolvedUsingValueDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  UnresolvedUsingValueDecl canonical_declaration(void) const;
  std::optional<UnresolvedUsingValueDecl> definition(void) const;
  gap::generator<UnresolvedUsingValueDecl> redeclarations(void) const &;
  static std::optional<UnresolvedUsingValueDecl> from_base(const Decl &parent);
  inline static std::optional<UnresolvedUsingValueDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<UnresolvedUsingValueDecl> from(const std::optional<Decl> &parent);
  static std::optional<UnresolvedUsingValueDecl> from(const Reference &r);
  static std::optional<UnresolvedUsingValueDecl> from(const VariantEntity &e);
  static std::optional<UnresolvedUsingValueDecl> from(const TokenContext &t);

  Token ellipsis_token(void) const;
  Token using_token(void) const;
  bool is_access_declaration(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(UnresolvedUsingValueDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
