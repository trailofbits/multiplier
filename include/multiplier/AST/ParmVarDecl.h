// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeclObjCDeclQualifier.h>
#include <multiplier/AST/VarDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class Expr;
class NamedDecl;
class ParmVarDecl;
class Stmt;
class Token;
class TokenRange;
class Type;
class ValueDecl;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ParmVarDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ParmVarDecl> in(const Index &index);
  static gap::generator<ParmVarDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ParmVarDecl> by_id(const Index &, EntityId);
  static gap::generator<ParmVarDecl> in(const Fragment &frag);
  static gap::generator<ParmVarDecl> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<ParmVarDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ParmVarDecl, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PARM_VAR;
  }

  static gap::generator<ParmVarDecl> containing(const Decl &decl);
  static gap::generator<ParmVarDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ParmVarDecl> containing(const Stmt &stmt);
  static gap::generator<ParmVarDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ParmVarDecl canonical_declaration(void) const;
  std::optional<ParmVarDecl> definition(void) const;
  gap::generator<ParmVarDecl> redeclarations(void) const &;
  static std::optional<ParmVarDecl> from_base(const Decl &parent);
  inline static std::optional<ParmVarDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ParmVarDecl> from(const std::optional<Decl> &parent);
  static std::optional<ParmVarDecl> from(const Reference &r);
  static std::optional<ParmVarDecl> from(const VariantEntity &e);
  static std::optional<ParmVarDecl> from(const TokenContext &t);

  std::optional<Expr> default_argument(void) const;
  TokenRange default_argument_range(void) const;
  DeclObjCDeclQualifier obj_c_decl_qualifier(void) const;
  Type original_type(void) const;
  std::optional<Expr> uninstantiated_default_argument(void) const;
  bool has_default_argument(void) const;
  bool has_inherited_default_argument(void) const;
  bool has_uninstantiated_default_argument(void) const;
  bool has_unparsed_default_argument(void) const;
  bool is_destroyed_in_callee(void) const;
  bool is_knr_promoted(void) const;
  bool is_obj_c_method_parameter(void) const;
};

static_assert(sizeof(ParmVarDecl) == sizeof(VarDecl));

#endif
} // namespace mx
