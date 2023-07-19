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
class ObjCEncodeExpr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCEncodeExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCEncodeExpr> in(const Index &index);
  static gap::generator<ObjCEncodeExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCEncodeExpr> by_id(const Index &, EntityId);
  static gap::generator<ObjCEncodeExpr> in(const Fragment &frag);
  static gap::generator<ObjCEncodeExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_ENCODE_EXPR;
  }

  static gap::generator<ObjCEncodeExpr> containing(const Decl &decl);
  static gap::generator<ObjCEncodeExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCEncodeExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCEncodeExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCEncodeExpr> from(const Stmt &parent);

  inline static std::optional<ObjCEncodeExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCEncodeExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCEncodeExpr> from(const Reference &r);
  static std::optional<ObjCEncodeExpr> from(const TokenContext &t);

  Token at_token(void) const;
  Type encoded_type(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ObjCEncodeExpr) == sizeof(Expr));

#endif
} // namespace mx
