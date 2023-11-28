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
class Attr;
class InheritableAttr;
class MinVectorWidthAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MinVectorWidthAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MinVectorWidthAttr> in(const Index &index);
  static gap::generator<MinVectorWidthAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MinVectorWidthAttr> by_id(const Index &, EntityId);
  static gap::generator<MinVectorWidthAttr> in(const Fragment &frag);
  static gap::generator<MinVectorWidthAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIN_VECTOR_WIDTH;
  }

  static std::optional<MinVectorWidthAttr> from_base(const Attr &parent);
  inline static std::optional<MinVectorWidthAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MinVectorWidthAttr> from(const std::optional<Attr> &parent);
  static std::optional<MinVectorWidthAttr> from(const Reference &r);
  static std::optional<MinVectorWidthAttr> from(const VariantEntity &e);
  static std::optional<MinVectorWidthAttr> from(const TokenContext &t);

};

static_assert(sizeof(MinVectorWidthAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
