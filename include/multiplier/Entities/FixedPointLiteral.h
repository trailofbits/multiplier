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
class FixedPointLiteral;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FixedPointLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<FixedPointLiteral> in(const Index &index);
  static gap::generator<FixedPointLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FixedPointLiteral> by_id(const Index &, EntityId);
  static gap::generator<FixedPointLiteral> in(const Fragment &frag);
  static gap::generator<FixedPointLiteral> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::FIXED_POINT_LITERAL;
  }

  static gap::generator<FixedPointLiteral> containing(const Decl &decl);
  static gap::generator<FixedPointLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<FixedPointLiteral> containing(const Stmt &stmt);
  static gap::generator<FixedPointLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FixedPointLiteral> from(const Stmt &parent);

  inline static std::optional<FixedPointLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return FixedPointLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FixedPointLiteral> from(const Reference &r);
  static std::optional<FixedPointLiteral> from(const TokenContext &t);

  Token token(void) const;
};

static_assert(sizeof(FixedPointLiteral) == sizeof(Expr));

#endif
} // namespace mx
