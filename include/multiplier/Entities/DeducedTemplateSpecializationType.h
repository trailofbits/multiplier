// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "DeducedType.h"

namespace mx {
class EntityProvider;
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
class DeducedTemplateSpecializationType : public DeducedType {
 private:
  friend class FragmentImpl;
  friend class DeducedType;
  friend class Type;
 public:
  static gap::generator<DeducedTemplateSpecializationType> in(const Fragment &frag);
  static gap::generator<DeducedTemplateSpecializationType> in(const File &file);
  static gap::generator<DeducedTemplateSpecializationType> in(const Index &index);
  static gap::generator<DeducedTemplateSpecializationType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DeducedTemplateSpecializationType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION;
  }

  static std::optional<DeducedTemplateSpecializationType> from(const Type &parent);

  inline static std::optional<DeducedTemplateSpecializationType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DeducedTemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeducedTemplateSpecializationType> from(const Reference &r);
  static std::optional<DeducedTemplateSpecializationType> from(const TokenContext &t);

};

static_assert(sizeof(DeducedTemplateSpecializationType) == sizeof(DeducedType));

#endif
} // namespace mx
