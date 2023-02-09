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

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class TemplateArgument;
class TemplateSpecializationType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateSpecializationType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TemplateSpecializationType> in(const Fragment &frag);
  static gap::generator<TemplateSpecializationType> in(const Index &index);
  static gap::generator<TemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TemplateSpecializationType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TEMPLATE_SPECIALIZATION;
  }

  inline static std::optional<TemplateSpecializationType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<TemplateSpecializationType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<TemplateSpecializationType> from(const Type &parent);

  inline static std::optional<TemplateSpecializationType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  std::optional<Type> aliased_type(void) const;
  bool is_current_instantiation(void) const;
  bool is_sugared(void) const;
  bool is_type_alias(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  gap::generator<TemplateArgument> template_arguments(void) const;
};

static_assert(sizeof(TemplateSpecializationType) == sizeof(Type));

#endif
} // namespace mx
