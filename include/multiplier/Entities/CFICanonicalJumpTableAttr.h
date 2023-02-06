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
class CFICanonicalJumpTableAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CFICanonicalJumpTableAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CFICanonicalJumpTableAttr> in(const Fragment &frag);
  static gap::generator<CFICanonicalJumpTableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CFI_CANONICAL_JUMP_TABLE;
  }

  inline static std::optional<CFICanonicalJumpTableAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<CFICanonicalJumpTableAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<CFICanonicalJumpTableAttr> from(const InheritableAttr &parent);

  inline static std::optional<CFICanonicalJumpTableAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CFICanonicalJumpTableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CFICanonicalJumpTableAttr> from(const Attr &parent);

  inline static std::optional<CFICanonicalJumpTableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CFICanonicalJumpTableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CFICanonicalJumpTableAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
