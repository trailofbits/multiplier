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

#include "Attr.h"
#include "AttrKind.h"
#include "LoopHintAttrLoopHintState.h"
#include "LoopHintAttrOptionType.h"
#include "LoopHintAttrSpelling.h"

namespace mx {
class Attr;
class Expr;
class LoopHintAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using LoopHintAttrRange = DerivedEntityRange<AttrIterator, LoopHintAttr>;
using LoopHintAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, LoopHintAttr>;
class LoopHintAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static LoopHintAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LoopHintAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : LoopHintAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOOP_HINT;
  }

  static std::optional<LoopHintAttr> from(const TokenContext &c);
  static std::optional<LoopHintAttr> from(const Attr &parent);

  inline static std::optional<LoopHintAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LoopHintAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  LoopHintAttrOptionType option(void) const;
  LoopHintAttrSpelling semantic_spelling(void) const;
  LoopHintAttrLoopHintState state(void) const;
  Expr value(void) const;
};

static_assert(sizeof(LoopHintAttr) == sizeof(Attr));

#endif
} // namespace mx
