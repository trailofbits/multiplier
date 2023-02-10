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
#include "TypeAttr.h"

namespace mx {
class Attr;
class ObjCGCAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCGCAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCGCAttr> in(const Fragment &frag);
  static gap::generator<ObjCGCAttr> in(const File &file);
  static gap::generator<ObjCGCAttr> in(const Index &index);
  static gap::generator<ObjCGCAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCGCAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_CGC;
  }

  static std::optional<ObjCGCAttr> from(const Attr &parent);

  inline static std::optional<ObjCGCAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCGCAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCGCAttr> from(const Reference &r) {
    return ObjCGCAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCGCAttr> from(const TokenContext &t) {
    return ObjCGCAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCGCAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
