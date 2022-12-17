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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Type.h"
#include "TypeKind.h"
#include "TypeUseSelector.h"

namespace mx {
class TemplateArgument;
class TemplateSpecializationType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TemplateSpecializationTypeRange = DerivedEntityRange<TypeIterator, TemplateSpecializationType>;
using TemplateSpecializationTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateSpecializationType>;
class TemplateSpecializationType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static TemplateSpecializationTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TemplateSpecializationTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : TemplateSpecializationType::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TEMPLATE_SPECIALIZATION;
  }

  static std::optional<TemplateSpecializationType> from(const TokenContext &c);
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
  std::vector<TemplateArgument> template_arguments(void) const;
};

static_assert(sizeof(TemplateSpecializationType) == sizeof(Type));

#endif
} // namespace mx
