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
class ParenType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ParenType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ParenType> in(const Index &index);
  static gap::generator<ParenType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ParenType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::PAREN;
  }

  static std::optional<ParenType> from(const Type &parent);

  inline static std::optional<ParenType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ParenType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ParenType> from(const Reference &r);
  static std::optional<ParenType> from(const TokenContext &t);

  Type desugar(void) const;
  Type inner_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ParenType) == sizeof(Type));

#endif
} // namespace mx
