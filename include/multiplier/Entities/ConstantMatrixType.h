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
class ConstantMatrixType : public MatrixType {
 private:
  friend class FragmentImpl;
  friend class MatrixType;
  friend class Type;
 public:
  inline static gap::generator<ConstantMatrixType> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ConstantMatrixType> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ConstantMatrixType::containing(tok)) {
      if(parent.id() == id()) { return true; }
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
