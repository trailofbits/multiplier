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
class ObjCClassStubAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCClassStubAttrRange = DerivedEntityRange<AttrIterator, ObjCClassStubAttr>;
using ObjCClassStubAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCClassStubAttr>;
class ObjCClassStubAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static ObjCClassStubAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCClassStubAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCClassStubAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_CLASS_STUB;
  }

  static std::optional<ObjCClassStubAttr> from(const TokenContext &c);
  static std::optional<ObjCClassStubAttr> from(const Attr &parent);

  inline static std::optional<ObjCClassStubAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCClassStubAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCClassStubAttr) == sizeof(Attr));

#endif
} // namespace mx
