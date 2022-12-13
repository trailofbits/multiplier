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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "LambdaCaptureDefault.h"
#include "StmtKind.h"
#include "StmtUseSelector.h"

namespace mx {
class CXXMethodDecl;
class CXXRecordDecl;
class CompoundStmt;
class Expr;
class LambdaExpr;
class NamedDecl;
class Stmt;
class TemplateParameterList;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LambdaExprRange = DerivedEntityRange<StmtIterator, LambdaExpr>;
using LambdaExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, LambdaExpr>;
using LambdaExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, LambdaExpr>;

class LambdaExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static LambdaExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LambdaExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : LambdaExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::LAMBDA_EXPR;
  }

  static LambdaExprContainingStmtRange containing(const Decl &decl);
  static LambdaExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<LambdaExpr> from(const TokenContext &c);
  static std::optional<LambdaExpr> from(const Expr &parent);

  inline static std::optional<LambdaExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return LambdaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LambdaExpr> from(const ValueStmt &parent);

  inline static std::optional<LambdaExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return LambdaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LambdaExpr> from(const Stmt &parent);

  inline static std::optional<LambdaExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return LambdaExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt body(void) const;
  CXXMethodDecl call_operator(void) const;
  LambdaCaptureDefault capture_default(void) const;
  Token capture_default_token(void) const;
  CompoundStmt compound_statement_body(void) const;
  std::vector<NamedDecl> explicit_template_parameters(void) const;
  TokenRange introducer_range(void) const;
  CXXRecordDecl lambda_class(void) const;
  std::optional<TemplateParameterList> template_parameter_list(void) const;
  std::optional<Expr> trailing_requires_clause(void) const;
  bool has_explicit_parameters(void) const;
  bool has_explicit_result_type(void) const;
  bool is_generic_lambda(void) const;
  bool is_mutable(void) const;
};

static_assert(sizeof(LambdaExpr) == sizeof(Expr));

#endif
} // namespace mx
