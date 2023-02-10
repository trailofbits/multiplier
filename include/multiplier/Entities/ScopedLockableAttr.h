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

namespace mx {
class Attr;
class InheritableAttr;
class ScopedLockableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ScopedLockableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ScopedLockableAttr> in(const Fragment &frag);
  static gap::generator<ScopedLockableAttr> in(const File &file);
  static gap::generator<ScopedLockableAttr> in(const Index &index);
  static gap::generator<ScopedLockableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ScopedLockableAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SCOPED_LOCKABLE;
  }

  static std::optional<ScopedLockableAttr> from(const Attr &parent);

  inline static std::optional<ScopedLockableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ScopedLockableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ScopedLockableAttr> from(const Reference &r) {
    return ScopedLockableAttr::from(r.as_attribute());
  }

  inline static std::optional<ScopedLockableAttr> from(const TokenContext &t) {
    return ScopedLockableAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ScopedLockableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
