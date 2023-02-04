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

#include "ElaboratedTypeKeyword.h"
#include "Type.h"
#include "TypeKind.h"

namespace mx {
class Type;
class TypeWithKeyword;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeWithKeyword : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<TypeWithKeyword> in(const Fragment &frag);
  static gap::generator<TypeWithKeyword> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static std::optional<TypeWithKeyword> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<TypeWithKeyword> from(const TokenContext &t) {
    return from(t.as_type());
  }

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
