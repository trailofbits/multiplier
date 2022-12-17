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

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class DependentBitIntType;
class Expr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DependentBitIntTypeRange = DerivedEntityRange<TypeIterator, DependentBitIntType>;
using DependentBitIntTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentBitIntType>;
class DependentBitIntType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static DependentBitIntTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentBitIntTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : DependentBitIntType::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_BIT_INT;
  }

  static std::optional<DependentBitIntType> from(const TokenContext &c);
  static std::optional<DependentBitIntType> from(const Type &parent);

  inline static std::optional<DependentBitIntType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentBitIntType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Expr num_bits_expression(void) const;
  bool is_signed(void) const;
  bool is_sugared(void) const;
  bool is_unsigned(void) const;
};

static_assert(sizeof(DependentBitIntType) == sizeof(Type));

#endif
} // namespace mx
