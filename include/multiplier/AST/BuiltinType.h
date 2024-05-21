// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/BuiltinTypeKind.h>
#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class BuiltinType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BuiltinType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<BuiltinType> in(const Index &index);
  static gap::generator<BuiltinType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BuiltinType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN;
  }

  static std::optional<BuiltinType> from_base(const Type &parent);
  inline static std::optional<BuiltinType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<BuiltinType> from(const std::optional<Type> &parent);
  static std::optional<BuiltinType> from(const Reference &r);
  static std::optional<BuiltinType> from(const VariantEntity &e);
  static std::optional<BuiltinType> from(const TokenContext &t);

  BuiltinTypeKind builtin_kind(void) const;
  bool is_floating_point(void) const;
  bool is_integer(void) const;
  bool is_sve_bool(void) const;
  bool is_sve_count(void) const;
  bool is_signed_integer(void) const;
  bool is_sugared(void) const;
  bool is_unsigned_integer(void) const;
};

static_assert(sizeof(BuiltinType) == sizeof(Type));

#endif
} // namespace mx
