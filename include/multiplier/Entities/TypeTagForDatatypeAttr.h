// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class Token;
class Type;
class TypeTagForDatatypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeTagForDatatypeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<TypeTagForDatatypeAttr> in(const Fragment &frag);
  static gap::generator<TypeTagForDatatypeAttr> in(const File &file);
  static gap::generator<TypeTagForDatatypeAttr> in(const Index &index);
  static gap::generator<TypeTagForDatatypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeTagForDatatypeAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_TAG_FOR_DATATYPE;
  }

  static std::optional<TypeTagForDatatypeAttr> from(const Attr &parent);

  inline static std::optional<TypeTagForDatatypeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeTagForDatatypeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeTagForDatatypeAttr> from(const Reference &r);
  static std::optional<TypeTagForDatatypeAttr> from(const TokenContext &t);

  bool layout_compatible(void) const;
  Type matching_c_type(void) const;
  Type matching_c_type_token(void) const;
  bool must_be_null(void) const;
};

static_assert(sizeof(TypeTagForDatatypeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
