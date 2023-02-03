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

#include "TagType.h"
#include "TypeKind.h"

namespace mx {
class EnumType;
class TagType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class EnumType : public TagType {
 private:
  friend class FragmentImpl;
  friend class TagType;
  friend class Type;
 public:
  inline static gap::generator<EnumType> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<EnumType> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : EnumType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ENUM;
  }

  static std::optional<EnumType> from(const TokenContext &c);
  static std::optional<EnumType> from(const TagType &parent);

  inline static std::optional<EnumType> from(const std::optional<TagType> &parent) {
    if (parent) {
      return EnumType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumType> from(const Type &parent);

  inline static std::optional<EnumType> from(const std::optional<Type> &parent) {
    if (parent) {
      return EnumType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(EnumType) == sizeof(TagType));

#endif
} // namespace mx
