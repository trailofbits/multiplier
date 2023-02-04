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
class AssumeAlignedAttr;
class Attr;
class Expr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AssumeAlignedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AssumeAlignedAttr> in(const Fragment &frag);
  static gap::generator<AssumeAlignedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSUME_ALIGNED;
  }

  inline static std::optional<AssumeAlignedAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AssumeAlignedAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AssumeAlignedAttr> from(const InheritableAttr &parent);

  inline static std::optional<AssumeAlignedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AssumeAlignedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssumeAlignedAttr> from(const Attr &parent);

  inline static std::optional<AssumeAlignedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssumeAlignedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr alignment(void) const;
  std::optional<Expr> offset(void) const;
};

static_assert(sizeof(AssumeAlignedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
