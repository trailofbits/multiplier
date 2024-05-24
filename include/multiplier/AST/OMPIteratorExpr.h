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
class File;
class OMPIteratorExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPIteratorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<OMPIteratorExpr> in(const Index &index);
  static gap::generator<OMPIteratorExpr> in(const Fragment &frag);
  static gap::generator<OMPIteratorExpr> in(const File &file);
  static gap::generator<OMPIteratorExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPIteratorExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPIteratorExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_ITERATOR_EXPR;
  }

  static gap::generator<OMPIteratorExpr> containing(const Decl &decl);
  static gap::generator<OMPIteratorExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPIteratorExpr> containing(const Stmt &stmt);
  static gap::generator<OMPIteratorExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPIteratorExpr> by_id(const Index &, EntityId);

  static std::optional<OMPIteratorExpr> from_base(const Stmt &parent);
  inline static std::optional<OMPIteratorExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPIteratorExpr> from(const std::optional<Stmt> &parent);
  static std::optional<OMPIteratorExpr> from(const Reference &r);
  static std::optional<OMPIteratorExpr> from(const VariantEntity &e);
  static std::optional<OMPIteratorExpr> from(const TokenContext &t);

  Token iterator_kw_token(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(OMPIteratorExpr) == sizeof(Expr));

#endif
} // namespace mx
