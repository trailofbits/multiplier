// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeWithKeyword.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ElaboratedType;
class TagDecl;
class Token;
class Type;
class TypeWithKeyword;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ElaboratedType : public TypeWithKeyword {
 private:
  friend class FragmentImpl;
  friend class TypeWithKeyword;
  friend class Type;
 public:
  static gap::generator<ElaboratedType> in(const Index &index);
  static gap::generator<ElaboratedType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ELABORATED;
  }

  static std::optional<ElaboratedType> by_id(const Index &, EntityId);

  static std::optional<ElaboratedType> from_base(const Type &parent);
  inline static std::optional<ElaboratedType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<ElaboratedType> from(const std::optional<Type> &parent);
  static std::optional<ElaboratedType> from(const Reference &r);
  static std::optional<ElaboratedType> from(const VariantEntity &e);
  static std::optional<ElaboratedType> from(const TokenContext &t);

  Type named_type(void) const;
  std::optional<TagDecl> owned_tag_declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ElaboratedType) == sizeof(TypeWithKeyword));

#endif
} // namespace mx
