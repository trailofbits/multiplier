// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "ArrayType.h"
#include "TypeKind.h"

namespace mx {
class ArrayType;
class Expr;
class Type;
class VariableArrayType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using VariableArrayTypeRange = DerivedEntityRange<TypeIterator, VariableArrayType>;
using VariableArrayTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, VariableArrayType>;
class VariableArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  inline static VariableArrayTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VariableArrayTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : VariableArrayType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::VARIABLE_ARRAY;
  }

  static std::optional<VariableArrayType> from(const TokenContext &c);
  static std::optional<VariableArrayType> from(const ArrayType &parent);

  inline static std::optional<VariableArrayType> from(const std::optional<ArrayType> &parent) {
    if (parent) {
      return VariableArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VariableArrayType> from(const Type &parent);

  inline static std::optional<VariableArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return VariableArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

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
