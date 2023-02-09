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
#include "TypeAttr.h"

namespace mx {
class Attr;
class NoDerefAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoDerefAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<NoDerefAttr> in(const Fragment &frag);
  static gap::generator<NoDerefAttr> in(const Index &index);
  static gap::generator<NoDerefAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<NoDerefAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_DEREF;
  }

  inline static std::optional<NoDerefAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<NoDerefAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<NoDerefAttr> from(const TypeAttr &parent);

  inline static std::optional<NoDerefAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return NoDerefAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoDerefAttr> from(const Attr &parent);

  inline static std::optional<NoDerefAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoDerefAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(NoDerefAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
