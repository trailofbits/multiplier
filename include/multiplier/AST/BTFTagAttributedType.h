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
class BTFTagAttributedType;
class BTFTypeTagAttr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BTFTagAttributedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<BTFTagAttributedType> in(const Index &index);
  static gap::generator<BTFTagAttributedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BTFTagAttributedType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BTF_TAG_ATTRIBUTED;
  }

  static std::optional<BTFTagAttributedType> from_base(const Type &parent);
  inline static std::optional<BTFTagAttributedType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<BTFTagAttributedType> from(const std::optional<Type> &parent);
  static std::optional<BTFTagAttributedType> from(const Reference &r);
  static std::optional<BTFTagAttributedType> from(const VariantEntity &e);
  static std::optional<BTFTagAttributedType> from(const TokenContext &t);

  Type desugar(void) const;
  BTFTypeTagAttr attribute(void) const;
  Type wrapped_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(BTFTagAttributedType) == sizeof(Type));

#endif
} // namespace mx
