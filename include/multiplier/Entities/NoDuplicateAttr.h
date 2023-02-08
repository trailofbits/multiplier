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
class Attr;
class InheritableAttr;
class NoDuplicateAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoDuplicateAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoDuplicateAttr> in(const Fragment &frag);
  static gap::generator<NoDuplicateAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_DUPLICATE;
  }

  static gap::generator<AttrKind> derived_kinds(void);
  inline static std::optional<NoDuplicateAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<NoDuplicateAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<NoDuplicateAttr> from(const InheritableAttr &parent);

  inline static std::optional<NoDuplicateAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NoDuplicateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoDuplicateAttr> from(const Attr &parent);

  inline static std::optional<NoDuplicateAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoDuplicateAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(NoDuplicateAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
