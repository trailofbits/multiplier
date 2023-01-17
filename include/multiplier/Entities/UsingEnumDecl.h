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

#include "BaseUsingDecl.h"
#include "DeclKind.h"

namespace mx {
class BaseUsingDecl;
class Decl;
class EnumDecl;
class NamedDecl;
class UsingEnumDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingEnumDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<UsingEnumDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UsingEnumDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UsingEnumDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_ENUM;
  }

  static gap::generator<UsingEnumDecl> containing(const Decl &decl);
  static gap::generator<UsingEnumDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UsingEnumDecl> from(const TokenContext &c);
  static std::optional<UsingEnumDecl> from(const BaseUsingDecl &parent);

  inline static std::optional<UsingEnumDecl> from(const std::optional<BaseUsingDecl> &parent) {
    if (parent) {
      return UsingEnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingEnumDecl> from(const NamedDecl &parent);

  inline static std::optional<UsingEnumDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UsingEnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingEnumDecl> from(const Decl &parent);

  inline static std::optional<UsingEnumDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingEnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  EnumDecl enum_declaration(void) const;
  Token enum_token(void) const;
  Token using_token(void) const;
};

static_assert(sizeof(UsingEnumDecl) == sizeof(BaseUsingDecl));

#endif
} // namespace mx
