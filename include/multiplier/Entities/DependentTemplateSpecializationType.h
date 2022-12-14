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
#include "TypeWithKeyword.h"

namespace mx {
class DependentTemplateSpecializationType;
class TemplateArgument;
class Type;
class TypeWithKeyword;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DependentTemplateSpecializationTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentTemplateSpecializationType>;
class DependentTemplateSpecializationType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  inline static gap::generator<DependentTemplateSpecializationType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static DependentTemplateSpecializationTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DependentTemplateSpecializationType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION;
  }

  static std::optional<DependentTemplateSpecializationType> from(const TokenContext &c);
  static std::optional<DependentTemplateSpecializationType> from(const TypeWithKeyword &parent);

  inline static std::optional<DependentTemplateSpecializationType> from(const std::optional<TypeWithKeyword> &parent) {
    if (parent) {
      return DependentTemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentTemplateSpecializationType> from(const Type &parent);

  inline static std::optional<DependentTemplateSpecializationType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentTemplateSpecializationType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
  std::vector<TemplateArgument> template_arguments(void) const;
};

static_assert(sizeof(DependentTemplateSpecializationType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx
