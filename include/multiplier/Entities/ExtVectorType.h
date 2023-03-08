// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "VectorType.h"

namespace mx {
class EntityProvider;
class Index;
class ExtVectorType;
class Token;
class Type;
class VectorType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExtVectorType : public VectorType {
 private:
  friend class FragmentImpl;
  friend class VectorType;
  friend class Type;
 public:
  static gap::generator<ExtVectorType> in(const Fragment &frag);
  static gap::generator<ExtVectorType> in(const File &file);
  static gap::generator<ExtVectorType> in(const Index &index);
  static gap::generator<ExtVectorType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExtVectorType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::EXT_VECTOR;
  }

  static std::optional<ExtVectorType> from(const Type &parent);

  inline static std::optional<ExtVectorType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ExtVectorType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExtVectorType> from(const Reference &r);
  static std::optional<ExtVectorType> from(const TokenContext &t);

};

static_assert(sizeof(ExtVectorType) == sizeof(VectorType));

#endif
} // namespace mx
