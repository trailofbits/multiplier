// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ElaboratedTypeKeyword.h"
#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class DependentNameType;
class DependentTemplateSpecializationType;
class ElaboratedType;
class Token;
class Type;
class TypeWithKeyword;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeWithKeyword : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TypeWithKeyword> in(const Index &index);
  static gap::generator<TypeWithKeyword> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeWithKeyword> by_id(const Index &, EntityId);

  static std::optional<TypeWithKeyword> from(const Type &parent);

  inline static std::optional<TypeWithKeyword> from(const std::optional<Type> &parent) {
    if (parent) {
      return TypeWithKeyword::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeWithKeyword> from(const Reference &r);
  static std::optional<TypeWithKeyword> from(const TokenContext &t);

  ElaboratedTypeKeyword keyword(void) const;
};

static_assert(sizeof(TypeWithKeyword) == sizeof(Type));

#endif
} // namespace mx
