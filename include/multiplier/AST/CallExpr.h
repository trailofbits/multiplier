// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CallExprADLCallKind.h>
#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CallExpr;
class CastExpr;
class Decl;
class Expr;
class File;
class FunctionDecl;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CallExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CallExpr> in(const Index &index);
  static gap::generator<CallExpr> in(const Fragment &frag);
  static gap::generator<CallExpr> in(const File &file);
  static gap::generator<CallExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CallExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CallExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CALL_EXPR;
  }

  static gap::generator<CallExpr> containing(const Decl &decl);
  static gap::generator<CallExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CallExpr> containing(const Stmt &stmt);
  static gap::generator<CallExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CallExpr> by_id(const Index &, EntityId);

  static std::optional<CallExpr> from_base(const Stmt &parent);
  inline static std::optional<CallExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CallExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CallExpr> from(const Reference &r);
  static std::optional<CallExpr> from(const VariantEntity &e);
  static std::optional<CallExpr> from(const TokenContext &t);

  std::optional<Expr> nth_argument(unsigned n) const;
  unsigned num_arguments(void) const;
  gap::generator<Expr> arguments(void) const &;
  CallExprADLCallKind adl_call_kind(void) const;
  uint32_t builtin_callee(void) const;
  Type call_return_type(void) const;
  Expr callee(void) const;
  std::optional<Decl> callee_declaration(void) const;
  std::optional<FunctionDecl> direct_callee(void) const;
  Token r_paren_token(void) const;
  bool has_stored_fp_features(void) const;
  bool has_unused_result_attribute(void) const;
  bool is_builtin_assume_false(void) const;
  bool is_call_to_std_move(void) const;
  bool is_unevaluated_builtin_call(void) const;
  bool uses_adl(void) const;
  std::optional<Type> casted_return_type(void) const;
  std::optional<CastExpr> casted_return_value(void) const;
};

static_assert(sizeof(CallExpr) == sizeof(Expr));

#endif
} // namespace mx
