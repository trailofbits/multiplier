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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class NonTypeTemplateParmDecl;
class Stmt;
class SubstNonTypeTemplateParmExpr;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SubstNonTypeTemplateParmExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<SubstNonTypeTemplateParmExpr> in(const Fragment &frag);
  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR;
  }

  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const Decl &decl);
  static gap::generator<SubstNonTypeTemplateParmExpr> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<SubstNonTypeTemplateParmExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<SubstNonTypeTemplateParmExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<SubstNonTypeTemplateParmExpr> from(const Expr &parent);

  inline static std::optional<SubstNonTypeTemplateParmExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return SubstNonTypeTemplateParmExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SubstNonTypeTemplateParmExpr> from(const ValueStmt &parent);

  inline static std::optional<SubstNonTypeTemplateParmExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return SubstNonTypeTemplateParmExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SubstNonTypeTemplateParmExpr> from(const Stmt &parent);

  inline static std::optional<SubstNonTypeTemplateParmExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SubstNonTypeTemplateParmExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token name_token(void) const;
  NonTypeTemplateParmDecl parameter(void) const;
  Type parameter_type(void) const;
  Expr replacement(void) const;
  bool is_reference_parameter(void) const;
};

static_assert(sizeof(SubstNonTypeTemplateParmExpr) == sizeof(Expr));

#endif
} // namespace mx
