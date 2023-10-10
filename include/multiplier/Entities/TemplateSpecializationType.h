// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class TemplateArgument;
class TemplateSpecializationType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateSpecializationType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TemplateSpecializationType> in(const Index &index);
  static gap::generator<TemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TemplateSpecializationType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TEMPLATE_SPECIALIZATION;
  }

  static std::optional<TemplateSpecializationType> from(const Type &parent);

  inline static std::optional<TemplateSpecializationType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateSpecializationType> from(const Reference &r);
  static std::optional<TemplateSpecializationType> from(const TokenContext &t);

  Type desugar(void) const;
  std::optional<Type> aliased_type(void) const;
  bool is_current_instantiation(void) const;
  bool is_sugared(void) const;
  bool is_type_alias(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  unsigned num_template_arguments(void) const;
  gap::generator<TemplateArgument> template_arguments(void) const &;
};

static_assert(sizeof(TemplateSpecializationType) == sizeof(Type));

#endif
} // namespace mx
