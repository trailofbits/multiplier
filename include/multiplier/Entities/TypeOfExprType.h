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

namespace mx {
class Expr;
class Type;
class TypeOfExprType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeOfExprType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TypeOfExprType> in(const Fragment &frag);
  static gap::generator<TypeOfExprType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TYPE_OF_EXPR;
  }

  inline static std::optional<TypeOfExprType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<TypeOfExprType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<TypeOfExprType> from(const Type &parent);

  inline static std::optional<TypeOfExprType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TypeOfExprType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Expr underlying_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TypeOfExprType) == sizeof(Type));

#endif
} // namespace mx
