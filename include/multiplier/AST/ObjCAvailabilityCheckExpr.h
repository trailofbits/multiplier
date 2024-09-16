// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class ObjCAvailabilityCheckExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCAvailabilityCheckExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCAvailabilityCheckExpr> in(const Index &index);
  static gap::generator<ObjCAvailabilityCheckExpr> in(const Fragment &frag);
  static gap::generator<ObjCAvailabilityCheckExpr> in(const File &file);
  static gap::generator<ObjCAvailabilityCheckExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ObjCAvailabilityCheckExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCAvailabilityCheckExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR;
  }

  static gap::generator<ObjCAvailabilityCheckExpr> containing(const Decl &decl);
  static gap::generator<ObjCAvailabilityCheckExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCAvailabilityCheckExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCAvailabilityCheckExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCAvailabilityCheckExpr> by_id(const Index &, EntityId);

  static std::optional<ObjCAvailabilityCheckExpr> from_base(const Stmt &parent);
  inline static std::optional<ObjCAvailabilityCheckExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCAvailabilityCheckExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCAvailabilityCheckExpr> from(const Reference &r);
  static std::optional<ObjCAvailabilityCheckExpr> from(const VariantEntity &e);
  static std::optional<ObjCAvailabilityCheckExpr> from(const TokenContext &t);

  bool has_version(void) const;
};

static_assert(sizeof(ObjCAvailabilityCheckExpr) == sizeof(Expr));

#endif
} // namespace mx
