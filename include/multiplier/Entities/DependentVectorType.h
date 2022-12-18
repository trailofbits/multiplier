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

#include "Type.h"
#include "TypeKind.h"
#include "VectorTypeVectorKind.h"

namespace mx {
class DependentVectorType;
class Expr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DependentVectorTypeRange = DerivedEntityRange<TypeIterator, DependentVectorType>;
using DependentVectorTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentVectorType>;
class DependentVectorType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static DependentVectorTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentVectorTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : DependentVectorType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::DEPENDENT_VECTOR;
  }

  static std::optional<DependentVectorType> from(const TokenContext &c);
  static std::optional<DependentVectorType> from(const Type &parent);

  inline static std::optional<DependentVectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return DependentVectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Token attribute_token(void) const;
  Type element_type(void) const;
  Expr size_expression(void) const;
  VectorTypeVectorKind vector_kind(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(DependentVectorType) == sizeof(Type));

#endif
} // namespace mx
