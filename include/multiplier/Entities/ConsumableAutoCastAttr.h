// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class ConsumableAutoCastAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConsumableAutoCastAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ConsumableAutoCastAttr> in(const Fragment &frag);
  static gap::generator<ConsumableAutoCastAttr> in(const File &file);
  static gap::generator<ConsumableAutoCastAttr> in(const Index &index);
  static gap::generator<ConsumableAutoCastAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConsumableAutoCastAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONSUMABLE_AUTO_CAST;
  }

  static std::optional<ConsumableAutoCastAttr> from(const Attr &parent);

  inline static std::optional<ConsumableAutoCastAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ConsumableAutoCastAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConsumableAutoCastAttr> from(const Reference &r);
  static std::optional<ConsumableAutoCastAttr> from(const TokenContext &t);

};

static_assert(sizeof(ConsumableAutoCastAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
