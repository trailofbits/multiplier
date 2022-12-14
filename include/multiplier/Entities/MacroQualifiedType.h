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

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class MacroQualifiedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroQualifiedTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, MacroQualifiedType>;
class MacroQualifiedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static gap::generator<MacroQualifiedType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static MacroQualifiedTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : MacroQualifiedType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::MACRO_QUALIFIED;
  }

  static std::optional<MacroQualifiedType> from(const TokenContext &c);
  static std::optional<MacroQualifiedType> from(const Type &parent);

  inline static std::optional<MacroQualifiedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return MacroQualifiedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type modified_type(void) const;
  Type underlying_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(MacroQualifiedType) == sizeof(Type));

#endif
} // namespace mx
