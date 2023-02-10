// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXDefaultArgExpr;
class Expr;
class ParmVarDecl;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDefaultArgExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXDefaultArgExpr> in(const Fragment &frag);
  static gap::generator<CXXDefaultArgExpr> in(const File &file);
  static gap::generator<CXXDefaultArgExpr> in(const Index &index);
  static gap::generator<CXXDefaultArgExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDefaultArgExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DEFAULT_ARG_EXPR;
  }

  static gap::generator<CXXDefaultArgExpr> containing(const Decl &decl);
  static gap::generator<CXXDefaultArgExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDefaultArgExpr> containing(const Stmt &stmt);
  static gap::generator<CXXDefaultArgExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDefaultArgExpr> from(const Stmt &parent);

  inline static std::optional<CXXDefaultArgExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXDefaultArgExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXDefaultArgExpr> from(const Reference &r) {
    return CXXDefaultArgExpr::from(r.as_statement());
  }

  inline static std::optional<CXXDefaultArgExpr> from(const TokenContext &t) {
    return CXXDefaultArgExpr::from(t.as_statement());
  }

  Expr expression(void) const;
  ParmVarDecl parameter(void) const;
  Token used_token(void) const;
};

static_assert(sizeof(CXXDefaultArgExpr) == sizeof(Expr));

#endif
} // namespace mx
