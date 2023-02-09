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
class AssumptionAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AssumptionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AssumptionAttr> in(const Fragment &frag);
  static gap::generator<AssumptionAttr> in(const Index &index);
  static gap::generator<AssumptionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<AssumptionAttr> by(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASSUMPTION;
  }

  inline static std::optional<AssumptionAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AssumptionAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AssumptionAttr> from(const InheritableAttr &parent);

  inline static std::optional<AssumptionAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AssumptionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AssumptionAttr> from(const Attr &parent);

  inline static std::optional<AssumptionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AssumptionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view assumption(void) const;
};

static_assert(sizeof(AssumptionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
