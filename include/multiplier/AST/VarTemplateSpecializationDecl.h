// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TemplateSpecializationKind.h>
#include <multiplier/AST/VarDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class NamedDecl;
class Stmt;
class TemplateArgument;
class Token;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplateSpecializationDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT VarTemplateSpecializationDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<VarTemplateSpecializationDecl> in(const Index &index);
  static gap::generator<VarTemplateSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VarTemplateSpecializationDecl> by_id(const Index &, EntityId);
  static gap::generator<VarTemplateSpecializationDecl> in(const Fragment &frag);
  static gap::generator<VarTemplateSpecializationDecl> in(const File &file);

  static std::optional<VarTemplateSpecializationDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<VarTemplateSpecializationDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR_TEMPLATE_SPECIALIZATION;
  }

  static gap::generator<VarTemplateSpecializationDecl> containing(const Decl &decl);
  static gap::generator<VarTemplateSpecializationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<VarTemplateSpecializationDecl> containing(const Stmt &stmt);
  static gap::generator<VarTemplateSpecializationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  VarTemplateSpecializationDecl canonical_declaration(void) const;
  std::optional<VarTemplateSpecializationDecl> definition(void) const;
  gap::generator<VarTemplateSpecializationDecl> redeclarations(void) const &;
  static std::optional<VarTemplateSpecializationDecl> from_base(const Decl &parent);
  inline static std::optional<VarTemplateSpecializationDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<VarTemplateSpecializationDecl> from(const std::optional<Decl> &parent);
  static std::optional<VarTemplateSpecializationDecl> from(const Reference &r);
  static std::optional<VarTemplateSpecializationDecl> from(const VariantEntity &e);
  static std::optional<VarTemplateSpecializationDecl> from(const TokenContext &t);

  Token extern_token(void) const;
  TemplateSpecializationKind specialization_kind(void) const;
  VarTemplateDecl specialized_template(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  unsigned num_template_arguments(void) const;
  gap::generator<TemplateArgument> template_arguments(void) const &;
  Token template_keyword_token(void) const;
  bool is_class_scope_explicit_specialization(void) const;
  bool is_explicit_instantiation_or_specialization(void) const;
  bool is_explicit_specialization(void) const;
};

static_assert(sizeof(VarTemplateSpecializationDecl) == sizeof(VarDecl));

#endif
} // namespace mx
