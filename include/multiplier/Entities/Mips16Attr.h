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
class InheritableAttr;
class Mips16Attr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Mips16Attr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<Mips16Attr> in(const Fragment &frag);
  static gap::generator<Mips16Attr> in(const File &file);
  static gap::generator<Mips16Attr> in(const Index &index);
  static gap::generator<Mips16Attr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Mips16Attr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MIPS16;
  }

  static std::optional<Mips16Attr> from(const Attr &parent);

  inline static std::optional<Mips16Attr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return Mips16Attr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<Mips16Attr> from(const Reference &r) {
    return Mips16Attr::from(r.as_attribute());
  }

  inline static std::optional<Mips16Attr> from(const TokenContext &t) {
    return Mips16Attr::from(t.as_attribute());
  }

};

static_assert(sizeof(Mips16Attr) == sizeof(InheritableAttr));

#endif
} // namespace mx
