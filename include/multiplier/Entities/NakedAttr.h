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
class InheritableAttr;
class NakedAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NakedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NakedAttr> in(const Index &index);
  static gap::generator<NakedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NakedAttr> by_id(const Index &, EntityId);
  static gap::generator<NakedAttr> in(const Fragment &frag);
  static gap::generator<NakedAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NAKED;
  }

  static std::optional<NakedAttr> from(const Attr &parent);

  inline static std::optional<NakedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NakedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NakedAttr> from(const Reference &r);
  static std::optional<NakedAttr> from(const TokenContext &t);

};

static_assert(sizeof(NakedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
