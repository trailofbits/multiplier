// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeWithKeyword.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class DependentTemplateSpecializationType;
class TemplateArgument;
class Token;
class Type;
class TypeWithKeyword;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DependentTemplateSpecializationType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  static gap::generator<DependentTemplateSpecializationType> in(const Index &index);
  static gap::generator<DependentTemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION;
  }

  static std::optional<DependentTemplateSpecializationType> by_id(const Index &, EntityId);

  static std::optional<DependentTemplateSpecializationType> from_base(const Type &parent);
  inline static std::optional<DependentTemplateSpecializationType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DependentTemplateSpecializationType> from(const std::optional<Type> &parent);
  static std::optional<DependentTemplateSpecializationType> from(const Reference &r);
  static std::optional<DependentTemplateSpecializationType> from(const VariantEntity &e);
  static std::optional<DependentTemplateSpecializationType> from(const TokenContext &t);

  bool is_sugared(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  unsigned num_template_arguments(void) const;
  gap::generator<TemplateArgument> template_arguments(void) const &;
};

static_assert(sizeof(DependentTemplateSpecializationType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx
