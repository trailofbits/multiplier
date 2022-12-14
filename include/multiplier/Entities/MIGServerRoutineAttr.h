// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class MIGServerRoutineAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MIGServerRoutineAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, MIGServerRoutineAttr>;
class MIGServerRoutineAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<MIGServerRoutineAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static MIGServerRoutineAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : MIGServerRoutineAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIG_SERVER_ROUTINE_;
  }

  static std::optional<MIGServerRoutineAttr> from(const TokenContext &c);
  static std::optional<MIGServerRoutineAttr> from(const InheritableAttr &parent);

  inline static std::optional<MIGServerRoutineAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return MIGServerRoutineAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MIGServerRoutineAttr> from(const Attr &parent);

  inline static std::optional<MIGServerRoutineAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MIGServerRoutineAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(MIGServerRoutineAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
