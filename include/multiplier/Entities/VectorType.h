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
class Type;
class VectorType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using VectorTypeRange = DerivedEntityRange<TypeIterator, VectorType>;
using VectorTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, VectorType>;
class VectorType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static VectorTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VectorTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : VectorType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::VECTOR;
  }

  static std::optional<VectorType> from(const TokenContext &c);
  static std::optional<VectorType> from(const Type &parent);

  inline static std::optional<VectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return VectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type element_type(void) const;
  VectorTypeVectorKind vector_kind(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(VectorType) == sizeof(Type));

#endif
} // namespace mx
