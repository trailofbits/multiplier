// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OpenCLLocalAddressSpaceAttrSpelling.h>
#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class OpenCLLocalAddressSpaceAttr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OpenCLLocalAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLLocalAddressSpaceAttr> in(const Index &index);
  static gap::generator<OpenCLLocalAddressSpaceAttr> in(const Fragment &frag);
  static gap::generator<OpenCLLocalAddressSpaceAttr> in(const File &file);
  static gap::generator<OpenCLLocalAddressSpaceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_LOCAL_ADDRESS_SPACE;
  }

  static std::optional<OpenCLLocalAddressSpaceAttr> by_id(const Index &, EntityId);

  static std::optional<OpenCLLocalAddressSpaceAttr> from_base(const Attr &parent);
  inline static std::optional<OpenCLLocalAddressSpaceAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OpenCLLocalAddressSpaceAttr> from(const std::optional<Attr> &parent);
  static std::optional<OpenCLLocalAddressSpaceAttr> from(const Reference &r);
  static std::optional<OpenCLLocalAddressSpaceAttr> from(const VariantEntity &e);
  static std::optional<OpenCLLocalAddressSpaceAttr> from(const TokenContext &t);

  OpenCLLocalAddressSpaceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(OpenCLLocalAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
