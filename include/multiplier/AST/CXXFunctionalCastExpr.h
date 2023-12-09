// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ExplicitCastExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXFunctionalCastExpr;
class CastExpr;
class Decl;
class ExplicitCastExpr;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXFunctionalCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXFunctionalCastExpr> in(const Index &index);
  static gap::generator<CXXFunctionalCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXFunctionalCastExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXFunctionalCastExpr> in(const Fragment &frag);
  static gap::generator<CXXFunctionalCastExpr> in(const File &file);

  static std::optional<CXXFunctionalCastExpr> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<CXXFunctionalCastExpr, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_FUNCTIONAL_CAST_EXPR;
  }

  static gap::generator<CXXFunctionalCastExpr> containing(const Decl &decl);
  static gap::generator<CXXFunctionalCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXFunctionalCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXFunctionalCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXFunctionalCastExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXFunctionalCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXFunctionalCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXFunctionalCastExpr> from(const Reference &r);
  static std::optional<CXXFunctionalCastExpr> from(const VariantEntity &e);
  static std::optional<CXXFunctionalCastExpr> from(const TokenContext &t);

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  bool is_list_initialization(void) const;
};

static_assert(sizeof(CXXFunctionalCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
