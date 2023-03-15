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
class AddrLabelExpr;
class Decl;
class Expr;
class LabelDecl;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AddrLabelExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<AddrLabelExpr> in(const Fragment &frag);
  static gap::generator<AddrLabelExpr> in(const File &file);
  static gap::generator<AddrLabelExpr> in(const Index &index);
  static gap::generator<AddrLabelExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AddrLabelExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::ADDR_LABEL_EXPR;
  }

  static gap::generator<AddrLabelExpr> containing(const Decl &decl);
  static gap::generator<AddrLabelExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<AddrLabelExpr> containing(const Stmt &stmt);
  static gap::generator<AddrLabelExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AddrLabelExpr> from(const Stmt &parent);

  inline static std::optional<AddrLabelExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AddrLabelExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AddrLabelExpr> from(const Reference &r);
  static std::optional<AddrLabelExpr> from(const TokenContext &t);

  Token amp_amp_token(void) const;
  LabelDecl label(void) const;
  Token label_token(void) const;
};

static_assert(sizeof(AddrLabelExpr) == sizeof(Expr));

#endif
} // namespace mx
