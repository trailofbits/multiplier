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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AutoTypeKeyword.h"
#include "DeducedType.h"
#include "TypeKind.h"

namespace mx {
class AutoType;
class ConceptDecl;
class DeducedType;
class TemplateArgument;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AutoType : public DeducedType {
 private:
  friend class FragmentImpl;
  friend class DeducedType;
  friend class Type;
 public:
  static gap::generator<AutoType> in(const Fragment &frag);
  static gap::generator<AutoType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::AUTO;
  }

  inline static std::optional<AutoType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<AutoType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<AutoType> from(const DeducedType &parent);

  inline static std::optional<AutoType> from(const std::optional<DeducedType> &parent) {
    if (parent) {
      return AutoType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AutoType> from(const Type &parent);

  inline static std::optional<AutoType> from(const std::optional<Type> &parent) {
    if (parent) {
      return AutoType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  AutoTypeKeyword keyword(void) const;
  std::optional<TemplateArgument> nth_type_constraint_argument(unsigned n) const;
  gap::generator<TemplateArgument> type_constraint_arguments(void) const;
  std::optional<ConceptDecl> type_constraint_concept(void) const;
  bool is_constrained(void) const;
  bool is_decltype_auto(void) const;
  bool is_gnu_auto_type(void) const;
};

static_assert(sizeof(AutoType) == sizeof(DeducedType));

#endif
} // namespace mx
