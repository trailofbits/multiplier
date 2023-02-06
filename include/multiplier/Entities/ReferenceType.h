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
class ReferenceType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ReferenceType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ReferenceType> in(const Fragment &frag);
  static gap::generator<ReferenceType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static std::optional<ReferenceType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<ReferenceType> from(const TokenContext &t) {
    return from(t.as_type());
  }

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
