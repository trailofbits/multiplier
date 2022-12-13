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
#include "../Use.h"

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
using ObjCObjectPointerTypeRange = DerivedEntityRange<TypeIterator, ObjCObjectPointerType>;
using ObjCObjectPointerTypeContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCObjectPointerType>;
class ObjCObjectPointerType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  inline static ObjCObjectPointerTypeRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCObjectPointerTypeContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCObjectPointerType::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_OBJECT_POINTER;
  }

  static std::optional<ObjCObjectPointerType> from(const TokenContext &c);
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
  std::vector<Type> type_arguments(void) const;
  std::vector<Type> type_arguments_as_written(void) const;
  bool is_kind_of_type(void) const;
  bool is_obj_c_id_or_class_type(void) const;
  bool is_specialized(void) const;
  bool is_specialized_as_written(void) const;
  bool is_sugared(void) const;
  bool is_unspecialized(void) const;
  bool is_unspecialized_as_written(void) const;
  std::vector<ObjCProtocolDecl> qualifiers(void) const;
  ObjCObjectPointerType strip_obj_c_kind_of_type_and_qualifiers(void) const;
  std::vector<ObjCProtocolDecl> protocols(void) const;
};

static_assert(sizeof(ObjCObjectPointerType) == sizeof(Type));

#endif
} // namespace mx
