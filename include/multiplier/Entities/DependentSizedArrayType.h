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

#include "ArrayType.h"
#include "TypeKind.h"

namespace mx {
class ArrayType;
class DependentSizedArrayType;
class Expr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentSizedArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  inline static gap::generator<DependentSizedArrayType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DependentSizedArrayType> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DependentSizedArrayType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_SIZED_ARRAY;
  }

  static std::optional<DependentSizedArrayType> from(const TokenContext &c);
  static std::optional<DependentSizedArrayType> from(const ArrayType &parent);

  inline static std::optional<DependentSizedArrayType> from(const std::optional<ArrayType> &parent) {
    if (parent) {
      return DependentSizedArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentSizedArrayType> from(const Type &parent);

  inline static std::optional<DependentSizedArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentSizedArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  TokenRange brackets_range(void) const;
  Token l_bracket_token(void) const;
  Token r_bracket_token(void) const;
  Expr size_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentSizedArrayType) == sizeof(ArrayType));

#endif
} // namespace mx
