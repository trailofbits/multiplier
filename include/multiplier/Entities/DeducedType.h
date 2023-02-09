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

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class DeducedType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeducedType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<DeducedType> in(const Fragment &frag);
  static gap::generator<DeducedType> in(const Index &index);
  static gap::generator<DeducedType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DeducedType> by_id(const Index &, EntityId);

  inline static std::optional<DeducedType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<DeducedType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<DeducedType> from(const Type &parent);

  inline static std::optional<DeducedType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DeducedType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  std::optional<Type> resolved_type(void) const;
  bool is_deduced(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DeducedType) == sizeof(Type));

#endif
} // namespace mx
