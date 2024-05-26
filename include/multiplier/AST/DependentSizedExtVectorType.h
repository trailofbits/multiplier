// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class DependentSizedExtVectorType;
class Expr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DependentSizedExtVectorType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DependentSizedExtVectorType> in(const Index &index);
  static gap::generator<DependentSizedExtVectorType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_SIZED_EXT_VECTOR;
  }

  static std::optional<DependentSizedExtVectorType> by_id(const Index &, EntityId);

  static std::optional<DependentSizedExtVectorType> from_base(const Type &parent);
  inline static std::optional<DependentSizedExtVectorType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DependentSizedExtVectorType> from(const std::optional<Type> &parent);
  static std::optional<DependentSizedExtVectorType> from(const Reference &r);
  static std::optional<DependentSizedExtVectorType> from(const VariantEntity &e);
  static std::optional<DependentSizedExtVectorType> from(const TokenContext &t);

  Token attribute_token(void) const;
  Type element_type(void) const;
  Expr size_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentSizedExtVectorType) == sizeof(Type));

#endif
} // namespace mx
