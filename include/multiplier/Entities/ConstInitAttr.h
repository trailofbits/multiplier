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
#include "ConstInitAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class ConstInitAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConstInitAttrRange = DerivedEntityRange<AttrIterator, ConstInitAttr>;
using ConstInitAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConstInitAttr>;
class ConstInitAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ConstInitAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConstInitAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ConstInitAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONST_INIT;
  }

  static std::optional<ConstInitAttr> from(const TokenContext &c);
  static std::optional<ConstInitAttr> from(const InheritableAttr &parent);

  inline static std::optional<ConstInitAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ConstInitAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstInitAttr> from(const Attr &parent);

  inline static std::optional<ConstInitAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ConstInitAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ConstInitAttrSpelling semantic_spelling(void) const;
  bool is_constinit(void) const;
};

static_assert(sizeof(ConstInitAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
