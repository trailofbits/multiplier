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

namespace mx {
class Attr;
class InitSegAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InitSegAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<InitSegAttr> in(const Fragment &frag);
  static gap::generator<InitSegAttr> in(const File &file);
  static gap::generator<InitSegAttr> in(const Index &index);
  static gap::generator<InitSegAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InitSegAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::INIT_SEG;
  }

  static std::optional<InitSegAttr> from(const Attr &parent);

  inline static std::optional<InitSegAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return InitSegAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<InitSegAttr> from(const Reference &r) {
    return InitSegAttr::from(r.as_attribute());
  }

  inline static std::optional<InitSegAttr> from(const TokenContext &t) {
    return InitSegAttr::from(t.as_attribute());
  }

  std::string_view section(void) const;
};

static_assert(sizeof(InitSegAttr) == sizeof(Attr));

#endif
} // namespace mx
