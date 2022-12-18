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
class ObjCIndirectCopyRestoreExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCIndirectCopyRestoreExprRange = DerivedEntityRange<StmtIterator, ObjCIndirectCopyRestoreExpr>;
using ObjCIndirectCopyRestoreExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCIndirectCopyRestoreExpr>;
using ObjCIndirectCopyRestoreExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCIndirectCopyRestoreExpr>;

class ObjCIndirectCopyRestoreExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCIndirectCopyRestoreExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCIndirectCopyRestoreExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCIndirectCopyRestoreExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR;
  }

  static ObjCIndirectCopyRestoreExprContainingStmtRange containing(const Decl &decl);
  static ObjCIndirectCopyRestoreExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCIndirectCopyRestoreExpr> from(const TokenContext &c);
  static std::optional<ObjCIndirectCopyRestoreExpr> from(const Expr &parent);

  inline static std::optional<ObjCIndirectCopyRestoreExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCIndirectCopyRestoreExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIndirectCopyRestoreExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCIndirectCopyRestoreExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCIndirectCopyRestoreExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIndirectCopyRestoreExpr> from(const Stmt &parent);

  inline static std::optional<ObjCIndirectCopyRestoreExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCIndirectCopyRestoreExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr sub_expression(void) const;
  bool should_copy(void) const;
};

static_assert(sizeof(ObjCIndirectCopyRestoreExpr) == sizeof(Expr));

#endif
} // namespace mx
