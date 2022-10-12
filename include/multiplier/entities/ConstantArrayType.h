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
#include "StmtUseSelector.h"
#include "TypeKind.h"

namespace mx {
class ArrayType;
class ConstantArrayType;
class Expr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConstantArrayTypeRange = DerivedEntityRange<TypeIterator, ConstantArrayType>;
using ConstantArrayTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConstantArrayType>;
class ConstantArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  inline static ConstantArrayTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConstantArrayTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ConstantArrayType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::CONSTANT_ARRAY;
  }

  static std::optional<ConstantArrayType> from(const TokenContext &c);
  static std::optional<ConstantArrayType> from(const ArrayType &parent);

  inline static std::optional<ConstantArrayType> from(const std::optional<ArrayType> &parent) {
    if (parent) {
      return ConstantArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstantArrayType> from(const Type &parent);

  inline static std::optional<ConstantArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ConstantArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  std::optional<Expr> size_expression(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ConstantArrayType) == sizeof(ArrayType));

#endif
} // namespace mx
