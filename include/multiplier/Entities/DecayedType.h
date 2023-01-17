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

#include "AdjustedType.h"
#include "TypeKind.h"

namespace mx {
class AdjustedType;
class DecayedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DecayedType : public AdjustedType {
 private:
  friend class FragmentImpl;
  friend class AdjustedType;
  friend class Type;
 public:
  inline static gap::generator<DecayedType> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DecayedType> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DecayedType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DECAYED;
  }

  static std::optional<DecayedType> from(const TokenContext &c);
  static std::optional<DecayedType> from(const AdjustedType &parent);

  inline static std::optional<DecayedType> from(const std::optional<AdjustedType> &parent) {
    if (parent) {
      return DecayedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DecayedType> from(const Type &parent);

  inline static std::optional<DecayedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DecayedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(DecayedType) == sizeof(AdjustedType));

#endif
} // namespace mx
