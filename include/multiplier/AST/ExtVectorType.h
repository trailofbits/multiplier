// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/VectorType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ExtVectorType;
class Token;
class Type;
class VectorType;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ExtVectorType : public VectorType {
 private:
  friend class FragmentImpl;
  friend class VectorType;
  friend class Type;
 public:
  static gap::generator<ExtVectorType> in(const Index &index);
  static gap::generator<ExtVectorType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::EXT_VECTOR;
  }

  static std::optional<ExtVectorType> by_id(const Index &, EntityId);

  static std::optional<ExtVectorType> from_base(const Type &parent);
  inline static std::optional<ExtVectorType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<ExtVectorType> from(const std::optional<Type> &parent);
  static std::optional<ExtVectorType> from(const Reference &r);
  static std::optional<ExtVectorType> from(const VariantEntity &e);
  static std::optional<ExtVectorType> from(const TokenContext &t);

};

static_assert(sizeof(ExtVectorType) == sizeof(VectorType));

#endif
} // namespace mx
