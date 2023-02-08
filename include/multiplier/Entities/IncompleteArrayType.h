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

#include "ArrayType.h"
#include "TypeKind.h"

namespace mx {
class ArrayType;
class IncompleteArrayType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IncompleteArrayType : public ArrayType {
 private:
  friend class FragmentImpl;
  friend class ArrayType;
  friend class Type;
 public:
  static gap::generator<IncompleteArrayType> in(const Fragment &frag);
  static gap::generator<IncompleteArrayType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::INCOMPLETE_ARRAY;
  }

  static gap::generator<TypeKind> derived_kinds(void);
  inline static std::optional<IncompleteArrayType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<IncompleteArrayType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<IncompleteArrayType> from(const ArrayType &parent);

  inline static std::optional<IncompleteArrayType> from(const std::optional<ArrayType> &parent) {
    if (parent) {
      return IncompleteArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IncompleteArrayType> from(const Type &parent);

  inline static std::optional<IncompleteArrayType> from(const std::optional<Type> &parent) {
    if (parent) {
      return IncompleteArrayType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(IncompleteArrayType) == sizeof(ArrayType));

#endif
} // namespace mx
