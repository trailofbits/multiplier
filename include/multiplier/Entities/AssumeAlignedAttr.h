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
#include "StmtUseSelector.h"

namespace mx {
class AssumeAlignedAttr;
class Attr;
class Expr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AssumeAlignedAttrRange = DerivedEntityRange<AttrIterator, AssumeAlignedAttr>;
using AssumeAlignedAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AssumeAlignedAttr>;
class AssumeAlignedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AssumeAlignedAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AssumeAlignedAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : AssumeAlignedAttr::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSUME_ALIGNED;
  }

  static std::optional<AssumeAlignedAttr> from(const TokenContext &c);
  static std::optional<AssumeAlignedAttr> from(const InheritableAttr &parent);

  inline static std::optional<AssumeAlignedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AssumeAlignedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssumeAlignedAttr> from(const Attr &parent);

  inline static std::optional<AssumeAlignedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssumeAlignedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr alignment(void) const;
  std::optional<Expr> offset(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(AssumeAlignedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
