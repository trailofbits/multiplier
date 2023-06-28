// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ObjCObjectType.h"

namespace mx {
class EntityProvider;
class Index;
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCObjectType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCInterfaceType : public ObjCObjectType {
 private:
  friend class FragmentImpl;
  friend class ObjCObjectType;
  friend class Type;
 public:
  static gap::generator<ObjCInterfaceType> in(const Fragment &frag);
  static gap::generator<ObjCInterfaceType> in(const File &file);
  static gap::generator<ObjCInterfaceType> in(const Index &index);
  static gap::generator<ObjCInterfaceType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCInterfaceType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_INTERFACE;
  }

  static std::optional<ObjCInterfaceType> from(const Type &parent);

  inline static std::optional<ObjCInterfaceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ObjCInterfaceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCInterfaceType> from(const Reference &r);
  static std::optional<ObjCInterfaceType> from(const TokenContext &t);

  ObjCInterfaceDecl declaration(void) const;
};

static_assert(sizeof(ObjCInterfaceType) == sizeof(ObjCObjectType));

#endif
} // namespace mx
