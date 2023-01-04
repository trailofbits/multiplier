// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCIsaExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCIsaExprRange = DerivedEntityRange<StmtIterator, ObjCIsaExpr>;
using ObjCIsaExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCIsaExpr>;
using ObjCIsaExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCIsaExpr>;

class ObjCIsaExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCIsaExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCIsaExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCIsaExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_ISA_EXPR;
  }

  static ObjCIsaExprContainingStmtRange containing(const Decl &decl);
  static ObjCIsaExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCIsaExpr> from(const TokenContext &c);
  static std::optional<ObjCIsaExpr> from(const Expr &parent);

  inline static std::optional<ObjCIsaExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCIsaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIsaExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCIsaExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCIsaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIsaExpr> from(const Stmt &parent);

  inline static std::optional<ObjCIsaExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCIsaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  Token base_token_end(void) const;
  Token isa_member_token(void) const;
  Token operation_token(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ObjCIsaExpr) == sizeof(Expr));

#endif
} // namespace mx
