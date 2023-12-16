// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class CXXBoolLiteralExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXBoolLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXBoolLiteralExpr> in(const Index &index);
  static gap::generator<CXXBoolLiteralExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXBoolLiteralExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXBoolLiteralExpr> in(const Fragment &frag);
  static gap::generator<CXXBoolLiteralExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<CXXBoolLiteralExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXBoolLiteralExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_BOOL_LITERAL_EXPR;
  }

  static gap::generator<CXXBoolLiteralExpr> containing(const Decl &decl);
  static gap::generator<CXXBoolLiteralExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXBoolLiteralExpr> containing(const Stmt &stmt);
  static gap::generator<CXXBoolLiteralExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXBoolLiteralExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXBoolLiteralExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXBoolLiteralExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXBoolLiteralExpr> from(const Reference &r);
  static std::optional<CXXBoolLiteralExpr> from(const VariantEntity &e);
  static std::optional<CXXBoolLiteralExpr> from(const TokenContext &t);

  Token token(void) const;
  bool value(void) const;
};

static_assert(sizeof(CXXBoolLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
