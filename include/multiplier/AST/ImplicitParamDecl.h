// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ImplicitParamDeclImplicitParamKind.h>
#include <multiplier/AST/VarDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class ImplicitParamDecl;
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
class MX_EXPORT ImplicitParamDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ImplicitParamDecl> in(const Index &index);
  static gap::generator<ImplicitParamDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ImplicitParamDecl> by_id(const Index &, EntityId);
  static gap::generator<ImplicitParamDecl> in(const Fragment &frag);
  static gap::generator<ImplicitParamDecl> in(const File &file);

  static std::optional<ImplicitParamDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ImplicitParamDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::IMPLICIT_PARAM;
  }

  static gap::generator<ImplicitParamDecl> containing(const Decl &decl);
  static gap::generator<ImplicitParamDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ImplicitParamDecl> containing(const Stmt &stmt);
  static gap::generator<ImplicitParamDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ImplicitParamDecl canonical_declaration(void) const;
  std::optional<ImplicitParamDecl> definition(void) const;
  gap::generator<ImplicitParamDecl> redeclarations(void) const &;
  static std::optional<ImplicitParamDecl> from_base(const Decl &parent);
  inline static std::optional<ImplicitParamDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ImplicitParamDecl> from(const std::optional<Decl> &parent);
  static std::optional<ImplicitParamDecl> from(const Reference &r);
  static std::optional<ImplicitParamDecl> from(const VariantEntity &e);
  static std::optional<ImplicitParamDecl> from(const TokenContext &t);

  ImplicitParamDeclImplicitParamKind parameter_kind(void) const;
};

static_assert(sizeof(ImplicitParamDecl) == sizeof(VarDecl));

#endif
} // namespace mx
