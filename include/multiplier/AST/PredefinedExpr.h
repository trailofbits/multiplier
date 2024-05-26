// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>
#include <multiplier/AST/PredefinedIdentKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class File;
class PredefinedExpr;
class Stmt;
class StringLiteral;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PredefinedExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<PredefinedExpr> in(const Index &index);
  static gap::generator<PredefinedExpr> in(const Fragment &frag);
  static gap::generator<PredefinedExpr> in(const File &file);
  static gap::generator<PredefinedExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<PredefinedExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<PredefinedExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PREDEFINED_EXPR;
  }

  static gap::generator<PredefinedExpr> containing(const Decl &decl);
  static gap::generator<PredefinedExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<PredefinedExpr> containing(const Stmt &stmt);
  static gap::generator<PredefinedExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PredefinedExpr> by_id(const Index &, EntityId);

  static std::optional<PredefinedExpr> from_base(const Stmt &parent);
  inline static std::optional<PredefinedExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<PredefinedExpr> from(const std::optional<Stmt> &parent);
  static std::optional<PredefinedExpr> from(const Reference &r);
  static std::optional<PredefinedExpr> from(const VariantEntity &e);
  static std::optional<PredefinedExpr> from(const TokenContext &t);

  std::optional<StringLiteral> function_name(void) const;
  PredefinedIdentKind identifier_kind(void) const;
  std::string_view identifier_kind_name(void) const;
  Token token(void) const;
  bool is_transparent(void) const;
};

static_assert(sizeof(PredefinedExpr) == sizeof(Expr));

#endif
} // namespace mx
