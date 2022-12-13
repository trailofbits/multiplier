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

#include "TagType.h"
#include "TypeKind.h"

namespace mx {
class RecordType;
class TagType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using RecordTypeRange = DerivedEntityRange<TypeIterator, RecordType>;
using RecordTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, RecordType>;
class RecordType : public TagType {
 private:
  friend class FragmentImpl;
  friend class TagType;
  friend class Type;
 public:
  inline static RecordTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RecordTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : RecordType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::RECORD;
  }

  static std::optional<RecordType> from(const TokenContext &c);
  static std::optional<RecordType> from(const TagType &parent);

  inline static std::optional<RecordType> from(const std::optional<TagType> &parent) {
    if (parent) {
      return RecordType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RecordType> from(const Type &parent);

  inline static std::optional<RecordType> from(const std::optional<Type> &parent) {
    if (parent) {
      return RecordType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool has_const_fields(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(RecordType) == sizeof(TagType));

#endif
} // namespace mx
