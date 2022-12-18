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
class DependentSizedMatrixType;
class Expr;
class MatrixType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DependentSizedMatrixTypeRange = DerivedEntityRange<TypeIterator, DependentSizedMatrixType>;
using DependentSizedMatrixTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentSizedMatrixType>;
class DependentSizedMatrixType : public MatrixType {
 private:
  friend class FragmentImpl;
  friend class MatrixType;
  friend class Type;
 public:
  inline static DependentSizedMatrixTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentSizedMatrixTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DependentSizedMatrixType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_SIZED_MATRIX;
  }

  static std::optional<DependentSizedMatrixType> from(const TokenContext &c);
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
