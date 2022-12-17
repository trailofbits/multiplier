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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "ObjCObjectType.h"
#include "TypeKind.h"

namespace mx {
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCObjectType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCInterfaceTypeRange = DerivedEntityRange<TypeIterator, ObjCInterfaceType>;
using ObjCInterfaceTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCInterfaceType>;
class ObjCInterfaceType : public ObjCObjectType {
 private:
  friend class FragmentImpl;
  friend class ObjCObjectType;
  friend class Type;
 public:
  inline static ObjCInterfaceTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCInterfaceTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ObjCInterfaceType::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_INTERFACE;
  }

  static std::optional<ObjCInterfaceType> from(const TokenContext &c);
  static std::optional<ObjCInterfaceType> from(const ObjCObjectType &parent);

  inline static std::optional<ObjCInterfaceType> from(const std::optional<ObjCObjectType> &parent) {
    if (parent) {
      return ObjCInterfaceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCInterfaceType> from(const Type &parent);

  inline static std::optional<ObjCInterfaceType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ObjCInterfaceType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ObjCInterfaceDecl declaration(void) const;
};

static_assert(sizeof(ObjCInterfaceType) == sizeof(ObjCObjectType));

#endif
} // namespace mx
