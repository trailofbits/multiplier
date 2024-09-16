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
class ReferenceType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ReferenceType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ReferenceType> in(const Index &index);
  static gap::generator<ReferenceType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ReferenceType> by_id(const Index &, EntityId);

  static std::optional<ReferenceType> from_base(const Type &parent);
  inline static std::optional<ReferenceType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<ReferenceType> from(const std::optional<Type> &parent);
  static std::optional<ReferenceType> from(const Reference &r);
  static std::optional<ReferenceType> from(const VariantEntity &e);
  static std::optional<ReferenceType> from(const TokenContext &t);

  Type pointee_type(void) const;
  Type pointee_type_as_written(void) const;
  bool is_inner_reference(void) const;
  bool is_spelled_as_l_value(void) const;
};

static_assert(sizeof(ReferenceType) == sizeof(Type));

#endif
} // namespace mx
