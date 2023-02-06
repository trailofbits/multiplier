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
class Attr;
class CalledOnceAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CalledOnceAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<CalledOnceAttr> in(const Fragment &frag);
  static gap::generator<CalledOnceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CALLED_ONCE;
  }

  inline static std::optional<CalledOnceAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<CalledOnceAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<CalledOnceAttr> from(const Attr &parent);

  inline static std::optional<CalledOnceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CalledOnceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CalledOnceAttr) == sizeof(Attr));

#endif
} // namespace mx
