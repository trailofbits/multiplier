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
#include "DeclaratorDecl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class MSPropertyDecl;
class NamedDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSPropertyDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<MSPropertyDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<MSPropertyDecl> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : MSPropertyDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::MS_PROPERTY;
  }

  static gap::generator<MSPropertyDecl> containing(const Decl &decl);
  static gap::generator<MSPropertyDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSPropertyDecl> from(const TokenContext &c);
  static std::optional<MSPropertyDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<MSPropertyDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return MSPropertyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSPropertyDecl> from(const ValueDecl &parent);

  inline static std::optional<MSPropertyDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return MSPropertyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSPropertyDecl> from(const NamedDecl &parent);

  inline static std::optional<MSPropertyDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return MSPropertyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSPropertyDecl> from(const Decl &parent);

  inline static std::optional<MSPropertyDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return MSPropertyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool has_getter(void) const;
  bool has_setter(void) const;
};

static_assert(sizeof(MSPropertyDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
