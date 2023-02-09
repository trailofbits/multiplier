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

#include "DeclKind.h"
#include "TypeDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TemplateTypeParmDecl;
class Type;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateTypeParmDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TemplateTypeParmDecl> in(const Fragment &frag);
  static gap::generator<TemplateTypeParmDecl> in(const Index &index);
  static gap::generator<TemplateTypeParmDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TemplateTypeParmDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TEMPLATE_TYPE_PARM;
  }

  static gap::generator<TemplateTypeParmDecl> containing(const Decl &decl);
  static gap::generator<TemplateTypeParmDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TemplateTypeParmDecl> containing(const Stmt &stmt);
  static gap::generator<TemplateTypeParmDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<TemplateTypeParmDecl> redeclarations(void) const;
  inline static std::optional<TemplateTypeParmDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<TemplateTypeParmDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<TemplateTypeParmDecl> from(const TypeDecl &parent);

  inline static std::optional<TemplateTypeParmDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return TemplateTypeParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateTypeParmDecl> from(const NamedDecl &parent);

  inline static std::optional<TemplateTypeParmDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TemplateTypeParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateTypeParmDecl> from(const Decl &parent);

  inline static std::optional<TemplateTypeParmDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateTypeParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool default_argument_was_inherited(void) const;
  std::optional<Type> default_argument(void) const;
  std::optional<Type> default_argument_info(void) const;
  Token default_argument_token(void) const;
  bool has_default_argument(void) const;
  bool has_type_constraint(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  bool was_declared_with_typename(void) const;
};

static_assert(sizeof(TemplateTypeParmDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
