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
class AArch64SVEPcsAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AArch64SVEPcsAttrRange = DerivedEntityRange<AttrIterator, AArch64SVEPcsAttr>;
using AArch64SVEPcsAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AArch64SVEPcsAttr>;
class AArch64SVEPcsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AArch64SVEPcsAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AArch64SVEPcsAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AArch64SVEPcsAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::A_ARCH64_SVE_PCS;
  }

  static std::optional<AArch64SVEPcsAttr> from(const TokenContext &c);
  static std::optional<AArch64SVEPcsAttr> from(const InheritableAttr &parent);

  inline static std::optional<AArch64SVEPcsAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AArch64SVEPcsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AArch64SVEPcsAttr> from(const Attr &parent);

  inline static std::optional<AArch64SVEPcsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AArch64SVEPcsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(AArch64SVEPcsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
