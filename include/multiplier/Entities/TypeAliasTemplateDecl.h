// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "RedeclarableTemplateDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class Stmt;
class TemplateDecl;
class Token;
class TypeAliasTemplateDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeAliasTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypeAliasTemplateDecl> in(const Index &index);
  static gap::generator<TypeAliasTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeAliasTemplateDecl> by_id(const Index &, EntityId);
  static gap::generator<TypeAliasTemplateDecl> in(const Fragment &frag);
  static gap::generator<TypeAliasTemplateDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPE_ALIAS_TEMPLATE;
  }

  static gap::generator<TypeAliasTemplateDecl> containing(const Decl &decl);
  static gap::generator<TypeAliasTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypeAliasTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<TypeAliasTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TypeAliasTemplateDecl canonical_declaration(void) const;
  std::optional<TypeAliasTemplateDecl> definition(void) const;
  gap::generator<TypeAliasTemplateDecl> redeclarations(void) const &;
  static std::optional<TypeAliasTemplateDecl> from(const Decl &parent);

  inline static std::optional<TypeAliasTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypeAliasTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasTemplateDecl> from(const Reference &r);
  static std::optional<TypeAliasTemplateDecl> from(const TokenContext &t);

};

static_assert(sizeof(TypeAliasTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
