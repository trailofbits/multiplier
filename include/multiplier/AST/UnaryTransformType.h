// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>
#include <multiplier/AST/UnaryTransformTypeUTTKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Token;
class Type;
class UnaryTransformType;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UnaryTransformType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<UnaryTransformType> in(const Index &index);
  static gap::generator<UnaryTransformType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnaryTransformType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::UNARY_TRANSFORM;
  }

  static std::optional<UnaryTransformType> from_base(const Type &parent);
  inline static std::optional<UnaryTransformType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<UnaryTransformType> from(const std::optional<Type> &parent);
  static std::optional<UnaryTransformType> from(const Reference &r);
  static std::optional<UnaryTransformType> from(const VariantEntity &e);
  static std::optional<UnaryTransformType> from(const TokenContext &t);

  std::optional<Type> desugar(void) const;
  std::optional<Type> base_type(void) const;
  UnaryTransformTypeUTTKind utt_kind(void) const;
  std::optional<Type> underlying_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(UnaryTransformType) == sizeof(Type));

#endif
} // namespace mx
