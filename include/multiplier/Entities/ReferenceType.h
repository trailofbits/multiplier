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
class ReferenceType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ReferenceTypeRange = DerivedEntityRange<TypeIterator, ReferenceType>;
using ReferenceTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, ReferenceType>;
class ReferenceType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static ReferenceTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ReferenceTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ReferenceType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static std::optional<ReferenceType> from(const TokenContext &c);
  static std::optional<ReferenceType> from(const Type &parent);

  inline static std::optional<ReferenceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ReferenceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type pointee_type_as_written(void) const;
  bool is_inner_reference(void) const;
  bool is_spelled_as_l_value(void) const;
};

static_assert(sizeof(ReferenceType) == sizeof(Type));

#endif
} // namespace mx
