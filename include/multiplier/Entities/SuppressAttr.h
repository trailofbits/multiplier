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
class StmtAttr;
class SuppressAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SuppressAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<SuppressAttr> in(const Fragment &frag);
  static gap::generator<SuppressAttr> in(const File &file);
  static gap::generator<SuppressAttr> in(const Index &index);
  static gap::generator<SuppressAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SuppressAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SUPPRESS;
  }

  static std::optional<SuppressAttr> from(const Attr &parent);

  inline static std::optional<SuppressAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SuppressAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SuppressAttr> from(const Reference &r) {
    return SuppressAttr::from(r.as_attribute());
  }

  inline static std::optional<SuppressAttr> from(const TokenContext &t) {
    return SuppressAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(SuppressAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
