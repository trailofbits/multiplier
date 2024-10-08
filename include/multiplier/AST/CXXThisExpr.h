// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXThisExpr;
class Decl;
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
class MX_EXPORT CXXThisExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXThisExpr> in(const Index &index);
  static gap::generator<CXXThisExpr> in(const Fragment &frag);
  static gap::generator<CXXThisExpr> in(const File &file);
  static gap::generator<CXXThisExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXThisExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXThisExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_THIS_EXPR;
  }

  static gap::generator<CXXThisExpr> containing(const Decl &decl);
  static gap::generator<CXXThisExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXThisExpr> containing(const Stmt &stmt);
  static gap::generator<CXXThisExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXThisExpr> by_id(const Index &, EntityId);

  static std::optional<CXXThisExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXThisExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXThisExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXThisExpr> from(const Reference &r);
  static std::optional<CXXThisExpr> from(const VariantEntity &e);
  static std::optional<CXXThisExpr> from(const TokenContext &t);

  Token token(void) const;
  bool is_implicit(void) const;
};

static_assert(sizeof(CXXThisExpr) == sizeof(Expr));

#endif
} // namespace mx
