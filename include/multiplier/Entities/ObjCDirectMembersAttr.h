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

namespace mx {
class Attr;
class ObjCDirectMembersAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCDirectMembersAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCDirectMembersAttr> in(const Fragment &frag);
  static gap::generator<ObjCDirectMembersAttr> in(const File &file);
  static gap::generator<ObjCDirectMembersAttr> in(const Index &index);
  static gap::generator<ObjCDirectMembersAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCDirectMembersAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_DIRECT_MEMBERS;
  }

  static std::optional<ObjCDirectMembersAttr> from(const Attr &parent);

  inline static std::optional<ObjCDirectMembersAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCDirectMembersAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCDirectMembersAttr> from(const Reference &r) {
    return ObjCDirectMembersAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCDirectMembersAttr> from(const TokenContext &t) {
    return ObjCDirectMembersAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCDirectMembersAttr) == sizeof(Attr));

#endif
} // namespace mx
