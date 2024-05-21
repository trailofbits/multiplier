// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class MatrixType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MatrixType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<MatrixType> in(const Index &index);
  static gap::generator<MatrixType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MatrixType> by_id(const Index &, EntityId);

  static std::optional<MatrixType> from_base(const Type &parent);
  inline static std::optional<MatrixType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<MatrixType> from(const std::optional<Type> &parent);
  static std::optional<MatrixType> from(const Reference &r);
  static std::optional<MatrixType> from(const VariantEntity &e);
  static std::optional<MatrixType> from(const TokenContext &t);

  Type element_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(MatrixType) == sizeof(Type));

#endif
} // namespace mx
