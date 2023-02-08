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

#include "Type.h"
#include "TypeKind.h"
#include "VectorTypeVectorKind.h"

namespace mx {
class DependentVectorType;
class Expr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentVectorType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DependentVectorType> in(const Fragment &frag);
  static gap::generator<DependentVectorType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_VECTOR;
  }

  static gap::generator<TypeKind> derived_kinds(void);
  inline static std::optional<DependentVectorType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<DependentVectorType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<DependentVectorType> from(const Type &parent);

  inline static std::optional<DependentVectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentVectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Token attribute_token(void) const;
  Type element_type(void) const;
  Expr size_expression(void) const;
  VectorTypeVectorKind vector_kind(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentVectorType) == sizeof(Type));

#endif
} // namespace mx
