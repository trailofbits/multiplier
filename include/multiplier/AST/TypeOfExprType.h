// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>
#include <multiplier/AST/TypeOfKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Expr;
class Token;
class Type;
class TypeOfExprType;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TypeOfExprType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TypeOfExprType> in(const Index &index);
  static gap::generator<TypeOfExprType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeOfExprType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TYPE_OF_EXPR;
  }

  static std::optional<TypeOfExprType> from_base(const Type &parent);
  inline static std::optional<TypeOfExprType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<TypeOfExprType> from(const std::optional<Type> &parent);
  static std::optional<TypeOfExprType> from(const Reference &r);
  static std::optional<TypeOfExprType> from(const VariantEntity &e);
  static std::optional<TypeOfExprType> from(const TokenContext &t);

  Type desugar(void) const;
  TypeOfKind type_kind(void) const;
  Expr underlying_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TypeOfExprType) == sizeof(Type));

#endif
} // namespace mx
