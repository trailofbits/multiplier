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
class DependentAddressSpaceType;
class Expr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DependentAddressSpaceType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DependentAddressSpaceType> in(const Index &index);
  static gap::generator<DependentAddressSpaceType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentAddressSpaceType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_ADDRESS_SPACE;
  }

  static std::optional<DependentAddressSpaceType> from_base(const Type &parent);
  inline static std::optional<DependentAddressSpaceType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DependentAddressSpaceType> from(const std::optional<Type> &parent);
  static std::optional<DependentAddressSpaceType> from(const Reference &r);
  static std::optional<DependentAddressSpaceType> from(const VariantEntity &e);
  static std::optional<DependentAddressSpaceType> from(const TokenContext &t);

  Type desugar(void) const;
  Expr address_space_expression(void) const;
  Token attribute_token(void) const;
  Type pointee_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentAddressSpaceType) == sizeof(Type));

#endif
} // namespace mx
