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
#include <span>
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
  static gap::generator<DecayedType> in(const File &file);
  static gap::generator<DecayedType> in(const Index &index);
  static gap::generator<DecayedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DecayedType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DECAYED;
  }

  static std::optional<DecayedType> from(const Type &parent);

  inline static std::optional<DecayedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DecayedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<DecayedType> from(const Reference &r) {
    return DecayedType::from(r.as_type());
  }

  inline static std::optional<DecayedType> from(const TokenContext &t) {
    return DecayedType::from(t.as_type());
  }

};

static_assert(sizeof(DecayedType) == sizeof(AdjustedType));

#endif
} // namespace mx
