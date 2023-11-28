// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OpenCLGlobalAddressSpaceAttrSpelling.h>
#include <multiplier/AST/TypeAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class OpenCLGlobalAddressSpaceAttr;
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OpenCLGlobalAddressSpaceAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<OpenCLGlobalAddressSpaceAttr> in(const Index &index);
  static gap::generator<OpenCLGlobalAddressSpaceAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OpenCLGlobalAddressSpaceAttr> by_id(const Index &, EntityId);
  static gap::generator<OpenCLGlobalAddressSpaceAttr> in(const Fragment &frag);
  static gap::generator<OpenCLGlobalAddressSpaceAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OPEN_CL_GLOBAL_ADDRESS_SPACE;
  }

  static std::optional<OpenCLGlobalAddressSpaceAttr> from_base(const Attr &parent);
  inline static std::optional<OpenCLGlobalAddressSpaceAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OpenCLGlobalAddressSpaceAttr> from(const std::optional<Attr> &parent);
  static std::optional<OpenCLGlobalAddressSpaceAttr> from(const Reference &r);
  static std::optional<OpenCLGlobalAddressSpaceAttr> from(const VariantEntity &e);
  static std::optional<OpenCLGlobalAddressSpaceAttr> from(const TokenContext &t);

  OpenCLGlobalAddressSpaceAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(OpenCLGlobalAddressSpaceAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
