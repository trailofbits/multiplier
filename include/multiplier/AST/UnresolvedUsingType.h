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
class UnresolvedUsingType;
class UnresolvedUsingTypenameDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UnresolvedUsingType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<UnresolvedUsingType> in(const Index &index);
  static gap::generator<UnresolvedUsingType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::UNRESOLVED_USING;
  }

  static std::optional<UnresolvedUsingType> by_id(const Index &, EntityId);

  static std::optional<UnresolvedUsingType> from_base(const Type &parent);
  inline static std::optional<UnresolvedUsingType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<UnresolvedUsingType> from(const std::optional<Type> &parent);
  static std::optional<UnresolvedUsingType> from(const Reference &r);
  static std::optional<UnresolvedUsingType> from(const VariantEntity &e);
  static std::optional<UnresolvedUsingType> from(const TokenContext &t);

  UnresolvedUsingTypenameDecl declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(UnresolvedUsingType) == sizeof(Type));

#endif
} // namespace mx
