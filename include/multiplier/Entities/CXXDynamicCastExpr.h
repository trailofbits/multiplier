// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CXXNamedCastExpr.h"

namespace mx {
class EntityProvider;
class Index;
class CXXDynamicCastExpr;
class CXXNamedCastExpr;
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
class CXXDynamicCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXDynamicCastExpr> in(const Fragment &frag);
  static gap::generator<CXXDynamicCastExpr> in(const File &file);
  static gap::generator<CXXDynamicCastExpr> in(const Index &index);
  static gap::generator<CXXDynamicCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDynamicCastExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DYNAMIC_CAST_EXPR;
  }

  static gap::generator<CXXDynamicCastExpr> containing(const Decl &decl);
  static gap::generator<CXXDynamicCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDynamicCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXDynamicCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDynamicCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXDynamicCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXDynamicCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDynamicCastExpr> from(const Reference &r);
  static std::optional<CXXDynamicCastExpr> from(const TokenContext &t);

  bool is_always_null(void) const;
};

static_assert(sizeof(CXXDynamicCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
