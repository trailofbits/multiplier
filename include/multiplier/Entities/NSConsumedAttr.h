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
#include "InheritableParamAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class NSConsumedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NSConsumedAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NSConsumedAttr> in(const Fragment &frag);
  static gap::generator<NSConsumedAttr> in(const File &file);
  static gap::generator<NSConsumedAttr> in(const Index &index);
  static gap::generator<NSConsumedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NSConsumedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_CONSUMED;
  }

  static std::optional<NSConsumedAttr> from(const Attr &parent);

  inline static std::optional<NSConsumedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NSConsumedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<NSConsumedAttr> from(const Reference &r) {
    return NSConsumedAttr::from(r.as_attribute());
  }

  inline static std::optional<NSConsumedAttr> from(const TokenContext &t) {
    return NSConsumedAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(NSConsumedAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
