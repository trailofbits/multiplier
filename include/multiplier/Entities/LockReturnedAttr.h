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
class Expr;
class InheritableAttr;
class LockReturnedAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LockReturnedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<LockReturnedAttr> in(const Fragment &frag);
  static gap::generator<LockReturnedAttr> in(const File &file);
  static gap::generator<LockReturnedAttr> in(const Index &index);
  static gap::generator<LockReturnedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LockReturnedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOCK_RETURNED;
  }

  static std::optional<LockReturnedAttr> from(const Attr &parent);

  inline static std::optional<LockReturnedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LockReturnedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<LockReturnedAttr> from(const Reference &r) {
    return LockReturnedAttr::from(r.as_attribute());
  }

  inline static std::optional<LockReturnedAttr> from(const TokenContext &t) {
    return LockReturnedAttr::from(t.as_attribute());
  }

  Expr argument(void) const;
};

static_assert(sizeof(LockReturnedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
