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
class Decl;
class NamedDecl;
class Stmt;
class TemplateDecl;
class TemplateTemplateParmDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateTemplateParmDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TemplateTemplateParmDecl> in(const Fragment &frag);
  static gap::generator<TemplateTemplateParmDecl> in(const File &file);
  static gap::generator<TemplateTemplateParmDecl> in(const Index &index);
  static gap::generator<TemplateTemplateParmDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TemplateTemplateParmDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TEMPLATE_TEMPLATE_PARM;
  }

  static gap::generator<TemplateTemplateParmDecl> containing(const Decl &decl);
  static gap::generator<TemplateTemplateParmDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TemplateTemplateParmDecl> containing(const Stmt &stmt);
  static gap::generator<TemplateTemplateParmDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TemplateTemplateParmDecl canonical_declaration(void) const;
  std::optional<TemplateTemplateParmDecl> definition(void) const;
  gap::generator<TemplateTemplateParmDecl> redeclarations(void) const &;
  static std::optional<TemplateTemplateParmDecl> from(const Decl &parent);

  inline static std::optional<TemplateTemplateParmDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateTemplateParmDecl> from(const Reference &r);
  static std::optional<TemplateTemplateParmDecl> from(const TokenContext &t);

  bool default_argument_was_inherited(void) const;
  Token default_argument_token(void) const;
  bool has_default_argument(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(TemplateTemplateParmDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
