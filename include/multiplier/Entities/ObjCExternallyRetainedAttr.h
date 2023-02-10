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
class ObjCExternallyRetainedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCExternallyRetainedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCExternallyRetainedAttr> in(const Fragment &frag);
  static gap::generator<ObjCExternallyRetainedAttr> in(const File &file);
  static gap::generator<ObjCExternallyRetainedAttr> in(const Index &index);
  static gap::generator<ObjCExternallyRetainedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCExternallyRetainedAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_EXTERNALLY_RETAINED;
  }

  static std::optional<ObjCExternallyRetainedAttr> from(const Attr &parent);

  inline static std::optional<ObjCExternallyRetainedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCExternallyRetainedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCExternallyRetainedAttr> from(const Reference &r) {
    return ObjCExternallyRetainedAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCExternallyRetainedAttr> from(const TokenContext &t) {
    return ObjCExternallyRetainedAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCExternallyRetainedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
