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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class ObjCDirectMembersAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCDirectMembersAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCDirectMembersAttr> in(const Fragment &frag);
  static gap::generator<ObjCDirectMembersAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_DIRECT_MEMBERS;
  }

  inline static std::optional<ObjCDirectMembersAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<ObjCDirectMembersAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<ObjCDirectMembersAttr> from(const Attr &parent);

  inline static std::optional<ObjCDirectMembersAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCDirectMembersAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(ObjCDirectMembersAttr) == sizeof(Attr));

#endif
} // namespace mx
