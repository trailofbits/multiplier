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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class ObjCBridgeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCBridgeAttrRange = DerivedEntityRange<AttrIterator, ObjCBridgeAttr>;
using ObjCBridgeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCBridgeAttr>;
class ObjCBridgeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ObjCBridgeAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCBridgeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCBridgeAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_BRIDGE;
  }

  static std::optional<ObjCBridgeAttr> from(const TokenContext &c);
  static std::optional<ObjCBridgeAttr> from(const InheritableAttr &parent);

  inline static std::optional<ObjCBridgeAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ObjCBridgeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCBridgeAttr> from(const Attr &parent);

  inline static std::optional<ObjCBridgeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCBridgeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCBridgeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
