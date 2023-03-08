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

#include "Attr.h"

namespace mx {
class AlignValueAttr;
class Attr;
class Expr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlignValueAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<AlignValueAttr> in(const Fragment &frag);
  static gap::generator<AlignValueAttr> in(const File &file);
  static gap::generator<AlignValueAttr> in(const Index &index);
  static gap::generator<AlignValueAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AlignValueAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGN_VALUE;
  }

  static std::optional<AlignValueAttr> from(const Attr &parent);

  inline static std::optional<AlignValueAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignValueAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AlignValueAttr> from(const Reference &r) {
    return AlignValueAttr::from(r.as_attribute());
  }

  inline static std::optional<AlignValueAttr> from(const TokenContext &t) {
    return AlignValueAttr::from(t.as_attribute());
  }

  Expr alignment(void) const;
};

static_assert(sizeof(AlignValueAttr) == sizeof(Attr));

#endif
} // namespace mx
