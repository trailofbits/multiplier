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
class NamedDecl;
class UsingDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<UsingDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UsingDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UsingDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING;
  }

  static gap::generator<UsingDecl> containing(const Decl &decl);
  static gap::generator<UsingDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UsingDecl> from(const TokenContext &c);
  static std::optional<UsingDecl> from(const BaseUsingDecl &parent);

  inline static std::optional<UsingDecl> from(const std::optional<BaseUsingDecl> &parent) {
    if (parent) {
      return UsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingDecl> from(const NamedDecl &parent);

  inline static std::optional<UsingDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingDecl> from(const Decl &parent);

  inline static std::optional<UsingDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token using_token(void) const;
  bool has_typename(void) const;
  bool is_access_declaration(void) const;
};

static_assert(sizeof(UsingDecl) == sizeof(BaseUsingDecl));

#endif
} // namespace mx
