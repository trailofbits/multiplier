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
#include "ZeroCallUsedRegsAttrZeroCallUsedRegsKind.h"

namespace mx {
class Attr;
class InheritableAttr;
class ZeroCallUsedRegsAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ZeroCallUsedRegsAttrRange = DerivedEntityRange<AttrIterator, ZeroCallUsedRegsAttr>;
using ZeroCallUsedRegsAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ZeroCallUsedRegsAttr>;
class ZeroCallUsedRegsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ZeroCallUsedRegsAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ZeroCallUsedRegsAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ZeroCallUsedRegsAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ZERO_CALL_USED_REGS;
  }

  static std::optional<ZeroCallUsedRegsAttr> from(const TokenContext &c);
  static std::optional<ZeroCallUsedRegsAttr> from(const InheritableAttr &parent);

  inline static std::optional<ZeroCallUsedRegsAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ZeroCallUsedRegsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ZeroCallUsedRegsAttr> from(const Attr &parent);

  inline static std::optional<ZeroCallUsedRegsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ZeroCallUsedRegsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
  ZeroCallUsedRegsAttrZeroCallUsedRegsKind zero_call_used_regs(void) const;
};

static_assert(sizeof(ZeroCallUsedRegsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
