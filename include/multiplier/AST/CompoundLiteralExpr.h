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
class CompoundLiteralExpr;
class Decl;
class Expr;
class File;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CompoundLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CompoundLiteralExpr> in(const Index &index);
  static gap::generator<CompoundLiteralExpr> in(const Fragment &frag);
  static gap::generator<CompoundLiteralExpr> in(const File &file);
  static gap::generator<CompoundLiteralExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CompoundLiteralExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CompoundLiteralExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COMPOUND_LITERAL_EXPR;
  }

  static gap::generator<CompoundLiteralExpr> containing(const Decl &decl);
  static gap::generator<CompoundLiteralExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CompoundLiteralExpr> containing(const Stmt &stmt);
  static gap::generator<CompoundLiteralExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CompoundLiteralExpr> by_id(const Index &, EntityId);

  static std::optional<CompoundLiteralExpr> from_base(const Stmt &parent);
  inline static std::optional<CompoundLiteralExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CompoundLiteralExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CompoundLiteralExpr> from(const Reference &r);
  static std::optional<CompoundLiteralExpr> from(const VariantEntity &e);
  static std::optional<CompoundLiteralExpr> from(const TokenContext &t);

  Expr initializer(void) const;
  Token l_paren_token(void) const;
  bool is_file_scope(void) const;
};

static_assert(sizeof(CompoundLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
