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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "BlocksAttrBlockType.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class BlocksAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BlocksAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<BlocksAttr> in(const Fragment &frag);
  static gap::generator<BlocksAttr> in(const File &file);
  static gap::generator<BlocksAttr> in(const Index &index);
  static gap::generator<BlocksAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BlocksAttr> by_id(const Index &, EntityId);

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

  inline static std::optional<BlocksAttr> from(const Reference &r) {
    return BlocksAttr::from(r.as_attribute());
  }

  inline static std::optional<BlocksAttr> from(const TokenContext &t) {
    return BlocksAttr::from(t.as_attribute());
  }

  BlocksAttrBlockType type(void) const;
};

static_assert(sizeof(BlocksAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
