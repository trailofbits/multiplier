// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Type.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class ObjCTypeParamDecl;
class ObjCTypeParamType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCTypeParamType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<ObjCTypeParamType> in(const Index &index);
  static gap::generator<ObjCTypeParamType> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::OBJ_C_TYPE_PARAM;
  }

  static std::optional<ObjCTypeParamType> by_id(const Index &, EntityId);

  static std::optional<ObjCTypeParamType> from_base(const Type &parent);
  inline static std::optional<ObjCTypeParamType> from(const Type &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCTypeParamType> from(const std::optional<Type> &parent);
  static std::optional<ObjCTypeParamType> from(const Reference &r);
  static std::optional<ObjCTypeParamType> from(const VariantEntity &e);
  static std::optional<ObjCTypeParamType> from(const TokenContext &t);

  ObjCTypeParamDecl declaration(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(ObjCTypeParamType) == sizeof(Type));

#endif
} // namespace mx
