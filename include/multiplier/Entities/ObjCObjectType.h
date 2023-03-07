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
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCObjectType;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCObjectType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ObjCObjectType> in(const Fragment &frag);
  static gap::generator<ObjCObjectType> in(const File &file);
  static gap::generator<ObjCObjectType> in(const Index &index);
  static gap::generator<ObjCObjectType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCObjectType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_OBJECT;
  }

  static std::optional<ObjCObjectType> from(const Type &parent);

  inline static std::optional<ObjCObjectType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ObjCObjectType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ObjCObjectType> from(const Reference &r) {
    return ObjCObjectType::from(r.as_type());
  }

  inline static std::optional<ObjCObjectType> from(const TokenContext &t) {
    return ObjCObjectType::from(t.as_type());
  }

  Type desugar(void) const;
  Type base_type(void) const;
  ObjCInterfaceDecl interface(void) const;
  std::optional<Type> super_class_type(void) const;
  std::optional<Type> nth_type_argument(unsigned n) const;
  unsigned num_type_arguments(void) const;
  gap::generator<Type> type_arguments(void) const &;
  gap::generator<Type> type_arguments_as_written(void) const &;
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
