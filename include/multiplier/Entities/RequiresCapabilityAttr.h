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
#include "RequiresCapabilityAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class RequiresCapabilityAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RequiresCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<RequiresCapabilityAttr> in(const Fragment &frag);
  static gap::generator<RequiresCapabilityAttr> in(const File &file);
  static gap::generator<RequiresCapabilityAttr> in(const Index &index);
  static gap::generator<RequiresCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RequiresCapabilityAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::REQUIRES_CAPABILITY;
  }

  static std::optional<RequiresCapabilityAttr> from(const Attr &parent);

  inline static std::optional<RequiresCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return RequiresCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<RequiresCapabilityAttr> from(const Reference &r) {
    return RequiresCapabilityAttr::from(r.as_attribute());
  }

  inline static std::optional<RequiresCapabilityAttr> from(const TokenContext &t) {
    return RequiresCapabilityAttr::from(t.as_attribute());
  }

  RequiresCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(RequiresCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
