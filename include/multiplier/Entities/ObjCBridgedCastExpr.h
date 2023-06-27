// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ExplicitCastExpr.h"
#include "ObjCBridgeCastKind.h"

namespace mx {
class EntityProvider;
class Index;
class CastExpr;
class Decl;
class ExplicitCastExpr;
class Expr;
class ObjCBridgedCastExpr;
class Stmt;
class Token;
class ValueStmt;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCBridgedCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCBridgedCastExpr> in(const Fragment &frag);
  static gap::generator<ObjCBridgedCastExpr> in(const File &file);
  static gap::generator<ObjCBridgedCastExpr> in(const Index &index);
  static gap::generator<ObjCBridgedCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCBridgedCastExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_BRIDGED_CAST_EXPR;
  }

  static gap::generator<ObjCBridgedCastExpr> containing(const Decl &decl);
  static gap::generator<ObjCBridgedCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCBridgedCastExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCBridgedCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCBridgedCastExpr> from(const Stmt &parent);

  inline static std::optional<ObjCBridgedCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCBridgedCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBridgedCastExpr> from(const Reference &r);
  static std::optional<ObjCBridgedCastExpr> from(const TokenContext &t);

  Token bridge_keyword_token(void) const;
  ObjCBridgeCastKind bridge_kind(void) const;
  std::string_view bridge_kind_name(void) const;
  Token l_paren_token(void) const;
};

static_assert(sizeof(ObjCBridgedCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
