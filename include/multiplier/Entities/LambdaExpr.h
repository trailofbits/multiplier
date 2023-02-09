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
#include "LambdaCaptureDefault.h"
#include "StmtKind.h"

namespace mx {
class CXXMethodDecl;
class CXXRecordDecl;
class CompoundStmt;
class Expr;
class FunctionTemplateDecl;
class LambdaExpr;
class NamedDecl;
class Stmt;
class TemplateParameterList;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LambdaExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<LambdaExpr> in(const Fragment &frag);
  static gap::generator<LambdaExpr> in(const Index &index);
  static gap::generator<LambdaExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LambdaExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::LAMBDA_EXPR;
  }

  static gap::generator<LambdaExpr> containing(const Decl &decl);
  static gap::generator<LambdaExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<LambdaExpr> containing(const Stmt &stmt);
  static gap::generator<LambdaExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<LambdaExpr> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<LambdaExpr> from(const TokenContext &t) {
    return from(t.as_statement());
  }

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
  std::optional<FunctionTemplateDecl> dependent_call_operator(void) const;
  std::optional<NamedDecl> nth_explicit_template_parameter(unsigned n) const;
  gap::generator<NamedDecl> explicit_template_parameters(void) const;
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
