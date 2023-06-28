// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class DependentBitIntType;
class Expr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentBitIntType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DependentBitIntType> in(const Fragment &frag);
  static gap::generator<DependentBitIntType> in(const File &file);
  static gap::generator<DependentBitIntType> in(const Index &index);
  static gap::generator<DependentBitIntType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentBitIntType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_BIT_INT;
  }

  static std::optional<DependentBitIntType> from(const Type &parent);

  inline static std::optional<DependentBitIntType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentBitIntType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentBitIntType> from(const Reference &r);
  static std::optional<DependentBitIntType> from(const TokenContext &t);

  Type desugar(void) const;
  Expr num_bits_expression(void) const;
  bool is_signed(void) const;
  bool is_sugared(void) const;
  bool is_unsigned(void) const;
};

static_assert(sizeof(DependentBitIntType) == sizeof(Type));

#endif
} // namespace mx
