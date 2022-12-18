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

namespace mx {
class Attr;
class ThreadAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ThreadAttrRange = DerivedEntityRange<AttrIterator, ThreadAttr>;
using ThreadAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ThreadAttr>;
class ThreadAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static ThreadAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ThreadAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ThreadAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::THREAD;
  }

  static std::optional<ThreadAttr> from(const TokenContext &c);
  static std::optional<ThreadAttr> from(const Attr &parent);

  inline static std::optional<ThreadAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ThreadAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ThreadAttr) == sizeof(Attr));

#endif
} // namespace mx
