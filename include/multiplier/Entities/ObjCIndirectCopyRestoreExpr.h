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
class ObjCIndirectCopyRestoreExpr;
class Stmt;
class Token;
class ValueStmt;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCIndirectCopyRestoreExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCIndirectCopyRestoreExpr> in(const Fragment &frag);
  static gap::generator<ObjCIndirectCopyRestoreExpr> in(const File &file);
  static gap::generator<ObjCIndirectCopyRestoreExpr> in(const Index &index);
  static gap::generator<ObjCIndirectCopyRestoreExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCIndirectCopyRestoreExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR;
  }

  static gap::generator<ObjCIndirectCopyRestoreExpr> containing(const Decl &decl);
  static gap::generator<ObjCIndirectCopyRestoreExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCIndirectCopyRestoreExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCIndirectCopyRestoreExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCIndirectCopyRestoreExpr> from(const Stmt &parent);

  inline static std::optional<ObjCIndirectCopyRestoreExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCIndirectCopyRestoreExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCIndirectCopyRestoreExpr> from(const Reference &r);
  static std::optional<ObjCIndirectCopyRestoreExpr> from(const TokenContext &t);

  Expr sub_expression(void) const;
  bool should_copy(void) const;
};

static_assert(sizeof(ObjCIndirectCopyRestoreExpr) == sizeof(Expr));

#endif
} // namespace mx
