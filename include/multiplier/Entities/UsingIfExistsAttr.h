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
class UsingIfExistsAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using UsingIfExistsAttrRange = DerivedEntityRange<AttrIterator, UsingIfExistsAttr>;
using UsingIfExistsAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingIfExistsAttr>;
class UsingIfExistsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static UsingIfExistsAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingIfExistsAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UsingIfExistsAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::USING_IF_EXISTS;
  }

  static std::optional<UsingIfExistsAttr> from(const TokenContext &c);
  static std::optional<UsingIfExistsAttr> from(const InheritableAttr &parent);

  inline static std::optional<UsingIfExistsAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return UsingIfExistsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingIfExistsAttr> from(const Attr &parent);

  inline static std::optional<UsingIfExistsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return UsingIfExistsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(UsingIfExistsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
