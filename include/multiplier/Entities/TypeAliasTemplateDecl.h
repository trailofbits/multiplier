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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "DeclUseSelector.h"
#include "RedeclarableTemplateDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
class TypeAliasDecl;
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
  inline static gap::generator<TypeAliasTemplateDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<TypeAliasTemplateDecl> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TypeAliasTemplateDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPE_ALIAS_TEMPLATE;
  }

  static gap::generator<TypeAliasTemplateDecl> containing(const Decl &decl);
  static gap::generator<TypeAliasTemplateDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypeAliasTemplateDecl> from(const TokenContext &c);
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

  std::optional<TypeAliasTemplateDecl> instantiated_from_member_template(void) const;
  TypeAliasDecl templated_declaration(void) const;
};

static_assert(sizeof(TypeAliasTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
