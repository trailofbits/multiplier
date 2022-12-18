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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class ConceptSpecializationExpr;
class Expr;
class Stmt;
class TemplateArgument;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConceptSpecializationExprRange = DerivedEntityRange<StmtIterator, ConceptSpecializationExpr>;
using ConceptSpecializationExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConceptSpecializationExpr>;
using ConceptSpecializationExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConceptSpecializationExpr>;

class ConceptSpecializationExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ConceptSpecializationExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConceptSpecializationExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ConceptSpecializationExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONCEPT_SPECIALIZATION_EXPR;
  }

  static ConceptSpecializationExprContainingStmtRange containing(const Decl &decl);
  static ConceptSpecializationExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConceptSpecializationExpr> from(const TokenContext &c);
  static std::optional<ConceptSpecializationExpr> from(const Expr &parent);

  inline static std::optional<ConceptSpecializationExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ConceptSpecializationExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConceptSpecializationExpr> from(const ValueStmt &parent);

  inline static std::optional<ConceptSpecializationExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ConceptSpecializationExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConceptSpecializationExpr> from(const Stmt &parent);

  inline static std::optional<ConceptSpecializationExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ConceptSpecializationExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<TemplateArgument> template_arguments(void) const;
  bool is_satisfied(void) const;
};

static_assert(sizeof(ConceptSpecializationExpr) == sizeof(Expr));

#endif
} // namespace mx
