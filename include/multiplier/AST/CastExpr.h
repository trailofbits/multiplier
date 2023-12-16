// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CastKind.h>
#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CastExpr;
class Decl;
class Expr;
class FieldDecl;
class NamedDecl;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CastExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CastExpr> in(const Index &index);
  static gap::generator<CastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CastExpr> by_id(const Index &, EntityId);
  static gap::generator<CastExpr> in(const Fragment &frag);
  static gap::generator<CastExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<CastExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CastExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  static gap::generator<CastExpr> containing(const Decl &decl);
  static gap::generator<CastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CastExpr> containing(const Stmt &stmt);
  static gap::generator<CastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CastExpr> from_base(const Stmt &parent);
  inline static std::optional<CastExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CastExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CastExpr> from(const Reference &r);
  static std::optional<CastExpr> from(const VariantEntity &e);
  static std::optional<CastExpr> from(const TokenContext &t);

  CastKind cast_kind(void) const;
  std::string_view cast_kind_name(void) const;
  std::optional<NamedDecl> conversion_function(void) const;
  Expr sub_expression(void) const;
  Expr sub_expression_as_written(void) const;
  std::optional<FieldDecl> target_union_field(void) const;
  bool has_stored_fp_features(void) const;
};

static_assert(sizeof(CastExpr) == sizeof(Expr));

#endif
} // namespace mx
