// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class CStyleCastExpr;
class CastExpr;
class Decl;
class ExplicitCastExpr;
class Expr;
class File;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CStyleCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CStyleCastExpr> in(const Index &index);
  static gap::generator<CStyleCastExpr> in(const Fragment &frag);
  static gap::generator<CStyleCastExpr> in(const File &file);
  static gap::generator<CStyleCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CStyleCastExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CStyleCastExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::C_STYLE_CAST_EXPR;
  }

  static gap::generator<CStyleCastExpr> containing(const Decl &decl);
  static gap::generator<CStyleCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CStyleCastExpr> containing(const Stmt &stmt);
  static gap::generator<CStyleCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CStyleCastExpr> by_id(const Index &, EntityId);

  static std::optional<CStyleCastExpr> from_base(const Stmt &parent);
  inline static std::optional<CStyleCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CStyleCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CStyleCastExpr> from(const Reference &r);
  static std::optional<CStyleCastExpr> from(const VariantEntity &e);
  static std::optional<CStyleCastExpr> from(const TokenContext &t);

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(CStyleCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
