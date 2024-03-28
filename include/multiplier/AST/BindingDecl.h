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
class BindingDecl;
class Decl;
class Expr;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BindingDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<BindingDecl> in(const Index &index);
  static gap::generator<BindingDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BindingDecl> by_id(const Index &, EntityId);
  static gap::generator<BindingDecl> in(const Fragment &frag);
  static gap::generator<BindingDecl> in(const File &file);

  static std::optional<BindingDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<BindingDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BINDING;
  }

  static gap::generator<BindingDecl> containing(const Decl &decl);
  static gap::generator<BindingDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<BindingDecl> containing(const Stmt &stmt);
  static gap::generator<BindingDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  BindingDecl canonical_declaration(void) const;
  std::optional<BindingDecl> definition(void) const;
  gap::generator<BindingDecl> redeclarations(void) const &;
  static std::optional<BindingDecl> from_base(const Decl &parent);
  inline static std::optional<BindingDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<BindingDecl> from(const std::optional<Decl> &parent);
  static std::optional<BindingDecl> from(const Reference &r);
  static std::optional<BindingDecl> from(const VariantEntity &e);
  static std::optional<BindingDecl> from(const TokenContext &t);

  std::optional<Expr> binding(void) const;
  ValueDecl decomposed_declaration(void) const;
  std::optional<VarDecl> holding_variable(void) const;
};

static_assert(sizeof(BindingDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
