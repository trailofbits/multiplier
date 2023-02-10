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
class Attr;
class Expr;
class InheritableAttr;
class SharedTrylockFunctionAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SharedTrylockFunctionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SharedTrylockFunctionAttr> in(const Fragment &frag);
  static gap::generator<SharedTrylockFunctionAttr> in(const File &file);
  static gap::generator<SharedTrylockFunctionAttr> in(const Index &index);
  static gap::generator<SharedTrylockFunctionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SharedTrylockFunctionAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SHARED_TRYLOCK_FUNCTION;
  }

  static std::optional<SharedTrylockFunctionAttr> from(const Attr &parent);

  inline static std::optional<SharedTrylockFunctionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SharedTrylockFunctionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SharedTrylockFunctionAttr> from(const Reference &r) {
    return SharedTrylockFunctionAttr::from(r.as_attribute());
  }

  inline static std::optional<SharedTrylockFunctionAttr> from(const TokenContext &t) {
    return SharedTrylockFunctionAttr::from(t.as_attribute());
  }

  Expr success_value(void) const;
};

static_assert(sizeof(SharedTrylockFunctionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
