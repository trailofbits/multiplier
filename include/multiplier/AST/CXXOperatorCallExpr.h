// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CallExpr.h>
#include <multiplier/AST/OverloadedOperatorKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXOperatorCallExpr;
class CallExpr;
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
class MX_EXPORT CXXOperatorCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXOperatorCallExpr> in(const Index &index);
  static gap::generator<CXXOperatorCallExpr> in(const Fragment &frag);
  static gap::generator<CXXOperatorCallExpr> in(const File &file);
  static gap::generator<CXXOperatorCallExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXOperatorCallExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXOperatorCallExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_OPERATOR_CALL_EXPR;
  }

  static gap::generator<CXXOperatorCallExpr> containing(const Decl &decl);
  static gap::generator<CXXOperatorCallExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXOperatorCallExpr> containing(const Stmt &stmt);
  static gap::generator<CXXOperatorCallExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXOperatorCallExpr> by_id(const Index &, EntityId);

  static std::optional<CXXOperatorCallExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXOperatorCallExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXOperatorCallExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXOperatorCallExpr> from(const Reference &r);
  static std::optional<CXXOperatorCallExpr> from(const VariantEntity &e);
  static std::optional<CXXOperatorCallExpr> from(const TokenContext &t);

  OverloadedOperatorKind operator_(void) const;
  Token operator_token(void) const;
  bool is_assignment_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_infix_binary_operation(void) const;
};

static_assert(sizeof(CXXOperatorCallExpr) == sizeof(CallExpr));

#endif
} // namespace mx
