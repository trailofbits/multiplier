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
class Attr;
class InheritableAttr;
class ObjCBridgeAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCBridgeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCBridgeAttr> in(const Fragment &frag);
  static gap::generator<ObjCBridgeAttr> in(const File &file);
  static gap::generator<ObjCBridgeAttr> in(const Index &index);
  static gap::generator<ObjCBridgeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCBridgeAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_BRIDGE;
  }

  static std::optional<ObjCBridgeAttr> from(const Attr &parent);

  inline static std::optional<ObjCBridgeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCBridgeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCBridgeAttr> from(const Reference &r) {
    return ObjCBridgeAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCBridgeAttr> from(const TokenContext &t) {
    return ObjCBridgeAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCBridgeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
