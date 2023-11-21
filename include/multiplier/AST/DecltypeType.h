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
class DecltypeType;
class Expr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DecltypeType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DecltypeType> in(const Index &index);
  static gap::generator<DecltypeType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DecltypeType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DECLTYPE;
  }

  static std::optional<DecltypeType> from_base(const Type &parent);
  inline static std::optional<DecltypeType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DecltypeType> from(const std::optional<Type> &parent);
  static std::optional<DecltypeType> from(const Reference &r);
  static std::optional<DecltypeType> from(const VariantEntity &e);
  static std::optional<DecltypeType> from(const TokenContext &t);

  Type desugar(void) const;
  Expr underlying_expression(void) const;
  Type underlying_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DecltypeType) == sizeof(Type));

#endif
} // namespace mx
