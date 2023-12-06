// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ElaboratedTypeKeyword.h>
#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Token;
class Type;
class TypeWithKeyword;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TypeWithKeyword : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TypeWithKeyword> in(const Index &index);
  static gap::generator<TypeWithKeyword> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeWithKeyword> by_id(const Index &, EntityId);

  static std::optional<TypeWithKeyword> from_base(const Type &parent);
  inline static std::optional<TypeWithKeyword> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<TypeWithKeyword> from(const std::optional<Type> &parent);
  static std::optional<TypeWithKeyword> from(const Reference &r);
  static std::optional<TypeWithKeyword> from(const VariantEntity &e);
  static std::optional<TypeWithKeyword> from(const TokenContext &t);

  ElaboratedTypeKeyword keyword(void) const;
};

static_assert(sizeof(TypeWithKeyword) == sizeof(Type));

#endif
} // namespace mx
