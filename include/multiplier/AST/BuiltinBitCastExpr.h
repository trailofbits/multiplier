// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ExplicitCastExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class BuiltinBitCastExpr;
class CastExpr;
class Decl;
class ExplicitCastExpr;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BuiltinBitCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<BuiltinBitCastExpr> in(const Index &index);
  static gap::generator<BuiltinBitCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BuiltinBitCastExpr> by_id(const Index &, EntityId);
  static gap::generator<BuiltinBitCastExpr> in(const Fragment &frag);
  static gap::generator<BuiltinBitCastExpr> in(const File &file);

  static std::optional<BuiltinBitCastExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<BuiltinBitCastExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BUILTIN_BIT_CAST_EXPR;
  }

  static gap::generator<BuiltinBitCastExpr> containing(const Decl &decl);
  static gap::generator<BuiltinBitCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<BuiltinBitCastExpr> containing(const Stmt &stmt);
  static gap::generator<BuiltinBitCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BuiltinBitCastExpr> from_base(const Stmt &parent);
  inline static std::optional<BuiltinBitCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<BuiltinBitCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<BuiltinBitCastExpr> from(const Reference &r);
  static std::optional<BuiltinBitCastExpr> from(const VariantEntity &e);
  static std::optional<BuiltinBitCastExpr> from(const TokenContext &t);

};

static_assert(sizeof(BuiltinBitCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
