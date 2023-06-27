// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TemplateDecl.h"

namespace mx {
class EntityProvider;
class Index;
class ConceptDecl;
class Decl;
class Expr;
class NamedDecl;
class Stmt;
class TemplateDecl;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConceptDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ConceptDecl> in(const Fragment &frag);
  static gap::generator<ConceptDecl> in(const File &file);
  static gap::generator<ConceptDecl> in(const Index &index);
  static gap::generator<ConceptDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConceptDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CONCEPT;
  }

  static gap::generator<ConceptDecl> containing(const Decl &decl);
  static gap::generator<ConceptDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ConceptDecl> containing(const Stmt &stmt);
  static gap::generator<ConceptDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ConceptDecl canonical_declaration(void) const;
  std::optional<ConceptDecl> definition(void) const;
  gap::generator<ConceptDecl> redeclarations(void) const &;
  static std::optional<ConceptDecl> from(const Decl &parent);

  inline static std::optional<ConceptDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ConceptDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConceptDecl> from(const Reference &r);
  static std::optional<ConceptDecl> from(const TokenContext &t);

  Expr constraint_expression(void) const;
  bool is_type_concept(void) const;
};

static_assert(sizeof(ConceptDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
