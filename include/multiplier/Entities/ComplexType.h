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
class ComplexType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ComplexType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ComplexType> in(const Fragment &frag);
  static gap::generator<ComplexType> in(const Index &index);
  static gap::generator<ComplexType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<ComplexType> by(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::COMPLEX;
  }

  inline static std::optional<ComplexType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<ComplexType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<ComplexType> from(const Type &parent);

  inline static std::optional<ComplexType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ComplexType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type element_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ComplexType) == sizeof(Type));

#endif
} // namespace mx
