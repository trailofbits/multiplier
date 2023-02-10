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

#include "MatrixType.h"
#include "TypeKind.h"

namespace mx {
class ConstantMatrixType;
class MatrixType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConstantMatrixType : public MatrixType {
 private:
  friend class FragmentImpl;
  friend class MatrixType;
  friend class Type;
 public:
  static gap::generator<ConstantMatrixType> in(const Fragment &frag);
  static gap::generator<ConstantMatrixType> in(const File &file);
  static gap::generator<ConstantMatrixType> in(const Index &index);
  static gap::generator<ConstantMatrixType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConstantMatrixType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::CONSTANT_MATRIX;
  }

  static std::optional<ConstantMatrixType> from(const Type &parent);

  inline static std::optional<ConstantMatrixType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ConstantMatrixType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ConstantMatrixType> from(const Reference &r) {
    return ConstantMatrixType::from(r.as_type());
  }

  inline static std::optional<ConstantMatrixType> from(const TokenContext &t) {
    return ConstantMatrixType::from(t.as_type());
  }

};

static_assert(sizeof(ConstantMatrixType) == sizeof(MatrixType));

#endif
} // namespace mx
