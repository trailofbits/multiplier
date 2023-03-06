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
#include "VectorTypeVectorKind.h"

namespace mx {
class ExtVectorType;
class Token;
class Type;
class VectorType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VectorType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<VectorType> in(const Fragment &frag);
  static gap::generator<VectorType> in(const File &file);
  static gap::generator<VectorType> in(const Index &index);
  static gap::generator<VectorType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<VectorType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::VECTOR;
  }

  static std::optional<VectorType> from(const Type &parent);

  inline static std::optional<VectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return VectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<VectorType> from(const Reference &r) {
    return VectorType::from(r.as_type());
  }

  inline static std::optional<VectorType> from(const TokenContext &t) {
    return VectorType::from(t.as_type());
  }

  Type desugar(void) const;
  Type element_type(void) const;
  VectorTypeVectorKind vector_kind(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(VectorType) == sizeof(Type));

#endif
} // namespace mx
