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
class CXXNamedCastExpr;
class CXXReinterpretCastExpr;
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
class MX_EXPORT CXXReinterpretCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXReinterpretCastExpr> in(const Index &index);
  static gap::generator<CXXReinterpretCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXReinterpretCastExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXReinterpretCastExpr> in(const Fragment &frag);
  static gap::generator<CXXReinterpretCastExpr> in(const File &file);

  static std::optional<CXXReinterpretCastExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXReinterpretCastExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_REINTERPRET_CAST_EXPR;
  }

  static gap::generator<CXXReinterpretCastExpr> containing(const Decl &decl);
  static gap::generator<CXXReinterpretCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXReinterpretCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXReinterpretCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXReinterpretCastExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXReinterpretCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXReinterpretCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXReinterpretCastExpr> from(const Reference &r);
  static std::optional<CXXReinterpretCastExpr> from(const VariantEntity &e);
  static std::optional<CXXReinterpretCastExpr> from(const TokenContext &t);

};

static_assert(sizeof(CXXReinterpretCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
