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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "BuiltinTypeKind.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class BuiltinType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BuiltinTypeRange = DerivedEntityRange<TypeIterator, BuiltinType>;
using BuiltinTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, BuiltinType>;
class BuiltinType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static BuiltinTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BuiltinTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BuiltinType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BUILTIN;
  }

  static std::optional<BuiltinType> from(const TokenContext &c);
  static std::optional<BuiltinType> from(const Type &parent);

  inline static std::optional<BuiltinType> from(const std::optional<Type> &parent) {
    if (parent) {
      return BuiltinType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  BuiltinTypeKind builtin_kind(void) const;
  bool is_floating_point(void) const;
  bool is_integer(void) const;
  bool is_sve_bool(void) const;
  bool is_signed_integer(void) const;
  bool is_sugared(void) const;
  bool is_unsigned_integer(void) const;
};

static_assert(sizeof(BuiltinType) == sizeof(Type));

#endif
} // namespace mx
