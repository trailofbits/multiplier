// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/MatrixType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class DependentSizedMatrixType;
class Expr;
class MatrixType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DependentSizedMatrixType : public MatrixType {
 private:
  friend class FragmentImpl;
  friend class MatrixType;
  friend class Type;
 public:
  static gap::generator<DependentSizedMatrixType> in(const Index &index);
  static gap::generator<DependentSizedMatrixType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DependentSizedMatrixType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_SIZED_MATRIX;
  }

  static std::optional<DependentSizedMatrixType> from_base(const Type &parent);
  inline static std::optional<DependentSizedMatrixType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<DependentSizedMatrixType> from(const std::optional<Type> &parent);
  static std::optional<DependentSizedMatrixType> from(const Reference &r);
  static std::optional<DependentSizedMatrixType> from(const VariantEntity &e);
  static std::optional<DependentSizedMatrixType> from(const TokenContext &t);

  Token attribute_token(void) const;
  Expr column_expression(void) const;
  Expr row_expression(void) const;
};

static_assert(sizeof(DependentSizedMatrixType) == sizeof(MatrixType));

#endif
} // namespace mx
