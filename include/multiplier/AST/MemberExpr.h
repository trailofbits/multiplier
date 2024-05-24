// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>
#include <multiplier/AST/NonOdrUseReason.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class File;
class MemberExpr;
class Stmt;
class Token;
class ValueDecl;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MemberExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<MemberExpr> in(const Index &index);
  static gap::generator<MemberExpr> in(const Fragment &frag);
  static gap::generator<MemberExpr> in(const File &file);
  static gap::generator<MemberExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<MemberExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<MemberExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MEMBER_EXPR;
  }

  static gap::generator<MemberExpr> containing(const Decl &decl);
  static gap::generator<MemberExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<MemberExpr> containing(const Stmt &stmt);
  static gap::generator<MemberExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MemberExpr> by_id(const Index &, EntityId);

  static std::optional<MemberExpr> from_base(const Stmt &parent);
  inline static std::optional<MemberExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<MemberExpr> from(const std::optional<Stmt> &parent);
  static std::optional<MemberExpr> from(const Reference &r);
  static std::optional<MemberExpr> from(const VariantEntity &e);
  static std::optional<MemberExpr> from(const TokenContext &t);

  Expr base(void) const;
  Token l_angle_token(void) const;
  ValueDecl member_declaration(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool had_multiple_candidates(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_qualifier(void) const;
  bool has_template_keyword(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
  NonOdrUseReason is_non_odr_use(void) const;
};

static_assert(sizeof(MemberExpr) == sizeof(Expr));

#endif
} // namespace mx
