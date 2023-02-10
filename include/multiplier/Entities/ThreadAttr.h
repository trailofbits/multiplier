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

namespace mx {
class Attr;
class ThreadAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ThreadAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ThreadAttr> in(const Fragment &frag);
  static gap::generator<ThreadAttr> in(const File &file);
  static gap::generator<ThreadAttr> in(const Index &index);
  static gap::generator<ThreadAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ThreadAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::THREAD;
  }

  static std::optional<ThreadAttr> from(const Attr &parent);

  inline static std::optional<ThreadAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ThreadAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ThreadAttr> from(const Reference &r) {
    return ThreadAttr::from(r.as_attribute());
  }

  inline static std::optional<ThreadAttr> from(const TokenContext &t) {
    return ThreadAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ThreadAttr) == sizeof(Attr));

#endif
} // namespace mx
