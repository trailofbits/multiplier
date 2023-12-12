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
class CXXRecordDecl;
class Decl;
class Expr;
class OverloadExpr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OverloadExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<OverloadExpr> in(const Index &index);
  static gap::generator<OverloadExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OverloadExpr> by_id(const Index &, EntityId);
  static gap::generator<OverloadExpr> in(const Fragment &frag);
  static gap::generator<OverloadExpr> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<OverloadExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<OverloadExpr, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  static gap::generator<OverloadExpr> containing(const Decl &decl);
  static gap::generator<OverloadExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<OverloadExpr> containing(const Stmt &stmt);
  static gap::generator<OverloadExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OverloadExpr> from_base(const Stmt &parent);
  inline static std::optional<OverloadExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OverloadExpr> from(const std::optional<Stmt> &parent);
  static std::optional<OverloadExpr> from(const Reference &r);
  static std::optional<OverloadExpr> from(const VariantEntity &e);
  static std::optional<OverloadExpr> from(const TokenContext &t);

  Token l_angle_token(void) const;
  Token name_token(void) const;
  std::optional<CXXRecordDecl> naming_class(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
};

static_assert(sizeof(OverloadExpr) == sizeof(Expr));

#endif
} // namespace mx
