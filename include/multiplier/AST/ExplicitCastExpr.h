// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CastExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CastExpr;
class Decl;
class ExplicitCastExpr;
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
class MX_EXPORT ExplicitCastExpr : public CastExpr {
 private:
  friend class FragmentImpl;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ExplicitCastExpr> in(const Index &index);
  static gap::generator<ExplicitCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExplicitCastExpr> by_id(const Index &, EntityId);
  static gap::generator<ExplicitCastExpr> in(const Fragment &frag);
  static gap::generator<ExplicitCastExpr> in(const File &file);

  static std::optional<ExplicitCastExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ExplicitCastExpr, ir::Operation>> in(const Compilation &tu);
  static gap::generator<ExplicitCastExpr> containing(const Decl &decl);
  static gap::generator<ExplicitCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ExplicitCastExpr> containing(const Stmt &stmt);
  static gap::generator<ExplicitCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExplicitCastExpr> from_base(const Stmt &parent);
  inline static std::optional<ExplicitCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ExplicitCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ExplicitCastExpr> from(const Reference &r);
  static std::optional<ExplicitCastExpr> from(const VariantEntity &e);
  static std::optional<ExplicitCastExpr> from(const TokenContext &t);

  Type type_as_written(void) const;
};

static_assert(sizeof(ExplicitCastExpr) == sizeof(CastExpr));

#endif
} // namespace mx
