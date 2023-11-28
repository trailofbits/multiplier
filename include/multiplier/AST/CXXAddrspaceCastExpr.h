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
class CXXAddrspaceCastExpr;
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
class CXXAddrspaceCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXAddrspaceCastExpr> in(const Index &index);
  static gap::generator<CXXAddrspaceCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXAddrspaceCastExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXAddrspaceCastExpr> in(const Fragment &frag);
  static gap::generator<CXXAddrspaceCastExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_ADDRSPACE_CAST_EXPR;
  }

  static gap::generator<CXXAddrspaceCastExpr> containing(const Decl &decl);
  static gap::generator<CXXAddrspaceCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXAddrspaceCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXAddrspaceCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXAddrspaceCastExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXAddrspaceCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXAddrspaceCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXAddrspaceCastExpr> from(const Reference &r);
  static std::optional<CXXAddrspaceCastExpr> from(const VariantEntity &e);
  static std::optional<CXXAddrspaceCastExpr> from(const TokenContext &t);

};

static_assert(sizeof(CXXAddrspaceCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
