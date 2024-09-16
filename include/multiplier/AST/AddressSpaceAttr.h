// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AddressSpaceAttr;
class Attr;
class File;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<AddressSpaceAttr> in(const Index &index);
  static gap::generator<AddressSpaceAttr> in(const Fragment &frag);
  static gap::generator<AddressSpaceAttr> in(const File &file);
  static gap::generator<AddressSpaceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ADDRESS_SPACE;
  }

  static std::optional<AddressSpaceAttr> by_id(const Index &, EntityId);

  static std::optional<AddressSpaceAttr> from_base(const Attr &parent);
  inline static std::optional<AddressSpaceAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AddressSpaceAttr> from(const std::optional<Attr> &parent);
  static std::optional<AddressSpaceAttr> from(const Reference &r);
  static std::optional<AddressSpaceAttr> from(const VariantEntity &e);
  static std::optional<AddressSpaceAttr> from(const TokenContext &t);

};

static_assert(sizeof(AddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
