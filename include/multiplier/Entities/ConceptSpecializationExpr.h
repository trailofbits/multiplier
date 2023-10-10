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
class ConceptDecl;
class ConceptSpecializationExpr;
class Decl;
class Expr;
class ImplicitConceptSpecializationDecl;
class NamedDecl;
class Stmt;
class TemplateArgument;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConceptSpecializationExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ConceptSpecializationExpr> in(const Index &index);
  static gap::generator<ConceptSpecializationExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConceptSpecializationExpr> by_id(const Index &, EntityId);
  static gap::generator<ConceptSpecializationExpr> in(const Fragment &frag);
  static gap::generator<ConceptSpecializationExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CONCEPT_SPECIALIZATION_EXPR;
  }

  static gap::generator<ConceptSpecializationExpr> containing(const Decl &decl);
  static gap::generator<ConceptSpecializationExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ConceptSpecializationExpr> containing(const Stmt &stmt);
  static gap::generator<ConceptSpecializationExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConceptSpecializationExpr> from(const Stmt &parent);

  inline static std::optional<ConceptSpecializationExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ConceptSpecializationExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConceptSpecializationExpr> from(const Reference &r);
  static std::optional<ConceptSpecializationExpr> from(const TokenContext &t);

  Token concept_name_token(void) const;
  NamedDecl found_declaration(void) const;
  ConceptDecl named_concept(void) const;
  ImplicitConceptSpecializationDecl specialization_declaration(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  unsigned num_template_arguments(void) const;
  gap::generator<TemplateArgument> template_arguments(void) const &;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool is_satisfied(void) const;
};

static_assert(sizeof(ConceptSpecializationExpr) == sizeof(Expr));

#endif
} // namespace mx
