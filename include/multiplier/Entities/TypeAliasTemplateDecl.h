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
#include "RedeclarableTemplateDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
class TypeAliasTemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeAliasTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypeAliasTemplateDecl> in(const Fragment &frag);
  static gap::generator<TypeAliasTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPE_ALIAS_TEMPLATE;
  }

  static gap::generator<TypeAliasTemplateDecl> containing(const Decl &decl);
  static gap::generator<TypeAliasTemplateDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<TypeAliasTemplateDecl> redeclarations(void) const;
  inline static std::optional<TypeAliasTemplateDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<TypeAliasTemplateDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<TypeAliasTemplateDecl> from(const RedeclarableTemplateDecl &parent);

  inline static std::optional<TypeAliasTemplateDecl> from(const std::optional<RedeclarableTemplateDecl> &parent) {
    if (parent) {
      return TypeAliasTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<TypeAliasTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return TypeAliasTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<TypeAliasTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TypeAliasTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasTemplateDecl> from(const Decl &parent);

  inline static std::optional<TypeAliasTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypeAliasTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(TypeAliasTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
