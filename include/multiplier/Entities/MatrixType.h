// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class ConstantMatrixType;
class DependentSizedMatrixType;
class MatrixType;
class Token;
class Type;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MatrixType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<MatrixType> in(const Fragment &frag);
  static gap::generator<MatrixType> in(const File &file);
  static gap::generator<MatrixType> in(const Index &index);
  static gap::generator<MatrixType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MatrixType> by_id(const Index &, EntityId);

  static std::optional<MatrixType> from(const Type &parent);

  inline static std::optional<MatrixType> from(const std::optional<Type> &parent) {
    if (parent) {
      return MatrixType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MatrixType> from(const Reference &r);
  static std::optional<MatrixType> from(const TokenContext &t);

  Type desugar(void) const;
  Type element_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(MatrixType) == sizeof(Type));

#endif
} // namespace mx
