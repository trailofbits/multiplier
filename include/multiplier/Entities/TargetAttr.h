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
class InheritableAttr;
class TargetAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TargetAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<TargetAttr> in(const Fragment &frag);
  static gap::generator<TargetAttr> in(const File &file);
  static gap::generator<TargetAttr> in(const Index &index);
  static gap::generator<TargetAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TargetAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TARGET;
  }

  static std::optional<TargetAttr> from(const Attr &parent);

  inline static std::optional<TargetAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TargetAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<TargetAttr> from(const Reference &r) {
    return TargetAttr::from(r.as_attribute());
  }

  inline static std::optional<TargetAttr> from(const TokenContext &t) {
    return TargetAttr::from(t.as_attribute());
  }

  std::string_view architecture(void) const;
  std::string_view features_string(void) const;
  bool is_default_version(void) const;
};

static_assert(sizeof(TargetAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
