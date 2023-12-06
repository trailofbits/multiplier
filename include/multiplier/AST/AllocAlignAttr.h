// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AllocAlignAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AllocAlignAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AllocAlignAttr> in(const Index &index);
  static gap::generator<AllocAlignAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AllocAlignAttr> by_id(const Index &, EntityId);
  static gap::generator<AllocAlignAttr> in(const Fragment &frag);
  static gap::generator<AllocAlignAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALLOC_ALIGN;
  }

  static std::optional<AllocAlignAttr> from_base(const Attr &parent);
  inline static std::optional<AllocAlignAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AllocAlignAttr> from(const std::optional<Attr> &parent);
  static std::optional<AllocAlignAttr> from(const Reference &r);
  static std::optional<AllocAlignAttr> from(const VariantEntity &e);
  static std::optional<AllocAlignAttr> from(const TokenContext &t);

};

static_assert(sizeof(AllocAlignAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
