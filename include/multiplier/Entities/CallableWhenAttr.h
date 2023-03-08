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
class CallableWhenAttr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CallableWhenAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CallableWhenAttr> in(const Fragment &frag);
  static gap::generator<CallableWhenAttr> in(const File &file);
  static gap::generator<CallableWhenAttr> in(const Index &index);
  static gap::generator<CallableWhenAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CallableWhenAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CALLABLE_WHEN;
  }

  static std::optional<CallableWhenAttr> from(const Attr &parent);

  inline static std::optional<CallableWhenAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CallableWhenAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CallableWhenAttr> from(const Reference &r) {
    return CallableWhenAttr::from(r.as_attribute());
  }

  inline static std::optional<CallableWhenAttr> from(const TokenContext &t) {
    return CallableWhenAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(CallableWhenAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
