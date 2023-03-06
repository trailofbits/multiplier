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

#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class PreferredNameAttr;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PreferredNameAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PreferredNameAttr> in(const Fragment &frag);
  static gap::generator<PreferredNameAttr> in(const File &file);
  static gap::generator<PreferredNameAttr> in(const Index &index);
  static gap::generator<PreferredNameAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PreferredNameAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PREFERRED_NAME;
  }

  static std::optional<PreferredNameAttr> from(const Attr &parent);

  inline static std::optional<PreferredNameAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PreferredNameAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<PreferredNameAttr> from(const Reference &r) {
    return PreferredNameAttr::from(r.as_attribute());
  }

  inline static std::optional<PreferredNameAttr> from(const TokenContext &t) {
    return PreferredNameAttr::from(t.as_attribute());
  }

  Type typedef_type(void) const;
  Type typedef_type_token(void) const;
};

static_assert(sizeof(PreferredNameAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
