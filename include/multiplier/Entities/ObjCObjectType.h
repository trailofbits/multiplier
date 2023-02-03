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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"

#include "Type.h"
#include "TypeKind.h"

namespace mx {
class ObjCInterfaceDecl;
class ObjCObjectType;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCObjectType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static gap::generator<ObjCObjectType> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCObjectType> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCObjectType::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_OBJECT;
  }

  static std::optional<ObjCObjectType> from(const TokenContext &c);
  static std::optional<ObjCObjectType> from(const Type &parent);

  inline static std::optional<ObjCObjectType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ObjCObjectType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  Type base_type(void) const;
  ObjCInterfaceDecl interface(void) const;
  std::optional<Type> super_class_type(void) const;
  std::optional<Type> nth_type_argument(unsigned n) const;
  gap::generator<Type> type_arguments(void) const;
  gap::generator<Type> type_arguments_as_written(void) const;
  bool is_kind_of_type(void) const;
  bool is_kind_of_type_as_written(void) const;
  bool is_obj_c_class(void) const;
  bool is_obj_c_id(void) const;
  bool is_obj_c_qualified_class(void) const;
  bool is_obj_c_qualified_id(void) const;
  bool is_obj_c_unqualified_class(void) const;
  bool is_obj_c_unqualified_id(void) const;
  bool is_obj_c_unqualified_id_or_class(void) const;
  bool is_specialized(void) const;
  bool is_specialized_as_written(void) const;
  bool is_sugared(void) const;
  bool is_unspecialized(void) const;
  bool is_unspecialized_as_written(void) const;
  Type strip_obj_c_kind_of_type_and_qualifiers(void) const;
};

static_assert(sizeof(ObjCObjectType) == sizeof(Type));

#endif
} // namespace mx
