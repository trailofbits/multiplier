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
class ExtVectorElementExpr;
class File;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ExtVectorElementExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ExtVectorElementExpr> in(const Index &index);
  static gap::generator<ExtVectorElementExpr> in(const Fragment &frag);
  static gap::generator<ExtVectorElementExpr> in(const File &file);
  static gap::generator<ExtVectorElementExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ExtVectorElementExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<ExtVectorElementExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
  }

  static gap::generator<ExtVectorElementExpr> containing(const Decl &decl);
  static gap::generator<ExtVectorElementExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ExtVectorElementExpr> containing(const Stmt &stmt);
  static gap::generator<ExtVectorElementExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExtVectorElementExpr> by_id(const Index &, EntityId);

  static std::optional<ExtVectorElementExpr> from_base(const Stmt &parent);
  inline static std::optional<ExtVectorElementExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ExtVectorElementExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ExtVectorElementExpr> from(const Reference &r);
  static std::optional<ExtVectorElementExpr> from(const VariantEntity &e);
  static std::optional<ExtVectorElementExpr> from(const TokenContext &t);

  bool contains_duplicate_elements(void) const;
  Token accessor_token(void) const;
  Expr base(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ExtVectorElementExpr) == sizeof(Expr));

#endif
} // namespace mx
