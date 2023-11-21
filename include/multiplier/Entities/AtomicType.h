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
class AtomicType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AtomicType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<AtomicType> in(const Index &index);
  static gap::generator<AtomicType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AtomicType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ATOMIC;
  }

  static std::optional<AtomicType> from_base(const Type &parent);
  inline static std::optional<AtomicType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<AtomicType> from(const std::optional<Type> &parent);
  static std::optional<AtomicType> from(const Reference &r);
  static std::optional<AtomicType> from(const VariantEntity &e);
  static std::optional<AtomicType> from(const TokenContext &t);

  Type desugar(void) const;
  Type value_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(AtomicType) == sizeof(Type));

#endif
} // namespace mx
