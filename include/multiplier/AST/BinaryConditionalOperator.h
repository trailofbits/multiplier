// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class BinaryConditionalOperator;
class Decl;
class Expr;
class OpaqueValueExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BinaryConditionalOperator : public AbstractConditionalOperator {
 private:
  friend class FragmentImpl;
  friend class AbstractConditionalOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<BinaryConditionalOperator> in(const Index &index);
  static gap::generator<BinaryConditionalOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BinaryConditionalOperator> by_id(const Index &, EntityId);
  static gap::generator<BinaryConditionalOperator> in(const Fragment &frag);
  static gap::generator<BinaryConditionalOperator> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BINARY_CONDITIONAL_OPERATOR;
  }

  static gap::generator<BinaryConditionalOperator> containing(const Decl &decl);
  static gap::generator<BinaryConditionalOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<BinaryConditionalOperator> containing(const Stmt &stmt);
  static gap::generator<BinaryConditionalOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BinaryConditionalOperator> from_base(const Stmt &parent);
  inline static std::optional<BinaryConditionalOperator> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<BinaryConditionalOperator> from(const std::optional<Stmt> &parent);
  static std::optional<BinaryConditionalOperator> from(const Reference &r);
  static std::optional<BinaryConditionalOperator> from(const VariantEntity &e);
  static std::optional<BinaryConditionalOperator> from(const TokenContext &t);

  Expr common(void) const;
  OpaqueValueExpr opaque_value(void) const;
};

static_assert(sizeof(BinaryConditionalOperator) == sizeof(AbstractConditionalOperator));

#endif
} // namespace mx
