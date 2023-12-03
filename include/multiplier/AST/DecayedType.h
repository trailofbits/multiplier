// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/AdjustedType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AdjustedType;
class DecayedType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DecayedType : public AdjustedType {
 private:
  friend class FragmentImpl;
  friend class AdjustedType;
  friend class Type;
 public:
  static gap::generator<DecayedType> in(const Index &index);
  static gap::generator<DecayedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DecayedType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DECAYED;
  }

  static std::optional<DecayedType> from_base(const Type &parent);
  inline static std::optional<DecayedType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DecayedType> from(const std::optional<Type> &parent);
  static std::optional<DecayedType> from(const Reference &r);
  static std::optional<DecayedType> from(const VariantEntity &e);
  static std::optional<DecayedType> from(const TokenContext &t);

  Type pointee_type(void) const;
};

static_assert(sizeof(DecayedType) == sizeof(AdjustedType));

#endif
} // namespace mx
