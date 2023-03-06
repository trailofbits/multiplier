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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "ObjCImplDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCImplementationDecl : public ObjCImplDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCImplDecl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCImplementationDecl> in(const Fragment &frag);
  static gap::generator<ObjCImplementationDecl> in(const File &file);
  static gap::generator<ObjCImplementationDecl> in(const Index &index);
  static gap::generator<ObjCImplementationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCImplementationDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_IMPLEMENTATION;
  }

  static gap::generator<ObjCImplementationDecl> containing(const Decl &decl);
  static gap::generator<ObjCImplementationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCImplementationDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCImplementationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCImplementationDecl> redeclarations(void) const &;
  static std::optional<ObjCImplementationDecl> from(const Decl &parent);

  inline static std::optional<ObjCImplementationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCImplementationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCImplementationDecl> from(const Reference &r) {
    return ObjCImplementationDecl::from(r.as_declaration());
  }

  inline static std::optional<ObjCImplementationDecl> from(const TokenContext &t) {
    return ObjCImplementationDecl::from(t.as_declaration());
  }

  Token instance_variable_l_brace_token(void) const;
  Token instance_variable_r_brace_token(void) const;
  std::string_view obj_c_runtime_name_as_string(void) const;
  ObjCInterfaceDecl super_class(void) const;
  Token super_class_token(void) const;
  bool has_destructors(void) const;
  bool has_non_zero_constructors(void) const;
  std::optional<ObjCIvarDecl> nth_instance_variable(unsigned n) const;
  gap::generator<ObjCIvarDecl> instance_variables(void) const &;
};

static_assert(sizeof(ObjCImplementationDecl) == sizeof(ObjCImplDecl));

#endif
} // namespace mx
