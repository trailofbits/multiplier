// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class CXXNamedCastExpr;
class CastExpr;
class Decl;
class ExplicitCastExpr;
class Expr;
class File;
class Stmt;
class Token;
class TokenRange;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXNamedCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXNamedCastExpr> in(const Index &index);
  static gap::generator<CXXNamedCastExpr> in(const Fragment &frag);
  static gap::generator<CXXNamedCastExpr> in(const File &file);
  static gap::generator<CXXNamedCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXNamedCastExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXNamedCastExpr, ir::Operation>> in(const Compilation &tu);
  static gap::generator<CXXNamedCastExpr> containing(const Decl &decl);
  static gap::generator<CXXNamedCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXNamedCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXNamedCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXNamedCastExpr> by_id(const Index &, EntityId);

  static std::optional<CXXNamedCastExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXNamedCastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXNamedCastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXNamedCastExpr> from(const Reference &r);
  static std::optional<CXXNamedCastExpr> from(const VariantEntity &e);
  static std::optional<CXXNamedCastExpr> from(const TokenContext &t);

  TokenRange angle_brackets(void) const;
  std::string_view cast_name(void) const;
  Token operator_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(CXXNamedCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
