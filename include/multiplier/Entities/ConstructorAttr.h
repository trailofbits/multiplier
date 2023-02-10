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
class ConstructorAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConstructorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ConstructorAttr> in(const Fragment &frag);
  static gap::generator<ConstructorAttr> in(const File &file);
  static gap::generator<ConstructorAttr> in(const Index &index);
  static gap::generator<ConstructorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConstructorAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CONSTRUCTOR;
  }

  static std::optional<ConstructorAttr> from(const Attr &parent);

  inline static std::optional<ConstructorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ConstructorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ConstructorAttr> from(const Reference &r) {
    return ConstructorAttr::from(r.as_attribute());
  }

  inline static std::optional<ConstructorAttr> from(const TokenContext &t) {
    return ConstructorAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ConstructorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
