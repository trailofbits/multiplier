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
class NoSpeculativeLoadHardeningAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoSpeculativeLoadHardeningAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoSpeculativeLoadHardeningAttr> in(const Fragment &frag);
  static gap::generator<NoSpeculativeLoadHardeningAttr> in(const File &file);
  static gap::generator<NoSpeculativeLoadHardeningAttr> in(const Index &index);
  static gap::generator<NoSpeculativeLoadHardeningAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoSpeculativeLoadHardeningAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_SPECULATIVE_LOAD_HARDENING;
  }

  static std::optional<NoSpeculativeLoadHardeningAttr> from(const Attr &parent);

  inline static std::optional<NoSpeculativeLoadHardeningAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoSpeculativeLoadHardeningAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoSpeculativeLoadHardeningAttr> from(const Reference &r);
  static std::optional<NoSpeculativeLoadHardeningAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoSpeculativeLoadHardeningAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
