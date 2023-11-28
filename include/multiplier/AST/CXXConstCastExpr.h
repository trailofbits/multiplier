// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CXXNamedCastExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXConstCastExpr;
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
class CXXConstCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXConstCastExpr> in(const Index &index);
  static gap::generator<CXXConstCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXConstCastExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXConstCastExpr> in(const Fragment &frag);
  static gap::generator<CXXConstCastExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_CONST_CAST_EXPR;
  }

  static gap::generator<CXXConstCastExpr> containing(const Decl &decl);
  static gap::generator<CXXConstCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXConstCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXConstCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXConstCastExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXConstCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXConstCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXConstCastExpr> from(const Reference &r);
  static std::optional<CXXConstCastExpr> from(const VariantEntity &e);
  static std::optional<CXXConstCastExpr> from(const TokenContext &t);

};

static_assert(sizeof(CXXConstCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
