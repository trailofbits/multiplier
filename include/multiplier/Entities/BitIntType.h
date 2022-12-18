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
class BitIntType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BitIntTypeRange = DerivedEntityRange<TypeIterator, BitIntType>;
using BitIntTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, BitIntType>;
class BitIntType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static BitIntTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BitIntTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : BitIntType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BIT_INT;
  }

  static std::optional<BitIntType> from(const TokenContext &c);
  static std::optional<BitIntType> from(const Type &parent);

  inline static std::optional<BitIntType> from(const std::optional<Type> &parent) {
    if (parent) {
      return BitIntType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_signed(void) const;
  bool is_sugared(void) const;
  bool is_unsigned(void) const;
};

static_assert(sizeof(BitIntType) == sizeof(Type));

#endif
} // namespace mx
