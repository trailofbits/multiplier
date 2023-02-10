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
class AnyX86NoCfCheckAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AnyX86NoCfCheckAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AnyX86NoCfCheckAttr> in(const Fragment &frag);
  static gap::generator<AnyX86NoCfCheckAttr> in(const File &file);
  static gap::generator<AnyX86NoCfCheckAttr> in(const Index &index);
  static gap::generator<AnyX86NoCfCheckAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AnyX86NoCfCheckAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ANY_X86_NO_CF_CHECK;
  }

  static std::optional<AnyX86NoCfCheckAttr> from(const Attr &parent);

  inline static std::optional<AnyX86NoCfCheckAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AnyX86NoCfCheckAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AnyX86NoCfCheckAttr> from(const Reference &r) {
    return AnyX86NoCfCheckAttr::from(r.as_attribute());
  }

  inline static std::optional<AnyX86NoCfCheckAttr> from(const TokenContext &t) {
    return AnyX86NoCfCheckAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(AnyX86NoCfCheckAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
