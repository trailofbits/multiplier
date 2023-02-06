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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class AlignValueAttr;
class Attr;
class Expr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlignValueAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<AlignValueAttr> in(const Fragment &frag);
  static gap::generator<AlignValueAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGN_VALUE;
  }

  inline static std::optional<AlignValueAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AlignValueAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AlignValueAttr> from(const Attr &parent);

  inline static std::optional<AlignValueAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignValueAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr alignment(void) const;
};

static_assert(sizeof(AlignValueAttr) == sizeof(Attr));

#endif
} // namespace mx
