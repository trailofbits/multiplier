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

#include "DeclKind.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class UnnamedGlobalConstantDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnnamedGlobalConstantDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<UnnamedGlobalConstantDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UnnamedGlobalConstantDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UnnamedGlobalConstantDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNNAMED_GLOBAL_CONSTANT;
  }

  static gap::generator<UnnamedGlobalConstantDecl> containing(const Decl &decl);
  static gap::generator<UnnamedGlobalConstantDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnnamedGlobalConstantDecl> from(const TokenContext &c);
  static std::optional<UnnamedGlobalConstantDecl> from(const ValueDecl &parent);

  inline static std::optional<UnnamedGlobalConstantDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return UnnamedGlobalConstantDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnnamedGlobalConstantDecl> from(const NamedDecl &parent);

  inline static std::optional<UnnamedGlobalConstantDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UnnamedGlobalConstantDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnnamedGlobalConstantDecl> from(const Decl &parent);

  inline static std::optional<UnnamedGlobalConstantDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnnamedGlobalConstantDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(UnnamedGlobalConstantDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
