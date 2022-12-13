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
class TagDecl;
class TagType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TagTypeRange = DerivedEntityRange<TypeIterator, TagType>;
using TagTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, TagType>;
class TagType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static TagTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TagTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TagType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static std::optional<TagType> from(const TokenContext &c);
  static std::optional<TagType> from(const Type &parent);

  inline static std::optional<TagType> from(const std::optional<Type> &parent) {
    if (parent) {
      return TagType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  TagDecl declaration(void) const;
  bool is_being_defined(void) const;
};

static_assert(sizeof(TagType) == sizeof(Type));

#endif
} // namespace mx
