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
class AlignMac68kAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AlignMac68kAttrRange = DerivedEntityRange<AttrIterator, AlignMac68kAttr>;
using AlignMac68kAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AlignMac68kAttr>;
class AlignMac68kAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AlignMac68kAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AlignMac68kAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AlignMac68kAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGN_MAC68K;
  }

  static std::optional<AlignMac68kAttr> from(const TokenContext &c);
  static std::optional<AlignMac68kAttr> from(const InheritableAttr &parent);

  inline static std::optional<AlignMac68kAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AlignMac68kAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AlignMac68kAttr> from(const Attr &parent);

  inline static std::optional<AlignMac68kAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignMac68kAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(AlignMac68kAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
