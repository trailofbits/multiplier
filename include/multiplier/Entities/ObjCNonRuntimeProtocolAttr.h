// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class ObjCNonRuntimeProtocolAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

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

  static std::optional<ObjCNonRuntimeProtocolAttr> from(const Reference &r);
  static std::optional<ObjCNonRuntimeProtocolAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCNonRuntimeProtocolAttr) == sizeof(Attr));

#endif
} // namespace mx
