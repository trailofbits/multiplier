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

#include "DeclKind.h"
#include "NamedDecl.h"
#include "ObjCPropertyDeclPropertyControl.h"
#include "ObjCPropertyDeclSetterKind.h"
#include "ObjCPropertyQueryKind.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCIvarDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCPropertyDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCPropertyDecl> in(const Fragment &frag);
  static gap::generator<ObjCPropertyDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_PROPERTY;
  }

  static gap::generator<ObjCPropertyDecl> containing(const Decl &decl);
  static gap::generator<ObjCPropertyDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCPropertyDecl> redeclarations(void) const;
  inline static std::optional<ObjCPropertyDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ObjCPropertyDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ObjCPropertyDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCPropertyDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCPropertyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCPropertyDecl> from(const Decl &parent);

  inline static std::optional<ObjCPropertyDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCPropertyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token at_token(void) const;
  ObjCMethodDecl getter_method_declaration(void) const;
  Token getter_name_token(void) const;
  Token l_paren_token(void) const;
  ObjCPropertyDeclPropertyControl property_implementation(void) const;
  ObjCIvarDecl property_instance_variable_declaration(void) const;
  ObjCPropertyQueryKind query_kind(void) const;
  ObjCPropertyDeclSetterKind setter_kind(void) const;
  ObjCMethodDecl setter_method_declaration(void) const;
  Token setter_name_token(void) const;
  Type type(void) const;
  bool is_atomic(void) const;
  bool is_class_property(void) const;
  bool is_direct_property(void) const;
  bool is_instance_property(void) const;
  bool is_optional(void) const;
  bool is_read_only(void) const;
  bool is_retaining(void) const;
};

static_assert(sizeof(ObjCPropertyDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
