// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/NamedDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NamespaceAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<NamespaceAliasDecl> in(const Index &index);
  static gap::generator<NamespaceAliasDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NamespaceAliasDecl> by_id(const Index &, EntityId);
  static gap::generator<NamespaceAliasDecl> in(const Fragment &frag);
  static gap::generator<NamespaceAliasDecl> in(const File &file);

  static std::optional<NamespaceAliasDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<NamespaceAliasDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NAMESPACE_ALIAS;
  }

  static gap::generator<NamespaceAliasDecl> containing(const Decl &decl);
  static gap::generator<NamespaceAliasDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<NamespaceAliasDecl> containing(const Stmt &stmt);
  static gap::generator<NamespaceAliasDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  NamespaceAliasDecl canonical_declaration(void) const;
  std::optional<NamespaceAliasDecl> definition(void) const;
  gap::generator<NamespaceAliasDecl> redeclarations(void) const &;
  static std::optional<NamespaceAliasDecl> from_base(const Decl &parent);
  inline static std::optional<NamespaceAliasDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<NamespaceAliasDecl> from(const std::optional<Decl> &parent);
  static std::optional<NamespaceAliasDecl> from(const Reference &r);
  static std::optional<NamespaceAliasDecl> from(const VariantEntity &e);
  static std::optional<NamespaceAliasDecl> from(const TokenContext &t);

  Token alias_token(void) const;
  NamedDecl aliased_namespace(void) const;
  NamespaceDecl namespace_(void) const;
  Token namespace_token(void) const;
  Token target_name_token(void) const;
};

static_assert(sizeof(NamespaceAliasDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
