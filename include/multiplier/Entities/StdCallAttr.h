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
class Attr;
class InheritableAttr;
class StdCallAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using StdCallAttrRange = DerivedEntityRange<AttrIterator, StdCallAttr>;
using StdCallAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, StdCallAttr>;
class StdCallAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static StdCallAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static StdCallAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : StdCallAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::STD_CALL;
  }

  static std::optional<StdCallAttr> from(const TokenContext &c);
  static std::optional<StdCallAttr> from(const InheritableAttr &parent);

  inline static std::optional<StdCallAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return StdCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<StdCallAttr> from(const Attr &parent);

  inline static std::optional<StdCallAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return StdCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(StdCallAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
