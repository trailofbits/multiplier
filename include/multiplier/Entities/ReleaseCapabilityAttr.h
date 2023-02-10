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

#include "AttrKind.h"
#include "InheritableAttr.h"
#include "ReleaseCapabilityAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class ReleaseCapabilityAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ReleaseCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ReleaseCapabilityAttr> in(const Fragment &frag);
  static gap::generator<ReleaseCapabilityAttr> in(const File &file);
  static gap::generator<ReleaseCapabilityAttr> in(const Index &index);
  static gap::generator<ReleaseCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ReleaseCapabilityAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RELEASE_CAPABILITY;
  }

  static std::optional<ReleaseCapabilityAttr> from(const Attr &parent);

  inline static std::optional<ReleaseCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ReleaseCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ReleaseCapabilityAttr> from(const Reference &r) {
    return ReleaseCapabilityAttr::from(r.as_attribute());
  }

  inline static std::optional<ReleaseCapabilityAttr> from(const TokenContext &t) {
    return ReleaseCapabilityAttr::from(t.as_attribute());
  }

  ReleaseCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_generic(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(ReleaseCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
