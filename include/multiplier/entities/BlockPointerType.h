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
class BlockPointerType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BlockPointerTypeRange = DerivedEntityRange<TypeIterator, BlockPointerType>;
using BlockPointerTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, BlockPointerType>;
class BlockPointerType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static BlockPointerTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BlockPointerTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BlockPointerType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::BLOCK_POINTER;
  }

  static std::optional<BlockPointerType> from(const TokenContext &c);
  static std::optional<BlockPointerType> from(const Type &parent);

  inline static std::optional<BlockPointerType> from(const std::optional<Type> &parent) {
    if (parent) {
      return BlockPointerType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(BlockPointerType) == sizeof(Type));

#endif
} // namespace mx
