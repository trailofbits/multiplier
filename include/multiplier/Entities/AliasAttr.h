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
class AliasAttr;
class Attr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AliasAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<AliasAttr> in(const Fragment &frag);
  static gap::generator<AliasAttr> in(const File &file);
  static gap::generator<AliasAttr> in(const Index &index);
  static gap::generator<AliasAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AliasAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIAS;
  }

  static std::optional<AliasAttr> from(const Attr &parent);

  inline static std::optional<AliasAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AliasAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AliasAttr> from(const Reference &r) {
    return AliasAttr::from(r.as_attribute());
  }

  inline static std::optional<AliasAttr> from(const TokenContext &t) {
    return AliasAttr::from(t.as_attribute());
  }

  std::string_view aliasee(void) const;
};

static_assert(sizeof(AliasAttr) == sizeof(Attr));

#endif
} // namespace mx
