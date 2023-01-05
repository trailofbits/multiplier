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

#include "ReferenceType.h"
#include "TypeKind.h"

namespace mx {
class RValueReferenceType;
class ReferenceType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RValueReferenceType : public ReferenceType {
 private:
  friend class FragmentImpl;
  friend class ReferenceType;
  friend class Type;
 public:
  inline static gap::generator<RValueReferenceType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<RValueReferenceType> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : RValueReferenceType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::R_VALUE_REFERENCE;
  }

  static std::optional<RValueReferenceType> from(const TokenContext &c);
  static std::optional<RValueReferenceType> from(const ReferenceType &parent);

  inline static std::optional<RValueReferenceType> from(const std::optional<ReferenceType> &parent) {
    if (parent) {
      return RValueReferenceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RValueReferenceType> from(const Type &parent);

  inline static std::optional<RValueReferenceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return RValueReferenceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(RValueReferenceType) == sizeof(ReferenceType));

#endif
} // namespace mx
