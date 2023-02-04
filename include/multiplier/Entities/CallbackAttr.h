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
class Attr;
class CallbackAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CallbackAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CallbackAttr> in(const Fragment &frag);
  static gap::generator<CallbackAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CALLBACK;
  }

  inline static std::optional<CallbackAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<CallbackAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<CallbackAttr> from(const InheritableAttr &parent);

  inline static std::optional<CallbackAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CallbackAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CallbackAttr> from(const Attr &parent);

  inline static std::optional<CallbackAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CallbackAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CallbackAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
