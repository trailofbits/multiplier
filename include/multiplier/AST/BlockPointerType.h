// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class BlockPointerType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BlockPointerType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<BlockPointerType> in(const Index &index);
  static gap::generator<BlockPointerType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BLOCK_POINTER;
  }

  static std::optional<BlockPointerType> by_id(const Index &, EntityId);

  static std::optional<BlockPointerType> from_base(const Type &parent);
  inline static std::optional<BlockPointerType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<BlockPointerType> from(const std::optional<Type> &parent);
  static std::optional<BlockPointerType> from(const Reference &r);
  static std::optional<BlockPointerType> from(const VariantEntity &e);
  static std::optional<BlockPointerType> from(const TokenContext &t);

  Type pointee_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(BlockPointerType) == sizeof(Type));

#endif
} // namespace mx
