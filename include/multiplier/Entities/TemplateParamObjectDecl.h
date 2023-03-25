// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ValueDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class TemplateParamObjectDecl;
class Token;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateParamObjectDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TemplateParamObjectDecl> in(const Fragment &frag);
  static gap::generator<TemplateParamObjectDecl> in(const File &file);
  static gap::generator<TemplateParamObjectDecl> in(const Index &index);
  static gap::generator<TemplateParamObjectDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TemplateParamObjectDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TEMPLATE_PARAM_OBJECT;
  }

  static gap::generator<TemplateParamObjectDecl> containing(const Decl &decl);
  static gap::generator<TemplateParamObjectDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TemplateParamObjectDecl> containing(const Stmt &stmt);
  static gap::generator<TemplateParamObjectDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TemplateParamObjectDecl canonical_declaration(void) const;
  std::optional<TemplateParamObjectDecl> definition(void) const;
  gap::generator<TemplateParamObjectDecl> redeclarations(void) const &;
  static std::optional<TemplateParamObjectDecl> from(const Decl &parent);

  inline static std::optional<TemplateParamObjectDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateParamObjectDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateParamObjectDecl> from(const Reference &r);
  static std::optional<TemplateParamObjectDecl> from(const TokenContext &t);

};

static_assert(sizeof(TemplateParamObjectDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
