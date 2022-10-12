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
#include "MipsShortCallAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class MipsShortCallAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MipsShortCallAttrRange = DerivedEntityRange<AttrIterator, MipsShortCallAttr>;
using MipsShortCallAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, MipsShortCallAttr>;
class MipsShortCallAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static MipsShortCallAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MipsShortCallAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : MipsShortCallAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIPS_SHORT_CALL;
  }

  static std::optional<MipsShortCallAttr> from(const TokenContext &c);
  static std::optional<MipsShortCallAttr> from(const InheritableAttr &parent);

  inline static std::optional<MipsShortCallAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return MipsShortCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MipsShortCallAttr> from(const Attr &parent);

  inline static std::optional<MipsShortCallAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MipsShortCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  MipsShortCallAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(MipsShortCallAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
