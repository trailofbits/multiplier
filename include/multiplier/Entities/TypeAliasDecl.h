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
#include "TypedefNameDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypeDecl;
class TypedefNameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeAliasDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<TypeAliasDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<TypeAliasDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TypeAliasDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPE_ALIAS;
  }

  static gap::generator<TypeAliasDecl> containing(const Decl &decl);
  static gap::generator<TypeAliasDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypeAliasDecl> from(const TokenContext &c);
  static std::optional<TypeAliasDecl> from(const TypedefNameDecl &parent);

  inline static std::optional<TypeAliasDecl> from(const std::optional<TypedefNameDecl> &parent) {
    if (parent) {
      return TypeAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasDecl> from(const TypeDecl &parent);

  inline static std::optional<TypeAliasDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return TypeAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasDecl> from(const NamedDecl &parent);

  inline static std::optional<TypeAliasDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TypeAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeAliasDecl> from(const Decl &parent);

  inline static std::optional<TypeAliasDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypeAliasDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<TypeAliasTemplateDecl> described_alias_template(void) const;
};

static_assert(sizeof(TypeAliasDecl) == sizeof(TypedefNameDecl));

#endif
} // namespace mx
