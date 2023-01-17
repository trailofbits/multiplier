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

#include "TypeKind.h"
#include "VectorType.h"

namespace mx {
class ExtVectorType;
class Type;
class VectorType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExtVectorType : public VectorType {
 private:
  friend class FragmentImpl;
  friend class VectorType;
  friend class Type;
 public:
  inline static gap::generator<ExtVectorType> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ExtVectorType> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ExtVectorType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::EXT_VECTOR;
  }

  static std::optional<ExtVectorType> from(const TokenContext &c);
  static std::optional<ExtVectorType> from(const VectorType &parent);

  inline static std::optional<ExtVectorType> from(const std::optional<VectorType> &parent) {
    if (parent) {
      return ExtVectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorType> from(const Type &parent);

  inline static std::optional<ExtVectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ExtVectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ExtVectorType) == sizeof(VectorType));

#endif
} // namespace mx
