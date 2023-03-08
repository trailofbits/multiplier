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

#include "StmtAttr.h"

namespace mx {
class Attr;
class LikelyAttr;
class StmtAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LikelyAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<LikelyAttr> in(const Fragment &frag);
  static gap::generator<LikelyAttr> in(const File &file);
  static gap::generator<LikelyAttr> in(const Index &index);
  static gap::generator<LikelyAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LikelyAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LIKELY;
  }

  static std::optional<LikelyAttr> from(const Attr &parent);

  inline static std::optional<LikelyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<LikelyAttr> from(const Reference &r) {
    return LikelyAttr::from(r.as_attribute());
  }

  inline static std::optional<LikelyAttr> from(const TokenContext &t) {
    return LikelyAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(LikelyAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
