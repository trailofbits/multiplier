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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class ObjCNonRuntimeProtocolAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCNonRuntimeProtocolAttrRange = DerivedEntityRange<AttrIterator, ObjCNonRuntimeProtocolAttr>;
using ObjCNonRuntimeProtocolAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCNonRuntimeProtocolAttr>;
class ObjCNonRuntimeProtocolAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static ObjCNonRuntimeProtocolAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCNonRuntimeProtocolAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCNonRuntimeProtocolAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_NON_RUNTIME_PROTOCOL;
  }

  static std::optional<ObjCNonRuntimeProtocolAttr> from(const TokenContext &c);
  static std::optional<ObjCNonRuntimeProtocolAttr> from(const Attr &parent);

  inline static std::optional<ObjCNonRuntimeProtocolAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCNonRuntimeProtocolAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCNonRuntimeProtocolAttr) == sizeof(Attr));

#endif
} // namespace mx
