// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "OwnershipAttrOwnershipKind.h"
#include "OwnershipAttrSpelling.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class OwnershipAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OwnershipAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OwnershipAttr> in(const Fragment &frag);
  static gap::generator<OwnershipAttr> in(const File &file);
  static gap::generator<OwnershipAttr> in(const Index &index);
  static gap::generator<OwnershipAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OwnershipAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OWNERSHIP;
  }

  static std::optional<OwnershipAttr> from(const Attr &parent);

  inline static std::optional<OwnershipAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OwnershipAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OwnershipAttr> from(const Reference &r);
  static std::optional<OwnershipAttr> from(const TokenContext &t);

  OwnershipAttrOwnershipKind own_kind(void) const;
  OwnershipAttrSpelling semantic_spelling(void) const;
  bool is_holds(void) const;
  bool is_returns(void) const;
  bool is_takes(void) const;
};

static_assert(sizeof(OwnershipAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
