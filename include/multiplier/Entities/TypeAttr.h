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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<TypeAttr> in(const Fragment &frag);
  static gap::generator<TypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<TypeAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<TypeAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<TypeAttr> from(const Attr &parent);

  inline static std::optional<TypeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(TypeAttr) == sizeof(Attr));

#endif
} // namespace mx
