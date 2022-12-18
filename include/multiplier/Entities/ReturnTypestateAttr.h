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
#include "ReturnTypestateAttrConsumedState.h"

namespace mx {
class Attr;
class InheritableAttr;
class ReturnTypestateAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ReturnTypestateAttrRange = DerivedEntityRange<AttrIterator, ReturnTypestateAttr>;
using ReturnTypestateAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ReturnTypestateAttr>;
class ReturnTypestateAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ReturnTypestateAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ReturnTypestateAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ReturnTypestateAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RETURN_TYPESTATE;
  }

  static std::optional<ReturnTypestateAttr> from(const TokenContext &c);
  static std::optional<ReturnTypestateAttr> from(const InheritableAttr &parent);

  inline static std::optional<ReturnTypestateAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ReturnTypestateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ReturnTypestateAttr> from(const Attr &parent);

  inline static std::optional<ReturnTypestateAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ReturnTypestateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
  ReturnTypestateAttrConsumedState state(void) const;
};

static_assert(sizeof(ReturnTypestateAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
