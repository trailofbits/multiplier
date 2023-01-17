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

#include "DeducedType.h"
#include "TypeKind.h"

namespace mx {
class DeducedTemplateSpecializationType;
class DeducedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeducedTemplateSpecializationType : public DeducedType {
 private:
  friend class FragmentImpl;
  friend class DeducedType;
  friend class Type;
 public:
  inline static gap::generator<DeducedTemplateSpecializationType> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DeducedTemplateSpecializationType> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DeducedTemplateSpecializationType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION;
  }

  static std::optional<DeducedTemplateSpecializationType> from(const TokenContext &c);
  static std::optional<DeducedTemplateSpecializationType> from(const DeducedType &parent);

  inline static std::optional<DeducedTemplateSpecializationType> from(const std::optional<DeducedType> &parent) {
    if (parent) {
      return DeducedTemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeducedTemplateSpecializationType> from(const Type &parent);

  inline static std::optional<DeducedTemplateSpecializationType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DeducedTemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(DeducedTemplateSpecializationType) == sizeof(DeducedType));

#endif
} // namespace mx
