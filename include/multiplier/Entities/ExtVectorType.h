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

#include "TypeKind.h"
#include "VectorType.h"

namespace mx {
class ExtVectorType;
class Type;
class VectorType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExtVectorType : public VectorType {
 private:
  friend class FragmentImpl;
  friend class VectorType;
  friend class Type;
 public:
  static gap::generator<ExtVectorType> in(const Fragment &frag);
  static gap::generator<ExtVectorType> in(const File &file);
  static gap::generator<ExtVectorType> in(const Index &index);
  static gap::generator<ExtVectorType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExtVectorType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::EXT_VECTOR;
  }

  static std::optional<ExtVectorType> from(const Type &parent);

  inline static std::optional<ExtVectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ExtVectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ExtVectorType> from(const Reference &r) {
    return ExtVectorType::from(r.as_type());
  }

  inline static std::optional<ExtVectorType> from(const TokenContext &t) {
    return ExtVectorType::from(t.as_type());
  }

};

static_assert(sizeof(ExtVectorType) == sizeof(VectorType));

#endif
} // namespace mx
