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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AcquiredBeforeAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AcquiredBeforeAttrRange = DerivedEntityRange<AttrIterator, AcquiredBeforeAttr>;
using AcquiredBeforeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AcquiredBeforeAttr>;
class AcquiredBeforeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AcquiredBeforeAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AcquiredBeforeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AcquiredBeforeAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRED_BEFORE;
  }

  static std::optional<AcquiredBeforeAttr> from(const TokenContext &c);
  static std::optional<AcquiredBeforeAttr> from(const InheritableAttr &parent);

  inline static std::optional<AcquiredBeforeAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AcquiredBeforeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AcquiredBeforeAttr> from(const Attr &parent);

  inline static std::optional<AcquiredBeforeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AcquiredBeforeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(AcquiredBeforeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
