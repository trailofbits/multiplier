// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OverloadExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class File;
class OverloadExpr;
class Stmt;
class Token;
class Type;
class UnresolvedMemberExpr;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UnresolvedMemberExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<UnresolvedMemberExpr> in(const Index &index);
  static gap::generator<UnresolvedMemberExpr> in(const Fragment &frag);
  static gap::generator<UnresolvedMemberExpr> in(const File &file);
  static gap::generator<UnresolvedMemberExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<UnresolvedMemberExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<UnresolvedMemberExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNRESOLVED_MEMBER_EXPR;
  }

  static gap::generator<UnresolvedMemberExpr> containing(const Decl &decl);
  static gap::generator<UnresolvedMemberExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<UnresolvedMemberExpr> containing(const Stmt &stmt);
  static gap::generator<UnresolvedMemberExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedMemberExpr> by_id(const Index &, EntityId);

  static std::optional<UnresolvedMemberExpr> from_base(const Stmt &parent);
  inline static std::optional<UnresolvedMemberExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<UnresolvedMemberExpr> from(const std::optional<Stmt> &parent);
  static std::optional<UnresolvedMemberExpr> from(const Reference &r);
  static std::optional<UnresolvedMemberExpr> from(const VariantEntity &e);
  static std::optional<UnresolvedMemberExpr> from(const TokenContext &t);

  Type base_type(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  bool has_unresolved_using(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

static_assert(sizeof(UnresolvedMemberExpr) == sizeof(OverloadExpr));

#endif
} // namespace mx
