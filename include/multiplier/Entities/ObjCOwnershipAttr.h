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
class ObjCOwnershipAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCOwnershipAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCOwnershipAttr> in(const Fragment &frag);
  static gap::generator<ObjCOwnershipAttr> in(const File &file);
  static gap::generator<ObjCOwnershipAttr> in(const Index &index);
  static gap::generator<ObjCOwnershipAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCOwnershipAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_OWNERSHIP;
  }

  static std::optional<ObjCOwnershipAttr> from(const Attr &parent);

  inline static std::optional<ObjCOwnershipAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCOwnershipAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCOwnershipAttr> from(const Reference &r) {
    return ObjCOwnershipAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCOwnershipAttr> from(const TokenContext &t) {
    return ObjCOwnershipAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCOwnershipAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
