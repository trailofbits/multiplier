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

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AnyX86InterruptAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnyX86InterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AnyX86InterruptAttr> in(const Fragment &frag);
  static gap::generator<AnyX86InterruptAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANY_X86_INTERRUPT;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<AnyX86InterruptAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AnyX86InterruptAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AnyX86InterruptAttr> from(const InheritableAttr &parent);

  inline static std::optional<AnyX86InterruptAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AnyX86InterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AnyX86InterruptAttr> from(const Attr &parent);

  inline static std::optional<AnyX86InterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AnyX86InterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(AnyX86InterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
