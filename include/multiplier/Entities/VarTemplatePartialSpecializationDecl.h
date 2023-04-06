// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "VarTemplateSpecializationDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class DeclaratorDecl;
class NamedDecl;
class Stmt;
class TemplateParameterList;
class Token;
class ValueDecl;
class VarDecl;
class VarTemplatePartialSpecializationDecl;
class VarTemplateSpecializationDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VarTemplatePartialSpecializationDecl : public VarTemplateSpecializationDecl {
 private:
  friend class FragmentImpl;
  friend class VarTemplateSpecializationDecl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<VarTemplatePartialSpecializationDecl> in(const Fragment &frag);
  static gap::generator<VarTemplatePartialSpecializationDecl> in(const File &file);
  static gap::generator<VarTemplatePartialSpecializationDecl> in(const Index &index);
  static gap::generator<VarTemplatePartialSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VarTemplatePartialSpecializationDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION;
  }

  static gap::generator<VarTemplatePartialSpecializationDecl> containing(const Decl &decl);
  static gap::generator<VarTemplatePartialSpecializationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<VarTemplatePartialSpecializationDecl> containing(const Stmt &stmt);
  static gap::generator<VarTemplatePartialSpecializationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  VarTemplatePartialSpecializationDecl canonical_declaration(void) const;
  std::optional<VarTemplatePartialSpecializationDecl> definition(void) const;
  gap::generator<VarTemplatePartialSpecializationDecl> redeclarations(void) const &;
  static std::optional<VarTemplatePartialSpecializationDecl> from(const Decl &parent);

  inline static std::optional<VarTemplatePartialSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return VarTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplatePartialSpecializationDecl> from(const Reference &r);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const TokenContext &t);

  VarTemplatePartialSpecializationDecl instantiated_from_member(void) const;
  TemplateParameterList template_parameters(void) const;
  bool has_associated_constraints(void) const;
};

static_assert(sizeof(VarTemplatePartialSpecializationDecl) == sizeof(VarTemplateSpecializationDecl));

#endif
} // namespace mx
