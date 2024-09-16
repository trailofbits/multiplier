// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Token;
class Type;
class UsingShadowDecl;
class UsingType;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UsingType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<UsingType> in(const Index &index);
  static gap::generator<UsingType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::USING;
  }

  static std::optional<UsingType> by_id(const Index &, EntityId);

  static std::optional<UsingType> from_base(const Type &parent);
  inline static std::optional<UsingType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<UsingType> from(const std::optional<Type> &parent);
  static std::optional<UsingType> from(const Reference &r);
  static std::optional<UsingType> from(const VariantEntity &e);
  static std::optional<UsingType> from(const TokenContext &t);

  UsingShadowDecl found_declaration(void) const;
  Type underlying_type(void) const;
  bool is_sugared(void) const;
  bool type_matches_declaration(void) const;
};

static_assert(sizeof(UsingType) == sizeof(Type));

#endif
} // namespace mx
