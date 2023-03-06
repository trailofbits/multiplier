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
class ThisCallAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ThisCallAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ThisCallAttr> in(const Fragment &frag);
  static gap::generator<ThisCallAttr> in(const File &file);
  static gap::generator<ThisCallAttr> in(const Index &index);
  static gap::generator<ThisCallAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ThisCallAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::THIS_CALL;
  }

  static std::optional<ThisCallAttr> from(const Attr &parent);

  inline static std::optional<ThisCallAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ThisCallAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ThisCallAttr> from(const Reference &r) {
    return ThisCallAttr::from(r.as_attribute());
  }

  inline static std::optional<ThisCallAttr> from(const TokenContext &t) {
    return ThisCallAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ThisCallAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
