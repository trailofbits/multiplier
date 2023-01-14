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

#include "AssertCapabilityAttrSpelling.h"
#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AssertCapabilityAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AssertCapabilityAttrRange = DerivedEntityRange<AttrIterator, AssertCapabilityAttr>;
using AssertCapabilityAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AssertCapabilityAttr>;
class AssertCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AssertCapabilityAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AssertCapabilityAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AssertCapabilityAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSERT_CAPABILITY;
  }

  static std::optional<AssertCapabilityAttr> from(const TokenContext &c);
  static std::optional<AssertCapabilityAttr> from(const InheritableAttr &parent);

  inline static std::optional<AssertCapabilityAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AssertCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssertCapabilityAttr> from(const Attr &parent);

  inline static std::optional<AssertCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssertCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  AssertCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AssertCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
