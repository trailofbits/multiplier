// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Type.h"
#include "TypeOfKind.h"

namespace mx {
class EntityProvider;
class Index;
class Token;
class Type;
class TypeOfType;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeOfType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TypeOfType> in(const Index &index);
  static gap::generator<TypeOfType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeOfType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::TYPE_OF;
  }

  static std::optional<TypeOfType> from(const Type &parent);

  inline static std::optional<TypeOfType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TypeOfType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeOfType> from(const Reference &r);
  static std::optional<TypeOfType> from(const TokenContext &t);

  Type desugar(void) const;
  TypeOfKind type_kind(void) const;
  Type unmodified_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(TypeOfType) == sizeof(Type));

#endif
} // namespace mx
