// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TypedefNameDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class Token;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypedefNameDecl;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeAliasDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypeAliasDecl> in(const Fragment &frag);
  static gap::generator<TypeAliasDecl> in(const File &file);
  static gap::generator<TypeAliasDecl> in(const Index &index);
  static gap::generator<TypeAliasDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeAliasDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPE_ALIAS;
  }

  static gap::generator<TypeAliasDecl> containing(const Decl &decl);
  static gap::generator<TypeAliasDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypeAliasDecl> containing(const Stmt &stmt);
  static gap::generator<TypeAliasDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TypeAliasDecl canonical_declaration(void) const;
  std::optional<TypeAliasDecl> definition(void) const;
  gap::generator<TypeAliasDecl> redeclarations(void) const &;
  static std::optional<TypeAliasDecl> from(const Decl &parent);

  inline static std::optional<TypeAliasDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypeAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasDecl> from(const Reference &r);
  static std::optional<TypeAliasDecl> from(const TokenContext &t);

  std::optional<TypeAliasTemplateDecl> described_alias_template(void) const;
};

static_assert(sizeof(TypeAliasDecl) == sizeof(TypedefNameDecl));

#endif
} // namespace mx
