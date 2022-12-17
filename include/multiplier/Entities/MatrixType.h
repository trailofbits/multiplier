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

namespace mx {
class MatrixType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MatrixTypeRange = DerivedEntityRange<TypeIterator, MatrixType>;
using MatrixTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, MatrixType>;
class MatrixType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static MatrixTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MatrixTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : MatrixType::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  static std::optional<MatrixType> from(const TokenContext &c);
  static std::optional<MatrixType> from(const Type &parent);

  inline static std::optional<MatrixType> from(const std::optional<Type> &parent) {
    if (parent) {
      return MatrixType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type element_type(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(MatrixType) == sizeof(Type));

#endif
} // namespace mx
