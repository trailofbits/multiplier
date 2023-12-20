// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class ObjCIsaExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCIsaExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCIsaExpr> in(const Index &index);
  static gap::generator<ObjCIsaExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCIsaExpr> by_id(const Index &, EntityId);
  static gap::generator<ObjCIsaExpr> in(const Fragment &frag);
  static gap::generator<ObjCIsaExpr> in(const File &file);

  static std::optional<ObjCIsaExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCIsaExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_ISA_EXPR;
  }

  static gap::generator<ObjCIsaExpr> containing(const Decl &decl);
  static gap::generator<ObjCIsaExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCIsaExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCIsaExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCIsaExpr> from_base(const Stmt &parent);
  inline static std::optional<ObjCIsaExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCIsaExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCIsaExpr> from(const Reference &r);
  static std::optional<ObjCIsaExpr> from(const VariantEntity &e);
  static std::optional<ObjCIsaExpr> from(const TokenContext &t);

  Expr base(void) const;
  Token base_token_end(void) const;
  Token isa_member_token(void) const;
  Token operation_token(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ObjCIsaExpr) == sizeof(Expr));

#endif
} // namespace mx
