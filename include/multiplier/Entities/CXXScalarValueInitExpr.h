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
class CXXScalarValueInitExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXScalarValueInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXScalarValueInitExpr> in(const Fragment &frag);
  static gap::generator<CXXScalarValueInitExpr> in(const File &file);
  static gap::generator<CXXScalarValueInitExpr> in(const Index &index);
  static gap::generator<CXXScalarValueInitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXScalarValueInitExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_SCALAR_VALUE_INIT_EXPR;
  }

  static gap::generator<CXXScalarValueInitExpr> containing(const Decl &decl);
  static gap::generator<CXXScalarValueInitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXScalarValueInitExpr> containing(const Stmt &stmt);
  static gap::generator<CXXScalarValueInitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXScalarValueInitExpr> from(const Stmt &parent);

  inline static std::optional<CXXScalarValueInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXScalarValueInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXScalarValueInitExpr> from(const Reference &r) {
    return CXXScalarValueInitExpr::from(r.as_statement());
  }

  inline static std::optional<CXXScalarValueInitExpr> from(const TokenContext &t) {
    return CXXScalarValueInitExpr::from(t.as_statement());
  }

  Token r_paren_token(void) const;
};

static_assert(sizeof(CXXScalarValueInitExpr) == sizeof(Expr));

#endif
} // namespace mx
