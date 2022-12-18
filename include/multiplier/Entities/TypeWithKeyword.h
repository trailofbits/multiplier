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

#include "ElaboratedTypeKeyword.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class Type;
class TypeWithKeyword;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeWithKeywordRange = DerivedEntityRange<TypeIterator, TypeWithKeyword>;
using TypeWithKeywordContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeWithKeyword>;
class TypeWithKeyword : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static TypeWithKeywordRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeWithKeywordContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TypeWithKeyword::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static std::optional<TypeWithKeyword> from(const TokenContext &c);
  static std::optional<TypeWithKeyword> from(const Type &parent);

  inline static std::optional<TypeWithKeyword> from(const std::optional<Type> &parent) {
    if (parent) {
      return TypeWithKeyword::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ElaboratedTypeKeyword keyword(void) const;
};

static_assert(sizeof(TypeWithKeyword) == sizeof(Type));

#endif
} // namespace mx
