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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Decl.h"
#include "DeclKind.h"
#include "ObjCPropertyImplDeclKind.h"

namespace mx {
class Decl;
class Expr;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCPropertyImplDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ObjCPropertyImplDecl> in(const Fragment &frag);
  static gap::generator<ObjCPropertyImplDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_PROPERTY_IMPL;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<ObjCPropertyImplDecl> containing(const Decl &decl);
  static gap::generator<ObjCPropertyImplDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCPropertyImplDecl> redeclarations(void) const;
  inline static std::optional<ObjCPropertyImplDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ObjCPropertyImplDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ObjCPropertyImplDecl> from(const Decl &parent);

  inline static std::optional<ObjCPropertyImplDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCPropertyImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr getter_cxx_constructor(void) const;
  ObjCMethodDecl getter_method_declaration(void) const;
  ObjCPropertyDecl property_declaration(void) const;
  ObjCPropertyImplDeclKind property_implementation(void) const;
  ObjCIvarDecl property_instance_variable_declaration(void) const;
  Token property_instance_variable_declaration_token(void) const;
  Expr setter_cxx_assignment(void) const;
  ObjCMethodDecl setter_method_declaration(void) const;
  bool is_instance_variable_name_specified(void) const;
};

static_assert(sizeof(ObjCPropertyImplDecl) == sizeof(Decl));

#endif
} // namespace mx
