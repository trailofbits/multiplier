// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>
#include <multiplier/AST/UnaryOperatorKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class Stmt;
class Token;
class UnaryOperator;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<UnaryOperator> in(const Index &index);
  static gap::generator<UnaryOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnaryOperator> by_id(const Index &, EntityId);
  static gap::generator<UnaryOperator> in(const Fragment &frag);
  static gap::generator<UnaryOperator> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::UNARY_OPERATOR;
  }

  static gap::generator<UnaryOperator> containing(const Decl &decl);
  static gap::generator<UnaryOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<UnaryOperator> containing(const Stmt &stmt);
  static gap::generator<UnaryOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnaryOperator> from_base(const Stmt &parent);
  inline static std::optional<UnaryOperator> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<UnaryOperator> from(const std::optional<Stmt> &parent);
  static std::optional<UnaryOperator> from(const Reference &r);
  static std::optional<UnaryOperator> from(const VariantEntity &e);
  static std::optional<UnaryOperator> from(const TokenContext &t);

  bool can_overflow(void) const;
  UnaryOperatorKind opcode(void) const;
  Token operator_token(void) const;
  Expr sub_expression(void) const;
  bool has_stored_fp_features(void) const;
  bool is_arithmetic_operation(void) const;
  bool is_decrement_operation(void) const;
  bool is_increment_decrement_operation(void) const;
  bool is_increment_operation(void) const;
  bool is_postfix(void) const;
  bool is_prefix(void) const;
};

static_assert(sizeof(UnaryOperator) == sizeof(Expr));

#endif
} // namespace mx
