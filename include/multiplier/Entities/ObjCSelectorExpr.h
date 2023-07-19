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
class ObjCSelectorExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCSelectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCSelectorExpr> in(const Index &index);
  static gap::generator<ObjCSelectorExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCSelectorExpr> by_id(const Index &, EntityId);
  static gap::generator<ObjCSelectorExpr> in(const Fragment &frag);
  static gap::generator<ObjCSelectorExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_SELECTOR_EXPR;
  }

  static gap::generator<ObjCSelectorExpr> containing(const Decl &decl);
  static gap::generator<ObjCSelectorExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCSelectorExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCSelectorExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCSelectorExpr> from(const Stmt &parent);

  inline static std::optional<ObjCSelectorExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCSelectorExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCSelectorExpr> from(const Reference &r);
  static std::optional<ObjCSelectorExpr> from(const TokenContext &t);

  Token at_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCSelectorExpr) == sizeof(Expr));

#endif
} // namespace mx
