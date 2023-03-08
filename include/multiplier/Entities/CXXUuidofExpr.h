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
class CXXUuidofExpr;
class Decl;
class Expr;
class MSGuidDecl;
class Stmt;
class Token;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXUuidofExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXUuidofExpr> in(const Fragment &frag);
  static gap::generator<CXXUuidofExpr> in(const File &file);
  static gap::generator<CXXUuidofExpr> in(const Index &index);
  static gap::generator<CXXUuidofExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXUuidofExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_UUIDOF_EXPR;
  }

  static gap::generator<CXXUuidofExpr> containing(const Decl &decl);
  static gap::generator<CXXUuidofExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXUuidofExpr> containing(const Stmt &stmt);
  static gap::generator<CXXUuidofExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXUuidofExpr> from(const Stmt &parent);

  inline static std::optional<CXXUuidofExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXUuidofExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXUuidofExpr> from(const Reference &r);
  static std::optional<CXXUuidofExpr> from(const TokenContext &t);

  std::optional<Expr> expression_operand(void) const;
  MSGuidDecl guid_declaration(void) const;
  Type type_operand(void) const;
  Type type_operand_source_info(void) const;
  bool is_type_operand(void) const;
};

static_assert(sizeof(CXXUuidofExpr) == sizeof(Expr));

#endif
} // namespace mx
