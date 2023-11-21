// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TypeWithKeyword.h"

namespace mx {
class EntityProvider;
class Index;
class DependentNameType;
class Token;
class Type;
class TypeWithKeyword;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentNameType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  static gap::generator<DependentNameType> in(const Index &index);
  static gap::generator<DependentNameType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentNameType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_NAME;
  }

  static std::optional<DependentNameType> from_base(const Type &parent);
  inline static std::optional<DependentNameType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DependentNameType> from(const std::optional<Type> &parent);
  static std::optional<DependentNameType> from(const Reference &r);
  static std::optional<DependentNameType> from(const VariantEntity &e);
  static std::optional<DependentNameType> from(const TokenContext &t);

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentNameType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx
