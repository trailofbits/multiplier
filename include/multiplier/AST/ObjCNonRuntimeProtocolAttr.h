// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class ObjCNonRuntimeProtocolAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCNonRuntimeProtocolAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCNonRuntimeProtocolAttr> in(const Index &index);
  static gap::generator<ObjCNonRuntimeProtocolAttr> in(const Fragment &frag);
  static gap::generator<ObjCNonRuntimeProtocolAttr> in(const File &file);
  static gap::generator<ObjCNonRuntimeProtocolAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_NON_RUNTIME_PROTOCOL;
  }

  static std::optional<ObjCNonRuntimeProtocolAttr> by_id(const Index &, EntityId);

  static std::optional<ObjCNonRuntimeProtocolAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCNonRuntimeProtocolAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCNonRuntimeProtocolAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCNonRuntimeProtocolAttr> from(const Reference &r);
  static std::optional<ObjCNonRuntimeProtocolAttr> from(const VariantEntity &e);
  static std::optional<ObjCNonRuntimeProtocolAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCNonRuntimeProtocolAttr) == sizeof(Attr));

#endif
} // namespace mx
