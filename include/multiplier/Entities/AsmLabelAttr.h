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

#include "InheritableAttr.h"

namespace mx {
class AsmLabelAttr;
class Attr;
class InheritableAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AsmLabelAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AsmLabelAttr> in(const Fragment &frag);
  static gap::generator<AsmLabelAttr> in(const File &file);
  static gap::generator<AsmLabelAttr> in(const Index &index);
  static gap::generator<AsmLabelAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AsmLabelAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ASM_LABEL;
  }

  static std::optional<AsmLabelAttr> from(const Attr &parent);

  inline static std::optional<AsmLabelAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AsmLabelAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<AsmLabelAttr> from(const Reference &r) {
    return AsmLabelAttr::from(r.as_attribute());
  }

  inline static std::optional<AsmLabelAttr> from(const TokenContext &t) {
    return AsmLabelAttr::from(t.as_attribute());
  }

  bool is_literal_label(void) const;
  std::string_view label(void) const;
};

static_assert(sizeof(AsmLabelAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
