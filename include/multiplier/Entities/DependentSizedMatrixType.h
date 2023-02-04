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

#include "MatrixType.h"
#include "TypeKind.h"

namespace mx {
class DependentSizedMatrixType;
class Expr;
class MatrixType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DependentSizedMatrixType : public MatrixType {
 private:
  friend class FragmentImpl;
  friend class MatrixType;
  friend class Type;
 public:
  static gap::generator<DependentSizedMatrixType> in(const Fragment &frag);
  static gap::generator<DependentSizedMatrixType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_SIZED_MATRIX;
  }

  inline static std::optional<DependentSizedMatrixType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<DependentSizedMatrixType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<DependentSizedMatrixType> from(const MatrixType &parent);

  inline static std::optional<DependentSizedMatrixType> from(const std::optional<MatrixType> &parent) {
    if (parent) {
      return DependentSizedMatrixType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DependentSizedMatrixType> from(const Type &parent);

  inline static std::optional<DependentSizedMatrixType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentSizedMatrixType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token attribute_token(void) const;
  Expr column_expression(void) const;
  Expr row_expression(void) const;
};

static_assert(sizeof(DependentSizedMatrixType) == sizeof(MatrixType));

#endif
} // namespace mx
