// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "SetTypestateAttrConsumedState.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class SetTypestateAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SetTypestateAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SetTypestateAttr> in(const Fragment &frag);
  static gap::generator<SetTypestateAttr> in(const File &file);
  static gap::generator<SetTypestateAttr> in(const Index &index);
  static gap::generator<SetTypestateAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SetTypestateAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SET_TYPESTATE;
  }

  static std::optional<SetTypestateAttr> from(const Attr &parent);

  inline static std::optional<SetTypestateAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SetTypestateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SetTypestateAttr> from(const Reference &r);
  static std::optional<SetTypestateAttr> from(const TokenContext &t);

  SetTypestateAttrConsumedState new_state(void) const;
};

static_assert(sizeof(SetTypestateAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
