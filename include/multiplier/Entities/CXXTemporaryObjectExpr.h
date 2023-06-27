// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CXXConstructExpr.h"

namespace mx {
class EntityProvider;
class Index;
class CXXConstructExpr;
class CXXTemporaryObjectExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXTemporaryObjectExpr : public CXXConstructExpr {
 private:
  friend class FragmentImpl;
  friend class CXXConstructExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXTemporaryObjectExpr> in(const Fragment &frag);
  static gap::generator<CXXTemporaryObjectExpr> in(const File &file);
  static gap::generator<CXXTemporaryObjectExpr> in(const Index &index);
  static gap::generator<CXXTemporaryObjectExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXTemporaryObjectExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_TEMPORARY_OBJECT_EXPR;
  }

  static gap::generator<CXXTemporaryObjectExpr> containing(const Decl &decl);
  static gap::generator<CXXTemporaryObjectExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXTemporaryObjectExpr> containing(const Stmt &stmt);
  static gap::generator<CXXTemporaryObjectExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXTemporaryObjectExpr> from(const Stmt &parent);

  inline static std::optional<CXXTemporaryObjectExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXTemporaryObjectExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXTemporaryObjectExpr> from(const Reference &r);
  static std::optional<CXXTemporaryObjectExpr> from(const TokenContext &t);

};

static_assert(sizeof(CXXTemporaryObjectExpr) == sizeof(CXXConstructExpr));

#endif
} // namespace mx
