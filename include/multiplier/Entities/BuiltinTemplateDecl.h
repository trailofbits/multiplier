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
class BuiltinTemplateDecl;
class Decl;
class NamedDecl;
class Stmt;
class TemplateDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BuiltinTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<BuiltinTemplateDecl> in(const Fragment &frag);
  static gap::generator<BuiltinTemplateDecl> in(const File &file);
  static gap::generator<BuiltinTemplateDecl> in(const Index &index);
  static gap::generator<BuiltinTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BuiltinTemplateDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BUILTIN_TEMPLATE;
  }

  static gap::generator<BuiltinTemplateDecl> containing(const Decl &decl);
  static gap::generator<BuiltinTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<BuiltinTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<BuiltinTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  BuiltinTemplateDecl canonical_declaration(void) const;
  std::optional<BuiltinTemplateDecl> definition(void) const;
  gap::generator<BuiltinTemplateDecl> redeclarations(void) const &;
  static std::optional<BuiltinTemplateDecl> from(const Decl &parent);

  inline static std::optional<BuiltinTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return BuiltinTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BuiltinTemplateDecl> from(const Reference &r);
  static std::optional<BuiltinTemplateDecl> from(const TokenContext &t);

};

static_assert(sizeof(BuiltinTemplateDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
