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
class ObjCDesignatedInitializerAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCDesignatedInitializerAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCDesignatedInitializerAttr> in(const Fragment &frag);
  static gap::generator<ObjCDesignatedInitializerAttr> in(const File &file);
  static gap::generator<ObjCDesignatedInitializerAttr> in(const Index &index);
  static gap::generator<ObjCDesignatedInitializerAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCDesignatedInitializerAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_DESIGNATED_INITIALIZER;
  }

  static std::optional<ObjCDesignatedInitializerAttr> from(const Attr &parent);

  inline static std::optional<ObjCDesignatedInitializerAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCDesignatedInitializerAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCDesignatedInitializerAttr> from(const Reference &r) {
    return ObjCDesignatedInitializerAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCDesignatedInitializerAttr> from(const TokenContext &t) {
    return ObjCDesignatedInitializerAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCDesignatedInitializerAttr) == sizeof(Attr));

#endif
} // namespace mx
