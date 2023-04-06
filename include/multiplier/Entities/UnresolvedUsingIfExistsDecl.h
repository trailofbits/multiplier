// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "NamedDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class Token;
class UnresolvedUsingIfExistsDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedUsingIfExistsDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UnresolvedUsingIfExistsDecl> in(const Fragment &frag);
  static gap::generator<UnresolvedUsingIfExistsDecl> in(const File &file);
  static gap::generator<UnresolvedUsingIfExistsDecl> in(const Index &index);
  static gap::generator<UnresolvedUsingIfExistsDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnresolvedUsingIfExistsDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_IF_EXISTS;
  }

  static gap::generator<UnresolvedUsingIfExistsDecl> containing(const Decl &decl);
  static gap::generator<UnresolvedUsingIfExistsDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedUsingIfExistsDecl> containing(const Stmt &stmt);
  static gap::generator<UnresolvedUsingIfExistsDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  UnresolvedUsingIfExistsDecl canonical_declaration(void) const;
  std::optional<UnresolvedUsingIfExistsDecl> definition(void) const;
  gap::generator<UnresolvedUsingIfExistsDecl> redeclarations(void) const &;
  static std::optional<UnresolvedUsingIfExistsDecl> from(const Decl &parent);

  inline static std::optional<UnresolvedUsingIfExistsDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnresolvedUsingIfExistsDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingIfExistsDecl> from(const Reference &r);
  static std::optional<UnresolvedUsingIfExistsDecl> from(const TokenContext &t);

};

static_assert(sizeof(UnresolvedUsingIfExistsDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
