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
#include "MSVtorDispMode.h"

namespace mx {
class Attr;
class InheritableAttr;
class MSVtorDispAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSVtorDispAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MSVtorDispAttr> in(const Fragment &frag);
  static gap::generator<MSVtorDispAttr> in(const File &file);
  static gap::generator<MSVtorDispAttr> in(const Index &index);
  static gap::generator<MSVtorDispAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSVtorDispAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MS_VTOR_DISP;
  }

  static std::optional<MSVtorDispAttr> from(const Attr &parent);

  inline static std::optional<MSVtorDispAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return MSVtorDispAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<MSVtorDispAttr> from(const Reference &r) {
    return MSVtorDispAttr::from(r.as_attribute());
  }

  inline static std::optional<MSVtorDispAttr> from(const TokenContext &t) {
    return MSVtorDispAttr::from(t.as_attribute());
  }

  MSVtorDispMode vtor_disp_mode(void) const;
};

static_assert(sizeof(MSVtorDispAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
