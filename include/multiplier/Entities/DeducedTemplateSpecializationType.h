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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
  static gap::generator<DeducedTemplateSpecializationType> in(const Fragment &frag);
  static gap::generator<DeducedTemplateSpecializationType> in(const Index &index);
  static gap::generator<DeducedTemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<DeducedTemplateSpecializationType> by(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION;
  }

  inline static std::optional<DeducedTemplateSpecializationType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<DeducedTemplateSpecializationType> from(const TokenContext &t) {
    return from(t.as_type());
  }

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
