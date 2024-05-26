// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ReferenceType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class LValueReferenceType;
class ReferenceType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT LValueReferenceType : public ReferenceType {
 private:
  friend class FragmentImpl;
  friend class ReferenceType;
  friend class Type;
 public:
  static gap::generator<LValueReferenceType> in(const Index &index);
  static gap::generator<LValueReferenceType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::L_VALUE_REFERENCE;
  }

  static std::optional<LValueReferenceType> by_id(const Index &, EntityId);

  static std::optional<LValueReferenceType> from_base(const Type &parent);
  inline static std::optional<LValueReferenceType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<LValueReferenceType> from(const std::optional<Type> &parent);
  static std::optional<LValueReferenceType> from(const Reference &r);
  static std::optional<LValueReferenceType> from(const VariantEntity &e);
  static std::optional<LValueReferenceType> from(const TokenContext &t);

  bool is_sugared(void) const;
};

static_assert(sizeof(LValueReferenceType) == sizeof(ReferenceType));

#endif
} // namespace mx
