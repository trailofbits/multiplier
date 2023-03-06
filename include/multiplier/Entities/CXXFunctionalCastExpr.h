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

#include "ExplicitCastExpr.h"

namespace mx {
class CXXFunctionalCastExpr;
class CastExpr;
class Decl;
class ExplicitCastExpr;
class Expr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXFunctionalCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXFunctionalCastExpr> in(const Fragment &frag);
  static gap::generator<CXXFunctionalCastExpr> in(const File &file);
  static gap::generator<CXXFunctionalCastExpr> in(const Index &index);
  static gap::generator<CXXFunctionalCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXFunctionalCastExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_FUNCTIONAL_CAST_EXPR;
  }

  static gap::generator<CXXFunctionalCastExpr> containing(const Decl &decl);
  static gap::generator<CXXFunctionalCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXFunctionalCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXFunctionalCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXFunctionalCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXFunctionalCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXFunctionalCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXFunctionalCastExpr> from(const Reference &r) {
    return CXXFunctionalCastExpr::from(r.as_statement());
  }

  inline static std::optional<CXXFunctionalCastExpr> from(const TokenContext &t) {
    return CXXFunctionalCastExpr::from(t.as_statement());
  }

  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  bool is_list_initialization(void) const;
};

static_assert(sizeof(CXXFunctionalCastExpr) == sizeof(ExplicitCastExpr));

#endif
} // namespace mx
