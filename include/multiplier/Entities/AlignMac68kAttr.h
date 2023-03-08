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
class AlignMac68kAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlignMac68kAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AlignMac68kAttr> in(const Fragment &frag);
  static gap::generator<AlignMac68kAttr> in(const File &file);
  static gap::generator<AlignMac68kAttr> in(const Index &index);
  static gap::generator<AlignMac68kAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AlignMac68kAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGN_MAC68K;
  }

  static std::optional<AlignMac68kAttr> from(const Attr &parent);

  inline static std::optional<AlignMac68kAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignMac68kAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AlignMac68kAttr> from(const Reference &r) {
    return AlignMac68kAttr::from(r.as_attribute());
  }

  inline static std::optional<AlignMac68kAttr> from(const TokenContext &t) {
    return AlignMac68kAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(AlignMac68kAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
