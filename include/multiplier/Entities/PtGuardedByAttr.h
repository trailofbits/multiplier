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
class Expr;
class InheritableAttr;
class PtGuardedByAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PtGuardedByAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PtGuardedByAttr> in(const Fragment &frag);
  static gap::generator<PtGuardedByAttr> in(const File &file);
  static gap::generator<PtGuardedByAttr> in(const Index &index);
  static gap::generator<PtGuardedByAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PtGuardedByAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PT_GUARDED_BY;
  }

  static std::optional<PtGuardedByAttr> from(const Attr &parent);

  inline static std::optional<PtGuardedByAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return PtGuardedByAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<PtGuardedByAttr> from(const Reference &r) {
    return PtGuardedByAttr::from(r.as_attribute());
  }

  inline static std::optional<PtGuardedByAttr> from(const TokenContext &t) {
    return PtGuardedByAttr::from(t.as_attribute());
  }

  Expr argument(void) const;
};

static_assert(sizeof(PtGuardedByAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
