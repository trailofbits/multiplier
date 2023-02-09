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
#include "TypeKind.h"

namespace mx {
class ObjCInterfaceDecl;
class ObjCInterfaceType;
class ObjCObjectPointerType;
class ObjCObjectType;
class ObjCProtocolDecl;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCObjectPointerType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ObjCObjectPointerType> in(const Fragment &frag);
  static gap::generator<ObjCObjectPointerType> in(const Index &index);
  static gap::generator<ObjCObjectPointerType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCObjectPointerType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_OBJECT_POINTER;
  }

  inline static std::optional<ObjCObjectPointerType> from(const Reference &r) {
    return from(r.as_type());
  }

  inline static std::optional<ObjCObjectPointerType> from(const TokenContext &t) {
    return from(t.as_type());
  }

  static std::optional<ObjCObjectPointerType> from(const Type &parent);

  inline static std::optional<ObjCObjectPointerType> from(const std::optional<Type> &parent) {
    if (parent) {
      return ObjCObjectPointerType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type desugar(void) const;
  ObjCInterfaceDecl interface_declaration(void) const;
  ObjCInterfaceType interface_type(void) const;
  ObjCObjectType object_type(void) const;
  Type super_class_type(void) const;
  std::optional<Type> nth_type_argument(unsigned n) const;
  gap::generator<Type> type_arguments(void) const;
  gap::generator<Type> type_arguments_as_written(void) const;
  bool is_kind_of_type(void) const;
  bool is_obj_c_id_or_class_type(void) const;
  bool is_specialized(void) const;
  bool is_specialized_as_written(void) const;
  bool is_sugared(void) const;
  bool is_unspecialized(void) const;
  bool is_unspecialized_as_written(void) const;
  std::optional<ObjCProtocolDecl> nth_qualifier(unsigned n) const;
  gap::generator<ObjCProtocolDecl> qualifiers(void) const;
  ObjCObjectPointerType strip_obj_c_kind_of_type_and_qualifiers(void) const;
  std::optional<ObjCProtocolDecl> nth_protocol(unsigned n) const;
  gap::generator<ObjCProtocolDecl> protocols(void) const;
};

static_assert(sizeof(ObjCObjectPointerType) == sizeof(Type));

#endif
} // namespace mx
