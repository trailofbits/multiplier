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
class Type;
class UsingEnumDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingEnumDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UsingEnumDecl> in(const Index &index);
  static gap::generator<UsingEnumDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UsingEnumDecl> by_id(const Index &, EntityId);
  static gap::generator<UsingEnumDecl> in(const Fragment &frag);
  static gap::generator<UsingEnumDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_ENUM;
  }

  static gap::generator<UsingEnumDecl> containing(const Decl &decl);
  static gap::generator<UsingEnumDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UsingEnumDecl> containing(const Stmt &stmt);
  static gap::generator<UsingEnumDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  UsingEnumDecl canonical_declaration(void) const;
  std::optional<UsingEnumDecl> definition(void) const;
  gap::generator<UsingEnumDecl> redeclarations(void) const &;
  static std::optional<UsingEnumDecl> from_base(const Decl &parent);
  inline static std::optional<UsingEnumDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<UsingEnumDecl> from(const std::optional<Decl> &parent);
  static std::optional<UsingEnumDecl> from(const Reference &r);
  static std::optional<UsingEnumDecl> from(const VariantEntity &e);
  static std::optional<UsingEnumDecl> from(const TokenContext &t);

  EnumDecl enum_declaration(void) const;
  Token enum_token(void) const;
  Type enum_type(void) const;
  Token using_token(void) const;
};

static_assert(sizeof(UsingEnumDecl) == sizeof(BaseUsingDecl));

#endif
} // namespace mx
