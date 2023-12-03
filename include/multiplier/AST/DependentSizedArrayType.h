// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ArrayType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ArrayType;
class DependentSizedArrayType;
class Expr;
class Token;
class TokenRange;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DependentSizedArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  static gap::generator<DependentSizedArrayType> in(const Index &index);
  static gap::generator<DependentSizedArrayType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentSizedArrayType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_SIZED_ARRAY;
  }

  static std::optional<DependentSizedArrayType> from_base(const Type &parent);
  inline static std::optional<DependentSizedArrayType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DependentSizedArrayType> from(const std::optional<Type> &parent);
  static std::optional<DependentSizedArrayType> from(const Reference &r);
  static std::optional<DependentSizedArrayType> from(const VariantEntity &e);
  static std::optional<DependentSizedArrayType> from(const TokenContext &t);

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
