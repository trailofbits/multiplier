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
class NoReturnAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoReturnAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoReturnAttr> in(const Fragment &frag);
  static gap::generator<NoReturnAttr> in(const Index &index);
  static gap::generator<NoReturnAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<NoReturnAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_RETURN;
  }

  inline static std::optional<NoReturnAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<NoReturnAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<NoReturnAttr> from(const InheritableAttr &parent);

  inline static std::optional<NoReturnAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoReturnAttr> from(const Attr &parent);

  inline static std::optional<NoReturnAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(NoReturnAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
