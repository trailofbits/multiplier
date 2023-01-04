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

#include "TagType.h"
#include "TypeKind.h"

namespace mx {
class EnumType;
class TagType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using EnumTypeRange = DerivedEntityRange<TypeIterator, EnumType>;
using EnumTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, EnumType>;
class EnumType : public TagType {
 private:
  friend class FragmentImpl;
  friend class TagType;
  friend class Type;
 public:
  inline static EnumTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EnumTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : EnumType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::ENUM;
  }

  static std::optional<EnumType> from(const TokenContext &c);
  static std::optional<EnumType> from(const TagType &parent);

  inline static std::optional<EnumType> from(const std::optional<TagType> &parent) {
    if (parent) {
      return EnumType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumType> from(const Type &parent);

  inline static std::optional<EnumType> from(const std::optional<Type> &parent) {
    if (parent) {
      return EnumType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(EnumType) == sizeof(TagType));

#endif
} // namespace mx
