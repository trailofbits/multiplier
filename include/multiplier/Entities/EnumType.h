// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TagType.h"

namespace mx {
class EntityProvider;
class Index;
class EnumType;
class TagType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class EnumType : public TagType {
 private:
  friend class FragmentImpl;
  friend class TagType;
  friend class Type;
 public:
  static gap::generator<EnumType> in(const Index &index);
  static gap::generator<EnumType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<EnumType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ENUM;
  }

  static std::optional<EnumType> from(const Type &parent);

  inline static std::optional<EnumType> from(const std::optional<Type> &parent) {
    if (parent) {
      return EnumType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumType> from(const Reference &r);
  static std::optional<EnumType> from(const TokenContext &t);

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(EnumType) == sizeof(TagType));

#endif
} // namespace mx
