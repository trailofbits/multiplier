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
#include "ZeroCallUsedRegsAttrZeroCallUsedRegsKind.h"

namespace mx {
class Attr;
class InheritableAttr;
class ZeroCallUsedRegsAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ZeroCallUsedRegsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ZeroCallUsedRegsAttr> in(const Fragment &frag);
  static gap::generator<ZeroCallUsedRegsAttr> in(const Index &index);
  static gap::generator<ZeroCallUsedRegsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ZeroCallUsedRegsAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ZERO_CALL_USED_REGS;
  }

  inline static std::optional<ZeroCallUsedRegsAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<ZeroCallUsedRegsAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<ZeroCallUsedRegsAttr> from(const InheritableAttr &parent);

  inline static std::optional<ZeroCallUsedRegsAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ZeroCallUsedRegsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ZeroCallUsedRegsAttr> from(const Attr &parent);

  inline static std::optional<ZeroCallUsedRegsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ZeroCallUsedRegsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ZeroCallUsedRegsAttrZeroCallUsedRegsKind zero_call_used_regs(void) const;
};

static_assert(sizeof(ZeroCallUsedRegsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
