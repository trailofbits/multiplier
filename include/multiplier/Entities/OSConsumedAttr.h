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
#include "InheritableParamAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class OSConsumedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OSConsumedAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OSConsumedAttr> in(const Fragment &frag);
  static gap::generator<OSConsumedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OS_CONSUMED;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<OSConsumedAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<OSConsumedAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<OSConsumedAttr> from(const InheritableParamAttr &parent);

  inline static std::optional<OSConsumedAttr> from(const std::optional<InheritableParamAttr> &parent) {
    if (parent) {
      return OSConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OSConsumedAttr> from(const InheritableAttr &parent);

  inline static std::optional<OSConsumedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return OSConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OSConsumedAttr> from(const Attr &parent);

  inline static std::optional<OSConsumedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OSConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OSConsumedAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
