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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "MatrixType.h"
#include "TypeKind.h"

namespace mx {
class ConstantMatrixType;
class MatrixType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConstantMatrixTypeRange = DerivedEntityRange<TypeIterator, ConstantMatrixType>;
using ConstantMatrixTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConstantMatrixType>;
class ConstantMatrixType : public MatrixType {
 private:
  friend class FragmentImpl;
  friend class MatrixType;
  friend class Type;
 public:
  inline static ConstantMatrixTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConstantMatrixTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ConstantMatrixType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::CONSTANT_MATRIX;
  }

  static std::optional<ConstantMatrixType> from(const TokenContext &c);
  static std::optional<ConstantMatrixType> from(const MatrixType &parent);

  inline static std::optional<ConstantMatrixType> from(const std::optional<MatrixType> &parent) {
    if (parent) {
      return ConstantMatrixType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstantMatrixType> from(const Type &parent);

  inline static std::optional<ConstantMatrixType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ConstantMatrixType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ConstantMatrixType) == sizeof(MatrixType));

#endif
} // namespace mx
