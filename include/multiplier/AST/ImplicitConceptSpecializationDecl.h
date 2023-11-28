// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class ImplicitConceptSpecializationDecl;
class Stmt;
class TemplateArgument;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ImplicitConceptSpecializationDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ImplicitConceptSpecializationDecl> in(const Index &index);
  static gap::generator<ImplicitConceptSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ImplicitConceptSpecializationDecl> by_id(const Index &, EntityId);
  static gap::generator<ImplicitConceptSpecializationDecl> in(const Fragment &frag);
  static gap::generator<ImplicitConceptSpecializationDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::IMPLICIT_CONCEPT_SPECIALIZATION;
  }

  static gap::generator<ImplicitConceptSpecializationDecl> containing(const Decl &decl);
  static gap::generator<ImplicitConceptSpecializationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ImplicitConceptSpecializationDecl> containing(const Stmt &stmt);
  static gap::generator<ImplicitConceptSpecializationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ImplicitConceptSpecializationDecl canonical_declaration(void) const;
  std::optional<ImplicitConceptSpecializationDecl> definition(void) const;
  gap::generator<ImplicitConceptSpecializationDecl> redeclarations(void) const &;
  static std::optional<ImplicitConceptSpecializationDecl> from_base(const Decl &parent);
  inline static std::optional<ImplicitConceptSpecializationDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ImplicitConceptSpecializationDecl> from(const std::optional<Decl> &parent);
  static std::optional<ImplicitConceptSpecializationDecl> from(const Reference &r);
  static std::optional<ImplicitConceptSpecializationDecl> from(const VariantEntity &e);
  static std::optional<ImplicitConceptSpecializationDecl> from(const TokenContext &t);

  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  unsigned num_template_arguments(void) const;
  gap::generator<TemplateArgument> template_arguments(void) const &;
};

static_assert(sizeof(ImplicitConceptSpecializationDecl) == sizeof(Decl));

#endif
} // namespace mx
