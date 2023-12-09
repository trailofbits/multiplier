// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/BinaryOperator.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class BinaryOperator;
class CompoundAssignOperator;
class Decl;
class Expr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CompoundAssignOperator : public BinaryOperator {
 private:
  friend class FragmentImpl;
  friend class BinaryOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CompoundAssignOperator> in(const Index &index);
  static gap::generator<CompoundAssignOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CompoundAssignOperator> by_id(const Index &, EntityId);
  static gap::generator<CompoundAssignOperator> in(const Fragment &frag);
  static gap::generator<CompoundAssignOperator> in(const File &file);

  static std::optional<CompoundAssignOperator> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<CompoundAssignOperator, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COMPOUND_ASSIGN_OPERATOR;
  }

  static gap::generator<CompoundAssignOperator> containing(const Decl &decl);
  static gap::generator<CompoundAssignOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<CompoundAssignOperator> containing(const Stmt &stmt);
  static gap::generator<CompoundAssignOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CompoundAssignOperator> from_base(const Stmt &parent);
  inline static std::optional<CompoundAssignOperator> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CompoundAssignOperator> from(const std::optional<Stmt> &parent);
  static std::optional<CompoundAssignOperator> from(const Reference &r);
  static std::optional<CompoundAssignOperator> from(const VariantEntity &e);
  static std::optional<CompoundAssignOperator> from(const TokenContext &t);

  Type computation_lhs_type(void) const;
  Type computation_result_type(void) const;
};

static_assert(sizeof(CompoundAssignOperator) == sizeof(BinaryOperator));

#endif
} // namespace mx
