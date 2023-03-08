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
class ExtVectorElementExpr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExtVectorElementExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ExtVectorElementExpr> in(const Fragment &frag);
  static gap::generator<ExtVectorElementExpr> in(const File &file);
  static gap::generator<ExtVectorElementExpr> in(const Index &index);
  static gap::generator<ExtVectorElementExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExtVectorElementExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
  }

  static gap::generator<ExtVectorElementExpr> containing(const Decl &decl);
  static gap::generator<ExtVectorElementExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ExtVectorElementExpr> containing(const Stmt &stmt);
  static gap::generator<ExtVectorElementExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ExtVectorElementExpr> from(const Stmt &parent);

  inline static std::optional<ExtVectorElementExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ExtVectorElementExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorElementExpr> from(const Reference &r);
  static std::optional<ExtVectorElementExpr> from(const TokenContext &t);

  bool contains_duplicate_elements(void) const;
  Token accessor_token(void) const;
  Expr base(void) const;
  bool is_arrow(void) const;
};

static_assert(sizeof(ExtVectorElementExpr) == sizeof(Expr));

#endif
} // namespace mx
