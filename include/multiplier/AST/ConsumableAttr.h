// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ConsumableAttrConsumedState.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class ConsumableAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConsumableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ConsumableAttr> in(const Index &index);
  static gap::generator<ConsumableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConsumableAttr> by_id(const Index &, EntityId);
  static gap::generator<ConsumableAttr> in(const Fragment &frag);
  static gap::generator<ConsumableAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONSUMABLE;
  }

  static std::optional<ConsumableAttr> from_base(const Attr &parent);
  inline static std::optional<ConsumableAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ConsumableAttr> from(const std::optional<Attr> &parent);
  static std::optional<ConsumableAttr> from(const Reference &r);
  static std::optional<ConsumableAttr> from(const VariantEntity &e);
  static std::optional<ConsumableAttr> from(const TokenContext &t);

  ConsumableAttrConsumedState default_state(void) const;
};

static_assert(sizeof(ConsumableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
