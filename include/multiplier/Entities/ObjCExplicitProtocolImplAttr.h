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
class ObjCExplicitProtocolImplAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCExplicitProtocolImplAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCExplicitProtocolImplAttr> in(const Fragment &frag);
  static gap::generator<ObjCExplicitProtocolImplAttr> in(const File &file);
  static gap::generator<ObjCExplicitProtocolImplAttr> in(const Index &index);
  static gap::generator<ObjCExplicitProtocolImplAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCExplicitProtocolImplAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_EXPLICIT_PROTOCOL_IMPL;
  }

  static std::optional<ObjCExplicitProtocolImplAttr> from(const Attr &parent);

  inline static std::optional<ObjCExplicitProtocolImplAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCExplicitProtocolImplAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCExplicitProtocolImplAttr> from(const Reference &r) {
    return ObjCExplicitProtocolImplAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCExplicitProtocolImplAttr> from(const TokenContext &t) {
    return ObjCExplicitProtocolImplAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCExplicitProtocolImplAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
