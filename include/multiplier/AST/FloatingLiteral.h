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
class FloatingLiteral;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FloatingLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<FloatingLiteral> in(const Index &index);
  static gap::generator<FloatingLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FloatingLiteral> by_id(const Index &, EntityId);
  static gap::generator<FloatingLiteral> in(const Fragment &frag);
  static gap::generator<FloatingLiteral> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::FLOATING_LITERAL;
  }

  static gap::generator<FloatingLiteral> containing(const Decl &decl);
  static gap::generator<FloatingLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<FloatingLiteral> containing(const Stmt &stmt);
  static gap::generator<FloatingLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FloatingLiteral> from_base(const Stmt &parent);
  inline static std::optional<FloatingLiteral> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<FloatingLiteral> from(const std::optional<Stmt> &parent);
  static std::optional<FloatingLiteral> from(const Reference &r);
  static std::optional<FloatingLiteral> from(const VariantEntity &e);
  static std::optional<FloatingLiteral> from(const TokenContext &t);

  Token token(void) const;
  bool is_exact(void) const;
};

static_assert(sizeof(FloatingLiteral) == sizeof(Expr));

#endif
} // namespace mx
