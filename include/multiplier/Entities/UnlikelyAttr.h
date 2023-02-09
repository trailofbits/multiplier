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
#include "StmtAttr.h"

namespace mx {
class Attr;
class StmtAttr;
class UnlikelyAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnlikelyAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<UnlikelyAttr> in(const Fragment &frag);
  static gap::generator<UnlikelyAttr> in(const Index &index);
  static gap::generator<UnlikelyAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnlikelyAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::UNLIKELY;
  }

  inline static std::optional<UnlikelyAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<UnlikelyAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<UnlikelyAttr> from(const StmtAttr &parent);

  inline static std::optional<UnlikelyAttr> from(const std::optional<StmtAttr> &parent) {
    if (parent) {
      return UnlikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnlikelyAttr> from(const Attr &parent);

  inline static std::optional<UnlikelyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return UnlikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(UnlikelyAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
