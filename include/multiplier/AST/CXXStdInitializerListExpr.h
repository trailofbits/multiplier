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
class CXXStdInitializerListExpr;
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
class MX_EXPORT CXXStdInitializerListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXStdInitializerListExpr> in(const Index &index);
  static gap::generator<CXXStdInitializerListExpr> in(const Fragment &frag);
  static gap::generator<CXXStdInitializerListExpr> in(const File &file);
  static gap::generator<CXXStdInitializerListExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXStdInitializerListExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXStdInitializerListExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_STD_INITIALIZER_LIST_EXPR;
  }

  static gap::generator<CXXStdInitializerListExpr> containing(const Decl &decl);
  static gap::generator<CXXStdInitializerListExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXStdInitializerListExpr> containing(const Stmt &stmt);
  static gap::generator<CXXStdInitializerListExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXStdInitializerListExpr> by_id(const Index &, EntityId);

  static std::optional<CXXStdInitializerListExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXStdInitializerListExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXStdInitializerListExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXStdInitializerListExpr> from(const Reference &r);
  static std::optional<CXXStdInitializerListExpr> from(const VariantEntity &e);
  static std::optional<CXXStdInitializerListExpr> from(const TokenContext &t);

  Expr sub_expression(void) const;
};

static_assert(sizeof(CXXStdInitializerListExpr) == sizeof(Expr));

#endif
} // namespace mx
