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
#include "CFGuardAttrGuardArg.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class CFGuardAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CFGuardAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CFGuardAttr> in(const Fragment &frag);
  static gap::generator<CFGuardAttr> in(const File &file);
  static gap::generator<CFGuardAttr> in(const Index &index);
  static gap::generator<CFGuardAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CFGuardAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CF_GUARD;
  }

  static std::optional<CFGuardAttr> from(const Attr &parent);

  inline static std::optional<CFGuardAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CFGuardAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CFGuardAttr> from(const Reference &r) {
    return CFGuardAttr::from(r.as_attribute());
  }

  inline static std::optional<CFGuardAttr> from(const TokenContext &t) {
    return CFGuardAttr::from(t.as_attribute());
  }

  CFGuardAttrGuardArg guard(void) const;
};

static_assert(sizeof(CFGuardAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
