// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "RedeclarableTemplateDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class Stmt;
class TemplateDecl;
class Token;
class VarTemplateDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VarTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<VarTemplateDecl> in(const Index &index);
  static gap::generator<VarTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VarTemplateDecl> by_id(const Index &, EntityId);
  static gap::generator<VarTemplateDecl> in(const Fragment &frag);
  static gap::generator<VarTemplateDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR_TEMPLATE;
  }

  static gap::generator<VarTemplateDecl> containing(const Decl &decl);
  static gap::generator<VarTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<VarTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<VarTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  VarTemplateDecl canonical_declaration(void) const;
  std::optional<VarTemplateDecl> definition(void) const;
  gap::generator<VarTemplateDecl> redeclarations(void) const &;
  static std::optional<VarTemplateDecl> from(const Decl &parent);

  inline static std::optional<VarTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return VarTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateDecl> from(const Reference &r);
  static std::optional<VarTemplateDecl> from(const TokenContext &t);

  bool is_this_declaration_a_definition(void) const;
};

static_assert(sizeof(VarTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
