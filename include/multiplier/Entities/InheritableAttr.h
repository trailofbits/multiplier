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
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InheritableAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<InheritableAttr> in(const Fragment &frag);
  static gap::generator<InheritableAttr> in(const File &file);
  static gap::generator<InheritableAttr> in(const Index &index);
  static gap::generator<InheritableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InheritableAttr> by_id(const Index &, EntityId);

  static std::optional<InheritableAttr> from(const Attr &parent);

  inline static std::optional<InheritableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return InheritableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<InheritableAttr> from(const Reference &r) {
    return InheritableAttr::from(r.as_attribute());
  }

  inline static std::optional<InheritableAttr> from(const TokenContext &t) {
    return InheritableAttr::from(t.as_attribute());
  }

  bool should_inherit_even_if_already_present(void) const;
};

static_assert(sizeof(InheritableAttr) == sizeof(Attr));

#endif
} // namespace mx
