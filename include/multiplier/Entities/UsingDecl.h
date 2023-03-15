// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "BaseUsingDecl.h"

namespace mx {
class EntityProvider;
class Index;
class BaseUsingDecl;
class Decl;
class NamedDecl;
class Stmt;
class Token;
class UsingDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UsingDecl> in(const Fragment &frag);
  static gap::generator<UsingDecl> in(const File &file);
  static gap::generator<UsingDecl> in(const Index &index);
  static gap::generator<UsingDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UsingDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING;
  }

  static gap::generator<UsingDecl> containing(const Decl &decl);
  static gap::generator<UsingDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UsingDecl> containing(const Stmt &stmt);
  static gap::generator<UsingDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<UsingDecl> redeclarations(void) const &;
  static std::optional<UsingDecl> from(const Decl &parent);

  inline static std::optional<UsingDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingDecl> from(const Reference &r);
  static std::optional<UsingDecl> from(const TokenContext &t);

  Token using_token(void) const;
  bool has_typename(void) const;
  bool is_access_declaration(void) const;
};

static_assert(sizeof(UsingDecl) == sizeof(BaseUsingDecl));

#endif
} // namespace mx
