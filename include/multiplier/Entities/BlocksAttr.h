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

#include "AttrKind.h"
#include "BlocksAttrBlockType.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class BlocksAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BlocksAttrRange = DerivedEntityRange<AttrIterator, BlocksAttr>;
using BlocksAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, BlocksAttr>;
class BlocksAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static BlocksAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BlocksAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : BlocksAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BLOCKS;
  }

  static std::optional<BlocksAttr> from(const TokenContext &c);
  static std::optional<BlocksAttr> from(const InheritableAttr &parent);

  inline static std::optional<BlocksAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return BlocksAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BlocksAttr> from(const Attr &parent);

  inline static std::optional<BlocksAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BlocksAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  BlocksAttrBlockType type(void) const;
};

static_assert(sizeof(BlocksAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
