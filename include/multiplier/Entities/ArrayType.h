// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ArrayTypeArraySizeModifier.h"
#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class ArrayType;
class ConstantArrayType;
class DependentSizedArrayType;
class IncompleteArrayType;
class Token;
class Type;
class VariableArrayType;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ArrayType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ArrayType> in(const Fragment &frag);
  static gap::generator<ArrayType> in(const File &file);
  static gap::generator<ArrayType> in(const Index &index);
  static gap::generator<ArrayType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ArrayType> by_id(const Index &, EntityId);

  static std::optional<ArrayType> from(const Type &parent);

  inline static std::optional<ArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArrayType> from(const Reference &r);
  static std::optional<ArrayType> from(const TokenContext &t);

  Type element_type(void) const;
  ArrayTypeArraySizeModifier size_modifier(void) const;
};

static_assert(sizeof(ArrayType) == sizeof(Type));

#endif
} // namespace mx
