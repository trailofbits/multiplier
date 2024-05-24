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
class CXXRewrittenBinaryOperator;
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
class MX_EXPORT CXXRewrittenBinaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXRewrittenBinaryOperator> in(const Index &index);
  static gap::generator<CXXRewrittenBinaryOperator> in(const Fragment &frag);
  static gap::generator<CXXRewrittenBinaryOperator> in(const File &file);
  static gap::generator<CXXRewrittenBinaryOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXRewrittenBinaryOperator> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXRewrittenBinaryOperator, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_REWRITTEN_BINARY_OPERATOR;
  }

  static gap::generator<CXXRewrittenBinaryOperator> containing(const Decl &decl);
  static gap::generator<CXXRewrittenBinaryOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXRewrittenBinaryOperator> containing(const Stmt &stmt);
  static gap::generator<CXXRewrittenBinaryOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXRewrittenBinaryOperator> by_id(const Index &, EntityId);

  static std::optional<CXXRewrittenBinaryOperator> from_base(const Stmt &parent);
  inline static std::optional<CXXRewrittenBinaryOperator> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXRewrittenBinaryOperator> from(const std::optional<Stmt> &parent);
  static std::optional<CXXRewrittenBinaryOperator> from(const Reference &r);
  static std::optional<CXXRewrittenBinaryOperator> from(const VariantEntity &e);
  static std::optional<CXXRewrittenBinaryOperator> from(const TokenContext &t);

  Expr lhs(void) const;
  BinaryOperatorKind opcode(void) const;
  std::string_view opcode_string(void) const;
  BinaryOperatorKind operator_(void) const;
  Token operator_token(void) const;
  Expr rhs(void) const;
  Expr semantic_form(void) const;
  bool is_assignment_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_reversed(void) const;
};

static_assert(sizeof(CXXRewrittenBinaryOperator) == sizeof(Expr));

#endif
} // namespace mx
