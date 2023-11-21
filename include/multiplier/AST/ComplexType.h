// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class ComplexType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ComplexType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ComplexType> in(const Index &index);
  static gap::generator<ComplexType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ComplexType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::COMPLEX;
  }

  static std::optional<ComplexType> from_base(const Type &parent);
  inline static std::optional<ComplexType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<ComplexType> from(const std::optional<Type> &parent);
  static std::optional<ComplexType> from(const Reference &r);
  static std::optional<ComplexType> from(const VariantEntity &e);
  static std::optional<ComplexType> from(const TokenContext &t);

  Type desugar(void) const;
  Type element_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ComplexType) == sizeof(Type));

#endif
} // namespace mx
