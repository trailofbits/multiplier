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
#include "BuiltinAliasAttrSpelling.h"

namespace mx {
class Attr;
class BuiltinAliasAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BuiltinAliasAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<BuiltinAliasAttr> in(const Fragment &frag);
  static gap::generator<BuiltinAliasAttr> in(const Index &index);
  static gap::generator<BuiltinAliasAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<BuiltinAliasAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BUILTIN_ALIAS;
  }

  inline static std::optional<BuiltinAliasAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<BuiltinAliasAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<BuiltinAliasAttr> from(const Attr &parent);

  inline static std::optional<BuiltinAliasAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BuiltinAliasAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  BuiltinAliasAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(BuiltinAliasAttr) == sizeof(Attr));

#endif
} // namespace mx
