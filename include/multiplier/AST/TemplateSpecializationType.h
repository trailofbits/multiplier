// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
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
class MX_EXPORT TemplateSpecializationType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TemplateSpecializationType> in(const Index &index);
  static gap::generator<TemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TEMPLATE_SPECIALIZATION;
  }

  static std::optional<TemplateSpecializationType> by_id(const Index &, EntityId);

  static std::optional<TemplateSpecializationType> from_base(const Type &parent);
  inline static std::optional<TemplateSpecializationType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<TemplateSpecializationType> from(const std::optional<Type> &parent);
  static std::optional<TemplateSpecializationType> from(const Reference &r);
  static std::optional<TemplateSpecializationType> from(const VariantEntity &e);
  static std::optional<TemplateSpecializationType> from(const TokenContext &t);

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
