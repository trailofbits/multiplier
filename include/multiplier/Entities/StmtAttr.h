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
#include "AttrKind.h"

namespace mx {
class Attr;
class StmtAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class StmtAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<StmtAttr> in(const Fragment &frag);
  static gap::generator<StmtAttr> in(const Index &index);
  static gap::generator<StmtAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<StmtAttr> by_id(const Index &, EntityId);

  inline static std::optional<StmtAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<StmtAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<StmtAttr> from(const Attr &parent);

  inline static std::optional<StmtAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return StmtAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(StmtAttr) == sizeof(Attr));

#endif
} // namespace mx
