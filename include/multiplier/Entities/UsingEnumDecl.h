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
class EnumDecl;
class NamedDecl;
class Stmt;
class Token;
class UsingEnumDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingEnumDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UsingEnumDecl> in(const Fragment &frag);
  static gap::generator<UsingEnumDecl> in(const File &file);
  static gap::generator<UsingEnumDecl> in(const Index &index);
  static gap::generator<UsingEnumDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UsingEnumDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_ENUM;
  }

  static gap::generator<UsingEnumDecl> containing(const Decl &decl);
  static gap::generator<UsingEnumDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UsingEnumDecl> containing(const Stmt &stmt);
  static gap::generator<UsingEnumDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<UsingEnumDecl> redeclarations(void) const &;
  static std::optional<UsingEnumDecl> from(const Decl &parent);

  inline static std::optional<UsingEnumDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingEnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingEnumDecl> from(const Reference &r);
  static std::optional<UsingEnumDecl> from(const TokenContext &t);

  EnumDecl enum_declaration(void) const;
  Token enum_token(void) const;
  Token using_token(void) const;
};

static_assert(sizeof(UsingEnumDecl) == sizeof(BaseUsingDecl));

#endif
} // namespace mx
