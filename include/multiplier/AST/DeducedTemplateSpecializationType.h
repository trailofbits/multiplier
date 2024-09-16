// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeducedType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class DeducedTemplateSpecializationType;
class DeducedType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DeducedTemplateSpecializationType : public DeducedType {
 private:
  friend class FragmentImpl;
  friend class DeducedType;
  friend class Type;
 public:
  static gap::generator<DeducedTemplateSpecializationType> in(const Index &index);
  static gap::generator<DeducedTemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION;
  }

  static std::optional<DeducedTemplateSpecializationType> by_id(const Index &, EntityId);

  static std::optional<DeducedTemplateSpecializationType> from_base(const Type &parent);
  inline static std::optional<DeducedTemplateSpecializationType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DeducedTemplateSpecializationType> from(const std::optional<Type> &parent);
  static std::optional<DeducedTemplateSpecializationType> from(const Reference &r);
  static std::optional<DeducedTemplateSpecializationType> from(const VariantEntity &e);
  static std::optional<DeducedTemplateSpecializationType> from(const TokenContext &t);

};

static_assert(sizeof(DeducedTemplateSpecializationType) == sizeof(DeducedType));

#endif
} // namespace mx
