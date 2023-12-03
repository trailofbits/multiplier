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
class IBActionAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT IBActionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<IBActionAttr> in(const Index &index);
  static gap::generator<IBActionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<IBActionAttr> by_id(const Index &, EntityId);
  static gap::generator<IBActionAttr> in(const Fragment &frag);
  static gap::generator<IBActionAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::IB_ACTION;
  }

  static std::optional<IBActionAttr> from_base(const Attr &parent);
  inline static std::optional<IBActionAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<IBActionAttr> from(const std::optional<Attr> &parent);
  static std::optional<IBActionAttr> from(const Reference &r);
  static std::optional<IBActionAttr> from(const VariantEntity &e);
  static std::optional<IBActionAttr> from(const TokenContext &t);

};

static_assert(sizeof(IBActionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
