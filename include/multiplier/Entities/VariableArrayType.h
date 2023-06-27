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
class Expr;
class Token;
class TokenRange;
class Type;
class VariableArrayType;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VariableArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  static gap::generator<VariableArrayType> in(const Fragment &frag);
  static gap::generator<VariableArrayType> in(const File &file);
  static gap::generator<VariableArrayType> in(const Index &index);
  static gap::generator<VariableArrayType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VariableArrayType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::VARIABLE_ARRAY;
  }

  static std::optional<VariableArrayType> from(const Type &parent);

  inline static std::optional<VariableArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return VariableArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VariableArrayType> from(const Reference &r);
  static std::optional<VariableArrayType> from(const TokenContext &t);

  Type desugar(void) const;
  TokenRange brackets_range(void) const;
  Token l_bracket_token(void) const;
  Token r_bracket_token(void) const;
  Expr size_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(VariableArrayType) == sizeof(ArrayType));

#endif
} // namespace mx
