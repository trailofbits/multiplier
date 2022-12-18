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
#include "MSVtorDispMode.h"

namespace mx {
class Attr;
class InheritableAttr;
class MSVtorDispAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MSVtorDispAttrRange = DerivedEntityRange<AttrIterator, MSVtorDispAttr>;
using MSVtorDispAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSVtorDispAttr>;
class MSVtorDispAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static MSVtorDispAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSVtorDispAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : MSVtorDispAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MS_VTOR_DISP;
  }

  static std::optional<MSVtorDispAttr> from(const TokenContext &c);
  static std::optional<MSVtorDispAttr> from(const InheritableAttr &parent);

  inline static std::optional<MSVtorDispAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return MSVtorDispAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSVtorDispAttr> from(const Attr &parent);

  inline static std::optional<MSVtorDispAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MSVtorDispAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
  MSVtorDispMode vtor_disp_mode(void) const;
};

static_assert(sizeof(MSVtorDispAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
