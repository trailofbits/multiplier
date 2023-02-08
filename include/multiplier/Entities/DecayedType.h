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

#include "AdjustedType.h"
#include "TypeKind.h"

namespace mx {
class AdjustedType;
class DecayedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DecayedType : public AdjustedType {
 private:
  friend class FragmentImpl;
  friend class AdjustedType;
  friend class Type;
 public:
  static gap::generator<DecayedType> in(const Fragment &frag);
  static gap::generator<DecayedType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DECAYED;
  }

  static gap::generator<TypeKind> derived_kinds(void);
  inline static std::optional<DecayedType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<DecayedType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<DecayedType> from(const AdjustedType &parent);

  inline static std::optional<DecayedType> from(const std::optional<AdjustedType> &parent) {
    if (parent) {
      return DecayedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DecayedType> from(const Type &parent);

  inline static std::optional<DecayedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DecayedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(DecayedType) == sizeof(AdjustedType));

#endif
} // namespace mx
