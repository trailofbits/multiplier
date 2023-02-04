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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class TagDecl;
class TagType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TagType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TagType> in(const Fragment &frag);
  static gap::generator<TagType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static std::optional<TagType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<TagType> from(const TokenContext &t) {
    return from(t.as_type());
  }

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
