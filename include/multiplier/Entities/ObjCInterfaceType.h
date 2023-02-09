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

#include "ObjCObjectType.h"
#include "TypeKind.h"

namespace mx {
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCObjectType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCInterfaceType : public ObjCObjectType {
 private:
  friend class FragmentImpl;
  friend class ObjCObjectType;
  friend class Type;
 public:
  static gap::generator<ObjCInterfaceType> in(const Fragment &frag);
  static gap::generator<ObjCInterfaceType> in(const Index &index);
  static gap::generator<ObjCInterfaceType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<ObjCInterfaceType> by(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_INTERFACE;
  }

  inline static std::optional<ObjCInterfaceType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<ObjCInterfaceType> from(const TokenContext &t) {
    return from(t.as_type());
  }

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
