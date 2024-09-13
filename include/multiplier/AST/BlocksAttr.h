// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/BlocksAttrBlockType.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class BlocksAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BlocksAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<BlocksAttr> in(const Index &index);
  static gap::generator<BlocksAttr> in(const Fragment &frag);
  static gap::generator<BlocksAttr> in(const File &file);
  static gap::generator<BlocksAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BLOCKS;
  }

  static std::optional<BlocksAttr> by_id(const Index &, EntityId);

  static std::optional<BlocksAttr> from_base(const Attr &parent);
  inline static std::optional<BlocksAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<BlocksAttr> from(const std::optional<Attr> &parent);
  static std::optional<BlocksAttr> from(const Reference &r);
  static std::optional<BlocksAttr> from(const VariantEntity &e);
  static std::optional<BlocksAttr> from(const TokenContext &t);

  BlocksAttrBlockType type(void) const;
};

static_assert(sizeof(BlocksAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
