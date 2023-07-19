// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "AttrKind.h"
#include "NullabilityKind.h"
#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class AttributedType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AttributedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<AttributedType> in(const Index &index);
  static gap::generator<AttributedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AttributedType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ATTRIBUTED;
  }

  static std::optional<AttributedType> from(const Type &parent);

  inline static std::optional<AttributedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return AttributedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AttributedType> from(const Reference &r);
  static std::optional<AttributedType> from(const TokenContext &t);

  Type desugar(void) const;
  AttrKind attribute_kind(void) const;
  Type equivalent_type(void) const;
  std::optional<NullabilityKind> immediate_nullability(void) const;
  Type modified_type(void) const;
  bool is_calling_conv(void) const;
  bool is_ms_type_spec(void) const;
  bool is_qualifier(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(AttributedType) == sizeof(Type));

#endif
} // namespace mx
