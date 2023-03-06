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

#include "TypeAttr.h"

namespace mx {
class Attr;
class ObjCKindOfAttr;
class Token;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCKindOfAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCKindOfAttr> in(const Fragment &frag);
  static gap::generator<ObjCKindOfAttr> in(const File &file);
  static gap::generator<ObjCKindOfAttr> in(const Index &index);
  static gap::generator<ObjCKindOfAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCKindOfAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_KIND_OF;
  }

  static std::optional<ObjCKindOfAttr> from(const Attr &parent);

  inline static std::optional<ObjCKindOfAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCKindOfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCKindOfAttr> from(const Reference &r) {
    return ObjCKindOfAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCKindOfAttr> from(const TokenContext &t) {
    return ObjCKindOfAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCKindOfAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
