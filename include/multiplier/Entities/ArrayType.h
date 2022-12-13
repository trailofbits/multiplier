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

#include "ArrayTypeArraySizeModifier.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class ArrayType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ArrayTypeRange = DerivedEntityRange<TypeIterator, ArrayType>;
using ArrayTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArrayType>;
class ArrayType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static ArrayTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArrayTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ArrayType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static std::optional<ArrayType> from(const TokenContext &c);
  static std::optional<ArrayType> from(const Type &parent);

  inline static std::optional<ArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type element_type(void) const;
  ArrayTypeArraySizeModifier size_modifier(void) const;
};

static_assert(sizeof(ArrayType) == sizeof(Type));

#endif
} // namespace mx
