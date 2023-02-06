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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AcquireCapabilityAttrSpelling.h"
#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AcquireCapabilityAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AcquireCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AcquireCapabilityAttr> in(const Fragment &frag);
  static gap::generator<AcquireCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRE_CAPABILITY;
  }

  inline static std::optional<AcquireCapabilityAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AcquireCapabilityAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AcquireCapabilityAttr> from(const InheritableAttr &parent);

  inline static std::optional<AcquireCapabilityAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AcquireCapabilityAttr> from(const Attr &parent);

  inline static std::optional<AcquireCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  AcquireCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AcquireCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
