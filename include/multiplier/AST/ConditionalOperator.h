// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/AbstractConditionalOperator.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AbstractConditionalOperator;
class ConditionalOperator;
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
class MX_EXPORT ConditionalOperator : public AbstractConditionalOperator {
 private:
  friend class FragmentImpl;
  friend class AbstractConditionalOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ConditionalOperator> in(const Index &index);
  static gap::generator<ConditionalOperator> in(const Fragment &frag);
  static gap::generator<ConditionalOperator> in(const File &file);
  static gap::generator<ConditionalOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ConditionalOperator> from(const ir::Operation &op);
  static gap::generator<std::pair<ConditionalOperator, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONDITIONAL_OPERATOR;
  }

  static gap::generator<ConditionalOperator> containing(const Decl &decl);
  static gap::generator<ConditionalOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<ConditionalOperator> containing(const Stmt &stmt);
  static gap::generator<ConditionalOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConditionalOperator> by_id(const Index &, EntityId);

  static std::optional<ConditionalOperator> from_base(const Stmt &parent);
  inline static std::optional<ConditionalOperator> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ConditionalOperator> from(const std::optional<Stmt> &parent);
  static std::optional<ConditionalOperator> from(const Reference &r);
  static std::optional<ConditionalOperator> from(const VariantEntity &e);
  static std::optional<ConditionalOperator> from(const TokenContext &t);

  Expr lhs(void) const;
  Expr rhs(void) const;
};

static_assert(sizeof(ConditionalOperator) == sizeof(AbstractConditionalOperator));

#endif
} // namespace mx
