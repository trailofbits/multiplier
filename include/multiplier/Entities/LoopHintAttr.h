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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
class LoopHintAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<LoopHintAttr> in(const Fragment &frag);
  static gap::generator<LoopHintAttr> in(const Index &index);
  static gap::generator<LoopHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LoopHintAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOOP_HINT;
  }

  inline static std::optional<LoopHintAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<LoopHintAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

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
