// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ArrayType.h"

namespace mx {
class EntityProvider;
class Index;
class ArrayType;
class ConstantArrayType;
class Expr;
class Token;
class Type;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConstantArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  static gap::generator<ConstantArrayType> in(const Fragment &frag);
  static gap::generator<ConstantArrayType> in(const File &file);
  static gap::generator<ConstantArrayType> in(const Index &index);
  static gap::generator<ConstantArrayType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConstantArrayType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::CONSTANT_ARRAY;
  }

  static std::optional<ConstantArrayType> from(const Type &parent);

  inline static std::optional<ConstantArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ConstantArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstantArrayType> from(const Reference &r);
  static std::optional<ConstantArrayType> from(const TokenContext &t);

  Type desugar(void) const;
  std::optional<Expr> size_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ConstantArrayType) == sizeof(ArrayType));

#endif
} // namespace mx
