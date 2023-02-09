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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class ObjCClassStubAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCClassStubAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCClassStubAttr> in(const Fragment &frag);
  static gap::generator<ObjCClassStubAttr> in(const Index &index);
  static gap::generator<ObjCClassStubAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCClassStubAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_CLASS_STUB;
  }

  inline static std::optional<ObjCClassStubAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<ObjCClassStubAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<ObjCClassStubAttr> from(const Attr &parent);

  inline static std::optional<ObjCClassStubAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCClassStubAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ObjCClassStubAttr) == sizeof(Attr));

#endif
} // namespace mx
