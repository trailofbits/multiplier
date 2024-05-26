// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/BinaryOperatorKind.h>
#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class BinaryOperator;
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
class MX_EXPORT BinaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<BinaryOperator> in(const Index &index);
  static gap::generator<BinaryOperator> in(const Fragment &frag);
  static gap::generator<BinaryOperator> in(const File &file);
  static gap::generator<BinaryOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<BinaryOperator> from(const ir::Operation &op);
  static gap::generator<std::pair<BinaryOperator, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BINARY_OPERATOR;
  }

  static gap::generator<BinaryOperator> containing(const Decl &decl);
  static gap::generator<BinaryOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<BinaryOperator> containing(const Stmt &stmt);
  static gap::generator<BinaryOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BinaryOperator> by_id(const Index &, EntityId);

  static std::optional<BinaryOperator> from_base(const Stmt &parent);
  inline static std::optional<BinaryOperator> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<BinaryOperator> from(const std::optional<Stmt> &parent);
  static std::optional<BinaryOperator> from(const Reference &r);
  static std::optional<BinaryOperator> from(const VariantEntity &e);
  static std::optional<BinaryOperator> from(const TokenContext &t);

  Expr lhs(void) const;
  BinaryOperatorKind opcode(void) const;
  std::string_view opcode_string(void) const;
  Token operator_token(void) const;
  Expr rhs(void) const;
  bool has_stored_fp_features(void) const;
  bool is_additive_operation(void) const;
  bool is_assignment_operation(void) const;
  bool is_bitwise_operation(void) const;
  bool is_comma_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_compound_assignment_operation(void) const;
  bool is_equality_operation(void) const;
  bool is_logical_operation(void) const;
  bool is_multiplicative_operation(void) const;
  bool is_pointer_memory_operation(void) const;
  bool is_relational_operation(void) const;
  bool is_shift_assign_operation(void) const;
  bool is_shift_operation(void) const;
};

static_assert(sizeof(BinaryOperator) == sizeof(Expr));

#endif
} // namespace mx
