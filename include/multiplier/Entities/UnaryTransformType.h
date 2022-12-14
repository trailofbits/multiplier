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

#include "Type.h"
#include "TypeKind.h"
#include "UnaryTransformTypeUTTKind.h"

namespace mx {
class Type;
class UnaryTransformType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnaryTransformType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static gap::generator<UnaryTransformType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UnaryTransformType> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : UnaryTransformType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::UNARY_TRANSFORM;
  }

  static std::optional<UnaryTransformType> from(const TokenContext &c);
  static std::optional<UnaryTransformType> from(const Type &parent);

  inline static std::optional<UnaryTransformType> from(const std::optional<Type> &parent) {
    if (parent) {
      return UnaryTransformType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type base_type(void) const;
  UnaryTransformTypeUTTKind utt_kind(void) const;
  Type underlying_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(UnaryTransformType) == sizeof(Type));

#endif
} // namespace mx
