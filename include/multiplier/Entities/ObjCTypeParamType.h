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

#include "Type.h"

namespace mx {
class ObjCTypeParamDecl;
class ObjCTypeParamType;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCTypeParamType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ObjCTypeParamType> in(const Fragment &frag);
  static gap::generator<ObjCTypeParamType> in(const File &file);
  static gap::generator<ObjCTypeParamType> in(const Index &index);
  static gap::generator<ObjCTypeParamType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCTypeParamType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_TYPE_PARAM;
  }

  static std::optional<ObjCTypeParamType> from(const Type &parent);

  inline static std::optional<ObjCTypeParamType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ObjCTypeParamType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCTypeParamType> from(const Reference &r) {
    return ObjCTypeParamType::from(r.as_type());
  }

  inline static std::optional<ObjCTypeParamType> from(const TokenContext &t) {
    return ObjCTypeParamType::from(t.as_type());
  }

  Type desugar(void) const;
  ObjCTypeParamDecl declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ObjCTypeParamType) == sizeof(Type));

#endif
} // namespace mx
