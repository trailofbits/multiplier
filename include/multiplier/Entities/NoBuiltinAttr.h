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
class NoBuiltinAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoBuiltinAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<NoBuiltinAttr> in(const Fragment &frag);
  static gap::generator<NoBuiltinAttr> in(const File &file);
  static gap::generator<NoBuiltinAttr> in(const Index &index);
  static gap::generator<NoBuiltinAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoBuiltinAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_BUILTIN;
  }

  static std::optional<NoBuiltinAttr> from(const Attr &parent);

  inline static std::optional<NoBuiltinAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoBuiltinAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<NoBuiltinAttr> from(const Reference &r) {
    return NoBuiltinAttr::from(r.as_attribute());
  }

  inline static std::optional<NoBuiltinAttr> from(const TokenContext &t) {
    return NoBuiltinAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(NoBuiltinAttr) == sizeof(Attr));

#endif
} // namespace mx
