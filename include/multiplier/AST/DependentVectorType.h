// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>
#include <multiplier/AST/VectorTypeVectorKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class DependentVectorType;
class Expr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentVectorType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DependentVectorType> in(const Index &index);
  static gap::generator<DependentVectorType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentVectorType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_VECTOR;
  }

  static std::optional<DependentVectorType> from_base(const Type &parent);
  inline static std::optional<DependentVectorType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DependentVectorType> from(const std::optional<Type> &parent);
  static std::optional<DependentVectorType> from(const Reference &r);
  static std::optional<DependentVectorType> from(const VariantEntity &e);
  static std::optional<DependentVectorType> from(const TokenContext &t);

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