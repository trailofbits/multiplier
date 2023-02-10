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
class ObjCNonRuntimeProtocolAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCNonRuntimeProtocolAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCNonRuntimeProtocolAttr> in(const Fragment &frag);
  static gap::generator<ObjCNonRuntimeProtocolAttr> in(const File &file);
  static gap::generator<ObjCNonRuntimeProtocolAttr> in(const Index &index);
  static gap::generator<ObjCNonRuntimeProtocolAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCNonRuntimeProtocolAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_NON_RUNTIME_PROTOCOL;
  }

  static std::optional<ObjCNonRuntimeProtocolAttr> from(const Attr &parent);

  inline static std::optional<ObjCNonRuntimeProtocolAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCNonRuntimeProtocolAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCNonRuntimeProtocolAttr> from(const Reference &r) {
    return ObjCNonRuntimeProtocolAttr::from(r.as_attribute());
  }

  inline static std::optional<ObjCNonRuntimeProtocolAttr> from(const TokenContext &t) {
    return ObjCNonRuntimeProtocolAttr::from(t.as_attribute());
  }

};

static_assert(sizeof(ObjCNonRuntimeProtocolAttr) == sizeof(Attr));

#endif
} // namespace mx
