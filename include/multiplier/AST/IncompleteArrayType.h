// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ArrayType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ArrayType;
class IncompleteArrayType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncompleteArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  static gap::generator<IncompleteArrayType> in(const Index &index);
  static gap::generator<IncompleteArrayType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<IncompleteArrayType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::INCOMPLETE_ARRAY;
  }

  static std::optional<IncompleteArrayType> from_base(const Type &parent);
  inline static std::optional<IncompleteArrayType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<IncompleteArrayType> from(const std::optional<Type> &parent);
  static std::optional<IncompleteArrayType> from(const Reference &r);
  static std::optional<IncompleteArrayType> from(const VariantEntity &e);
  static std::optional<IncompleteArrayType> from(const TokenContext &t);

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(IncompleteArrayType) == sizeof(ArrayType));

#endif
} // namespace mx
