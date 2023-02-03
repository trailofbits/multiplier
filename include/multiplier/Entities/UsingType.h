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

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class Type;
class UsingShadowDecl;
class UsingType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static gap::generator<UsingType> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UsingType> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UsingType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::USING;
  }

  static std::optional<UsingType> from(const TokenContext &c);
  static std::optional<UsingType> from(const Type &parent);

  inline static std::optional<UsingType> from(const std::optional<Type> &parent) {
    if (parent) {
      return UsingType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  UsingShadowDecl found_declaration(void) const;
  Type underlying_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(UsingType) == sizeof(Type));

#endif
} // namespace mx
