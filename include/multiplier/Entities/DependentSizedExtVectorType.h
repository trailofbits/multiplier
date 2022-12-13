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

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class DependentSizedExtVectorType;
class Expr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DependentSizedExtVectorTypeRange = DerivedEntityRange<TypeIterator, DependentSizedExtVectorType>;
using DependentSizedExtVectorTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentSizedExtVectorType>;
class DependentSizedExtVectorType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static DependentSizedExtVectorTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentSizedExtVectorTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DependentSizedExtVectorType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_SIZED_EXT_VECTOR;
  }

  static std::optional<DependentSizedExtVectorType> from(const TokenContext &c);
  static std::optional<DependentSizedExtVectorType> from(const Type &parent);

  inline static std::optional<DependentSizedExtVectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentSizedExtVectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Token attribute_token(void) const;
  Type element_type(void) const;
  Expr size_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentSizedExtVectorType) == sizeof(Type));

#endif
} // namespace mx
