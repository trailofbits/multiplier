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
#include "MSInheritanceAttrSpelling.h"
#include "MSInheritanceModel.h"

namespace mx {
class Attr;
class InheritableAttr;
class MSInheritanceAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSInheritanceAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MSInheritanceAttr> in(const Fragment &frag);
  static gap::generator<MSInheritanceAttr> in(const File &file);
  static gap::generator<MSInheritanceAttr> in(const Index &index);
  static gap::generator<MSInheritanceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSInheritanceAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MS_INHERITANCE;
  }

  static std::optional<MSInheritanceAttr> from(const Attr &parent);

  inline static std::optional<MSInheritanceAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MSInheritanceAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<MSInheritanceAttr> from(const Reference &r) {
    return MSInheritanceAttr::from(r.as_attribute());
  }

  inline static std::optional<MSInheritanceAttr> from(const TokenContext &t) {
    return MSInheritanceAttr::from(t.as_attribute());
  }

  bool best_case(void) const;
  MSInheritanceModel inheritance_model(void) const;
  MSInheritanceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(MSInheritanceAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
