// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class FunctionParmPackExpr;
class Stmt;
class Token;
class ValueStmt;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FunctionParmPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<FunctionParmPackExpr> in(const Fragment &frag);
  static gap::generator<FunctionParmPackExpr> in(const File &file);
  static gap::generator<FunctionParmPackExpr> in(const Index &index);
  static gap::generator<FunctionParmPackExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FunctionParmPackExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::FUNCTION_PARM_PACK_EXPR;
  }

  static gap::generator<FunctionParmPackExpr> containing(const Decl &decl);
  static gap::generator<FunctionParmPackExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<FunctionParmPackExpr> containing(const Stmt &stmt);
  static gap::generator<FunctionParmPackExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FunctionParmPackExpr> from(const Stmt &parent);

  inline static std::optional<FunctionParmPackExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return FunctionParmPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionParmPackExpr> from(const Reference &r);
  static std::optional<FunctionParmPackExpr> from(const TokenContext &t);

  VarDecl parameter_pack(void) const;
  Token parameter_pack_token(void) const;
  std::optional<VarDecl> nth_expansion(unsigned n) const;
  unsigned num_expansions(void) const;
  gap::generator<VarDecl> expansions(void) const &;
};

static_assert(sizeof(FunctionParmPackExpr) == sizeof(Expr));

#endif
} // namespace mx
