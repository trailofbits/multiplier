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
class NamespaceDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NamespaceDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<NamespaceDecl> in(const Index &index);
  static gap::generator<NamespaceDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NamespaceDecl> by_id(const Index &, EntityId);
  static gap::generator<NamespaceDecl> in(const Fragment &frag);
  static gap::generator<NamespaceDecl> in(const File &file);

  static std::optional<NamespaceDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<NamespaceDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NAMESPACE;
  }

  static gap::generator<NamespaceDecl> containing(const Decl &decl);
  static gap::generator<NamespaceDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<NamespaceDecl> containing(const Stmt &stmt);
  static gap::generator<NamespaceDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  NamespaceDecl canonical_declaration(void) const;
  std::optional<NamespaceDecl> definition(void) const;
  gap::generator<NamespaceDecl> redeclarations(void) const &;
  static std::optional<NamespaceDecl> from_base(const Decl &parent);
  inline static std::optional<NamespaceDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<NamespaceDecl> from(const std::optional<Decl> &parent);
  static std::optional<NamespaceDecl> from(const Reference &r);
  static std::optional<NamespaceDecl> from(const VariantEntity &e);
  static std::optional<NamespaceDecl> from(const TokenContext &t);

  std::optional<NamespaceDecl> anonymous_namespace(void) const;
  NamespaceDecl original_namespace(void) const;
  Token r_brace_token(void) const;
  bool is_anonymous_namespace(void) const;
  bool is_inline(void) const;
  bool is_nested(void) const;
  bool is_original_namespace(void) const;
};

static_assert(sizeof(NamespaceDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
