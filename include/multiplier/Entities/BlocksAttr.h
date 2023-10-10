// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "BlocksAttrBlockType.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class BlocksAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BlocksAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<BlocksAttr> in(const Index &index);
  static gap::generator<BlocksAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BlocksAttr> by_id(const Index &, EntityId);
  static gap::generator<BlocksAttr> in(const Fragment &frag);
  static gap::generator<BlocksAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BLOCKS;
  }

  static std::optional<BlocksAttr> from(const Attr &parent);

  inline static std::optional<BlocksAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BlocksAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BlocksAttr> from(const Reference &r);
  static std::optional<BlocksAttr> from(const TokenContext &t);

  BlocksAttrBlockType type(void) const;
};

static_assert(sizeof(BlocksAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
